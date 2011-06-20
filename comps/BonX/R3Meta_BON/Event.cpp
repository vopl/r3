#include "stdafx.h"
#include "R3MetaBonX.h"


//********************************************************************************
// 
//********************************************************************************
void R3Meta_BON::EventImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// 
//********************************************************************************
R3Meta_BON::EventImpl::Direction_Type R3Meta_BON::EventImpl::getDirection()
{
	std::string val = FCOImpl::getAttribute("Direction")->getStringValue();

	if ( val == "s2c") return s2c_Direction_Type;
	else if ( val == "c2s") return c2s_Direction_Type;
	else if ( val == "both") return both_Direction_Type;
	else throw("None of the possible items");
}


//********************************************************************************
// 
//********************************************************************************
void R3Meta_BON::EventImpl::setDirection( EventImpl::Direction_Type val)
{
	std::string str_val = "";

	if ( val == s2c_Direction_Type) str_val = "s2c";
	else if ( val == c2s_Direction_Type) str_val = "c2s";
	else if ( val == both_Direction_Type) str_val = "both";
	else throw("None of the possible items");

	FCOImpl::getAttribute("Direction")->setStringValue( str_val);
}


//********************************************************************************
// getter for role "Audio" among "Field"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::Audio> R3Meta_BON::EventImpl::getAudio()
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
// getter for role "Binary" among "Field"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::Binary> R3Meta_BON::EventImpl::getBinary()
{
	std::set<R3Meta_BON::Binary> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Binary");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::Binary elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Bool" among "Field"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::Bool> R3Meta_BON::EventImpl::getBool()
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
// getter for role "CategoryReference" among "R3Meta_BON::CategoryReference"s
//********************************************************************************
std::set<R3Meta_BON::CategoryReference> R3Meta_BON::EventImpl::getCategoryReference()
{
	std::set<R3Meta_BON::CategoryReference> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("CategoryReference");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::CategoryReference elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Date" among "Field"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::Date> R3Meta_BON::EventImpl::getDate()
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
// getter for role "DateTimeInterval" among "Field"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::DateTimeInterval> R3Meta_BON::EventImpl::getDateTimeInterval()
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
// getter for role "Enum" among "Field"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::Enum> R3Meta_BON::EventImpl::getEnum()
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
// aggregated getter for role "R3Meta_BON::" among "R3Meta_BON::Field"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::Field> R3Meta_BON::EventImpl::getField()
{
	std::set<R3Meta_BON::Field> res;
	const int len = 20;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("Audio");
	roles_vec[1] = ModelImpl::getChildFCOsAs("Binary");
	roles_vec[2] = ModelImpl::getChildFCOsAs("Bool");
	roles_vec[3] = ModelImpl::getChildFCOsAs("Date");
	roles_vec[4] = ModelImpl::getChildFCOsAs("DateTimeInterval");
	roles_vec[5] = ModelImpl::getChildFCOsAs("File");
	roles_vec[6] = ModelImpl::getChildFCOsAs("Image");
	roles_vec[7] = ModelImpl::getChildFCOsAs("Int16");
	roles_vec[8] = ModelImpl::getChildFCOsAs("Int32");
	roles_vec[9] = ModelImpl::getChildFCOsAs("Int64");
	roles_vec[10] = ModelImpl::getChildFCOsAs("Int8");
	roles_vec[11] = ModelImpl::getChildFCOsAs("Money");
	roles_vec[12] = ModelImpl::getChildFCOsAs("Real32");
	roles_vec[13] = ModelImpl::getChildFCOsAs("Real64");
	roles_vec[14] = ModelImpl::getChildFCOsAs("String");
	roles_vec[15] = ModelImpl::getChildFCOsAs("Time");
	roles_vec[16] = ModelImpl::getChildFCOsAs("Timestamp");
	roles_vec[17] = ModelImpl::getChildFCOsAs("Video");
	roles_vec[18] = ModelImpl::getChildFCOsAs("Enum");
	roles_vec[19] = ModelImpl::getChildFCOsAs("Set");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			R3Meta_BON::Field elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "File" among "Field"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::File> R3Meta_BON::EventImpl::getFile()
{
	std::set<R3Meta_BON::File> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("File");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		R3Meta_BON::File elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Image" among "Field"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::Image> R3Meta_BON::EventImpl::getImage()
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
// getter for role "Int16" among "Field"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::Int16> R3Meta_BON::EventImpl::getInt16()
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
// getter for role "Int32" among "Field"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::Int32> R3Meta_BON::EventImpl::getInt32()
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
// getter for role "Int64" among "Field"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::Int64> R3Meta_BON::EventImpl::getInt64()
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
// getter for role "Int8" among "Field"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::Int8> R3Meta_BON::EventImpl::getInt8()
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
// getter for role "Money" among "Field"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::Money> R3Meta_BON::EventImpl::getMoney()
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
// getter for role "Real32" among "Field"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::Real32> R3Meta_BON::EventImpl::getReal32()
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
// getter for role "Real64" among "Field"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::Real64> R3Meta_BON::EventImpl::getReal64()
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
// getter for role "Set" among "Field"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::Set> R3Meta_BON::EventImpl::getSet()
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
// getter for role "String" among "Field"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::String> R3Meta_BON::EventImpl::getString()
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
// getter for role "Time" among "Field"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::Time> R3Meta_BON::EventImpl::getTime()
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
// getter for role "Timestamp" among "Field"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::Timestamp> R3Meta_BON::EventImpl::getTimestamp()
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
// getter for role "Video" among "Field"s and its descendants
//********************************************************************************
std::set<R3Meta_BON::Video> R3Meta_BON::EventImpl::getVideo()
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


