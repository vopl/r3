#include "pch.h"
#include "variantLoadGrammar.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


namespace utils
{
	using namespace qi::labels;

	//////////////////////////////////////////////////////////////////////////
	VariantLoadGrammar::VariantLoadGrammar(VariantLoadScope &scope)
		: base_type(_variant, "variant")
		, _scope(scope)
	{

		//////////////////////////////////////////////////////////////////////////
		_scalar.name("scalar");
		_scalar %= 
			_string | _real | _integer | _datetime | _bool | _bitset | _uuid;

		//////////////////////////////////////////////////////////////////////////
		_stringStart.name("stringStart");
		_stringStart %= qi::lexeme[qi::char_("'\"")];

		_stringChar.name("stringChar");
		_stringChar = (qi::char_ - qi::char_(_r1)) | (qi::char_('\\') >> qi::char_(_r1));

		_stringStop.name("stringStop");
		_stringStop = qi::char_(_r1);

		_string.name("string");
		_string %=
			_stringStart[_a = _1] >
			*_stringChar(_a) >
 			_stringStop(_a);

		//////////////////////////////////////////////////////////////////////////
		_map.name("map");
		_map %= qi::lit("map");

		//////////////////////////////////////////////////////////////////////////
		_array.name("array");
		_array %= 
			qi::lit("[") > 
			*(_variant >> (qi::lit(",")|qi::eps)) > 
			qi::lit("]");

		//////////////////////////////////////////////////////////////////////////
		_include.name("include");
		_include %= qi::lit("include");

		//////////////////////////////////////////////////////////////////////////
		_variant.name("variant");
		_variant %= _scalar | _map | _array | _include;

		using namespace qi::labels;

		qi::on_error<qi::fail>
			(
			_variant, 
			phx::bind(&VariantLoadScope::error, _scope, _1, _2, _3, _4)
			);

	}

}
