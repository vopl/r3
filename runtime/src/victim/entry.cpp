#include "pch.h"
#include "utils/variant.hpp"

//////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{

	utils::Variant v;
	std::string errors;
	bool b = v.load("P:\\projects\\r3\\repo\\runtime\\server\\test.js", &errors);

	std::cout<<(b?"success":"failure")<<std::endl;
	if(!b)
	{
		std::cout<<errors<<std::endl;
	}

	std::cout<<v<<std::endl;

	return EXIT_SUCCESS;
}

