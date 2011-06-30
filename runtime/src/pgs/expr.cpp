#include "pgs/expr.hpp"
#include "exprImpl.hpp"

namespace pgs
{
	Expr op1_pre(const char *name, const Expr &a)
	{
		return Expr(ExprImpl_ptr(new ExprImpl_op1(name, a, true)));
	}
	Expr op1_post(const char *name, const Expr &a)
	{
		return Expr(ExprImpl_ptr(new ExprImpl_op1(name, a, false)));
	}
	Expr op2(const char *name, const Expr &a, const Expr &b)
	{
		return Expr(ExprImpl_ptr(new ExprImpl_op2(name, a, b)));
	}
	Expr op3(const char *name1, const char *name2, const Expr &a, const Expr &b, const Expr &c)
	{
		return Expr(ExprImpl_ptr(new ExprImpl_op3(name1, name2, a, b, c)));
	}


	//////////////////////////////////////////////////////////////////////////
	Expr and(const Expr &a, const Expr &b)
	{
		return op2("AND", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expr or(const Expr &a, const Expr &b)
	{
		return op2("OR", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expr not(const Expr &a)
	{
		return op1_pre("NOT", a);
	}

	//////////////////////////////////////////////////////////////////////////
	Expr lt(const Expr &a, const Expr &b)
	{
		return op2("<", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expr gt(const Expr &a, const Expr &b)
	{
		return op2(">", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expr le(const Expr &a, const Expr &b)
	{
		return op2("<=", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expr ge(const Expr &a, const Expr &b)
	{
		return op2(">=", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expr eq(const Expr &a, const Expr &b)
	{
		return op2("=", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expr ne(const Expr &a, const Expr &b)
	{
		return op2("<>", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expr between(const Expr &a, const Expr &b, const Expr &c)
	{
		return op3("BETWEEN", "AND", a, b, c);
	}

	//////////////////////////////////////////////////////////////////////////
	Expr isNull(const Expr &a)
	{
		return op1_post("IS NULL", a);
	}

	//////////////////////////////////////////////////////////////////////////
	Expr plus(const Expr &a, const Expr &b)
	{
		return op2("+", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expr minus(const Expr &a, const Expr &b)
	{
		return op2("-", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expr mul(const Expr &a, const Expr &b)
	{
		return op2("*", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expr div(const Expr &a, const Expr &b)
	{
		return op2("/", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expr mod(const Expr &a, const Expr &b)
	{
		return op2("%", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expr exp(const Expr &a, const Expr &b)
	{
		return op2("^", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expr sqrt(const Expr &a, const Expr &b)
	{
		return op2("|/", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expr curt(const Expr &a, const Expr &b)
	{
		return op2("||/", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expr fact(const Expr &a)
	{
		return op1_post("!", a);
	}

	//////////////////////////////////////////////////////////////////////////
	Expr abs(const Expr &a)
	{
		return op1_pre("@", a);
	}

	//////////////////////////////////////////////////////////////////////////
	Expr band(const Expr &a, const Expr &b)
	{
		return op2("&", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expr bor(const Expr &a, const Expr &b)
	{
		return op2("|", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expr bxor(const Expr &a, const Expr &b)
	{
		return op2("#", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expr bnot(const Expr &a)
	{
		return op1_pre("~", a);
	}

	//////////////////////////////////////////////////////////////////////////
	Expr shl(const Expr &a, const Expr &b)
	{
		return op2("<<", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expr shr(const Expr &a, const Expr &b)
	{
		return op2(">>", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expr func(const char *name)
	{
		ExprImpl_func *p = new ExprImpl_func(name);
		return Expr(ExprImpl_ptr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expr func(const char *name, const Expr &a)
	{
		ExprImpl_func *p = new ExprImpl_func(name);
		p->pushArg(a);
		return Expr(ExprImpl_ptr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expr func(const char *name, const Expr &a, const Expr &b)
	{
		ExprImpl_func *p = new ExprImpl_func(name);
		p->pushArg(a);
		p->pushArg(b);
		return Expr(ExprImpl_ptr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expr func(const char *name, const Expr &a, const Expr &b, const Expr &c)
	{
		ExprImpl_func *p = new ExprImpl_func(name);
		p->pushArg(a);
		p->pushArg(b);
		p->pushArg(c);
		return Expr(ExprImpl_ptr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expr func(const char *name, const Expr &a, const Expr &b, const Expr &c, const Expr &d)
	{
		ExprImpl_func *p = new ExprImpl_func(name);
		p->pushArg(a);
		p->pushArg(b);
		p->pushArg(c);
		p->pushArg(d);
		return Expr(ExprImpl_ptr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expr like(const Expr &a, const Expr &b)
	{
		return op2("LIKE", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expr similar(const Expr &a, const Expr &b)
	{
		return op2("SIMILAR TO", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expr re_cs(const Expr &a, const Expr &b)
	{
		return op2("~", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expr re_ci(const Expr &a, const Expr &b)
	{
		return op2("~*", a, b);
	}

	//////////////////////////////////////////////////////////////////////////
	Expr casec(const Expr &c1, const Expr &r1)
	{
		ExprImpl_casec *p = new ExprImpl_casec();
		p->pushPair(c1, r1);
		return Expr(ExprImpl_ptr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expr casec(const Expr &c1, const Expr &r1, const Expr &el)
	{
		ExprImpl_casec *p = new ExprImpl_casec();
		p->pushPair(c1, r1);
		p->pushElse(el);
		return Expr(ExprImpl_ptr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expr casec(const Expr &c1, const Expr &r1, const Expr &c2, const Expr &r2)
	{
		ExprImpl_casec *p = new ExprImpl_casec();
		p->pushPair(c1, r1);
		p->pushPair(c2, r2);
		return Expr(ExprImpl_ptr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expr casec(const Expr &c1, const Expr &r1, const Expr &c2, const Expr &r2, const Expr &el)
	{
		ExprImpl_casec *p = new ExprImpl_casec();
		p->pushPair(c1, r1);
		p->pushPair(c2, r2);
		p->pushElse(el);
		return Expr(ExprImpl_ptr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expr casec(const Expr &c1, const Expr &r1, const Expr &c2, const Expr &r2, const Expr &c3, const Expr &r3)
	{
		ExprImpl_casec *p = new ExprImpl_casec();
		p->pushPair(c1, r1);
		p->pushPair(c2, r2);
		p->pushPair(c3, r3);
		return Expr(ExprImpl_ptr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expr casec(const Expr &c1, const Expr &r1, const Expr &c2, const Expr &r2, const Expr &c3, const Expr &r3, const Expr &el)
	{
		ExprImpl_casec *p = new ExprImpl_casec();
		p->pushPair(c1, r1);
		p->pushPair(c2, r2);
		p->pushPair(c3, r3);
		p->pushElse(el);
		return Expr(ExprImpl_ptr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expr casec(const Expr &c1, const Expr &r1, const Expr &c2, const Expr &r2, const Expr &c3, const Expr &r3, const Expr &c4, const Expr &r4)
	{
		ExprImpl_casec *p = new ExprImpl_casec();
		p->pushPair(c1, r1);
		p->pushPair(c2, r2);
		p->pushPair(c3, r3);
		p->pushPair(c4, r4);
		return Expr(ExprImpl_ptr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expr casec(const Expr &c1, const Expr &r1, const Expr &c2, const Expr &r2, const Expr &c3, const Expr &r3, const Expr &c4, const Expr &r4, const Expr &el)
	{
		ExprImpl_casec *p = new ExprImpl_casec();
		p->pushPair(c1, r1);
		p->pushPair(c2, r2);
		p->pushPair(c3, r3);
		p->pushPair(c4, r4);
		p->pushElse(el);
		return Expr(ExprImpl_ptr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expr casee(const Expr &e, const Expr &v1, const Expr &r1)
	{
		ExprImpl_casee *p = new ExprImpl_casee(e);
		p->pushPair(v1, r1);
		return Expr(ExprImpl_ptr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expr casee(const Expr &e, const Expr &v1, const Expr &r1, const Expr &el)
	{
		ExprImpl_casee *p = new ExprImpl_casee(e);
		p->pushPair(v1, r1);
		p->pushElse(el);
		return Expr(ExprImpl_ptr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expr casee(const Expr &e, const Expr &v1, const Expr &r1, const Expr &v2, const Expr &r2)
	{
		ExprImpl_casee *p = new ExprImpl_casee(e);
		p->pushPair(v1, r1);
		p->pushPair(v2, r2);
		return Expr(ExprImpl_ptr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expr casee(const Expr &e, const Expr &v1, const Expr &r1, const Expr &v2, const Expr &r2, const Expr &el)
	{
		ExprImpl_casee *p = new ExprImpl_casee(e);
		p->pushPair(v1, r1);
		p->pushPair(v2, r2);
		p->pushElse(el);
		return Expr(ExprImpl_ptr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expr casee(const Expr &e, const Expr &v1, const Expr &r1, const Expr &v2, const Expr &r2, const Expr &v3, const Expr &r3)
	{
		ExprImpl_casee *p = new ExprImpl_casee(e);
		p->pushPair(v1, r1);
		p->pushPair(v2, r2);
		p->pushPair(v3, r3);
		return Expr(ExprImpl_ptr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expr casee(const Expr &e, const Expr &v1, const Expr &r1, const Expr &v2, const Expr &r2, const Expr &v3, const Expr &r3, const Expr &el)
	{
		ExprImpl_casee *p = new ExprImpl_casee(e);
		p->pushPair(v1, r1);
		p->pushPair(v2, r2);
		p->pushPair(v3, r3);
		p->pushElse(el);
		return Expr(ExprImpl_ptr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expr casee(const Expr &e, const Expr &v1, const Expr &r1, const Expr &v2, const Expr &r2, const Expr &v3, const Expr &r3, const Expr &v4, const Expr &r4)
	{
		ExprImpl_casee *p = new ExprImpl_casee(e);
		p->pushPair(v1, r1);
		p->pushPair(v2, r2);
		p->pushPair(v3, r3);
		p->pushPair(v4, r4);
		return Expr(ExprImpl_ptr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expr casee(const Expr &e, const Expr &v1, const Expr &r1, const Expr &v2, const Expr &r2, const Expr &v3, const Expr &r3, const Expr &v4, const Expr &r4, const Expr &el)
	{
		ExprImpl_casee *p = new ExprImpl_casee(e);
		p->pushPair(v1, r1);
		p->pushPair(v2, r2);
		p->pushPair(v3, r3);
		p->pushPair(v4, r4);
		p->pushElse(el);
		return Expr(ExprImpl_ptr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expr in(const Expr &a, const Expr &v1)
	{
		ExprImpl_func *p = new ExprImpl_func("IN");
		p->pushArg(v1);
		return Expr(ExprImpl_ptr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expr in(const Expr &a, const Expr &v1, const Expr &v2)
	{
		ExprImpl_func *p = new ExprImpl_func("IN");
		p->pushArg(v1);
		p->pushArg(v2);
		return Expr(ExprImpl_ptr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expr in(const Expr &a, const Expr &v1, const Expr &v2, const Expr &v3)
	{
		ExprImpl_func *p = new ExprImpl_func("IN");
		p->pushArg(v1);
		p->pushArg(v2);
		p->pushArg(v3);
		return Expr(ExprImpl_ptr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expr in(const Expr &a, const Expr &v1, const Expr &v2, const Expr &v3, const Expr &v4)
	{
		ExprImpl_func *p = new ExprImpl_func("IN");
		p->pushArg(v1);
		p->pushArg(v2);
		p->pushArg(v3);
		p->pushArg(v4);
		return Expr(ExprImpl_ptr(p));
	}

	//////////////////////////////////////////////////////////////////////////
	Expr eqAny(const Expr &a, const Expr &vs)
	{
		ExprImpl_func *p = new ExprImpl_func("=ANY");
		p->pushArg(vs);
		return Expr(ExprImpl_ptr(p));
	}

	//////////////////////////////////////////////////////////////////////////

}
