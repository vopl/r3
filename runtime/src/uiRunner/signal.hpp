#ifndef _SIGNAL_HPP_
#define _SIGNAL_HPP_

#include <QtCore>
#include <QScriptable>
#include <QScriptClass>


//////////////////////////////////////////////////////////////////////////
class Signal
	: public QObject

{
	Q_OBJECT

	struct Slot
	{
		QScriptValue		_object;
		QScriptValue		_function;

		bool operator==(const Slot &with)
		{
			return _object.equals(with._object) && _function.equals(with._function);
		}
	};
	QList<Slot>	_slots;

public:
	Signal();
	~Signal();


public:
	static QScriptValue qtscript_ctor(QScriptContext *context, QScriptEngine *engine);
	static QScriptValue qtscript_call(QScriptContext *context, QScriptEngine *engine);

	Q_INVOKABLE QString toString();
	Q_INVOKABLE QScriptValue connect(QScriptValue func);
	Q_INVOKABLE QScriptValue connect(QScriptValue obj, QScriptValue func);

	Q_INVOKABLE QScriptValue disconnect(QScriptValue func);
	Q_INVOKABLE QScriptValue disconnect(QScriptValue obj, QScriptValue func);
};

Q_DECLARE_METATYPE(Signal *)

#endif
