#ifndef _R3_RIGHTFILLERSERVER_HPP_
#define _R3_RIGHTFILLERSERVER_HPP_

namespace r3
{
	//////////////////////////////////////////////////////////////////////////
	template <>
	class RightFiller<true>
	{
		static boost::thread_specific_ptr<RightFiller<true> > _instance;
		boost::int64_t _user_id;
	public:
		RightFiller(boost::int64_t user_id)
			: _user_id(user_id)
		{
		}

		static RightFiller *instance()
		{
			return _instance.get();
		}
		static void setInstance(RightFiller *rf)
		{
			return _instance.reset(rf);
		}

		//////////////////////////////////////////////////////////////////////////
		struct enumOper_collectIds
		{
			std::vector<RightId> _ids;
			template <class Right> void operator()(Right right)
			{
				_ids.push_back(Right::tid);
			}
		};

		template <class Context>
		void fillRights(Context *ctx, const std::map<RightId, ERightValue> &rights)
		{
			//enum rights from ctx
			enumOper_collectIds o;
			Context::enumRights(o);
			o._ids;

			//select right values for user_id
			r3::data::s_V1::Right_ptr cat = r3::server::instance()->localSchema()->getRight();
			using namespace r3::data::s_V1;

			//cat->select().where(Right::stableId.in(o._ids) && Right::owner=_user_id).orderBy(Right::stableId).limit(1);
		}
	};
}

#endif
