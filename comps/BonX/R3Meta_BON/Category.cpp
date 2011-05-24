#include "stdafx.h"
#include "R3MetaBonX.h"


//********************************************************************************
// 
//********************************************************************************
void R3Meta_BON::CategoryImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// 
//********************************************************************************
bool R3Meta_BON::CategoryImpl::isAbstract() 
{
	return FCOImpl::getAttribute("Abstract")->getBooleanValue();
}


//********************************************************************************
// 
//********************************************************************************
void R3Meta_BON::CategoryImpl::setAbstract( bool val)
{
	FCOImpl::getAttribute("Abstract")->setBooleanValue( val);
}


//********************************************************************************
// getter for role "Audio" among "CategoryMember"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::Audio> R3Meta_BON::CategoryImpl::getAudio()
{
	std::set<R3Meta_BON::Audio> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Audio");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::Audio elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Bool" among "CategoryMember"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::Bool> R3Meta_BON::CategoryImpl::getBool()
{
	std::set<R3Meta_BON::Bool> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Bool");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::Bool elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "R3Meta_BON::" among "R3Meta_BON::CategoryMember"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::CategoryMember> R3Meta_BON::CategoryImpl::getCategoryMember()
{
	std::set<R3Meta_BON::CategoryMember> res;
	const int len = 20;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("Audio");
	roles_vec[1] = ModelImpl::getChildFCOsAs("Bool");
	roles_vec[2] = ModelImpl::getChildFCOsAs("Date");
	roles_vec[3] = ModelImpl::getChildFCOsAs("DateTimeInterval");
	roles_vec[4] = ModelImpl::getChildFCOsAs("Image");
	roles_vec[5] = ModelImpl::getChildFCOsAs("Index");
	roles_vec[6] = ModelImpl::getChildFCOsAs("Int16");
	roles_vec[7] = ModelImpl::getChildFCOsAs("Int32");
	roles_vec[8] = ModelImpl::getChildFCOsAs("Int64");
	roles_vec[9] = ModelImpl::getChildFCOsAs("Int8");
	roles_vec[10] = ModelImpl::getChildFCOsAs("Money");
	roles_vec[11] = ModelImpl::getChildFCOsAs("Real32");
	roles_vec[12] = ModelImpl::getChildFCOsAs("Real64");
	roles_vec[13] = ModelImpl::getChildFCOsAs("String");
	roles_vec[14] = ModelImpl::getChildFCOsAs("Time");
	roles_vec[15] = ModelImpl::getChildFCOsAs("Timestamp");
	roles_vec[16] = ModelImpl::getChildFCOsAs("Video");
	roles_vec[17] = ModelImpl::getChildFCOsAs("Enum");
	roles_vec[18] = ModelImpl::getChildFCOsAs("Set");
	roles_vec[19] = ModelImpl::getChildFCOsAs("IndexOnCategoryField");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			R3Meta_BON::CategoryMember elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "Date" among "CategoryMember"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::Date> R3Meta_BON::CategoryImpl::getDate()
{
	std::set<R3Meta_BON::Date> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Date");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::Date elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "DateTimeInterval" among "CategoryMember"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::DateTimeInterval> R3Meta_BON::CategoryImpl::getDateTimeInterval()
{
	std::set<R3Meta_BON::DateTimeInterval> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("DateTimeInterval");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::DateTimeInterval elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Enum" among "CategoryMember"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::Enum> R3Meta_BON::CategoryImpl::getEnum()
{
	std::set<R3Meta_BON::Enum> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Enum");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::Enum elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Image" among "CategoryMember"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::Image> R3Meta_BON::CategoryImpl::getImage()
{
	std::set<R3Meta_BON::Image> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Image");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::Image elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Index" among "CategoryMember"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::Index> R3Meta_BON::CategoryImpl::getIndex()
{
	std::set<R3Meta_BON::Index> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Index");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::Index elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "IndexOnCategoryField" among "CategoryMember"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::IndexOnCategoryField> R3Meta_BON::CategoryImpl::getIndexOnCategoryField()
{
	std::set<R3Meta_BON::IndexOnCategoryField> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("IndexOnCategoryField");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::IndexOnCategoryField elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Int16" among "CategoryMember"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::Int16> R3Meta_BON::CategoryImpl::getInt16()
{
	std::set<R3Meta_BON::Int16> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Int16");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::Int16 elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Int32" among "CategoryMember"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::Int32> R3Meta_BON::CategoryImpl::getInt32()
{
	std::set<R3Meta_BON::Int32> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Int32");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::Int32 elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Int64" among "CategoryMember"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::Int64> R3Meta_BON::CategoryImpl::getInt64()
{
	std::set<R3Meta_BON::Int64> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Int64");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::Int64 elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Int8" among "CategoryMember"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::Int8> R3Meta_BON::CategoryImpl::getInt8()
{
	std::set<R3Meta_BON::Int8> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Int8");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::Int8 elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Money" among "CategoryMember"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::Money> R3Meta_BON::CategoryImpl::getMoney()
{
	std::set<R3Meta_BON::Money> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Money");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::Money elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Real32" among "CategoryMember"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::Real32> R3Meta_BON::CategoryImpl::getReal32()
{
	std::set<R3Meta_BON::Real32> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Real32");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::Real32 elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Real64" among "CategoryMember"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::Real64> R3Meta_BON::CategoryImpl::getReal64()
{
	std::set<R3Meta_BON::Real64> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Real64");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::Real64 elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Set" among "CategoryMember"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::Set> R3Meta_BON::CategoryImpl::getSet()
{
	std::set<R3Meta_BON::Set> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Set");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::Set elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "String" among "CategoryMember"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::String> R3Meta_BON::CategoryImpl::getString()
{
	std::set<R3Meta_BON::String> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("String");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::String elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Time" among "CategoryMember"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::Time> R3Meta_BON::CategoryImpl::getTime()
{
	std::set<R3Meta_BON::Time> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Time");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::Time elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Timestamp" among "CategoryMember"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::Timestamp> R3Meta_BON::CategoryImpl::getTimestamp()
{
	std::set<R3Meta_BON::Timestamp> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Timestamp");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::Timestamp elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Video" among "CategoryMember"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::Video> R3Meta_BON::CategoryImpl::getVideo()
{
	std::set<R3Meta_BON::Video> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Video");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::Video elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


