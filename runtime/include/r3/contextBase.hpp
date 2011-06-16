#ifndef _R3_CONTEXTBASE_HPP_
#define _R3_CONTEXTBASE_HPP_

#include "r3/logic.hpp"

namespace r3
{
	//////////////////////////////////////////////////////////////////////////
	typedef int ContextId;
	typedef int TypeId;

	//////////////////////////////////////////////////////////////////////////
	struct ContextPathItem
	{
		TypeId tid;
		ContextId id;
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

		virtual ~EventBase()
		{
		}
	};

	//////////////////////////////////////////////////////////////////////////
	struct Event_ping:EventBase
	{
		static const TypeId tid=31;
		Event_ping()
			: EventBase(tid)
			, counter(0)
		{}

		boost::uint32_t counter;
	};
	struct Event_pong:EventBase
	{
		static const TypeId tid=32;
		Event_pong(const Event_ping &ping)
			: EventBase(tid)
			, counter(ping.counter+1)
		{}
		boost::uint32_t counter;
	};
	struct Event_shutdown:EventBase
	{
		static const TypeId tid=33;
		Event_shutdown():EventBase(tid){}
	};


	/////////////////////////////////////////////////
	template <class Context, class Parent>
	class ContextBase
	{
	public:
		void shutdown();

		template <class Event>
		void handle(const Event &evt);

		void handle(const Event_ping &evt);
		void handle(const Event_pong &evt);
		void handle(const Event_shutdown &evt);

		template <class Event>
		void fire(const Event &evt);

	protected:
		ContextId _id;
		Parent *_parent;

	protected:
		ContextBase(ContextId id, Parent *parent);

	protected:
		template <class Parent>
		friend struct DoWithParent;

		template <class ContextChild>
		ContextId startupImpl(std::map<ContextId, ContextChild> &map_childs, ContextId id);

		template <class ContextChild>
		void shutdownImpl(std::map<ContextId, ContextChild> &map_childs, ContextId id);

		template <class ContextChild>
		void dispatchImpl(std::map<ContextId, ContextChild> &map_childs, ContextId id, Path p, const EventBase *evt);

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
			Logic<Context>::Context *lself = (Logic<Context>::Context *)self;
			lself->fireImpl(Path(), &evt);
		}

		template <class Context>
		static void fireImpl(Context *self, Parent *p, const Path &path, const EventBase *evt)
		{
			Logic<Parent>::Context *lp = (Logic<Parent>::Context *)p;
			Path newPath(path);
			ContextPathItem cpi = {Context::tid, self->_id};
			newPath.push_back(cpi);
			lp->fireImpl(newPath, evt);
		}

		template <class Context>
		static void shutdown(Context *self, Parent *p)
		{
			Logic<Parent>::Context *lp = (Logic<Parent>::Context *)p;
			lp->shutdown(Context::tid, self->_id);
		}
	};
	//////////////////////////////////////////////////////////////////////////
	template <>
	struct DoWithParent<void>
	{
		template <class Context, class Event>
		static void fire(Context *self, void *p, const Event &evt)
		{
			Logic<Context>::Context *lself = (Logic<Context>::Context *)self;
			lself->fireImpl(Path(), &evt);
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
		Logic<Context>::Context *lself = (Logic<Context>::Context *)this;
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
	void ContextBase<Context, Parent>::handle(const Event_shutdown &evt)
	{
		shutdown();
	}


	//////////////////////////////////////////////////////////////////////////
	template <class Context, class Parent>
	ContextBase<Context, Parent>::ContextBase(ContextId id, Parent *parent)
		: _id(id)
		, _parent(parent)
	{
	}


	//////////////////////////////////////////////////////////////////////////
	template <class Context, class Parent>
	template <class ContextChild>
	ContextId ContextBase<Context, Parent>::startupImpl(std::map<ContextId, ContextChild> &map_childs, ContextId id)
	{
		assert(!"not impl");
		return id;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Context, class Parent>
	template <class ContextChild>
	void ContextBase<Context, Parent>::shutdownImpl(std::map<ContextId, ContextChild> &map_childs, ContextId id)
	{
		assert(!"not impl");
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Context, class Parent>
	template <class ContextChild>
	void ContextBase<Context, Parent>::dispatchImpl(std::map<ContextId, ContextChild> &map_childs, ContextId id, Path p, const EventBase *evt)
	{
		assert(!"not impl");
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Context, class Parent>
	template <class Event>
	void ContextBase<Context, Parent>::handleImpl(const Event *evt)
	{
		typename Logic<Context>::Context *self = (typename Logic<Context>::Context *)this;
 		//self->handlePre((Context *)this, evt);
 		self->handle(*evt);
 		//self->handlePost((Context *)this, evt);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Context, class Parent>
	void ContextBase<Context, Parent>::fireImpl(const Path &p, const EventBase *evt)
	{
		DoWithParent<Parent>::fireImpl((Context *)this, _parent, p, evt);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Context, class Parent>
	void ContextBase<Context, Parent>::dispatchCommon(const EventBase *evt)
	{
		switch(evt->tid)
		{
		case Event_ping::tid:
			return handleImpl((const Event_ping *)evt);

		case Event_pong::tid:
			return handleImpl((const Event_pong *)evt);

		case Event_shutdown::tid:
			return handleImpl((const Event_shutdown *)evt);

		default:
			assert(0);
			throw 220;
		}
	}

}

#endif
