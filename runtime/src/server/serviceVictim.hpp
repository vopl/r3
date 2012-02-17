#ifndef _SERVER_SERVICEVICTIM_HPP_
#define _SERVER_SERVICEVICTIM_HPP_

#include "server/nodeBase.hpp"
#include "pgc/connection.hpp"
#include "pgc/db.hpp"

namespace server
{
	using namespace boost;

	//////////////////////////////////////////////////////////////////////////
	class ServiceVictim
		: public NodeBase<ServiceVictim, false, true>
	{
		typedef NodeBase<ServiceVictim, false, true> Base;
		pluma::Pluma *_pluma;

		pgc::Db _db;

		void onResult(pgc::Result r);
		void connectionLoop1();
		void syncPgs();

	public:
		ServiceVictim();
		~ServiceVictim();

	public://INode
		virtual void onManagerAdd(INodeManagerPtr manager);
		virtual void onManagerDel(INodeManagerPtr manager);

// 	public://ITask
// 		virtual void call(
// 			INodeManagerPtr manager,
// 			ISessionPtr session,
// 			const client::TEndpoint &endpoint,
// 			utils::VariantPtr data);
	};
	typedef boost::shared_ptr<ServiceVictim> ServiceVictimPtr;

	//////////////////////////////////////////////////////////////////////////
	PLUMA_INHERIT_PROVIDER(ServiceVictim, INode)
}
#endif
