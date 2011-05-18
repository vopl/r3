#ifndef _PGC_STATEMENTIMPL_HPP_
#define _PGC_STATEMENTIMPL_HPP_

#include <deque>
#include <libpq-fe.h>
#include "resultImpl.hpp"

namespace pgc
{
	class ConnectionImpl;
	typedef boost::shared_ptr<ConnectionImpl> ConnectionImplPtr;
//	typedef boost::weak_ptr<ConnectionImpl> ConnectionImplWtr;

	struct CppConstValue
	{
		int _typIdx;
		void const * _data;
		CppConstValue()
			: _typIdx(0)
			, _data(0)
		{
		}
		CppConstValue(int typIdx, void const *data)
			: _typIdx(typIdx)
			, _data(data)
		{
		}
	};
	//////////////////////////////////////////////////////////////////////////
	class StatementImpl
		: public boost::enable_shared_from_this<StatementImpl>
	{
		ConnectionImplPtr _con;

		bool _once;
		std::string _sql;

		std::deque<CppConstValue> _binds;
	public:
		StatementImpl(ConnectionImplPtr con, bool once);
		~StatementImpl();

		void sql(const char *csz);
		void bind(int typIdx, void const *data, size_t idx);
		ResultImplPtr exec();
	};

	typedef boost::shared_ptr<StatementImpl> StatementImplPtr;
}
#endif
