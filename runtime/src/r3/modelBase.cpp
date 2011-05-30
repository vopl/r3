#include "stdafx.h"
#include "r3/modelBase.hpp"

namespace r3
{
	std::vector<TStmStorageCreator> &StmStorageBase::creators()
	{
		static std::vector<TStmStorageCreator> creators;
		return creators;
	}

	std::vector<TStmStorageDestroyer> &StmStorageBase::destroyers()
	{
		static std::vector<TStmStorageDestroyer> destroyers;
		return destroyers;
	}

	void StmStorageBase::startInThread(pgc::Connection con)
	{
		_tcon.reset(new pgc::Connection(con));
	}

	void StmStorageBase::stopInThread()
	{
		_tcon.reset();
	}


	//////////////////////////////////////////////////////////////////////////
	ModelBase::ModelBase()
	{

	}

	//////////////////////////////////////////////////////////////////////////
	ModelBase::~ModelBase()
	{

	}

	//////////////////////////////////////////////////////////////////////////
	void ModelBase::startInThread(const char *conninfo)
	{
		_tcon.reset(new pgc::Connection);
		_tcon->open(conninfo);

		assert(_stmStorages.empty());
		_stmStorages.resize(StmStorageBase::creators().size());
		for(size_t i(0); i<_stmStorages.size(); i++)
		{
			_stmStorages[i] = StmStorageBase::creators()[i]();
			_stmStorages[i]->startInThread(*_tcon);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////
	void ModelBase::stopInThread()
	{
		assert(_stmStorages.size() == StmStorageBase::destroyers().size());
		for(size_t i(0); i<_stmStorages.size(); i++)
		{
			StmStorageBase::destroyers()[i](_stmStorages[i]);
		}
		_stmStorages.clear();

		_tcon.reset();
	}

	//////////////////////////////////////////////////////////////////////////
	pgc::Connection ModelBase::con()
	{
		return *_tcon;
	}

}