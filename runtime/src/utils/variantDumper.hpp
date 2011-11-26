#include <boost/foreach.hpp>

namespace utils
{





	template <class Container> std::ostream &dumpOstr_seq(std::ostream &ostr, const Container &c, size_t level, bool levelApplyed);
	template <class Container> std::ostream &dumpOstr_assoc(std::ostream &ostr, const Container &c, size_t level, bool levelApplyed);
	std::ostream &dumpOstr_variant(std::ostream &ostr, const Variant &v, size_t level, bool levelApplyed);


	//////////////////////////////////////////////////////////////////////////
	void dumpOstr_indent(std::ostream &ostr, size_t level, bool levelApplyed)
	{
		if(!levelApplyed)
		{
			for(size_t i(0); i<level; i++)
			{
				ostr<<"\t";
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////
	template <class T>
	std::ostream &dumpOstr(std::ostream &ostr, const T &v, size_t /*level*/, bool /*levelApplyed*/)
	{
		ostr<<v;
		return ostr;
	}

	//////////////////////////////////////////////////////////////////////////
	template <>
	std::ostream &dumpOstr<tm>(std::ostream &ostr, const tm &v, size_t /*level*/, bool /*levelApplyed*/)
	{
		ostr
			<<v.tm_year+1900<<"-"<<v.tm_mon+1<<"-"<<v.tm_mday
			<<" "

			<<v.tm_hour<<":"<<v.tm_min<<":"<<v.tm_sec
			<<" (wday="<<v.tm_wday
			<<", yday="<<v.tm_yday
			<<", isdst="<<v.tm_isdst<<")";

		return ostr;
	}

	//////////////////////////////////////////////////////////////////////////
	template <>
	std::ostream &dumpOstr<Variant>(std::ostream &ostr, const Variant &v, size_t level, bool levelApplyed)
	{
		return dumpOstr_variant(ostr, v, level, levelApplyed);
	}

	// std::ostream &operator <<(std::ostream &ostr, const Variant::VectorVariant &v);
	//////////////////////////////////////////////////////////////////////////
	template <>
	std::ostream &dumpOstr<Variant::VectorVariant>(std::ostream &ostr, const Variant::VectorVariant &v, size_t level, bool levelApplyed)
	{
		return dumpOstr_seq(ostr, v, level, levelApplyed);
	}

	// std::ostream &operator <<(std::ostream &ostr, const Variant::SetVariant &v);
	//////////////////////////////////////////////////////////////////////////
	template <>
	std::ostream &dumpOstr<Variant::SetVariant>(std::ostream &ostr, const Variant::SetVariant &v, size_t level, bool levelApplyed)
	{
		return dumpOstr_seq(ostr, v, level, levelApplyed);
	}

	// std::ostream &operator <<(std::ostream &ostr, const Variant::MultisetVariant &v);
	//////////////////////////////////////////////////////////////////////////
	template <>
	std::ostream &dumpOstr<Variant::MultisetVariant>(std::ostream &ostr, const Variant::MultisetVariant &v, size_t level, bool levelApplyed)
	{
		return dumpOstr_seq(ostr, v, level, levelApplyed);
	}

	// std::ostream &operator <<(std::ostream &ostr, const Variant::DequeVariant &v);
	//////////////////////////////////////////////////////////////////////////
	template <>
	std::ostream &dumpOstr<Variant::DequeVariant>(std::ostream &ostr, const Variant::DequeVariant &v, size_t level, bool levelApplyed)
	{
		return dumpOstr_seq(ostr, v, level, levelApplyed);
	}

	// std::ostream &operator <<(std::ostream &ostr, const Variant::ListVariant &v);
	//////////////////////////////////////////////////////////////////////////
	template <>
	std::ostream &dumpOstr<Variant::ListVariant>(std::ostream &ostr, const Variant::ListVariant &v, size_t level, bool levelApplyed)
	{
		return dumpOstr_seq(ostr, v, level, levelApplyed);
	}


	// std::ostream &operator <<(std::ostream &ostr, const Variant::MapStringVariant &v);
	//////////////////////////////////////////////////////////////////////////
	template <>
	std::ostream &dumpOstr<Variant::MapStringVariant>(std::ostream &ostr, const Variant::MapStringVariant &v, size_t level, bool levelApplyed)
	{
		return dumpOstr_assoc(ostr, v, level, levelApplyed);
	}

	// std::ostream &operator <<(std::ostream &ostr, const Variant::MapVariantVariant &v);
	//////////////////////////////////////////////////////////////////////////
	template <>
	std::ostream &dumpOstr<Variant::MapVariantVariant>(std::ostream &ostr, const Variant::MapVariantVariant &v, size_t level, bool levelApplyed)
	{
		return dumpOstr_assoc(ostr, v, level, levelApplyed);
	}

	// std::ostream &operator <<(std::ostream &ostr, const Variant::MultimapStringVariant &v);
	//////////////////////////////////////////////////////////////////////////
	template <>
	std::ostream &dumpOstr<Variant::MultimapStringVariant>(std::ostream &ostr, const Variant::MultimapStringVariant &v, size_t level, bool levelApplyed)
	{
		return dumpOstr_assoc(ostr, v, level, levelApplyed);
	}

	// std::ostream &operator <<(std::ostream &ostr, const Variant::MultimapVariantVariant &v);
	//////////////////////////////////////////////////////////////////////////
	template <>
	std::ostream &dumpOstr<Variant::MultimapVariantVariant>(std::ostream &ostr, const Variant::MultimapVariantVariant &v, size_t level, bool levelApplyed)
	{
		return dumpOstr_assoc(ostr, v, level, levelApplyed);
	}






	//////////////////////////////////////////////////////////////////////////
	std::ostream &dumpOstr_variant(std::ostream &ostr, const Variant &v, size_t level, bool levelApplyed)
	{
		if(v.isNull())
		{
			switch(v.type())
			{
			case Variant::etVoid: ostr<<"Void# Null"; break;

#define ENUMTYPES_ONE(T) case Variant::et ## T: ostr<< #T<<"# Null"; break;
				ENUMTYPES
#undef ENUMTYPES_ONE
			default:
				assert(!"bad et for dumpOstr_variant");
				throw "bad et for dumpOstr_variant";
			}
		}
		else
		{
			switch(v.type())
			{
			case Variant::etVoid: ostr<<"Void# <void>"; break;

#define ENUMTYPES_ONE(T) case Variant::et ## T: ostr<< #T<<"# "; dumpOstr(ostr, v.as<Variant::T>(), level, levelApplyed); break;
				ENUMTYPES
#undef ENUMTYPES_ONE
			default:
				assert(!"bad et for dumpOstr_variant");
				throw "bad et for dumpOstr_variant";
			}
		}

		return ostr;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Container>
	std::ostream &dumpOstr_seq(std::ostream &ostr, const Container &c, size_t level, bool levelApplyed)
	{
		dumpOstr_indent(ostr, level, levelApplyed);
		ostr<<"[\n";
		level++;

		BOOST_FOREACH(typename Container::const_reference v, c)
		{
			dumpOstr_indent(ostr, level, false);
			dumpOstr(ostr, v, level, true);
			ostr<<",\n";
		}

		level--;
		dumpOstr_indent(ostr, level, false);
		ostr<<"]";

		return ostr;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Container>
	std::ostream &dumpOstr_assoc(std::ostream &ostr, const Container &c, size_t level, bool levelApplyed)
	{
		dumpOstr_indent(ostr, level, levelApplyed);
		ostr<<"{\n";
		level++;

		BOOST_FOREACH(typename Container::const_reference v, c)
		{
			dumpOstr_indent(ostr, level, false);
			dumpOstr(ostr, v.first, level, true);
			ostr<<" => ";
			dumpOstr(ostr, v.second, level, true);
			ostr<<",\n";
		}

		level--;
		dumpOstr_indent(ostr, level, false);
		ostr<<"}";

		return ostr;
	}

















	//////////////////////////////////////////////////////////////////////////
	std::ostream &operator <<(std::ostream &ostr, const Variant &v)
	{
		return dumpOstr(ostr, v, 0, false);
	}

	//////////////////////////////////////////////////////////////////////////
	std::ostream &operator <<(std::ostream &ostr, const Variant::VectorVariant &v)
	{
		return dumpOstr(ostr, v, 0, false);
	}

	//////////////////////////////////////////////////////////////////////////
	std::ostream &operator <<(std::ostream &ostr, const Variant::MapStringVariant &v)
	{
		return dumpOstr(ostr, v, 0, false);
	}

	//////////////////////////////////////////////////////////////////////////
	std::ostream &operator <<(std::ostream &ostr, const Variant::MapVariantVariant &v)
	{
		return dumpOstr(ostr, v, 0, false);
	}

	//////////////////////////////////////////////////////////////////////////
	std::ostream &operator <<(std::ostream &ostr, const Variant::MultimapStringVariant &v)
	{
		return dumpOstr(ostr, v, 0, false);
	}

	//////////////////////////////////////////////////////////////////////////
	std::ostream &operator <<(std::ostream &ostr, const Variant::MultimapVariantVariant &v)
	{
		return dumpOstr(ostr, v, 0, false);
	}

	//////////////////////////////////////////////////////////////////////////
	std::ostream &operator <<(std::ostream &ostr, const Variant::SetVariant &v)
	{
		return dumpOstr(ostr, v, 0, false);
	}

	//////////////////////////////////////////////////////////////////////////
	std::ostream &operator <<(std::ostream &ostr, const Variant::MultisetVariant &v)
	{
		return dumpOstr(ostr, v, 0, false);
	}

	//////////////////////////////////////////////////////////////////////////
	std::ostream &operator <<(std::ostream &ostr, const Variant::DequeVariant &v)
	{
		return dumpOstr(ostr, v, 0, false);
	}

	//////////////////////////////////////////////////////////////////////////
	std::ostream &operator <<(std::ostream &ostr, const Variant::ListVariant &v)
	{
		return dumpOstr(ostr, v, 0, false);
	}
}