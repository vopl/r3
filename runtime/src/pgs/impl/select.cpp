#include "stdafx.h"
#include "select.hpp"
#include "pgs/meta/cluster.hpp"
#include "utils/ntoa.hpp"

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
		bool Select::compile(std::string &sql, const impl::Cluster_ptr &cluster)
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
				sql += " ";
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

			std::cout<<sql;
			assert(0);
			return false;
		}

		//////////////////////////////////////////////////////////////////////////
		void Select::mkWhats(std::deque<std::string> &res, SCompileState &state)
		{
			BOOST_FOREACH(Expression_ptr &expr, _whats)
			{
				expr->compile(res, state, ecmSelectWhat);
			}
		}

		//////////////////////////////////////////////////////////////////////////
		void Select::mkFrom(std::string &res, SCompileState &state)
		{
			assert(_from);

			res += state._cluster->tableName(_from->meta());
			res += " AS ";
			res += state._cluster->escapeName(_from->alias());

			state._aliases.insert(_from->alias());
		}

		//////////////////////////////////////////////////////////////////////////
		void Select::mkLinks(std::deque<std::string> &res, SCompileState &state)
		{
			BOOST_FOREACH(Link_ptr &link, _links)
			{
				//проверить наличие srcAlias во from или уже реализованых link
				state.checkAliasExistence(link->srcAlias(), true);

				//проверить отсутствие alias во from или уже реализованых link
				state.checkAliasExistence(link->alias(), false);

				std::string srcAlias = state._cluster->escapeName(link->srcAlias());
				std::string alias = state._cluster->escapeName(link->alias());
				std::string crossTable = state._cluster->tableName(link->meta()->_relation);
				char tmp[64];
				std::string crossAlias = state._cluster->escapeName(std::string("___cross_")+utils::_ntoa(state._nextCrossIndex++, tmp));
				std::string foreignTable = state._cluster->tableName(link->meta()->_anotherEnd->_category);
				
				std::string sql;
				sql += "LEFT OUTER JOIN ";
				sql += crossTable;
				sql += " AS ";
				sql += crossAlias;
				sql += " ON (";

				sql += srcAlias;
				sql += ".id";
				sql += "=";
				sql += crossAlias;
				sql += ".";
				sql += link->meta()->_isInput?"output_id":"input_id";



				sql += ") LEFT OUTER JOIN ";
				sql += foreignTable;
				sql += " AS ";
				sql += alias;

				sql += " ON(";

				sql += crossAlias;
				sql += ".";
				sql += link->meta()->_isInput?"input_id":"output_id";
				sql += "=";
				sql += alias;
				sql += ".id";


				sql += ")";


				res.push_back(sql);
				state._aliases.insert(link->alias());
			}
		}

		//////////////////////////////////////////////////////////////////////////
		void Select::mkWhere(std::string &res, SCompileState &state)
		{
			res = __FUNCTION__;
		}

		//////////////////////////////////////////////////////////////////////////
		void Select::mkOrders(std::deque<std::string> &res, SCompileState &state)
		{
			res.push_back(__FUNCTION__);
		}

		//////////////////////////////////////////////////////////////////////////
		void Select::mkLimit(std::string &res, SCompileState &state)
		{
			res = __FUNCTION__;
		}

		//////////////////////////////////////////////////////////////////////////
		void Select::mkOffset(std::string &res, SCompileState &state)
		{
			res = __FUNCTION__;
		}
	}
}
