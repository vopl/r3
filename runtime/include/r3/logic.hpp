#ifndef _R3_LOGIC_HPP_
#define _R3_LOGIC_HPP_


namespace r3
{

	/////////////////////////////////////////////////
	template <class ProtocolContext>
	struct Logic
	{
		typedef class Context
			: public ProtocolContext
		{
		public:
			Context()
				: ProtocolContext(0, NULL)
			{

			}

		} Context;
	};
}

#endif
