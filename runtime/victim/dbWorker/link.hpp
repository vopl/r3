#ifndef _DBWORKER_LINK_HPP_
#define _DBWORKER_LINK_HPP_

namespace dbWorker
{
	//////////////////////////////////////////////////////////////////////////
	class Link
	{
		dbMeta::RelationEndCPtr _metaRelatioEnd;
	public:
		Link(dbMeta::RelationEndCPtr re);

		dbMeta::RelationEndCPtr meta() const;
	};
}

#endif
