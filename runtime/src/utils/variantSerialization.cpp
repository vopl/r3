#include "pch.h"
#include "utils/variant.hpp"
#include <boost/crc.hpp>

namespace utils
{
	using namespace boost;
	namespace
	{
		class Serializer
		{
			typedef std::map<const VariantPtr, uint32_t> TMPtrKey;
			TMPtrKey _mPtrKey;

#pragma pack (push, 1)
			struct Header
			{
				uint16_t	_signature;//����� ���������� ���������
				uint16_t	_crc;//��������� _size � ��� ������
				uint32_t	_size;//������ ������
			};
#pragma pack (pop)

			char *_bufIter;
			char *_bufEnd;

		public:
			//////////////////////////////////////////////////////////////////////////
			Serializer()
				: _bufIter(NULL)
				, _bufEnd(NULL)
			{

			}

			//////////////////////////////////////////////////////////////////////////
			~Serializer()
			{

			}

			//////////////////////////////////////////////////////////////////////////
			shared_array<char> serialize(const Variant &v, uint32_t &size)
			{
				//������ ������, ��������� �����
				size = calcSize(v);
				_mPtrKey.clear();

				shared_array<char> data(new char[sizeof(Header) + size]);

				Header *ph = (Header *)data.get();
				ph->_signature = 0x3F47;
				ph->_size = size;

				_bufIter = data.get() + sizeof(Header);
				_bufEnd = _bufIter + size;
				write(v);
				_mPtrKey.clear();
				assert(_bufIter == _bufEnd);
				_bufIter = NULL;
				_bufEnd = NULL;

				crc_16_type		crcCalculator;
				crcCalculator.process_bytes(data.get()+4, size+4);
				ph->_crc = crcCalculator.checksum();
				return data;
			}

			//////////////////////////////////////////////////////////////////////////
			bool deserialize(Variant &v, shared_array<char> data, uint32_t size)
			{
				assert(0);
				return false;
			}

