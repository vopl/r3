#ifndef _R3_CATEGORYBASE_HPP_
#define _R3_CATEGORYBASE_HPP_

namespace r3
{
	template <class C>
	class CategoryBase
	{
	public:
		void init(...);

		void dbCreateTable();
		void dbCreateFields();
		void dbCreateIndices();
		void dbCreateForeignFields();
		void dbCreateCrosses();
		void dbCreateForeignConstraints();
		void dbCreateViews();
	};
}

#endif
