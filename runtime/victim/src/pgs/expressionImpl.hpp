#ifndef _PGS_EXPRESSIONIMPL_HPP_
#define _PGS_EXPRESSIONIMPL_HPP_

#include "pgs/expression.hpp"
#include <vector>
#include <boost/enable_shared_from_this.hpp>

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	class ExpressionImpl;
	typedef boost::shared_ptr<ExpressionImpl> ExpressionImpl_ptr;

	//////////////////////////////////////////////////////////////////////////
	class StatementImpl;


	//////////////////////////////////////////////////////////////////////////
	class ExpressionImpl
		: public boost::enable_shared_from_this<ExpressionImpl>
	{
	protected:
		ExpressionImpl();

	public:
		virtual void reg(StatementImpl *s) =0;
		virtual void mkSql(std::string &result) =0;
	};

	//////////////////////////////////////////////////////////////////////////
	class ExpressionImpl_list
		: public ExpressionImpl
	{
		std::vector<ExpressionImpl_ptr> _list;
	public:
		ExpressionImpl_list();
		~ExpressionImpl_list();

		void push(const Expression &a);

		virtual void reg(StatementImpl *s);
		virtual void mkSql(std::string &result);
	};
	typedef boost::shared_ptr<ExpressionImpl_list> ExpressionImpl_list_ptr;

	//////////////////////////////////////////////////////////////////////////
	class ExpressionImpl_op0
		: public ExpressionImpl
	{
		std::string		_name;
	public:
		ExpressionImpl_op0(const char *name);
		~ExpressionImpl_op0();

		virtual void reg(StatementImpl *s);
		virtual void mkSql(std::string &result);
	};

	//////////////////////////////////////////////////////////////////////////
	class ExpressionImpl_op1
		: public ExpressionImpl
	{
		std::string		_name;
		ExpressionImpl_ptr	_a;
		bool			_isPre;
	public:
		ExpressionImpl_op1(const char *name, const Expression &a, bool isPre=true);
		~ExpressionImpl_op1();

		virtual void reg(StatementImpl *s);
		virtual void mkSql(std::string &result);
	};

	//////////////////////////////////////////////////////////////////////////
	class ExpressionImpl_op2
		: public ExpressionImpl
	{
		std::string		_name;
		ExpressionImpl_ptr	_a;
		ExpressionImpl_ptr	_b;
	public:
		ExpressionImpl_op2(const char *name, const Expression &a, const Expression &b);
		~ExpressionImpl_op2();

		virtual void reg(StatementImpl *s);
		virtual void mkSql(std::string &result);
	};

	//////////////////////////////////////////////////////////////////////////
	class ExpressionImpl_op3
		: public ExpressionImpl
	{
	public:
		ExpressionImpl_op3(const char *name1, const char *name2, const Expression &a, const Expression &b, const Expression &c);
		~ExpressionImpl_op3();

		virtual void reg(StatementImpl *s);
		virtual void mkSql(std::string &result);
	};

	//////////////////////////////////////////////////////////////////////////
	class ExpressionImpl_func
		: public ExpressionImpl
	{
		std::string	_name;

		typedef std::vector<ExpressionImpl_ptr> TVArgs;
		TVArgs _args;
	public:
		ExpressionImpl_func(const char *name);
		~ExpressionImpl_func();

		void pushArg(const Expression &a);

		virtual void reg(StatementImpl *s);
		virtual void mkSql(std::string &result);
	};

	//////////////////////////////////////////////////////////////////////////
	class ExpressionImpl_casec
		: public ExpressionImpl
	{
	public:
		ExpressionImpl_casec();
		~ExpressionImpl_casec();

		void pushPair(const Expression &c, const Expression &r);
		void pushElse(const Expression &e);

		virtual void reg(StatementImpl *s);
		virtual void mkSql(std::string &result);
	};

	//////////////////////////////////////////////////////////////////////////
	class ExpressionImpl_casee
		: public ExpressionImpl
	{
	public:
		ExpressionImpl_casee(const Expression &e);
		~ExpressionImpl_casee();

		void pushPair(const Expression &v, const Expression &r);
		void pushElse(const Expression &e);

		virtual void reg(StatementImpl *s);
		virtual void mkSql(std::string &result);
	};

}
#endif
