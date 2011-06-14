#ifndef _R3_DATABASE_HPP_
#define _R3_DATABASE_HPP_

#include "pgc/connection.hpp"

#include <boost/thread/tss.hpp>
#include <boost/thread/mutex.hpp>

namespace r3
{
	//////////////////////////////////////////////////////////////////////////
	class StmStorageBase;
	typedef StmStorageBase *(*TStmStorageCreator)();
	typedef void (*TStmStorageDestroyer)(StmStorageBase *);

	//////////////////////////////////////////////////////////////////////////
	class StmStorageBase
	{
	protected:
		boost::thread_specific_ptr<pgc::Connection> _tcon;

	public:
		static std::vector<TStmStorageCreator> &creators();
		static std::vector<TStmStorageDestroyer> &destroyers();

		virtual void startInThread(pgc::Connection con);
		virtual void stopInThread();
		virtual pgc::Statement call(const std::string &key)=0;
	};

	//////////////////////////////////////////////////////////////////////////
	template <class tag> class StmStorage
		: public StmStorageBase
	{
		static StmStorageBase *creator();
		static void destroyer(StmStorageBase *);

		static size_t statInitializer();

		typedef std::map<std::string, pgc::Statement> TMStatements;
		TMStatements _statements;
	public:
		static size_t _index;

		virtual void startInThread(pgc::Connection con);
		virtual void stopInThread();
		virtual pgc::Statement call(const std::string &key);
	};

	//////////////////////////////////////////////////////////////////////////
	class Data;

	//////////////////////////////////////////////////////////////////////////
	class DataBase
	{
		boost::thread_specific_ptr<pgc::Connection> _tcon;
		std::vector<StmStorageBase *> _stmStorages;
		boost::mutex _mtx;

	public:
		DataBase();
		~DataBase();

		void startInThread(const char *conninfo);
		void stopInThread();

		pgc::Connection con();
		template <class tag>
		pgc::Statement stm(const std::string &key);
		pgc::Statement stm(const std::string &key);

	private:
		struct StmSecretType;


	protected:
		template <class SP>
		SP getSchemaImpl(std::map<std::string, SP> &m, const char *id);
	};

	//////////////////////////////////////////////////////////////////////////
	template <class tag> StmStorageBase *StmStorage<tag>::creator()
	{
		return new StmStorage<tag>;
	}
	template <class tag> void StmStorage<tag>::destroyer(StmStorageBase *p)
	{
		delete (StmStorage<tag> *)p;
	}
	template <class tag> size_t StmStorage<tag>::_index = StmStorage<tag>::statInitializer();
	template <class tag> size_t StmStorage<tag>::statInitializer()
	{
		creators().push_back(&creator);
		destroyers().push_back(&destroyer);
		return creators().size()-1;
	}

	template <class tag> pgc::Statement StmStorage<tag>::call(const std::string &key)
	{
		TMStatements::iterator iter = _statements.find(key);
		if(_statements.end() == iter)
		{
			_statements[key] = _tcon->prep();
			iter = _statements.find(key);
		}

		return iter->second;;
	}

	template <class tag> void StmStorage<tag>::startInThread(pgc::Connection con)
	{
		_statements.clear();
		StmStorageBase::startInThread(con);
	}

	template <class tag> void StmStorage<tag>::stopInThread()
	{
		_statements.clear();
		StmStorageBase::stopInThread();
	}


	//////////////////////////////////////////////////////////////////////////
	template <class SP>
	SP DataBase::getSchemaImpl(std::map<std::string, SP> &m, const char *id)
	{
		boost::mutex::scoped_lock sl(_mtx);

		SP &p = m[id];
		if(!p)
		{
			p.reset(new typename SP::value_type((Data *)this, id));
		}
		return p;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class tag> pgc::Statement DataBase::stm(const std::string &key)
	{
		size_t idx = StmStorage<tag>::_index;
		assert(_stmStorages.size() && _stmStorages.size() > idx);
		return _stmStorages[idx]->call(key);
	}

	//////////////////////////////////////////////////////////////////////////
	inline pgc::Statement DataBase::stm(const std::string &key)
	{
		return stm<DataBase::StmSecretType>(key);
	}

}

#endif
