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
}

#endif
