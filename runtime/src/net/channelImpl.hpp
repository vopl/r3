#ifndef _NET_CHANNELIMPL_HPP_
#define _NET_CHANNELIMPL_HPP_


namespace net
{
	typedef boost::asio::ip::tcp::socket TRawSocket;
	typedef boost::asio::ssl::stream<TRawSocket> TSslSocket;
	typedef boost::shared_ptr<TSslSocket> TSslSocket_ptr;


	class ChannelImpl;
	typedef boost::shared_ptr<ChannelImpl> ChannelImpl_ptr;
	//////////////////////////////////////////////////////////////////////////
	class ChannelImpl
		: public Channel
		, public boost::enable_shared_from_this<ChannelImpl>
	{
		struct OutPacketWrapper
		{
			size_t			_totalSended;
			boost::uint32_t	_sizeNetOrder;
			boost::uint32_t	_crc32NetOrder;
			const char		*_data;
			boost::uint32_t	_size;
		};
		typedef boost::shared_ptr<OutPacketWrapper> OutPacketWrapper_ptr;

		struct InPacketWrapper
		{
			size_t				_totalReceived;
			boost::uint32_t		_size;
			boost::uint32_t		_crc32;
			std::vector<char>	_data;
		};
		typedef boost::shared_ptr<InPacketWrapper> InPacketWrapper_ptr;

		TSslSocket_ptr _socket;
		IChannelHandler *_handler;
	public:
		ChannelImpl(TSslSocket_ptr socket);
		virtual void setHandler(IChannelHandler *);
		virtual void send(const char *data, size_t size);
		virtual void close();

	private:
		void handleSend(ChannelImpl_ptr selfKeeper, OutPacketWrapper_ptr packet, const boost::system::error_code& ec, const size_t sended);

	private:
		void makeReceive();
		void handleReceive(ChannelImpl_ptr selfKeeper, InPacketWrapper_ptr packet, const boost::system::error_code& ec, const size_t received);
	};


	//////////////////////////////////////////////////////////////////////////

}

#endif
