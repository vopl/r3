#include "pch.h"
#include "utils/variant.hpp"

using namespace utils;
using namespace std;
using namespace boost;

//////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
	Variant v;

	Variant::MapStringVariant &m_ = v.as<Variant::MapStringVariant>(true);

	m_["Void_Null"].forceType<Variant::Void>();
	m_["String_Null"].forceType<Variant::String>();
	m_["Float_Null"].forceType<Variant::Float>();
	m_["Double_Null"].forceType<Variant::Double>();
	m_["Int8_Null"].forceType<Variant::Int8>();
	m_["Int16_Null"].forceType<Variant::Int16>();
	m_["Int32_Null"].forceType<Variant::Int32>();
	m_["Int64_Null"].forceType<Variant::Int64>();
	m_["UInt8_Null"].forceType<Variant::UInt8>();
	m_["UInt16_Null"].forceType<Variant::UInt16>();
	m_["UInt32_Null"].forceType<Variant::UInt32>();
	m_["UInt64_Null"].forceType<Variant::UInt64>();
	m_["VectorChar_Null"].forceType<Variant::VectorChar>();
	m_["Date_Null"].forceType<Variant::Date>();
	m_["Datetime_Null"].forceType<Variant::Datetime>();
	m_["VectorVariant_Null"].forceType<Variant::VectorVariant>();
	m_["MapStringVariant_Null"].forceType<Variant::MapStringVariant>();
	m_["Bool_Null"].forceType<Variant::Bool>();
	m_["Tm_Null"].forceType<Variant::Tm>();
	m_["Bitset8_Null"].forceType<Variant::Bitset8>();
	m_["Bitset16_Null"].forceType<Variant::Bitset16>();
	m_["Bitset32_Null"].forceType<Variant::Bitset32>();
	m_["Bitset64_Null"].forceType<Variant::Bitset64>();
	m_["Bitset128_Null"].forceType<Variant::Bitset128>();
	m_["Bitset256_Null"].forceType<Variant::Bitset256>();
	m_["Bitset512_Null"].forceType<Variant::Bitset512>();
	m_["DateDuration_Null"].forceType<Variant::DateDuration>();
	m_["TimeDuration_Null"].forceType<Variant::TimeDuration>();
	m_["DateTimeDuration_Null"].forceType<Variant::DateTimeDuration>();
	m_["MapVariantVariant_Null"].forceType<Variant::MapVariantVariant>();
	m_["MultimapStringVariant_Null"].forceType<Variant::MultimapStringVariant>();
	m_["MultimapVariantVariant_Null"].forceType<Variant::MultimapVariantVariant>();
	m_["SetVariant_Null"].forceType<Variant::SetVariant>();
	m_["MultisetVariant_Null"].forceType<Variant::MultisetVariant>();
	m_["DequeVariant_Null"].forceType<Variant::DequeVariant>();
	m_["ListVariant_Null"].forceType<Variant::ListVariant>();
	m_["Char_Null"].forceType<Variant::Char>();
	m_["Uuid_Null"].forceType<Variant::Uuid>();
	m_["VariantPtr_Null"].forceType<Variant::VariantPtr>();

	m_["Void"];
	m_["String"] = std::string("abracadabra\0220");
	m_["Float"] = 1.234f;
	m_["Double"] = 3.456;
	m_["Int8"] = int8_t(-21);
	m_["Int16"] = int16_t(-22);
	m_["Int32"] = int32_t(-23);
	m_["Int64"] = int64_t(-24);
	m_["UInt8"] = uint8_t(21);
	m_["UInt16"] = uint16_t(22);
	m_["UInt32"] = uint32_t(23);
	m_["UInt64"] = uint64_t(24);
	m_["VectorChar"].as<Variant::VectorChar>(true).push_back('a');
	m_["VectorChar"].as<Variant::VectorChar>(true).push_back('b');
	m_["VectorChar"].as<Variant::VectorChar>(true).push_back('c');
	m_["Date"] = gregorian::date(2011, gregorian::Feb, 4);
	m_["Datetime"] = posix_time::ptime(
		gregorian::date(2011, gregorian::Feb, 4),
		posix_time::time_duration(32, 45, 56));
	m_["VectorVariant"].as<Variant::VectorVariant>(true).push_back('c');
	m_["VectorVariant"].as<Variant::VectorVariant>(true).push_back(20);
	m_["VectorVariant"].as<Variant::VectorVariant>(true).push_back("asdf");

	m_["MapStringVariant"].as<Variant::MapStringVariant>(true)["one"] =  "one";
	m_["MapStringVariant"].as<Variant::MapStringVariant>(true)["two"] =  2;
	m_["Bool"] = true;
	m_["Tm"].as<Variant::Tm>(true).tm_year = 2200;
	m_["Bitset8"].as<Variant::Bitset8>(true).set(4);
	m_["Bitset16"].as<Variant::Bitset16>(true).set(4);
	m_["Bitset32"].as<Variant::Bitset32>(true).set(4);
	m_["Bitset64"].as<Variant::Bitset64>(true).set(4);
	m_["Bitset128"].as<Variant::Bitset128>(true).set(4);
	m_["Bitset256"].as<Variant::Bitset256>(true).set(4);
	m_["Bitset512"].as<Variant::Bitset512>(true).set(4);
	m_["DateDuration"] = gregorian::days(67);
	m_["TimeDuration"] = posix_time::microseconds(78236592);
	m_["DateTimeDuration"].as<Variant::DateTimeDuration>(true)._dd = gregorian::days(67);
	m_["DateTimeDuration"].as<Variant::DateTimeDuration>(true)._td = posix_time::microseconds(78236592);
	
	m_["MapVariantVariant"].as<Variant::MapVariantVariant>(true)['a'] = 'b';
	m_["MapVariantVariant"].as<Variant::MapVariantVariant>(true)["c"] = "d";
	
	m_["MultimapStringVariant"].as<Variant::MultimapStringVariant>(true).insert(std::make_pair("a", 'a'));
	m_["MultimapStringVariant"].as<Variant::MultimapStringVariant>(true).insert(std::make_pair("a", 'b'));

	m_["MultimapVariantVariant"].as<Variant::MultimapVariantVariant>(true).insert(std::make_pair("a", 'a'));
	m_["MultimapVariantVariant"].as<Variant::MultimapVariantVariant>(true).insert(std::make_pair("a", 'b'));

	m_["SetVariant"].as<Variant::SetVariant>(true).insert(1);
	m_["SetVariant"].as<Variant::SetVariant>(true).insert("2");

	m_["MultisetVariant"].as<Variant::MultisetVariant>(true).insert("2");
	m_["MultisetVariant"].as<Variant::MultisetVariant>(true).insert("2");
	m_["MultisetVariant"].as<Variant::MultisetVariant>(true).insert(2);

	m_["DequeVariant"].as<Variant::DequeVariant>(true).push_back("asdf1");
	m_["DequeVariant"].as<Variant::DequeVariant>(true).push_back("asdf2");
	m_["DequeVariant"].as<Variant::DequeVariant>(true).push_back("asdf3");

	m_["ListVariant"].as<Variant::ListVariant>(true).push_back("asdf1");
	m_["ListVariant"].as<Variant::ListVariant>(true).push_back("asdf2");
	m_["ListVariant"].as<Variant::ListVariant>(true).push_back("asdf3");

	m_["Char"] = 's';
	m_["Uuid"] = uuids::uuid();
	
	m_["VariantPtr"] = VariantPtr(new Variant(22));
	m_["MultisetVariant"].as<Variant::MultisetVariant>(true).insert(m_["VariantPtr"]);

	size_t size;
	boost::shared_array<char> data = v.serialize(size);
	
	Variant v2;
	bool success = v2.deserialize(data, size);

	std::cout<<"success: "<<success<<", "<<(v==v2)<<std::endl;

	return EXIT_SUCCESS;
}

