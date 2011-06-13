#ifndef _R3_CONTEXTBASE_HPP_
#define _R3_CONTEXTBASE_HPP_


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
	};

	//////////////////////////////////////////////////////////////////////////
	struct Event_ping:EventBase
	{
		static const TypeId tid=31;
		Event_ping():EventBase(tid){}
	};
	struct Event_pong:EventBase
	{
		static const TypeId tid=32;
		Event_pong():EventBase(tid){}
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
		void handle(const Event &evt)
		{

		}
		template<> void handle(const Event_ping &evt)
		{

		}
		void handle(const Event_pong &evt)
		{

		}
		void handle(const Event_destroy &evt)
		{

		}


	protected:
		ContextId _id;
		Parent *_parent;

	protected:
		ContextBase(ContextId id, Parent *parent);

	protected:

		template <class ContextChild>
		ContextId createImpl(std::map<ContextId, ContextChild> &map_childs, ContextId id);

		template <class ContextChild>
		void destroyImpl(std::map<ContextId, ContextChild> &map_childs, ContextId id);

		template <class ContextChild>
		void dispathImpl(std::map<ContextId, ContextChild> &map_childs, ContextId id, Path p, const EventBase *evt);

		template <class Event>
		void handleImpl(const Event *evt);

		template <class Event>
		void fireImpl(const Event *evt);
	};

	//////////////////////////////////////////////////////////////////////////
	template <class Context, class Parent>
	void ContextBase<Context, Parent>::destroy()
	{
		assert(_parent);
		if(_parent)
		{
			_parent->destroy(Context::tid, _id);
		}
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
	void ContextBase<Context, Parent>::dispathImpl(std::map<ContextId, ContextChild> &map_childs, ContextId id, Path p, const EventBase *evt)
	{
		assert(!"not impl");
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Context, class Parent>
	template <class Event>
	void ContextBase<Context, Parent>::handleImpl(const Event *evt)
	{
		ContextUser<Context>::User *self = (ContextUser<Context>::User *)this;
 		//self->handlePre((Context *)this, evt);
 		self->handle(*evt);
 		//self->handlePost((Context *)this, evt);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Context, class Parent>
	template <class Event>
	void ContextBase<Context, Parent>::fireImpl(const Event *evt)
	{
		assert(!"not impl");
	}

}

#endif
