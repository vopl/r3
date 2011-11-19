#ifndef _NET_CHANNELIMPL_HPP_
#define _NET_CHANNELIMPL_HPP_

#include "cmaHandler.hpp"

namespace net
{
 	//typedef boost::asio::ip::tcp::socket TSocket;
	typedef boost::asio::ssl::stream<boost::asio::ip::tcp::socket> TSocket;
	typedef boost::shared_ptr<TSocket> TSocketPtr;


	class ChannelImpl;
	typedef boost::shared_ptr<ChannelImpl> ChannelImplPtr;

	class ServiceImpl;

	//////////////////////////////////////////////////////////////////////////
	class ChannelImpl
		: public Channel
		, public boost::enable_shared_from_this<ChannelImpl>
	{
		struct PacketWrapper
			: SPacket
		{
			boost::uint32_t _headerNetOrder[3];

			PacketWrapper();
			PacketWrapper(const SPacket &p);
		};

		typedef boost::shared_ptr<PacketWrapper> PacketWrapperPtr;


		ServiceImpl *_serviceImpl;
		TSocketPtr _socket;
		IChannelHandler *_handler;

		boost::mutex _sendQueueMtx;
		std::queue<PacketWrapperPtr> _sendQueue;

	public:
		ChannelImpl(ServiceImpl *serviceImpl, TSocketPtr socket);
		~ChannelImpl();
		virtual void setHandler(IChannelHandler *handler);
		virtual void send(const SPacket &p);
		virtual void close();
		void makeReceive();

	private:
		void handleSend(ChannelImplPtr selfKeeper, PacketWrapperPtr packet, const boost::system::error_code& ec, const size_t sended, AllocatorPtr alloc);

	private:
		void makeReceive(AllocatorPtr alloc);
		void handleReceive(ChannelImplPtr selfKeeper, PacketWrapperPtr packet, const boost::system::error_code& ec, const size_t received, AllocatorPtr alloc);
	};


	//////////////////////////////////////////////////////////////////////////

}

#endif
