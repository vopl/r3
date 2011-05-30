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
	protected:
		ConnectionImplPtr _con;

		std::string _sql;

		//std::deque<CppConstValue> _binds;
		std::vector<Oid>	_bindTyp;
		std::vector<char *>	_bindVal;
		std::vector<int>	_bindLen;
		std::vector<int>	_bindFmt;
		std::vector<bool>	_bindOwn;
	public:
		StatementImpl(ConnectionImplPtr con);
		~StatementImpl();

		void sql(const char *sql);
		void sql(const std::string &sql);

		bool empty() const;

		virtual void bind(int typCpp, void const *valCpp, size_t idx);
		virtual void unbind(size_t idx);
		virtual ResultImplPtr exec();

	protected:
		bool bindFiller(
			int typCpp, void const *valCpp, 
			Oid	&_bindTyp,
			char *&_bindVal,
			int &_bindLen,
			int &_bindFmt,
			bool &_bindOwn);

	};

	typedef boost::shared_ptr<StatementImpl> StatementImplPtr;
}
#endif
