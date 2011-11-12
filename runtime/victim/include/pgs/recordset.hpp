#ifndef _PGS_RECORDSET_HPP_
#define _PGS_RECORDSET_HPP_

namespace pgs
{
	class Meta;
	class Data;


	//////////////////////////////////////////////////////////////////////////
	class Meta
	{
	public://доступ к мета
		size_t fields();
		const std::string &name(size_t fieldIdx);
		EFieldType type(size_t fieldIdx);
		size_t index(const char *name);

		Data create(size_t size);
	};

	//////////////////////////////////////////////////////////////////////////
	class Data
	{
	public://доступ к данным
		size_t size();
		template <class T> T&value(size_t fieldIdx, size_t rowIdx);
		bool &null(size_t fieldIdx, size_t rowIdx);
	};

}
#endif
