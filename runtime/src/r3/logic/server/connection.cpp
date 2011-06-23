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
				: r3::protocol::server::Connection()
				, _channel(channel)
			{
				_channel->setHandler(this);
			}
			
			//////////////////////////////////////////////////////////////////////////
			Connection::~Connection()
			{
				_channel->setHandler(NULL);

				if(one_Session)
				{
					r3::server::instance()->sessionManager()->unget(boost::static_pointer_cast<Session>(one_Session), false);
				}
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
				//авторизовать
				if(evt.login.fvs() != r3::fields::fvs_set ||
					evt.password.fvs() != r3::fields::fvs_set)
				{
					fire(Event_badLogin());
					return;
				}
				if(evt.login.value() != "test" ||
					evt.password.value() != "test")
				{
					fire(Event_badLogin());
					return;
				}

				//восстановить или поднять сессию
				Session_ptr session = r3::server::instance()->sessionManager()->get(evt.sid.fvs() == r3::fields::fvs_set ? evt.sid.value() : 0);

				startup(session, session->sid());
			}
		}
	}
}
