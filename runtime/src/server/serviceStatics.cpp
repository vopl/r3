#include "pch.h"

#undef LOG_NAME
#define LOG_NAME server_statics
#include "log/client.hpp"

#include "serviceStatics.hpp"
#include "server/iserviceHub.hpp"

namespace server
{
	//////////////////////////////////////////////////////////////////////////
	const TEndpoint ServiceStatics::_endpoint = "statics";

	//////////////////////////////////////////////////////////////////////////
	ServiceStatics::ServiceStatics()
		: _root("../statics")
	{

	}

	//////////////////////////////////////////////////////////////////////////
	ServiceStatics::~ServiceStatics()
	{

	}

	//////////////////////////////////////////////////////////////////////////
	const TEndpoint &ServiceStatics::getEndpoint()
	{
		return _endpoint;
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceStatics::onHubAdd(IServiceHubPtr hub)
	{
		//
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceStatics::onHubDel(IServiceHubPtr hub)
	{
		//
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceStatics::onSessionAdd(ISessionPtr session)
	{
		//
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceStatics::onSessionDel(ISessionPtr session)
	{
		//
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceStatics::onReceive(
		IServiceHubPtr hub,
		ISessionPtr session,
		const client::TEndpoint &endpoint,
		utils::VariantPtr data)
	{
		if(!data->is<utils::Variant::MapStringVariant>())
		{
			data.reset(new utils::Variant);
			utils::Variant::MapStringVariant &m = data->as<utils::Variant::MapStringVariant>(true);
			m["error"] = "badRequest";
			hub->send(shared_from_this(), session, endpoint, data);
			return;
		}

		utils::Variant::MapStringVariant &m = data->as<utils::Variant::MapStringVariant>();
		utils::Variant cmd = m["cmd"];
		utils::Variant path = m["path"];

		if(
			!cmd.is<utils::Variant::String>() || 
			!path.is<utils::Variant::String>() ||
			cmd.as<utils::Variant::String>() != "get")
		{
			data.reset(new utils::Variant);
			utils::Variant::MapStringVariant &m = data->as<utils::Variant::MapStringVariant>(true);
			m["error"] = "badRequest";
			hub->send(shared_from_this(), session, endpoint, data);
			return;
		}

		filesystem::path bpath = _root / path.as<utils::Variant::String>();

		if(!filesystem::is_regular_file(bpath))
		{
			ELOG("not found "<<path.as<utils::Variant::String>());
			data.reset(new utils::Variant);
			utils::Variant::MapStringVariant &m = data->as<utils::Variant::MapStringVariant>(true);
			m["error"] = "notFound";
			hub->send(shared_from_this(), session, endpoint, data);
			return;
		}

		size_t size = (size_t)filesystem::file_size(bpath);
		data.reset(new utils::Variant);
		utils::Variant::VectorChar &buffer = data->as<utils::Variant::VectorChar>(true);
		buffer.resize(size);

		if(size)
		{
			std::ifstream in(bpath.string().c_str(), std::ios_base::binary);
			in.read(&buffer[0], size);

			if(size != in.gcount())
			{
				ELOG("not found (corrupted?) "<<path.as<utils::Variant::String>());
				data.reset(new utils::Variant);
				utils::Variant::MapStringVariant &m = data->as<utils::Variant::MapStringVariant>(true);
				m["error"] = "notFound";
				hub->send(shared_from_this(), session, endpoint, data);
				return;
			}
		}

		ILOG("statics "<<path.as<utils::Variant::String>());
		hub->send(shared_from_this(), session, endpoint, data);
	}
}
