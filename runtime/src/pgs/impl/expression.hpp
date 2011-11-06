#ifndef _PGS_IMPL_EXPRESSION_HPP_
#define _PGS_IMPL_EXPRESSION_HPP_

#include "pgs/expression.hpp"
#include <vector>
#include <boost/enable_shared_from_this.hpp>

namespace pgs
{
	namespace impl
	{
		//////////////////////////////////////////////////////////////////////////
		class Expression
			: public boost::enable_shared_from_this<Expression>
		{
		public:
			Expression();
			virtual ~Expression();

		public:
		};
		typedef boost::shared_ptr<Expression> Expression_ptr;

		//////////////////////////////////////////////////////////////////////////
		class Expression_list
			: public Expression
		{
			std::vector<Expression_ptr> _list;
		public:
			Expression_list();
			~Expression_list();

			void push(const pgs::Expression &a);
		};
		typedef boost::shared_ptr<Expression_list> Expression_list_ptr;

		//////////////////////////////////////////////////////////////////////////
		class Expression_op0
			: public Expression
		{
			std::string		_name;
		public:
			Expression_op0(const char *name);
			~Expression_op0();

		};

		//////////////////////////////////////////////////////////////////////////
		class Expression_op1
			: public Expression
		{
			std::string		_name;
			Expression_ptr	_a;
			bool			_isPre;
		public:
			Expression_op1(const char *name, const pgs::Expression &a, bool isPre=true);
			~Expression_op1();
		};

		//////////////////////////////////////////////////////////////////////////
		class Expression_op2
			: public Expression
		{
			std::string		_name;
			Expression_ptr	_a;
			Expression_ptr	_b;
		public:
			Expression_op2(const char *name, const pgs::Expression &a, const pgs::Expression &b);
			~Expression_op2();

		};

		//////////////////////////////////////////////////////////////////////////
		class Expression_op3
			: public Expression
		{
		public:
			Expression_op3(const char *name1, const char *name2, const pgs::Expression &a, const pgs::Expression &b, const pgs::Expression &c);
			~Expression_op3();

		};

		//////////////////////////////////////////////////////////////////////////
		class Expression_func
			: public Expression
		{
			std::string	_name;

			typedef std::vector<Expression_ptr> TVArgs;
			TVArgs _args;
		public:
			Expression_func(const char *name);
			~Expression_func();

			void pushArg(const pgs::Expression &a);

		};

		//////////////////////////////////////////////////////////////////////////
		class Expression_casec
			: public Expression
		{
		public:
			Expression_casec();
			~Expression_casec();

			void pushPair(const pgs::Expression &c, const pgs::Expression &r);
			void pushElse(const pgs::Expression &e);

		};

		//////////////////////////////////////////////////////////////////////////
		class Expression_casee
			: public Expression
		{
		public:
			Expression_casee(const pgs::Expression &e);
			~Expression_casee();

			void pushPair(const pgs::Expression &v, const pgs::Expression &r);
			void pushElse(const pgs::Expression &e);

		};
	}
}
#endif
