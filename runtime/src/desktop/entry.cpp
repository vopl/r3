#include "pch.hpp"
#include "client.hpp"
#include "agent.hpp"
#include "session.hpp"
#include "signal.hpp"

//////////////////////////////////////////////////////////////////////////
QScriptValue loadFile(QString fileName, QScriptEngine *engine)
{
	QScriptValue res;

	// avoid loading files more than once
	QFileInfo fileInfo(fileName);
	QString absoluteFileName = fileInfo.absoluteFilePath();
	QString absolutePath = fileInfo.absolutePath();
	QString canonicalFileName = fileInfo.canonicalFilePath();

	QString path = fileInfo.path();

	// load the file
	QFile file(fileName);
	if (file.open(QFile::ReadOnly))
	{
		QTextStream stream(&file);
		QString contents = stream.readAll();
		file.close();

		QScriptValue  newScript = engine->newObject();

		newScript.setProperty("filePath", engine->toScriptValue(absoluteFileName));
		newScript.setProperty("path", engine->toScriptValue(absolutePath));

		engine->currentContext()->activationObject().setProperty("script", newScript);
		res = engine->evaluate(contents, fileName);
	}
	else
	{
		return engine->currentContext()->throwError(QString("File not found: %1").arg(fileName));
	}
	return res;
}

//////////////////////////////////////////////////////////////////////////
QScriptValue include(QScriptContext *context, QScriptEngine *engine)
{
	QString currentFileName = engine->globalObject().property("script").property("filePath").toString();
	QFileInfo currentFileInfo(currentFileName);
	QString path = currentFileInfo.path();
	QString importFile = context->argument(0).toString();
	QFileInfo importInfo(importFile);
	if(importInfo.isRelative())
	{
		importFile =  path + "/" + importInfo.filePath();
	}

	return loadFile(importFile, engine);
}

//////////////////////////////////////////////////////////////////////////
QScriptValue importExtension(QScriptContext *context, QScriptEngine *engine)
{
	return engine->importExtension(context->argument(0).toString());
}

//////////////////////////////////////////////////////////////////////////
QScriptValue print(QScriptContext *context, QScriptEngine *engine)
{
	int argumentCount = context->argumentCount();
	for(int i(0); i<argumentCount; i++)
	{
		QByteArray ba = context->argument(i).toString().toUtf8();
		std::cout.write(ba.constData(), ba.size());
	}
	std::cout<<std::endl;

	return QScriptValue();
}

//////////////////////////////////////////////////////////////////////////
#define XLOG(x,X)\
QScriptValue x##log(QScriptContext *context, QScriptEngine *engine)\
{\
	int argumentCount = context->argumentCount();\
	QStringList sl;\
	for(int i(0); i<argumentCount; i++)\
	{\
		sl.push_back(context->argument(i).toString());\
	}\
	X##LOG(sl.join(" ").toUtf8().data());\
	return QScriptValue();\
}\

#define NLOG(x,X)\
QScriptValue x##log(QScriptContext *context, QScriptEngine *engine)\
{\
	return QScriptValue();\
}\

#if !defined(LOG4CPLUS_DISABLE_FATAL)
XLOG(f,F)
#else
NLOG(f,F)
#endif

#if !defined(LOG4CPLUS_DISABLE_ERROR)
XLOG(e,E)
#else
NLOG(e,E)
#endif

#if !defined(LOG4CPLUS_DISABLE_WARN)
XLOG(w,W)
#else
NLOG(w,W)
#endif

#if !defined(LOG4CPLUS_DISABLE_INFO)
XLOG(i,I)
#else
NLOG(i,I)
#endif

#if !defined(LOG4CPLUS_DISABLE_DEBUG)
XLOG(d,D)
#else
NLOG(d,D)
#endif

#if !defined(LOG4CPLUS_DISABLE_TRACE)
XLOG(t,T)
#else
NLOG(t,T)
#endif

//////////////////////////////////////////////////////////////////////////
template <class T>
QScriptValue qtscript_toScriptValue(QScriptEngine *engine, T* const &in)
{
	return engine->newQObject(in, QScriptEngine::AutoOwnership);
}

//////////////////////////////////////////////////////////////////////////
template <class T>
void qtscript_fromScriptValue(const QScriptValue &value, T* &out)
{
	out = qobject_cast<T*>(value.toQObject());
}


//////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

// 	//пути к расширениям
// 	QDir dir = QDir::current();
// 	dir.cdUp();
// 	if(!dir.cd("plug"))
// 	{
// 		fprintf(stderr, "plug folder does not exist\n");
// 		return EXIT_FAILURE;
// 	}
// 	QStringList paths = app.libraryPaths();
// 	paths <<  dir.absolutePath();
// 	app.setLibraryPaths(paths);


	/*
		global
			extensions
			importExtension
			include


		script
			filePath
			directoryPath
			parent
	*/

	//////////////////////////////////////////////////////////////////////////
	QScriptEngine *engine = new QScriptEngine();

#ifndef NDEBUG
	QScriptEngineDebugger *debugger = new QScriptEngineDebugger();
	debugger->attachTo(engine);
#endif

	QScriptValue global = engine->globalObject();
	global.setProperty("global", global);

	global.setProperty("extensions", engine->toScriptValue(engine->availableExtensions()));
	global.setProperty("importExtension", engine->newFunction(importExtension));
	global.setProperty("include", engine->newFunction(include));
	global.setProperty("print", engine->newFunction(print));

	global.setProperty("flog", engine->newFunction(flog));
	global.setProperty("elog", engine->newFunction(elog));
	global.setProperty("wlog", engine->newFunction(wlog));
	global.setProperty("ilog", engine->newFunction(ilog));
	global.setProperty("dlog", engine->newFunction(dlog));
	global.setProperty("tlog", engine->newFunction(tlog));
	global.setProperty("log", engine->newFunction(tlog));

	//////////////////////////////////////////////////////////////////////////
	// register client
	qScriptRegisterMetaType<Client*>(
		engine, 
		&qtscript_toScriptValue<Client>, 
		&qtscript_fromScriptValue<Client>);

	qScriptRegisterMetaType<Session*>(
		engine, 
		&qtscript_toScriptValue<Session>, 
		&qtscript_fromScriptValue<Session>);

	qScriptRegisterMetaType<Agent*>(
		engine, 
		&qtscript_toScriptValue<Agent>, 
		&qtscript_fromScriptValue<Agent>);

	qScriptRegisterMetaType<ErrorCode*>(
		engine, 
		&qtscript_toScriptValue<ErrorCode>, 
		&qtscript_fromScriptValue<ErrorCode>);

	global.setProperty("Client", engine->newFunction(&Client::qtscript_ctor));
	global.setProperty("Signal", engine->newFunction(&Signal::qtscript_ctor));

	//////////////////////////////////////////////////////////////////////////
	

	{ // read script file and execute

		QString fileName = ":/main.js";
		QScriptValue res = loadFile(fileName, engine);

		if(engine->hasUncaughtException())
		{
			QStringList backtrace = engine->uncaughtExceptionBacktrace();
			ELOG(res.toString().toUtf8().data()<<"\n"<<backtrace.join("\n").toUtf8().data());
		}
	}

	delete engine;

#ifndef NDEBUG
	delete debugger;
#endif

	return EXIT_SUCCESS;
}
