#ifndef _R3_SERIALIZATION_HPP_
#define _R3_SERIALIZATION_HPP_

#include "r3/contextBase.hpp"
#include "r3/protocol/serialization.hpp"

//////////////////////////////////////////////////////////////////////////
template<class Archive>
void r3::ContextPathItem::serialize(Archive &ar, const unsigned int file_version)
{
	ar &BOOST_SERIALIZATION_NVP(tid);
	ar &BOOST_SERIALIZATION_NVP(id);;
}

//////////////////////////////////////////////////////////////////////////
template<class Archive>
void r3::EventBase::serialize(Archive &ar, const unsigned int file_version)
{
	ar &BOOST_SERIALIZATION_NVP(tid);
}

//////////////////////////////////////////////////////////////////////////
template<class Archive>
void r3::Event_ping::serialize(Archive &ar, const unsigned int file_version)
{
	ar &BOOST_SERIALIZATION_BASE_OBJECT_NVP(EventBase);
	ar &BOOST_SERIALIZATION_NVP(counter);
}

//////////////////////////////////////////////////////////////////////////
template<class Archive>
void r3::Event_pong::serialize(Archive &ar, const unsigned int file_version)
{
	ar &BOOST_SERIALIZATION_BASE_OBJECT_NVP(EventBase);
	ar &BOOST_SERIALIZATION_NVP(counter);
}

//////////////////////////////////////////////////////////////////////////
template<class Archive>
void r3::Event_startup::serialize(Archive &ar, const unsigned int file_version)
{
	ar &BOOST_SERIALIZATION_BASE_OBJECT_NVP(EventBase);
	ar &BOOST_SERIALIZATION_NVP(cid);
	ar &BOOST_SERIALIZATION_NVP(ctid);
	ar &BOOST_SERIALIZATION_NVP(rightValues);
}

//////////////////////////////////////////////////////////////////////////
template<class Archive>
void r3::Event_shutdown::serialize(Archive &ar, const unsigned int file_version)
{
	ar &BOOST_SERIALIZATION_BASE_OBJECT_NVP(EventBase);
}

#endif
