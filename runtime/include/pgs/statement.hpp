#ifndef _PGS_STATEMENT_HPP_
#define _PGS_STATEMENT_HPP_

#include "pgs/result.hpp"
#include <boost/shared_ptr.hpp>
#include "pgc/cppDataType.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	class StatementImpl;
	typedef boost::shared_ptr<StatementImpl> StatementImplPtr;

	//////////////////////////////////////////////////////////////////////////
	class Statement
		: public pgc::Statement
	{
	protected:
		typedef StatementImplPtr ImplPtr;

		friend class Select;
		Statement(ImplPtr impl);
	public:

		using pgc::Statement::bind;
		using pgc::Statement::bindList;
		using pgc::Statement::bindNative;
		using pgc::Statement::unbind;

		bool bindNative(int typCpp, void const *valCpp, const char *name);
		template <class T> Statement &bind(T const &v, const char *name);
		template <class T> Statement &bind(T const *pv, const char *name);
		Statement &bind(const utils::Variant &v, const char *name);

		template <class MapVariant> 
		Statement &bindMap(const MapVariant &v);

		Statement &unbind(const char *name);

		Result exec();
	};

	//////////////////////////////////////////////////////////////////////////
	template <class T> Statement &Statement::bind(T const &v, const char *name)
	{
		if(!bindNative(pgc::CppDataType<T>::cdt_index, &v, name))
		{
			throw std::invalid_argument("for Statement::bind");
		}
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class T> Statement &Statement::bind(T const *pv, const char *name)
	{
		if(!bindNative(pgc::CppDataType<T>::cdt_index, pv, name))
		{
			throw std::invalid_argument("for Statement::bind");
		}
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class MapVariant> 
	Statement &Statement::bindMap(const MapVariant &v)
	{
		MapVariant::const_iterator iter = v.begin();
		MapVariant::const_iterator end = v.end();

		for(; iter!=end; iter++)
		{
			if(!bindNative(iter->second.type(), iter->second.data(), iter->first.data()))
			{
				throw std::invalid_argument("for Statement::bindMap");
			}
		}
		return *this;
	}


}
#endif
