#ifndef _PGC_CONNECTIONPREPAREDS_HPP_
#define _PGC_CONNECTIONPREPAREDS_HPP_

#include "connectionProcessor.hpp"

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/member.hpp>

namespace pgc
{
	using namespace boost::multi_index;

	//////////////////////////////////////////////////////////////////////////
	class ConnectionPrepareds;
	typedef shared_ptr<ConnectionPrepareds> ConnectionPreparedsPtr;
	class ConnectionPrepareds
		: public ConnectionProcessor
	{
	private:
		//��������� ��������������� �������
		struct StatementPrepareState
		{
			//�������������
			std::string					_prid;
			//���������, � ���� ���������� �����, sql
			IStatementWtr				_stm;
			//����� ���������� �������
			boost::posix_time::ptime	_accessTime;
		};

		//���������, ������������ �� �������� � ������ �������
		typedef multi_index_container<
			StatementPrepareState,
			indexed_by<
				ordered_unique<
					member<
						StatementPrepareState, 
						IStatementWtr,
						&StatementPrepareState::_stm
					>
				>,
				ordered_non_unique<
					member<
						StatementPrepareState, 
						boost::posix_time::ptime,
						&StatementPrepareState::_accessTime
					>
				>
			> 
		> TPrepareds;

	private:
		//����������� �� ���������� ������������ �������� ��������
		static const size_t	_max = 1000;
		//������� �������� �� �����������
		static const size_t	_timeout = 1000*60*30;//millisec
		//����� �� ������ ������ ������
		posix_time::ptime	_now;
		//��������� � ���������
		TPrepareds			_prepareds;

	private:
		bool hasPrepared(IStatementWtr p);
		std::string getPrid(IStatementWtr p);
		void genPrid(IStatementWtr p);

		void cleanPrepareds(posix_time::ptime boundATime, function<void()> done);

	private:
		ConnectionPreparedsPtr shared_from_this();

	private:
		void onPrepare(IStatementPtr s,
			BindDataPtr data,
			boost::function<void (IResultPtr)> done,
			IResultPtr result,
			bool inTrans);

		void onSavepoint(IStatementPtr s,
			BindDataPtr data,
			boost::function<void (IResultPtr)> done,
			IResultPtr result);

		void onRollbackSavepoint(IStatementPtr s,
			BindDataPtr data,
			boost::function<void (IResultPtr)> done,
			IResultPtr result);

		void onReleaseSavepoint(IStatementPtr s,
			BindDataPtr data,
			boost::function<void (IResultPtr)> done,
			IResultPtr result);

	private:
		//�������
		enum ERequestType
		{
			ertQueryWithPrepare,
			ertCleanPrepareds,
		};
		struct SRequest
		{
			ERequestType	_ert;
			SRequest(ERequestType ert)
				: _ert(ert)
			{}
		};
		typedef shared_ptr<SRequest> SRequestPtr;

		struct SQueryWithPrepare
			: SRequest
		{
			IStatementPtr	_s;
			BindDataPtr		_data;
			TDone			_done;
			SQueryWithPrepare(IStatementPtr s, BindDataPtr data, TDone done)
				: SRequest(ertQueryWithPrepare), _s(s), _data(data), _done(done)
			{}
		};

		struct SCleanPrepareds
			: SRequest
		{
			function<void()> _done;
			SCleanPrepareds(function<void()> done)
				: SRequest(ertCleanPrepareds), _done(done)
			{}
		};

		typedef std::deque<SRequestPtr> TRequests;
		TRequests	_requests;

		void runNextRequest();
		void requestTerminator(TDone done, IResultPtr result);
		void cleanTerminator(function<void()> done);

	public:
		ConnectionPrepareds(PGconn *pgcon, asio::io_service &io_service);
		~ConnectionPrepareds();

		void beginWork();
		void endWork(function<void()> done);

		void runQueryWithPrepare(IStatementPtr s,
			BindDataPtr data,
			boost::function<void (IResultPtr)> done);
	};
}
#endif
