#ifndef _PGS_SELECT_HPP_
#define _PGS_SELECT_HPP_

#include "pgs/where.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	class Select
	{
		Where _w;
// 		orderBy, limitOffset, 
	public:
// 		const string &sql();
// 		void bind(pgc::Statement stm);

		Select set(Where e){return *this;}
// 		Select set(OrderBy d){return *this;}
// 		Select set(LimitOffset e){return *this;}

	};


}
#endif
