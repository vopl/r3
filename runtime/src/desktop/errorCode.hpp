#ifndef _ERRORCODE_HPP_
#define _ERRORCODE_HPP_

#include <QtCore>
#include <QPointer>
#include <QScriptable>
#include <boost/system/error_code.hpp>
#include <QScriptable>

//////////////////////////////////////////////////////////////////////////
class ErrorCode
	: public QObject
	, private QScriptable
{
	Q_OBJECT

	boost::system::error_code _ec;

private:
	Q_DISABLE_COPY(ErrorCode)

	bool getOk();
	bool getFail();
	int getValue();
	QString getMessage();
	QString getCategory();

public:
	ErrorCode();
	ErrorCode(const boost::system::error_code &ec);
	~ErrorCode();

public:
	Q_PROPERTY(bool ok READ getOk);
	Q_PROPERTY(bool fail READ getFail);
	Q_PROPERTY(int value READ getValue);
	Q_PROPERTY(QString message READ getMessage);
	Q_PROPERTY(QString category READ getCategory);

	Q_INVOKABLE QString toString();
	Q_INVOKABLE ErrorCode *valueOf();
};

Q_DECLARE_METATYPE(ErrorCode *)

#endif
