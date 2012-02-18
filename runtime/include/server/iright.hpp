#ifndef _SERVER_IRIGHT_HPP_
#define _SERVER_IRIGHT_HPP_

#include "server/isession.hpp"

namespace server
{
	//////////////////////////////////////////////////////////////////////////
	enum ERightValue
	{
		ervNull		=0,
		ervAllow,
		ervDeny
	};

	//////////////////////////////////////////////////////////////////////////
	struct IRight
	{
		virtual ~IRight(){}

		virtual const utils::Variant &getMeta() =0;

		virtual ERightValue evaluate(ISessionPtr session, const utils::Variant &context) =0;
	};
	typedef boost::shared_ptr<IRight> IRightPtr;
}
#endif
