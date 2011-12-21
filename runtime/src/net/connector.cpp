#include "pch.h"
#include "connector.hpp"
#include "channelSocket.hpp"

namespace net
{
	//////////////////////////////////////////////////////////////////////////
	std::string Connector::onSslPassword()
	{
		return "test";
	}

	//////////////////////////////////////////////////////////////////////////
	void Connector::onListenResolve(
		SListenStatePtr ls,
		const system::error_code& ec,
		ip::tcp::resolver::iterator iterator)
	{
		if(ec)
		{
			unlisten(ls->_addr, ls);
			ls->_fail(ec);
			return;
		}

		mutex::scoped_lock sl(_mtx);
		ls->_resolver.reset();
		ls->_acceptor.reset(new ip::tcp::acceptor(async::io()));
		ls->_acceptor->open(iterator->endpoint().protocol());
		ls->_acceptor->set_option(ip::tcp::acceptor::reuse_address(true));
		ls->_acceptor->set_option(socket_base::enable_connection_aborted(true));
		ls->_acceptor->bind(*iterator);
		ls->_acceptor->listen();

		TSocketPtr socket(new TSocket(async::io(), *_sslContext));
		ls->_acceptor->async_accept(
			socket->lowest_layer(),
			bind(&Connector::onListenAccept, shared_from_this(),
				ls,
				_1,
				socket));


	}

	//////////////////////////////////////////////////////////////////////////
	void Connector::onListenAccept(
		SListenStatePtr ls, 
		const system::error_code& ec,
		TSocketPtr socket)
	{
		if(ec)
		{
			ls->_fail(ec);
			return;
		}

		{
			TSocketPtr socket(new TSocket(async::io(), *_sslContext));
			ls->_acceptor->async_accept(
				socket->lowest_layer(),
				bind(&Connector::onListenAccept, shared_from_this(),
					ls,
					_1,
					socket));
		}

		socket->async_handshake(
			ssl::stream_base::server,
			bind(&Connector::onListenHandshake, shared_from_this(),
				ls,
				_1,
				socket));
	}

	//////////////////////////////////////////////////////////////////////////
	void Connector::onListenHandshake(
		SListenStatePtr ls, 
		const system::error_code& ec,
		TSocketPtr socket)
	{
		if(ec)
		{
			ls->_fail(ec);
			return;
		}

		//addSock(socket, alloc);

		IChannelPtr channel(new ChannelSocket(socket));
		ls->_ok(channel);
	}










	//////////////////////////////////////////////////////////////////////////
	void Connector::onConnectResolve(
		SConnectStatePtr cs,
		const system::error_code& ec,
		ip::tcp::resolver::iterator iterator)
	{
		if(ec)
		{
			cs->_fail(ec);
			return;
		}
		TSocketPtr socket(new TSocket(async::io(), *_sslContext));
		socket->lowest_layer().async_connect(
			*iterator,
			bind(&Connector::onConnect, shared_from_this(),
				cs,
				_1,
				socket));


	}

	//////////////////////////////////////////////////////////////////////////
	void Connector::onConnect(
		SConnectStatePtr cs, 
		const system::error_code& ec,
		TSocketPtr socket)
	{
		if(ec)
		{
			cs->_fail(ec);
			return;
		}

		socket->async_handshake(
			ssl::stream_base::client,
			bind(&Connector::onConnectHandshake, shared_from_this(),
				cs,
				_1,
				socket));
	}

	//////////////////////////////////////////////////////////////////////////
	void Connector::onConnectHandshake(
		SConnectStatePtr cs, 
		const system::error_code& ec,
		TSocketPtr socket)
	{
		if(ec)
		{
			cs->_fail(ec);
			return;
		}

		//addSock(socket, alloc);

		IChannelPtr channel(new ChannelSocket(socket));
		cs->_ok(channel);
	}







	//////////////////////////////////////////////////////////////////////////
	bool Connector::unlisten(const TAddr &addr, SListenStatePtr ls)
	{
		mutex::scoped_lock sl(_mtx);
		TMAddrListens::iterator miter = _listens.find(addr);
		if(_listens.end() != miter)
		{
			TSListens &s = miter->second;

			if(ls)
			{
				TSListens::iterator siter = s.find(ls);
				if(s.end() != siter)
				{
					if(ls->_acceptor)
					{
						system::error_code ec;
						ls->_acceptor->cancel(ec);
						ls->_acceptor->close(ec);
					}
					if(ls->_resolver)
					{
						ls->_resolver->cancel();
					}
					s.erase(siter);
					if(s.empty())
					{
						_listens.erase(miter);
					}
					return true;
				}
				return false;
			}
			else
			{
				BOOST_FOREACH(const SListenStatePtr &ls, s)
				{
					if(ls->_acceptor)
					{
						system::error_code ec;
						ls->_acceptor->cancel(ec);
						ls->_acceptor->close(ec);
					}
					if(ls->_resolver)
					{
						ls->_resolver->cancel();
					}
				}
				_listens.erase(miter);
				return true;
			}
		}
		return false;
	}


	//////////////////////////////////////////////////////////////////////////
	Connector::Connector()
	{

	}


	//////////////////////////////////////////////////////////////////////////
	void Connector::initialize()
	{
		assert(!_sslContext);

		_sslContext.reset(new TSslContext(async::io(), ssl::context::sslv23));

		_sslContext->set_options(
			ssl::context::default_workarounds
			| ssl::context::no_sslv2
			| ssl::context::single_dh_use);

		_sslContext->set_password_callback(bind(&onSslPassword));


		boost::system::error_code ec;
		_sslContext->use_certificate_chain_file("server.pem", ec);
		_sslContext->use_private_key_file("server.pem", ssl::context::pem, ec);
		_sslContext->use_tmp_dh_file("dh512.pem", ec);
	}

	//////////////////////////////////////////////////////////////////////////
	Connector::~Connector()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	void Connector::listen(
		const char *host, const char *service,
		function<void (IChannelPtr)> ok,
		function<void (system::error_code)> fail)
	{
		SListenStatePtr ls(new SListenState);
		ls->_addr = std::make_pair(host, service);
		ls->_resolver.reset(new ip::tcp::resolver(async::io()));
		ls->_ok = ok;
		ls->_fail = fail;

		{
			boost::mutex::scoped_lock sl(_mtx);
			_listens[ls->_addr].insert(ls);
		}

		ls->_resolver->async_resolve(
			ip::tcp::resolver::query(host, service), 
			bind(&Connector::onListenResolve, shared_from_this(),
				ls, _1, _2));
	}

	//////////////////////////////////////////////////////////////////////////
	bool Connector::unlisten(const char *host, const char *service)
	{
		return unlisten(std::make_pair(host, service), SListenStatePtr());
	}

	//////////////////////////////////////////////////////////////////////////
	void Connector::connect(
		const char *host, const char *service,
		function<void (IChannelPtr)> ok,
		function<void (system::error_code)> fail)
	{
		SConnectStatePtr cs(new SConnectState);
		cs->_resolver.reset(new ip::tcp::resolver(async::io()));
		cs->_ok = ok;
		cs->_fail = fail;

		cs->_resolver->async_resolve(
			ip::tcp::resolver::query(host, service), 
			bind(&Connector::onConnectResolve, shared_from_this(),
				cs, _1, _2));
	}

}
