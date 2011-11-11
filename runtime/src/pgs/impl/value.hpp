#ifndef _PGS_IMPL_VALUE_HPP_
#define _PGS_IMPL_VALUE_HPP_

#include "expression.hpp"
#include "pgs/value.hpp"
#include "pgc/blob.hpp"

namespace pgs
{
	namespace impl
	{
		//////////////////////////////////////////////////////////////////////////
		class Value
			: public impl::Expression
		{
			std::string				_alias;

			Value(const Value &);
			void operator=(const Value &);

		public:
			Value(const std::string &alias);

			const std::string &alias() const;

			virtual void compile(std::deque<std::string> &res, SCompileState &state, ECompileMode ecm);
		};
		typedef boost::shared_ptr<Value> Value_ptr;
	}
}
#endif
