#ifndef _PGC_STATEMENTPREPIMPL_HPP_
#define _PGC_STATEMENTPREPIMPL_HPP_

#include "statementImpl.hpp"

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	class StatementPrepImpl
		: public StatementImpl
	{
		std::string _id;

	public:
		StatementPrepImpl(ConnectionImplPtr con);
		~StatementPrepImpl();

		void bind(int typCpp, void const *valCpp, size_t idx);
		void unbind(size_t idx);
		ResultImplPtr exec();

	private:
		ResultImplPtr prepare();
		void unprepare();
	};

	typedef boost::shared_ptr<StatementPrepImpl> StatementPrepImplPtr;
}
#endif
