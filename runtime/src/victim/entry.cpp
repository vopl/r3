#include "pch.hpp"
#include "utils/variant.hpp"

typedef bool (utils::Variant::*TLoad)(const char *fileName, std::string *errors);
void testOne(TLoad load)
{

	FILETIME stub, kt, ut;
	GetThreadTimes(GetCurrentThread(), &stub, &stub, &kt, &ut);
	boost::uint64_t start = (((boost::uint64_t)kt.dwHighDateTime)<<32) + kt.dwLowDateTime;
	start += (((boost::uint64_t)ut.dwHighDateTime)<<32) + ut.dwLowDateTime;
	bool b = true;
	size_t s(0);

	for(size_t i(0); i<10; i++)
	{
		utils::Variant v;
		std::string errors;
		bool b = (v.*load)("P:\\projects\\r3\\repo\\runtime\\make\\vs9_x64\\test.js", &errors);

		//std::cout<<(b?"success":"failure")<<std::endl;
		if(!b)
		{
			std::cout<<errors<<std::endl;
		}

		//std::cout<<v<<std::endl;
	}

	GetThreadTimes(GetCurrentThread(), &stub, &stub, &kt, &ut);
	boost::uint64_t stop = (((boost::uint64_t)kt.dwHighDateTime)<<32) + kt.dwLowDateTime;
	stop += (((boost::uint64_t)ut.dwHighDateTime)<<32) + ut.dwLowDateTime;



	std::cout<<double(stop-start)/1e7;
}

//////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{

	for(size_t i(0); i<100; i++)
	{

		testOne(&utils::Variant::load);
		std::cout<<" ";
		testOne(&utils::Variant::load2);
		std::cout<<std::endl;
	}

	return EXIT_SUCCESS;
}

