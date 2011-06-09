#include "stdafx.h"
#include "serviceImpl.hpp"
#include "utils/ntoa.hpp"
#include "channelImpl.hpp"
#include <iostream>

namespace net
{
	using namespace boost::asio;

	//////////////////////////////////////////////////////////////////////////
	void ServiceImpl::workerProc(ServiceWorkerPtr swp)
	{
		std::cout<<"workerProc start\n";
		std::cout.flush();

		_handler->onStartInThread(_iface);

		boost::system::error_code ec;
		for(;;)
		{
			_io_service.run(ec);
			if(swp->_stop)
			{
				break;
			}
			std::cout<<"workerProc sleep\n";
			std::cout.flush();
			swp->_thread.sleep(boost::get_system_time() + boost::posix_time::milliseconds(500));
		}

		std::cout<<"workerProc stop\n";
		std::cout.flush();

		_handler->onStopInThread();
	}

	//////////////////////////////////////////////////////////////////////////
	const std::string &ServiceImpl::handleGetPasswordSsl()
	{
		std::cout<<__FUNCTION__<<std::endl;
		return _ssl_password;
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceImpl::makeAcceptSsl()
	{
		std::cout<<__FUNCTION__<<std::endl;
		TSslSocket_ptr socket(new TSslSocket(_io_service, _contextSsl));

		_acceptorSsl.async_accept(socket->lowest_layer(),
			boost::bind(&ServiceImpl::handleAcceptSsl, this,
			socket,
			placeholders::error));
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceImpl::handleAcceptSsl(TSslSocket_ptr socket, const boost::system::error_code& e)
	{
		std::cout<<__FUNCTION__<<std::endl;
		//if(swp->_stop) return;

		makeAcceptSsl();

		if(e)
		{
			std::cerr<<"TransportAsio::handleAcceptSsl: "<<e.message()<<"("<<e.value()<<")"<<std::endl;
			return;
		}

		socket->async_handshake(
			ssl::stream_base::server,
			boost::bind(
				&ServiceImpl::handleServerHandshakeSsl, this,
				socket,
				placeholders::error));
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceImpl::handleServerHandshakeSsl(TSslSocket_ptr socket, const boost::system::error_code& e)
	{
		std::cout<<__FUNCTION__<<std::endl;
		if(e)
		{
			//std::cerr<<"TransportAsio::handleHandshakeSsl: "<<e.message()<<"("<<e.value()<<")"<<std::endl;
			socket->lowest_layer().close();
			return;
		}

		Channel_ptr channel(new ChannelImpl(socket));

		_handler->onAccept(channel);
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceImpl::handleConnectSsl(TSslSocket_ptr socket, const boost::system::error_code& e)
	{
		std::cout<<__FUNCTION__<<std::endl;
		if(e)
		{
			return;
		}
		socket->async_handshake(
			ssl::stream_base::client,
			boost::bind(
				&ServiceImpl::handleClientHandshakeSsl, this,
				socket,
				placeholders::error));

	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceImpl::handleClientHandshakeSsl(TSslSocket_ptr socket, const boost::system::error_code& e)
	{
		std::cout<<__FUNCTION__<<std::endl;
		if(e)
		{
			return;
		}

	}



	//////////////////////////////////////////////////////////////////////////
	ServiceImpl::ServiceImpl(Service *iface, IServiceHandler *handler)
		: _iface(iface)
		, _handler(handler)
		, _io_service()
		, _contextSsl(_io_service, ssl::context::sslv23)
		, _acceptorSsl(_io_service)
	{
		std::cout<<__FUNCTION__<<std::endl;
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceImpl::balance(size_t numThreads)
	{
		std::cout<<__FUNCTION__<<std::endl;
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

		while(count<numThreads)
		{
			ServiceWorkerPtr swp(new ServiceWorker);
			swp->_stop = false;
			swp->_thread = boost::thread(boost::bind(&ServiceImpl::workerProc, this, swp));
 			_workers.push_back(swp);
			count++;
		}

		_work.reset();
		_io_service.stop();

		BOOST_FOREACH(ServiceWorkerPtr &swp, stopped)
		{
			swp->_thread.join();
		}

		if(numThreads)
		{
			_io_service.reset();
			_work.reset(new boost::asio::io_service::work(_io_service));
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceImpl::listen(const char *host, short port)
	{
		std::cout<<__FUNCTION__<<std::endl;
		_contextSsl.set_options(
			ssl::context::default_workarounds
			| ssl::context::no_sslv2
			| ssl::context::single_dh_use);
		_contextSsl.set_password_callback(boost::bind(&ServiceImpl::handleGetPasswordSsl, this));

		if(!_ssl_certificate.empty())
		{
			_contextSsl.use_certificate_chain_file(_ssl_certificate);
		}

		if(!_ssl_privateKey.empty())
		{
			_contextSsl.use_private_key_file(_ssl_privateKey, ssl::context::pem);
		}

		if(!_ssl_tmpdh.empty())
		{
			_contextSsl.use_tmp_dh_file(_ssl_tmpdh);
		}

		ip::tcp::resolver resolver(_io_service);
		char sport[32];
		ip::tcp::resolver::query query(host, utils::_ntoa(port, sport));
		ip::tcp::endpoint endpoint = *resolver.resolve(query);


		_acceptorSsl.open(endpoint.protocol());
		_acceptorSsl.set_option(ip::tcp::acceptor::reuse_address(true));
		_acceptorSsl.set_option(socket_base::enable_connection_aborted(true));
		_acceptorSsl.bind(endpoint);
		_acceptorSsl.listen();

		makeAcceptSsl();


	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceImpl::connect(const char *host, short port)
	{
		std::cout<<__FUNCTION__<<std::endl;
		ip::tcp::resolver resolver(_io_service);
		char sport[32];
		ip::tcp::resolver::query query(host, utils::_ntoa(port, sport));
		ip::tcp::endpoint endpoint = *resolver.resolve(query);

		TSslSocket_ptr socket(new TSslSocket(_io_service, _contextSsl));
		socket->lowest_layer().async_connect(endpoint, 
			boost::bind(
				&ServiceImpl::handleConnectSsl, this,
				socket,
				placeholders::error));
	}

}