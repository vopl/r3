#ifndef _DBMETA_PTRCONTAINER_HPP_
#define _DBMETA_PTRCONTAINER_HPP_

// #include <boost/multi_index_container.hpp>
// #include <boost/multi_index/member.hpp>
// #include <boost/multi_index/ordered_index.hpp>
// #include <boost/multi_index/random_access_index.hpp>

namespace dbMeta
{
	/*
	//очень т€желый дл€ компил€ции
	template <class Ptr>
	struct PtrContainer_nameExtractor
	{
		typedef const std::string result_type;
		result_type &operator()(const Ptr& r)const // operator() must be const
		{
			return r->_name;
		}
	};

	//////////////////////////////////////////////////////////////////////////
	template <class T, bool isSmart=false>
	class PtrContainer;

	template <class T>
	class PtrContainer<T, false>
		: public 
			boost::multi_index::multi_index_container<
				T*,
				boost::multi_index::indexed_by<
					boost::multi_index::random_access<>,
					boost::multi_index::ordered_non_unique<PtrContainer_nameExtractor<T*> >
				>
			>
	{
	};

	template <class T>
	class PtrContainer<T, true>
		: public 
			boost::multi_index::multi_index_container<
			boost::shared_ptr<T>,
				boost::multi_index::indexed_by<
					boost::multi_index::random_access<>,
					boost::multi_index::ordered_non_unique<PtrContainer_nameExtractor<boost::shared_ptr<T> > >
				>
			>
	{
	};
	*/




	//////////////////////////////////////////////////////////////////////////
	template <class Ptr, class ConstPtr>
	class PtrContainer
		: public std::vector<Ptr>
	{
		typedef std::vector<Ptr> Base;

		typedef std::multimap<std::string, Ptr> TMMap;
		TMMap _map;

	private:
		void insertToMap(const Ptr &c);
		void eraseFromMap(const Ptr &c);


	public:
		PtrContainer();
		PtrContainer(const PtrContainer &);
		template <class I> PtrContainer(const I &);

		Ptr operator[](size_type idx);
		const ConstPtr operator[](size_type idx) const;

		Ptr operator[](const char *name);
		const ConstPtr operator[](const char *name) const;

		Ptr operator[](const std::string &name);
		const ConstPtr operator[](const std::string &name) const;

		void resize ( size_type sz, Ptr c = Ptr() );

		template <class InputIterator>
		void assign ( InputIterator first, InputIterator last );
		void assign ( size_type n, const Ptr& u );

		void push_back ( const Ptr& x );
		void pop_back ( );

		iterator insert ( iterator position, const Ptr& x );
		void insert ( iterator position, size_type n, const Ptr& x );
		
		template <class InputIterator>
		void insert ( iterator position, InputIterator first, InputIterator last );

		iterator erase ( iterator position );
		iterator erase ( iterator first, iterator last );

		void swap ( PtrContainer<Ptr, ConstPtr>& cnt );
		void clear ( );
	};

	//////////////////////////////////////////////////////////////////////////
	template <class Ptr, class ConstPtr>
	void PtrContainer<Ptr, ConstPtr>::insertToMap(const Ptr &c)
	{
		_map.insert(std::make_pair(c->_name, c));
	}
	
	//////////////////////////////////////////////////////////////////////////
	template <class Ptr, class ConstPtr>
	void PtrContainer<Ptr, ConstPtr>::eraseFromMap(const Ptr &c)
	{
		TMMap::iterator iter = _map.find(c->_name);
		TMMap::iterator end = _map.end();
		for(; iter!=end; iter++)
		{
			if(iter->second == c)
			{
				_map.erase(iter);
				return;
			}
		}

		assert(!"элемент к удалению не найден");
		return;
	}


