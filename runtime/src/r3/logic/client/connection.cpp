#include "StdAfx.h"
#include "connection.h"

namespace r3
{
	namespace logic
	{
		Connection::Connection(QWidget *parent)
			: QWidget(parent)
			, r3::protocol::client::Connection(0, NULL)
		{
			ui.setupUi(this);
		}

		Connection::~Connection()
		{

		}
	}
}
