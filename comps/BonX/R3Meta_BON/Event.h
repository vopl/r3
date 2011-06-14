#ifndef R3META_BONEVENT_H
#define R3META_BONEVENT_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   EventImpl
//*******************************************************************
class EventImpl :
	  virtual public BON::ModelImpl
	, public EventOrReferenceImpl
{
public:
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<R3Meta_BON::Audio>     getAudio();
	virtual std::set<R3Meta_BON::Binary>    getBinary();
	virtual std::set<R3Meta_BON::Bool>      getBool();
	virtual std::set<R3Meta_BON::CategoryReference>   getCategoryReference();
	virtual std::set<R3Meta_BON::Date>      getDate();
	virtual std::set<R3Meta_BON::DateTimeInterval>    getDateTimeInterval();
	virtual std::set<R3Meta_BON::Enum>      getEnum();
	virtual std::set<R3Meta_BON::Event>     getEvent();
	virtual std::set<R3Meta_BON::EventOrReference>    getEventOrReference();
	virtual std::set<R3Meta_BON::EventReference>      getEventReference();
	virtual std::set<R3Meta_BON::Field>     getField();
	virtual std::set<R3Meta_BON::File>      getFile();
	virtual std::set<R3Meta_BON::Image>     getImage();
	virtual std::set<R3Meta_BON::Int16>     getInt16();
	virtual std::set<R3Meta_BON::Int32>     getInt32();
	virtual std::set<R3Meta_BON::Int64>     getInt64();
	virtual std::set<R3Meta_BON::Int8>      getInt8();
	virtual std::set<R3Meta_BON::Money>     getMoney();
	virtual std::set<R3Meta_BON::Real32>    getReal32();
	virtual std::set<R3Meta_BON::Real64>    getReal64();
	virtual std::set<R3Meta_BON::Set>       getSet();
	virtual std::set<R3Meta_BON::String>    getString();
	virtual std::set<R3Meta_BON::Time>      getTime();
	virtual std::set<R3Meta_BON::Timestamp> getTimestamp();
	virtual std::set<R3Meta_BON::Video>     getVideo();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


#endif
