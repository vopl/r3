#ifndef _SERVER_NODEBASE_HPP_
#define _SERVER_NODEBASE_HPP_

#include <boost/enable_shared_from_this.hpp>
#include "server/inode.hpp"
#include "server/itask.hpp"
#include "server/iservice.hpp"

namespace server
{
	//////////////////////////////////////////////////////////////////////////
	template <class T, bool withTask = false, bool withService = false>
	class NodeBase;

	//////////////////////////////////////////////////////////////////////////
	template <class T>
	class NodeBase<T, false, false>
		: public INode
		, public boost::enable_shared_from_this<T>
	{
	private:
		std::string				_id;

	protected:
		utils::Variant			_meta;
		std::vector<INodePtr>	_childs;
		std::vector<IRightPtr>	_rights;

	public:
		NodeBase(const std::string &id)
			: _id(id)
		{
			utils::Variant::MapStringVariant &mm = _meta.as<utils::Variant::MapStringVariant>(true);
			mm["id"] = _id;
			//mm["hasTask"] = false;
			//mm["hasService"] = false;
		}

		//////////////////////////////////////////////////////////////////////////
		virtual const utils::Variant &getMeta()
		{
			return _meta;
		}

		//////////////////////////////////////////////////////////////////////////
		virtual const std::string &getId()
		{
			return _id;
		}

		//////////////////////////////////////////////////////////////////////////
		virtual boost::uint32_t getFlags()
		{
			return enfNull;
		}

		//////////////////////////////////////////////////////////////////////////
		virtual const std::vector<INodePtr> &getChilds()
		{
			return _childs;
		}

		//////////////////////////////////////////////////////////////////////////
		virtual const std::vector<IRightPtr> &getRights()
		{
			return _rights;
		}

		//////////////////////////////////////////////////////////////////////////
		virtual ITaskPtr getTask()
		{
			return ITaskPtr();
		}

		//////////////////////////////////////////////////////////////////////////
		virtual IServicePtr getService()
		{
			return IServicePtr();
		}

		//////////////////////////////////////////////////////////////////////////
		virtual void onManagerAdd(INodeManagerPtr manager)
		{
			//nohing
		}

		//////////////////////////////////////////////////////////////////////////
		virtual void onManagerDel(INodeManagerPtr manager)
		{
			//nohing
		}

	};

	//////////////////////////////////////////////////////////////////////////
	template <class T>
	class NodeBase<T, true, false>
		: public NodeBase<T, false, false>
		, public ITask
	{
	    typedef NodeBase<T, false, false> Base;

	public:
		//////////////////////////////////////////////////////////////////////////
		NodeBase(const std::string &id)
			: Base(id)
		{
		    utils::Variant &meta = Base::_meta;
			utils::Variant::MapStringVariant &mm = meta.as<utils::Variant::MapStringVariant>();
			mm["hasTask"] = true;
		}

		//////////////////////////////////////////////////////////////////////////
		virtual void call(
			INodeManagerPtr manager,
			ISessionPtr session,
			const client::TEndpoint &endpoint,
			utils::VariantPtr data)
		{
			//nothing
		}

		//////////////////////////////////////////////////////////////////////////
		virtual boost::uint32_t getFlags()
		{
			return enfNull | enfTask;
		}

		//////////////////////////////////////////////////////////////////////////
		virtual ITaskPtr getTask()
		{
			return Base::shared_from_this();
		}
	};

	//////////////////////////////////////////////////////////////////////////
	template <class T>
	class NodeBase<T, false, true>
		: public NodeBase<T, false, false>
		, public IService
	{
	    typedef NodeBase<T, false, false> Base;

	public:
		//////////////////////////////////////////////////////////////////////////
		NodeBase(const std::string &id)
			: Base(id)
		{
		    utils::Variant &meta = Base::_meta;
			utils::Variant::MapStringVariant &mm = meta.as<utils::Variant::MapStringVariant>();
			mm["hasService"] = true;
		}

		//////////////////////////////////////////////////////////////////////////
		virtual void onSessionAdd(ISessionPtr session)
		{
			//nothing
		}

		//////////////////////////////////////////////////////////////////////////
		virtual void onSessionDel(ISessionPtr session)
		{
			//nothing
		}

		//////////////////////////////////////////////////////////////////////////
		virtual boost::uint32_t getFlags()
		{
			return enfNull | enfService;
		}

		//////////////////////////////////////////////////////////////////////////
		virtual IServicePtr getService()
		{
			return Base::shared_from_this();
		}
	};



















	//////////////////////////////////////////////////////////////////////////
	template <class T>
	class NodeBase<T, true, true>
		: public NodeBase<T, false, false>
		, public ITask
		, public IService
	{
	    typedef NodeBase<T, false, false> Base;

	public:
		//////////////////////////////////////////////////////////////////////////
		NodeBase(const std::string &id)
			: NodeBase<T, false, false>(id)
		{
		    utils::Variant &meta = Base::_meta;
			utils::Variant::MapStringVariant &mm = meta.as<utils::Variant::MapStringVariant>();
			mm["hasTask"] = true;
			mm["hasService"] = true;
		}

		//////////////////////////////////////////////////////////////////////////
		virtual void call(
			INodeManagerPtr manager,
			ISessionPtr session,
			const client::TEndpoint &endpoint,
			utils::VariantPtr data)
		{
			//nothing
		}

		//////////////////////////////////////////////////////////////////////////
		virtual void onSessionAdd(ISessionPtr session)
		{
			//nothing
		}

		//////////////////////////////////////////////////////////////////////////
		virtual void onSessionDel(ISessionPtr session)
		{
			//nothing
		}

		//////////////////////////////////////////////////////////////////////////
		virtual boost::uint32_t getFlags()
		{
			return enfNull | enfTask | enfService;
		}

		//////////////////////////////////////////////////////////////////////////
		virtual ITaskPtr getTask()
		{
			return Base::shared_from_this();
		}

		//////////////////////////////////////////////////////////////////////////
		virtual IServicePtr getService()
		{
			return Base::shared_from_this();
		}

	};
}
#endif
