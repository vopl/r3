#ifndef R3METABONX_H
#define R3METABONX_H

#include "BON.h"
#include "BONImpl.h"
#include "Extensions.h"

///BUP
// add your include files/class definitions here
///EUP

namespace R3Meta_BON {      DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, CategoryMemberImpl, CategoryMember ); }
namespace R3Meta_BON {      DECLARE_ABSTRACT_BONEXTENSION( CategoryMember, FieldImpl, Field ); }
namespace R3Meta_BON {      DECLARE_BONEXTENSION2( BON::Atom, CategoryMember, IndexImpl, Index ); }
namespace R3Meta_BON {      DECLARE_BONEXTENSION2( BON::Connection, CategoryMember, IndexOnCategoryFieldImpl, IndexOnCategoryField ); }
namespace R3Meta_BON {      DECLARE_ABSTRACT_BONEXTENSION2( BON::Model, Field, ScantyImpl, Scanty ); }
namespace R3Meta_BON {      DECLARE_ABSTRACT_BONEXTENSION( Field, SimpleImpl, Simple ); }
namespace R3Meta_BON {      DECLARE_BONEXTENSION( Scanty, EnumImpl, Enum ); }
namespace R3Meta_BON {      DECLARE_BONEXTENSION( Scanty, SetImpl, Set ); }
namespace R3Meta_BON {      DECLARE_ABSTRACT_BONEXTENSION( Simple, DateTimeImpl, DateTime ); }
namespace R3Meta_BON {      DECLARE_ABSTRACT_BONEXTENSION( Simple, IntImpl, Int ); }
namespace R3Meta_BON {      DECLARE_ABSTRACT_BONEXTENSION( Simple, RealImpl, Real ); }
namespace R3Meta_BON {      DECLARE_BONEXTENSION2( BON::Atom, Simple, BinaryImpl, Binary ); }
namespace R3Meta_BON {      DECLARE_ABSTRACT_BONEXTENSION2( BON::Atom, Simple, BitsetImpl, Bitset ); }
namespace R3Meta_BON {      DECLARE_BONEXTENSION2( BON::Atom, Simple, BoolImpl, Bool ); }
namespace R3Meta_BON {      DECLARE_BONEXTENSION2( BON::Atom, Simple, FileImpl, File ); }
namespace R3Meta_BON {      DECLARE_BONEXTENSION2( BON::Atom, Simple, MoneyImpl, Money ); }
namespace R3Meta_BON {      DECLARE_BONEXTENSION2( BON::Atom, Simple, StringImpl, String ); }
namespace R3Meta_BON {      DECLARE_BONEXTENSION2( BON::Atom, Simple, UuidImpl, Uuid ); }
namespace R3Meta_BON {      DECLARE_BONEXTENSION2( BON::Atom, Simple, VariantImpl, Variant ); }
namespace R3Meta_BON {      DECLARE_ABSTRACT_BONEXTENSION( DateTime, DateTimeValueImpl, DateTimeValue ); }
namespace R3Meta_BON {      DECLARE_BONEXTENSION( Bitset, Bitset128Impl, Bitset128 ); }
namespace R3Meta_BON {      DECLARE_BONEXTENSION( Bitset, Bitset16Impl, Bitset16 ); }
namespace R3Meta_BON {      DECLARE_BONEXTENSION( Bitset, Bitset256Impl, Bitset256 ); }
namespace R3Meta_BON {      DECLARE_BONEXTENSION( Bitset, Bitset32Impl, Bitset32 ); }
namespace R3Meta_BON {      DECLARE_BONEXTENSION( Bitset, Bitset512Impl, Bitset512 ); }
namespace R3Meta_BON {      DECLARE_BONEXTENSION( Bitset, Bitset64Impl, Bitset64 ); }
namespace R3Meta_BON {      DECLARE_BONEXTENSION( Bitset, Bitset8Impl, Bitset8 ); }
namespace R3Meta_BON {      DECLARE_BONEXTENSION2( BON::Atom, DateTime, DateTimeIntervalImpl, DateTimeInterval ); }
namespace R3Meta_BON {      DECLARE_BONEXTENSION2( BON::Atom, Int, Int16Impl, Int16 ); }
namespace R3Meta_BON {      DECLARE_BONEXTENSION2( BON::Atom, Int, Int32Impl, Int32 ); }
namespace R3Meta_BON {      DECLARE_BONEXTENSION2( BON::Atom, Int, Int64Impl, Int64 ); }
namespace R3Meta_BON {      DECLARE_BONEXTENSION2( BON::Atom, Int, Int8Impl, Int8 ); }
namespace R3Meta_BON {      DECLARE_BONEXTENSION2( BON::Atom, Real, Real32Impl, Real32 ); }
namespace R3Meta_BON {      DECLARE_BONEXTENSION2( BON::Atom, Real, Real64Impl, Real64 ); }
namespace R3Meta_BON {      DECLARE_BONEXTENSION2( BON::Atom, DateTimeValue, DateImpl, Date ); }
namespace R3Meta_BON {      DECLARE_BONEXTENSION2( BON::Atom, DateTimeValue, TimeImpl, Time ); }
namespace R3Meta_BON {      DECLARE_BONEXTENSION2( BON::Atom, DateTimeValue, TimestampImpl, Timestamp ); }
namespace R3Meta_BON {      DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, CategoryOrReferenceImpl, CategoryOrReference ); }
namespace R3Meta_BON {      DECLARE_BONEXTENSION2( BON::Model, CategoryOrReference, CategoryImpl, Category ); }
namespace R3Meta_BON {      DECLARE_BONEXTENSION2( BON::Reference, CategoryOrReference, CategoryReferenceImpl, CategoryReference ); }
namespace R3Meta_BON {      DECLARE_BONEXTENSION( BON::Model, DataImpl, Data ); }
namespace R3Meta_BON {      DECLARE_BONEXTENSION( BON::Atom, ScantyValueImpl, ScantyValue ); }
namespace R3Meta_BON {      DECLARE_BONEXTENSION( BON::Connection, CategoryInheritanceImpl, CategoryInheritance ); }
namespace R3Meta_BON {      DECLARE_BONEXTENSION( BON::Connection, CategoryRelationImpl, CategoryRelation ); }


