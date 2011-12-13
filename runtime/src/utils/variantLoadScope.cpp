#include "pch.h"
#include "variantLoadScope.hpp"
#include "utils/ntoa.hpp"
#include "utils/aton.hpp"
#include "utils/xton.hpp"

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
		, _errorWas(false)
	{
		_stack.push_back(Variant());
	}

	//////////////////////////////////////////////////////////////////////////
	VariantLoadScope::~VariantLoadScope()
	{
		if(!_errorWas)
		{
			assert(_stack.size() == 1);
			if(_root && 1 == _stack.size())
			{
				_root->swap(_stack.back());
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void VariantLoadScope::error(
		const char *first, const char *last, 
		const char *errorPos, 
		const boost::spirit::info &what)
	{
		_errorWas = true;
		_stack.clear();

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

	//////////////////////////////////////////////////////////////////////////
	void VariantLoadScope::set_null()
	{
		if(_errorWas) return;
		assert(_stack.size() > 0);

		_stack.back().setNull<void>(true);
	}

	//////////////////////////////////////////////////////////////////////////
	void VariantLoadScope::set_string(const std::string &content)
	{
		if(_errorWas) return;
		assert(_stack.size() > 0);

		_stack.back() = content;
	}

	//////////////////////////////////////////////////////////////////////////
	void VariantLoadScope::set_double(const double &content)
	{
		if(_errorWas) return;
		assert(_stack.size() > 0);

		_stack.back() = content;
	}

	//////////////////////////////////////////////////////////////////////////
	void VariantLoadScope::set_float(const float &content)
	{
		if(_errorWas) return;
		assert(_stack.size() > 0);

		_stack.back() = content;
	}

	//////////////////////////////////////////////////////////////////////////
	void VariantLoadScope::set_integer(const std::string &content)
	{
		if(_errorWas) return;
		assert(_stack.size() > 0);

		size_t size = content.size();
		
		bool unsigned_ = false;
		size_t volume = 32;
		
		size_t posUI = content.find_first_of("ui");
		if(std::string::npos != posUI)
		{
			size_t pos = posUI;
			while(pos != size)
			{
				switch(content[pos])
				{
				case 'u':
					unsigned_ = true;
				case 'i':
					break;
				case '8':
					volume = 8;
					break;
				case '1':
					pos++;
					assert(content[pos]=='6');
					volume = 16;
					break;
				case '3':
					pos++;
					assert(content[pos]=='2');
					volume = 32;
					break;
				case '6':
					pos++;
					assert(content[pos]=='4');
					volume = 64;
					break;
				default:
					assert(0);
				}
				pos++;
				continue;
			}
			size = posUI;
		}

		const char *begin = content.data();

		bool radix16 = false;

		if(size>2 && begin[0] == '0' && begin[1]=='x')
		{
			radix16 = true;
			begin += 2;
			size -= 2;
		}

		switch(volume)
		{
		case 8:
			if(unsigned_)
			{
				boost::uint8_t n;
				if(radix16)	_xtoun(begin, n);
				else		_atoun(begin, n);
				_stack.back() = n;
			}
			else
			{
				boost::int8_t n;
				if(radix16)	_xtoun(begin, n);
				else		_aton(begin, n);
				_stack.back() = n;
			}
			break;
		case 16:
			if(unsigned_)
			{
				boost::uint16_t n;
				if(radix16)	_xtoun(begin, n);
				else		_atoun(begin, n);
				_stack.back() = n;
			}
			else
			{
				boost::int16_t n;
				if(radix16)	_xtoun(begin, n);
				else		_aton(begin, n);
				_stack.back() = n;
			}
			break;
		case 32:
			if(unsigned_)
			{
				boost::uint32_t n;
				if(radix16)	_xtoun(begin, n);
				else		_atoun(begin, n);
				_stack.back() = n;
			}
			else
			{
				boost::int32_t n;
				if(radix16)	_xtoun(begin, n);
				else		_aton(begin, n);
				_stack.back() = n;
			}
			break;
		case 64:
			if(unsigned_)
			{
				boost::uint64_t n;
				if(radix16)	_xtoun(begin, n);
				else		_atoun(begin, n);
				_stack.back() = n;
			}
			else
			{
				boost::int64_t n;
				if(radix16)	_xtoun(begin, n);
				else		_aton(begin, n);
				_stack.back() = n;
			}
			break;
		}
	}


	//////////////////////////////////////////////////////////////////////////
	void VariantLoadScope::set_bool(bool b)
	{
		if(_errorWas) return;
		assert(_stack.size() > 0);

		_stack.back() = b;
	}

	//////////////////////////////////////////////////////////////////////////
	void VariantLoadScope::array_start()
	{
		if(_errorWas) return;
		assert(_stack.size() > 0);

		_stack.back().as<Variant::DequeVariant>(true);
		_stack.push_back(Variant());
	}

	//////////////////////////////////////////////////////////////////////////
	void VariantLoadScope::array_push()
	{
		if(_errorWas) return;
		assert(_stack.size() > 1);

		Variant v;
		v.swap(_stack.back());
		_stack[_stack.size()-2].as<Variant::DequeVariant>().push_back(v);
	}

	//////////////////////////////////////////////////////////////////////////
	void VariantLoadScope::array_stop()
	{
		if(_errorWas) return;
		assert(_stack.size() > 1);

		_stack.pop_back();
	}

	//////////////////////////////////////////////////////////////////////////
	void VariantLoadScope::map_start()
	{
		if(_errorWas) return;
		assert(_stack.size() > 0);

		_stack.back().as<Variant::MapStringVariant>(true);
		_stack.push_back(Variant());

	}

	//////////////////////////////////////////////////////////////////////////
	void VariantLoadScope::map_key(const std::string &content)
	{
		if(_errorWas) return;
		assert(_stack.size() > 1);
		_mapKey = content;
	}

	//////////////////////////////////////////////////////////////////////////
	void VariantLoadScope::map_push()
	{
		if(_errorWas) return;
		assert(_stack.size() > 1);

		_stack[_stack.size()-2].as<Variant::MapStringVariant>()[_mapKey].swap(_stack.back());

	}

	//////////////////////////////////////////////////////////////////////////
	void VariantLoadScope::map_stop()
	{
		if(_errorWas) return;
		assert(_stack.size() > 1);

		_stack.pop_back();
	}



}
