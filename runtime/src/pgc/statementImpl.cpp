#include "statementImpl.hpp"
#include "connectionImpl.hpp"
#include "pgDataType.h"
#include "utils/fixEndian.hpp"
#include "utils/ntoa.hpp"
#include "utils/julian.h"
#include <boost/static_assert.hpp>
#include "pgc/blob.hpp"
#include "blobImpl.hpp"

namespace pgc
{
	StatementImpl::StatementImpl(ConnectionImplPtr con)
		: _con(con)
	{

	}
	StatementImpl::~StatementImpl()
	{
		unbind(0);
		_con.reset();
	}

	ConnectionImplPtr StatementImpl::con()
	{
		return _con;
	}

	void StatementImpl::sql(const char *sql)
	{
		_sql = sql;
	}

	void StatementImpl::sql(const std::string &sql)
	{
		_sql = sql;
	}

	bool StatementImpl::empty() const
	{
		return _sql.empty();
	}

	namespace impl
	{
		template <size_t N>
		void bitset2Bits(const std::bitset<N> &bs, boost::uint8_t *bits)
		{
			BOOST_STATIC_ASSERT(N%8 == 0);

			for(size_t i(0); i<N/8; i++)
			{
				bits[i]=
					(bs[i*8+0]?0x80:0) |
					(bs[i*8+1]?0x40:0) |
					(bs[i*8+2]?0x20:0) |
					(bs[i*8+3]?0x10:0) |
					(bs[i*8+4]?0x08:0) |
					(bs[i*8+5]?0x04:0) |
					(bs[i*8+6]?0x02:0) |
					(bs[i*8+7]?0x01:0);
			}
		}
	}
	bool StatementImpl::bind(int typCpp, void const *valCpp, size_t idx)
	{
		assert(
			_bindTyp.size() == _bindVal.size() &&
			_bindTyp.size() == _bindVal.size() &&
			_bindTyp.size() == _bindLen.size() &&
			_bindTyp.size() == _bindFmt.size() &&
			_bindTyp.size() == _bindOwn.size());

		Oid	bindTyp;
		char *bindVal;
		int bindLen;
		int bindFmt;
		bool bindOwn;

		bool bf = bindFiller(
			typCpp, valCpp,
			bindTyp,
			bindVal,
			bindLen,
			bindFmt,
			bindOwn);

		if(bf)
		{

			if(!idx)
			{
				idx = _bindTyp.size();
			}
			else
			{
				//���������� � ��������, ���� � ����
				idx--;
			}

			if(idx >= _bindTyp.size())
			{
				_bindTyp.resize(idx+1, InvalidOid);
				_bindVal.resize(idx+1, NULL);
				_bindLen.resize(idx+1, 0);
				_bindFmt.resize(idx+1, 0);
				_bindOwn.resize(idx+1, false);
			}
			else
			{
				unbind(idx+1);
			}

			_bindTyp[idx] = bindTyp;
			_bindVal[idx] = bindVal;
			_bindLen[idx] = bindLen;
			_bindFmt[idx] = bindFmt;
			_bindOwn[idx] = bindOwn;

			return true;
		}

		return false;
	}

	void StatementImpl::unbind(size_t idx)
	{
		assert(
			_bindTyp.size() == _bindVal.size() &&
			_bindTyp.size() == _bindVal.size() &&
			_bindTyp.size() == _bindLen.size() &&
			_bindTyp.size() == _bindFmt.size() &&
			_bindTyp.size() == _bindOwn.size());

		if(idx)
		{
			idx--;

			if(idx < _bindTyp.size())
			{
				_bindTyp[idx] = 0;//untyped literal string

				if(_bindOwn[idx])
				{
					delete [] _bindVal[idx];
				}

				_bindVal[idx] = NULL;
				_bindLen[idx] = 0;//ignored for text
				_bindFmt[idx] = 0;//text
				_bindOwn[idx] = false;//alien _bindVal[idx]
			}

		}
		else
		{
			//all
			if(!_bindTyp.empty())
			{
				for(size_t i(0); i<_bindTyp.size(); i++)
				{
					if(_bindOwn[idx])
					{
						delete [] _bindVal[idx];
					}
				}

				_bindTyp.clear();
				_bindVal.clear();
				_bindLen.clear();
				_bindFmt.clear();
				_bindOwn.clear();
			}
		}
	}

