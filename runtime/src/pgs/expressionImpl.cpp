#include "stdafx.h"
#include "expressionImpl.hpp"
#include "implAccess.hpp"
#include "sdHelpers.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	SCompileState::SCompileState()
		: _nextCrossIndex(0)
		, _nextWhatColumnIndex(0)
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
	ExpressionImpl::ExpressionImpl()
	{
	}
	//////////////////////////////////////////////////////////////////////////
	ExpressionImpl::~ExpressionImpl()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	ExpressionImpl_list::ExpressionImpl_list()
	{

	}

	//////////////////////////////////////////////////////////////////////////
	ExpressionImpl_list::~ExpressionImpl_list()
	{

	}

	//////////////////////////////////////////////////////////////////////////
	void ExpressionImpl_list::push(const Expression &a)
	{
		_list.push_back(ImplAccess<pgs::Expression>(a));
	}

	//////////////////////////////////////////////////////////////////////////
	void ExpressionImpl_list::compile(std::deque<std::string> &res, SCompileState &state, ECompileMode ecm)
	{
		switch(ecm)
		{
		default:
			assert(0);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	ExpressionImpl_op0::ExpressionImpl_op0(const char *name)
		: _name(name)
	{

	}

	//////////////////////////////////////////////////////////////////////////
	ExpressionImpl_op0::~ExpressionImpl_op0()
	{

	}

	//////////////////////////////////////////////////////////////////////////
	void ExpressionImpl_op0::compile(std::deque<std::string> &res, SCompileState &state, ECompileMode ecm)
	{
		switch(ecm)
		{
		default:
			assert(0);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	ExpressionImpl_op1::ExpressionImpl_op1(const char *name, const Expression &a, bool isPre)
		: _name(name)
		, _a(ImplAccess<pgs::Expression>(a))
		, _isPre(isPre)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	ExpressionImpl_op1::~ExpressionImpl_op1()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	void ExpressionImpl_op1::compile(std::deque<std::string> &res, SCompileState &state, ECompileMode ecm)
	{
		switch(ecm)
		{
		default:
			assert(0);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	ExpressionImpl_op2::ExpressionImpl_op2(const char *name, const Expression &a, const Expression &b)
		: _name(name)
		, _a(ImplAccess<pgs::Expression>(a))
		, _b(ImplAccess<pgs::Expression>(b))
	{
	}

	//////////////////////////////////////////////////////////////////////////
	ExpressionImpl_op2::~ExpressionImpl_op2()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	void ExpressionImpl_op2::compile(std::deque<std::string> &res, SCompileState &state, ECompileMode ecm)
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
	ExpressionImpl_op3::ExpressionImpl_op3(const char *name1, const char *name2, const Expression &a, const Expression &b, const Expression &c)
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	ExpressionImpl_op3::~ExpressionImpl_op3()
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	void ExpressionImpl_op3::compile(std::deque<std::string> &res, SCompileState &state, ECompileMode ecm)
	{
		switch(ecm)
		{
		default:
			assert(0);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	ExpressionImpl_func::ExpressionImpl_func(const char *name)
		: _name(name)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	ExpressionImpl_func::~ExpressionImpl_func()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	void ExpressionImpl_func::pushArg(const Expression &a)
	{
		_args.push_back(ImplAccess<Expression>(a));
	}

	//////////////////////////////////////////////////////////////////////////
	void ExpressionImpl_func::compile(std::deque<std::string> &res, SCompileState &state, ECompileMode ecm)
	{
		switch(ecm)
		{
		default:
			assert(0);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	ExpressionImpl_casec::ExpressionImpl_casec()
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	ExpressionImpl_casec::~ExpressionImpl_casec()
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	void ExpressionImpl_casec::pushPair(const Expression &c, const Expression &r)
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	void ExpressionImpl_casec::pushElse(const Expression &e)
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	void ExpressionImpl_casec::compile(std::deque<std::string> &res, SCompileState &state, ECompileMode ecm)
	{
		switch(ecm)
		{
		default:
			assert(0);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	ExpressionImpl_casee::ExpressionImpl_casee(const Expression &e)
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	ExpressionImpl_casee::~ExpressionImpl_casee()
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	void ExpressionImpl_casee::pushPair(const Expression &v, const Expression &r)
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	void ExpressionImpl_casee::pushElse(const Expression &e)
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	void ExpressionImpl_casee::compile(std::deque<std::string> &res, SCompileState &state, ECompileMode ecm)
	{
		switch(ecm)
		{
		default:
			assert(0);
		}
	}
}
