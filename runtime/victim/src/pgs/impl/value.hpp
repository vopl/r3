#ifndef _PGS_IMPL_VALUE_HPP_
#define _PGS_IMPL_VALUE_HPP_

#include "expression.hpp"
#include "pgs/value.hpp"
#include "pgc/blob.hpp"

namespace pgs
{
	namespace impl
	{
		//////////////////////////////////////////////////////////////////////////
		class Value
			: public impl::Expression
		{
			EValueDataMode	_vdm;
			const void		*_data;
			int				_cdt;

			typedef void (Value:: *TDataDeleter)();

			TDataDeleter _dataDeleter;


			Value(const Value &);
			void operator=(const Value &);

			template <class CppType>
			void dataDeleter();

			void reset();

		public:
			Value();

			template <class CppType>
			Value(const CppType *v, EValueDataMode vdm);

			template <class CppType>
			Value(const CppType &v, EValueDataMode vdm);

			template <class CppType>
			void set(const CppType *v, EValueDataMode vdm);

			template <class CppType>
			void set(const CppType &v, EValueDataMode vdm);

			~Value();
		};
		typedef boost::shared_ptr<Value> Value_ptr;


		//////////////////////////////////////////////////////////////////////////
		template <class CppType>
		void Value::dataDeleter()
		{
			delete (CppType *)_data;
		}


		//////////////////////////////////////////////////////////////////////////
		template <class CppType>
		Value::Value(const CppType *v, EValueDataMode vdm)
			: _vdm(vdm_null)
			, _data(NULL)
			, _cdt(0)
			, _dataDeleter(NULL)
		{
			set(v, vdm);
		}

		template <class CppType>
		void Value::set(const CppType *v, EValueDataMode vdm)
		{
			reset();
			_vdm = vdm;
			if(vdm_makeCopy == _vdm)
			{
				if(v)
				{
					_dataDeleter = &Value::dataDeleter<CppType>;
					_data = new CppType(*v);
				}
			}
			else
			{
				if(vdm_doDeleteOnFree == _vdm)
				{
					_dataDeleter = &Value::dataDeleter<CppType>;
				}
				_data = v;
			}
			_cdt = pgc::CppDataType<CppType>::cdt_index;
		}

		template <class CppType>
		Value::Value(const CppType &v, EValueDataMode vdm)
			: _vdm(vdm_null)
			, _data(NULL)
			, _cdt(0)
			, _dataDeleter(NULL)
		{
			set(v, vdm);
		}

		template <class CppType>
		void Value::set(const CppType &v, EValueDataMode vdm)
		{
			reset();

			_vdm = vdm;
			if(vdm_makeCopy == _vdm)
			{
				_dataDeleter = &Value::dataDeleter<CppType>;
				_data = new CppType(v);
			}
			else
			{
				assert(vdm_doDeleteOnFree != _vdm);
				_data = &v;
			}
			_cdt = pgc::CppDataType<CppType>::cdt_index;
		}
	}
}
#endif
