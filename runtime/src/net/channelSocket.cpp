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
	ChannelSocket::Sock::Sock(TSocketSslPtr socketSsl, TSslContextPtr sslContext)
		: _socketSsl(socketSsl)
		, _sslContext(sslContext)
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
	void ChannelSocket::receive_f()
	{
		for(;;)
		{
			Result2<error_code, SPacket> op;
			{
				mutex::scoped_lock sl(_mtxReceives);
				if(_receives.empty())
				{
					return;
				}
				op = _receives[0];
				_receives.erase(_receives.begin());
			}

			size_t				transferedSize = 0;
			boost::uint32_t		header[1];
			error_code			ec;


			//заголовок
			while(transferedSize < sizeof(header))
			{
				Result2<error_code, size_t> readRes;
				_sock.read(
					buffer((char *)&header + transferedSize, sizeof(header) - transferedSize), 
					readRes);
				ec = readRes.data1();

				if(ec)
				{
					op(ec, SPacket());
					return;
				}
				transferedSize += readRes.data2();
			}
			assert(transferedSize == sizeof(header));
			transferedSize = 0;

			//данные
			SPacket				packet;
			packet._size = utils::litEndian(header[0]);
			if(packet._size)
			{
				packet._data.reset(new char[packet._size]);
				while(transferedSize < packet._size)
				{
					Result2<error_code, size_t> readRes;
					_sock.read(
						buffer(packet._data.get() + transferedSize, packet._size - transferedSize), 
						readRes);
					ec = readRes.data1();

					if(ec)
					{
						op(ec, SPacket());
						return;
					}
					transferedSize += readRes.data2();
				}
			}
			assert(transferedSize == packet._size);
			transferedSize = 0;

			op(error_code(), packet);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelSocket::send_f()
	{
		for(;;)
		{
			std::pair<Result<error_code>, SPacket> op;
			{
				mutex::scoped_lock sl(_mtxSends);
				if(_sends.empty())
				{
					return;
				}
				op = _sends[0];
				_sends.erase(_sends.begin());
			}

			size_t				transferedSize = 0;
			boost::uint32_t		header[1];
			error_code			ec;


			//заголовок
			header[0] = utils::litEndian(op.second._size);
			while(transferedSize < sizeof(header))
			{
				Result2<error_code, size_t> readRes;
				_sock.write(
					buffer((char *)&header + transferedSize, sizeof(header) - transferedSize), 
					readRes);
				ec = readRes.data1();

				if(ec)
				{
					op.first(ec);
					return;
				}
				transferedSize += readRes.data2();
			}
			assert(transferedSize == sizeof(header));
			transferedSize = 0;

			//данные
			SPacket				&packet = op.second;
			if(packet._size)
			{
				while(transferedSize < packet._size)
				{
					Result2<error_code, size_t> writeRes;
					_sock.write(
						buffer(packet._data.get() + transferedSize, packet._size - transferedSize), 
						writeRes);
					ec = writeRes.data1();

					if(ec)
					{
						op.first(ec);
						return;
					}
					transferedSize += writeRes.data2();
				}
			}
			assert(transferedSize == packet._size);
			transferedSize = 0;

			op.first(error_code());
		}
	}

	//////////////////////////////////////////////////////////////////////////
	ChannelSocket::ChannelSocket(TSocketPtr socket)
		: _sock(socket)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	ChannelSocket::ChannelSocket(TSocketSslPtr socket, TSslContextPtr sslContext)
		: _sock(socket, sslContext)
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

		mutex::scoped_lock sl(_mtxReceives);
		_receives.push_back(res);
		if(_receives.size() < 2)
		{
			spawn(bind(&ChannelSocket::receive_f, shared_from_this()));
		}

		return res;
	}



	//////////////////////////////////////////////////////////////////////////
	Result<error_code> ChannelSocket::send(const SPacket &p)
	{
		Result<error_code> res;

		mutex::scoped_lock sl(_mtxSends);
		_sends.push_back(std::make_pair(res, p));
		if(_sends.size() < 2)
		{
			spawn(bind(&ChannelSocket::send_f, shared_from_this()));
		}

		return res;
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelSocket::close()
	{
		boost::system::error_code ec;
		_sock.close();
	}
}
