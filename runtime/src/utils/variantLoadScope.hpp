#ifndef _UTILS_VARIANTLOADSCOPE_HPP_
#define _UTILS_VARIANTLOADSCOPE_HPP_

#include "utils/variant.hpp"

namespace utils
{
	class VariantLoadScope
	{
		Variant			*_root;
		std::string		_fileName;
		const char		*_first;
		const char		*_last;
		std::string		*_errors;

	public:
		VariantLoadScope(
			Variant *root, 
			const char *fileName, 
			const char *first,
			const char *last,
			std::string *errors);
		~VariantLoadScope();

		void error(const char *first, const char *last, const char *errorPos, const boost::spirit::info &what);
	};
}

#endif
