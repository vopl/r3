#ifndef _PGC_BINDDATA_HPP_
#define _PGC_BINDDATA_HPP_

#include "utils/variant.hpp"

namespace pgc
{
	class BindData
	{
		std::vector<Oid>	_bindTyp;
		std::vector<char *>	_bindVal;
		std::vector<int>	_bindLen;
		std::vector<int>	_bindFmt;

	public:
		BindData(const utils::Variant &data);
		~BindData();

		const std::vector<Oid> &	typ;
		const std::vector<char *> &	val;
		const std::vector<int> &	len;
		const std::vector<int> &	fmt;


	};
	typedef boost::shared_ptr<BindData> BindDataPtr;
}
#endif
