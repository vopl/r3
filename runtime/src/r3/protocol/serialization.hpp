// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _R3_PROTOCOL_SERIALIZATION_HPP_
#define _R3_PROTOCOL_SERIALIZATION_HPP_

#include "r3/protocol/server/Connection.hpp"

//////////////////////////////////////////////////////////////////////////
template<class Archive>
void r3::protocol::server::Connection::Event_session::serialize(Archive &ar, const unsigned int file_version)
{
	ar &BOOST_SERIALIZATION_BASE_OBJECT_NVP(EventBase);
	ar &BOOST_SERIALIZATION_NVP(sid);
}

//////////////////////////////////////////////////////////////////////////
template<class Archive>
void r3::protocol::server::Connection::Event_login::serialize(Archive &ar, const unsigned int file_version)
{
	ar &BOOST_SERIALIZATION_BASE_OBJECT_NVP(EventBase);
	ar &BOOST_SERIALIZATION_NVP(sid);
	ar &BOOST_SERIALIZATION_NVP(login);
	ar &BOOST_SERIALIZATION_NVP(password);
}

//////////////////////////////////////////////////////////////////////////
template<class Archive>
void r3::protocol::server::Connection::Event_badLogin::serialize(Archive &ar, const unsigned int file_version)
{
	ar &BOOST_SERIALIZATION_BASE_OBJECT_NVP(EventBase);
}

//////////////////////////////////////////////////////////////////////////
template<class Archive>
void r3::protocol::server::Connection::Session::Event_unblock::serialize(Archive &ar, const unsigned int file_version)
{
	ar &BOOST_SERIALIZATION_BASE_OBJECT_NVP(EventBase);
}

//////////////////////////////////////////////////////////////////////////
template<class Archive>
void r3::protocol::server::Connection::Session::Event_block::serialize(Archive &ar, const unsigned int file_version)
{
	ar &BOOST_SERIALIZATION_BASE_OBJECT_NVP(EventBase);
}

//////////////////////////////////////////////////////////////////////////
template<class Archive>
void r3::protocol::server::Connection::Session::Event_logout::serialize(Archive &ar, const unsigned int file_version)
{
	ar &BOOST_SERIALIZATION_BASE_OBJECT_NVP(EventBase);
}


#endif
