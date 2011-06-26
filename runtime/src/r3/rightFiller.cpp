#include "stdafx.h"
#include "r3/rightFiller.hpp"

namespace r3
{
	boost::thread_specific_ptr<RightFiller<true> > RightFiller<true>::_instance;
}