#ifndef _PGS_EXPRIMPL_HPP_
#define _PGS_EXPRIMPL_HPP_

#include "pgs/expr.hpp"
#include <vector>
#include <boost/enable_shared_from_this.hpp>

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	class ExprImpl;
	typedef boost::shared_ptr<ExprImpl> ExprImpl_ptr;

	//////////////////////////////////////////////////////////////////////////
	class StatementImpl;


	//////////////////////////////////////////////////////////////////////////
	class ExprImpl
		: public boost::enable_shared_from_this<ExprImpl>
	{
	protected:
		ExprImpl();

	public:
		virtual void reg(StatementImpl *s) =0;
		virtual void mkSql(std::string &result) =0;
	};

	//////////////////////////////////////////////////////////////////////////
	class ExprImpl_op1
		: public ExprImpl
	{
		std::string		_name;
		ExprImpl_ptr	_a;
		bool			_isPre;
	public:
		ExprImpl_op1(const char *name, const Expr &a, bool isPre=true);
		~ExprImpl_op1();

		virtual void reg(StatementImpl *s);
		virtual void mkSql(std::string &result);
	};

	//////////////////////////////////////////////////////////////////////////
	class ExprImpl_op2
		: public ExprImpl
	{
		std::string		_name;
		ExprImpl_ptr	_a;
		ExprImpl_ptr	_b;
	public:
		ExprImpl_op2(const char *name, const Expr &a, const Expr &b);
		~ExprImpl_op2();

		virtual void reg(StatementImpl *s);
		virtual void mkSql(std::string &result);
	};

	//////////////////////////////////////////////////////////////////////////
	class ExprImpl_op3
		: public ExprImpl
	{
	public:
		ExprImpl_op3(const char *name1, const char *name2, const Expr &a, const Expr &b, const Expr &c);
		~ExprImpl_op3();

		virtual void reg(StatementImpl *s);
		virtual void mkSql(std::string &result);
	};

	//////////////////////////////////////////////////////////////////////////
	class ExprImpl_func
		: public ExprImpl
	{
		std::string	_name;

		typedef std::vector<ExprImpl_ptr> TVArgs;
		TVArgs _args;
	public:
		ExprImpl_func(const char *name);
		~ExprImpl_func();

		void pushArg(const Expr &a);

		virtual void reg(StatementImpl *s);
		virtual void mkSql(std::string &result);
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

		virtual void reg(StatementImpl *s);
		virtual void mkSql(std::string &result);
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

		virtual void reg(StatementImpl *s);
		virtual void mkSql(std::string &result);
	};

}
#endif