		private:
			//////////////////////////////////////////////////////////////////////////
			uint32_t calcSize(const Variant &v)
			{
				//_et
				uint32_t size = 2;

				//������ �������
				static const uint32_t S = sizeof(uint32_t);

				if(v.isNull())
				{
					//������
				}
				else
				{
					switch(v.type())
					{
					case Variant::etUnknown:
						break;
					case Variant::etVoid:
						break;
					case Variant::etString:
						size += S;
						size += v.as<Variant::String>().size();
						break;
					case Variant::etFloat:
						size += 4;
						break;
					case Variant::etDouble:
						size += 8;
						break;
					case Variant::etInt8:
						size += 1;
						break;
					case Variant::etInt16:
						size += 2;
						break;
					case Variant::etInt32:
						size += 4;
						break;
					case Variant::etInt64:
						size += 8;
						break;
					case Variant::etUInt8:
						size += 1;
						break;
					case Variant::etUInt16:
						size += 2;
						break;
					case Variant::etUInt32:
						size += 4;
						break;
					case Variant::etUInt64:
						size += 8;
						break;
					case Variant::etVectorChar:
						size += S;
						size += v.as<Variant::VectorChar>().size();
						break;
					case Variant::etDate:
						size += 4;
						break;
					case Variant::etDatetime:
						size += 8;
						break;
					case Variant::etVectorVariant:
						size += S;
						BOOST_FOREACH(const Variant &el, v.as<Variant::VectorVariant>())
						{
							size += calcSize(el);
						}
						break;
					case Variant::etMapStringVariant:
						size += S;
						BOOST_FOREACH(const Variant::MapStringVariant::value_type &el, v.as<Variant::MapStringVariant>())
						{
							//key
							size += S;
							size += el.first.size();
							//value
							size += calcSize(el.second);
						}
						break;
					case Variant::etBool:
						size += 1;
						break;
					case Variant::etTm:
						size += 9*4;
						break;
					case Variant::etBitset8:
						size += 1;
						break;
					case Variant::etBitset16:
						size += 2;
						break;
					case Variant::etBitset32:
						size += 4;
						break;
					case Variant::etBitset64:
						size += 8;
						break;
					case Variant::etBitset128:
						size += 16;
						break;
					case Variant::etBitset256:
						size += 32;
						break;
					case Variant::etBitset512:
						size += 64;
						break;
					case Variant::etDateDuration:
						size += 4;
						break;
					case Variant::etTimeDuration:
						size += 4;
						break;
					case Variant::etDateTimeDuration:
						size += 8;
						break;
					case Variant::etMapVariantVariant:
						size += S;
						BOOST_FOREACH(const Variant::MapVariantVariant::value_type &el, v.as<Variant::MapVariantVariant>())
						{
							//key
							size += calcSize(el.first);
							//value
							size += calcSize(el.second);
						}
						break;
					case Variant::etMultimapStringVariant:
						size += S;
						BOOST_FOREACH(const Variant::MultimapStringVariant::value_type &el, v.as<Variant::MultimapStringVariant>())
						{
							//key
							size += S;
							size += el.first.size();
							//value
							size += calcSize(el.second);
						}
						break;
					case Variant::etMultimapVariantVariant:
						size += S;
						BOOST_FOREACH(const Variant::MultimapVariantVariant::value_type &el, v.as<Variant::MultimapVariantVariant>())
						{
							//key
							size += calcSize(el.first);
							//value
							size += calcSize(el.second);
						}
						break;
					case Variant::etSetVariant:
						size += S;
						BOOST_FOREACH(const Variant &el, v.as<Variant::SetVariant>())
						{
							size += calcSize(el);
						}
						break;
					case Variant::etMultisetVariant:
						size += S;
						BOOST_FOREACH(const Variant &el, v.as<Variant::MultisetVariant>())
						{
							size += calcSize(el);
						}
						break;
					case Variant::etDequeVariant:
						size += S;
						BOOST_FOREACH(const Variant &el, v.as<Variant::DequeVariant>())
						{
							size += calcSize(el);
						}
						break;
					case Variant::etListVariant:
						size += S;
						BOOST_FOREACH(const Variant &el, v.as<Variant::ListVariant>())
						{
							size += calcSize(el);
						}
						break;
					case Variant::etChar:
						size += 1;
						break;
					case Variant::etUuid:
						size += 16;
						break;
					case Variant::etVariantPtr:
						size += 4;//key
						{
							const Variant::VariantPtr &p = v.as<Variant::VariantPtr>();
							if(p)
							{
								TMPtrKey::iterator iter = _mPtrKey.find(p);
								if(_mPtrKey.end() == iter)
								{
									//������������ ����� ���� � ��������� ��� � �����
									_mPtrKey.insert(std::make_pair(p, _mPtrKey.size()+1));
									size += calcSize(*p);
								}
								else
								{
									//��� ���
								}
							}
						}
						break;
					default:
						assert(0);
					}
				}
				return size;
			}

			//////////////////////////////////////////////////////////////////////////
			void writeBinary(const char *data, uint32_t size)
			{
				assert(_bufEnd-_bufIter >= (int)size);
				memcpy(_bufIter, data, size);
				_bufIter += size;
			}

			//////////////////////////////////////////////////////////////////////////
			template <class T>
			void writeIntegral(const T &value)
			{
				assert(_bufEnd-_bufIter >= sizeof(T));
				T v2 = litEndian(value);
				writeBinary((const char *)&v2, sizeof(T));
			}

			//////////////////////////////////////////////////////////////////////////
			void write(const std::string &value)
			{
				uint32_t size = (uint32_t)value.size();
				writeIntegral(size);
				if(size)
				{
					writeBinary(value.data(), size);
				}
			}

			//////////////////////////////////////////////////////////////////////////
			template <size_t N>
			void writeBitset(const std::bitset<N> &value)
			{
				assert(_bufEnd-_bufIter >= N/8);

				uint8_t buf[N/8] = {};
				for(size_t i(0); i<N; i++)
				{
					if(value.test(i))
					{
						buf[i/8] |= 1<<(i%8);
					}
				}
				writeBinary((const char *)buf, N/8);
			}

