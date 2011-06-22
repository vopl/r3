#ifndef _R3_CONTEXTBASE_HPP_
#define _R3_CONTEXTBASE_HPP_

#include "r3/logic.hpp"
#include <deque>
#include <map>
#include <boost/cstdint.hpp>
#include <cassert>

namespace r3
{
	//////////////////////////////////////////////////////////////////////////
	typedef boost::int32_t ContextId;
	typedef boost::int32_t TypeId;

	//////////////////////////////////////////////////////////////////////////
	struct ContextPathItem
	{
		TypeId tid;
		ContextId id;
		ContextPathItem(TypeId tid, ContextId id)
			: tid(tid)
			, id(id)
		{
		}
		ContextPathItem()
			: tid(0)
			, id(0)
		{
		}
		virtual ~ContextPathItem(){}
		template<class Archive> void serialize(Archive &ar, const unsigned int file_version);
	};

	typedef std::deque<ContextPathItem> Path;

	//////////////////////////////////////////////////////////////////////////
	struct EventBase
	{
		TypeId tid;
		EventBase(TypeId tid)
			: tid(tid)
		{
		}
		EventBase()
			: tid(0)
		{
		}

		virtual ~EventBase()
		{
		}
		template<class Archive> void serialize(Archive &ar, const unsigned int file_version);
	};

	//////////////////////////////////////////////////////////////////////////
	struct Event_ping:EventBase
	{
		static const TypeId tid=31;
		Event_ping()
			: EventBase(tid)
			, counter(0)
		{}
		template<class Archive> void serialize(Archive &ar, const unsigned int file_version);

		boost::uint32_t counter;
	};

	struct Event_pong:EventBase
	{
		static const TypeId tid=32;
		Event_pong(const Event_ping &ping)
			: EventBase(tid)
			, counter(ping.counter+1)
		{}
		Event_pong()
			: EventBase(tid)
			, counter(0)
		{}
		template<class Archive> void serialize(Archive &ar, const unsigned int file_version);

		boost::uint32_t counter;
	};

	struct Event_startup:EventBase
	{
		static const TypeId tid=33;
		Event_startup():EventBase(tid),ctid(0),cid(0){}
		Event_startup(TypeId ctid, ContextId cid):EventBase(tid),ctid(ctid),cid(cid){}

		template<class Archive> void serialize(Archive &ar, const unsigned int file_version);

		TypeId		ctid;
		ContextId	cid;
	};

	struct Event_shutdown:EventBase
	{
		static const TypeId tid=34;
		Event_shutdown():EventBase(tid){}

		template<class Archive> void serialize(Archive &ar, const unsigned int file_version);
	};


	/////////////////////////////////////////////////
	template <class Context, class Parent>
	class ContextBase
	{
	public:
		ContextId id();
		void shutdown();

		template <class Event>
		void handle(const Event &evt);

		void handle(const Event_ping &evt);
		void handle(const Event_pong &evt);
		void handle(const Event_startup &evt);
		void handle(const Event_shutdown &evt);

		template <class Event>
		void fire(const Event &evt);

	protected:
		ContextId _id;
		Parent *_parent;

	public:
		ContextBase();
		void setPlace(ContextId id, Parent *parent);

		template <class ChildContext>
		bool makeNewChild(boost::shared_ptr<ChildContext> &child, ContextId id);

	protected:
		template <class Parent>
		friend struct DoWithParent;

		template <class ContextChild_ptr>
		ContextId startupImpl(std::map<ContextId, ContextChild_ptr> &map_childs, ContextId id, ContextChild_ptr child=ContextChild_ptr());

		template <class ContextChild_ptr>
		void shutdownImpl(std::map<ContextId, ContextChild_ptr> &map_childs, ContextId id);

		template <class ContextChild_ptr>
		void dispatchImpl(std::map<ContextId, ContextChild_ptr> &map_childs, ContextId id, Path p, const EventBase *evt);

		template <class Event>
		void handleImpl(const Event *evt);

		void fireImpl(const Path &cpi, const EventBase *evt);

		void dispatchCommon(const EventBase *evt);

	private:
	};

	//////////////////////////////////////////////////////////////////////////
	//помогалка для разделения рекурсивных по иерархии действий между узлами и корнем
	template <class Parent>
	struct DoWithParent
	{
		template <class Context, class Event>
		static void fire(Context *self, Parent *p, const Event &evt)
		{
			if(self)
			{
				Logic<Context>::Context *lself = static_cast<Logic<Context>::Context *>(self);
				lself->fireImpl(Path(), &evt);
			}
		}

		template <class Context>
		static void fireImpl(Context *self, Parent *p, const Path &path, const EventBase *evt)
		{
			if(p)
			{
				Logic<Parent>::Context *lp = static_cast<Logic<Parent>::Context *>(p);
				Path newPath(path);
				ContextPathItem cpi(Context::tid, self->_id);
				newPath.push_back(cpi);
				lp->fireImpl(newPath, evt);
			}
		}

		template <class Context>
		static void shutdown(Context *self, Parent *p)
		{
			if(p)
			{
				Logic<Parent>::Context *lp = static_cast<Logic<Parent>::Context *>(p);
				lp->shutdown(Context::tid, self->_id);
			}
		}
	};
	//////////////////////////////////////////////////////////////////////////
	template <>
	struct DoWithParent<void>
	{
		template <class Context, class Event>
		static void fire(Context *self, void *p, const Event &evt)
		{
			if(self)
			{
				Logic<Context>::Context *lself = static_cast<Logic<Context>::Context *>(self);
				lself->fireImpl(Path(), &evt);
			}
		}
		template <class Context>
		static void fireImpl(Context *self, void *p, const Path &path, const EventBase *evt)
		{
			assert(!"unimplemented method");
		}
		template <class Context>
		static void shutdown(Context *self, void *p)
		{
			assert(!"unimplemented method");
		}
	};

