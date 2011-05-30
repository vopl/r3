#ifndef R3META_BONCATEGORY_H
#define R3META_BONCATEGORY_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   CategoryImpl
//*******************************************************************
class CategoryImpl :
	  virtual public BON::ModelImpl
	, public CategoryOrReferenceImpl
{
public:
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// attribute getters and setters
	virtual std::string getSchema() ;
	virtual bool        isAbstract() ;
	virtual void        setAbstract( bool val);
	virtual void        setSchema( const std::string& val);
	//
	// kind and role getters
	virtual std::set<R3Meta_BON::Audio>     getAudio();
	virtual std::set<R3Meta_BON::Bool>      getBool();
	virtual std::set<R3Meta_BON::CategoryMember>      getCategoryMember();
	virtual std::set<R3Meta_BON::Date>      getDate();
	virtual std::set<R3Meta_BON::DateTimeInterval>    getDateTimeInterval();
	virtual std::set<R3Meta_BON::Enum>      getEnum();
	virtual std::set<R3Meta_BON::File>      getFile();
	virtual std::set<R3Meta_BON::Image>     getImage();
	virtual std::set<R3Meta_BON::Index>     getIndex();
	virtual std::set<R3Meta_BON::IndexOnCategoryField> getIndexOnCategoryField();
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
