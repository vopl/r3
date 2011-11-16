#ifndef _NET_CHANNELIMPL_HPP_
#define _NET_CHANNELIMPL_HPP_

#include "cmaHandler.hpp"

namespace net
{
 	//typedef boost::asio::ip::tcp::socket TSocket;
	typedef boost::asio::ssl::stream<boost::asio::ip::tcp::socket> TSocket;
	typedef boost::shared_ptr<TSocket> TSocket_ptr;


	class ChannelImpl;
	typedef boost::shared_ptr<ChannelImpl> ChannelImpl_ptr;

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
			size_t			_totalSended;
			boost::uint32_t	_sizeNetOrder;
			boost::uint32_t	_crc32NetOrder;//4 старших бита - вид
			boost::shared_array<char> _data;
			boost::uint32_t	_size;
		};
		typedef boost::shared_ptr<OutPacketWrapper> OutPacketWrapper_ptr;

		struct InPacketWrapper
		{
			size_t				_totalReceived;
			boost::uint32_t		_size;
			EPacketKind			_kind;
			boost::uint32_t		_crc32;
			boost::shared_array<char> _data;
		};
		typedef boost::shared_ptr<InPacketWrapper> InPacketWrapper_ptr;


		ServiceImpl *_serviceImpl;
		TSocket_ptr _socket;
		IChannelHandler *_handler;

		boost::mutex _sendQueueMtx;
		std::queue<OutPacketWrapper_ptr> _sendQueue;

		void sendImpl(boost::shared_array<char> data, size_t size, EPacketKind kind);

	public:
		ChannelImpl(ServiceImpl *serviceImpl, TSocket_ptr socket);
		~ChannelImpl();
		virtual void setHandler(IChannelHandler *);
		virtual void send(boost::shared_array<char> data, size_t size);
		virtual void send(const utils::Variant &v);
		virtual void close();

	private:
		void handleSend(ChannelImpl_ptr selfKeeper, OutPacketWrapper_ptr packet, const boost::system::error_code& ec, const size_t sended, Allocator_ptr alloc);

	private:
		void makeReceive();
		void handleReceive(ChannelImpl_ptr selfKeeper, InPacketWrapper_ptr packet, const boost::system::error_code& ec, const size_t received, Allocator_ptr alloc);
		void handleReceiveComplete(ChannelImpl_ptr selfKeeper, boost::shared_array<char> data, size_t size, EPacketKind kind, Allocator_ptr alloc);
	};


	//////////////////////////////////////////////////////////////////////////

}

#endif
