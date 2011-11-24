// victim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////////
class Module;
typedef boost::shared_ptr<Module> ModulePtr;

typedef int TMuid;

//////////////////////////////////////////////////////////////////////////
class ModuleManager
{
public:

	//версионность


	//реестр модулей
	ModulePtr mkInstance(TMuid);


};

//////////////////////////////////////////////////////////////////////////
class Module
{
public:

public:
	Module(ModuleManager & mm);

};
//////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
	return 0;
}

