#ifndef _R3_CLIENT_INSTANCE_HPP_
#define _R3_CLIENT_INSTANCE_HPP_

#include "net/service.hpp"

namespace r3
{


	//////////////////////////////////////////////////////////////////////////
	namespace client
	{
		//////////////////////////////////////////////////////////////////////////
		class Instance
			: public QObject
			, public net::IServiceHandler
			, public net::IChannelHandler
		{
			Q_OBJECT

		protected:
			boost::mutex _mtx;

			std::string _host;
			short		_port;
			size_t		_threads;

			net::Service _netsrv;

			size_t		_favorNumChannels;
			std::set<net::ChannelPtr> _channels;
		public:
			Instance();
			~Instance();

			void setAddress(const std::string &host, short port);
			void balance(size_t numChannels);

		public slots:
			bool send(boost::shared_array<char> data, size_t size);
			bool send(const utils::Variant &v);
			bool send(const utils::VariantPtr &v);

		private slots:
			void tconnected(size_t channels);
			void treceive(boost::shared_array<char> data, size_t size);
			void treceive(const utils::VariantPtr &v);

		signals:
			void connected(size_t channels);
			void receive(boost::shared_array<char> data, size_t size);
			void receive(const utils::VariantPtr &v);

		private:
			//for servece
			virtual void onStartInThread(net::Service *netsrv);
			virtual void onError(net::Service *netsrv, net::EStage es, const boost::system::error_code& ec);
			virtual void onAccept(net::ChannelPtr channel);
			virtual void onConnect(net::ChannelPtr channel);
			virtual void onStopInThread();

		private:
			//for channel
			virtual void onReceive(const net::ChannelPtr &channel, boost::shared_array<char> data, size_t size);
			virtual void onReceive(const net::ChannelPtr &channel, const utils::VariantPtr vptr);
			virtual void onError(const net::ChannelPtr &channel, net::EStage es, const boost::system::error_code& ec);
			virtual void onClose(const net::ChannelPtr &channel);

		private:
			void balance();

		};
	}
}
#endif
