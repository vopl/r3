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
		TMName2idx _bindName2idx;
		TMName2idx _fetchName2idx;

		pgs::ClusterImpl_ptr _cluster;

	public:
		size_t bindName2idx(const char *name);
		bool fldIndex(size_t &res, const std::string &name);
		bool fldIndex(size_t &res, const FieldImpl_ptr &fld);
		bool fldIndices(std::deque<size_t> &res, const CategoryImpl_ptr &cat);

	public:
		StatementImpl(
			pgs::ClusterImpl_ptr cluster, 
			const TMName2idx &bindName2idx,
			const TMName2idx &fetchName2idx);

		bool bind(int typCpp, void const *valCpp, const char *name);

		void unbind(const char *name);

	};
	typedef boost::shared_ptr<StatementImpl> StatementImpl_ptr;
}

#endif
