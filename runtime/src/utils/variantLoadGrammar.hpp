#ifndef _UTILS_VARIANTLOADGRAMMAR_HPP_
#define _UTILS_VARIANTLOADGRAMMAR_HPP_

#include "variantLoadScope.hpp"
// #include <boost/spirit/include/qi_grammar.hpp>
// #include <boost/spirit/include/phoenix_core.hpp>
// #include <boost/spirit/include/phoenix_function.hpp>
// #include <boost/spirit/include/phoenix_operator.hpp>
// #include <boost/spirit/home/phoenix/bind/bind_member_function.hpp>

namespace utils
{
	namespace spirit = boost::spirit;
	namespace phx = boost::phoenix;
	namespace qi = boost::spirit::qi;

	struct VariantLoadGrammar
		: qi::grammar<const char *, qi::ascii::space_type>
	{

	public:
		VariantLoadGrammar(VariantLoadScope &scope);

		qi::rule<const char *, qi::ascii::space_type> _variant;

		qi::rule<const char *> _scalar;
		qi::rule<const char *, qi::ascii::space_type> _map;
		qi::rule<const char *, qi::ascii::space_type> _mapPair;
		qi::rule<const char *, qi::ascii::space_type> _array;
		qi::rule<const char *, qi::ascii::space_type> _include;

		qi::rule<const char *> _null;
		qi::rule<const char *, std::string()> _string;
		qi::rule<const char *, float()> _float;
		qi::rule<const char *, double()> _double;
		qi::rule<const char *, std::string()> _integer;
		qi::rule<const char *> _datetime;
		qi::rule<const char *, bool()> _bool;
		qi::symbols<char, bool> _boolSymbols;
		qi::rule<const char *> _bitset;
		qi::rule<const char *, std::string()> _uuid;

		qi::rule<const char *, std::string()> _ident;
		qi::rule<const char *, char()> _hexDigit;

		VariantLoadScope &_scope;
	};
}

#endif
