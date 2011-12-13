#include "pch.h"
#include "variantLoadGrammar.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


namespace utils
{
	using namespace qi::labels;
	using namespace qi;

	//////////////////////////////////////////////////////////////////////////
	VariantLoadGrammar::VariantLoadGrammar(VariantLoadScope &scope)
		: base_type(_variant, "variant")
		, _scope(scope)
	{

		//////////////////////////////////////////////////////////////////////////
		_scalar.name("scalar");
		_scalar = 
			_null				[phx::bind(&VariantLoadScope::set_null, _scope)] | 
			_string				[phx::bind(&VariantLoadScope::set_string, _scope, _1)] | 
			_float				[phx::bind(&VariantLoadScope::set_float, _scope, _1)] | 
			_double				[phx::bind(&VariantLoadScope::set_double, _scope, _1)] | 
			_integer			[phx::bind(&VariantLoadScope::set_integer, _scope, _1)] | 
			_datetime | 
			_bool				[phx::bind(&VariantLoadScope::set_bool, _scope, _1)] | 
			_bitset | 
			_uuid;








		//////////////////////////////////////////////////////////////////////////
		_null.name("null");
		_null = lit("null");


		//////////////////////////////////////////////////////////////////////////
		_string.name("string");
		_string =
			(
				lit('"') >
				*((lit('\\') >> char_('"')) | (char_ - char_('"'))) >
 				lit('"')
			)|
			(
				lit('\'') >
				*((lit('\\') >> char_('\'')) | (char_ - char_('\''))) >
 				lit('\'')
			);

		//////////////////////////////////////////////////////////////////////////
		_float.name("float");
		_float = 
			real_parser<float, strict_real_policies<float> >() >>lit('f');

		//////////////////////////////////////////////////////////////////////////
		_double.name("double");
		_double = 
			real_parser<double, strict_real_policies<double> >();

		//////////////////////////////////////////////////////////////////////////
		_integer.name("integer");
		_integer =
			(
				ascii::string("0x") > 
				+char_("0-9a-fA-F") >>
				-(char_('u') >>
					-(ascii::string("8")|ascii::string("16")|ascii::string("32")|ascii::string("64")
					)
				)
			)|
			(
				+char_("0-9") >> 
				-((ascii::string("ui") | char_('u') | char_('i')) >>
					-(ascii::string("8")|ascii::string("16")|ascii::string("32")|ascii::string("64")
					)
				)
			)|
			(
				char_('-') >>
				+char_("0-9") >> 
				-(char_('i') >>
					-(ascii::string("8")|ascii::string("16")|ascii::string("32")|ascii::string("64")
					)
				)
			);

		//////////////////////////////////////////////////////////////////////////
		_datetime;

		//////////////////////////////////////////////////////////////////////////
		_bool.name("bool");
		_bool = no_case[_boolSymbols];

		_boolSymbols.add
			("true", true)
			("t", true)
			("on", true)
			("false", false)
			("f", false)
			("off", false);

		//////////////////////////////////////////////////////////////////////////
		_bitset;

		//////////////////////////////////////////////////////////////////////////
		_uuid;


		//////////////////////////////////////////////////////////////////////////
		_ident.name("ident");
		_ident = 
			((alpha | char_('_')) >> *(alnum | char_('_')));








		//////////////////////////////////////////////////////////////////////////
		_map.name("map");
		_map = 
			lit("{")[phx::bind(&VariantLoadScope::map_start, _scope)] > 
			-(
				_mapPair >> 
				*(lit(",") >> _mapPair) >> 
				-lit(",")
			) > 
			lit("}")[phx::bind(&VariantLoadScope::map_stop, _scope)];

		_mapPair.name("mapPair");
		_mapPair = 
			(_ident | _string)[phx::bind(&VariantLoadScope::map_key, _scope, _1)] >
			(lit(':')|lit('=')) >
			_variant[phx::bind(&VariantLoadScope::map_push, _scope)];

		//////////////////////////////////////////////////////////////////////////
		_array.name("array");
		_array = 
			lit("[")[phx::bind(&VariantLoadScope::array_start, _scope)] > 
			-(
				_variant[phx::bind(&VariantLoadScope::array_push, _scope)] >> 
				*(lit(",") >> _variant[phx::bind(&VariantLoadScope::array_push, _scope)]) >> 
				-lit(",")
			) > 
			lit("]")[phx::bind(&VariantLoadScope::array_stop, _scope)];

		//////////////////////////////////////////////////////////////////////////
		_include.name("include");
		_include = lit("include");

		//////////////////////////////////////////////////////////////////////////
		_variant.name("variant");
		_variant = _map | _array | _include | _scalar;

		using namespace labels;

		//////////////////////////////////////////////////////////////////////////
		on_error<fail>
			(
			_variant, 
			phx::bind(&VariantLoadScope::error, _scope, _1, _2, _3, _4)
			);

	}

}
