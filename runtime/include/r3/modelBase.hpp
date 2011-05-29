#ifndef _R3_MODELBASE_HPP_
#define _R3_MODELBASE_HPP_

#include "pgc/connection.hpp"

#include <boost/thread/tss.hpp>

namespace r3
{
	class Model;

	class ModelBase
	{
		boost::thread_specific_ptr<pgc::Connection> _tcon;
	public:
		ModelBase();
		~ModelBase();

		void startInThread(const char *conninfo);
		void stopInThread();
		pgc::Connection con();

	protected:

		template <class SP>
		SP getSchemaImpl(std::map<std::string, SP> &m, const char *id)
		{
			SP &p = m[id];
			if(!p)
			{
				p.reset(new SP::value_type((Model *)this, id));
			}
			return p;
		}

	};
}

#endif
