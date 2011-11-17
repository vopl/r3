#include "stdafx.h"
#include "net/channel.hpp"
#include "channelImpl.hpp"
#include "serviceImpl.hpp"
#include "utils/fixEndian.hpp"
#include "utils/crc32.hpp"

//#define LOG(e) if(e){std::cerr<<__FUNCTION__<<": "<<e.message()<<"("<<e.value()<<")"<<std::endl;}
#define LOG(e)

namespace net
{
	using namespace boost::asio;

	//////////////////////////////////////////////////////////////////////////
	ChannelImpl::ChannelImpl(ServiceImpl *serviceImpl, TSocketPtr socket)
		: _serviceImpl(serviceImpl)
		, _socket(socket)
		, _handler(NULL)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	ChannelImpl::~ChannelImpl()
	{
		_serviceImpl->delSock(_socket);
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelImpl::listen()
	{
		makeReceive(boost::make_shared<Allocator>());
	}


	//////////////////////////////////////////////////////////////////////////
	void ChannelImpl::setHandler(IChannelHandler *handler)
	{
		//bool handlerWas = _handler?true:false;
		_handler = handler;

// 		if(!handlerWas && _handler)
// 		{
// 			makeReceive(boost::make_shared<Allocator>());
// 		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelImpl::sendImpl(OutPacketWrapperPtr packet)
	{
		EPacketKind kind = epkRaw;
		if(packet->_variant)
		{
			packet->_data = packet->_variant->save(packet->_size);
			kind = epkVariant;
		}

		packet->_totalSended = 0;

		packet->_flags = kind;
		packet->_sizeNetOrder = utils::fixEndian(packet->_size);
		packet->_flagsNetOrder = utils::fixEndian(packet->_flags);

		boost::mutex::scoped_lock l(_sendQueueMtx);
		_sendQueue.push(packet);

		if(1 == _sendQueue.size())
		{
			AllocatorPtr alloc = boost::make_shared<Allocator>();
			handleSend(shared_from_this(), packet, boost::system::error_code(), 0, alloc);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelImpl::send(boost::shared_array<char> data, size_t size)
	{
		OutPacketWrapperPtr packet(new OutPacketWrapper);
		packet->_size = size;
		packet->_data = data;

		sendImpl(packet);
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelImpl::send(utils::VariantPtr v)
	{
		OutPacketWrapperPtr packet(new OutPacketWrapper);
		packet->_variant = v;

		sendImpl(packet);
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelImpl::handleSend(
		ChannelImplPtr selfKeeper,
		OutPacketWrapperPtr packet, 
		const boost::system::error_code& ec, const size_t sended,
		AllocatorPtr alloc)
	{
		packet->_totalSended += sended;
		if(ec)
		{
			LOG(ec);
			if(_handler) _handler->onError(shared_from_this(), esSend, ec);
			close();
			return;
		}
		if(packet->_totalSended < 4)
		{
			size_t lsended = packet->_totalSended;
			boost::array<boost::asio::const_buffers_1, 3> packedData = 
			{
				const_buffers_1((const char *)&packet->_sizeNetOrder+lsended, 4-lsended), 
				const_buffers_1(packet->_data.get(), packet->_size), 
				const_buffers_1(&packet->_flagsNetOrder, 4), 
			};

			_socket->async_write_some(packedData, 
				makeCmaHandler(*alloc, boost::bind(
					&ChannelImpl::handleSend, this, selfKeeper,
					packet, 
					placeholders::error, placeholders::bytes_transferred, alloc)));
		}
		else if(packet->_totalSended < 4+packet->_size)
		{
			size_t lsended = packet->_totalSended - 4;
			boost::array<boost::asio::const_buffers_1, 2> packedData = 
			{
				const_buffers_1(packet->_data.get()+lsended, packet->_size-lsended), 
				const_buffers_1(&packet->_flagsNetOrder, 4), 
			};

			_socket->async_write_some(packedData, 
				makeCmaHandler(*alloc, boost::bind(
					&ChannelImpl::handleSend, this, selfKeeper,
					packet, 
					placeholders::error, placeholders::bytes_transferred, alloc)));
		}
		else if(packet->_totalSended < 4+packet->_size+4)
		{
			size_t lsended = packet->_totalSended - 4 - packet->_size;
			_socket->async_write_some(buffer((const char *)&packet->_flagsNetOrder+lsended, 4-lsended), 
				makeCmaHandler(*alloc, boost::bind(
					&ChannelImpl::handleSend, this, selfKeeper,
					packet, 
					placeholders::error, placeholders::bytes_transferred, alloc)));
		}
		else
		{
			assert(packet->_totalSended == 4+packet->_size+4);

			handleSendComplete(selfKeeper, packet);

			boost::mutex::scoped_lock l(_sendQueueMtx);
			assert(_sendQueue.size());
			assert(packet == _sendQueue.front());
			_sendQueue.pop();

			if(!_sendQueue.empty())
			{
				packet = _sendQueue.front();
				handleSend(selfKeeper, packet, boost::system::error_code(), 0, alloc);
			}

		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelImpl::handleSendComplete(ChannelImplPtr selfKeeper, OutPacketWrapperPtr packet)
	{
		if(_handler)
		{
			EPacketKind kind = (EPacketKind)packet->_flags;
			switch(kind)
			{
			case epkRaw:
				_handler->onSendComplete(selfKeeper, packet->_data, packet->_size);
				break;
			case epkVariant:
				{
					_handler->onSendComplete(selfKeeper, packet->_variant);
				}
				break;
			default:
				assert(!"unknown packet kind");
				throw "unknown packet kind";
			}
		}
	}



	//////////////////////////////////////////////////////////////////////////
	void ChannelImpl::close()
	{
		boost::system::error_code ec;
		_socket->lowest_layer().shutdown(boost::asio::socket_base::shutdown_both,ec);
		_socket->lowest_layer().close(ec);
		
		_serviceImpl->delSock(_socket);
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelImpl::makeReceive(AllocatorPtr alloc)
	{
		InPacketWrapperPtr packet(new InPacketWrapper);
		packet->_totalReceived = 0;
		packet->_size = 0;
		packet->_flags = 0;

		handleReceive(shared_from_this(), packet, boost::system::error_code(), 0, alloc);
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelImpl::handleReceive(ChannelImplPtr selfKeeper, InPacketWrapperPtr packet, const boost::system::error_code& ec, const size_t received, AllocatorPtr alloc)
	{
		if(ec)
		{
			LOG(ec);
			if(_handler) _handler->onError(shared_from_this(), esReceive, ec);
			close();
			return;
		}
		packet->_totalReceived += received;
		if(packet->_totalReceived < 4)
		{
			size_t lreceived = packet->_totalReceived;
			_socket->async_read_some(buffer((char *)&packet->_size + lreceived, 4-lreceived), 
				makeCmaHandler(*alloc, boost::bind(
					&ChannelImpl::handleReceive, this, selfKeeper,
					packet, 
					placeholders::error, placeholders::bytes_transferred, alloc)));
		}
		else if(packet->_totalReceived == 4)
		{
			packet->_size = utils::fixEndian(packet->_size);
			packet->_data.reset(new char [packet->_size]);

			boost::array<boost::asio::mutable_buffer, 2> packedData = 
			{
				buffer(&packet->_data[0], packet->_size), 
				buffer(&packet->_flags, 4), 
			};

			_socket->async_read_some(packedData, 
				makeCmaHandler(*alloc, boost::bind(
					&ChannelImpl::handleReceive, this, selfKeeper,
					packet, 
					placeholders::error, placeholders::bytes_transferred, alloc)));

		}
		else if(packet->_totalReceived < 4+packet->_size)
		{
			size_t lreceived = packet->_totalReceived-4;
			boost::array<boost::asio::mutable_buffer, 2> packedData = 
			{
				buffer(&packet->_data[lreceived], packet->_size-lreceived), 
				buffer(&packet->_flags, 4), 
			};

			_socket->async_read_some(packedData, 
				makeCmaHandler(*alloc, boost::bind(
					&ChannelImpl::handleReceive, this, selfKeeper,
					packet, 
					placeholders::error, placeholders::bytes_transferred, alloc)));

		}
		else if(packet->_totalReceived < 4+packet->_size+4)
		{
			size_t lreceived = packet->_totalReceived-4-packet->_size;

			_socket->async_read_some(buffer((char *)&packet->_flags+lreceived, 4-lreceived),
				makeCmaHandler(*alloc, boost::bind(
					&ChannelImpl::handleReceive, this, selfKeeper,
					packet, 
					placeholders::error, placeholders::bytes_transferred, alloc)));

		}
		else if(packet->_totalReceived == 4+packet->_size+4)
		{
			packet->_flags = utils::fixEndian(packet->_flags);
			_socket->get_io_service().post(
				makeCmaHandler(*alloc, boost::bind(
					&ChannelImpl::handleReceiveComplete, 
					this, 
					shared_from_this(), 
					packet))
				);
				makeReceive(alloc);
		}
		else
		{
			assert(0);
		}


	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelImpl::handleReceiveComplete(ChannelImplPtr selfKeeper, InPacketWrapperPtr packet)
	{
		if(_handler)
		{
			EPacketKind kind = (EPacketKind)packet->_flags;
			switch(kind)
			{
			case epkRaw:
				_handler->onReceive(selfKeeper, packet->_data, packet->_size);
				break;
			case epkVariant:
				{
					utils::VariantPtr pv(new utils::Variant);
					if(pv->load(packet->_data, packet->_size))
					{
						_handler->onReceive(selfKeeper, pv);
					}
					else
					{
						//corrupted data?
						boost::system::error_code ec = boost::system::errc::make_error_code(boost::system::errc::bad_message);
						_handler->onError(selfKeeper, esReceive, ec);
					}
				}
				break;
			default:
				assert(!"unknown packet kind");
				throw "unknown packet kind";
			}
		}
	}

}
