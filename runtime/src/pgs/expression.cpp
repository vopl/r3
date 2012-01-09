#include "pch.h"
#include "pgs/expression.hpp"
#include "expressionImpl.hpp"
#include "implAccess.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	Expression op1_pre(const char *name, const Expression &a)
	{
		return ImplAccess<Expression>(ExpressionImplPtr(new ExpressionImpl_op1(name, a, true)));
	}
	//////////////////////////////////////////////////////////////////////////
	Expression op1_post(const char *name, const Expression &a)
	{
		return ImplAccess<Expression>(ExpressionImplPtr(new ExpressionImpl_op1(name, a, false)));
	}
	//////////////////////////////////////////////////////////////////////////
	Expression op2(const char *name, const Expression &a, const Expression &b)
	{
		return ImplAccess<Expression>(ExpressionImplPtr(new ExpressionImpl_op2(name, a, b)));
	}
	//////////////////////////////////////////////////////////////////////////
	Expression op3(const char *name1, const char *name2, const Expression &a, const Expression &b, const Expression &c)
	{
		return ImplAccess<Expression>(ExpressionImplPtr(new ExpressionImpl_op3(name1, name2, a, b, c)));
	}


	//////////////////////////////////////////////////////////////////////////
	Expression and_(const Expression &a, const Expression &b)
	{
		return op2(" AND ", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expression or_(const Expression &a, const Expression &b)
	{
		return op2(" OR ", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expression not_(const Expression &a)
	{
		return op1_pre("NOT ", a);
	}

	//////////////////////////////////////////////////////////////////////////
	Expression lt(const Expression &a, const Expression &b)
	{
		return op2("<", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expression gt(const Expression &a, const Expression &b)
	{
		return op2(">", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expression le(const Expression &a, const Expression &b)
	{
		return op2("<=", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expression ge(const Expression &a, const Expression &b)
	{
		return op2(">=", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expression eq(const Expression &a, const Expression &b)
	{
		return op2("=", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expression ne(const Expression &a, const Expression &b)
	{
		return op2("<>", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expression between(const Expression &a, const Expression &b, const Expression &c)
	{
		return op3("BETWEEN ", " AND ", a, b, c);
	}

	//////////////////////////////////////////////////////////////////////////
	Expression isNull(const Expression &a)
	{
		return op1_post(" IS NULL", a);
	}

	//////////////////////////////////////////////////////////////////////////
	Expression plus(const Expression &a, const Expression &b)
	{
		return op2("+", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expression minus(const Expression &a, const Expression &b)
	{
		return op2("-", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expression mul(const Expression &a, const Expression &b)
	{
		return op2("*", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expression div(const Expression &a, const Expression &b)
	{
		return op2("/", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expression mod(const Expression &a, const Expression &b)
	{
		return op2("%", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expression exp(const Expression &a, const Expression &b)
	{
		return op2("^", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expression sqrt(const Expression &a, const Expression &b)
	{
		return op2("|/", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expression curt(const Expression &a, const Expression &b)
	{
		return op2("||/", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expression fact(const Expression &a)
	{
		return op1_post("!", a);
	}

	//////////////////////////////////////////////////////////////////////////
	Expression abs(const Expression &a)
	{
		return op1_pre("@", a);
	}

	//////////////////////////////////////////////////////////////////////////
	Expression band(const Expression &a, const Expression &b)
	{
		return op2("&", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expression bor(const Expression &a, const Expression &b)
	{
		return op2("|", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expression bxor(const Expression &a, const Expression &b)
	{
		return op2("#", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expression bnot(const Expression &a)
	{
		return op1_pre("~", a);
	}

	//////////////////////////////////////////////////////////////////////////
	Expression shl(const Expression &a, const Expression &b)
	{
		return op2("<<", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expression shr(const Expression &a, const Expression &b)
	{
		return op2(">>", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expression func(const char *name)
	{
		ExpressionImpl_func *p = new ExpressionImpl_func(name);
		return ImplAccess<Expression>(ExpressionImplPtr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expression func(const char *name, const Expression &a)
	{
		ExpressionImpl_func *p = new ExpressionImpl_func(name);
		p->pushArg(a);
		return ImplAccess<Expression>(ExpressionImplPtr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expression func(const char *name, const Expression &a, const Expression &b)
	{
		ExpressionImpl_func *p = new ExpressionImpl_func(name);
		p->pushArg(a);
		p->pushArg(b);
		return ImplAccess<Expression>(ExpressionImplPtr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expression func(const char *name, const Expression &a, const Expression &b, const Expression &c)
	{
		ExpressionImpl_func *p = new ExpressionImpl_func(name);
		p->pushArg(a);
		p->pushArg(b);
		p->pushArg(c);
		return ImplAccess<Expression>(ExpressionImplPtr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expression func(const char *name, const Expression &a, const Expression &b, const Expression &c, const Expression &d)
	{
		ExpressionImpl_func *p = new ExpressionImpl_func(name);
		p->pushArg(a);
		p->pushArg(b);
		p->pushArg(c);
		p->pushArg(d);
		return ImplAccess<Expression>(ExpressionImplPtr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expression like(const Expression &a, const Expression &b)
	{
		return op2(" LIKE ", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expression similar(const Expression &a, const Expression &b)
	{
		return op2(" SIMILAR TO ", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expression re_cs(const Expression &a, const Expression &b)
	{
		return op2("~", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expression re_ci(const Expression &a, const Expression &b)
	{
		return op2("~*", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expression casec(const Expression &c1, const Expression &r1)
	{
		ExpressionImpl_casec *p = new ExpressionImpl_casec();
		p->pushPair(c1, r1);
		return ImplAccess<Expression>(ExpressionImplPtr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expression casec(const Expression &c1, const Expression &r1, const Expression &el)
	{
		ExpressionImpl_casec *p = new ExpressionImpl_casec();
		p->pushPair(c1, r1);
		p->pushElse(el);
		return ImplAccess<Expression>(ExpressionImplPtr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expression casec(const Expression &c1, const Expression &r1, const Expression &c2, const Expression &r2)
	{
		ExpressionImpl_casec *p = new ExpressionImpl_casec();
		p->pushPair(c1, r1);
		p->pushPair(c2, r2);
		return ImplAccess<Expression>(ExpressionImplPtr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expression casec(const Expression &c1, const Expression &r1, const Expression &c2, const Expression &r2, const Expression &el)
	{
		ExpressionImpl_casec *p = new ExpressionImpl_casec();
		p->pushPair(c1, r1);
		p->pushPair(c2, r2);
		p->pushElse(el);
		return ImplAccess<Expression>(ExpressionImplPtr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expression casec(const Expression &c1, const Expression &r1, const Expression &c2, const Expression &r2, const Expression &c3, const Expression &r3)
	{
		ExpressionImpl_casec *p = new ExpressionImpl_casec();
		p->pushPair(c1, r1);
		p->pushPair(c2, r2);
		p->pushPair(c3, r3);
		return ImplAccess<Expression>(ExpressionImplPtr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expression casec(const Expression &c1, const Expression &r1, const Expression &c2, const Expression &r2, const Expression &c3, const Expression &r3, const Expression &el)
	{
		ExpressionImpl_casec *p = new ExpressionImpl_casec();
		p->pushPair(c1, r1);
		p->pushPair(c2, r2);
		p->pushPair(c3, r3);
		p->pushElse(el);
		return ImplAccess<Expression>(ExpressionImplPtr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expression casec(const Expression &c1, const Expression &r1, const Expression &c2, const Expression &r2, const Expression &c3, const Expression &r3, const Expression &c4, const Expression &r4)
	{
		ExpressionImpl_casec *p = new ExpressionImpl_casec();
		p->pushPair(c1, r1);
		p->pushPair(c2, r2);
		p->pushPair(c3, r3);
		p->pushPair(c4, r4);
		return ImplAccess<Expression>(ExpressionImplPtr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expression casec(const Expression &c1, const Expression &r1, const Expression &c2, const Expression &r2, const Expression &c3, const Expression &r3, const Expression &c4, const Expression &r4, const Expression &el)
	{
		ExpressionImpl_casec *p = new ExpressionImpl_casec();
		p->pushPair(c1, r1);
		p->pushPair(c2, r2);
		p->pushPair(c3, r3);
		p->pushPair(c4, r4);
		p->pushElse(el);
		return ImplAccess<Expression>(ExpressionImplPtr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expression casee(const Expression &e, const Expression &v1, const Expression &r1)
	{
		ExpressionImpl_casee *p = new ExpressionImpl_casee(e);
		p->pushPair(v1, r1);
		return ImplAccess<Expression>(ExpressionImplPtr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expression casee(const Expression &e, const Expression &v1, const Expression &r1, const Expression &el)
	{
		ExpressionImpl_casee *p = new ExpressionImpl_casee(e);
		p->pushPair(v1, r1);
		p->pushElse(el);
		return ImplAccess<Expression>(ExpressionImplPtr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expression casee(const Expression &e, const Expression &v1, const Expression &r1, const Expression &v2, const Expression &r2)
	{
		ExpressionImpl_casee *p = new ExpressionImpl_casee(e);
		p->pushPair(v1, r1);
		p->pushPair(v2, r2);
		return ImplAccess<Expression>(ExpressionImplPtr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expression casee(const Expression &e, const Expression &v1, const Expression &r1, const Expression &v2, const Expression &r2, const Expression &el)
	{
		ExpressionImpl_casee *p = new ExpressionImpl_casee(e);
		p->pushPair(v1, r1);
		p->pushPair(v2, r2);
		p->pushElse(el);
		return ImplAccess<Expression>(ExpressionImplPtr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expression casee(const Expression &e, const Expression &v1, const Expression &r1, const Expression &v2, const Expression &r2, const Expression &v3, const Expression &r3)
	{
		ExpressionImpl_casee *p = new ExpressionImpl_casee(e);
		p->pushPair(v1, r1);
		p->pushPair(v2, r2);
		p->pushPair(v3, r3);
		return ImplAccess<Expression>(ExpressionImplPtr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expression casee(const Expression &e, const Expression &v1, const Expression &r1, const Expression &v2, const Expression &r2, const Expression &v3, const Expression &r3, const Expression &el)
	{
		ExpressionImpl_casee *p = new ExpressionImpl_casee(e);
		p->pushPair(v1, r1);
		p->pushPair(v2, r2);
		p->pushPair(v3, r3);
		p->pushElse(el);
		return ImplAccess<Expression>(ExpressionImplPtr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expression casee(const Expression &e, const Expression &v1, const Expression &r1, const Expression &v2, const Expression &r2, const Expression &v3, const Expression &r3, const Expression &v4, const Expression &r4)
	{
		ExpressionImpl_casee *p = new ExpressionImpl_casee(e);
		p->pushPair(v1, r1);
		p->pushPair(v2, r2);
		p->pushPair(v3, r3);
		p->pushPair(v4, r4);
		return ImplAccess<Expression>(ExpressionImplPtr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expression casee(const Expression &e, const Expression &v1, const Expression &r1, const Expression &v2, const Expression &r2, const Expression &v3, const Expression &r3, const Expression &v4, const Expression &r4, const Expression &el)
	{
		ExpressionImpl_casee *p = new ExpressionImpl_casee(e);
		p->pushPair(v1, r1);
		p->pushPair(v2, r2);
		p->pushPair(v3, r3);
		p->pushPair(v4, r4);
		p->pushElse(el);
		return ImplAccess<Expression>(ExpressionImplPtr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expression in(const Expression &a, const Expression &v1)
	{
		ExpressionImpl_func *p = new ExpressionImpl_func("IN");
		p->pushArg(v1);
		return ImplAccess<Expression>(ExpressionImplPtr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expression in(const Expression &a, const Expression &v1, const Expression &v2)
	{
		ExpressionImpl_func *p = new ExpressionImpl_func("IN");
		p->pushArg(v1);
		p->pushArg(v2);
		return ImplAccess<Expression>(ExpressionImplPtr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expression in(const Expression &a, const Expression &v1, const Expression &v2, const Expression &v3)
	{
		ExpressionImpl_func *p = new ExpressionImpl_func("IN");
		p->pushArg(v1);
		p->pushArg(v2);
		p->pushArg(v3);
		return ImplAccess<Expression>(ExpressionImplPtr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expression in(const Expression &a, const Expression &v1, const Expression &v2, const Expression &v3, const Expression &v4)
	{
		ExpressionImpl_func *p = new ExpressionImpl_func("IN");
		p->pushArg(v1);
		p->pushArg(v2);
		p->pushArg(v3);
		p->pushArg(v4);
		return ImplAccess<Expression>(ExpressionImplPtr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expression any(const Expression &a)
	{
		ExpressionImpl_func *p = new ExpressionImpl_func("ANY");
		p->pushArg(a);
		return ImplAccess<Expression>(ExpressionImplPtr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expression list(const Expression &v1, const Expression &v2)
	{
		ExpressionImpl_listPtr l1 = boost::shared_dynamic_cast<ExpressionImpl_list>(ImplAccess<Expression>(v1).impl());
		if(l1)
		{
			l1->push(v2);
			return v1;
		}

		ExpressionImpl_listPtr l(new ExpressionImpl_list);
		l->push(v1);
		l->push(v2);

		return ImplAccess<Expression>(l);
	}

}
