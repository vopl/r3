#ifndef _UTILS_VARIANTLOADSCOPE_HPP_
#define _UTILS_VARIANTLOADSCOPE_HPP_

#include "utils/variant.hpp"
#include <deque>

namespace utils
{
	class VariantLoadScope
	{
		Variant			*_root;

		std::deque<Variant>			_stack;

		std::string		_fileName;
		const char		*_first;
		const char		*_last;
		std::string		*_errors;
		bool			_errorWas;

	public:
		VariantLoadScope(
			Variant *root, 
			const char *fileName, 
			const char *first,
			const char *last,
			std::string *errors);
		~VariantLoadScope();

		void error(const char *first, const char *last, const char *errorPos, const boost::spirit::info &what);
		
		void set_string(const std::string &content);
		void set_double(const double &content);
		void set_float(const float &content);
		void set_integer(const std::string &content);

		void array_start();
		void array_push();
		void array_stop();

	};
}

#endif
