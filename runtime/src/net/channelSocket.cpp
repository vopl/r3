#include "pch.hpp"
#include "channelSocket.hpp"
#include "utils/fixEndian.hpp"
#include <boost/bind.hpp>

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
		, _sslStrand(new TStrand(socketSsl->get_io_service()))
	{
	}

	//////////////////////////////////////////////////////////////////////////
	ChannelSocket::Sock::~Sock()
	{

	}

	//////////////////////////////////////////////////////////////////////////
	template <class Buffer, class Handler>
	void ChannelSocket::Sock::read(const Buffer &b, const Handler &h)
	{
		if(_socket)
		{
			_socket->async_read_some(b, async::bridge(h));
		}
		else
		{
			typedef asio::detail::wrapped_handler<
				asio::io_service::strand,
				async::AsioBridge<Handler> > WrappedHandler;
			_sslStrand->dispatch(
				bind(&TSocketSsl::async_read_some<Buffer, WrappedHandler>, _socketSsl.get(), b, _sslStrand->wrap(async::bridge(h))));
		}
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Buffer, class Handler>
	void ChannelSocket::Sock::write(const Buffer &b, const Handler &h)
	{
		if(_socket)
		{
			_socket->async_write_some(b, async::bridge(h));
		}
		else
		{
			typedef asio::detail::wrapped_handler<
				asio::io_service::strand,
				async::AsioBridge<Handler> > WrappedHandler;
			_sslStrand->dispatch(
				bind(&TSocketSsl::async_write_some<Buffer, WrappedHandler>, _socketSsl.get(), b, _sslStrand->wrap(async::bridge(h))));
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelSocket::Sock::close()
	{
		error_code ec;
		if(_socket)
		{
			_socket->lowest_layer().shutdown(asio::socket_base::shutdown_both, ec);
			_socket->lowest_layer().close(ec);
		}
		else
		{
			_socketSsl->lowest_layer().shutdown(asio::socket_base::shutdown_both, ec);
			_socketSsl->lowest_layer().close(ec);

// 			typedef function<void(const error_code &)> TOnShutdown;
// 			TOnShutdown onShutdown = boost::bind(&Sock::onSslShutdown, _1, _socketSsl, _sslContext);
//
// 			_sslStrand->dispatch(
// 				bind(&TSocketSsl::async_shutdown<TOnShutdown>, _socketSsl, onShutdown)
// 				);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelSocket::Sock::onSslShutdown(
		const error_code &ec,
		TSocketSslPtr socketSsl,
		TSslContextPtr sslContextHolder)
	{
		error_code ecl;
		socketSsl->lowest_layer().shutdown(asio::socket_base::shutdown_both, ecl);
		socketSsl->lowest_layer().close(ecl);
	}



	//////////////////////////////////////////////////////////////////////////
	void ChannelSocket::receiveLoop_f()
	{
		TReceive receive;
		receive.second = 0;

		{
			mutex::scoped_lock sl(_mtxReceive);
			if(_receiveLoopInProgress)
			{
				return;
			}
			_receiveLoopInProgress = true;
		}

		for(;;)
		{
			while(!receive.second)
			{
				mutex::scoped_lock sl(_mtxReceive);
				if(_receives.empty())
				{
					_receiveLoopInProgress = false;
					return;
				}

				std::swap(receive, _receives[0]);
				_receives.erase(_receives.begin());
			}
			receive.second--;

			size_t				transferedSize = 0;
			uint32_t			header[1]={};
			error_code			ec;


			//заголовок
			while(transferedSize < sizeof(header))
			{
				Future2<error_code, size_t> readRes;
				_sock.read(
					buffer((char *)&header + transferedSize, sizeof(header) - transferedSize),
					readRes);
				ec = readRes.data1();

				if(ec)
				{
					if(asio::error::operation_aborted == ec)
					{
						mutex::scoped_lock sl(_mtxReceive);
						_receiveLoopInProgress = false;
						return;
					}
					spawn(bind(receive.first, ec, SPacket()));

					mutex::scoped_lock sl(_mtxReceive);
					_receiveLoopInProgress = false;
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
					Future2<error_code, size_t> readRes;
					_sock.read(
						buffer(packet._data.get() + transferedSize, packet._size - transferedSize),
						readRes);
					ec = readRes.data1();

					if(ec)
					{
						if(asio::error::operation_aborted == ec.value())
						{
							mutex::scoped_lock sl(_mtxReceive);
							_receiveLoopInProgress = false;
							return;
						}
						spawn(bind(receive.first, ec, SPacket()));

						mutex::scoped_lock sl(_mtxReceive);
						_receiveLoopInProgress = false;
						return;
					}
					transferedSize += readRes.data2();
				}
			}
			assert(transferedSize == packet._size);
			transferedSize = 0;

			spawn(bind(receive.first, error_code(), packet));
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelSocket::send_f()
	{
		for(;;)
		{
			std::pair<Future<error_code>, SPacket> op;
			{
				mutex::scoped_lock sl(_mtxSends);
				if(_sendInProcess)
				{
					return;
				}
				if(_sends.empty())
				{
					return;
				}
				op = _sends[0];
				_sends.erase(_sends.begin());
				_sendInProcess = true;
			}

			size_t				transferedSize = 0;
			uint32_t			header[1];
			error_code			ec;


			//заголовок
			header[0] = utils::litEndian(op.second._size);
			while(transferedSize < sizeof(header))
			{
				Future2<error_code, size_t> readRes;
				_sock.write(
					buffer((char *)&header + transferedSize, sizeof(header) - transferedSize),
					readRes);
				ec = readRes.data1();

				if(ec)
				{
					op.first(ec);
					mutex::scoped_lock sl(_mtxSends);
					_sendInProcess = false;
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
					Future2<error_code, size_t> writeRes;
					_sock.write(
						buffer(packet._data.get() + transferedSize, packet._size - transferedSize),
						writeRes);
					ec = writeRes.data1();

					if(ec)
					{
						op.first(ec);
						mutex::scoped_lock sl(_mtxSends);
						_sendInProcess = false;
						return;
					}
					transferedSize += writeRes.data2();
				}
			}
			assert(transferedSize == packet._size);
			transferedSize = 0;

			op.first(error_code());
			mutex::scoped_lock sl(_mtxSends);
			_sendInProcess = false;
		}
	}

	//////////////////////////////////////////////////////////////////////////
	ChannelSocket::ChannelSocket(TSocketPtr socket)
		: _sock(socket)
		, _sendInProcess(false)
		, _receiveLoopInProgress(false)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	ChannelSocket::ChannelSocket(TSocketSslPtr socket, TSslContextPtr sslContext)
		: _sock(socket, sslContext)
		, _sendInProcess(false)
		, _receiveLoopInProgress(false)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	ChannelSocket::~ChannelSocket()
	{
		close();
	}


	//////////////////////////////////////////////////////////////////////////
	void ChannelSocket::listen(const TOnReceive &onReceive, size_t amount)
	{
		mutex::scoped_lock sl(_mtxReceive);
		_receives.push_back(std::make_pair(onReceive, amount));
		spawn(bind(&ChannelSocket::receiveLoop_f, shared_from_this()));
	}

	//////////////////////////////////////////////////////////////////////////
	Future<error_code> ChannelSocket::send(const SPacket &p)
	{
		Future<error_code> res;

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
		_sock.close();
	}
}
