#include "pch.h"
#include "networkReply.hpp"
#include "async/service.hpp"

namespace client
{
	namespace qt
	{
		using namespace async;
		using namespace boost;
		using namespace boost::system;

		//////////////////////////////////////////////////////////////////////////
		void NetworkReply::abort()
		{
			//
		}

		//////////////////////////////////////////////////////////////////////////
		qint64 NetworkReply::bytesAvailable() const
		{
			return 
				(qint64)_data->as<utils::Variant::VectorChar>().size() - 
				_readPos;
		}

		//////////////////////////////////////////////////////////////////////////
		bool NetworkReply::isSequential() const
		{
			return true;
		}

		//////////////////////////////////////////////////////////////////////////
		qint64 NetworkReply::readData(char *data, qint64 maxSize)
		{
			utils::Variant::VectorChar &vc = _data->as<utils::Variant::VectorChar>();
			if (_readPos >= vc.size())
			{
				return -1;
			}

			qint64 number = qMin(maxSize, (qint64)(vc.size() - _readPos));
			memcpy(data, &vc[_readPos], number);
			_readPos += number;

			return number;
		}

		//////////////////////////////////////////////////////////////////////////
		void NetworkReply::processSend(Future<error_code> res)
		{
			res.wait();
			assert(!res.data());
		}

		//////////////////////////////////////////////////////////////////////////
		void NetworkReply::onReceive(server::TEndpoint endpoint, utils::VariantPtr data)
		{
			if(data->is<utils::Variant::VectorChar>())
			{
				_data = data;
				_readPos = 0;
				open(ReadOnly | Unbuffered);
				setHeader(QNetworkRequest::ContentLengthHeader, QVariant((qint64)data->as<utils::Variant::VectorChar>().size()));

				emit readyRead();
				emit finished();
			}
			else
			{
				_data.reset();
				_readPos = 0;
				setError(ContentNotFoundError, QString("notFound"));
				emit error(ContentNotFoundError);
				emit finished();
			}
		}

		//////////////////////////////////////////////////////////////////////////
		NetworkReply::NetworkReply(QObject *parent, QUrl url, ISessionPtr session)
			: _readPos(0)
		{
			_agent = session->allocAgent();
			assert(_agent);
			utils::VariantPtr v(new utils::Variant);
			utils::Variant::MapStringVariant &m = v->as<utils::Variant::MapStringVariant>(true);
			m["cmd"] = "get";
			m["path"] = url.path().toUtf8().constData();

			server::TEndpoint endpoint = url.host().toUtf8().constData();

			Future<error_code> sres = _agent->send(endpoint, v);
			spawn(bind(&NetworkReply::processSend, this, sres));

			_agent->listen(bind(&NetworkReply::onReceive, this,  _1, _2));
		}

		//////////////////////////////////////////////////////////////////////////
		NetworkReply::~NetworkReply()
		{
		}
	}
}
