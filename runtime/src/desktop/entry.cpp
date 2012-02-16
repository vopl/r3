#include "pch.hpp"

//////////////////////////////////////////////////////////////////////////
bool loadFile(QString fileName, QScriptEngine *engine)
{
	// avoid loading files more than once
	static QSet<QString> loadedFiles;
	QFileInfo fileInfo(fileName);
	QString absoluteFileName = fileInfo.absoluteFilePath();
	QString absolutePath = fileInfo.absolutePath();
	QString canonicalFileName = fileInfo.canonicalFilePath();
	if (loadedFiles.contains(canonicalFileName)) {
		return true;
	}
	loadedFiles.insert(canonicalFileName);
	QString path = fileInfo.path();

	// load the file
	QFile file(fileName);
	if (file.open(QFile::ReadOnly)) {
		QTextStream stream(&file);
		QString contents = stream.readAll();
		file.close();

		int endlineIndex = contents.indexOf('\n');
		QString line = contents.left(endlineIndex);
		int lineNumber = 1;

		// strip off #!/usr/bin/env qscript line
		if (line.startsWith("#!")) {
			contents.remove(0, endlineIndex+1);
			++lineNumber;
		}

		// set qt.script.absoluteFilePath
		QScriptValue script = engine->globalObject().property("qs").property("script");
		QScriptValue oldFilePathValue = script.property("absoluteFilePath");
		QScriptValue oldPathValue = script.property("absolutePath");
		script.setProperty("absoluteFilePath", engine->toScriptValue(absoluteFileName));
		script.setProperty("absolutePath", engine->toScriptValue(absolutePath));

		QScriptValue r = engine->evaluate(contents, fileName, lineNumber);
		if (engine->hasUncaughtException()) {
			QStringList backtrace = engine->uncaughtExceptionBacktrace();
			qDebug() << QString("    %1\n%2\n\n").arg(r.toString()).arg(backtrace.join("\n"));
			return true;
		}
		script.setProperty("absoluteFilePath", oldFilePathValue); // if we come from includeScript(), or whereever
		script.setProperty("absolutePath", oldPathValue); // if we come from includeScript(), or whereever
	} else {
		return false;
	}
	return true;
}

//////////////////////////////////////////////////////////////////////////
QScriptValue includeScript(QScriptContext *context, QScriptEngine *engine)
{
	QString currentFileName = engine->globalObject().property("qs").property("script").property("absoluteFilePath").toString();
	QFileInfo currentFileInfo(currentFileName);
	QString path = currentFileInfo.path();
	QString importFile = context->argument(0).toString();
	QFileInfo importInfo(importFile);
	if (importInfo.isRelative()) {
		importFile =  path + "/" + importInfo.filePath();
	}
	if (!loadFile(importFile, engine)) {
		return context->throwError(QString("Failed to resolve include: %1").arg(importFile));
	}
	return engine->toScriptValue(true);
}

//////////////////////////////////////////////////////////////////////////
QScriptValue importExtension(QScriptContext *context, QScriptEngine *engine)
{
	return engine->importExtension(context->argument(0).toString());
}

//////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	//пути к расширениям
	QDir dir = QDir::current();
	dir.cdUp();
	if(!dir.cd("plug"))
	{
		fprintf(stderr, "plug folder does not exist\n");
		return EXIT_FAILURE;
	}
	QStringList paths = app.libraryPaths();
	paths <<  dir.absolutePath();
	app.setLibraryPaths(paths);



	//////////////////////////////////////////////////////////////////////////
	QScriptEngine *engine = new QScriptEngine();

#ifndef NDEBUG
	QScriptEngineDebugger *debugger = new QScriptEngineDebugger();
	debugger->attachTo(engine);
#endif

	QScriptValue global = engine->globalObject();
	global.setProperty("global", global);

	// add the qt object
	global.setProperty("qs", engine->newObject());
	// add a 'script' object
	QScriptValue script = engine->newObject();
	global.property("qs").setProperty("script", script);
	// add a 'system' object
	QScriptValue system = engine->newObject();
	global.property("qs").setProperty("system", system);

	global.property("qs").setProperty("extensions", engine->toScriptValue(engine->availableExtensions()));


	// add the include functionality to qt.script.include
	script.setProperty("include", engine->newFunction(includeScript));
	// add the importExtension functionality to qt.script.importExtension
	script.setProperty("importExtension", engine->newFunction(importExtension));

	//QStringList args = QCoreApplication::arguments();
	//args.takeFirst();


	{ // read script file and execute

		QString fileName = ":/main.js";
		if (!loadFile(fileName, engine))
		{
			qDebug() << "Failed:" << fileName;
			return EXIT_FAILURE;
		}
	}

	delete engine;

#ifndef NDEBUG
	delete debugger;
#endif

	return EXIT_SUCCESS;
}

