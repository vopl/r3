#include "stdafx.h"
#include "serviceImpl.hpp"
#include "utils/ntoa.hpp"
#include "channelImpl.hpp"

#define LOG(e) if(e){std::cerr<<__FUNCTION__<<": "<<e.message()<<"("<<e.value()<<")"<<std::endl;}

namespace net
{
	using namespace boost::asio;

	//////////////////////////////////////////////////////////////////////////
	void ServiceImpl::workerProc(ServiceWorkerPtr swp)
	{
// 		std::cout<<"workerProc start\n";
// 		std::cout.flush();

		_handler->onStartInThread(_iface);

		boost::system::error_code ec;
		for(;;)
		{
			_io_service.run(ec);
			if(swp->_stop)
			{
				break;
			}
// 			std::cout<<"workerProc sleep\n";
// 			std::cout.flush();
			swp->_thread.sleep(boost::get_system_time() + boost::posix_time::milliseconds(500));
		}

// 		std::cout<<"workerProc stop\n";
// 		std::cout.flush();

		_handler->onStopInThread();
	}

	//////////////////////////////////////////////////////////////////////////
	const std::string &ServiceImpl::handleGetPassword()
	{
		return _ssl_password;
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceImpl::makeAccept()
	{
		TSocketPtr socket(new TSocket(_io_service, _ssl_context));
		//TSocketPtr socket(new TSocket(_io_service));

		AllocatorPtr alloc = boost::make_shared<Allocator>();

		_acceptor.async_accept(socket->lowest_layer(),
			makeCmaHandler(*alloc, boost::bind(&ServiceImpl::handleAccept, this,
				socket,
				placeholders::error, alloc)));
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceImpl::handleAccept(TSocketPtr socket, const boost::system::error_code& ec, AllocatorPtr alloc)
	{
		if(ec)
		{
			LOG(ec);
			if(_handler) _handler->onError(_iface);
			{
				boost::system::error_code ec;
				socket->shutdown(ec);
				socket->lowest_layer().shutdown(boost::asio::socket_base::shutdown_both, ec);
				socket->lowest_layer().close(ec);
			}
			return;
		}

		makeAccept();

// 		addSock(socket);
// 		_handler->onAccept(ChannelPtr(new ChannelImpl(this, socket)));
		socket->async_handshake(
			ssl::stream_base::server,
			makeCmaHandler(*alloc, boost::bind(
				&ServiceImpl::handleServerHandshake, this,
				socket,
				placeholders::error, alloc)));
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceImpl::handleServerHandshake(TSocketPtr socket, const boost::system::error_code& ec, AllocatorPtr alloc)
	{
		if(ec)
		{
			LOG(ec);
			if(_handler) _handler->onError(_iface);
			{
				boost::system::error_code ec;
				socket->shutdown(ec);
				socket->lowest_layer().shutdown(boost::asio::socket_base::shutdown_both, ec);
				socket->lowest_layer().close(ec);
			}
			return;
		}

		addSock(socket, alloc);
		_handler->onAccept(ChannelPtr(new ChannelImpl(this, socket)));
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceImpl::handleConnect(TSocketPtr socket, const boost::system::error_code& ec, AllocatorPtr alloc)
	{
		if(ec)
		{
			LOG(ec);
			if(_handler) _handler->onError(_iface);
			{
				boost::system::error_code ec;
				socket->shutdown(ec);
				socket->lowest_layer().shutdown(boost::asio::socket_base::shutdown_both, ec);
				socket->lowest_layer().close(ec);
			}
			return;
		}
// 		addSock(socket);
// 		_handler->onConnect(ChannelPtr(new ChannelImpl(this, socket)));
		socket->async_handshake(
			ssl::stream_base::client,
			makeCmaHandler(*alloc, boost::bind(
				&ServiceImpl::handleClientHandshake, this,
				socket,
				placeholders::error, alloc)));
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceImpl::handleClientHandshake(TSocketPtr socket, const boost::system::error_code& ec, AllocatorPtr alloc)
	{
		if(ec)
		{
			LOG(ec);
			if(_handler) _handler->onError(_iface);
			{
				boost::system::error_code ec;
				socket->shutdown(ec);
				socket->lowest_layer().shutdown(boost::asio::socket_base::shutdown_both, ec);
				socket->lowest_layer().close(ec);
			}
			return;
		}

		addSock(socket, alloc);
		_handler->onConnect(ChannelPtr(new ChannelImpl(this, socket)));
	}


	//////////////////////////////////////////////////////////////////////////
	void ServiceImpl::addSock(TSocketPtr socket, AllocatorPtr alloc)
	{
		_io_service.post(_socksPoolStrand.wrap(
			makeCmaHandler(*alloc, boost::bind(&ServiceImpl::handleAddSock, this, socket, alloc))
			));
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceImpl::delSock(TSocketPtr socket)
	{
		_io_service.post(_socksPoolStrand.wrap(
			boost::bind(&ServiceImpl::handleDelSock, this, socket)
			));
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceImpl::closeSocks()
	{
		_io_service.post(_socksPoolStrand.wrap(
			boost::bind(&ServiceImpl::handleCloseSocks, this)
			));
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceImpl::handleAddSock(TSocketPtr socket, AllocatorPtr alloc)
	{
		_socks.insert(socket);
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceImpl::handleDelSock(TSocketPtr socket)
	{
		_socks.erase(socket);
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceImpl::handleCloseSocks()
	{
		boost::system::error_code ec;
		BOOST_FOREACH(TSocketPtr socket, _socks)
		{
			socket->shutdown(ec);
			socket->lowest_layer().shutdown(boost::asio::socket_base::shutdown_both, ec);
			socket->lowest_layer().close(ec);
		}
		_socks.clear();
	}


	//////////////////////////////////////////////////////////////////////////
	ServiceImpl::ServiceImpl(Service *iface, IServiceHandler *handler)
		: _iface(iface)
		, _handler(handler)
		, _io_service()
		, _ssl_context(_io_service, ssl::context::sslv23)
		, _acceptor(_io_service)
		, _socksPoolStrand(_io_service)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	ServiceImpl::~ServiceImpl()
	{

	}


	//////////////////////////////////////////////////////////////////////////
	void ServiceImpl::balance(size_t numThreads)
	{
		if(!numThreads)
		{
			boost::system::error_code ec;
			_acceptor.cancel(ec);
			_acceptor.close(ec);
			closeSocks();
		}

		size_t count = 0;
		BOOST_FOREACH(ServiceWorkerPtr &swp, _workers)
		{
			if(!swp->_stop)
			{
				count++;
			}
		}

		std::vector<ServiceWorkerPtr> stopped;
		for(size_t i(0); i<_workers.size(); i++)
		{
			ServiceWorkerPtr swp = _workers[i];
			if(count > numThreads)
			{
				if(!swp->_stop)
				{
					swp->_stop = true;
					count--;
					_workers.erase(_workers.begin()+i);
					stopped.push_back(swp);
					i--;
				}
			}
		}

		_work.reset();
		_io_service.stop();

		while(count<numThreads)
		{
			ServiceWorkerPtr swp(new ServiceWorker);
			swp->_stop = false;
			swp->_thread = boost::thread(boost::bind(&ServiceImpl::workerProc, this, swp));
 			_workers.push_back(swp);
			count++;
		}


		BOOST_FOREACH(ServiceWorkerPtr &swp, stopped)
		{
			swp->_thread.join();
		}

		if(numThreads)
		{
			_io_service.reset();
			_work.reset(new boost::asio::io_service::work(_io_service));
		}
		else
		{
			_io_service.reset();
			_io_service.poll();
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceImpl::listen(const char *host, short port)
	{
		_ssl_context.set_options(
			ssl::context::default_workarounds
			| ssl::context::no_sslv2
			| ssl::context::single_dh_use);
		_ssl_context.set_password_callback(boost::bind(&ServiceImpl::handleGetPassword, this));

		_ssl_password = "test";
		_ssl_certificate = "server.pem";
		_ssl_privateKey = "server.pem";
		_ssl_tmpdh = "dh512.pem";


		if(!_ssl_certificate.empty())
		{
			_ssl_context.use_certificate_chain_file(_ssl_certificate);
		}

		if(!_ssl_privateKey.empty())
		{
			_ssl_context.use_private_key_file(_ssl_privateKey, ssl::context::pem);
		}

		if(!_ssl_tmpdh.empty())
		{
			_ssl_context.use_tmp_dh_file(_ssl_tmpdh);
		}

		ip::tcp::resolver resolver(_io_service);
		char sport[32];
		ip::tcp::resolver::query query(host, utils::_ntoa(port, sport));
		ip::tcp::endpoint endpoint = *resolver.resolve(query);


		_acceptor.open(endpoint.protocol());
		_acceptor.set_option(ip::tcp::acceptor::reuse_address(true));
		_acceptor.set_option(socket_base::enable_connection_aborted(true));
		_acceptor.bind(endpoint);
		_acceptor.listen();

		makeAccept();


	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceImpl::connect(const char *host, short port)
	{
		ip::tcp::resolver resolver(_io_service);
		char sport[32];
		ip::tcp::resolver::query query(host, utils::_ntoa(port, sport));
		ip::tcp::endpoint endpoint = *resolver.resolve(query);

		TSocketPtr socket(new TSocket(_io_service, _ssl_context));
		//TSocketPtr socket(new TSocket(_io_service));

		AllocatorPtr alloc = boost::make_shared<Allocator>();
		socket->lowest_layer().async_connect(endpoint,
			makeCmaHandler(*alloc, boost::bind(
				&ServiceImpl::handleConnect, this,
				socket,
				placeholders::error, alloc)));
	}

}
