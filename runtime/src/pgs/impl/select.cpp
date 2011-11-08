#include "stdafx.h"
#include "select.hpp"
#include "pgs/meta/cluster.hpp"
#include "utils/ntoa.hpp"

namespace pgs
{
	namespace impl
	{
		//////////////////////////////////////////////////////////////////////////
		Select::SCompileState::SCompileState()
			: _nextCrossIndex(0)
		{

		}

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
				//НЕ ТАК
				/*
					перебрать выражение, в нем пораскрывать категории в наборы полей
				*/
				Category_ptr cat = boost::dynamic_pointer_cast<Category>(expr);

				if(cat)
				{
					//проверить наличие alias во from или links
					checkAliasExistence(state, cat->alias(), true);

					std::string categoryAlias = state._cluster->escapeName(cat->alias());

					std::string sql;
					//tableoid
					sql += categoryAlias;
					sql += ".tableoid";
					// TRATATA тут фиксировать информацию для феча

					//перебрать все поля
					BOOST_FOREACH(meta::FieldCPtr mf, cat->meta()->_fields)
					{
						sql += ", ";
						sql += categoryAlias;
						sql += ".";
						sql += state._cluster->escapeName(mf->_name);
						// TRATATA тут фиксировать информацию для феча
					}

					res.push_back(sql);
					continue;
				}

				Field_ptr fld = boost::dynamic_pointer_cast<Field>(expr);
				if(fld)
				{
					checkAliasExistence(state, fld->srcAlias(), true);
					std::string categoryAlias = state._cluster->escapeName(fld->srcAlias());

					std::string sql;

					sql += categoryAlias;
					sql += ".";
					sql += state._cluster->escapeName(fld->meta()->_name);

					res.push_back(sql);
					continue;
				}

				assert(!"'what' must be category or field");
				throw "'what' must be category or field";
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
				checkAliasExistence(state, link->srcAlias(), true);

				//проверить отсутствие alias во from или уже реализованых link
				checkAliasExistence(state, link->alias(), false);

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

		//////////////////////////////////////////////////////////////////////////
		bool Select::checkAliasExistence(SCompileState &state, const std::string &alias, bool mustExists)
		{
			bool exists = state._aliases.end() != state._aliases.find(alias);
			if(mustExists && !exists)
			{
				assert(!"alias must be present");
				throw "alias must be present";
				return false;
			}
			if(!mustExists && exists)
			{
				assert(!"alias must be absent");
				throw "alias must be absent";
				return false;
			}

			return true;
		}


	}
}
