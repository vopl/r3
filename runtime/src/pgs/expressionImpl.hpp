#ifndef _PGS_EXPRESSIONIMPL_HPP_
#define _PGS_EXPRESSIONIMPL_HPP_

#include "pgs/expression.hpp"
#include "clusterImpl.hpp"
#include <vector>
#include <boost/enable_shared_from_this.hpp>

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	enum ECompileMode
	{
		ecmSelectFrom,
		ecmSelectLink,
		ecmSelectWhat,
		ecmSelectWhere,
		ecmSelectOrder,
		ecmSelectLimit,
		ecmSelectOffset,
	};

	//////////////////////////////////////////////////////////////////////////
	//объект состояния компиляции
	struct SCompileState
	{
		ClusterImplPtr				_cluster;
		std::set<std::string>		_aliases;
		size_t						_nextCrossIndex;
		size_t						_nextWhatColumnIndex;

		std::map<void *, size_t>	_valueNumbers;

		typedef std::map<std::string, size_t>	TMName2idx;
		TMName2idx					_bindName2idx;
		TMName2idx					_fetchName2idx;


		SCompileState();
		bool checkAliasExistence(const std::string &alias, bool mustExists);
	};

	//////////////////////////////////////////////////////////////////////////
	class ExpressionImpl
		: public boost::enable_shared_from_this<ExpressionImpl>
	{
	public:
		ExpressionImpl();
		virtual ~ExpressionImpl();

	public:
		virtual void compile(std::deque<std::string> &res, SCompileState &state, ECompileMode ecm)=0;
	};
	typedef boost::shared_ptr<ExpressionImpl> ExpressionImplPtr;

	//////////////////////////////////////////////////////////////////////////
	class ExpressionImpl_list
		: public ExpressionImpl
	{
		std::vector<ExpressionImplPtr> _list;
	public:
		ExpressionImpl_list();
		~ExpressionImpl_list();

		void push(const Expression &a);

		virtual void compile(std::deque<std::string> &res, SCompileState &state, ECompileMode ecm);
	};
	typedef boost::shared_ptr<ExpressionImpl_list> ExpressionImpl_listPtr;

	//////////////////////////////////////////////////////////////////////////
	class ExpressionImpl_op0
		: public ExpressionImpl
	{
		std::string		_name;
	public:
		ExpressionImpl_op0(const char *name);
		~ExpressionImpl_op0();

		virtual void compile(std::deque<std::string> &res, SCompileState &state, ECompileMode ecm);
	};

	//////////////////////////////////////////////////////////////////////////
	class ExpressionImpl_op1
		: public ExpressionImpl
	{
		std::string		_name;
		ExpressionImplPtr	_a;
		bool			_isPre;
	public:
		ExpressionImpl_op1(const char *name, const Expression &a, bool isPre=true);
		~ExpressionImpl_op1();

		virtual void compile(std::deque<std::string> &res, SCompileState &state, ECompileMode ecm);
	};

	//////////////////////////////////////////////////////////////////////////
	class ExpressionImpl_op2
		: public ExpressionImpl
	{
		std::string		_name;
		ExpressionImplPtr	_a;
		ExpressionImplPtr	_b;
	public:
		ExpressionImpl_op2(const char *name, const Expression &a, const Expression &b);
		~ExpressionImpl_op2();

		virtual void compile(std::deque<std::string> &res, SCompileState &state, ECompileMode ecm);
	};

	//////////////////////////////////////////////////////////////////////////
	class ExpressionImpl_op3
		: public ExpressionImpl
	{
	public:
		ExpressionImpl_op3(const char *name1, const char *name2, const Expression &a, const Expression &b, const Expression &c);
		~ExpressionImpl_op3();

		virtual void compile(std::deque<std::string> &res, SCompileState &state, ECompileMode ecm);
	};

	//////////////////////////////////////////////////////////////////////////
	class ExpressionImpl_func
		: public ExpressionImpl
	{
		std::string	_name;

		typedef std::vector<ExpressionImplPtr> TVArgs;
		TVArgs _args;
	public:
		ExpressionImpl_func(const char *name);
		~ExpressionImpl_func();

		void pushArg(const Expression &a);

		virtual void compile(std::deque<std::string> &res, SCompileState &state, ECompileMode ecm);
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

		virtual void compile(std::deque<std::string> &res, SCompileState &state, ECompileMode ecm);
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

		virtual void compile(std::deque<std::string> &res, SCompileState &state, ECompileMode ecm);
	};
}
#endif
