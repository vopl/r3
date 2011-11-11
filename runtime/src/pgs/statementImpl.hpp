#ifndef _PGS_IMPL_STATEMENT_HPP_
#define _PGS_IMPL_STATEMENT_HPP_

#include "../pgc/statementPrepImpl.hpp"
#include "resultImpl.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	class StatementImpl
		: public pgc::StatementPrepImpl
	{
		typedef std::map<std::string, size_t>	TMName2idx;
		TMName2idx _name2idx;

	private:
		size_t name2idx(const char *name);

	public:
		StatementImpl(pgc::ConnectionImplPtr con, const TMName2idx &name2idx);

		void bind(int typCpp, void const *valCpp, const char *name);
		void unbind(const char *name);

	};
	typedef boost::shared_ptr<StatementImpl> StatementImpl_ptr;
}

#endif
