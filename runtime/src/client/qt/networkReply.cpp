#include "pch.h"
#include "networkReply.hpp"

namespace client
{
	namespace qt
	{
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

			qint64 number = qMin(maxSize, (qint64)vc.size() - _readPos);
			memcpy(data, &vc[_readPos], number);
			_readPos += number;

			return number;
		}

		//////////////////////////////////////////////////////////////////////////
		void NetworkReply::onReceive(
			IAgentHubPtr hub,
			const server::TEndpoint &endpoint,
			utils::VariantPtr data)
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
		NetworkReply::NetworkReply(QObject *parent, QUrl url)
			: _readPos(0)
		{
			utils::VariantPtr v(new utils::Variant);
			utils::Variant::MapStringVariant &m = v->as<utils::Variant::MapStringVariant>(true);
			m["cmd"] = "get";
			m["path"] = url.path().toUtf8().constData();

			send(url.host().toUtf8().constData(), v);
		}

		//////////////////////////////////////////////////////////////////////////
		NetworkReply::~NetworkReply()
		{
		}
	}
}