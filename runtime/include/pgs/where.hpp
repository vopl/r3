#ifndef _PGS_WHERE_HPP_
#define _PGS_WHERE_HPP_

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	class Where
	{
	public:
		Where and(Where) const
		{
			return Where();
		}
		Where or(Where) const
		{
			return Where();
		}
	};
}
#endif