	//////////////////////////////////////////////////////////////////////////
	template <class Context, class Parent>
	ContextId ContextBase<Context, Parent>::id()
	{
		return _id;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Context, class Parent>
	void ContextBase<Context, Parent>::shutdown()
	{
		DoWithParent<Parent>::shutdown((Context *)this, _parent);
	}


	//////////////////////////////////////////////////////////////////////////
	template <class Context, class Parent>
	template <class Event>
	void ContextBase<Context, Parent>::handle(const Event &evt)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Context, class Parent>
	void ContextBase<Context, Parent>::handle(const Event_ping &evt)
	{
		Logic<Context>::Context *lself = static_cast<Logic<Context>::Context *>(this);
		lself->fire(Event_pong(evt));
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Context, class Parent>
	void ContextBase<Context, Parent>::handle(const Event_pong &evt)
	{
		//ignore
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Context, class Parent>
	template <class Event>
	void ContextBase<Context, Parent>::fire(const Event &evt)
	{
		DoWithParent<Parent>::fire((Context *)this, _parent, evt);
	}


	//////////////////////////////////////////////////////////////////////////
	template <class Context, class Parent>
	void ContextBase<Context, Parent>::handle(const Event_startup &evt)
	{
		static_cast<Context *>(this)->startup(evt.ctid, evt.cid);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Context, class Parent>
	void ContextBase<Context, Parent>::handle(const Event_shutdown &evt)
	{
		shutdown();
	}


	//////////////////////////////////////////////////////////////////////////
	template <class Context, class Parent>
	ContextBase<Context, Parent>::ContextBase()
		: _id(0)
		, _parent(NULL)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Context, class Parent>
	void ContextBase<Context, Parent>::setPlace(ContextId id, Parent *parent)
	{
		_id = id;
		_parent = parent;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Context, class Parent>
	template <class ChildContext>
	bool ContextBase<Context, Parent>::makeNewChild(boost::shared_ptr<ChildContext> &child, ContextId id)
	{
		
		child.reset(new Logic<ChildContext>::Context);
		return false;
	}


	//////////////////////////////////////////////////////////////////////////
	template <class Context, class Parent>
	template <class ContextChild_ptr>
	ContextId ContextBase<Context, Parent>::startupImpl(std::map<ContextId, ContextChild_ptr> &map_childs, ContextId id, ContextChild_ptr child)
	{
		if(map_childs.end() != map_childs.find(id))
		{
			return id;
		}

		if(!child)
		{
			Logic<Context>::Context *lself = static_cast<Logic<Context>::Context *>(this);
			if(!lself->makeNewChild(child, id) || !child)
			{
				return 0;
			}
		}

		child->setPlace(id, static_cast<Context *>(this));

		map_childs[id] = child;
		fire(Event_startup(ContextChild_ptr::value_type::tid, id));
		return id;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Context, class Parent>
	template <class ContextChild_ptr>
	void ContextBase<Context, Parent>::shutdownImpl(std::map<ContextId, ContextChild_ptr> &map_childs, ContextId id)
	{
		std::map<ContextId, ContextChild_ptr>::iterator iter = map_childs.find(id);
		if(map_childs.end() == iter)
		{
			return;
		}
		ContextChild_ptr child = iter->second;
		child->fire(Event_shutdown());
		child->setPlace(0, NULL);
		map_childs.erase(iter);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Context, class Parent>
	template <class ContextChild_ptr>
	void ContextBase<Context, Parent>::dispatchImpl(std::map<ContextId, ContextChild_ptr> &map_childs, ContextId id, Path p, const EventBase *evt)
	{
		std::map<ContextId, ContextChild_ptr>::iterator iter = map_childs.find(id);
		if(map_childs.end() == iter)
		{
			static_cast<Context *>(this)->shutdown(ContextChild_ptr::value_type::tid, id);
			return;
		}
		iter->second->dispatch(p, evt);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Context, class Parent>
	template <class Event>
	void ContextBase<Context, Parent>::handleImpl(const Event *evt)
	{
		typename Logic<Context>::Context *self = static_cast<typename Logic<Context>::Context *>(this);
 		//self->handlePre((Context *)this, evt);
 		self->handle(*evt);
 		//self->handlePost((Context *)this, evt);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Context, class Parent>
	void ContextBase<Context, Parent>::fireImpl(const Path &p, const EventBase *evt)
	{
		DoWithParent<Parent>::fireImpl(static_cast<Context *>(this), _parent, p, evt);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Context, class Parent>
	void ContextBase<Context, Parent>::dispatchCommon(const EventBase *evt)
	{
		switch(evt->tid)
		{
		case Event_ping::tid:
			return handleImpl(static_cast<const Event_ping *>(evt));

		case Event_pong::tid:
			return handleImpl(static_cast<const Event_pong *>(evt));

		case Event_startup::tid:
			return handleImpl(static_cast<const Event_startup *>(evt));

		case Event_shutdown::tid:
			return handleImpl(static_cast<const Event_shutdown *>(evt));

		default:
			assert(0);
			throw 220;
		}
	}

}

// BOOST_CLASS_EXPORT(r3::EventBase);
// BOOST_CLASS_EXPORT(r3::Event_ping);
// BOOST_CLASS_EXPORT(r3::Event_pong);
// BOOST_CLASS_EXPORT(r3::Event_shutdown);


#endif
