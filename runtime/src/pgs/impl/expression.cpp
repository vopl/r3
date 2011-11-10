#include "stdafx.h"
#include "expression.hpp"
#include "access.hpp"
#include "sdHelpers.hpp"

namespace pgs
{
	namespace impl
	{
		//////////////////////////////////////////////////////////////////////////
		SCompileState::SCompileState()
			: _nextCrossIndex(0)
		{

		}
		//////////////////////////////////////////////////////////////////////////
		bool SCompileState::checkAliasExistence(const std::string &alias, bool mustExists)
		{
			bool exists = _aliases.end() != _aliases.find(alias);
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


		//////////////////////////////////////////////////////////////////////////
		Expression::Expression()
		{
		}
		//////////////////////////////////////////////////////////////////////////
		Expression::~Expression()
		{
		}

		//////////////////////////////////////////////////////////////////////////
		Expression_list::Expression_list()
		{

		}

		//////////////////////////////////////////////////////////////////////////
		Expression_list::~Expression_list()
		{

		}

		//////////////////////////////////////////////////////////////////////////
		void Expression_list::push(const pgs::Expression &a)
		{
			_list.push_back(Access<pgs::Expression>(a));
		}

		//////////////////////////////////////////////////////////////////////////
		void Expression_list::compile(std::deque<std::string> &res, SCompileState &state, ECompileMode ecm)
		{
			switch(ecm)
			{
			default:
				assert(0);
			}
		}

		//////////////////////////////////////////////////////////////////////////
		Expression_op0::Expression_op0(const char *name)
			: _name(name)
		{

		}

		//////////////////////////////////////////////////////////////////////////
		Expression_op0::~Expression_op0()
		{

		}

		//////////////////////////////////////////////////////////////////////////
		void Expression_op0::compile(std::deque<std::string> &res, SCompileState &state, ECompileMode ecm)
		{
			switch(ecm)
			{
			default:
				assert(0);
			}
		}

		//////////////////////////////////////////////////////////////////////////
		Expression_op1::Expression_op1(const char *name, const pgs::Expression &a, bool isPre)
			: _name(name)
			, _a(Access<pgs::Expression>(a))
			, _isPre(isPre)
		{
		}

		//////////////////////////////////////////////////////////////////////////
		Expression_op1::~Expression_op1()
		{
		}

		//////////////////////////////////////////////////////////////////////////
		void Expression_op1::compile(std::deque<std::string> &res, SCompileState &state, ECompileMode ecm)
		{
			switch(ecm)
			{
			default:
				assert(0);
			}
		}

		//////////////////////////////////////////////////////////////////////////
		Expression_op2::Expression_op2(const char *name, const pgs::Expression &a, const pgs::Expression &b)
			: _name(name)
			, _a(Access<pgs::Expression>(a))
			, _b(Access<pgs::Expression>(b))
		{
		}

		//////////////////////////////////////////////////////////////////////////
		Expression_op2::~Expression_op2()
		{
		}

		//////////////////////////////////////////////////////////////////////////
		void Expression_op2::compile(std::deque<std::string> &res, SCompileState &state, ECompileMode ecm)
		{
			switch(ecm)
			{
			case ecmSelectWhere:
				{
					res += "(";
					_a->compile(res, state, ecm);
					//res += ")";
					res += _name;
					//res += "(";
					_b->compile(res, state, ecm);
					res += ")";
				}
				break;
			default:
				assert(0);
			}
		}

		//////////////////////////////////////////////////////////////////////////
		Expression_op3::Expression_op3(const char *name1, const char *name2, const pgs::Expression &a, const pgs::Expression &b, const pgs::Expression &c)
		{
			assert(0);
		}

		//////////////////////////////////////////////////////////////////////////
		Expression_op3::~Expression_op3()
		{
			assert(0);
		}

		//////////////////////////////////////////////////////////////////////////
		void Expression_op3::compile(std::deque<std::string> &res, SCompileState &state, ECompileMode ecm)
		{
			switch(ecm)
			{
			default:
				assert(0);
			}
		}

		//////////////////////////////////////////////////////////////////////////
		Expression_func::Expression_func(const char *name)
			: _name(name)
		{
		}

		//////////////////////////////////////////////////////////////////////////
		Expression_func::~Expression_func()
		{
		}

		//////////////////////////////////////////////////////////////////////////
		void Expression_func::pushArg(const pgs::Expression &a)
		{
			_args.push_back(Access<pgs::Expression>(a));
		}

		//////////////////////////////////////////////////////////////////////////
		void Expression_func::compile(std::deque<std::string> &res, SCompileState &state, ECompileMode ecm)
		{
			switch(ecm)
			{
			default:
				assert(0);
			}
		}

		//////////////////////////////////////////////////////////////////////////
		Expression_casec::Expression_casec()
		{
			assert(0);
		}

		//////////////////////////////////////////////////////////////////////////
		Expression_casec::~Expression_casec()
		{
			assert(0);
		}

		//////////////////////////////////////////////////////////////////////////
		void Expression_casec::pushPair(const pgs::Expression &c, const pgs::Expression &r)
		{
			assert(0);
		}

		//////////////////////////////////////////////////////////////////////////
		void Expression_casec::pushElse(const pgs::Expression &e)
		{
			assert(0);
		}

		//////////////////////////////////////////////////////////////////////////
		void Expression_casec::compile(std::deque<std::string> &res, SCompileState &state, ECompileMode ecm)
		{
			switch(ecm)
			{
			default:
				assert(0);
			}
		}

		//////////////////////////////////////////////////////////////////////////
		Expression_casee::Expression_casee(const pgs::Expression &e)
		{
			assert(0);
		}

		//////////////////////////////////////////////////////////////////////////
		Expression_casee::~Expression_casee()
		{
			assert(0);
		}

		//////////////////////////////////////////////////////////////////////////
		void Expression_casee::pushPair(const pgs::Expression &v, const pgs::Expression &r)
		{
			assert(0);
		}

		//////////////////////////////////////////////////////////////////////////
		void Expression_casee::pushElse(const pgs::Expression &e)
		{
			assert(0);
		}

		//////////////////////////////////////////////////////////////////////////
		void Expression_casee::compile(std::deque<std::string> &res, SCompileState &state, ECompileMode ecm)
		{
			switch(ecm)
			{
			default:
				assert(0);
			}
		}

	}
}
