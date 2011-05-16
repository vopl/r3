//
// Copyright (C) 2004-2008 Maciej Sobczak, Stephen Hutton
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#include "StdAfx.h"

#define SOCI_POSTGRESQL_SOURCE
#include "soci-postgresql.h"
#include "blob.h"
#include "rowid.h"
#include <soci-platform.h>
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

void postgresql_standard_use_type_backend::bind_by_pos(
    int & position, void * data, exchange_type type, bool /* readOnly */)
{
    // readOnly is ignored, because PostgreSQL does not support
    // any data to be written back to used (bound) objects.

    data_ = data;
    type_ = type;
    position_ = position++;
}

void postgresql_standard_use_type_backend::bind_by_name(
    std::string const & name, void * data, exchange_type type, bool /* readOnly */)
{
    // readOnly is ignored, because PostgreSQL does not support
    // any data to be written back to used (bound) objects.

    data_ = data;
    type_ = type;
    name_ = name;
}

void postgresql_standard_use_type_backend::pre_use(indicator const * ind)
{
    if (ind != NULL && *ind == i_null)
    {
        // leave the working buffer as NULL
    }
    else
    {
		/*
			вынести свич в отдельную функцю, параметризовать на вектор с индексом или сырое значение
		*/

		//char *val;
		//pre_use_switch<false>(type_, data_, typ, len, fmt, buf_);
		switch (type_)
		{
#define RST_ENTRY(i, t, n) case x2_##n: fromInternal2Db(*static_cast<SF##n *>(data_), pgtv_.typ, pgtv_.len, pgtv_.fmt, pgtv_.val); break;
#include "rawSimpleTypes/list.h"

		default:
			throw soci_error("Use element used with non-supported type.");
		};
    }

    if (position_ > 0)
    {
        // binding by position
        statement_.useByPosBuffers_[position_] = &pgtv_;
    }
    else
    {
        // binding by name
        statement_.useByNameBuffers_[name_] = &pgtv_;
    }
}

void postgresql_standard_use_type_backend::post_use(
    bool /* gotData */, indicator * /* ind */)
{
    // PostgreSQL does not support any data moving back the same channel,
    // so there is nothing to do here.
    // In particular, there is nothing to protect, because both const and non-const
    // objects will never be modified.

    // clean up the working buffer, it might be allocated anew in
    // the next run of preUse
    clean_up();
}

void postgresql_standard_use_type_backend::clean_up()
{
    if (pgtv_.val != NULL)
    {
        delete [] pgtv_.val;
        pgtv_.val = NULL;
    }
}