			//////////////////////////////////////////////////////////////////////////
			template <class Map>
			void writeMap(const Map &value)
			{
				uint32_t size = (uint32_t)value.size();
				writeIntegral(size);
				if(size)
				{
					BOOST_FOREACH(const typename Map::value_type &el, value)
					{
						//key
						write(el.first);
						//value
						write(el.second);
					}
				}
			}

			//////////////////////////////////////////////////////////////////////////
			template <class Seq>
			void writeSeq(const Seq &value)
			{
				uint32_t size = (uint32_t)value.size();
				writeIntegral(size);
				if(size)
				{
					BOOST_FOREACH(const typename Seq::value_type &el, value)
					{
						write(el);
					}
				}
			}


			//////////////////////////////////////////////////////////////////////////
			void write(const Variant &v)
			{
				int16_t et = v.type();
				if(v.isNull())
				{
					et = -et;
				}
				writeIntegral(et);

				if(!v.isNull())
				{
					switch(v.type())
					{
					case Variant::etUnknown:
						break;
					case Variant::etVoid:
						break;
					case Variant::etString:
						write(v.as<Variant::String>());
						break;
					case Variant::etFloat:
						writeIntegral(v.as<Variant::Float>());
						break;
					case Variant::etDouble:
						writeIntegral(v.as<Variant::Double>());
						break;
					case Variant::etInt8:
						writeIntegral(v.as<Variant::Int8>());
						break;
					case Variant::etInt16:
						writeIntegral(v.as<Variant::Int16>());
						break;
					case Variant::etInt32:
						writeIntegral(v.as<Variant::Int32>());
						break;
					case Variant::etInt64:
						writeIntegral(v.as<Variant::Int64>());
						break;
					case Variant::etUInt8:
						writeIntegral(v.as<Variant::UInt8>());
						break;
					case Variant::etUInt16:
						writeIntegral(v.as<Variant::UInt16>());
						break;
					case Variant::etUInt32:
						writeIntegral(v.as<Variant::UInt32>());
						break;
					case Variant::etUInt64:
						writeIntegral(v.as<Variant::UInt64>());
						break;
					case Variant::etVectorChar:
						{
							const Variant::VectorChar &raw = v.as<Variant::VectorChar>();
							uint32_t size = (uint32_t)raw.size();
							writeIntegral(size);
							if(size)
							{
								writeBinary(&raw[0], size);
							}
						}
						break;
					case Variant::etDate:
						{
							const Variant::Date &raw = v.as<Variant::Date>();
							uint32_t ui4 = 
								raw.year()*10000 + 
								raw.month()*100 + 
								raw.day();
							writeIntegral(ui4);
						}
						break;
					case Variant::etDatetime:
						{
							const Variant::Datetime &raw = v.as<Variant::Datetime>();
							const Variant::Date d = raw.date();
							const Variant::TimeDuration td = raw.time_of_day();

							uint32_t ui4_d = 
								d.year()*10000 + 
								d.month()*100 + 
								d.day();
							writeIntegral(ui4_d);

							writeIntegral((int32_t)td.total_microseconds());
						}
						break;
					case Variant::etVectorVariant:
						writeSeq(v.as<Variant::VectorVariant>());
						break;
					case Variant::etMapStringVariant:
						writeMap(v.as<Variant::MapStringVariant>());
						break;
					case Variant::etBool:
						writeIntegral(v.as<Variant::Bool>());
						break;
					case Variant::etTm:
						{
							const Variant::Tm &raw = v.as<Variant::Tm>();

							writeIntegral((int32_t)raw.tm_sec);     /* seconds after the minute - [0,59] */
							writeIntegral((int32_t)raw.tm_min);     /* minutes after the hour - [0,59] */
							writeIntegral((int32_t)raw.tm_hour);    /* hours since midnight - [0,23] */
							writeIntegral((int32_t)raw.tm_mday);    /* day of the month - [1,31] */
							writeIntegral((int32_t)raw.tm_mon);     /* months since January - [0,11] */
							writeIntegral((int32_t)raw.tm_year);    /* years since 1900 */
							writeIntegral((int32_t)raw.tm_wday);    /* days since Sunday - [0,6] */
							writeIntegral((int32_t)raw.tm_yday);    /* days since January 1 - [0,365] */
							writeIntegral((int32_t)raw.tm_isdst);   /* daylight savings time flag */
						}
						break;
					case Variant::etBitset8:
						writeBitset(v.as<Variant::Bitset8>());
						break;
					case Variant::etBitset16:
						writeBitset(v.as<Variant::Bitset16>());
						break;
					case Variant::etBitset32:
						writeBitset(v.as<Variant::Bitset32>());
						break;
					case Variant::etBitset64:
						writeBitset(v.as<Variant::Bitset64>());
						break;
					case Variant::etBitset128:
						writeBitset(v.as<Variant::Bitset128>());
						break;
					case Variant::etBitset256:
						writeBitset(v.as<Variant::Bitset256>());
						break;
					case Variant::etBitset512:
						writeBitset(v.as<Variant::Bitset512>());
						break;
					case Variant::etDateDuration:
						writeIntegral((int32_t)v.as<Variant::DateDuration>().days());
						break;
					case Variant::etTimeDuration:
						writeIntegral((int32_t)v.as<Variant::TimeDuration>().total_microseconds());
						break;
					case Variant::etDateTimeDuration:
						{
							const Variant::DateTimeDuration &raw = v.as<Variant::DateTimeDuration>();
							writeIntegral((int32_t)raw._dd.days());
							writeIntegral((int32_t)raw._td.total_microseconds());
						}
						break;
					case Variant::etMapVariantVariant:
						writeMap(v.as<Variant::MapVariantVariant>());
						break;
					case Variant::etMultimapStringVariant:
						writeMap(v.as<Variant::MultimapStringVariant>());
						break;
					case Variant::etMultimapVariantVariant:
						writeMap(v.as<Variant::MultimapVariantVariant>());
						break;
					case Variant::etSetVariant:
						writeSeq(v.as<Variant::SetVariant>());
						break;
					case Variant::etMultisetVariant:
						writeSeq(v.as<Variant::MultisetVariant>());
						break;
					case Variant::etDequeVariant:
						writeSeq(v.as<Variant::DequeVariant>());
						break;
					case Variant::etListVariant:
						writeSeq(v.as<Variant::ListVariant>());
						break;
					case Variant::etChar:
						writeIntegral(v.as<Variant::Char>());
						break;
					case Variant::etUuid:
						{
							const Variant::Uuid &raw = v.as<Variant::Uuid>();
							writeBinary((char *)raw.data, 16);
						}
						break;
					case Variant::etVariantPtr:
						{
							const Variant::VariantPtr &p = v.as<Variant::VariantPtr>();
							if(p)
							{
								TMPtrKey::iterator iter = _mPtrKey.find(p);
								if(_mPtrKey.end() == iter)
								{
									//������������ ����� ���� � ��������� ��� � �����
									uint32_t key = _mPtrKey.size()+1;
									_mPtrKey.insert(std::make_pair(p,key));

									writeIntegral(key);
									write(*p);
								}
								else
								{
									//��� ���
									writeIntegral(iter->second);
								}
							}
							else
							{
								uint32_t key = 0;
								writeIntegral(key);
							}
						}
						break;
					default:
						assert(0);
					}
				}
			}
		};
	}

	//////////////////////////////////////////////////////////////////////////
	shared_array<char> Variant::serialize(uint32_t &size) const
	{
		Serializer s;
		return s.serialize(*this, size);
	}
	
	//////////////////////////////////////////////////////////////////////////
	bool Variant::deserialize(shared_array<char> data, uint32_t size)
	{
		Variant tmp;
		Serializer s;
		if(!s.deserialize(tmp, data, size))
		{
			return false;
		}
		swap(tmp);
		return true;
	}

}
