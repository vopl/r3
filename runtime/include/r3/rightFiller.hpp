#ifndef _R3_RIGHTFILLER_HPP_
#define _R3_RIGHTFILLER_HPP_

namespace r3
{
	//////////////////////////////////////////////////////////////////////////
	typedef boost::int32_t RightId;
	//////////////////////////////////////////////////////////////////////////
	enum ERightValue
	{
		erv_null,
		erv_grant,
		erv_deny,
	};

	//////////////////////////////////////////////////////////////////////////
	template <bool isServer>
	class RightFiller
	{
	public:
		static RightFiller *instance()
		{
			static RightFiller rf;
			return &rf;
		}
		template <class Context>
		void fillRights(Context *, const std::map<RightId, ERightValue> &)
		{
		}
	};

	//////////////////////////////////////////////////////////////////////////
	template <>
	class RightFiller<true>
	{
		static boost::thread_specific_ptr<RightFiller<true> > _instance;
		boost::int64_t _user_id;
	public:
		RightFiller(boost::int64_t user_id)
			: _user_id(user_id)
		{
		}

		static RightFiller *instance()
		{
			return _instance.get();
		}
		static void setInstance(RightFiller *rf)
		{
			return _instance.reset(rf);
		}

		template <class Context>
		void fillRights(Context *ctx, const std::map<RightId, ERightValue> &rights)
		{
			//enum rights from ctx
			//select right values for user_id
		}
	};
}

#endif
