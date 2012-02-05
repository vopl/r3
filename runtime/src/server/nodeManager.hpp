#ifndef _SERVER_NODEMANAGER_HPP_
#define _SERVER_NODEMANAGER_HPP_

#include "server/inode.hpp"
#include "server/itask.hpp"
#include "server/iservice.hpp"
#include "server/endpoint.hpp"
#include <boost/enable_shared_from_this.hpp>

namespace server
{
	using namespace boost;

	//////////////////////////////////////////////////////////////////////////
	class NodeManager
		: public INodeManager
		, public enable_shared_from_this<NodeManager>
	{
		typedef std::map<TServerSid, ISessionPtr> TMSessions;
		typedef std::map<TEndpoint, INodePtr> TMNodes;
		typedef std::map<INodePtr, TEndpoint> TMNodesBack;

		TMNodes		_nodes;
		TMNodesBack	_nodesBack;

		IServerPtr	_server;

		mutex		_mtx;

	private:
		ITaskPtr findTask(const server::TEndpoint &endpoint);
		void onReceive(const boost::system::error_code &ec, const net::SPacket &p, ISessionPtr session);

	private:
		void addNode(INodePtr node, const server::TEndpoint &base);
		void delNode(INodePtr node, const server::TEndpoint &base);


	public:
		NodeManager();
		virtual ~NodeManager();

		virtual void setServer(IServerPtr server);
		virtual IServerPtr getServer();

		virtual void addSession(ISessionPtr session);
		virtual void delSession(ISessionPtr session);

		virtual void addNode(INodePtr node);
		virtual void delNode(INodePtr node);
		virtual void delNodes();

		virtual async::Future<error_code> send(
			INodePtr node,
			ISessionPtr session,
			const client::TEndpoint &endpoint,
			utils::VariantPtr data);
	};
	typedef boost::shared_ptr<NodeManager> NodeManagerPtr;

	//////////////////////////////////////////////////////////////////////////
	PLUMA_INHERIT_PROVIDER(NodeManager, INodeManager);

}
#endif
