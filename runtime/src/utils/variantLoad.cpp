#include "pch.h"
#include "utils/variant.hpp"
#include "variantLoadScope.hpp"
#include "variantLoadGrammar.hpp"
#include <fstream>

#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/support_multi_pass.hpp>

namespace utils
{
	namespace qi = boost::spirit::qi;
	namespace spirit = boost::spirit;

	//////////////////////////////////////////////////////////////////////////
	bool Variant::load(const char *fileName, std::string *errors)
	{
		std::ifstream in(fileName, std::ios::binary);
		if(!in)
		{
			if(errors)
			{
				*errors += "file not found: ";
				*errors += fileName;
				*errors += "\n";
			}
			return false;
		}

		std::vector<char> buffer;
		in.seekg(0, std::ios::end);
		buffer.resize(in.tellg());
		in.seekg(std::ios::beg, 0);
		if(buffer.size())
		{
			in.read(&buffer[0], buffer.size());
			in.close();
		}
		else
		{
			forceType<void>();
			return true;
		}

		const char *first = &buffer[0];
		const char *last = first + buffer.size();

		VariantLoadScope scope(this, fileName, first, last, errors);
        bool parseResult = qi::phrase_parse(
			first, 
			last,
			VariantLoadGrammar(scope),
			spirit::ascii::space);

		if(parseResult)
		{
			if(first != last)
			{
				boost::spirit::info what(std::string("end"));
				scope.error(&buffer[0], last, first, what);
			}
		}

		return parseResult && !scope.errorWas();
	}


}
