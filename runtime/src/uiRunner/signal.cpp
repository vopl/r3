#include "pch.hpp"
#include "signal.hpp"

//////////////////////////////////////////////////////////////////////////
Signal::Signal()
	: QObject()
{

}

//////////////////////////////////////////////////////////////////////////
Signal::~Signal()
{

}

//////////////////////////////////////////////////////////////////////////
QScriptValue Signal::qtscript_ctor(QScriptContext *context, QScriptEngine *engine)
{
	if (context->thisObject().strictlyEquals(context->engine()->globalObject()))
	{
		return context->throwError(QString::fromLatin1("Signal(): Did you forget to construct with 'new'?"));
	}

	Signal* cpp = new Signal();
	QScriptValue qs = context->engine()->newQObject(
		context->thisObject(), 
		cpp, 
		QScriptEngine::AutoOwnership);

	QScriptValue call = engine->newFunction(&Signal::qtscript_call);

	call.setPrototype(qs);

	return call;
}

//////////////////////////////////////////////////////////////////////////
QScriptValue Signal::qtscript_call(QScriptContext *context, QScriptEngine *engine)
{
	Signal* self = qscriptvalue_cast<Signal*>(context->callee().prototype());

	QList<Slot>::iterator iter = self->_slots.begin();
	QList<Slot>::iterator end = self->_slots.end();
	for(; iter!=end; ++iter)
	{
		iter->_function.call(iter->_object, context->argumentsObject());
	}

	return QScriptValue();
}

//////////////////////////////////////////////////////////////////////////
QString Signal::toString()
{
	return "Signal";
}

//////////////////////////////////////////////////////////////////////////
QScriptValue Signal::connect(QScriptValue func)
{
	return connect(QScriptValue(), func);
}

//////////////////////////////////////////////////////////////////////////
QScriptValue Signal::connect(QScriptValue obj, QScriptValue func)
{
	Slot slot = {obj, func};
	_slots.push_back(slot);
	return QScriptValue();
}

//////////////////////////////////////////////////////////////////////////
QScriptValue Signal::disconnect(QScriptValue func)
{
	return disconnect(QScriptValue(), func);
}

//////////////////////////////////////////////////////////////////////////
QScriptValue Signal::disconnect(QScriptValue obj, QScriptValue func)
{
	Slot slot = {obj, func};
	int idx = _slots.indexOf(slot);
	if(0 > idx)
	{
		return QScriptValue(false);
	}
	_slots.removeAt(idx);
	return QScriptValue(true);
}

