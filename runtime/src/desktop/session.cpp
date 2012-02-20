#include "pch.hpp"
#include "session.hpp"
#include "client.hpp"

//////////////////////////////////////////////////////////////////////////
void Session::onState(QPointer<Session> thisKeeper, const boost::system::error_code &ec, size_t numChannels)
{
	emit stateChanged(new ErrorCode(ec), (quint32)numChannels);
}

//////////////////////////////////////////////////////////////////////////
Client *Session::getClient()
{
	return _client;
}

//////////////////////////////////////////////////////////////////////////
quint32 Session::getNumChannels()
{
	return (quint32)_session->getNumChannels();
}

//////////////////////////////////////////////////////////////////////////
QUuid Session::getSid()
{
	std::string str;
	utils::Variant(_session->sid()).to(str);

	return QString::fromStdString(str);
}

//////////////////////////////////////////////////////////////////////////
Session::Session(QPointer<Client> client, client::ISessionPtr session)
	: _client(client)
	, _session(session)
{
	_session->watchState(boost::bind(
		&Session::onState, 
		this,
		QPointer<Session>(this),
		_1, _2));

	_session->balance(4);

}

//////////////////////////////////////////////////////////////////////////
Session::~Session()
{
	_session->close();
}

//////////////////////////////////////////////////////////////////////////
void Session::balance(quint32 numChannels)
{
	_session->balance(numChannels);
}

//////////////////////////////////////////////////////////////////////////
void Session::close()
{
	_session->close();
}
