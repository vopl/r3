#ifndef _NET_CHANNEL_HPP_
#define _NET_CHANNEL_HPP_

#include <boost/cstdint.hpp>
#include <boost/shared_array.hpp>
#include <boost/function.hpp>
#include <boost/system/error_code.hpp>

namespace net
{
	//////////////////////////////////////////////////////////////////////////
	struct SPacket
	{
		boost::shared_array<char> _data;
		boost::uint32_t _size;

		SPacket();
		SPacket(boost::shared_array<char> data, boost::uint32_t size);
	};

	//////////////////////////////////////////////////////////////////////////
	class ChannelImplBase;
	class Channel
	{
	protected:
		typedef boost::shared_ptr<ChannelImplBase> ImplPtr;
		ImplPtr _impl;

	public:
		Channel(ImplPtr impl);

		void receive(
			boost::function<void (const SPacket &)> ok,
			boost::function<void (boost::system::error_code)> fail = boost::function<void (boost::system::error_code)>());

		void send(
			const SPacket &p,
			boost::function<void ()> ok,
			boost::function<void (boost::system::error_code)> fail = boost::function<void (boost::system::error_code)>());

		void close();

		bool operator<(const Channel &with) const;
	};
}
#endif
