#ifndef _SERVER_INODEMANAGER_HPP_
#define _SERVER_INODEMANAGER_HPP_

#include "server/isession.hpp"
#include "client/endpoint.hpp"
#include "async/future.hpp"
#include "pluma/pluma.hpp"

namespace server
{
	//////////////////////////////////////////////////////////////////////////
	struct IServer;
	typedef boost::shared_ptr<IServer> IServerPtr;

	//////////////////////////////////////////////////////////////////////////
	struct INode;
	typedef boost::shared_ptr<INode> INodePtr;

	//////////////////////////////////////////////////////////////////////////
	struct INodeManager
	{
		virtual ~INodeManager(){}

		virtual void setServer(IServerPtr server) =0;
		virtual IServerPtr getServer() =0;

		virtual void addSession(ISessionPtr session) =0;
		virtual void delSession(ISessionPtr session) =0;

		virtual void addNode(INodePtr node) =0;
		virtual void delNode(INodePtr node) =0;
		virtual void delNodes() =0;

		virtual async::Future<boost::system::error_code> send(
			INodePtr node,
			ISessionPtr session,
			const client::TEndpoint &endpoint,
			utils::VariantPtr data) =0;

	};
	typedef boost::shared_ptr<INodeManager> INodeManagerPtr;

	//////////////////////////////////////////////////////////////////////////
	PLUMA_PROVIDER_HEADER(INodeManager, 1, 1);

}
#endif
