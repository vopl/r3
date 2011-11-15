#include "stdafx.h"
#include "net/channel.hpp"
#include "channelImpl.hpp"
#include "serviceImpl.hpp"
#include "utils/fixEndian.hpp"
#include "utils/crc32.hpp"

#define LOG(e) if(e){std::cerr<<__FUNCTION__<<": "<<e.message()<<"("<<e.value()<<")"<<std::endl;}

namespace net
{
	using namespace boost::asio;

	//////////////////////////////////////////////////////////////////////////
	ChannelImpl::ChannelImpl(ServiceImpl *serviceImpl, TSocket_ptr socket)
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
	void ChannelImpl::setHandler(IChannelHandler *handler)
	{
		bool handlerWas = _handler?true:false;
		_handler = handler;

		if(!handlerWas && _handler)
		{
			makeReceive();
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelImpl::sendImpl(boost::shared_array<char> data, size_t size, EPacketKind kind)
	{
		OutPacketWrapper_ptr packet(new OutPacketWrapper);
		packet->_totalSended = 0;
		packet->_size = size;
		packet->_sizeNetOrder = utils::fixEndian(packet->_size | (((boost::uint32_t)kind)<<28));
		packet->_crc32NetOrder = utils::fixEndian(utils::crc32(data.get(), size));
		packet->_data = data;

		boost::mutex::scoped_lock l(_sendQueueMtx);
		_sendQueue.push(packet);

		if(1 == _sendQueue.size())
		{
			Allocator_ptr alloc = boost::make_shared<Allocator>();
			handleSend(shared_from_this(), packet, boost::system::error_code(), 0, alloc);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelImpl::send(boost::shared_array<char> data, size_t size)
	{
		sendImpl(data, size, epkRaw);
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelImpl::send(const utils::Variant &v)
	{
		size_t size;
		boost::shared_array<char> data = v.save(size);
		sendImpl(data, size, epkVariant);
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelImpl::handleSend(
		ChannelImpl_ptr selfKeeper,
		OutPacketWrapper_ptr packet, 
		const boost::system::error_code& ec, const size_t sended,
		Allocator_ptr alloc)
	{
		packet->_totalSended += sended;
		if(ec)
		{
			LOG(ec);
			if(_handler) _handler->onError(shared_from_this());
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
				const_buffers_1(&packet->_crc32NetOrder, 4), 
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
				const_buffers_1(&packet->_crc32NetOrder, 4), 
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
			_socket->async_write_some(buffer((const char *)&packet->_crc32NetOrder+lsended, 4-lsended), 
				makeCmaHandler(*alloc, boost::bind(
					&ChannelImpl::handleSend, this, selfKeeper,
					packet, 
					placeholders::error, placeholders::bytes_transferred, alloc)));
		}
		else
		{
			assert(packet->_totalSended == 4+packet->_size+4);

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
	void ChannelImpl::close()
	{
		boost::system::error_code ec;
		_socket->lowest_layer().shutdown(boost::asio::socket_base::shutdown_both,ec);
		_socket->lowest_layer().close(ec);
		
		_serviceImpl->delSock(_socket);
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelImpl::makeReceive()
	{
		InPacketWrapper_ptr packet(new InPacketWrapper);
		packet->_totalReceived = 0;
		packet->_size = 0;
		packet->_crc32 = 0;

		Allocator_ptr alloc = boost::make_shared<Allocator>();
		handleReceive(shared_from_this(), packet, boost::system::error_code(), 0, alloc);
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelImpl::handleReceive(ChannelImpl_ptr selfKeeper, InPacketWrapper_ptr packet, const boost::system::error_code& ec, const size_t received, Allocator_ptr alloc)
	{
		if(ec)
		{
			LOG(ec);
			if(_handler) _handler->onError(shared_from_this());
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
			packet->_kind = (EPacketKind)(packet->_size>>28);
			packet->_size &= 0x0fffffff;
			packet->_data.reset(new char [packet->_size]);

			boost::array<boost::asio::mutable_buffer, 2> packedData = 
			{
				buffer(&packet->_data[0], packet->_size), 
				buffer(&packet->_crc32, 4), 
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
				buffer(&packet->_crc32, 4), 
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

			_socket->async_read_some(buffer((char *)&packet->_crc32+lreceived, 4-lreceived),
				makeCmaHandler(*alloc, boost::bind(
					&ChannelImpl::handleReceive, this, selfKeeper,
					packet, 
					placeholders::error, placeholders::bytes_transferred, alloc)));

		}
		else if(packet->_totalReceived == 4+packet->_size+4)
		{
			packet->_crc32 = utils::fixEndian(packet->_crc32);
			boost::uint32_t crc32 = utils::crc32(&packet->_data[0], packet->_size);

			if(crc32 == packet->_crc32)
			{
				_socket->get_io_service().post(
					makeCmaHandler(*alloc, boost::bind(
						&ChannelImpl::handleReceiveComplete, 
						this, 
						shared_from_this(), 
						packet->_data, 
						packet->_size, 
						packet->_kind, 
						alloc))
					);
				makeReceive();
			}
			else
			{
				//assert(0);
				std::cerr<<"bad crc"<<std::endl;
			}
		}
		else
		{
			assert(0);
		}


	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelImpl::handleReceiveComplete(
		ChannelImpl_ptr selfKeeper, boost
		::shared_array<char> data, 
		size_t size, 
		EPacketKind kind,
		Allocator_ptr alloc)
	{
		if(_handler)
		{
			switch(kind)
			{
			case epkRaw:
				_handler->onReceive(selfKeeper, data, size);
				break;
			case epkVariant:
				{
					utils::VariantPtr pv(new utils::Variant);
					if(pv->load(data, size))
					{
						_handler->onReceive(selfKeeper, pv);
					}
					else
					{
						//corrupted data?
						_handler->onError(selfKeeper);
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
