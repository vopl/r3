#include "Stdafx.h"
#include "workers/wSchema.hpp"

namespace workers
{
	WSchema::WSchema()
	{

	}
	WSchema::~WSchema()
	{

	}

	void WSchema::operator()(const Schema &s)
	{
		std::set<Category> cats = s->getCategory();

	}
}
