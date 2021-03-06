#include "pch.hpp"
#include "acceptor.hpp"

namespace net
{
	//////////////////////////////////////////////////////////////////////////
	std::string Acceptor::onSslPassword()
	{
		return "test";
	}

	//////////////////////////////////////////////////////////////////////////
	void Acceptor::listen_f(
		Future<error_code> res,
		const function<void(error_code, IChannelPtr)> &onAccept,
		const std::string &host, const std::string &service, bool useSsl)
	{
		TAcceptorPtr acceptor;
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
				ILOG("create ssl context");
				_sslContext.reset(new TSslContext(async::io(), ssl::context::sslv23));

				error_code ec;
				_sslContext->set_options(
					ssl::context::default_workarounds
					| ssl::context::no_sslv2
					| ssl::context::single_dh_use, ec);
				assert(!ec);
				if(ec)
				{
					WLOG("set_options failed: "<<ec.message()<<"("<<ec.value()<<")");
					res(ec);
					return;
				}

				_sslContext->set_password_callback(bind(&Acceptor::onSslPassword, shared_from_this()));
				_sslContext->use_certificate_chain_file("server.pem", ec);
				assert(!ec);
				if(ec)
				{
					WLOG("use_certificate_chain_file failed: "<<ec.message()<<"("<<ec.value()<<")");
					res(ec);
					return;
				}

				_sslContext->use_private_key_file("server.pem", ssl::context::pem, ec);
				assert(!ec);
				if(ec)
				{
					WLOG("use_private_key_file failed: "<<ec.message()<<"("<<ec.value()<<")");
					res(ec);
					return;
				}

				_sslContext->use_tmp_dh_file("dh512.pem", ec);
				assert(!ec);
				if(ec)
				{
					WLOG("use_tmp_dh_file failed: "<<ec.message()<<"("<<ec.value()<<")");
					res(ec);
					return;
				}
			}
			_acceptor.reset(new TAcceptor(async::io()));
			acceptor = _acceptor;
		}

		//резолвить адрес
		ip::tcp::resolver resolver(async::io());

		Future2<error_code, ip::tcp::resolver::iterator> resolveRes;
		resolver.async_resolve(
			ip::tcp::resolver::query(host, service),
			async::bridge(resolveRes));
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
		acceptor->open(resolveRes.data2()->endpoint().protocol());
		acceptor->set_option(ip::tcp::acceptor::reuse_address(true));
		acceptor->set_option(socket_base::enable_connection_aborted(true));
		acceptor->bind(*resolveRes.data2());
		acceptor->listen();


		spawn(bind(res, error_code()));
		accept_f(onAccept, useSsl);
	}

	//////////////////////////////////////////////////////////////////////////
	void Acceptor::accept_f(const function<void(error_code, IChannelPtr)> &onAccept, bool useSsl)
	{
		TAcceptorPtr acceptor;
		TSocketPtr sock;
		TSocketSslPtr sockSsl;
		TSslContextPtr	sslContext;
		error_code ec;

		{
			mutex::scoped_lock sl(_mtx);
			if(!_inProcess)
			{
				onAccept(make_error_code(errc::operation_not_permitted), IChannelPtr());
				return;
			}
			assert(_acceptor);
			acceptor = _acceptor;
			if(useSsl)
			{
				sslContext = _sslContext;
				assert(sslContext);
			}
		}

		if(sslContext)
		{
			sockSsl.reset(new TSocketSsl(async::io(), *sslContext));
		}
		else
		{
			sock.reset(new TSocket(async::io()));
		}

		Future<error_code> ecRes;
		if(sockSsl)
		{
			acceptor->async_accept(sockSsl->lowest_layer(), async::bridge(ecRes));
		}
		else
		{
			acceptor->async_accept(*sock, async::bridge(ecRes));
		}

		ec = ecRes;

		if(ec)
		{
			//fail
			if(errc::operation_canceled == ec || error::operation_aborted == ec)
			{
				//ok
				return;
			}

			WLOG("async_accept failed: "<<ec.message()<<"("<<ec.value()<<")");
			return;
		}
		spawn(bind(&Acceptor::accept_f, shared_from_this(), onAccept, useSsl));

		if(sockSsl)
		{
			//делать handshake
			ecRes.reset();
			sockSsl->async_handshake(ssl::stream_base::server, async::bridge(ecRes));
			ec = ecRes;

			if(ec)
			{
				//fail
				if(errc::operation_canceled == ec)
				{
					//ok
					return;
				}

				WLOG("async_handshake failed: "<<ec.message()<<"("<<ec.value()<<")");
				return;
			}

			spawn(bind(onAccept, error_code(), IChannelPtr(new ChannelSocket(sockSsl, sslContext))));
		}
		else//if(_sslContext)
		{
			spawn(bind(onAccept, error_code(), IChannelPtr(new ChannelSocket(sock))));
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
	Future<error_code> Acceptor::listen(
		const boost::function<void(boost::system::error_code, IChannelPtr)> &onAccept,
		const char *host, const char *service, bool useSsl)
	{
		Future<error_code> res;
		spawn(bind(&Acceptor::listen_f, shared_from_this(), res, onAccept, std::string(host), std::string(service), useSsl));
		return res;
	}

	//////////////////////////////////////////////////////////////////////////
	void Acceptor::unlisten()
	{
		mutex::scoped_lock sl(_mtx);
		if(_inProcess)
		{
			assert(_acceptor);

			error_code ec;
			_acceptor->close(ec);
			_acceptor.reset();
			_sslContext.reset();
			_inProcess = false;
		}
	}
}
