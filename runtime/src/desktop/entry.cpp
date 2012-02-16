#include "pch.hpp"

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


	{ // read script file and execute

		QString fileName = ":/main.js";
		QScriptValue res = loadFile(fileName, engine);

		if(engine->hasUncaughtException())
		{
			QStringList backtrace = engine->uncaughtExceptionBacktrace();
			qDebug() << QString("    %1\n%2\n\n").arg(res.toString()).arg(backtrace.join("\n"));
		}
	}

	delete engine;

#ifndef NDEBUG
	delete debugger;
#endif

	return EXIT_SUCCESS;
}

