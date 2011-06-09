#ifndef _NET_CHANNELIMPL_HPP_
#define _NET_CHANNELIMPL_HPP_


namespace net
{
	typedef boost::asio::ip::tcp::socket TRawSocket;
	typedef boost::asio::ssl::stream<TRawSocket> TSslSocket;
	typedef boost::shared_ptr<TSslSocket> TSslSocket_ptr;


	//////////////////////////////////////////////////////////////////////////
	class ChannelImpl
		: public Channel
	{
		TSslSocket_ptr _socket;
		IChannelHandler *_handler;
	public:
		ChannelImpl(TSslSocket_ptr socket);
		virtual void setHandler(IChannelHandler *);
		virtual void send(const char *data, size_t size);
		virtual void close();

	private:
		void handleSend(const char *data, size_t size, const boost::system::error_code& ec, const size_t sended);
	};


	//////////////////////////////////////////////////////////////////////////

}

#endif
