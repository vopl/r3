#include "pch.h"
#include "utils/variant.hpp"

using namespace utils;
using namespace std;

//////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{

	Variant v;

	struct SP
	{
		const char *_name;
		Variant::EType _et;
	};

	SP _sps[] ={
		{"Void", Variant::etVoid}
#define ENUM_VARIANT_TYPE(T) ,{#T, Variant::et##T}
	ENUM_VARIANT_TYPES
#undef ENUM_VARIANT_TYPE
	};

	size_t nTypes = sizeof(_sps)/sizeof(SP);

// 	cout<<"name"<<"\t";
// 	for(size_t i(0); i<nTypes; i++)
// 	{
// 		cout<<_sps[i]._name<<"\t";
// 	}
// 	cout<<endl;

	size_t count=0;
	for(size_t i(0); i<nTypes+1; i++)
	{
		cout<<"--";
	}
	cout<<endl;
	for(size_t i(0); i<nTypes; i++)
	{
		cout<<'|';
		v.forceType(_sps[i]._et);
		v.setNull(false);
		if(_sps[i]._et == Variant::etVariantPtr)
		{
			v.as<VariantPtr>().reset(new Variant("tratata"));
			VariantPtr vp = v;
		}
// 		cout<<_sps[i]._name<<"\t";
		for(size_t i(0); i<nTypes; i++)
		{
#ifdef _DEBUG
			if(v.canConvert(_sps[i]._et))
#else
			if(true)
#endif
			{
				count++;
				cout<<"<>";
			}
			else
			{
				cout<<"  ";
			}
// 			cout<<v.canConvert(_sps[i]._et)<<"\t";
		}
		cout<<'|';
		cout<<endl;
	}
	for(size_t i(0); i<nTypes+1; i++)
	{
		cout<<"--";
	}
	cout<<endl;

	cout<<count<<"/"<<nTypes*nTypes<<endl;

	return EXIT_SUCCESS;
}

