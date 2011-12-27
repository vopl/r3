#include "pch.h"
#include "agent.hpp"
#include "session.hpp"

namespace client
{
	//////////////////////////////////////////////////////////////////////////
	void Agent::onReceive(const server::TEndpoint &endpoint, utils::VariantPtr data)
	{
		mutex::scoped_lock sl(_mtx);
		if(!_receivesWait.empty())
		{
			_receivesWait.front()(error_code(), endpoint, data);
			_receivesWait.erase(_receivesWait.begin());
			return;
		}

		if(!_closed)
		{
			Result3<error_code, server::TEndpoint, utils::VariantPtr> res;
			res(error_code(), endpoint, data);
			_receivesReady.push_back(res);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void Agent::close()
	{
		mutex::scoped_lock sl(_mtx);
		_closed = true;
		BOOST_FOREACH(TReceiveResult &res, _receivesWait)
		{
			res(make_error_code(errc::operation_canceled), server::TEndpoint(), utils::VariantPtr());
		}
		_receivesWait.clear();
		assert(_receivesReady.empty());
	}


	//////////////////////////////////////////////////////////////////////////
	Agent::Agent(SessionPtr session, TEndpoint	endpoint)
		: _session(session)
		, _endpoint(endpoint)
		, _closed(false)
	{

	}

	//////////////////////////////////////////////////////////////////////////
	Agent::~Agent()
	{
		_session->freeAgent(_endpoint);
		mutex::scoped_lock sl(_mtx);
		BOOST_FOREACH(TReceiveResult &res, _receivesWait)
		{
			res(make_error_code(errc::operation_canceled), server::TEndpoint(), utils::VariantPtr());
		}
	}

	//////////////////////////////////////////////////////////////////////////
	Result<error_code> Agent::send(
		const server::TEndpoint &endpoint,
		utils::VariantPtr data)
	{
		utils::Variant v;
		utils::Variant::MapStringVariant &m = v.as<utils::Variant::MapStringVariant>(true);
		m["server::endpoint"] = endpoint;
		m["client::endpoint"] = _endpoint;
		m["data"] = data;
		return _session->send(v);
	}

	//////////////////////////////////////////////////////////////////////////
	Result3<error_code, server::TEndpoint, utils::VariantPtr> Agent::receive()
	{
		mutex::scoped_lock sl(_mtx);

		Result3<error_code, server::TEndpoint, utils::VariantPtr> res;
		if(_closed)
		{
			res(make_error_code(errc::operation_canceled), server::TEndpoint(), utils::VariantPtr());
			return res;
		}

		if(!_receivesReady.empty())
		{
			res = _receivesReady.front();
			_receivesReady.erase(_receivesReady.begin());
			return res;
		}
		_receivesWait.push_back(res);
		return res;
	}

	//////////////////////////////////////////////////////////////////////////
	ISessionPtr Agent::getSession()
	{
		return _session;
	}


}