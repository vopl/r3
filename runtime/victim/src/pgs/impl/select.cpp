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
			//��������� ������ ���������, ��������� ������� ���� �����, ������� ��� ����������
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
			//�������� �������� ��� bind
			//�������� ���� ��� fetch
			//��������� sql
			
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

			assert(0);
			return false;
		}
	}
}
