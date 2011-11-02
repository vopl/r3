#ifndef _PGS_LINK_HPP_
#define _PGS_LINK_HPP_

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	class Link
	{
		pgs::meta::RelationEndCPtr _metaRelatioEnd;
	public:
		Link(pgs::meta::RelationEndCPtr re);

		pgs::meta::RelationEndCPtr meta() const;
	};
}

#endif
