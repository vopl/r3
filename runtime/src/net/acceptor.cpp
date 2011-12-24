#include "pch.h"
#include "acceptor.hpp"
#include "channelSocket.hpp"

namespace net
{
	//////////////////////////////////////////////////////////////////////////
	std::string Acceptor::onSslPassword()
	{
		return "test";
	}

	//////////////////////////////////////////////////////////////////////////
	void Acceptor::listen_f(
		async::Result<error_code> res,
		const std::string &host, const std::string &service, bool useSsl)
	{
		{
			mutex::scoped_lock sl(_mtx);
			if(_inProcess)
			{
				res(make_error_code(errc::operation_in_progress));
				return;
			}
			_inProcess = true;

			if(useSsl)
			{
				_sslContext.reset(new TSslContext(io(), ssl::context::sslv23));
				_sslContext->set_options(
					ssl::context::default_workarounds
					| ssl::context::no_sslv2
					| ssl::context::single_dh_use);

				_sslContext->set_password_callback(bind(&Acceptor::onSslPassword, shared_from_this()));
				error_code ec;
				_sslContext->use_certificate_chain_file("server.pem", ec);
				_sslContext->use_private_key_file("server.pem", ssl::context::pem, ec);
				_sslContext->use_tmp_dh_file("dh512.pem", ec);
			}
			_acceptor = TAcceptorPtr(new TAcceptor(io()));
		}

		//резолвить адрес
		ip::tcp::resolver resolver(io());

		Result2<error_code, ip::tcp::resolver::iterator> resolveRes;
		resolver.async_resolve(
			ip::tcp::resolver::query(host, service),
			resolveRes);
		resolveRes.wait();

		if(resolveRes.data1())
		{
			//неудача, вернуть ее
			{
				mutex::scoped_lock sl(_mtx);
				_inProcess = false;
				_sslContext.reset();
			}
			res(resolveRes.data1());
			return;
		}

		//зарядить акцептор asio
		_acceptor->open(resolveRes.data2()->endpoint().protocol());
		_acceptor->set_option(ip::tcp::acceptor::reuse_address(true));
		_acceptor->set_option(socket_base::enable_connection_aborted(true));
		_acceptor->bind(*resolveRes.data2());
		_acceptor->listen();

		res(error_code());
	}

	//////////////////////////////////////////////////////////////////////////
	void Acceptor::accept_f(Result2<error_code, IChannelPtr> res)
	{
		TAcceptorPtr a;
		{
			mutex::scoped_lock sl(_mtx);
			if(!_inProcess)
			{
				res(make_error_code(errc::operation_not_permitted), IChannelPtr());
				return;
			}

			assert(_acceptor);
			a = _acceptor;
		}

		error_code ec;
		TSocketPtr sock = _sslContext?TSocketPtr():TSocketPtr(new TSocket(io()));
		TSocketSslPtr sockSsl = _sslContext?TSocketSslPtr(new TSocketSsl(io(), *_sslContext)):TSocketSslPtr();

		Result<error_code> ecRes;
		if(sockSsl)
		{
			a->async_accept(sockSsl->lowest_layer(), ecRes);
		}
		else
		{
			a->async_accept(*sock, ecRes);
		}

		ec = ecRes;

		if(ec)
		{
			//fail
			if(errc::operation_canceled == ec.value())
			{
				//ok
				return;
			}

			WLOG("async_accept failed: "<<ec.message()<<"("<<ec.value()<<")");
			return;
		}

		if(sockSsl)
		{
			//делать handshake
			ecRes.reset();
			sockSsl->async_handshake(ssl::stream_base::server, ecRes);
			ec = ecRes;

			if(ec)
			{
				//fail
				if(errc::operation_canceled == ec.value())
				{
					//ok
					return;
				}

				WLOG("async_handshake failed: "<<ec.message()<<"("<<ec.value()<<")");
				return;
			}

			res(error_code(), IChannelPtr(new ChannelSocket(sockSsl)));
		}
		else//if(_sslContext)
		{
			res(error_code(), IChannelPtr(new ChannelSocket(sock)));
		}
	}



	//////////////////////////////////////////////////////////////////////////
	Acceptor::Acceptor()
		: _inProcess(false)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	Acceptor::~Acceptor()
	{
		unlisten();
	}

	//////////////////////////////////////////////////////////////////////////
	Result<error_code> Acceptor::listen(const char *host, const char *service, bool useSsl)
	{
		Result<error_code> res;
		spawn(bind(&Acceptor::listen_f, shared_from_this(), res, std::string(host), std::string(service), useSsl));
		return res;
	}

	//////////////////////////////////////////////////////////////////////////
	Result2<error_code, IChannelPtr> Acceptor::accept()
	{
		Result2<error_code, IChannelPtr> res;
		spawn(bind(&Acceptor::accept_f, shared_from_this(), res));
		return res;
	}

	//////////////////////////////////////////////////////////////////////////
	void Acceptor::unlisten()
	{
		mutex::scoped_lock sl(_mtx);
		if(_inProcess)
		{
			assert(_acceptor);
			assert(_sslContext);

			error_code ec;
			_acceptor->close(ec);
			_acceptor.reset();
			_sslContext.reset();
			_inProcess = false;
		}
	}
}