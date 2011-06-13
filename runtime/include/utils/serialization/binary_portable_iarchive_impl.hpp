#ifndef BOOST_ARCHIVE_BINARY_PORTABLE_IARCHIVE_IMPL_HPP
#define BOOST_ARCHIVE_BINARY_PORTABLE_IARCHIVE_IMPL_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// binary_iarchive_impl.hpp

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for updates, documentation, and revision history.

#include <istream>
#include <boost/serialization/pfto.hpp>
#include <boost/archive/basic_binary_iprimitive.hpp>
#include <boost/archive/basic_binary_iarchive.hpp>

#include "utils/fixEndian.hpp"

#ifdef BOOST_MSVC
#  pragma warning(push)
#  pragma warning(disable : 4511 4512)
#endif

namespace utils { 
namespace serialization {

template<class Archive, class Elem, class Tr>
class binary_portable_iarchive_impl : 
    public boost::archive::basic_binary_iprimitive<Archive, Elem, Tr>,
    public boost::archive::basic_binary_iarchive<Archive>
{
#ifdef BOOST_NO_MEMBER_TEMPLATE_FRIENDS
public:
#else
    friend class boost::archive::detail::interface_iarchive<Archive>;
    friend class boost::archive::basic_binary_iarchive<Archive>;
    friend class boost::archive::load_access;
protected:
#endif
    // note: the following should not needed - but one compiler (vc 7.1)
    // fails to compile one test (test_shared_ptr) without it !!!
    // make this protected so it can be called from a derived archive
    template<class T>
    void load_override(T & t, BOOST_PFTO int){
        this->basic_binary_iarchive<Archive>::load_override(t, 0L);
    }
    void init(unsigned int flags){
        if(0 != (flags & boost::archive::no_header))
            return;
        #if ! defined(__MWERKS__)
            this->basic_binary_iarchive<Archive>::init();
            this->basic_binary_iprimitive<Archive, Elem, Tr>::init();
        #else
            basic_binary_iarchive<Archive>::init();
            basic_binary_iprimitive<Archive, Elem, Tr>::init();
        #endif
    }
    binary_portable_iarchive_impl(
        std::basic_streambuf<Elem, Tr> & bsb, 
        unsigned int flags
    ) :
        basic_binary_iprimitive<Archive, Elem, Tr>(
            bsb, 
            0 != (flags & boost::archive::no_codecvt)
        ),
        basic_binary_iarchive<Archive>(flags)
    {
        init(flags);
    }
    binary_portable_iarchive_impl(
        std::basic_istream<Elem, Tr> & is, 
        unsigned int flags
    ) :
        basic_binary_iprimitive<Archive, Elem, Tr>(
            * is.rdbuf(), 
            0 != (flags & boost::archive::no_codecvt)
        ),
        basic_binary_iarchive<Archive>(flags)
    {
        init(flags);
    }

public:
	// default saving of primitives.
	template<class T>
	void load(T & t)
	{
		boost::archive::basic_binary_iprimitive<Archive, Elem, Tr>::load(t);
	}

	void load(boost::int16_t & t)
	{
		boost::archive::basic_binary_iprimitive<Archive, Elem, Tr>::load(t);
		t = utils::fixEndian(t);
	}
	void load(boost::int32_t & t)
	{
		boost::archive::basic_binary_iprimitive<Archive, Elem, Tr>::load(t);
		t = utils::fixEndian(t);
	}
	void load(boost::int64_t & t)
	{
		boost::archive::basic_binary_iprimitive<Archive, Elem, Tr>::load(t);
		t = utils::fixEndian(t);
	}
	void load(boost::uint16_t & t)
	{
		boost::archive::basic_binary_iprimitive<Archive, Elem, Tr>::load(t);
		t = utils::fixEndian(t);
	}
	void load(boost::uint32_t & t)
	{
		boost::archive::basic_binary_iprimitive<Archive, Elem, Tr>::load(t);
		t = utils::fixEndian(t);
	}
	void load(boost::uint64_t & t)
	{
		boost::archive::basic_binary_iprimitive<Archive, Elem, Tr>::load(t);
		t = utils::fixEndian(t);
	}
	void load(float & t)
	{
		boost::archive::basic_binary_iprimitive<Archive, Elem, Tr>::load(t);
		t = utils::fixEndian(t);
	}
	void load(double & t)
	{
		boost::archive::basic_binary_iprimitive<Archive, Elem, Tr>::load(t);
		t = utils::fixEndian(t);
	}

};

} 
} 

#ifdef BOOST_MSVC
#pragma warning(pop)
#endif

#endif // BOOST_ARCHIVE_BINARY_IARCHIVE_IMPL_HPP
