#include "pch.h"
#include "agent.hpp"
#include <QtDeclarative/qdeclarative.h>
#include "mainWindow.hpp"

namespace client
{
	namespace qt
	{
		ISessionPtr	Agent::_staticSession;

		//////////////////////////////////////////////////////////////////////////
		void Agent::variantCnvt(utils::Variant &dst, const QVariant &src)
		{
			if(!src.isValid())
			{
				dst.forceType<void>();
				return;
			}

			bool isNull = src.isNull();
			switch(src.type())
			{
				//////////////////////////////////////////////////////////////////////////
			case QVariant::Bool:
				if(isNull)
				{
					dst.setNull<utils::Variant::Bool>();
				}
				else
				{
					dst.as<utils::Variant::Bool>(true) = src.toBool();
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case QVariant::Int:
				if(isNull)
				{
					dst.setNull<utils::Variant::Int32>();
				}
				else
				{
					dst.as<utils::Variant::Int32>(true) = src.toInt();
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case QVariant::UInt:
				if(isNull)
				{
					dst.setNull<utils::Variant::UInt32>();
				}
				else
				{
					dst.as<utils::Variant::UInt32>(true) = src.toUInt();
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case QVariant::LongLong:
				if(isNull)
				{
					dst.setNull<utils::Variant::Int64>();
				}
				else
				{
					dst.as<utils::Variant::Int64>(true) = src.toLongLong();
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case QVariant::ULongLong:
				if(isNull)
				{
					dst.setNull<utils::Variant::UInt64>();
				}
				else
				{
					dst.as<utils::Variant::UInt64>(true) = src.toULongLong();
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case QVariant::Double:
				if(isNull)
				{
					dst.setNull<utils::Variant::Double>();
				}
				else
				{
					dst.as<utils::Variant::Double>(true) = src.toDouble();
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case QVariant::Char:
				if(isNull)
				{
					dst.setNull<utils::Variant::Char>();
				}
				else
				{
					dst.as<utils::Variant::Char>(true) = src.toChar().toAscii();
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case QVariant::Map:
				if(isNull)
				{
					dst.setNull<utils::Variant::MapStringVariant>(true);
				}
				else
				{
					QMap<QString,QVariant> qm = src.toMap();

					utils::Variant::MapStringVariant &m = dst.as<utils::Variant::MapStringVariant>(true);
					m.clear();

					QMap<QString,QVariant>::const_iterator iter = qm.begin();
					QMap<QString,QVariant>::const_iterator end = qm.end();
					for(; iter!=end; iter++)
					{
						variantCnvt(m[iter.key().toUtf8().constData()], iter.value());
					}
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case QVariant::List:
				if(isNull)
				{
					dst.setNull<utils::Variant::DequeVariant>(true);
				}
				else
				{
					QList<QVariant> ql = src.toList();

					utils::Variant::DequeVariant &d = dst.as<utils::Variant::DequeVariant>(true);
					d.resize(ql.size());

					for(size_t i(0); i<d.size(); i++)
					{
						variantCnvt(d[i], ql[(int)i]);
					}
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case QVariant::String:
				if(isNull)
				{
					dst.setNull<utils::Variant::String>();
				}
				else
				{
					dst.as<utils::Variant::String>(true) = src.toString().toUtf8().constData();
				}
				break;
				//////////////////////////////////////////////////////////////////////////
// 			case QVariant::StringList:
// 				break;
				//////////////////////////////////////////////////////////////////////////
			case QVariant::ByteArray:
				if(isNull)
				{
					dst.setNull<utils::Variant::VectorChar>(true);
				}
				else
				{
					QByteArray qba = src.toByteArray();
					utils::Variant::VectorChar &vc = dst.as<utils::Variant::VectorChar>(true);
					vc.resize(qba.size());
					if(vc.size())
					{
						memcpy(&vc[0], qba.constData(), vc.size());
					}
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case QVariant::BitArray:
				if(isNull)
				{
					dst.setNull<utils::Variant::Bitset8>(true);
				}
				else
				{
					QBitArray qba = src.toBitArray();
					int srcSize = qba.size();

#define VAO(size)	if(srcSize <= size)																		\
					{																						\
						utils::Variant::Bitset##size &bs = dst.as<utils::Variant::Bitset##size>(true);		\
						for(int i(0); i<size; i++) bs[i] = qba[i];										\
					}	else																				//\

					VAO(8)
					VAO(16)
					VAO(32)
					VAO(64)
					VAO(128)
					VAO(256)
					VAO(512)
					{
						utils::Variant::Bitset512 &bs = dst.as<utils::Variant::Bitset512>(true);\
						for(int i(0); i<512; i++) bs[i] = qba[i];
					}
#undef VAO
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case QVariant::Date:
				if(isNull)
				{
					dst.setNull<utils::Variant::Date>(true);
				}
				else
				{
					QDate qd = src.toDate();
					dst.as<utils::Variant::Date>(true) = utils::Variant::Date(qd.year(), qd.month()-1, qd.day());
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case QVariant::Time:
				if(isNull)
				{
					dst.setNull<utils::Variant::TimeDuration>(true);
				}
				else
				{
					QTime qt = src.toTime();
					dst.as<utils::Variant::TimeDuration>(true) = 
						boost::posix_time::hours(qt.hour())+
						boost::posix_time::minutes(qt.minute())+
						boost::posix_time::seconds(qt.second())+
						boost::posix_time::millisec(qt.msec());
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case QVariant::DateTime:
				if(isNull)
				{
					dst.setNull<utils::Variant::Datetime>(true);
				}
				else
				{
					QDateTime qdt = src.toDateTime();
					QDate qd = qdt.date();
					QTime qt = qdt.time();

					dst.as<utils::Variant::Datetime>(true) = utils::Variant::Datetime(
						utils::Variant::Date(qd.year(), qd.month()-1, qd.day()),
						boost::posix_time::hours(qt.hour())+
							boost::posix_time::minutes(qt.minute())+
							boost::posix_time::seconds(qt.second())+
							boost::posix_time::millisec(qt.msec()));
				}
				break;
				//////////////////////////////////////////////////////////////////////////
// 			case QVariant::Url:
// 				break;
				//////////////////////////////////////////////////////////////////////////
// 			case QVariant::Locale:
// 				break;
				//////////////////////////////////////////////////////////////////////////
// 			case QVariant::Rect:
// 				break;
				//////////////////////////////////////////////////////////////////////////
// 			case QVariant::RectF:
// 				break;
				//////////////////////////////////////////////////////////////////////////
// 			case QVariant::Size:
// 				break;
				//////////////////////////////////////////////////////////////////////////
// 			case QVariant::SizeF:
// 				break;
				//////////////////////////////////////////////////////////////////////////
// 			case QVariant::Line:
// 				break;
				//////////////////////////////////////////////////////////////////////////
// 			case QVariant::LineF:
// 				break;
				//////////////////////////////////////////////////////////////////////////
// 			case QVariant::Point:
// 				break;
				//////////////////////////////////////////////////////////////////////////
// 			case QVariant::PointF:
// 				break;
				//////////////////////////////////////////////////////////////////////////
// 			case QVariant::RegExp:
// 				break;
				//////////////////////////////////////////////////////////////////////////
			case QVariant::Hash:
				if(isNull)
				{
					dst.setNull<utils::Variant::MapStringVariant>(true);
				}
				else
				{
					QHash<QString,QVariant> qm = src.toHash();

					utils::Variant::MapStringVariant &m = dst.as<utils::Variant::MapStringVariant>(true);
					m.clear();

					QHash<QString,QVariant>::const_iterator iter = qm.begin();
					QHash<QString,QVariant>::const_iterator end = qm.end();
					for(; iter!=end; iter++)
					{
						variantCnvt(m[iter.key().toUtf8().constData()], iter.value());
					}
				}
				break;
				//////////////////////////////////////////////////////////////////////////
// 			case QVariant::EasingCurve:
// 				break;
				//////////////////////////////////////////////////////////////////////////
// 			case QVariant::Font:
// 				break;
				//////////////////////////////////////////////////////////////////////////
// 			case QVariant::Pixmap:
// 				break;
				//////////////////////////////////////////////////////////////////////////
// 			case QVariant::Brush:
// 				break;
				//////////////////////////////////////////////////////////////////////////
// 			case QVariant::Color:
// 				break;
				//////////////////////////////////////////////////////////////////////////
// 			case QVariant::Palette:
// 				break;
				//////////////////////////////////////////////////////////////////////////
// 			case QVariant::Icon:
// 				break;
				//////////////////////////////////////////////////////////////////////////
// 			case QVariant::Image:
// 				break;
				//////////////////////////////////////////////////////////////////////////
// 			case QVariant::Polygon:
// 				break;
				//////////////////////////////////////////////////////////////////////////
// 			case QVariant::Region:
// 				break;
				//////////////////////////////////////////////////////////////////////////
// 			case QVariant::Bitmap:
// 				break;
				//////////////////////////////////////////////////////////////////////////
// 			case QVariant::Cursor:
// 				break;
				//////////////////////////////////////////////////////////////////////////
// 			case QVariant::SizePolicy:
// 				break;
				//////////////////////////////////////////////////////////////////////////
// 			case QVariant::KeySequence:
// 				break;
				//////////////////////////////////////////////////////////////////////////
// 			case QVariant::Pen:
// 				break;
				//////////////////////////////////////////////////////////////////////////
// 			case QVariant::TextLength:
// 				break;
				//////////////////////////////////////////////////////////////////////////
// 			case QVariant::TextFormat:
// 				break;
				//////////////////////////////////////////////////////////////////////////
// 			case QVariant::Matrix:
// 				break;
				//////////////////////////////////////////////////////////////////////////
// 			case QVariant::Transform:
// 				break;
				//////////////////////////////////////////////////////////////////////////
// 			case QVariant::Matrix4x4:
// 				break;
				//////////////////////////////////////////////////////////////////////////
// 			case QVariant::Vector2D:
// 				break;
				//////////////////////////////////////////////////////////////////////////
// 			case QVariant::Vector3D:
// 				break;
				//////////////////////////////////////////////////////////////////////////
// 			case QVariant::Vector4D:
// 				break;
				//////////////////////////////////////////////////////////////////////////
// 			case QVariant::Quaternion:
// 				break;
				//////////////////////////////////////////////////////////////////////////
// 			case QVariant::UserType:
// 				break;
				//////////////////////////////////////////////////////////////////////////
			default:
				qDebug()<<__FUNCTION__<<": unknown QVariant type";
				dst.setNull();
				break;
			}
		}

		//////////////////////////////////////////////////////////////////////////
		void Agent::variantCnvt(QVariant &dst, const utils::Variant &src)
		{
			bool isNull = src.isNull();

			switch(src.type())
			{
				//////////////////////////////////////////////////////////////////////////
			case utils::Variant::etUnknown:
				{
					dst.clear();
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case utils::Variant::etVoid:
				{
					dst.clear();
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case utils::Variant::etString:
				if(isNull)
				{
					dst = QVariant(QVariant::String);
				}
				else
				{
					dst = QString::fromUtf8(src.as<utils::Variant::String>().data());
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case utils::Variant::etFloat:
				if(isNull)
				{
					dst = QVariant(QVariant::Double);
				}
				else
				{
					dst = (utils::Variant::Double)src.as<utils::Variant::Float>();
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case utils::Variant::etDouble:
				if(isNull)
				{
					dst = QVariant(QVariant::Double);
				}
				else
				{
					dst = src.as<utils::Variant::Double>();
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case utils::Variant::etInt8:
				if(isNull)
				{
					dst = QVariant(QVariant::Int);
				}
				else
				{
					dst = src.as<utils::Variant::Int8>();
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case utils::Variant::etInt16:
				if(isNull)
				{
					dst = QVariant(QVariant::Int);
				}
				else
				{
					dst = src.as<utils::Variant::Int16>();
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case utils::Variant::etInt32:
				if(isNull)
				{
					dst = QVariant(QVariant::Int);
				}
				else
				{
					dst = src.as<utils::Variant::Int32>();
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case utils::Variant::etInt64:
				if(isNull)
				{
					dst = QVariant(QVariant::LongLong);
				}
				else
				{
					dst = src.as<utils::Variant::Int64>();
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case utils::Variant::etUInt8:
				if(isNull)
				{
					dst = QVariant(QVariant::UInt);
				}
				else
				{
					dst = src.as<utils::Variant::UInt8>();
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case utils::Variant::etUInt16:
				if(isNull)
				{
					dst = QVariant(QVariant::UInt);
				}
				else
				{
					dst = src.as<utils::Variant::UInt16>();
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case utils::Variant::etUInt32:
				if(isNull)
				{
					dst = QVariant(QVariant::UInt);
				}
				else
				{
					dst = src.as<utils::Variant::UInt32>();
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case utils::Variant::etUInt64:
				if(isNull)
				{
					dst = QVariant(QVariant::ULongLong);
				}
				else
				{
					dst = src.as<utils::Variant::UInt64>();
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case utils::Variant::etVectorChar:
				if(isNull)
				{
					dst = QVariant(QVariant::ByteArray);
				}
				else
				{
					const utils::Variant::VectorChar &vc = src.as<utils::Variant::VectorChar>();
					if(vc.empty())
					{
						dst = QByteArray();
					}
					else
					{
						dst = QByteArray(&vc[0], (int)vc.size());
					}
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case utils::Variant::etDate:
				if(isNull)
				{
					dst = QVariant(QVariant::Date);
				}
				else
				{
					const utils::Variant::Date &d = src.as<utils::Variant::Date>();
					dst = QDate(d.year(), d.month()+1, d.day());
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case utils::Variant::etDatetime:
				if(isNull)
				{
					dst = QVariant(QVariant::DateTime);
				}
				else
				{
					const utils::Variant::Datetime &dt = src.as<utils::Variant::Datetime>();

					const utils::Variant::Date d = dt.date();
					const utils::Variant::TimeDuration t = dt.time_of_day();

					dst = QDateTime(
						QDate(d.year(), d.month()+1, d.day()),
						QTime(t.hours(), t.minutes(), t.seconds(), t.fractional_seconds()*1000/t.ticks_per_second()));
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case utils::Variant::etVectorVariant:
				if(isNull)
				{
					dst = QVariant(QVariant::List);
				}
				else
				{
					const utils::Variant::VectorVariant &vv = src.as<utils::Variant::VectorVariant>();

					QList<QVariant> qlv;
					qlv.reserve((int)vv.size());
					for(size_t i(0); i<vv.size(); i++)
					{
						QVariant qv;
						variantCnvt(qv, vv[i]);
						qlv.push_back(qv);
					}
					dst = qlv;
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case utils::Variant::etMapStringVariant:
				if(isNull)
				{
					dst = QVariant(QVariant::Map);
				}
				else
				{
					const utils::Variant::MapStringVariant &msv = src.as<utils::Variant::MapStringVariant>();

					QMap<QString, QVariant> qmsv;

					utils::Variant::MapStringVariant::const_iterator iter = msv.begin();
					utils::Variant::MapStringVariant::const_iterator end = msv.end();
					for(; iter != end; iter++)
					{
						QVariant qv;
						variantCnvt(qv, iter->second);
						qmsv.insert(QString::fromUtf8(iter->first.c_str()), qv);
					}
					dst = qmsv;
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case utils::Variant::etBool:
				if(isNull)
				{
					dst = QVariant(QVariant::Bool);
				}
				else
				{
					dst = src.as<utils::Variant::Bool>();
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case utils::Variant::etTm:
				if(isNull)
				{
					dst = QVariant(QVariant::DateTime);
				}
				else
				{
					const utils::Variant::Tm &tm = src.as<utils::Variant::Tm>();

					dst = QDateTime(
						QDate(tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday),
						QTime(tm.tm_hour, tm.tm_min, tm.tm_sec));
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case utils::Variant::etBitset8:
				if(isNull)
				{
					dst = QVariant(QVariant::BitArray);
				}
				else
				{
					const utils::Variant::Bitset8 &bs = src.as<utils::Variant::Bitset8>();
					QBitArray qba((int)bs.size());

					for(int i(0); i<(int)bs.size(); i++)
					{
						qba[i] = bs[i];
					}

					dst = qba;
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case utils::Variant::etBitset16:
				if(isNull)
				{
					dst = QVariant(QVariant::BitArray);
				}
				else
				{
					const utils::Variant::Bitset16 &bs = src.as<utils::Variant::Bitset16>();
					QBitArray qba((int)bs.size());

					for(int i(0); i<(int)bs.size(); i++)
					{
						qba[i] = bs[i];
					}

					dst = qba;
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case utils::Variant::etBitset32:
				if(isNull)
				{
					dst = QVariant(QVariant::BitArray);
				}
				else
				{
					const utils::Variant::Bitset32 &bs = src.as<utils::Variant::Bitset32>();
					QBitArray qba((int)bs.size());

					for(int i(0); i<(int)bs.size(); i++)
					{
						qba[i] = bs[i];
					}

					dst = qba;
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case utils::Variant::etBitset64:
				if(isNull)
				{
					dst = QVariant(QVariant::BitArray);
				}
				else
				{
					const utils::Variant::Bitset64 &bs = src.as<utils::Variant::Bitset64>();
					QBitArray qba((int)bs.size());

					for(int i(0); i<(int)bs.size(); i++)
					{
						qba[i] = bs[i];
					}

					dst = qba;
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case utils::Variant::etBitset128:
				if(isNull)
				{
					dst = QVariant(QVariant::BitArray);
				}
				else
				{
					const utils::Variant::Bitset128 &bs = src.as<utils::Variant::Bitset128>();
					QBitArray qba((int)bs.size());

					for(int i(0); i<(int)bs.size(); i++)
					{
						qba[i] = bs[i];
					}

					dst = qba;
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case utils::Variant::etBitset256:
				if(isNull)
				{
					dst = QVariant(QVariant::BitArray);
				}
				else
				{
					const utils::Variant::Bitset256 &bs = src.as<utils::Variant::Bitset256>();
					QBitArray qba((int)bs.size());

					for(int i(0); i<(int)bs.size(); i++)
					{
						qba[i] = bs[i];
					}

					dst = qba;
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case utils::Variant::etBitset512:
				if(isNull)
				{
					dst = QVariant(QVariant::BitArray);
				}
				else
				{
					const utils::Variant::Bitset512 &bs = src.as<utils::Variant::Bitset512>();
					QBitArray qba((int)bs.size());

					for(int i(0); i<(int)bs.size(); i++)
					{
						qba[i] = bs[i];
					}

					dst = qba;
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case utils::Variant::etDateDuration:
				if(isNull)
				{
					dst = QVariant(QVariant::Date);
				}
				else
				{
					const utils::Variant::DateDuration &dd = src.as<utils::Variant::DateDuration>();

					dst = QDate(0,0,0).addDays(dd.days());
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case utils::Variant::etTimeDuration:
				if(isNull)
				{
					dst = QVariant(QVariant::Time);
				}
				else
				{
					const utils::Variant::TimeDuration &td = src.as<utils::Variant::TimeDuration>();

					dst = QTime(td.hours(), td.minutes(), td.seconds(), td.fractional_seconds()*1000/td.ticks_per_second());
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case utils::Variant::etDateTimeDuration:
				if(isNull)
				{
					dst = QVariant(QVariant::DateTime);
				}
				else
				{
					const utils::Variant::DateTimeDuration &dtd = src.as<utils::Variant::DateTimeDuration>();

					dst = QDateTime(
						QDate(0,0,0).addDays(dtd._dd.days()),
						QTime(dtd._td.hours(), dtd._td.minutes(), dtd._td.seconds(), dtd._td.fractional_seconds()*1000/dtd._td.ticks_per_second()));
				}
				break;
				//////////////////////////////////////////////////////////////////////////
// 			case utils::Variant::etMapVariantVariant:
// 				break;
				//////////////////////////////////////////////////////////////////////////
// 			case utils::Variant::etMultimapVariantVariant:
// 				break;
				//////////////////////////////////////////////////////////////////////////
			case utils::Variant::etMultimapStringVariant:
				if(isNull)
				{
					dst = QVariant(QVariant::Map);
				}
				else
				{
					const utils::Variant::MultimapStringVariant &msv = src.as<utils::Variant::MultimapStringVariant>();

					QMap<QString, QVariant> qmsv;

					utils::Variant::MultimapStringVariant::const_iterator iter = msv.begin();
					utils::Variant::MultimapStringVariant::const_iterator end = msv.end();
					for(; iter != end; iter++)
					{
						QVariant qv;
						variantCnvt(qv, iter->second);
						qmsv.insertMulti(QString::fromUtf8(iter->first.c_str()), qv);
					}
					dst = qmsv;
				}
				break;
				//////////////////////////////////////////////////////////////////////////
// 			case utils::Variant::etSetVariant:
// 				break;
				//////////////////////////////////////////////////////////////////////////
// 			case utils::Variant::etMultisetVariant:
// 				break;
				//////////////////////////////////////////////////////////////////////////
			case utils::Variant::etDequeVariant:
				if(isNull)
				{
					dst = QVariant(QVariant::List);
				}
				else
				{
					const utils::Variant::DequeVariant &dv = src.as<utils::Variant::DequeVariant>();

					QList<QVariant> qlv;
					qlv.reserve((int)dv.size());
					for(size_t i(0); i<dv.size(); i++)
					{
						QVariant qv;
						variantCnvt(qv, dv[i]);
						qlv.push_back(qv);
					}
					dst = qlv;
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case utils::Variant::etListVariant:
				if(isNull)
				{
					dst = QVariant(QVariant::List);
				}
				else
				{
					const utils::Variant::ListVariant &lv = src.as<utils::Variant::ListVariant>();

					QList<QVariant> qlv;
					qlv.reserve((int)lv.size());
					utils::Variant::ListVariant::const_iterator iter = lv.begin();
					for(size_t i(0); i<lv.size(); i++)
					{
						QVariant qv;
						variantCnvt(qv, *iter);
						qlv.push_back(qv);
						iter++;
					}
					dst = qlv;
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case utils::Variant::etChar:
				if(isNull)
				{
					dst = QVariant(QVariant::Char);
				}
				else
				{
					dst = QChar::fromAscii(src.as<utils::Variant::Char>());
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case utils::Variant::etUuid:
				if(isNull)
				{
					dst = QVariant(QVariant::ByteArray);
				}
				else
				{
					const utils::Variant::Uuid &uuid= src.as<utils::Variant::Uuid>();
					dst = QByteArray((const char *)uuid.begin(), (int)uuid.size());
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			case utils::Variant::etVariantPtr:
				if(isNull)
				{
					dst.clear();
				}
				else
				{
					variantCnvt(dst, *src.as<utils::Variant::VariantPtr>());
				}
				break;
				//////////////////////////////////////////////////////////////////////////
			default:
				qDebug()<<__FUNCTION__<<": unknown utils::Variant type";
				dst.clear();
			}
		}

		//////////////////////////////////////////////////////////////////////////
		void Agent::receiveLoop_f()
		{
			for(;;)
			{
				IAgentPtr agent = _agent;
				if(!agent)
				{
					return;
				}
				async::Result3<boost::system::error_code, server::TEndpoint, utils::VariantPtr> res;
				res = agent->receive();
				res.wait();
				if(res.data1())
				{
					assert(!_agent);
					return;
				}

				QString service = 
					QString::fromUtf8(res.data2().c_str(), res.data2().size());

				QVariant data;
				variantCnvt(data, res.data3());

				emit receive(data, service);
			}
		}

		//////////////////////////////////////////////////////////////////////////
		QString Agent::getService()
		{
			return _service;
		}
		
		//////////////////////////////////////////////////////////////////////////
		void Agent::setService(QString service)
		{
			_service = service;
		}

		//////////////////////////////////////////////////////////////////////////
		quint32 Agent::getNumChannels()
		{
			return _numChannels;
		}

		//////////////////////////////////////////////////////////////////////////
		Agent::Agent(QObject *parent)
			: QObject(parent)
		{
			_agent = _staticSession->allocAgent();
			assert(_agent);
			async::spawn(boost::bind(&Agent::receiveLoop_f, this));
		}

	
		//////////////////////////////////////////////////////////////////////////
		Agent::~Agent()
		{
			_agent.reset();
		}

		//////////////////////////////////////////////////////////////////////////
		void Agent::send(QVariant data, QString service)
		{
			if(service.isEmpty() || service.isNull())
			{
				service = _service;
			}

			utils::VariantPtr pv(new utils::Variant);
			variantCnvt(*pv, data);

			_agent->send(service.toUtf8().data(), pv);
		}
	}
}
