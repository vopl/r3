#ifndef _PGS_META_PTRCONTAINER_HPP_
#define _PGS_META_PTRCONTAINER_HPP_

#include <vector>
#include <string>
#include <map>
#include <algorithm>


namespace pgs
{
	namespace meta
	{
		//////////////////////////////////////////////////////////////////////////
		template <class T>
		class PWrapper
		{
			T *_p;

		public:
			/////////////////////
			PWrapper()
				: _p(NULL)
			{
			}

			PWrapper(T *p)
				: _p(p)
			{

			}
			PWrapper(const PWrapper &pw)
				: _p(pw._p)
			{

			}

			/////////////////////
			T &operator *()
			{
				return *_p;
			}
			const T &operator *() const
			{
				return *_p;
			}

			/////////////////////
			T* operator->()
			{
				return _p;
			}
			const T* operator->() const
			{
				return _p;
			}

			/////////////////////
			operator T*()
			{
				return _p;
			}
			operator const T*() const
			{
				return _p;
			}

			/////////////////////
			template <class Y>
			operator Y*()
			{
				return static_cast<Y*>(_p);
			}
			template <class Y>
			operator const Y*() const
			{
				return static_cast<Y*>(_p);
			}

			/////////////////////
			bool operator == (const PWrapper &pw) const
			{
				return _p == pw._p;
			}
			/////////////////////
			bool operator != (const PWrapper &pw) const
			{
				return _p != pw._p;
			}
		};


		//////////////////////////////////////////////////////////////////////////
		template <class T>
		class PtrContainer
			: public std::vector<PWrapper<T> >
		{
		private:
			typedef PWrapper<T> Ptr;
			typedef std::vector<Ptr> Base;

			typedef std::multimap<std::string, Ptr> TMMap;
			TMMap _map;

		private:
			void insertToMap(const Ptr &c);
			void eraseFromMap(const Ptr &c);


		public:
			typedef typename Base::size_type size_type;
			typedef typename Base::iterator iterator;
		
		public:
			PtrContainer();
			PtrContainer(const PtrContainer &);
			template <class I> PtrContainer(const I &);

			Ptr operator[](size_type idx);
			const Ptr operator[](size_type idx) const;

			Ptr operator[](const char *name);
			const Ptr operator[](const char *name) const;

			Ptr operator[](const std::string &name);
			const Ptr operator[](const std::string &name) const;

			void resize ( size_type sz, Ptr c = Ptr() );

			template <class InputIterator>
			void assign ( InputIterator first, InputIterator last );
			void assign ( size_type n, const Ptr& u );

			void push_back ( const Ptr& x );
			void pop_back ( );

			void replace ( const Ptr& x );

			iterator insert ( iterator position, const Ptr& x );
			void insert ( iterator position, size_type n, const Ptr& x );

			template <class InputIterator>
			void insert ( iterator position, InputIterator first, InputIterator last );

			iterator erase ( iterator position );
			iterator erase ( iterator first, iterator last );

			void swap ( PtrContainer<T>& cnt );
			void clear ( );
		};

		//////////////////////////////////////////////////////////////////////////
		template <class T>
		void PtrContainer<T>::insertToMap(const Ptr &c)
		{
			_map.insert(std::make_pair(c->_name, c));
		}

		//////////////////////////////////////////////////////////////////////////
		template <class T>
		void PtrContainer<T>::eraseFromMap(const Ptr &c)
		{
			typename TMMap::iterator iter = _map.find(c->_name);
			typename TMMap::iterator end = _map.end();
			for(; iter!=end; iter++)
			{
				if(iter->second == c)
				{
					_map.erase(iter);
					return;
				}
			}

			assert(!"ГЅГ«ГҐГ¬ГҐГ­ГІ ГЄ ГіГ¤Г Г«ГҐГ­ГЁГѕ Г­ГҐ Г­Г Г©Г¤ГҐГ­");
			return;
		}


		//////////////////////////////////////////////////////////////////////////
		template <class T>
		PtrContainer<T>::PtrContainer()
			: Base()
			, _map()
		{
		}

		//////////////////////////////////////////////////////////////////////////
		template <class T>
		PtrContainer<T>::PtrContainer(const PtrContainer &cnt)
			: Base(cnt)
			, _map(cnt._map)
		{
		}

		//////////////////////////////////////////////////////////////////////////
		template <class T>
		template <class I> 
		PtrContainer<T>::PtrContainer(const I &i)
			: Base(i)
			, _map()
		{
			iterator iter = Base::begin();
			iterator end = Base::end();
			for(; iter!=end; iter++)
			{
				_map[(*iter)->_name] = *iter;
			}
		}

		//////////////////////////////////////////////////////////////////////////
		template <class T>
		typename PtrContainer<T>::Ptr PtrContainer<T>::operator[](size_type idx)
		{
			if(idx < Base::size())
			{
				return Base::operator [](idx);
			}
			return Ptr();
		}

		//////////////////////////////////////////////////////////////////////////
		template <class T>
		const typename PtrContainer<T>::Ptr PtrContainer<T>::operator[](size_type idx) const
		{
			if(idx < Base::size())
			{
				return Base::operator [](idx);
			}
			return Ptr();
		}

