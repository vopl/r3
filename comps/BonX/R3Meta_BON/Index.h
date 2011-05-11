#ifndef R3META_BONINDEX_H
#define R3META_BONINDEX_H

#include "R3MetaBonX.h"


namespace R3Meta_BON
{
//*******************************************************************
//   C  L  A  S  S   IndexImpl
//*******************************************************************
class IndexImpl :
	  virtual public BON::AtomImpl
	, public CategoryMemberImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };
	virtual void        accept( BON::Visitor *pVisitor);
	typedef enum
	{
		tree_IndexType_Type,
		hash_IndexType_Type
	} IndexType_Type;

	//
	// connectionEnd getters
	virtual std::set<R3Meta_BON::IndexOnCategoryField> getInIndexOnCategoryFieldLinks();
	virtual std::multiset<R3Meta_BON::Field>          getIndexOnCategoryFieldSrcs();
	//
	// attribute getters and setters
	virtual R3Meta_BON::IndexImpl::IndexType_Type     getIndexType();
	virtual void        setIndexType( IndexImpl::IndexType_Type val);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


#endif
