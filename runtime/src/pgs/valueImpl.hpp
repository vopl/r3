#ifndef _PGS_VALUEIMPL_HPP_
#define _PGS_VALUEIMPL_HPP_

#include "exprImpl.hpp"
#include "pgs/value.hpp"
#include "pgc/blob.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	class ValueImpl
		: public ExprImpl
	{
		int		_dataMode;
		const void	*_data;
		int		_cdt;
		size_t	_number;

		typedef void (ValueImpl:: *TDataDeleter)();

		TDataDeleter _dataDeleter;


		ValueImpl(const ValueImpl &);
		void operator=(const ValueImpl &);

		template <class CppType>
		void dataDeleter();

		void reset();

	public:
		ValueImpl();

		template <class CppType>
		ValueImpl(const CppType *v, int dataMode = dsm_ptr|ddm_drop|dom_own);

		template <class CppType>
		void set(const CppType *v=NULL, int dataMode = dsm_ptr|ddm_drop|dom_own);

		template <class CppType>
		ValueImpl(const CppType &v, int dataMode = dsm_value);

		template <class CppType>
		void set(const CppType &v, int dataMode = dsm_value);

		~ValueImpl();

		void setNumber(size_t num);

		virtual void reg(StatementImpl *s);
		virtual void mkSql(std::string &result);
	};
	typedef boost::shared_ptr<ValueImpl> ValueImpl_ptr;


	//////////////////////////////////////////////////////////////////////////
	template <class CppType>
	void ValueImpl::dataDeleter()
	{
		delete (CppType *)_data;
	}


	//////////////////////////////////////////////////////////////////////////
	template <class CppType>
	ValueImpl::ValueImpl(const CppType *v, int dataMode)
		: _dataMode(0)
		, _data(NULL)
		, _cdt(0)
		, _dataDeleter(NULL)
	{
		set(v, dataMode);
	}

	template <class CppType>
	void ValueImpl::set(const CppType *v, int dataMode)
	{
		reset();

		_dataMode = dataMode;
		if(dm_isCopy & _dataMode)
		{
			if(v)
			{
				_dataDeleter = &ValueImpl::dataDeleter<CppType>;
				_data = new CppType(*v);
			}
		}
		else
		{
			if(dm_doDeleteOnFree & _dataMode)
			{
				_dataDeleter = &ValueImpl::dataDeleter<CppType>;
			}
			_data = v;
		}
		_cdt = pgc::CppDataType<CppType>::cdt_index;
	}

	template <class CppType>
	ValueImpl::ValueImpl(const CppType &v, int dataMode)
		: _dataMode(0)
		, _data(NULL)
		, _cdt(0)
		, _dataDeleter(NULL)
	{
		set(v, dataMode);
	}

	template <class CppType>
	void ValueImpl::set(const CppType &v, int dataMode)
	{
		reset();

		_dataMode = dataMode;
		if(dm_isCopy & _dataMode)
		{
			_dataDeleter = &ValueImpl::dataDeleter<CppType>;
			_data = new CppType(v);
		}
		else
		{
			assert(!(dm_doDeleteOnFree & _dataMode));
			_data = &v;
		}
		_cdt = pgc::CppDataType<CppType>::cdt_index;
	}


}
#endif
