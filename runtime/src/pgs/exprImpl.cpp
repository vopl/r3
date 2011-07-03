#include "exprImpl.hpp"
#include "exprAccess.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	ExprImpl::ExprImpl()
	{
	}

// 	//////////////////////////////////////////////////////////////////////////
// 	void ExprImpl::mkSql(std::string &result)
// 	{
// 		assert(0);
// 		result += "[[[ ExprImpl::mkSql ]]]";
// 	}

	//////////////////////////////////////////////////////////////////////////
	ExprImpl_list::ExprImpl_list()
	{

	}

	//////////////////////////////////////////////////////////////////////////
	ExprImpl_list::~ExprImpl_list()
	{

	}

	//////////////////////////////////////////////////////////////////////////
	void ExprImpl_list::push(const Expr &a)
	{
		_list.push_back(ExprAccess(a));
	}

	//////////////////////////////////////////////////////////////////////////
	void ExprImpl_list::reg(StatementImpl *s)
	{
		for(size_t i(0); i<_list.size(); i++)
		{
			_list[i]->reg(s);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ExprImpl_list::mkSql(std::string &result)
	{
		for(size_t i(0); i<_list.size(); i++)
		{
			if(i)
			{
				result += ",";
			}
			_list[i]->mkSql(result);
		}
	}


	//////////////////////////////////////////////////////////////////////////
	ExprImpl_op0::ExprImpl_op0(const char *name)
		: _name(name)
	{

	}

	//////////////////////////////////////////////////////////////////////////
	ExprImpl_op0::~ExprImpl_op0()
	{

	}

	//////////////////////////////////////////////////////////////////////////
	void ExprImpl_op0::reg(StatementImpl *s)
	{

	}

	//////////////////////////////////////////////////////////////////////////
	void ExprImpl_op0::mkSql(std::string &result)
	{
		result += _name;
	}


	//////////////////////////////////////////////////////////////////////////
	ExprImpl_op1::ExprImpl_op1(const char *name, const Expr &a, bool isPre)
		: _name(name)
		, _a(ExprAccess(a))
		, _isPre(isPre)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	ExprImpl_op1::~ExprImpl_op1()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	void ExprImpl_op1::reg(StatementImpl *s)
	{
		_a->reg(s);
	}

	//////////////////////////////////////////////////////////////////////////
	void ExprImpl_op1::mkSql(std::string &result)
	{
		assert(!__FUNCTION__);
	}

	//////////////////////////////////////////////////////////////////////////
	ExprImpl_op2::ExprImpl_op2(const char *name, const Expr &a, const Expr &b)
		: _name(name)
		, _a(ExprAccess(a))
		, _b(ExprAccess(b))
	{
	}

	//////////////////////////////////////////////////////////////////////////
	ExprImpl_op2::~ExprImpl_op2()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	void ExprImpl_op2::reg(StatementImpl *s)
	{
		_a->reg(s);
		_b->reg(s);
	}

	//////////////////////////////////////////////////////////////////////////
	void ExprImpl_op2::mkSql(std::string &result)
	{
		result += "(";
		_a->mkSql(result);
		result += _name;
		_b->mkSql(result);
		result += ")";
	}

	//////////////////////////////////////////////////////////////////////////
	ExprImpl_op3::ExprImpl_op3(const char *name1, const char *name2, const Expr &a, const Expr &b, const Expr &c)
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	ExprImpl_op3::~ExprImpl_op3()
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	void ExprImpl_op3::reg(StatementImpl *s)
	{
// 		_a->reg(s);
// 		_b->reg(s);
// 		_c->reg(s);
	}

	//////////////////////////////////////////////////////////////////////////
	void ExprImpl_op3::mkSql(std::string &result)
	{
		assert(!__FUNCTION__);
	}

	//////////////////////////////////////////////////////////////////////////
	ExprImpl_func::ExprImpl_func(const char *name)
		: _name(name)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	ExprImpl_func::~ExprImpl_func()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	void ExprImpl_func::pushArg(const Expr &a)
	{
		_args.push_back(ExprAccess(a));
	}

	//////////////////////////////////////////////////////////////////////////
	void ExprImpl_func::reg(StatementImpl *s)
	{
		for(size_t i(0); i<_args.size(); i++)
		{
			_args[i]->reg(s);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ExprImpl_func::mkSql(std::string &result)
	{
		result += _name;
		result += "(";
		for(size_t i(0); i<_args.size(); i++)
		{
			if(i)
			{
				result += ",";
			}
			_args[i]->mkSql(result);
		}
		result += ")";
	}

	//////////////////////////////////////////////////////////////////////////
	ExprImpl_casec::ExprImpl_casec()
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	ExprImpl_casec::~ExprImpl_casec()
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	void ExprImpl_casec::pushPair(const Expr &c, const Expr &r)
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	void ExprImpl_casec::pushElse(const Expr &e)
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	void ExprImpl_casec::reg(StatementImpl *s)
	{
		assert(0);
		//_args[i]->reg(s);
	}

	//////////////////////////////////////////////////////////////////////////
	void ExprImpl_casec::mkSql(std::string &result)
	{
		assert(!__FUNCTION__);
	}

	//////////////////////////////////////////////////////////////////////////
	ExprImpl_casee::ExprImpl_casee(const Expr &e)
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	ExprImpl_casee::~ExprImpl_casee()
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	void ExprImpl_casee::pushPair(const Expr &v, const Expr &r)
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	void ExprImpl_casee::pushElse(const Expr &e)
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	void ExprImpl_casee::reg(StatementImpl *s)
	{
		//_args[i]->reg(s);
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	void ExprImpl_casee::mkSql(std::string &result)
	{
		assert(!__FUNCTION__);
	}

}
