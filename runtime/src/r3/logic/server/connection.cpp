#include "stdafx.h"
#include "connection.hpp"
#include "r3/server/instance.hpp"
#include "utils/streambufOnArray.hpp"

namespace r3
{
	namespace logic
	{
		namespace server
		{
			//////////////////////////////////////////////////////////////////////////
			Connection::Connection(net::Channel_ptr channel)
				: r3::protocol::server::Connection(0,NULL)
				, _channel(channel)
			{
				_channel->setHandler(this);
			}
			
			//////////////////////////////////////////////////////////////////////////
			Connection::~Connection()
			{
				_channel->setHandler(NULL);
			}

			//////////////////////////////////////////////////////////////////////////
			void Connection::close()
			{
				_channel->close();
			}

			//////////////////////////////////////////////////////////////////////////
			void Connection::onReceive(net::Channel_ptr channel, boost::shared_array<char> data, size_t size)
			{
				Path cpi;
				EventBase *evt = NULL;

				try
				{
					utils::StreambufOnArray sbuf(data, size);
					{
						std::istream is(&sbuf);
						utils::serialization::polymorphic_binary_portable_iarchive ia(is, boost::archive::no_header|boost::archive::no_codecvt);

						ia >> BOOST_SERIALIZATION_NVP(cpi);
						ia >> BOOST_SERIALIZATION_NVP(evt);
					}

					this->dispatch(cpi, evt);
				}
				catch(...)
				{
					std::cerr<<"exception in "<<__FUNCTION__<<std::endl;
				}
				delete evt;
			}
			
			//////////////////////////////////////////////////////////////////////////
			void Connection::onError(net::Channel_ptr channel)
			{
				_channel->close();
				r3::server::instance()->onConnectionError(shared_from_this());
			}
			
			//////////////////////////////////////////////////////////////////////////
			void Connection::onClose(net::Channel_ptr channel)
			{
				r3::server::instance()->onConnectionClose(shared_from_this());
			}
			
			//////////////////////////////////////////////////////////////////////////
			void Connection::fireImpl(const Path &cpi, const EventBase *evt)
			{
				utils::StreambufOnArray sbuf;
				{
					std::ostream os(&sbuf);
					utils::serialization::polymorphic_binary_portable_oarchive oa(os, boost::archive::no_header|boost::archive::no_codecvt);

					oa << BOOST_SERIALIZATION_NVP(cpi);
					oa << BOOST_SERIALIZATION_NVP(evt);
				}
				_channel->send(sbuf.data(), sbuf.size());
			}

			//////////////////////////////////////////////////////////////////////////
			void Connection::handle(const Event_login &evt)
			{
				std::cout<<__FUNCTION__<<std::endl;
				std::cout<<evt.login.value()<<", "<<evt.password.value()<<std::endl;

				Event_session evts;
				evts.sid=1;
				fire(evts);
			}


		}
	}
}
