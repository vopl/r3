#ifndef _PGS_SELECTIMPL_HPP_
#define _PGS_SELECTIMPL_HPP_

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
		std::deque<ExpressionImplPtr>	_whats;

		CategoryImplPtr				_from;
		std::deque<LinkImplPtr>		_links;

		ExpressionImplPtr				_where;
		ExpressionImplPtr				_limit;
		ExpressionImplPtr				_offset;

		std::deque<OrderImplPtr>		_orders;

	public:
		SelectImpl();

		void whats(ExpressionImplPtr);

		void from(CategoryImplPtr);
		void links(LinkImplPtr);
		void where(ExpressionImplPtr);

		void limit(ExpressionImplPtr);
		void offset(ExpressionImplPtr);
		void orders(OrderImplPtr);

	public:
		StatementImplPtr compile(const ClusterImplPtr &cluster);

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
