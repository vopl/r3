#ifndef _PGS_IMPL_SELECT_HPP_
#define _PGS_IMPL_SELECT_HPP_

#include "categoryImpl.hpp"
#include "expressionImpl.hpp"
#include "fieldImpl.hpp"
#include "linkImpl.hpp"
#include "orderImpl.hpp"
#include "valueImpl.hpp"
#include "clusterImpl.hpp"
#include "statementImpl.hpp"

#include <deque>

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	class SelectImpl
	{
		std::deque<ExpressionImpl_ptr>	_whats;

		CategoryImpl_ptr				_from;
		std::deque<LinkImpl_ptr>		_links;

		ExpressionImpl_ptr				_where;
		ExpressionImpl_ptr				_limit;
		ExpressionImpl_ptr				_offset;

		std::deque<OrderImpl_ptr>		_orders;

	public:
		SelectImpl();

		void whats(ExpressionImpl_ptr);

		void from(CategoryImpl_ptr);
		void links(LinkImpl_ptr);
		void where(ExpressionImpl_ptr);

		void limit(ExpressionImpl_ptr);
		void offset(ExpressionImpl_ptr);
		void orders(OrderImpl_ptr);

	public:
		StatementImpl_ptr compile(const ClusterImpl_ptr &cluster);

	private:
		void mkWhats(std::deque<std::string> &res,	SCompileState &state);
		void mkFrom(std::deque<std::string> &res,	SCompileState &state);
		void mkLinks(std::deque<std::string> &res,	SCompileState &state);
		void mkWhere(std::deque<std::string> &res,	SCompileState &state);
		void mkOrders(std::deque<std::string> &res,	SCompileState &state);
		void mkLimit(std::deque<std::string> &res,	SCompileState &state);
		void mkOffset(std::deque<std::string> &res,	SCompileState &state);
	};
}

#endif
