#ifndef _R3_RIGHTEVALUATOR_HPP_
#define _R3_RIGHTEVALUATOR_HPP_

namespace r3
{
	//////////////////////////////////////////////////////////////////////////
	enum ERightValue
	{
		erv_null,
		erv_grant,
		erv_deny,
	};

	//////////////////////////////////////////////////////////////////////////
	class RightEvaluator
	{
	public:
		template <class Context, class RightId>
		ERightValue evalRight(Context *ctx, const RightId &id)
		{
			return erv_null;
		}
	};
}

#endif
