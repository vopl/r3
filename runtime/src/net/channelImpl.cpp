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

		if(!handlerWas)
		{
			makeReceive();
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelImpl::send(boost::shared_array<char> data, size_t size)
	{
		OutPacketWrapper_ptr packet(new OutPacketWrapper);
		packet->_totalSended = 0;
		packet->_size = size;
		packet->_sizeNetOrder = utils::fixEndian(packet->_size);
		packet->_crc32NetOrder = utils::fixEndian(utils::crc32(data.get(), size));
		packet->_data = data;

		handleSend(shared_from_this(), packet, boost::system::error_code(), 0);
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelImpl::handleSend(
		ChannelImpl_ptr selfKeeper,
		OutPacketWrapper_ptr packet, 
		const boost::system::error_code& ec, const size_t sended)
	{
		packet->_totalSended += sended;
		if(ec)
		{
			LOG(ec);
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
				boost::bind(
					&ChannelImpl::handleSend, this, selfKeeper,
					packet, 
					placeholders::error, placeholders::bytes_transferred));
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
				boost::bind(
					&ChannelImpl::handleSend, this, selfKeeper,
					packet, 
					placeholders::error, placeholders::bytes_transferred));
		}
		else if(packet->_totalSended < 4+packet->_size+4)
		{
			size_t lsended = packet->_totalSended - 4 - packet->_size;
			_socket->async_write_some(buffer((const char *)&packet->_crc32NetOrder+lsended, 4-lsended), 
				boost::bind(
					&ChannelImpl::handleSend, this, selfKeeper,
					packet, 
					placeholders::error, placeholders::bytes_transferred));
		}
		else
		{
			assert(packet->_totalSended == 4+packet->_size+4);
		}
	}


	//////////////////////////////////////////////////////////////////////////
	void ChannelImpl::close()
	{
		boost::system::error_code ec;
		//_socket->shutdown(ec);
		_socket->lowest_layer().shutdown(boost::asio::socket_base::shutdown_both);
		_socket->lowest_layer().close();
		
		_serviceImpl->delSock(_socket);
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelImpl::makeReceive()
	{
		InPacketWrapper_ptr packet(new InPacketWrapper);
		packet->_totalReceived = 0;
		packet->_size = 0;
		packet->_crc32 = 0;
		handleReceive(shared_from_this(), packet, boost::system::error_code(), 0);
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelImpl::handleReceive(ChannelImpl_ptr selfKeeper, InPacketWrapper_ptr packet, const boost::system::error_code& ec, const size_t received)
	{
		if(ec)
		{
			LOG(ec);
			return;
		}
		packet->_totalReceived += received;
		if(packet->_totalReceived < 4)
		{
			size_t lreceived = packet->_totalReceived;
			_socket->async_read_some(buffer((char *)&packet->_size + lreceived, 4-lreceived), 
				boost::bind(
					&ChannelImpl::handleReceive, this, selfKeeper,
					packet, 
					placeholders::error, placeholders::bytes_transferred));
		}
		else if(packet->_totalReceived == 4)
		{
			packet->_size = utils::fixEndian(packet->_size);
			packet->_data.reset(new char [packet->_size]);

			boost::array<boost::asio::mutable_buffer, 2> packedData = 
			{
				buffer(&packet->_data[0], packet->_size), 
				buffer(&packet->_crc32, 4), 
			};

			_socket->async_read_some(packedData, 
				boost::bind(
					&ChannelImpl::handleReceive, this, selfKeeper,
					packet, 
					placeholders::error, placeholders::bytes_transferred));

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
				boost::bind(
					&ChannelImpl::handleReceive, this, selfKeeper,
					packet, 
					placeholders::error, placeholders::bytes_transferred));

		}
		else if(packet->_totalReceived < 4+packet->_size+4)
		{
			size_t lreceived = packet->_totalReceived-4-packet->_size;

			_socket->async_read_some(buffer((char *)&packet->_crc32+lreceived, 4-lreceived),
				boost::bind(
					&ChannelImpl::handleReceive, this, selfKeeper,
					packet, 
					placeholders::error, placeholders::bytes_transferred));

		}
		else if(packet->_totalReceived == 4+packet->_size+4)
		{
			packet->_crc32 = utils::fixEndian(packet->_crc32);
			boost::uint32_t crc32 = utils::crc32(&packet->_data[0], packet->_size);

			if(crc32 == packet->_crc32)
			{
				_socket->get_io_service().post(boost::bind(&ChannelImpl::handleReceiveComplete, this, shared_from_this(), packet->_data, packet->_size));
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
	void ChannelImpl::handleReceiveComplete(ChannelImpl_ptr selfKeeper, boost::shared_array<char> data, size_t size)
	{
		_handler->onReceive(selfKeeper, data, size);
	}

}
