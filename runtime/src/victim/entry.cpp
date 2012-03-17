#include "pch.hpp"
#include "utils/variant.hpp"

typedef bool (utils::Variant::*TLoad)(const char *fileName, std::string *errors);
bool testOne(TLoad load)
{
	bool res = true;

	FILETIME stub, kt, ut;
	GetThreadTimes(GetCurrentThread(), &stub, &stub, &kt, &ut);
	boost::uint64_t start = (((boost::uint64_t)kt.dwHighDateTime)<<32) + kt.dwLowDateTime;
	start += (((boost::uint64_t)ut.dwHighDateTime)<<32) + ut.dwLowDateTime;
	bool b = true;
	size_t s(0);

	for(size_t i(0); i<1; i++)
	{
		utils::Variant v;
		std::string errors;
		bool b = (v.*load)("P:\\projects\\r3\\repo\\runtime\\make\\vs9_x64\\test.js", &errors);
		res &= b;

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

	return res;
}

//////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
	bool b = true;;

	for(size_t i(0); i<100; i++)
	{

		b &= testOne(&utils::Variant::load);
		std::cout<<" ";
		b &= testOne(&utils::Variant::load2);
		std::cout<<std::endl;
	}

	return b?EXIT_SUCCESS:EXIT_FAILURE;
}

