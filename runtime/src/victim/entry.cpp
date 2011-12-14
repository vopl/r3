#include "pch.h"
#include "utils/variant.hpp"

using namespace utils;

//////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{

	Variant v;
	std::string errors;
	bool b = v.load("P:\\projects\\r3\\repo\\runtime\\server\\test.js", &errors);

	std::cout<<(b?"success":"failure")<<std::endl;
	if(!b)
	{
		std::cout<<errors<<std::endl;
	}

	std::cout<<v<<std::endl;

	b = v.isScalar();
	b = v.isMap();
	b = v.isArray();
	//size_t size = v;
	Variant d = v["deque"];
	Variant m = v["map"];

	Variant d0 = d[0];
	d0.convert<int>();

	return EXIT_SUCCESS;
}

