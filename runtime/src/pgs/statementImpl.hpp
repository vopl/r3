#ifndef _PGS_STATEMENTIMPL_HPP_
#define _PGS_STATEMENTIMPL_HPP_

#include "pgc/statementImpl.hpp"
#include "resultImpl.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	class StatementImpl
		: public pgc::StatementImpl
	{
		typedef std::map<std::string, size_t>	TMName2idx;
		TMName2idx _bindName2idx;

		pgs::ClusterImplPtr _cluster;

	public:
		size_t bindName2idx(const char *name);

	public:
		StatementImpl(	const std::string &sql,
						pgs::ClusterImplPtr cluster, 
						const TMName2idx &bindName2idx);

		//bool bind(int typCpp, void const *valCpp, const char *name);

		//void unbind(const char *name);

	};
	typedef boost::shared_ptr<StatementImpl> StatementImplPtr;
}

#endif
