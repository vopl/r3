#include "stdafx.h"
#include "R3MetaBonX.h"


namespace BON
{

IMPLEMENT_ABSTRACT_BONEXTENSION( R3Meta_BON::CategoryMember );
IMPLEMENT_ABSTRACT_BONEXTENSION( R3Meta_BON::Field );
IMPLEMENT_BONEXTENSION( R3Meta_BON::Index, "Index" );
IMPLEMENT_BONEXTENSION( R3Meta_BON::IndexOnCategoryField, "IndexOnCategoryField" );
IMPLEMENT_ABSTRACT_BONEXTENSION( R3Meta_BON::Scanty );
IMPLEMENT_ABSTRACT_BONEXTENSION( R3Meta_BON::File );
IMPLEMENT_ABSTRACT_BONEXTENSION( R3Meta_BON::Simple );
IMPLEMENT_BONEXTENSION( R3Meta_BON::Enum, "Enum" );
IMPLEMENT_BONEXTENSION( R3Meta_BON::Set, "Set" );
IMPLEMENT_ABSTRACT_BONEXTENSION( R3Meta_BON::DateTime );
IMPLEMENT_ABSTRACT_BONEXTENSION( R3Meta_BON::Int );
IMPLEMENT_ABSTRACT_BONEXTENSION( R3Meta_BON::Real );
IMPLEMENT_BONEXTENSION( R3Meta_BON::Audio, "Audio" );
IMPLEMENT_BONEXTENSION( R3Meta_BON::Bool, "Bool" );
IMPLEMENT_BONEXTENSION( R3Meta_BON::Image, "Image" );
IMPLEMENT_BONEXTENSION( R3Meta_BON::Money, "Money" );
IMPLEMENT_BONEXTENSION( R3Meta_BON::String, "String" );
IMPLEMENT_BONEXTENSION( R3Meta_BON::Video, "Video" );
IMPLEMENT_ABSTRACT_BONEXTENSION( R3Meta_BON::DateTimeValue );
IMPLEMENT_BONEXTENSION( R3Meta_BON::DateTimeInterval, "DateTimeInterval" );
IMPLEMENT_BONEXTENSION( R3Meta_BON::Int16, "Int16" );
IMPLEMENT_BONEXTENSION( R3Meta_BON::Int32, "Int32" );
IMPLEMENT_BONEXTENSION( R3Meta_BON::Int64, "Int64" );
IMPLEMENT_BONEXTENSION( R3Meta_BON::Int8, "Int8" );
IMPLEMENT_BONEXTENSION( R3Meta_BON::Real32, "Real32" );
IMPLEMENT_BONEXTENSION( R3Meta_BON::Real64, "Real64" );
IMPLEMENT_BONEXTENSION( R3Meta_BON::Date, "Date" );
IMPLEMENT_BONEXTENSION( R3Meta_BON::Time, "Time" );
IMPLEMENT_BONEXTENSION( R3Meta_BON::Timestamp, "Timestamp" );
IMPLEMENT_ABSTRACT_BONEXTENSION( R3Meta_BON::CategoryOrReference );
IMPLEMENT_BONEXTENSION( R3Meta_BON::Category, "Category" );
IMPLEMENT_BONEXTENSION( R3Meta_BON::CategoryReference, "CategoryReference" );
IMPLEMENT_BONEXTENSION( R3Meta_BON::Exchange, "Exchange" );
IMPLEMENT_BONEXTENSION( R3Meta_BON::Schema, "Schema" );
IMPLEMENT_BONEXTENSION( R3Meta_BON::Channel, "Channel" );
IMPLEMENT_BONEXTENSION( R3Meta_BON::ScantyValue, "ScantyValue" );
IMPLEMENT_BONEXTENSION( R3Meta_BON::CategoryInheritance, "CategoryInheritance" );
IMPLEMENT_BONEXTENSION( R3Meta_BON::CategoryInput, "CategoryInput" );
IMPLEMENT_BONEXTENSION( R3Meta_BON::CategoryOutput, "CategoryOutput" );
IMPLEMENT_BONEXTENSION( R3Meta_BON::CategoryRelation, "CategoryRelation" );


} // namespace BON

