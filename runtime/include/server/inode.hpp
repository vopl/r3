#ifndef _SERVER_INODE_HPP_
#define _SERVER_INODE_HPP_

#include "utils/variant.hpp"
#include "server/iright.hpp"
#include "server/inodeManager.hpp"
#include "pluma/pluma.hpp"

namespace server
{
	//////////////////////////////////////////////////////////////////////////
	enum ENodeFlags
	{
		enfNull		= 0x0,
		enfService	= 0x1,
		enfTask		= 0x2,
	};

	//////////////////////////////////////////////////////////////////////////
	struct INode;
	typedef boost::shared_ptr<INode> INodePtr;

	//////////////////////////////////////////////////////////////////////////
	struct ITask;
	typedef boost::shared_ptr<ITask> ITaskPtr;

	//////////////////////////////////////////////////////////////////////////
	struct IService;
	typedef boost::shared_ptr<IService> IServicePtr;

	//////////////////////////////////////////////////////////////////////////
	struct INode
	{
		virtual ~INode(){}

		/// описательны€ информаци€ о ноде
		/*
			{
				description => #string,
			}
		*/
		virtual const utils::Variant &getMeta() =0;

		virtual const std::string &getId() =0;
		virtual boost::uint32_t getFlags() =0;
		virtual const std::vector<INodePtr> &getChilds() =0;
		virtual const std::vector<IRightPtr> &getRights() =0;

		virtual ITaskPtr getTask() =0;
		virtual IServicePtr getService() =0;

		virtual void onManagerAdd(INodeManagerPtr manager) =0;
		virtual void onManagerDel(INodeManagerPtr manager) =0;

	};

	//////////////////////////////////////////////////////////////////////////
	PLUMA_PROVIDER_HEADER(INode, 1, 1);
}
#endif
