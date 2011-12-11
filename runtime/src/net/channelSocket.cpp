#include "pch.h"
#include "channelSocket.hpp"
#include "utils/fixEndian.hpp"

namespace net
{
	//////////////////////////////////////////////////////////////////////////
	ChannelSocket::STransferStateSend::STransferStateSend(
		const SPacket &packet, 
		function<void ()> ok,
		function<void (system::error_code)> fail)
		: _ok(ok)
	{
		_packet = packet;
		_header[0] = 0;
		_transferedSize = 0;
		_fail = fail;
	}

	//////////////////////////////////////////////////////////////////////////
	ChannelSocket::STransferStateReceive::STransferStateReceive(
		function<void (const SPacket &)> ok,
		function<void (system::error_code)> fail)
		: _ok(ok)
	{
		_header[0] = 0;
		_transferedSize = 0;
		_fail = fail;
	}

	//////////////////////////////////////////////////////////////////////////
	ChannelSocket::ChannelSocket(TSocketPtr socket)
		: _socket(socket)
		, _strand(socket->get_io_service())
	{
	}

	//////////////////////////////////////////////////////////////////////////
	ChannelSocket::~ChannelSocket()
	{
		close();
	}


	//////////////////////////////////////////////////////////////////////////
	void ChannelSocket::receive(
		function<void (const SPacket &)> ok,
		function<void (system::error_code)> fail)
	{
		STransferStateReceivePtr ts(new STransferStateReceive(ok, fail));

		_strand.dispatch(
			bind(&ChannelSocket::onReceive, shared_from_this(), 
				ts, 
				system::error_code(), 
				size_t(0)));
	}



	//////////////////////////////////////////////////////////////////////////
	void ChannelSocket::send(
		const SPacket &p,
		function<void ()> ok,
		function<void (system::error_code)> fail)
	{
		STransferStateSendPtr ts(new STransferStateSend(p, ok, fail));
		ts->_header[0] = utils::litEndian(ts->_packet._size);
		
		_strand.dispatch(
			bind(&ChannelSocket::onSend, shared_from_this(), 
				ts, 
				system::error_code(), 
				size_t(0)));
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelSocket::onReceive(STransferStateReceivePtr ts, system::error_code ec, size_t size)
	{
		if(ec)
		{
			if(ts->_fail)
			{
				ts->_fail(ec);
			}
			return;
		}

		ts->_transferedSize += size;
		if(ts->_transferedSize < sizeof(ts->_header))
		{
			_socket->async_read_some(
				buffer((char *)&ts->_header, sizeof(ts->_header)-ts->_transferedSize), 
				_strand.wrap(
					bind(
						&ChannelSocket::onReceive, shared_from_this(),
						ts, 
						_1, _2
					)
				)
			);
			return;
		}
		else if(ts->_transferedSize == sizeof(ts->_header))
		{
			ts->_packet._size = utils::litEndian(ts->_header[0]);
			if(ts->_packet._size)
			{
				ts->_packet._data.reset(new char[ts->_packet._size]);

				_socket->async_read_some(
					buffer(ts->_packet._data.get(), ts->_packet._size), 
					_strand.wrap(
						bind(
							&ChannelSocket::onReceive, shared_from_this(),
							ts, 
							_1, _2
						)
					)
				);
				return;
			}
			else
			{
				ts->_packet._data.reset();
			}
		}
		
		if(ts->_transferedSize < sizeof(ts->_header)+ ts->_packet._size)
		{
			size_t dataTransferedSize = ts->_transferedSize-sizeof(ts->_header);

			_socket->async_read_some(
				buffer(
					ts->_packet._data.get()+dataTransferedSize, 
					ts->_packet._size-dataTransferedSize), 
				_strand.wrap(
					bind(
						&ChannelSocket::onReceive, shared_from_this(),
						ts, 
						_1, _2
					)
				)
			);
		}
		else
		{
			assert(ts->_transferedSize == sizeof(ts->_header)+ts->_packet._size);
			ts->_ok(ts->_packet);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelSocket::onSend(STransferStateSendPtr ts, system::error_code ec, size_t size)
	{
		if(ec)
		{
			if(ts->_fail)
			{
				ts->_fail(ec);
			}
			return;
		}

		ts->_transferedSize += size;
		if(ts->_transferedSize < sizeof(ts->_header))
		{
			boost::array<boost::asio::const_buffers_1, 2> packedData = 
			{
				const_buffers_1((char *)&ts->_header+ts->_transferedSize, sizeof(ts->_header)-ts->_transferedSize), 
				const_buffers_1(ts->_packet._data.get(), ts->_packet._size), 
			};

			_socket->async_write_some(
				packedData, 
				_strand.wrap(
					bind(
						&ChannelSocket::onSend, shared_from_this(),
						ts, 
						_1, _2
					)
				)
			);

		}
		else if(ts->_transferedSize < sizeof(ts->_header)+ts->_packet._size)
		{
			size_t dataTransferedSize = ts->_transferedSize-sizeof(ts->_header);
			boost::asio::const_buffers_1 packedData(
				ts->_packet._data.get()+dataTransferedSize, 
				ts->_packet._size-dataTransferedSize);

			_socket->async_write_some(
				packedData, 
				_strand.wrap(
					bind(
						&ChannelSocket::onSend, shared_from_this(),
						ts, 
						_1, _2
					)
				)
			);
		}
		else
		{
			assert(ts->_transferedSize == sizeof(ts->_header)+ts->_packet._size);
			ts->_ok();
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelSocket::close()
	{
		boost::system::error_code ec;
		_socket->lowest_layer().shutdown(boost::asio::socket_base::shutdown_both, ec);
		_socket->lowest_layer().close(ec);
	}
}
