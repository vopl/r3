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

		static boost::uuids::random_generator _uuidGen;
		static std::string preparedIdGen();

	private:

		enum EPrepState
		{
			epsStart,
			epsSPMaked,
			epsPrepMaked,
			epsSPReverted,
			epsSPReleased,
		};
		struct SPrepState
		{
			EPrepState		_eps;
			IStatementPtr	_s;
			BindDataPtr		_data;
			boost::function<void (IResultPtr)> _done;
			bool			_inTrans;
			std::string		_uniq;
		};
		typedef boost::shared_ptr<SPrepState> SPrepStatePtr;

		void prepare_(IStatementPtr s, BindDataPtr data, boost::function<void (IResultPtr)> done);
		void prepareStep_(SPrepStatePtr state);

		void exec_(IStatementPtr s, BindDataPtr data, boost::function<void (IResultPtr)> done);

	public:
		Connection(DbPtr db, PGconnWrapperPtr con);
		~Connection();

		virtual void exec(IStatementPtr s,
			boost::function<void (IResultPtr)> done);

		virtual void exec(IStatementPtr s,
			const utils::Variant &data,
			boost::function<void (IResultPtr)> done);
	};
	typedef boost::shared_ptr<Connection> ConnectionPtr;
}

#endif

