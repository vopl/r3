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
	struct Event_destroy:EventBase
	{
		static const TypeId tid=33;
		Event_destroy():EventBase(tid){}
	};


	/////////////////////////////////////////////////
	template <class Context, class Parent>
	class ContextBase
	{
	public:
		void destroy();

		template <class Event>
		void handle(const Event &evt);

		void handle(const Event_ping &evt);
		void handle(const Event_pong &evt);
		void handle(const Event_destroy &evt);

		template <class Event>
		void fire(const Event &evt);

	protected:
		ContextId _id;
		Parent *_parent;

	protected:
		ContextBase(ContextId id, Parent *parent);

	public:

		template <class ContextChild>
		ContextId createImpl(std::map<ContextId, ContextChild> &map_childs, ContextId id);

		template <class ContextChild>
		void destroyImpl(std::map<ContextId, ContextChild> &map_childs, ContextId id);

		template <class ContextChild>
		void dispatchImpl(std::map<ContextId, ContextChild> &map_childs, ContextId id, Path p, const EventBase *evt);

		template <class Event>
		void handleImpl(const Event *evt);

		void fireImpl(const Path &cpi, const EventBase *evt);

	private:
	};

	//////////////////////////////////////////////////////////////////////////
	//помогалка для разделения рекурсивных по иерархии действий между узлами и корнем
	template <class Parent>
	struct DoWithParent
	{
		template <class Event>
		static void fire(Parent *p, const Event &evt)
		{
			p->fireImpl(Path(), &evt);
		}
	};
	//////////////////////////////////////////////////////////////////////////
	template <>
	struct DoWithParent<void>
	{
		template <class Event>
		static void fire(void *p, const Event &evt)
		{
			assert(!"unimplemented method");
		}
	};

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
		fire(Event_pong(evt));
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
		DoWithParent<Parent>::fire(_parent, evt);
	}


	//////////////////////////////////////////////////////////////////////////
	template <class Context, class Parent>
	void ContextBase<Context, Parent>::handle(const Event_destroy &evt)
	{
		destroy();
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
	ContextId ContextBase<Context, Parent>::createImpl(std::map<ContextId, ContextChild> &map_childs, ContextId id)
	{
		assert(!"not impl");
		return id;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Context, class Parent>
	template <class ContextChild>
	void ContextBase<Context, Parent>::destroyImpl(std::map<ContextId, ContextChild> &map_childs, ContextId id)
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
		assert(!"not impl");
	}

}

#endif