		//////////////////////////////////////////////////////////////////////////
		template <class T>
		typename PtrContainer<T>::Ptr PtrContainer<T>::operator[](const char *name)
		{
			const std::string key(name);
			typename TMMap::iterator iter = _map.find(key);
			if(_map.end() != iter)
			{
				return iter->second;
			}
			return Ptr();
		}

		//////////////////////////////////////////////////////////////////////////
		template <class T>
		const typename PtrContainer<T>::Ptr PtrContainer<T>::operator[](const char *name) const
		{
			const std::string key(name);
			typename TMMap::const_iterator iter = _map.find(key);
			if(_map.end() != iter)
			{
				return iter->second;
			}
			return Ptr();
		}

		//////////////////////////////////////////////////////////////////////////
		template <class T>
		typename PtrContainer<T>::Ptr PtrContainer<T>::operator[](const std::string &name)
		{
			typename TMMap::iterator iter = _map.find(name);
			if(_map.end() != iter)
			{
				return iter->second;
			}
			return Ptr();
		}

		//////////////////////////////////////////////////////////////////////////
		template <class T>
		const typename PtrContainer<T>::Ptr PtrContainer<T>::operator[](const std::string &name) const
		{
			typename TMMap::const_iterator iter = _map.find(name);
			if(_map.end() != iter)
			{
				return iter->second;
			}
			return Ptr();
		}

		//////////////////////////////////////////////////////////////////////////
		template <class T>
		void PtrContainer<T>::resize ( size_type sz, Ptr c)
		{
			size_type size = Base::size();
			if(sz < size)
			{
				for(size_type i(sz); i<size; i++)
				{
					eraseFromMap(Base::operator [](i));
				}
			}
			else
			{
				for(size_type i(sz); i<size; i++)
				{
					insertToMap(c);
				}
			}
			Base::resize(sz, c);
		}

		//////////////////////////////////////////////////////////////////////////
		template <class T>
		template <class InputIterator>
		void PtrContainer<T>::assign ( InputIterator first, InputIterator last )
		{
			Base::assign(first, last);

			_map.clear();
			for(InputIterator iter=first; iter!=last; iter++)
			{
				insertToMap(*iter);
			}
		}

		//////////////////////////////////////////////////////////////////////////
		template <class T>
		void PtrContainer<T>::assign ( size_type n, const Ptr& u )
		{
			Base::assign(n, u);

			_map.clear();
			for(size_type i(0); i<n; i++)
			{
				insertToMap(u);
			}
		}

		//////////////////////////////////////////////////////////////////////////
		template <class T>
		void PtrContainer<T>::push_back ( const Ptr& x )
		{
			Base::push_back(x);
			insertToMap(x);
		}

		//////////////////////////////////////////////////////////////////////////
		template <class T>
		void PtrContainer<T>::pop_back ( )
		{
			eraseFromMap(Base::back());
			Base::pop_back();
		}

		//////////////////////////////////////////////////////////////////////////
		template <class T>
		void PtrContainer<T>::replace ( const Ptr& x )
		{
			typename TMMap::iterator iter = _map.find(x->_name);
			if(_map.end() != iter)
			{
				*std::find(Base::begin(), Base::end(), iter->second) = x;
				iter->second = x;
			}
			else
			{
				assert(!"absent");
			}
		}


		//////////////////////////////////////////////////////////////////////////
		template <class T>
		typename PtrContainer<T>::iterator PtrContainer<T>::insert ( iterator position, const Ptr& x )
		{
			Base::insert(position, x);
			insertToMap(x);
		}

		//////////////////////////////////////////////////////////////////////////
		template <class T>
		void PtrContainer<T>::insert ( iterator position, size_type n, const Ptr& x )
		{
			Base::insert(position, n, x);
			for(size_type i(0); i<n; i++)
			{
				insertToMap(x);
			}
		}

		//////////////////////////////////////////////////////////////////////////
		template <class T>
		template <class InputIterator>
		void PtrContainer<T>::insert ( iterator position, InputIterator first, InputIterator last )
		{
			Base::insert(position, first, last);
			for(InputIterator iter=first; iter!=last; iter++)
			{
				insertToMap(*iter);
			}
		}

		//////////////////////////////////////////////////////////////////////////
		template <class T>
		typename PtrContainer<T>::iterator PtrContainer<T>::erase ( iterator position )
		{
			eraseFromMap(*position);
			Base::erase(position);
		}

		//////////////////////////////////////////////////////////////////////////
		template <class T>
		typename PtrContainer<T>::iterator PtrContainer<T>::erase ( iterator first, iterator last )
		{
			for(iterator iter=first; iter!=last; iter++)
			{
				eraseFromMap(*iter);
			}
			Base::erase(first, last);
		}

		//////////////////////////////////////////////////////////////////////////
		template <class T>
		void PtrContainer<T>::swap ( PtrContainer<T>& cnt )
		{
			Base::swap(cnt);
			_map.swap(cnt);
		}

		//////////////////////////////////////////////////////////////////////////
		template <class T>
		void PtrContainer<T>::clear ( )
		{
			Base::clear();
			_map.clear();
		}

	}
}

#endif
