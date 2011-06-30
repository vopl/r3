#ifndef _PGS_EXPRIMPL_HPP_
#define _PGS_EXPRIMPL_HPP_

#include "pgs/expr.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	class ExprImpl
	{
	protected:
		ExprImpl(...);
	};

	//////////////////////////////////////////////////////////////////////////
	class ExprImpl_op1
		: public ExprImpl
	{
	public:
		ExprImpl_op1(const char *name, const Expr &a, bool isPre=true);
		~ExprImpl_op1();
	};

	//////////////////////////////////////////////////////////////////////////
	class ExprImpl_op2
		: public ExprImpl
	{
	public:
		ExprImpl_op2(const char *name, const Expr &a, const Expr &b);
		~ExprImpl_op2();
	};

	//////////////////////////////////////////////////////////////////////////
	class ExprImpl_op3
		: public ExprImpl
	{
	public:
		ExprImpl_op3(const char *name1, const char *name2, const Expr &a, const Expr &b, const Expr &c);
		~ExprImpl_op3();
	};

	//////////////////////////////////////////////////////////////////////////
	class ExprImpl_func
		: public ExprImpl
	{
	public:
		ExprImpl_func(const char *name);
		~ExprImpl_func();

		void pushArg(const Expr &a);
	};

	//////////////////////////////////////////////////////////////////////////
	class ExprImpl_casec
		: public ExprImpl
	{
	public:
		ExprImpl_casec();
		~ExprImpl_casec();

		void pushPair(const Expr &c, const Expr &r);
		void pushElse(const Expr &e);
	};

	//////////////////////////////////////////////////////////////////////////
	class ExprImpl_casee
		: public ExprImpl
	{
	public:
		ExprImpl_casee(const Expr &e);
		~ExprImpl_casee();

		void pushPair(const Expr &v, const Expr &r);
		void pushElse(const Expr &e);

	};

}
#endif
