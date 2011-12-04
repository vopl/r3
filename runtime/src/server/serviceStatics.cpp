#include "pch.h"
#include "serviceStatics.hpp"
#include "server/iserviceHub.hpp"

namespace server
{
	//////////////////////////////////////////////////////////////////////////
	const TEndpoint ServiceStatics::_endpoint = "statics";

	//////////////////////////////////////////////////////////////////////////
	void ServiceStatics::onSendOk()
	{
		//
	}
	
	//////////////////////////////////////////////////////////////////////////
	void ServiceStatics::onSendFail(system::error_code ec)
	{
		//
	}

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
			hub->send(shared_from_this(), session, endpoint, data, 
				bind(&ServiceStatics::onSendOk, shared_from_this()),
				bind(&ServiceStatics::onSendFail, shared_from_this(), _1));
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
			hub->send(shared_from_this(), session, endpoint, data, 
				bind(&ServiceStatics::onSendOk, shared_from_this()),
				bind(&ServiceStatics::onSendFail, shared_from_this(), _1));
			return;
		}

		filesystem::path bpath = _root / path.as<utils::Variant::String>();

		if(!filesystem::is_regular_file(bpath))
		{
			std::cerr<<"statics not found: "<<path.as<utils::Variant::String>()<<std::endl;
			data.reset(new utils::Variant);
			utils::Variant::MapStringVariant &m = data->as<utils::Variant::MapStringVariant>(true);
			m["error"] = "notFound";
			hub->send(shared_from_this(), session, endpoint, data, 
				bind(&ServiceStatics::onSendOk, shared_from_this()),
				bind(&ServiceStatics::onSendFail, shared_from_this(), _1));
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
				std::cerr<<"statics not found(corrupted?): "<<path.as<utils::Variant::String>()<<std::endl;
				data.reset(new utils::Variant);
				utils::Variant::MapStringVariant &m = data->as<utils::Variant::MapStringVariant>(true);
				m["error"] = "notFound";
				hub->send(shared_from_this(), session, endpoint, data, 
					bind(&ServiceStatics::onSendOk, shared_from_this()),
					bind(&ServiceStatics::onSendFail, shared_from_this(), _1));
				return;
			}
		}

		//std::cerr<<"statics: "<<path.as<utils::Variant::String>()<<std::endl;
		hub->send(shared_from_this(), session, endpoint, data, 
			bind(&ServiceStatics::onSendOk, shared_from_this()),
			bind(&ServiceStatics::onSendFail, shared_from_this(), _1));
	}
}
