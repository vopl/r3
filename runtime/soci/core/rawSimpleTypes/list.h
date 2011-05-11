
#ifndef BEGIN_RST_LIST
#	define BEGIN_RST_LIST
#endif
#ifndef END_RST_LIST
#	define END_RST_LIST
#endif
#ifndef RST_ENTRY
#	define RST_ENTRY(i,t,n)
#endif

BEGIN_RST_LIST

RST_ENTRY(1, std::string, String)
RST_ENTRY(11, std::bitset<8>, Bits8)
RST_ENTRY(12, std::bitset<16>, Bits16)
RST_ENTRY(13, std::bitset<32>, Bits32)
RST_ENTRY(14, std::bitset<64>, Bits64)
RST_ENTRY(15, std::bitset<128>, Bits128)
RST_ENTRY(16, std::bitset<256>, Bits256)
RST_ENTRY(21, std::vector<boost::uint8_t>, Bytea)
RST_ENTRY(31, bool, Bool)
RST_ENTRY(41, float, Real32)
RST_ENTRY(42, double, Real64)
RST_ENTRY(51, boost::int8_t, Int8)
RST_ENTRY(52, boost::int16_t, Int16)
RST_ENTRY(53, boost::int32_t, Int32)
RST_ENTRY(54, boost::int64_t, Int64)
RST_ENTRY(61, boost::uint8_t, Uint8)
RST_ENTRY(62, boost::uint16_t, Uint16)
RST_ENTRY(63, boost::uint32_t, Uint32)
RST_ENTRY(64, boost::uint64_t, Uint64)
RST_ENTRY(71, boost::posix_time::ptime::date_type, Date)
RST_ENTRY(72, boost::posix_time::ptime::time_duration_type, Time)
RST_ENTRY(73, boost::posix_time::ptime, Timestamp)
RST_ENTRY(83, struct
{
	boost::posix_time::ptime::date_duration_type iDate; 
	boost::posix_time::ptime::time_duration_type iTime;
}, Interval)

RST_ENTRY(91, boost::uint64_t, Money)

END_RST_LIST


#undef BEGIN_RST_LIST
#undef END_RST_LIST
#undef RST_ENTRY

