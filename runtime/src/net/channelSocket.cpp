#include "pch.h"
#include "channelSocket.hpp"
#include "utils/fixEndian.hpp"

namespace net
{
	//////////////////////////////////////////////////////////////////////////
	ChannelSocket::Sock::Sock(TSocketPtr socket)
		: _socket(socket)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	ChannelSocket::Sock::Sock(TSocketSslPtr socketSsl)
		: _socketSsl(socketSsl)
	{

	}

	//////////////////////////////////////////////////////////////////////////
	template <class Buffer, class Handler>
	void ChannelSocket::Sock::read(Buffer b, Handler h)
	{
		if(_socket)
		{
			_socket->async_read_some(b,h);
		}
		else
		{
			_socketSsl->async_read_some(b,h);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Buffer, class Handler>
	void ChannelSocket::Sock::write(Buffer b, Handler h)
	{
		if(_socket)
		{
			_socket->async_write_some(b,h);
		}
		else
		{
			_socketSsl->async_write_some(b,h);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelSocket::Sock::close()
	{
		error_code ec;
		if(_socket)
		{
			_socket->lowest_layer().shutdown(boost::asio::socket_base::shutdown_both, ec);
			_socket->lowest_layer().close(ec);
		}
		else
		{
			_socketSsl->lowest_layer().shutdown(boost::asio::socket_base::shutdown_both, ec);
			_socketSsl->lowest_layer().close(ec);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	ChannelSocket::STransferStateSend::STransferStateSend(
		const SPacket &packet, 
		Result<error_code> res)
		: _res(res)
	{
		_packet = packet;
		_header[0] = 0;
		_transferedSize = 0;
	}

	//////////////////////////////////////////////////////////////////////////
	ChannelSocket::STransferStateReceive::STransferStateReceive(Result2<error_code, SPacket> res)
		: _res(res)
	{
		_header[0] = 0;
		_transferedSize = 0;
	}

	//////////////////////////////////////////////////////////////////////////
	ChannelSocket::ChannelSocket(TSocketSslPtr socket)
		: _sock(socket)
		, _strand(socket->get_io_service())
	{
	}

	//////////////////////////////////////////////////////////////////////////
	ChannelSocket::ChannelSocket(TSocketPtr socket)
		: _sock(socket)
		, _strand(socket->get_io_service())
	{
	}

	//////////////////////////////////////////////////////////////////////////
	ChannelSocket::~ChannelSocket()
	{
		close();
	}


	//////////////////////////////////////////////////////////////////////////
	Result2<error_code, SPacket> ChannelSocket::receive()
	{
		Result2<error_code, SPacket> res;
		STransferStateReceivePtr ts(new STransferStateReceive(res));

		_strand.dispatch(
			bind(&ChannelSocket::onReceive, shared_from_this(), 
				ts, 
				system::error_code(), 
				size_t(0)));

		return res;
	}



	//////////////////////////////////////////////////////////////////////////
	Result<error_code> ChannelSocket::send(const SPacket &p)
	{
		Result<error_code> res;
		STransferStateSendPtr ts(new STransferStateSend(p, res));
		ts->_header[0] = utils::litEndian(ts->_packet._size);
		
		_strand.dispatch(
			bind(&ChannelSocket::onSend, shared_from_this(), 
				ts, 
				system::error_code(), 
				size_t(0)));

		return res;
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelSocket::onReceive(STransferStateReceivePtr ts, system::error_code ec, size_t size)
	{
		if(ec)
		{
			ts->_res(ec, SPacket());
			return;
		}

		ts->_transferedSize += size;
		if(ts->_transferedSize < sizeof(ts->_header))
		{
			_sock.read(
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

				_sock.read(
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

			_sock.read(
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
			ts->_res(error_code(), ts->_packet);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelSocket::onSend(STransferStateSendPtr ts, system::error_code ec, size_t size)
	{
		if(ec)
		{
			ts->_res(ec);
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

			_sock.write(
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

			_sock.write(
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
			ts->_res(error_code());
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelSocket::close()
	{
		boost::system::error_code ec;
		_sock.close();
	}
}
