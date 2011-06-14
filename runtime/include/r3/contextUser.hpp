#ifndef _R3_CONTEXTUSER_HPP_
#define _R3_CONTEXTUSER_HPP_


namespace r3
{

	/////////////////////////////////////////////////
	template <class Context>
	struct ContextUser
	{
		typedef class User
			: public Context
		{
		public:
            User()
                : Context(0, NULL)
            {

            }

		} User;
	};
}

#endif
