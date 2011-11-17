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
		enum EPacketKind
		{
			epkRaw,
			epkVariant,
		};
		struct OutPacketWrapper
		{
			boost::uint32_t		_sizeNetOrder;
			boost::uint32_t		_flagsNetOrder;

			size_t				_totalSended;
			boost::uint32_t		_flags;

			boost::shared_array<char> _data;
			boost::uint32_t		_size;
			utils::VariantPtr	_variant;
		};
		typedef boost::shared_ptr<OutPacketWrapper> OutPacketWrapperPtr;

		struct InPacketWrapper
		{
			size_t				_totalReceived;
			boost::uint32_t		_size;
			boost::uint32_t		_flags;
			boost::shared_array<char> _data;
		};
		typedef boost::shared_ptr<InPacketWrapper> InPacketWrapperPtr;


		ServiceImpl *_serviceImpl;
		TSocketPtr _socket;
		IChannelHandler *_handler;

		boost::mutex _sendQueueMtx;
		std::queue<OutPacketWrapperPtr> _sendQueue;

		void sendImpl(OutPacketWrapperPtr packet);

	public:
		ChannelImpl(ServiceImpl *serviceImpl, TSocketPtr socket);
		~ChannelImpl();
		virtual void setHandler(IChannelHandler *);
		virtual void send(boost::shared_array<char> data, size_t size);
		virtual void send(utils::VariantPtr v);
		virtual void close();

	private:
		void handleSend(ChannelImplPtr selfKeeper, OutPacketWrapperPtr packet, const boost::system::error_code& ec, const size_t sended, AllocatorPtr alloc);
		void handleSendComplete(ChannelImplPtr selfKeeper, OutPacketWrapperPtr packet);

	private:
		void makeReceive(AllocatorPtr alloc);
		void handleReceive(ChannelImplPtr selfKeeper, InPacketWrapperPtr packet, const boost::system::error_code& ec, const size_t received, AllocatorPtr alloc);
		void handleReceiveComplete(ChannelImplPtr selfKeeper, InPacketWrapperPtr packet);
	};


	//////////////////////////////////////////////////////////////////////////

}

#endif
