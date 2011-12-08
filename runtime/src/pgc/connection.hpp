#ifndef _PGC_CONNECTION_HPP_
#define _PGC_CONNECTION_HPP_

#include "pgc/iconnection.hpp"
#include <boost/enable_shared_from_this.hpp>
#include <boost/uuid/random_generator.hpp>
#include "pgconnWrapper.hpp"
#include "bindData.hpp"

namespace pgc
{
	using namespace boost;


	class Db;
	typedef boost::shared_ptr<Db> DbPtr;

	//////////////////////////////////////////////////////////////////////////
	class Connection
		: public IConnection
		, public enable_shared_from_this<Connection>
	{
		DbPtr _db;
		PGconnWrapperPtr _con;

	private:

		enum EPrepState
		{
			epsStart,
			epsSPMaked,
			epsPrepMaked,
			epsPrepared,
			epsError,
		};
		struct SPrepState
		{
			EPrepState		_eps;
			IStatementPtr	_s;
			BindDataPtr		_data;
			boost::function<void (IResultPtr)> _done;
			bool			_inTrans;
		};
		typedef boost::shared_ptr<SPrepState> SPrepStatePtr;

		void prepareStep_(SPrepStatePtr state, IResultPtr lastRes=IResultPtr());
		void prepare_(IStatementPtr s, BindDataPtr data, boost::function<void (IResultPtr)> done);

		void exec_(IStatementPtr s, BindDataPtr data, boost::function<void (IResultPtr)> done);

		void keeper(boost::function<void (IResultPtr)> done, IResultPtr res);

	public:
		Connection(DbPtr db, PGconnWrapperPtr con);
		~Connection();

		virtual void exec(const char *sql,
			boost::function<void (IResultPtr)> done);

		virtual void exec(IStatementPtr s,
			boost::function<void (IResultPtr)> done);

		virtual void exec(IStatementPtr s,
			const utils::Variant &data,
			boost::function<void (IResultPtr)> done);

		virtual EConnectionStatus status(){return ecsOk;};

		virtual void close();

	};
	typedef boost::shared_ptr<Connection> ConnectionPtr;
}

#endif

