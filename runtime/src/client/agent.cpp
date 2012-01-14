#include "pch.h"
#include "agent.hpp"
#include "session.hpp"

namespace client
{
	//////////////////////////////////////////////////////////////////////////
	void Agent::onReceive(const server::TEndpoint &endpoint, utils::VariantPtr data)
	{
		boost::function<void(server::TEndpoint, utils::VariantPtr)> onReceive;

		{
			mutex::scoped_lock sl(_mtx);
			onReceive = _onReceive;
		}

		if(onReceive)
		{
			_onReceive(endpoint, data);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void Agent::close()
	{
		mutex::scoped_lock sl(_mtx);
		_closed = true;
		_onReceive.swap(boost::function<void(server::TEndpoint, utils::VariantPtr)>());
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
		_onReceive.swap(boost::function<void(server::TEndpoint, utils::VariantPtr)>());
	}

	//////////////////////////////////////////////////////////////////////////
	Future<error_code> Agent::send(
		const server::TEndpoint &endpoint,
		utils::VariantPtr data)
	{
		utils::Variant v;

		{
			mutex::scoped_lock sl(_mtx);
			utils::Variant::MapStringVariant &m = v.as<utils::Variant::MapStringVariant>(true);
			m["server::endpoint"] = endpoint;
			m["client::endpoint"] = _endpoint;
			m["data"] = data;
		}
		return _session->send(v);
	}

	//////////////////////////////////////////////////////////////////////////
	void Agent::listen(const boost::function<void(server::TEndpoint, utils::VariantPtr)> onReceive)
	{
		mutex::scoped_lock sl(_mtx);
		_onReceive = onReceive;
	}


	//////////////////////////////////////////////////////////////////////////
	ISessionPtr Agent::getSession()
	{
		return _session;
	}


}