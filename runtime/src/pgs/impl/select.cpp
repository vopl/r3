#include "stdafx.h"
#include "select.hpp"
#include "pgs/meta/cluster.hpp"
#include "sdHelpers.hpp"

namespace pgs
{
	namespace impl
	{
		//////////////////////////////////////////////////////////////////////////
		Select::Select()
		{

		}

		//////////////////////////////////////////////////////////////////////////
		void Select::whats(Expression_ptr e)
		{
			_whats.push_back(e);
		}

		//////////////////////////////////////////////////////////////////////////
		void Select::from(Category_ptr c)
		{
			_from = c;
		}

		//////////////////////////////////////////////////////////////////////////
		void Select::links(Link_ptr l)
		{
			_links.push_back(l);
		}

		//////////////////////////////////////////////////////////////////////////
		void Select::where(Expression_ptr e)
		{
			//перебрать дерево выражения, проверить наличие всех полей, собрать все переменные
			_where = e;
		}

		//////////////////////////////////////////////////////////////////////////
		void Select::limit(Expression_ptr e)
		{
			_limit = e;
		}

		//////////////////////////////////////////////////////////////////////////
		void Select::offset(Expression_ptr e)
		{
			_offset = e;
		}

		//////////////////////////////////////////////////////////////////////////
		void Select::orders(Order_ptr o)
		{
			_orders.push_back(o);
		}

		//////////////////////////////////////////////////////////////////////////
		Statement_ptr Select::compile(const impl::Cluster_ptr &cluster)
		{
			std::string sql;
			//выделить значения для bind
			//выделить поля для fetch
			//составить sql
			
			/*
				SELECT
					what
				FROM
					from
				[LEFT JOIN ... links]
				WHERE
					where
				ORDER BY
					[orders]
				LIMIT
					limit
				OFFSET
					offset
			*/
			std::deque<std::string>	whats;
			std::deque<std::string>	from;
			std::deque<std::string>	links;
			std::deque<std::string>	where;
			std::deque<std::string>	orders;
			std::deque<std::string>	limit;
			std::deque<std::string>	offset;

			{
				SCompileState state;
				state._cluster = cluster;

				mkFrom(from, state);
				mkLinks(links, state);

				mkWhats(whats, state);

				mkWhere(where, state);

				mkOrders(orders, state);

				mkLimit(limit, state);
				mkOffset(offset, state);
			}


			//////////////////////////////////////////////////////////////////////////
			sql += "SELECT ";
			sql += whats;

			sql += " FROM ";
			sql += from;

			sql += links;

			if(where.empty())
			{
				//
			}
			else
			{
				sql += " WHERE ";
				sql += where;
			}

			if(orders.empty())
			{

			}
			else
			{
				sql += " ORDER BY ";
				sql += orders;
			}

			if(!limit.empty())
			{
				sql += " LIMIT ";
				sql += limit;
			}

			if(!offset.empty())
			{
				sql += " OFFSET ";
				sql += offset;
			}

			std::cout<<sql<<std::endl;
			assert(0);
			return Statement_ptr();
		}

		//////////////////////////////////////////////////////////////////////////
		void Select::mkWhats(std::deque<std::string> &res, SCompileState &state)
		{
			bool first = true;
			BOOST_FOREACH(Expression_ptr &expr, _whats)
			{
				if(first)
				{
					first = false;
				}
				else
				{
					res += ", ";
				}

				expr->compile(res, state, ecmSelectWhat);
			}

			if(first)
			{
				res += "*";
			}
		}

		//////////////////////////////////////////////////////////////////////////
		void Select::mkFrom(std::deque<std::string> &res, SCompileState &state)
		{
			assert(_from);
			if(_from)
			{
				_from->compile(res, state, ecmSelectFrom);
			}
		}

		//////////////////////////////////////////////////////////////////////////
		void Select::mkLinks(std::deque<std::string> &res, SCompileState &state)
		{
			BOOST_FOREACH(Link_ptr &link, _links)
			{
				res += " ";
				link->compile(res, state, ecmSelectLink);
			}
		}

		//////////////////////////////////////////////////////////////////////////
		void Select::mkWhere(std::deque<std::string> &res, SCompileState &state)
		{
			if(_where)
			{
				_where->compile(res, state, ecmSelectWhere);
			}
		}

		//////////////////////////////////////////////////////////////////////////
		void Select::mkOrders(std::deque<std::string> &res, SCompileState &state)
		{
			bool first = true;
			BOOST_FOREACH(Order_ptr &order, _orders)
			{
				if(first)
				{
					first = false;
				}
				else
				{
					res += ", ";
				}
				order->compile(res, state, ecmSelectOrder);
			}
		}

		//////////////////////////////////////////////////////////////////////////
		void Select::mkLimit(std::deque<std::string> &res, SCompileState &state)
		{
			if(_limit)
			{
				_limit->compile(res, state, ecmSelectLimit);
			}
		}

		//////////////////////////////////////////////////////////////////////////
		void Select::mkOffset(std::deque<std::string> &res, SCompileState &state)
		{
			if(_offset)
			{
				_offset->compile(res, state, ecmSelectOffset);
			}
		}
	}
}
