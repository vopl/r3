#include "pch.h"
#include "dAgent.hpp"
#include <QtDeclarative/qdeclarative.h>

namespace client
{
	namespace qt
	{
		//////////////////////////////////////////////////////////////////////////
		IAgentHubPtr DAgent::_lowAgentHub;

		//////////////////////////////////////////////////////////////////////////
		void DAgent::LowAgent::onReceive(
			IAgentHubPtr hub,
			const server::TEndpoint &endpoint,
			utils::VariantPtr data)
		{
			_agent->onReceive_sig(hub, endpoint, data);
		}

		//////////////////////////////////////////////////////////////////////////
		DAgent::LowAgent::LowAgent(DAgent *agent)
			: _agent(agent)
		{
		}

		//////////////////////////////////////////////////////////////////////////
		void DAgent::onReceive_slot(
			IAgentHubPtr hub,
			const server::TEndpoint &endpoint,
			utils::VariantPtr data)
		{
			QVariant qtv;
			variantCnvt(qtv, *data);
			emit receive(qtv, QString::fromUtf8(endpoint.data(), endpoint.size()));
		}

		//////////////////////////////////////////////////////////////////////////
		void DAgent::variantCnvt(utils::Variant &dst, const QVariant &src)
		{
			if(src.isNull() || !src.isValid())
			{
				dst.setNull();
				return;
			}

			switch(src.type())
			{

			case QVariant::Bool:
				dst = src.toBool();
				break;
			case QVariant::Int:
				dst = src.toInt();
				break;
			case QVariant::UInt:
				dst = src.toUInt();
				break;
			case QVariant::LongLong:
				dst = src.toLongLong();
				break;
			case QVariant::ULongLong:
				dst = src.toULongLong();
				break;
			case QVariant::Double:
				dst = src.toDouble();
				break;
			case QVariant::Char:
				dst = src.toChar().unicode();
				break;
			case QVariant::Map:
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
			case QVariant::List:
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
			case QVariant::String:
				dst = src.toString().toUtf8().constData();
				break;
// 			case QVariant::StringList:
// 				break;
			case QVariant::ByteArray:
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
// 			case QVariant::BitArray:
// 				break;
			case QVariant::Date:
				{
					QDate qd = src.toDate();
					dst = utils::Variant::Date(qd.year(), qd.month()-1, qd.day());
				}
				break;
			case QVariant::Time:
				{
					QTime qt = src.toTime();
					dst = 
						boost::posix_time::hours(qt.hour())+
						boost::posix_time::minutes(qt.minute())+
						boost::posix_time::seconds(qt.second())+
						boost::posix_time::millisec(qt.msec());
				}
				break;
			case QVariant::DateTime:
				{
					QDateTime qdt = src.toDateTime();
					QDate qd = qdt.date();
					QTime qt = qdt.time();

					dst = utils::Variant::Time(
						utils::Variant::Date(qd.year(), qd.month()-1, qd.day()),
						boost::posix_time::hours(qt.hour())+
							boost::posix_time::minutes(qt.minute())+
							boost::posix_time::seconds(qt.second())+
							boost::posix_time::millisec(qt.msec()));
				}
				break;
// 			case QVariant::Url:
// 				break;
// 			case QVariant::Locale:
// 				break;
// 			case QVariant::Rect:
// 				break;
// 			case QVariant::RectF:
// 				break;
// 			case QVariant::Size:
// 				break;
// 			case QVariant::SizeF:
// 				break;
// 			case QVariant::Line:
// 				break;
// 			case QVariant::LineF:
// 				break;
// 			case QVariant::Point:
// 				break;
// 			case QVariant::PointF:
// 				break;
// 			case QVariant::RegExp:
// 				break;
			case QVariant::Hash:
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
// 			case QVariant::EasingCurve:
// 				break;
// 			case QVariant::Font:
// 				break;
// 			case QVariant::Pixmap:
// 				break;
// 			case QVariant::Brush:
// 				break;
// 			case QVariant::Color:
// 				break;
// 			case QVariant::Palette:
// 				break;
// 			case QVariant::Icon:
// 				break;
// 			case QVariant::Image:
// 				break;
// 			case QVariant::Polygon:
// 				break;
// 			case QVariant::Region:
// 				break;
// 			case QVariant::Bitmap:
// 				break;
// 			case QVariant::Cursor:
// 				break;
// 			case QVariant::SizePolicy:
// 				break;
// 			case QVariant::KeySequence:
// 				break;
// 			case QVariant::Pen:
// 				break;
// 			case QVariant::TextLength:
// 				break;
// 			case QVariant::TextFormat:
// 				break;
// 			case QVariant::Matrix:
// 				break;
// 			case QVariant::Transform:
// 				break;
// 			case QVariant::Matrix4x4:
// 				break;
// 			case QVariant::Vector2D:
// 				break;
// 			case QVariant::Vector3D:
// 				break;
// 			case QVariant::Vector4D:
// 				break;
// 			case QVariant::Quaternion:
// 				break;
// 			case QVariant::UserType:
// 				break;
			default:
				assert(!"unknown variant type");
				dst.setNull();
				break;
			}
		}

		//////////////////////////////////////////////////////////////////////////
		void DAgent::variantCnvt(const QVariant &dst, utils::Variant &src)
		{
			assert(0);
		}


		//////////////////////////////////////////////////////////////////////////
		DAgent::DAgent(QObject *parent)
		{
			connect(
				this, SIGNAL(onReceive_sig(IAgentHubPtr, const server::TEndpoint &, utils::VariantPtr)),
				this, SLOT(onReceive_slot(IAgentHubPtr, const server::TEndpoint &, utils::VariantPtr)),
				Qt::QueuedConnection);

			_lowAgent.reset(new LowAgent(this));
			_lowAgentHub->addAgent(_lowAgent);
		}

	
		//////////////////////////////////////////////////////////////////////////
		DAgent::~DAgent()
		{
			_lowAgentHub->delAgent(_lowAgent);
		}

		//////////////////////////////////////////////////////////////////////////
		void DAgent::send(QVariant data, QString service)
		{
			utils::VariantPtr pv(new utils::Variant);
			variantCnvt(*pv, data);
			_lowAgentHub->send(_lowAgent, std::string(service.toUtf8()), pv);
		}

	}
}
