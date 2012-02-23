#ifndef _FILEENGINEHANDLER_HPP_
#define _FILEENGINEHANDLER_HPP_

#include <boost/filesystem.hpp>

class FileEngineHandler
	: public QAbstractFileEngineHandler
{
	QStringList _stack;

public:
	FileEngineHandler();
	~FileEngineHandler();

	void pushCurrentPath(const QString &path);
	void popCurrentPath();
	QAbstractFileEngine *create(const QString &fileName) const;
};


#endif
