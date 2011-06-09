#include "stdafx.h"
#include "net/channel.hpp"
#include "channelImpl.hpp"

namespace net
{
	using namespace boost::asio;

	//////////////////////////////////////////////////////////////////////////
	ChannelImpl::ChannelImpl(TSslSocket_ptr socket)
		: _socket(socket)
		, _handler(NULL)
	{

	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelImpl::setHandler(IChannelHandler *handler)
	{
		_handler = handler;
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelImpl::send(const char *data, size_t size)
	{
		async_write(*_socket, const_buffers_1(data, size), 
			boost::bind(
				&ChannelImpl::handleSend, this, 
				data, size, 
				placeholders::error, placeholders::bytes_transferred));
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelImpl::handleSend(
		const char *data, size_t size, 
		const boost::system::error_code& ec, const size_t sended)
	{

	}


	//////////////////////////////////////////////////////////////////////////
	void ChannelImpl::close()
	{
		_socket->lowest_layer().close();
	}

}