	//////////////////////////////////////////////////////////////////////////
	template <class Ptr, class ConstPtr>
	PtrContainer<Ptr, ConstPtr>::PtrContainer()
		: Base()
		, _map()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Ptr, class ConstPtr>
	PtrContainer<Ptr, ConstPtr>::PtrContainer(const PtrContainer &cnt)
		: Base(cnt)
		, _map(cnt._map)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Ptr, class ConstPtr>
	template <class I> 
	PtrContainer<Ptr, ConstPtr>::PtrContainer(const I &i)
		: Base(i)
		, _map()
	{
		iterator iter = begin();
		iterator end = end();
		for(; iter!=end; iter++)
		{
			_map[(*iter)->_name] = *iter;
		}
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Ptr, class ConstPtr>
	Ptr PtrContainer<Ptr, ConstPtr>::operator[](size_type idx)
	{
		if(idx < size())
		{
			return Base::operator [](idx);
		}
		return Ptr();
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Ptr, class ConstPtr>
	const ConstPtr PtrContainer<Ptr, ConstPtr>::operator[](size_type idx) const
	{
		if(idx < size())
		{
			return Base::operator [](idx);
		}
		return ConstPtr();
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Ptr, class ConstPtr>
	Ptr PtrContainer<Ptr, ConstPtr>::operator[](const char *name)
	{
		const std::string key(name);
		TMMap::iterator iter = _map.find(key);
		if(_map.end() != iter)
		{
			return *iter;
		}
		return Ptr();
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Ptr, class ConstPtr>
	const ConstPtr PtrContainer<Ptr, ConstPtr>::operator[](const char *name) const
	{
		const std::string key(name);
		TMMap::const_iterator iter = _map.find(key);
		if(_map.end() != iter)
		{
			return *iter;
		}
		return const Ptr();
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Ptr, class ConstPtr>
	Ptr PtrContainer<Ptr, ConstPtr>::operator[](const std::string &name)
	{
		const std::string key(name);
		TMMap::iterator iter = _map.find(name);
		if(_map.end() != iter)
		{
			return *iter;
		}
		return Ptr();
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Ptr, class ConstPtr>
	const ConstPtr PtrContainer<Ptr, ConstPtr>::operator[](const std::string &name) const
	{
		const std::string key(name);
		TMMap::const_iterator iter = _map.find(name);
		if(_map.end() != iter)
		{
			return *iter;
		}
		return ConstPtr();
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Ptr, class ConstPtr>
	void PtrContainer<Ptr, ConstPtr>::resize ( size_type sz, Ptr c = Ptr() )
	{
		if(sz < size())
		{
			for(size_type i(sz); i<size(); i++)
			{
				eraseFromMap(Base::operator [](i));
			}
		}
		else
		{
			for(size_type i(sz); i<size(); i++)
			{
				insertToMap(c);
			}
		}
		Base::resize(cz, c);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Ptr, class ConstPtr>
	template <class InputIterator>
	void PtrContainer<Ptr, ConstPtr>::assign ( InputIterator first, InputIterator last )
	{
		Base::assign(first, last);

		_map.clear();
		for(InputIterator iter=first; iter!=last; iter++)
		{
			insertToMap(*iter);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Ptr, class ConstPtr>
	void PtrContainer<Ptr, ConstPtr>::assign ( size_type n, const Ptr& u )
	{
		Base::assign(first, last);

		_map.clear();
		for(size_type i(0); i<n; i++)
		{
			insertToMap(u);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Ptr, class ConstPtr>
	void PtrContainer<Ptr, ConstPtr>::push_back ( const Ptr& x )
	{
		Base::push_back(x);
		insertToMap(x);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Ptr, class ConstPtr>
	void PtrContainer<Ptr, ConstPtr>::pop_back ( )
	{
		eraseFromMap(back());
		Base::pop_back();
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Ptr, class ConstPtr>
	typename PtrContainer<Ptr, ConstPtr>::iterator PtrContainer<Ptr, ConstPtr>::insert ( iterator position, const Ptr& x )
	{
		Base::insert(position, x);
		insertToMap(x);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Ptr, class ConstPtr>
	void PtrContainer<Ptr, ConstPtr>::insert ( iterator position, size_type n, const Ptr& x )
	{
		Base::insert(position, n, x);
		for(size_type i(0); i<n; i++)
		{
			insertToMap(x);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Ptr, class ConstPtr>
	template <class InputIterator>
	void PtrContainer<Ptr, ConstPtr>::insert ( iterator position, InputIterator first, InputIterator last )
	{
		Base::insert(position, first, last);
		for(InputIterator iter=first; iter!=last; iter++)
		{
			insertToMap(*iter);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Ptr, class ConstPtr>
	typename PtrContainer<Ptr, ConstPtr>::iterator PtrContainer<Ptr, ConstPtr>::erase ( iterator position )
	{
		eraseFromMap(*position);
		Base::erase(position);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Ptr, class ConstPtr>
	typename PtrContainer<Ptr, ConstPtr>::iterator PtrContainer<Ptr, ConstPtr>::erase ( iterator first, iterator last )
	{
		for(InputIterator iter=first; iter!=last; iter++)
		{
			eraseFromMap(*iter);
		}
		Base::erase(first, last);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Ptr, class ConstPtr>
	void PtrContainer<Ptr, ConstPtr>::swap ( PtrContainer<Ptr, ConstPtr>& cnt )
	{
		Base::swap(cnt);
		_map.swap(cnt);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Ptr, class ConstPtr>
	void PtrContainer<Ptr, ConstPtr>::clear ( )
	{
		Base::clear();
		_map.clear();
	}

}

#endif
