#ifndef _PGS_IMPL_STATEMENT_HPP_
#define _PGS_IMPL_STATEMENT_HPP_

#include "pgc/statement.hpp"
#include "result.hpp"

namespace pgs
{
	namespace impl
	{
		//////////////////////////////////////////////////////////////////////////
		class Statement
		{
			pgc::Statement _pg;
			typedef std::map<std::string, size_t>	TMName2idx;
			TMName2idx _name2idx;

		private:
			size_t name2idx(const std::string &name);

		public:
			Statement(pgc::Statement pg, const TMName2idx &name2idx);

			void bind(int typCpp, void const *valCpp, size_t idx);
			void bind(int typCpp, void const *valCpp, const std::string &name);
			void unbind(size_t idx=0);
			void unbind(const std::string &name);
			Result_ptr exec();

		};
		typedef boost::shared_ptr<Statement> Statement_ptr;
	}
}

#endif
