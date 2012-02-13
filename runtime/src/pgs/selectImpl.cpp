#include "pch.hpp"
#include "selectImpl.hpp"
#include "pgs/meta/cluster.hpp"
#include "sdHelpers.hpp"
#include "utils/implAccess.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	SelectImpl::SelectImpl()
	{

	}

	//////////////////////////////////////////////////////////////////////////
	void SelectImpl::whats(ExpressionImplPtr e)
	{
		_whats.push_back(e);
	}

	//////////////////////////////////////////////////////////////////////////
	void SelectImpl::from(CategoryImplPtr c)
	{
		_from = c;
	}

	//////////////////////////////////////////////////////////////////////////
	void SelectImpl::links(LinkImplPtr l)
	{
		_links.push_back(l);
	}

	//////////////////////////////////////////////////////////////////////////
	void SelectImpl::where(ExpressionImplPtr e)
	{
		//РїРµСЂРµР±СЂР°С‚СЊ РґРµСЂРµРІРѕ РІС‹СЂР°Р¶РµРЅРёСЏ, РїСЂРѕРІРµСЂРёС‚СЊ РЅР°Р»РёС‡РёРµ РІСЃРµС… РїРѕР»РµР№, СЃРѕР±СЂР°С‚СЊ РІСЃРµ РїРµСЂРµРјРµРЅРЅС‹Рµ
		_where = e;
	}

	//////////////////////////////////////////////////////////////////////////
	void SelectImpl::limit(ExpressionImplPtr e)
	{
		_limit = e;
	}

	//////////////////////////////////////////////////////////////////////////
	void SelectImpl::offset(ExpressionImplPtr e)
	{
		_offset = e;
	}

	//////////////////////////////////////////////////////////////////////////
	void SelectImpl::orders(OrderImplPtr o)
	{
		_orders.push_back(o);
	}

	//////////////////////////////////////////////////////////////////////////
	StatementImplPtr SelectImpl::compile(const ClusterImplPtr &cluster)
	{
		std::string sql;
		//РІС‹РґРµР»РёС‚СЊ Р·РЅР°С‡РµРЅРёСЏ РґР»СЏ bind
		//РІС‹РґРµР»РёС‚СЊ РїРѕР»СЏ РґР»СЏ fetch
		//СЃРѕСЃС‚Р°РІРёС‚СЊ sql
		
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

		SCompileState state;
		state._cluster = cluster;

		mkFrom(from, state);
		mkLinks(links, state);

		mkWhats(whats, state);

		mkWhere(where, state);

		mkOrders(orders, state);

		mkLimit(limit, state);
		mkOffset(offset, state);

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

		//////////////////////////////////////////////////////////////////////////
		StatementImplPtr stm(new StatementImpl(
			sql,
			cluster, 
			state._bindName2idx));

		//state._fetchName2idx

		return stm;
	}

	//////////////////////////////////////////////////////////////////////////
	void SelectImpl::mkWhats(std::deque<std::string> &res, SCompileState &state)
	{
		bool first = true;
		BOOST_FOREACH(ExpressionImplPtr &expr, _whats)
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
	void SelectImpl::mkFrom(std::deque<std::string> &res, SCompileState &state)
	{
		assert(_from);
		if(_from)
		{
			_from->compile(res, state, ecmSelectFrom);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void SelectImpl::mkLinks(std::deque<std::string> &res, SCompileState &state)
	{
		BOOST_FOREACH(LinkImplPtr &link, _links)
		{
			res += " ";
			link->compile(res, state, ecmSelectLink);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void SelectImpl::mkWhere(std::deque<std::string> &res, SCompileState &state)
	{
		if(_where)
		{
			_where->compile(res, state, ecmSelectWhere);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void SelectImpl::mkOrders(std::deque<std::string> &res, SCompileState &state)
	{
		bool first = true;
		BOOST_FOREACH(OrderImplPtr &order, _orders)
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
	void SelectImpl::mkLimit(std::deque<std::string> &res, SCompileState &state)
	{
		if(_limit)
		{
			_limit->compile(res, state, ecmSelectLimit);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void SelectImpl::mkOffset(std::deque<std::string> &res, SCompileState &state)
	{
		if(_offset)
		{
			_offset->compile(res, state, ecmSelectOffset);
		}
	}
}
