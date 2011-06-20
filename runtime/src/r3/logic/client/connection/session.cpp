#include "StdAfx.h"
#include "session.hpp"

namespace r3
{
	namespace logic
	{
		namespace client
		{

			Connection::Session::Session(ContextId id, r3::logic::client::Connection *parent)
				: QWidget(parent)
				, r3::protocol::client::Connection::Session(id, parent)
			{
				ui.setupUi(this);
			}

			Connection::Session::~Session()
			{

			}
		}
	}
}
