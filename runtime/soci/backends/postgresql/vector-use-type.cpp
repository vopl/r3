//
// Copyright (C) 2004-2008 Maciej Sobczak, Stephen Hutton
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#include "StdAfx.h"

#define SOCI_POSTGRESQL_SOURCE
#include "soci-postgresql.h"
#include "common.h"
#include <libpq/libpq-fs.h> // libpq

#include "fromInternal2Db.hpp"

#ifdef SOCI_POSTGRESQL_NOPARAMS
#define SOCI_POSTGRESQL_NOBINDBYNAME
#endif // SOCI_POSTGRESQL_NOPARAMS

#ifdef _MSC_VER
#pragma warning(disable:4355 4996)
#define snprintf _snprintf
#endif

using namespace soci;
using namespace soci::details;
using namespace soci::details::postgresql;


void postgresql_vector_use_type_backend::bind_by_pos(int & position,
        void * data, exchange_type type)
{
    data_ = data;
    type_ = type;
    position_ = position++;
}

void postgresql_vector_use_type_backend::bind_by_name(
    std::string const & name, void * data, exchange_type type)
{
    data_ = data;
    type_ = type;
    name_ = name;
}

void postgresql_vector_use_type_backend::pre_use(indicator const * ind)
{
    std::size_t const vsize = size();
    for (size_t i = 0; i != vsize; ++i)
    {
		Oid		typ=0;		//type oid
		int		len=0;		//length of data in bytes
		int		fmt=0;		//text=0 or binary=1
		char	*val=NULL;	//data

        // the data in vector can be either i_ok or i_null
        if (ind != NULL && ind[i] == i_null)
        {
			typ = 0;
			len = 0;
			fmt = 0;
            val = NULL;
        }
        else
        {
            // allocate and fill the buffer with text-formatted client data
			//pre_use_switch<true>(type_, data_, typ, len, fmt, val);
			switch (type_)
			{
#define RST_ENTRY(i, t, n) case x2_##n: fromInternal2Db(static_cast<std::vector<SF##n> *>(data_)->operator[](i), typ, len, fmt, val); break;
#include "rawSimpleTypes/list.h"

		default:
			throw soci_error("Use element used with non-supported type.");
			};

        }

		assert(!"גלוסעו ס val ןנמגוסעט ושו typ, len, fmt");
        buffers_.push_back(val);
    }

    if (position_ > 0)
    {
        // binding by position
        statement_.useByPosBuffers_[position_] = &buffers_[0];
    }
    else
    {
        // binding by name
        statement_.useByNameBuffers_[name_] = &buffers_[0];
    }
}

std::size_t postgresql_vector_use_type_backend::size()
{
    std::size_t sz = 0; // dummy initialization to please the compiler
    switch (type_)
    {



#define RST_ENTRY(i,t,n) case x2_##n: sz = get_vector_size<SF##n>(data_); break;
#include "rawSimpleTypes/list.h"

    default:
        throw soci_error("Use vector element used with non-supported type.");
    }

    return sz;
}

void postgresql_vector_use_type_backend::clean_up()
{
    std::size_t const bsize = buffers_.size();
    for (std::size_t i = 0; i != bsize; ++i)
    {
        delete [] buffers_[i];
    }
}
