#include "pch.hpp"
#include "fileEngineHandler.hpp"

using namespace boost::filesystem;

//////////////////////////////////////////////////////////////////////////
FileEngineHandler::FileEngineHandler()
{
	_stack.push_back(QDir::currentPath());
}

//////////////////////////////////////////////////////////////////////////
FileEngineHandler::~FileEngineHandler()
{

}

//////////////////////////////////////////////////////////////////////////
void FileEngineHandler::pushCurrentPath(const QString &path)
{
	if(path.endsWith('/'))
	{
		_stack.push_back(path.left(path.size()-1));
	}
	else
	{
		_stack.push_back(path);
	}
}

//////////////////////////////////////////////////////////////////////////
void FileEngineHandler::popCurrentPath()
{
	_stack.pop_back();
}

//////////////////////////////////////////////////////////////////////////
QAbstractFileEngine *FileEngineHandler::create(const QString &name) const
{
	if(name.isEmpty() || name[0] == ':' || _stack.back()[0] == ':')
	{
		return NULL;
	}

	if(boost::filesystem::path(name.toUtf8().data()).is_relative())
	{
		QString res = name;
		if(res[0] == '/')
		{
			res = _stack.back() + res;
		}
		else
		{
			res = _stack.back() + '/' + res;
		}

		if(boost::filesystem::exists(res.toUtf8().data()))
		{
			return new QFSFileEngine(res);
		}
	}

	return 0;
}
