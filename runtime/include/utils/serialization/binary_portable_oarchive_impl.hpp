#ifndef BOOST_ARCHIVE_BINARY_PORTABLE_OARCHIVE_IMPL_HPP
#define BOOST_ARCHIVE_BINARY_PORTABLE_OARCHIVE_IMPL_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// binary_oarchive_impl.hpp

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com .
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for updates, documentation, and revision history.

#include <ostream>
#include <boost/config.hpp>
#include <boost/serialization/pfto.hpp>
#include <boost/archive/basic_binary_oprimitive.hpp>
#include <boost/archive/basic_binary_oarchive.hpp>

#include "utils/fixEndian.hpp"

#ifdef BOOST_MSVC
#  pragma warning(push)
#  pragma warning(disable : 4511 4512)
#endif

namespace utils {
namespace serialization {

template<class Archive, class Elem, class Tr>
class binary_portable_oarchive_impl :
	public boost::archive::basic_binary_oprimitive<Archive, Elem, Tr>,
	public boost::archive::basic_binary_oarchive<Archive>
{
#ifdef BOOST_NO_MEMBER_TEMPLATE_FRIENDS
public:
#else
	friend class boost::archive::detail::interface_oarchive<Archive>;
    friend class boost::archive::basic_binary_oarchive<Archive>;
    friend class boost::archive::save_access;
protected:
#endif
    // note: the following should not needed - but one compiler (vc 7.1)
    // fails to compile one test (test_shared_ptr) without it !!!
    // make this protected so it can be called from a derived archive
    template<class T>
    void save_override(T & t, BOOST_PFTO int){
        this->boost::archive::basic_binary_oarchive<Archive>::save_override(t, 0L);
    }
    void init(unsigned int flags) {
        if(0 != (flags & boost::archive::no_header))
            return;
        #if ! defined(__MWERKS__)
            this->boost::archive::basic_binary_oarchive<Archive>::init();
            this->boost::archive::basic_binary_oprimitive<Archive, Elem, Tr>::init();
        #else
            boost::archive::basic_binary_oarchive<Archive>::init();
            boost::archive::basic_binary_oprimitive<Archive, Elem, Tr>::init();
        #endif
    }
    binary_portable_oarchive_impl(
        std::basic_streambuf<Elem, Tr> & bsb,
        unsigned int flags
    ) :
        boost::archive::basic_binary_oprimitive<Archive, Elem, Tr>(
            bsb,
            0 != (flags & boost::archive::no_codecvt)
        ),
        boost::archive::basic_binary_oarchive<Archive>(flags)
    {
        init(flags);
    }
    binary_portable_oarchive_impl(
        std::basic_ostream<Elem, Tr> & os,
        unsigned int flags
    ) :
        boost::archive::basic_binary_oprimitive<Archive, Elem, Tr>(
            * os.rdbuf(),
            0 != (flags & boost::archive::no_codecvt)
        ),
        boost::archive::basic_binary_oarchive<Archive>(flags)
    {
        init(flags);
    }

public:
	// default saving of primitives.
	template<class T>
	void save(const T & t)
	{
		boost::archive::basic_binary_oprimitive<Archive, Elem, Tr>::save(t);
	}
	void save(const boost::int16_t & t)
	{
		boost::archive::basic_binary_oprimitive<Archive, Elem, Tr>::save(utils::fixEndian(t));
	}
	void save(const boost::int32_t & t)
	{
		boost::archive::basic_binary_oprimitive<Archive, Elem, Tr>::save(utils::fixEndian(t));
	}
	void save(const boost::int64_t & t)
	{
		boost::archive::basic_binary_oprimitive<Archive, Elem, Tr>::save(utils::fixEndian(t));
	}
	void save(const boost::uint16_t & t)
	{
		boost::archive::basic_binary_oprimitive<Archive, Elem, Tr>::save(utils::fixEndian(t));
	}
	void save(const boost::uint32_t & t)
	{
		boost::archive::basic_binary_oprimitive<Archive, Elem, Tr>::save(utils::fixEndian(t));
	}
	void save(const boost::uint64_t & t)
	{
		boost::archive::basic_binary_oprimitive<Archive, Elem, Tr>::save(utils::fixEndian(t));
	}
	void save(const float & t)
	{
		boost::archive::basic_binary_oprimitive<Archive, Elem, Tr>::save(utils::fixEndian(t));
	}
	void save(const double & t)
	{
		boost::archive::basic_binary_oprimitive<Archive, Elem, Tr>::save(utils::fixEndian(t));
	}
};

}
}

#ifdef BOOST_MSVC
#pragma warning(pop)
#endif

#endif // BOOST_ARCHIVE_BINARY_OARCHIVE_IMPL_HPP
