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
		_stack.push_back(path);
	}
	else
	{
		_stack.push_back(path+"/");
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
	if(boost::filesystem::path(name.toUtf8().data()).is_relative())
	{
		QString res = name;
		if(res[0] == '/')
		{
			res = res.right(res.size()-1);
		}
		res = _stack.back() + res;

		if(boost::filesystem::exists(boost::filesystem::path(res.toUtf8().data())))
		{
			return new QFSFileEngine(res);
		}
	}

	return 0;
}
