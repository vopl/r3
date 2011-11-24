#include "stdafx.h"
#include "channelSocketImpl.hpp"
#include "utils/fixEndian.hpp"

namespace net
{
	//////////////////////////////////////////////////////////////////////////
	ChannelSocketImpl::STransferStateSend::STransferStateSend(
		const SPacket &packet, 
		ChannelSocketImplPtr ch, 
		function<void ()> ok,
		function<void (system::error_code)> fail)
		: _ok(ok)
	{
		_packet = packet;
		_header[0] = 0;
		_ch = ch;
		_transferedSize = 0;
		_fail = fail;
	}

	//////////////////////////////////////////////////////////////////////////
	ChannelSocketImpl::STransferStateReceive::STransferStateReceive(
		ChannelSocketImplPtr ch, 
		function<void (const SPacket &)> ok,
		function<void (system::error_code)> fail)
		: _ok(ok)
	{
		_header[0] = 0;
		_ch = ch;
		_transferedSize = 0;
		_fail = fail;
	}

	//////////////////////////////////////////////////////////////////////////
	ChannelSocketImpl::ChannelSocketImpl(TSocketPtr socket)
		: _socket(socket)
		, _strand(socket->get_io_service())
	{
	}

	//////////////////////////////////////////////////////////////////////////
	ChannelSocketImpl::~ChannelSocketImpl()
	{
		close();
	}


	//////////////////////////////////////////////////////////////////////////
	void ChannelSocketImpl::receive(
		function<void (const SPacket &)> ok,
		function<void (system::error_code)> fail)
	{
		STransferStateReceivePtr ts(new STransferStateReceive(static_pointer_cast<ChannelSocketImpl>(shared_from_this()), ok, fail));
		onReceive(ts, system::error_code(), 0);
	}



	//////////////////////////////////////////////////////////////////////////
	void ChannelSocketImpl::send(
		const SPacket &p,
		function<void ()> ok,
		function<void (system::error_code)> fail)
	{
		STransferStateSendPtr ts(new STransferStateSend(p, static_pointer_cast<ChannelSocketImpl>(shared_from_this()), ok, fail));
		ts->_header[0] = utils::fixEndian(ts->_packet._size);
		onSend(ts, system::error_code(), 0);
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelSocketImpl::onReceive(STransferStateReceivePtr ts, system::error_code ec, size_t size)
	{
		if(ec)
		{
			if(ts->_fail)
			{
				ts->_fail(ec);
			}
			return;
		}

		ts->_transferedSize += size;
		if(ts->_transferedSize < sizeof(ts->_header))
		{
			ts->_ch->_socket->async_read_some(
				buffer((char *)&ts->_header, sizeof(ts->_header)-ts->_transferedSize), 
				ts->_ch->_strand.wrap(
					bind(
						&ChannelSocketImpl::onReceive,
						ts, 
						_1, _2
					)
				)
			);
		}
		else if(ts->_transferedSize == sizeof(ts->_header))
		{
			ts->_packet._size = utils::fixEndian(ts->_header[0]);
			ts->_packet._data.reset(new char[ts->_packet._size]);

			ts->_ch->_socket->async_read_some(
				buffer(ts->_packet._data.get(), ts->_packet._size), 
				ts->_ch->_strand.wrap(
					bind(
						&ChannelSocketImpl::onReceive,
						ts, 
						_1, _2
					)
				)
			);
		}
		else if(ts->_transferedSize < sizeof(ts->_header)+ ts->_packet._size)
		{
			size_t dataTransferedSize = ts->_transferedSize-sizeof(ts->_header);
			ts->_ch->_socket->async_read_some(
				buffer(
					ts->_packet._data.get()+dataTransferedSize, 
					ts->_packet._size-dataTransferedSize), 
				ts->_ch->_strand.wrap(
					bind(
						&ChannelSocketImpl::onReceive,
						ts, 
						_1, _2
					)
				)
			);
		}
		else
		{
			assert(ts->_transferedSize == sizeof(ts->_header)+ts->_packet._size);
			ts->_ok(ts->_packet);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ChannelSocketImpl::onSend(STransferStateSendPtr ts, system::error_code ec, size_t size)
	{
		if(ec)
		{
			if(ts->_fail)
			{
				ts->_fail(ec);
			}
			return;
		}

		ts->_transferedSize += size;
		if(ts->_transferedSize < sizeof(ts->_header))
		{
			boost::array<boost::asio::const_buffers_1, 2> packedData = 
			{
				const_buffers_1((char *)&ts->_header+ts->_transferedSize, sizeof(ts->_header)-ts->_transferedSize), 
				const_buffers_1(ts->_packet._data.get(), ts->_packet._size), 
			};

			ts->_ch->_socket->async_write_some(
				packedData, 
				ts->_ch->_strand.wrap(
					bind(
						&ChannelSocketImpl::onSend,
						ts, 
						_1, _2
					)
				)
			);

		}
		else if(ts->_transferedSize < sizeof(ts->_header)+ts->_packet._size)
		{
			size_t dataTransferedSize = ts->_transferedSize-sizeof(ts->_header);
			boost::asio::const_buffers_1 packedData(
				ts->_packet._data.get()+dataTransferedSize, 
				ts->_packet._size-dataTransferedSize);

			ts->_ch->_socket->async_write_some(
				packedData, 
				ts->_ch->_strand.wrap(
					bind(
						&ChannelSocketImpl::onSend,
						ts, 
						_1, _2
					)
				)
			);
		}
		else
		{
			assert(ts->_transferedSize == sizeof(ts->_header)+ts->_packet._size);
			ts->_ok();
		}
	}


	//////////////////////////////////////////////////////////////////////////
	void ChannelSocketImpl::close()
	{
		boost::system::error_code ec;
		_socket->lowest_layer().shutdown(boost::asio::socket_base::shutdown_both, ec);
		_socket->lowest_layer().close(ec);
	}
}
