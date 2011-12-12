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
		_scalar = 
			_string				[phx::bind(&VariantLoadScope::set_string, _scope, _1)] | 
			_float				[phx::bind(&VariantLoadScope::set_float, _scope, _1)] | 
			_double				[phx::bind(&VariantLoadScope::set_double, _scope, _1)] | 
			_integer			[phx::bind(&VariantLoadScope::set_integer, _scope, _1)] | 
			_datetime | 
			_bool | 
			_bitset | 
			_uuid;










		//////////////////////////////////////////////////////////////////////////
		_string.name("string");
		_string =
			(
				qi::lit('"') >
				*((qi::lit('\\') >> qi::char_('"')) | (qi::char_ - qi::char_('"'))) >
 				qi::lit('"')
			)|
			(
				qi::lit('\'') >
				*((qi::lit('\\') >> qi::char_('\'')) | (qi::char_ - qi::char_('\''))) >
 				qi::lit('\'')
			);

		//////////////////////////////////////////////////////////////////////////
		_float.name("float");
		_float = 
			qi::real_parser<float, qi::strict_real_policies<float> >() >>qi::lit('f');

		//////////////////////////////////////////////////////////////////////////
		_double.name("double");
		_double = 
			qi::real_parser<double, qi::strict_real_policies<double> >();

		//////////////////////////////////////////////////////////////////////////
		_integer.name("integer");
		_integer =
			(
				qi::ascii::string("0x") > 
				+qi::char_("0-9a-fA-F") >>
				-(qi::char_('u') >>
					-(qi::ascii::string("8")|qi::ascii::string("16")|qi::ascii::string("32")|qi::ascii::string("64")
					)
				)
			)|
			(
				+qi::char_("0-9") >> 
				-((qi::ascii::string("ui") | qi::char_('u') | qi::char_('i')) >>
					-(qi::ascii::string("8")|qi::ascii::string("16")|qi::ascii::string("32")|qi::ascii::string("64")
					)
				)
			)|
			(
				qi::char_('-') >>
				+qi::char_("0-9") >> 
				-(qi::char_('i') >>
					-(qi::ascii::string("8")|qi::ascii::string("16")|qi::ascii::string("32")|qi::ascii::string("64")
					)
				)
			);


		_ident.name("ident");
		_ident = 
			((qi::alpha | qi::char_('_')) >> *(qi::alnum | qi::char_('_')));








		//////////////////////////////////////////////////////////////////////////
		_map.name("map");
		_map = 
			qi::lit("{")[phx::bind(&VariantLoadScope::map_start, _scope)] > 
			-(
				_mapPair >> 
				*(qi::lit(",") > _mapPair) >> 
				-qi::lit(",")
			) > 
			qi::lit("}")[phx::bind(&VariantLoadScope::map_stop, _scope)];

		_mapPair.name("mapPair");
		_mapPair = 
			(_ident | _string)[phx::bind(&VariantLoadScope::map_key, _scope, _1)] >
			(qi::lit(':')|qi::lit('=')) >
			_variant[phx::bind(&VariantLoadScope::map_push, _scope)];

		//////////////////////////////////////////////////////////////////////////
		_array.name("array");
		_array = 
			qi::lit("[")[phx::bind(&VariantLoadScope::array_start, _scope)] > 
			-(
				_variant[phx::bind(&VariantLoadScope::array_push, _scope)] >> 
				*(qi::lit(",") > _variant[phx::bind(&VariantLoadScope::array_push, _scope)]) >> 
				-qi::lit(",")
			) > 
			qi::lit("]")[phx::bind(&VariantLoadScope::array_stop, _scope)];

		//////////////////////////////////////////////////////////////////////////
		_include.name("include");
		_include = qi::lit("include");

		//////////////////////////////////////////////////////////////////////////
		_variant.name("variant");
		_variant = _map | _array | _include | _scalar;

		using namespace qi::labels;

		qi::on_error<qi::fail>
			(
			_variant, 
			phx::bind(&VariantLoadScope::error, _scope, _1, _2, _3, _4)
			);

	}

}
