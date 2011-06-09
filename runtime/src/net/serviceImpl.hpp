#ifndef _NET_SERVICEIMPL_HPP_
#define _NET_SERVICEIMPL_HPP_

#include "net/service.hpp"
#include "channelImpl.hpp"

namespace net
{
	class ServiceImpl;

	struct ServiceWorker
	{
		boost::thread		_thread;
		bool				_stop;

	};
	typedef boost::shared_ptr<ServiceWorker> ServiceWorkerPtr;

	//////////////////////////////////////////////////////////////////////////
	class ServiceImpl
	{
		Service							*_iface;
		IServiceHandler					*_handler;


		boost::asio::io_service			_io_service;
		boost::shared_ptr<boost::asio::io_service::work>	_work;
		boost::asio::ssl::context		_contextSsl;
		boost::asio::ip::tcp::acceptor	_acceptorSsl;

		std::string						_ssl_certificate;
		std::string						_ssl_privateKey;
		std::string						_ssl_tmpdh;
		std::string						_ssl_password;

		std::vector<ServiceWorkerPtr>	_workers;

	private:
		void workerProc(ServiceWorkerPtr swp);

	private:
		const std::string &handleGetPasswordSsl();

		void makeAcceptSsl();
		void handleAcceptSsl(TSslSocket_ptr socket, const boost::system::error_code& e);
		void handleServerHandshakeSsl(TSslSocket_ptr socket, const boost::system::error_code& e);

		void handleConnectSsl(TSslSocket_ptr socket, const boost::system::error_code& e);
		void handleClientHandshakeSsl(TSslSocket_ptr socket, const boost::system::error_code& e);

	public:
		ServiceImpl(Service *iface, IServiceHandler *);

		void balance(size_t numThreads);

		void listen(const char *host, short port);
		void connect(const char *host, short port);
	};
}
#endif
