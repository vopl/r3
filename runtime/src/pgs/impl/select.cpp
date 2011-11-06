#include "stdafx.h"
#include "select.hpp"
#include "pgs/meta/cluster.hpp"

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
			_what.push_back(e);
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
		bool Select::compile(std::string &sql)
		{
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
			std::deque<std::string> whats;
			std::string from;
			std::deque<std::string> links;
			std::string where;
			std::deque<std::string> orders;
			std::string limit;
			std::string offset;

			mkWhats(whats);
			mkFrom(from);
			mkLinks(links);
			mkWhere(where);
			mkOrders(orders);
			mkLimit(limit);
			mkOffset(offset);


			//////////////////////////////////////////////////////////////////////////
			if(whats.empty())
			{
				sql += "SELECT *";
			}
			else
			{
				sql += "SELECT ";
				bool first = true;
				BOOST_FOREACH(std::string &what, whats)
				{
					if(first)
					{
						first = false;
					}
					else
					{
						sql += ", ";
					}
					sql += what;
				}
			}

			if(from.empty())
			{

			}
			else
			{
				sql += " FROM ";
				sql += from;
			}

			BOOST_FOREACH(std::string &link, links)
			{
				sql += ", ";
				sql += link;
			}

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
				bool first = true;
				BOOST_FOREACH(std::string &order, orders)
				{
					if(first)
					{
						first = false;
					}
					else
					{
						sql += ", ";
					}
					sql += order;
				}
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

			assert(0);
			return false;
		}

		//////////////////////////////////////////////////////////////////////////
		void Select::mkWhats(std::deque<std::string> &res)
		{
			res.push_back(__FUNCTION__);
		}

		//////////////////////////////////////////////////////////////////////////
		void Select::mkFrom(std::string &res)
		{
			res = __FUNCTION__;
		}

		//////////////////////////////////////////////////////////////////////////
		void Select::mkLinks(std::deque<std::string> &res)
		{
			res.push_back(__FUNCTION__);
		}

		//////////////////////////////////////////////////////////////////////////
		void Select::mkWhere(std::string &res)
		{
			res = __FUNCTION__;
		}

		//////////////////////////////////////////////////////////////////////////
		void Select::mkOrders(std::deque<std::string> &res)
		{
			res.push_back(__FUNCTION__);
		}

		//////////////////////////////////////////////////////////////////////////
		void Select::mkLimit(std::string &res)
		{
			res = __FUNCTION__;
		}

		//////////////////////////////////////////////////////////////////////////
		void Select::mkOffset(std::string &res)
		{
			res = __FUNCTION__;
		}


	}
}
