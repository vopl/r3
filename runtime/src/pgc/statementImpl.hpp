#ifndef _PGC_STATEMENTIMPL_HPP_
#define _PGC_STATEMENTIMPL_HPP_

#include <deque>
#include <libpq-fe.h>
#include "resultImpl.hpp"

namespace pgc
{
	class ConnectionImpl;
	typedef boost::shared_ptr<ConnectionImpl> ConnectionImplPtr;

	//////////////////////////////////////////////////////////////////////////
	class StatementImpl
		: public boost::enable_shared_from_this<StatementImpl>
	{
		ConnectionImplPtr _con;

		bool _once;
		std::string _sql;

		//std::deque<CppConstValue> _binds;
		std::vector<Oid>	_bindTyp;
		std::vector<char *>	_bindVal;
		std::vector<int>	_bindLen;
		std::vector<int>	_bindFmt;
		std::vector<bool>	_bindOwn;

		void ensureBindIndex(size_t idx);
	public:
		StatementImpl(ConnectionImplPtr con, bool once);
		~StatementImpl();

		void sql(const char *csz);
		void bind(int typCpp, void const *valCpp, size_t idx);
		void unbind(size_t idx);
		ResultImplPtr exec();
	};

	typedef boost::shared_ptr<StatementImpl> StatementImplPtr;
}
#endif
