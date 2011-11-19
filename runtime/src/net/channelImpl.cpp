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
	SPacket::SPacket()
		: _id(0)
		, _kind(0)
		, _size(0)
		, _data()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	ChannelImpl::PacketWrapper::PacketWrapper(const SPacket &p)
		: SPacket(p)
	{
		_headerNetOrder[0] = utils::fixEndian(p._id);
		_headerNetOrder[1] = utils::fixEndian(p._kind);
		_headerNetOrder[2] = utils::fixEndian(p._size);
	}

	//////////////////////////////////////////////////////////////////////////
	ChannelImpl::PacketWrapper::PacketWrapper()
	{
	}


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
	void ChannelImpl::send(const SPacket &p)
	{
		PacketWrapperPtr packet(new PacketWrapper(p));

		boost::mutex::scoped_lock l(_sendQueueMtx);
		_sendQueue.push(packet);

		if(1 == _sendQueue.size())
		{
			AllocatorPtr alloc = boost::make_shared<Allocator>();
			handleSend(shared_from_this(), packet, boost::system::error_code(), 0, alloc);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelImpl::handleSend(
		ChannelImplPtr selfKeeper,
		PacketWrapperPtr packet, 
		const boost::system::error_code& ec, const size_t sended,
		AllocatorPtr alloc)
	{
		if(ec)
		{
			LOG(ec);
			if(_handler)
			{
				_handler->onSendFailed(selfKeeper, *packet);
				_handler->onClose(selfKeeper);
			}
			close();
			return;
		}

		assert(
			sended == 0 || 
			sended == sizeof(packet->_headerNetOrder) + packet->_size);

		if(!sended)
		{
			boost::array<boost::asio::const_buffers_1, 2> packedData = 
			{
				const_buffers_1((const char *)&packet->_headerNetOrder, sizeof(packet->_headerNetOrder)), 
				const_buffers_1(packet->_data.get(), packet->_size)
			};

			async_write(
				*_socket,
				packedData, 
				makeCmaHandler(*alloc, boost::bind(
					&ChannelImpl::handleSend, this, selfKeeper,
					packet, 
					placeholders::error, placeholders::bytes_transferred, alloc)));
		}
		else
		{
			assert(sended == sizeof(packet->_headerNetOrder)+packet->_size);

			if(_handler)
			{
				_handler->onSendComplete(selfKeeper, *packet);
			}

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
		return makeReceive(AllocatorPtr(new Allocator));
	}


	//////////////////////////////////////////////////////////////////////////
	void ChannelImpl::makeReceive(AllocatorPtr alloc)
	{
		PacketWrapperPtr packet(new PacketWrapper);
		handleReceive(shared_from_this(), packet, boost::system::error_code(), 0, alloc);
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelImpl::handleReceive(ChannelImplPtr selfKeeper, PacketWrapperPtr packet, const boost::system::error_code& ec, const size_t received, AllocatorPtr alloc)
	{
		if(ec)
		{
			LOG(ec);
			if(_handler)
			{
				_handler->onClose(selfKeeper);
			}
			close();
			return;
		}

		if(packet->_data)
		{
			assert(received == packet->_size);

			if(_handler)
			{
				_handler->onReceive(selfKeeper, *packet);
			}

			makeReceive(alloc);
		}
		else
		{
			assert(
				received == 0 || 
				received == sizeof(packet->_headerNetOrder));

			if(!received)
			{
				async_read(
					*_socket,
					buffer((char *)&packet->_headerNetOrder, sizeof(packet->_headerNetOrder)), 
					makeCmaHandler(*alloc, boost::bind(
						&ChannelImpl::handleReceive, this, selfKeeper,
						packet, 
						placeholders::error, placeholders::bytes_transferred, alloc)));
			}
			else
			{
				packet->_id = utils::fixEndian(packet->_headerNetOrder[0]);
				packet->_kind = utils::fixEndian(packet->_headerNetOrder[1]);
				packet->_size = utils::fixEndian(packet->_headerNetOrder[2]);
				packet->_data.reset(new char [packet->_size]);

				async_read(
					*_socket,
					buffer(&packet->_data[0], packet->_size), 
					makeCmaHandler(*alloc, boost::bind(
						&ChannelImpl::handleReceive, this, selfKeeper,
						packet, 
						placeholders::error, placeholders::bytes_transferred, alloc)));

			}
		}
	}
}