#include "R3Meta_BON/CategoryMember.h"
#include "R3Meta_BON/Field.h"
#include "R3Meta_BON/Index.h"
#include "R3Meta_BON/IndexOnCategoryField.h"
#include "R3Meta_BON/Scanty.h"
#include "R3Meta_BON/Simple.h"
#include "R3Meta_BON/Enum.h"
#include "R3Meta_BON/Set.h"
#include "R3Meta_BON/DateTime.h"
#include "R3Meta_BON/Int.h"
#include "R3Meta_BON/Real.h"
#include "R3Meta_BON/Binary.h"
#include "R3Meta_BON/Bitset.h"
#include "R3Meta_BON/Bool.h"
#include "R3Meta_BON/File.h"
#include "R3Meta_BON/Money.h"
#include "R3Meta_BON/String.h"
#include "R3Meta_BON/Uuid.h"
#include "R3Meta_BON/Variant.h"
#include "R3Meta_BON/DateTimeValue.h"
#include "R3Meta_BON/Bitset128.h"
#include "R3Meta_BON/Bitset16.h"
#include "R3Meta_BON/Bitset256.h"
#include "R3Meta_BON/Bitset32.h"
#include "R3Meta_BON/Bitset512.h"
#include "R3Meta_BON/Bitset64.h"
#include "R3Meta_BON/Bitset8.h"
#include "R3Meta_BON/DateTimeInterval.h"
#include "R3Meta_BON/Int16.h"
#include "R3Meta_BON/Int32.h"
#include "R3Meta_BON/Int64.h"
#include "R3Meta_BON/Int8.h"
#include "R3Meta_BON/Real32.h"
#include "R3Meta_BON/Real64.h"
#include "R3Meta_BON/Date.h"
#include "R3Meta_BON/Time.h"
#include "R3Meta_BON/Timestamp.h"
#include "R3Meta_BON/CategoryOrReference.h"
#include "R3Meta_BON/Category.h"
#include "R3Meta_BON/CategoryReference.h"
#include "R3Meta_BON/Data.h"
#include "R3Meta_BON/ScantyValue.h"
#include "R3Meta_BON/CategoryInheritance.h"
#include "R3Meta_BON/CategoryRelation.h"

///BUP
// add your additional class definitions here
///EUP

#endif // R3METABONX_H
