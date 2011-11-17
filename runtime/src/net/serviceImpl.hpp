#ifndef _NET_SERVICEIMPL_HPP_
#define _NET_SERVICEIMPL_HPP_

#include "net/service.hpp"
#include "channelImpl.hpp"
#include "cmaHandler.hpp"
#include <set>

namespace net
{
	class ServiceImpl;

	struct ServiceWorker
	{
		boost::thread		_thread;
		volatile bool		_stop;
	};
	typedef boost::shared_ptr<ServiceWorker> ServiceWorkerPtr;

	//////////////////////////////////////////////////////////////////////////
	class ServiceImpl
	{
		Service							*_iface;
		IServiceHandler					*_handler;


		boost::asio::io_service			_io_service;
		boost::shared_ptr<boost::asio::io_service::work>	_work;
		boost::asio::ip::tcp::acceptor	_acceptor;

		boost::asio::ssl::context		_ssl_context;
		std::string						_ssl_certificate;
		std::string						_ssl_privateKey;
		std::string						_ssl_tmpdh;
		std::string						_ssl_password;

		std::vector<ServiceWorkerPtr>	_workers;


		boost::asio::io_service::strand	_socksPoolStrand;
		std::set<TSocketPtr>			_socks;
		volatile bool					_stop;

	private:
		void workerProc(ServiceWorkerPtr swp);

	private:
		const std::string &handleGetPassword();

		void makeAccept();
		void handleAccept(TSocketPtr socket, const boost::system::error_code& e, AllocatorPtr alloc);
		void handleServerHandshake(TSocketPtr socket, const boost::system::error_code& e, AllocatorPtr alloc);

		void handleConnect(TSocketPtr socket, const boost::system::error_code& e, AllocatorPtr alloc);
		void handleClientHandshake(TSocketPtr socket, const boost::system::error_code& e, AllocatorPtr alloc);

	public:
		void addSock(TSocketPtr socket, AllocatorPtr alloc);
		void delSock(TSocketPtr socket);
	private:
		void closeSocks();
		void handleAddSock(TSocketPtr socket, AllocatorPtr alloc);
		void handleDelSock(TSocketPtr socket);
		void handleCloseSocks();
	public:
		ServiceImpl(Service *iface, IServiceHandler *);
		~ServiceImpl();

		void balance(size_t numThreads);

		bool listen(const char *host, short port);
		bool connect(const char *host, short port);
	};
}
#endif
