#include "statementImpl.hpp"
#include "connectionImpl.hpp"
#include "pgDataType.h"
#include "utils/fixEndian.hpp"
#include "utils/ntoa.hpp"
#include "utils/julian.h"

namespace pgc
{
	void StatementImpl::ensureBindIndex(size_t idx)
	{
		if(idx >= _bindTyp.size())
		{
			_bindTyp.resize(idx+1, InvalidOid);
			_bindVal.resize(idx+1, NULL);
			_bindLen.resize(idx+1, 0);
			_bindFmt.resize(idx+1, 0);
			_bindOwn.resize(idx+1, false);
		}
	}

	StatementImpl::StatementImpl(ConnectionImplPtr con, bool once)
		: _con(con)
		, _once(once)
	{

	}
	StatementImpl::~StatementImpl()
	{
		unbind(0);
		_con.reset();
	}

	void StatementImpl::sql(const char *csz)
	{
		_sql = csz;
	}
	void StatementImpl::bind(int typCpp, void const *valCpp, size_t idx)
	{
		assert(
			_bindTyp.size() == _bindVal.size() &&
			_bindTyp.size() == _bindVal.size() &&
			_bindTyp.size() == _bindLen.size() &&
			_bindTyp.size() == _bindFmt.size() &&
			_bindTyp.size() == _bindOwn.size());

		if(!idx)
		{
			idx = _bindTyp.size();
		}
		else
		{
			//начинается с единички, надо с нуля
			idx--;
		}
		ensureBindIndex(idx);
		unbind(idx+1);

		switch(typCpp)
		{
		case CppDataType<char *>::cdt_index:
			_bindTyp[idx] = 0;//untyped literal string
			_bindVal[idx] = *(char **)valCpp;
			_bindLen[idx] = 0;//ignored for text
			_bindFmt[idx] = 0;//text
			_bindOwn[idx] = false;//alien _bindVal[idx]
			break;
		case CppDataType<std::string>::cdt_index:
			_bindTyp[idx] = 0;//untyped literal string
			_bindVal[idx] = const_cast<char *>((*(std::string *)valCpp).data());
			_bindLen[idx] = 0;//ignored for text
			_bindFmt[idx] = 0;//text
			_bindOwn[idx] = false;//alien _bindVal[idx]
			break;
		case CppDataType<bool>::cdt_index:
			_bindTyp[idx] = 16;//bool
			_bindVal[idx] = new char[1];
			*_bindVal[idx] = (*(bool *)valCpp);
			_bindLen[idx] = 1;
			_bindFmt[idx] = 1;//binary
			_bindOwn[idx] = true;//own _bindVal[idx] wil be deleted later
			break;
		case CppDataType<float>::cdt_index:
			_bindTyp[idx] = 700;//float4
			_bindVal[idx] = new char[4];
			*(float *)_bindVal[idx] = utils::fixEndian(*(float *)valCpp);
			_bindLen[idx] = 4;
			_bindFmt[idx] = 1;
			_bindOwn[idx] = true;
			break;
		case CppDataType<double>::cdt_index:
			_bindTyp[idx] = 701;//float8
			_bindVal[idx] = new char[8];
			*(double *)_bindVal[idx] = utils::fixEndian(*(double *)valCpp);
			_bindLen[idx] = 8;
			_bindFmt[idx] = 1;
			_bindOwn[idx] = true;
			break;
		case CppDataType<boost::int8_t>::cdt_index:
			_bindTyp[idx] = 21;//int2
			_bindVal[idx] = new char[2];
			*(boost::uint16_t *)_bindVal[idx] = utils::fixEndian((boost::int16_t)*(boost::int8_t *)valCpp);
			_bindLen[idx] = 2;
			_bindFmt[idx] = 1;
			_bindOwn[idx] = true;
			break;
		case CppDataType<boost::int16_t>::cdt_index:
			_bindTyp[idx] = 21;//int2
			_bindVal[idx] = new char[2];
			*(boost::uint16_t *)_bindVal[idx] = utils::fixEndian(*(boost::int16_t *)valCpp);
			_bindLen[idx] = 2;
			_bindFmt[idx] = 1;
			_bindOwn[idx] = true;
			break;
		case CppDataType<boost::int32_t>::cdt_index:
			_bindTyp[idx] = 23;//int4
			_bindVal[idx] = new char[4];
			*(boost::uint32_t *)_bindVal[idx] = utils::fixEndian(*(boost::int32_t *)valCpp);
			_bindLen[idx] = 4;
			_bindFmt[idx] = 1;
			_bindOwn[idx] = true;
			break;
		case CppDataType<boost::int64_t>::cdt_index:
			_bindTyp[idx] = 20;//int8
			_bindVal[idx] = new char[8];
			*(boost::uint64_t *)_bindVal[idx] = utils::fixEndian(*(boost::int64_t *)valCpp);
			_bindLen[idx] = 8;
			_bindFmt[idx] = 1;
			_bindOwn[idx] = true;
			break;
		case CppDataType<boost::uint8_t>::cdt_index:
			_bindTyp[idx] = 21;//int2
			_bindVal[idx] = new char[2];
			*(boost::uint16_t *)_bindVal[idx] = utils::fixEndian((boost::uint16_t)*(boost::uint8_t *)valCpp);
			_bindLen[idx] = 2;
			_bindFmt[idx] = 1;
			_bindOwn[idx] = true;
			break;
		case CppDataType<boost::uint16_t>::cdt_index:
			_bindTyp[idx] = 23;//int4
			_bindVal[idx] = new char[4];
			*(boost::uint32_t *)_bindVal[idx] = utils::fixEndian((boost::uint32_t)*(boost::uint16_t *)valCpp);
			_bindLen[idx] = 4;
			_bindFmt[idx] = 1;
			_bindOwn[idx] = true;
			break;
		case CppDataType<boost::uint32_t>::cdt_index:
			_bindTyp[idx] = 20;//int8
			_bindVal[idx] = new char[8];
			*(boost::uint64_t *)_bindVal[idx] = utils::fixEndian((boost::uint64_t)*(boost::uint32_t *)valCpp);
			_bindLen[idx] = 8;
			_bindFmt[idx] = 1;
			_bindOwn[idx] = true;
			break;
		case CppDataType<boost::uint64_t>::cdt_index:
			{
				boost::uint64_t &ui64 = *(boost::uint64_t *)valCpp;
				if(ui64 & 0x8000000000000000ULL)
				{
					_bindTyp[idx] = 20;//int8
					_bindVal[idx] = new char[8];
					*(boost::uint64_t *)_bindVal[idx] = utils::fixEndian(*(boost::uint64_t *)valCpp);
					_bindLen[idx] = 8;
					_bindFmt[idx] = 1;
					_bindOwn[idx] = true;
				}
				else
				{
					_bindTyp[idx] = 0;
					_bindVal[idx] = new char[32];
					utils::_ntoa(ui64, _bindVal[idx]);
					_bindLen[idx] = 0;
					_bindFmt[idx] = 0;
					_bindOwn[idx] = true;
				}
			}
			break;
		case CppDataType<std::tm>::cdt_index:
			{
				const std::tm &stm = *(const std::tm *)valCpp;

				boost::int64_t ts = 
					utils::time2t(stm.tm_hour, stm.tm_min, stm.tm_sec, 0) + 
					(utils::date2j(stm.tm_year+1900, stm.tm_mon+1, stm.tm_mday) - utils::POSTGRES_EPOCH_JDATE) * utils::USECS_PER_DAY;

				_bindTyp[idx] = 1114;//timestamp
				_bindVal[idx] = new char[8];
				*(boost::uint64_t *)_bindVal[idx] = utils::fixEndian(ts);
				_bindLen[idx] = 8;
				_bindFmt[idx] = 1;
				_bindOwn[idx] = true;

			}
			break;
		case CppDataType<boost::gregorian::date>::cdt_index:
			{
				const boost::gregorian::date &bgd = *(const boost::gregorian::date *)valCpp;

				boost::int32_t d = 
					utils::date2j(bgd.year(), bgd.month(), bgd.day()) - utils::POSTGRES_EPOCH_JDATE;

				_bindTyp[idx] = 1082;//date
				_bindVal[idx] = new char[4];
				*(boost::uint32_t *)_bindVal[idx] = utils::fixEndian(d);
				_bindLen[idx] = 4;
				_bindFmt[idx] = 1;
				_bindOwn[idx] = true;

			}
			break;
		case CppDataType<boost::posix_time::ptime>::cdt_index:
			{
				const boost::posix_time::ptime &ptm = *(const boost::posix_time::ptime *)valCpp;

				boost::gregorian::date bgd = ptm.date();
				boost::posix_time::time_duration pt = ptm.time_of_day();

				boost::int64_t ts = 
					pt.total_microseconds() + 
					(utils::date2j(bgd.year(), bgd.month(), bgd.day()) - utils::POSTGRES_EPOCH_JDATE) * utils::USECS_PER_DAY;

				_bindTyp[idx] = 1114;//timestamp
				_bindVal[idx] = new char[8];
				*(boost::uint64_t *)_bindVal[idx] = utils::fixEndian(ts);
				_bindLen[idx] = 8;
				_bindFmt[idx] = 1;
				_bindOwn[idx] = true;

			}
			break;
		case CppDataType<boost::gregorian::date_duration>::cdt_index:
			{
				const boost::gregorian::date_duration &bgdd = *(const boost::gregorian::date_duration *)valCpp;

				_bindTyp[idx] = 1186;//interval
				_bindVal[idx] = new char[sizeof(PG_Interval)];
				PG_Interval &pgi = *(PG_Interval *)_bindVal[idx];
				_bindLen[idx] = sizeof(PG_Interval);
				_bindFmt[idx] = 1;
				_bindOwn[idx] = true;

				pgi.month = utils::fixEndian((boost::uint32_t)(bgdd.days() / utils::DAYS_PER_MONTH));
				pgi.day = utils::fixEndian((boost::uint32_t)(bgdd.days() % utils::DAYS_PER_MONTH));
				pgi.time = 0;
			}
			break;
		case CppDataType<boost::posix_time::time_duration>::cdt_index:
			{
				const boost::posix_time::time_duration &bptd = *(const boost::posix_time::time_duration *)valCpp;

				_bindTyp[idx] = 1186;//interval
				_bindVal[idx] = new char[sizeof(PG_Interval)];
				PG_Interval &pgi = *(PG_Interval *)_bindVal[idx];
				_bindLen[idx] = sizeof(PG_Interval);
				_bindFmt[idx] = 1;
				_bindOwn[idx] = true;

				pgi.month = 0;
				pgi.day = 0;
				pgi.time = utils::fixEndian(bptd.total_microseconds());
			}
			break;
		case CppDataType<DateTimeDuration>::cdt_index:
			{
				const DateTimeDuration &dtd = *(const DateTimeDuration *)valCpp;


				_bindTyp[idx] = 1186;//interval
				_bindVal[idx] = new char[sizeof(PG_Interval)];
				PG_Interval &pgi = *(PG_Interval *)_bindVal[idx];
				_bindLen[idx] = sizeof(PG_Interval);
				_bindFmt[idx] = 1;
				_bindOwn[idx] = true;

				pgi.month = utils::fixEndian((boost::uint32_t)(dtd._dd.days() / utils::DAYS_PER_MONTH));
				pgi.day = utils::fixEndian((boost::uint32_t)(dtd._dd.days() % utils::DAYS_PER_MONTH));
				pgi.time = utils::fixEndian(dtd._td.total_microseconds());
			}
			break;

		}
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

	ResultImplPtr StatementImpl::exec()
	{
		ResultImplPtr res;
		if(_once)
		{
			if(_bindTyp.empty())
			{
				res.reset(new ResultImpl(_con, PQexecParams(
					_con->_pgcon, 
					_sql.c_str(), 
					0, 
					0, 
					0, 
					0, 
					0, 
					1)));
			}
			else
			{
				assert(
					_bindTyp.size() ==
					_bindVal.size() ==
					_bindLen.size() ==
					_bindFmt.size() == 
					_bindOwn.size());

				res.reset(new ResultImpl(_con, PQexecParams(
					_con->_pgcon, 
					_sql.c_str(), 
					_bindTyp.size(), 
					&_bindTyp[0], 
					&_bindVal[0], 
					&_bindLen[0], 
					&_bindFmt[0], 
					1)));
			}
		}
		else
		{
			if(_bindTyp.size())
			{
				assert(!"bind");
			}
			else
			{
				assert(!"exec");
			}
		}

		//почистить бинды
		unbind(0);

		return res;
	}
}