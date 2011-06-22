#include "StdAfx.h"
#include "session.hpp"

namespace r3
{
	namespace logic
	{
		namespace client
		{

			//////////////////////////////////////////////////////////////////////////
			Connection::Session::Session(QWidget *parent)
				: QWidget(parent)
				, r3::protocol::client::Connection::Session()
			{
				ui.setupUi(this);

				connect(ui.pushButton, SIGNAL(clicked()),
					this, SLOT(onLogout()));
			}

			//////////////////////////////////////////////////////////////////////////
			Connection::Session::~Session()
			{

			}

			//////////////////////////////////////////////////////////////////////////
			void Connection::Session::handle(const Event_shutdown &evt)
			{
				doShutdown();
				BaseType::handle(evt);
			}
			//////////////////////////////////////////////////////////////////////////
			void Connection::Session::handle(const Event_logout &evt)
			{
				doShutdown();
				shutdown();
			}

			//////////////////////////////////////////////////////////////////////////
			void Connection::Session::onBlock()
			{

			}

			//////////////////////////////////////////////////////////////////////////
			void Connection::Session::onLogout()
			{
				doShutdown();
				shutdown();
			}

		}
	}
}
