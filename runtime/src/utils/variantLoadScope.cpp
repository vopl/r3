#include "pch.h"
#include "variantLoadScope.hpp"
#include "utils/ntoa.hpp"

namespace utils
{
	//////////////////////////////////////////////////////////////////////////
	VariantLoadScope::VariantLoadScope(
		Variant *root, 
		const char *fileName, 
		const char *first,
		const char *last,
		std::string *errors)
		: _root(root)
		, _fileName(fileName)
		, _first(first)
		, _last(last)
		, _errors(errors)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	VariantLoadScope::~VariantLoadScope()
	{

	}

	//////////////////////////////////////////////////////////////////////////
	void VariantLoadScope::error(
		const char *first, const char *last, 
		const char *errorPos, 
		const boost::spirit::info &what)
	{
		if(!_errors)
		{
			return;
		}
// 		if(_first != first || _last!=last)
// 		{
// 			return;
// 		}
		first = _first;
		last = _last;

		std::string &msg = *_errors;

		const char *firstContext=first, *lastContext=errorPos;
		size_t line = 1;
		for(const char *iter=first; iter!=errorPos; iter++)
		{
			if('\r' == *iter && iter+1 != last && '\n' == *(iter+1))
			{
				line++;
				firstContext = iter+2;
				iter++;
			}
			else if('\n' == *iter || '\r' == *iter)
			{
				line++;
				firstContext = iter+1;
			}
		}

		size_t col = std::distance(firstContext, errorPos)+1;

		for(; lastContext!=last; lastContext++)
		{
			if('\r' == *lastContext && lastContext+1 != last && '\n' == *(lastContext+1))
			{
				break;
			}
			else if('\n' == *lastContext || '\r' == *lastContext)
			{
				break;
			}
		}
		std::string(firstContext, lastContext);

		msg += "error at line ";
		char tmp[32];
		msg += _ntoa(line, tmp);
		msg += " column ";
		msg += _ntoa(col, tmp);

		std::stringstream ss;
		ss<<what;
		msg += ": expected "+ss.str()+"\n";

		msg += std::string(firstContext, lastContext);
		msg += "\n";
		for(size_t i(0); i<col-1; i++)
		{
			msg += firstContext[i]=='\t'?'\t':' ';
		}
		msg += "^\n";

		return;


// 		"error at line %d, %d: " what
// 			context

// 		std::cout
// 			<< phx::val("Error! Expecting ")
// 			<< _4                               // what failed?
// 			<< phx::val(" here: \"")
// 			<< phx::construct<std::string>(_3, _2)   // iterators to error-pos, end
// 			<< phx::val("\"")
// 			<< std::endl

	}

}
