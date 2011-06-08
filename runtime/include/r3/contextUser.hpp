#ifndef _R3_CONTEXTUSER_HPP_
#define _R3_CONTEXTUSER_HPP_


namespace r3
{

	/////////////////////////////////////////////////
	template <class Context>
	class ContextUserBase
	{
	public:
		typedef char State;

		static void create(Context *ctx)
		{
			//null
		}
		static void destroy(Context *ctx)
		{
			//null
		}


		static void handlePre(Context *ctx, ...)
		{
			//null
		}

		template <class Event>
		static void handle(Context *ctx, const Event &evt)
		{
			//typeid(evt).name();
			assert(!"default handle impl");
		}

		static void handlePost(Context *ctx, ...)
		{
			//ctx->destroy();
		}
	};

	/////////////////////////////////////////////////
	template <class Context>
	class ContextUser
		: public ContextUserBase<Context>
	{
		//по дефолту все из базы
	};
}

#endif