	PGresult *StatementImpl::exec()
	{
		_con->doLogExec(_sql);

		PGresult *res = NULL;
		if(_bindTyp.empty())
		{
			res = PQexecParams(
				_con->_pgcon,
				_sql.c_str(),
				0,
				0,
				0,
				0,
				0,
				1);
		}
		else
		{
			assert(
				_bindTyp.size() == _bindVal.size() &&
				_bindTyp.size() == _bindVal.size() &&
				_bindTyp.size() == _bindLen.size() &&
				_bindTyp.size() == _bindFmt.size() &&
				_bindTyp.size() == _bindOwn.size());

			res = PQexecParams(
				_con->_pgcon,
				_sql.c_str(),
				(int)_bindTyp.size(),
				&_bindTyp[0],
				&_bindVal[0],
				&_bindLen[0],
				&_bindFmt[0],
				1);
		}
		_con->doLogError(_sql, res);

		//��������� �����
		unbind(0);

		return res;
	}





	//////////////////////////////////////////////////////////////////////////
	bool StatementImpl::bindFiller(
		int typCpp, void const *valCpp,
		Oid	&bindTyp,
		char *&bindVal,
		int &bindLen,
		int &bindFmt,
		bool &bindOwn)
	{
		if(!valCpp)
		{
			bindVal = NULL;
			bindLen = 0;
			bindOwn = false;
		}

		switch(typCpp)
		{
// 		case CppDataType<char *>::cdt_index:
// 			bindTyp = 0;//untyped literal string
// 			bindVal = *(char **)valCpp;
// 			bindLen = 0;//ignored for text
// 			bindFmt = 0;//text
// 			bindOwn = false;//alien bindVal
// 			break;
		case CppDataType<std::string>::cdt_index:
			bindTyp = 0;//untyped literal string
			bindFmt = 0;//text
			if(valCpp)
			{
				bindVal = const_cast<char *>((*(std::string *)valCpp).data());
				bindLen = 0;//ignored for text
				bindOwn = false;//alien bindVal
			}
			break;
		case CppDataType<bool>::cdt_index:
			bindTyp = 16;//bool
			bindFmt = 1;//binary
			if(valCpp)
			{
				bindVal = new char[1];
				*bindVal = (*(bool *)valCpp);
				bindLen = 1;
				bindOwn = true;//own bindVal wil be deleted later
			}
			break;
		case CppDataType<float>::cdt_index:
			bindTyp = 700;//float4
			bindFmt = 1;
			if(valCpp)
			{
				bindVal = new char[4];
				*(float *)bindVal = utils::fixEndian(*(float *)valCpp);
				bindLen = 4;
				bindOwn = true;
			}
			break;
		case CppDataType<double>::cdt_index:
			bindTyp = 701;//float8
			bindFmt = 1;
			if(valCpp)
			{
				bindVal = new char[8];
				*(double *)bindVal = utils::fixEndian(*(double *)valCpp);
				bindLen = 8;
				bindOwn = true;
			}
			break;
		case CppDataType<boost::int8_t>::cdt_index:
			bindTyp = 21;//int2
			bindFmt = 1;
			if(valCpp)
			{
				bindVal = new char[2];
				*(boost::uint16_t *)bindVal = utils::fixEndian((boost::int16_t)*(boost::int8_t *)valCpp);
				bindLen = 2;
				bindOwn = true;
			}
			break;
		case CppDataType<boost::int16_t>::cdt_index:
			bindTyp = 21;//int2
			bindFmt = 1;
			if(valCpp)
			{
				bindVal = new char[2];
				*(boost::uint16_t *)bindVal = utils::fixEndian(*(boost::int16_t *)valCpp);
				bindLen = 2;
				bindOwn = true;
			}
			break;
		case CppDataType<boost::int32_t>::cdt_index:
			bindTyp = 23;//int4
			bindFmt = 1;
			if(valCpp)
			{
				bindVal = new char[4];
				*(boost::uint32_t *)bindVal = utils::fixEndian(*(boost::int32_t *)valCpp);
				bindLen = 4;
				bindOwn = true;
			}
			break;
		case CppDataType<boost::int64_t>::cdt_index:
			bindTyp = 20;//int8
			bindFmt = 1;
			if(valCpp)
			{
				bindVal = new char[8];
				*(boost::uint64_t *)bindVal = utils::fixEndian(*(boost::int64_t *)valCpp);
				bindLen = 8;
				bindOwn = true;
			}
			break;
		case CppDataType<boost::uint8_t>::cdt_index:
			bindTyp = 21;//int2
			bindFmt = 1;
			if(valCpp)
			{
				bindVal = new char[2];
				*(boost::uint16_t *)bindVal = utils::fixEndian((boost::uint16_t)*(boost::uint8_t *)valCpp);
				bindLen = 2;
				bindOwn = true;
			}
			break;
		case CppDataType<boost::uint16_t>::cdt_index:
			bindTyp = 23;//int4
			bindFmt = 1;
			if(valCpp)
			{
				bindVal = new char[4];
				*(boost::uint32_t *)bindVal = utils::fixEndian((boost::uint32_t)*(boost::uint16_t *)valCpp);
				bindLen = 4;
				bindOwn = true;
			}
			break;
		case CppDataType<boost::uint32_t>::cdt_index:
			bindTyp = 20;//int8
			bindFmt = 1;
			if(valCpp)
			{
				bindVal = new char[8];
				*(boost::uint64_t *)bindVal = utils::fixEndian((boost::uint64_t)*(boost::uint32_t *)valCpp);
				bindLen = 8;
				bindOwn = true;
			}
			break;
		case CppDataType<boost::uint64_t>::cdt_index:
			{
				bindTyp = 20;//int8
				bindFmt = 1;
				if(valCpp)
				{
					boost::uint64_t &ui64 = *(boost::uint64_t *)valCpp;
					if(ui64 & 0x8000000000000000ULL)
					{
						bindTyp = 0;
						bindFmt = 0;
						bindVal = new char[32];
						utils::_ntoa(ui64, bindVal);
						bindLen = 0;
						bindOwn = true;
					}
					else
					{
						bindVal = new char[8];
						*(boost::uint64_t *)bindVal = utils::fixEndian(*(boost::uint64_t *)valCpp);
						bindLen = 8;
						bindOwn = true;
					}
				}
			}
			break;
		case CppDataType<std::tm>::cdt_index:
			{
				bindTyp = 1114;//timestamp
				bindFmt = 1;

				if(valCpp)
				{
					const std::tm &stm = *(const std::tm *)valCpp;

					boost::int64_t ts =
						utils::time2t(stm.tm_hour, stm.tm_min, stm.tm_sec, 0) +
						(utils::date2j(stm.tm_year+1900, stm.tm_mon+1, stm.tm_mday) - utils::POSTGRES_EPOCH_JDATE) * utils::USECS_PER_DAY;

					bindVal = new char[8];

					if(_con->integerDatetimes())
						*(boost::uint64_t *)bindVal = utils::fixEndian(ts);
					else
						*(double *)bindVal = utils::fixEndian(double(ts/1000000)+double(ts%1000000)/1000000);
					bindLen = 8;
					bindOwn = true;
				}
			}
			break;
		case CppDataType<boost::gregorian::date>::cdt_index:
			{
				bindTyp = 1082;//date
				bindFmt = 1;
				if(valCpp)
				{
					const boost::gregorian::date &bgd = *(const boost::gregorian::date *)valCpp;

					boost::int32_t d =
						utils::date2j(bgd.year(), bgd.month(), bgd.day()) - utils::POSTGRES_EPOCH_JDATE;

					bindVal = new char[4];
					*(boost::uint32_t *)bindVal = utils::fixEndian(d);
					bindLen = 4;
					bindOwn = true;
				}
			}
			break;
		case CppDataType<boost::posix_time::ptime>::cdt_index:
			{
				bindTyp = 1114;//timestamp
				bindFmt = 1;
				if(valCpp)
				{
					const boost::posix_time::ptime &ptm = *(const boost::posix_time::ptime *)valCpp;

					boost::gregorian::date bgd = ptm.date();
					boost::posix_time::time_duration pt = ptm.time_of_day();

					boost::int64_t ts =
						pt.total_microseconds() +
						(utils::date2j(bgd.year(), bgd.month(), bgd.day()) - utils::POSTGRES_EPOCH_JDATE) * utils::USECS_PER_DAY;

					bindVal = new char[8];
					if(_con->integerDatetimes())
						*(boost::uint64_t *)bindVal = utils::fixEndian(ts);
					else
					{
						*(double *)bindVal = utils::fixEndian(double(ts/1000000)+double(ts%1000000)/1000000);
					}
					bindLen = 8;
					bindOwn = true;
				}
			}
			break;
		case CppDataType<boost::gregorian::date_duration>::cdt_index:
			{
				bindTyp = 1186;//interval
				bindFmt = 1;
				if(valCpp)
				{
					const boost::gregorian::date_duration &bgdd = *(const boost::gregorian::date_duration *)valCpp;

					bindVal = new char[sizeof(PG_Interval)];
					PG_Interval &pgi = *(PG_Interval *)bindVal;
					bindLen = sizeof(PG_Interval);
					bindOwn = true;

					pgi.month = utils::fixEndian((boost::uint32_t)(bgdd.days() / utils::DAYS_PER_MONTH));
					pgi.day = utils::fixEndian((boost::uint32_t)(bgdd.days() % utils::DAYS_PER_MONTH));
					pgi.time = 0;
				}
			}
			break;
		case CppDataType<boost::posix_time::time_duration>::cdt_index:
			{
				bindTyp = 1186;//interval
				bindFmt = 1;
				if(valCpp)
				{
					const boost::posix_time::time_duration &bptd = *(const boost::posix_time::time_duration *)valCpp;

					bindVal = new char[sizeof(PG_Interval)];
					PG_Interval &pgi = *(PG_Interval *)bindVal;
					bindLen = sizeof(PG_Interval);
					bindOwn = true;

					pgi.month = 0;
					pgi.day = 0;
					if(_con->integerDatetimes())
						pgi.time = utils::fixEndian(bptd.total_microseconds());
					else
					{
						boost::int64_t tms = bptd.total_microseconds();
						*(double *)(void *)&pgi.time = utils::fixEndian(double(tms/1000000)+double(tms%1000000)/1000000);
					}
				}
			}
			break;
		case CppDataType<utils::DateTimeDuration>::cdt_index:
			{
				bindTyp = 1186;//interval
				bindFmt = 1;
				if(valCpp)
				{
					const utils::DateTimeDuration &dtd = *(const utils::DateTimeDuration *)valCpp;

					bindVal = new char[sizeof(PG_Interval)];
					PG_Interval &pgi = *(PG_Interval *)bindVal;
					bindLen = sizeof(PG_Interval);
					bindOwn = true;

					pgi.month = utils::fixEndian((boost::uint32_t)(dtd._dd.days() / utils::DAYS_PER_MONTH));
					pgi.day = utils::fixEndian((boost::uint32_t)(dtd._dd.days() % utils::DAYS_PER_MONTH));

					if(_con->integerDatetimes())
						pgi.time = utils::fixEndian(dtd._td.total_microseconds());
					else
					{
						boost::int64_t tms = dtd._td.total_microseconds();
						*(double *)(void *)&pgi.time = utils::fixEndian(double(tms/1000000)+double(tms%1000000)/1000000);
					}
				}
			}
			break;

		case CppDataType<std::bitset<8> >::cdt_index:
			{
				bindTyp = 1562;//varbit
				bindFmt = 1;
				if(valCpp)
				{
					const std::bitset<8> &bs = *(const std::bitset<8> *)valCpp;

					bindVal = new char[sizeof(PG_VarBit)-1+1];
					PG_VarBit &vb = *(PG_VarBit *)bindVal;
					bindLen = sizeof(PG_VarBit)-1+1;
					bindOwn = true;

					vb.amount = utils::fixEndian((boost::uint32_t)8);
					impl::bitset2Bits(bs, vb.bits);
				}
			}
			break;
		case CppDataType<std::bitset<16> >::cdt_index:
			{
				bindTyp = 1562;//varbit
				bindFmt = 1;
				if(valCpp)
				{
					const std::bitset<16> &bs = *(const std::bitset<16> *)valCpp;

					bindVal = new char[sizeof(PG_VarBit)-1+2];
					PG_VarBit &vb = *(PG_VarBit *)bindVal;
					bindLen = sizeof(PG_VarBit)-1+2;
					bindOwn = true;

					vb.amount = utils::fixEndian((boost::uint32_t)16);
					impl::bitset2Bits(bs, vb.bits);
				}
			}
			break;
		case CppDataType<std::bitset<32> >::cdt_index:
			{
				bindTyp = 1562;//varbit
				bindFmt = 1;
				if(valCpp)
				{
					const std::bitset<32> &bs = *(const std::bitset<32> *)valCpp;

					bindVal = new char[sizeof(PG_VarBit)-1+4];
					PG_VarBit &vb = *(PG_VarBit *)bindVal;
					bindLen = sizeof(PG_VarBit)-1+4;
					bindOwn = true;

					vb.amount = utils::fixEndian((boost::uint32_t)32);
					impl::bitset2Bits(bs, vb.bits);
				}
			}
			break;
		case CppDataType<std::bitset<64> >::cdt_index:
			{
				bindTyp = 1562;//varbit
				bindFmt = 1;
				if(valCpp)
				{
					const std::bitset<64> &bs = *(const std::bitset<64> *)valCpp;

					bindVal = new char[sizeof(PG_VarBit)-1+8];
					PG_VarBit &vb = *(PG_VarBit *)bindVal;
					bindLen = sizeof(PG_VarBit)-1+8;
					bindOwn = true;

					vb.amount = utils::fixEndian((boost::uint32_t)64);
					impl::bitset2Bits(bs, vb.bits);
				}
			}
			break;
		case CppDataType<std::bitset<128> >::cdt_index:
			{
				bindTyp = 1562;//varbit
				bindFmt = 1;

				if(valCpp)
				{
					const std::bitset<128> &bs = *(const std::bitset<128> *)valCpp;

					bindVal = new char[sizeof(PG_VarBit)-1+16];
					PG_VarBit &vb = *(PG_VarBit *)bindVal;
					bindLen = sizeof(PG_VarBit)-1+16;
					bindOwn = true;

					vb.amount = utils::fixEndian((boost::uint32_t)128);
					impl::bitset2Bits(bs, vb.bits);
				}
			}
			break;
		case CppDataType<std::bitset<256> >::cdt_index:
			{
				bindTyp = 1562;//varbit
				bindFmt = 1;
				if(valCpp)
				{
					const std::bitset<256> &bs = *(const std::bitset<256> *)valCpp;

					bindVal = new char[sizeof(PG_VarBit)-1+32];
					PG_VarBit &vb = *(PG_VarBit *)bindVal;
					bindLen = sizeof(PG_VarBit)-1+32;
					bindOwn = true;

					vb.amount = utils::fixEndian((boost::uint32_t)256);
					impl::bitset2Bits(bs, vb.bits);
				}
			}
			break;
		case CppDataType<std::bitset<512> >::cdt_index:
			{
				bindTyp = 1562;//varbit
				bindFmt = 1;
				if(valCpp)
				{
					const std::bitset<512> &bs = *(const std::bitset<512> *)valCpp;

					bindVal = new char[sizeof(PG_VarBit)-1+64];
					PG_VarBit &vb = *(PG_VarBit *)bindVal;
					bindLen = sizeof(PG_VarBit)-1+64;
					bindOwn = true;

					vb.amount = utils::fixEndian((boost::uint32_t)512);
					impl::bitset2Bits(bs, vb.bits);
				}
			}
			break;
		case CppDataType<std::vector<unsigned char> >::cdt_index:
			{
				bindTyp = 17;//bytea
				bindFmt = 1;
				if(valCpp)
				{
					std::vector<unsigned char> &vec = *(std::vector<unsigned char> *)valCpp;
					bindVal = (char *)&vec[0];
					bindLen = (int)vec.size();
					bindOwn = false;
				}
			}
			break;
		case CppDataType<Blob>::cdt_index:
			{
				bindTyp = 26;//oid
				bindFmt = 1;
				if(valCpp)
				{
					Blob &b = *(Blob *)valCpp;
					bindVal = new char[4];
					*(Oid *)bindVal = utils::fixEndian(b._impl->oid());
					bindLen = 4;
					bindOwn = true;
				}
			}
			break;

		case CppDataType<Money>::cdt_index:
			{
				bindTyp = 790;//money
				bindFmt = 1;
				if(valCpp)
				{
					boost::int64_t &i64 = ((Money *)valCpp)->_value;
					bindVal = new char[8];
					*(boost::uint64_t *)bindVal = utils::fixEndian(i64);
					bindLen = 8;
					bindOwn = true;
				}
			}
			break;
		default:
			{
				return false;
				assert(!"unknown type for bind");
				bindTyp = 0;
				bindFmt = 0;
				bindVal = NULL;
				bindLen = 0;
				bindOwn = false;
			}
			break;

		}

		return true;
	}

}
