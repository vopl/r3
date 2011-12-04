#ifndef _CLIENT_QT_NETWORKREPLY_HPP_
#define _CLIENT_QT_NETWORKREPLY_HPP_

#include <QtNetwork/QNetworkReply>
#include "agent.hpp"

namespace client
{
	namespace qt
	{

		class NetworkReply
			: public QNetworkReply
			, Agent
		{
			Q_OBJECT

		private:
			virtual bool 	atEnd () const;
			virtual qint64 	bytesAvailable () const;
			virtual qint64 	bytesToWrite () const;
			virtual bool 	canReadLine () const;
			virtual void 	close ();
			virtual bool 	isSequential () const;
			virtual bool 	open ( OpenMode mode );
			virtual qint64 	pos () const;
			virtual bool 	reset ();
			virtual bool 	seek ( qint64 pos );
			virtual qint64 	size () const;
			virtual bool 	waitForBytesWritten ( int msecs );
			virtual bool 	waitForReadyRead ( int msecs );

			virtual qint64 	readData ( char * data, qint64 maxSize );
			virtual qint64 	readLineData ( char * data, qint64 maxSize );
			virtual qint64 	writeData ( const char * data, qint64 maxSize );

			virtual void	abort();
			virtual void 	setReadBufferSize ( qint64 size );
			virtual void 	ignoreSslErrors ();

		protected:
			virtual void onReceive(
				IAgentHubPtr hub,
				const server::TEndpoint &endpoint,
				utils::VariantPtr data);

		public:
			NetworkReply(QObject *parent, QUrl url);
			~NetworkReply();

		};

	}
}

#endif
