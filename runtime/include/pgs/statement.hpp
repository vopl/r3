#ifndef _PGS_STATEMENT_HPP_
#define _PGS_STATEMENT_HPP_

#include "pgs/result.hpp"
#include <boost/shared_ptr.hpp>

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	namespace impl
	{
		class Statement;
		typedef boost::shared_ptr<Statement> Statement_ptr;
	}

	//////////////////////////////////////////////////////////////////////////
	class Statement
		: public pgc::Statement
	{
	protected:
		typedef impl::Statement_ptr Impl_ptr;

		friend class Select;
		Statement(Impl_ptr impl);
	public:

// 		template <class T> Statement &bind(T const &v, const std::string &name);
// 		template <class T> Statement &bind(T const *pv, const std::string &name);
// 		Statement &unbind(const std::string &name);

		Result exec();
	};

}
#endif
