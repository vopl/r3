#ifndef _PGS_IMPL_SELECT_HPP_
#define _PGS_IMPL_SELECT_HPP_

#include "category.hpp"
#include "expression.hpp"
#include "field.hpp"
#include "link.hpp"
#include "order.hpp"
#include "value.hpp"
#include "cluster.hpp"

#include <deque>

namespace pgs
{
	namespace impl
	{
		//////////////////////////////////////////////////////////////////////////
		class Select
		{
			std::deque<Expression_ptr>	_whats;

			Category_ptr				_from;
			std::deque<Link_ptr>		_links;

			Expression_ptr				_where;
			Expression_ptr				_limit;
			Expression_ptr				_offset;

			std::deque<Order_ptr>		_orders;

			//объект состояния компиляции
			struct SCompileState
			{
				impl::Cluster_ptr		_cluster;
				std::set<std::string>	_aliases;
				size_t					_nextCrossIndex;
				SCompileState();
			};

		public:
			Select();

			void whats(Expression_ptr);

			void from(Category_ptr);
			void links(Link_ptr);
			void where(Expression_ptr);

			void limit(Expression_ptr);
			void offset(Expression_ptr);
			void orders(Order_ptr);

		public:
			bool compile(std::string &sql, const impl::Cluster_ptr &cluster);

		private:
			void mkWhats(std::deque<std::string> &res,	SCompileState &state);
			void mkFrom(std::string &res,				SCompileState &state);
			void mkLinks(std::deque<std::string> &res,	SCompileState &state);
			void mkWhere(std::string &res,				SCompileState &state);
			void mkOrders(std::deque<std::string> &res,	SCompileState &state);
			void mkLimit(std::string &res,				SCompileState &state);
			void mkOffset(std::string &res,				SCompileState &state);

		private:
			bool checkAliasExistence(SCompileState &state, const std::string &alias, bool mustExists);
		};
	}
}

#endif
