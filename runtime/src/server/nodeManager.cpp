#include "pch.h"
#include "nodeManager.hpp"

namespace server
{
	//////////////////////////////////////////////////////////////////////////
	ITaskPtr NodeManager::findTask(const server::TEndpoint &endpoint)
	{
		TMNodes::iterator iter = _nodes.find(endpoint);
		if(_nodes.end() == iter)
		{
			//запрошеный путь не найден среди нодов
			return ITaskPtr();
		}
		INodePtr node = iter->second;
		if(!(enfTask & node->getFlags()))
		{
			//нода не содержит задачу
			return ITaskPtr();
		}
		return node->getTask();
	}

	//////////////////////////////////////////////////////////////////////////
	void NodeManager::onReceive(const boost::system::error_code &ec, const net::SPacket &p, ISessionPtr session)
	{
		if(ec)
		{
			if(ec == errc::operation_canceled)
			{
				return;
			}

			assert(0);
			WLOG(__FUNCTION__<<", "<<ec.message()<<"("<<ec.value()<<")");
			return;
		}

		server::TEndpoint serverEndpoint_;
		client::TEndpoint clientEndpoint_;
		utils::VariantPtr data_;
		ITaskPtr task_;
		bool serverEndpointExists = false;
		bool clientEndpointExists = false;
		bool dataExists = false;

		{
			//распарсить пакет, найти службу и передать ей
			utils::Variant v;
			if(	v.deserialize(p._data, p._size) &&
				v.is<utils::Variant::MapStringVariant>())
			{
				utils::Variant::MapStringVariant &m = v.as<utils::Variant::MapStringVariant>();
				utils::Variant serverEndpoint = m["server::endpoint"];

				if(serverEndpoint.is<TEndpoint>())
				{
					serverEndpoint_ = serverEndpoint.as<TEndpoint>();
					serverEndpointExists = true;
					{
						mutex::scoped_lock sl(_mtx);
						task_ = findTask(serverEndpoint_);
					}

					utils::Variant clientEndpoint = m["client::endpoint"];
					if(	clientEndpoint.is<client::TEndpoint>())
					{
						clientEndpoint_ = clientEndpoint.as<client::TEndpoint>();
						clientEndpointExists = true;
					}

					utils::Variant data = m["data"];
					if(data.is<utils::VariantPtr>())
					{
						data_ = data.as<utils::VariantPtr>();
						dataExists = true;
					}
				}
			}
		}


		if(task_ && dataExists && clientEndpointExists)
		{
			task_->call(
				shared_from_this(),
				session,
				clientEndpoint_,
				data_);
		}
		else
		{
// 			assert(!"log error?");

			if(clientEndpointExists && serverEndpointExists)
			{
				//запаковать данные
				utils::Variant v;
				utils::Variant::MapStringVariant &m = v.as<utils::Variant::MapStringVariant>(true);
				m["server::endpoint"] = serverEndpoint_;
				m["client::endpoint"] = clientEndpoint_;
				m["error"] = "badRequest";

				net::SPacket p;
				p._data = v.serialize(p._size);

				//отослать без контроля
				session->send(p);
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void NodeManager::addNode(INodePtr node, const server::TEndpoint &base)
	{
		server::TEndpoint endpoint = (base.empty()?"":base + '.') + node->getId();
		if(_nodes.end() == _nodes.find(endpoint))
		{
			_nodes[endpoint] = node;
			_nodesBack[node] = endpoint;

			node->onManagerAdd(shared_from_this());

			BOOST_FOREACH(const INodePtr &child, node->getChilds())
			{
				addNode(child, endpoint);
			}
		}
		else
		{
			assert(!"duplicate node id?");
			WLOG("duplicate node id?: "<<node->getId());
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void NodeManager::delNode(INodePtr node, const server::TEndpoint &base)
	{
		server::TEndpoint endpoint = (base.empty()?"":base + '.') + node->getId();
		TMNodes::iterator iter = _nodes.find(endpoint);
		if(_nodes.end() == iter)
		{
			BOOST_FOREACH(const INodePtr &child, node->getChilds())
			{
				delNode(child, endpoint);
			}

			node->onManagerDel(shared_from_this());
			_nodes.erase(iter);
			_nodesBack.erase(node);
		}
		else
		{
			assert(!"duplicate node id?");
		}
	}


	//////////////////////////////////////////////////////////////////////////
	NodeManager::NodeManager()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	NodeManager::~NodeManager()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	void NodeManager::setServer(IServerPtr server)
	{
		_server = server;
	}

	//////////////////////////////////////////////////////////////////////////
	IServerPtr NodeManager::getServer()
	{
		return _server;
	}


	//////////////////////////////////////////////////////////////////////////
	void NodeManager::addSession(ISessionPtr session)
	{
		{
			mutex::scoped_lock sl(_mtx);

			//оповестить службы
			BOOST_FOREACH(TMNodes::value_type &pair, _nodes)
			{
				if(enfService & pair.second->getFlags())
				{
					pair.second->getService()->onSessionAdd(session);
				}
			}
		}

		session->listen(bind(&NodeManager::onReceive, shared_from_this(), _1, _2, session));
	}

	//////////////////////////////////////////////////////////////////////////
	void NodeManager::delSession(ISessionPtr session)
	{

		{
			mutex::scoped_lock sl(_mtx);

			//оповестить службы
			BOOST_FOREACH(TMNodes::value_type &pair, _nodes)
			{
				if(enfService & pair.second->getFlags())
				{
					pair.second->getService()->onSessionDel(session);
				}
			}
		}
		//надо отменить прослушивание, а как? да вот так
		session->close();
	}

	//////////////////////////////////////////////////////////////////////////
	void NodeManager::addNode(INodePtr node)
	{
		mutex::scoped_lock sl(_mtx);
		addNode(node, "");
	}

	//////////////////////////////////////////////////////////////////////////
	void NodeManager::delNode(INodePtr node)
	{
		mutex::scoped_lock sl(_mtx);
		delNode(node, "");
	}

	//////////////////////////////////////////////////////////////////////////
	void NodeManager::delNodes()
	{
		mutex::scoped_lock sl(_mtx);
		BOOST_FOREACH(TMNodes::value_type &p, _nodes)
		{
			p.second->onManagerDel(shared_from_this());
		}
		_nodes.clear();
		_nodesBack.clear();
	}


	//////////////////////////////////////////////////////////////////////////
	async::Future<error_code> NodeManager::send(
		INodePtr node,
		ISessionPtr session,
		const client::TEndpoint &endpoint,
		utils::VariantPtr data)
	{
		//запаковать данные
		utils::Variant v;
		utils::Variant::MapStringVariant &m = v.as<utils::Variant::MapStringVariant>(true);
		{
			mutex::scoped_lock sl(_mtx);
			assert(_nodesBack.end() != _nodesBack.find(node));
			m["server::endpoint"] = _nodesBack.find(node)->second;
		}
		m["client::endpoint"] = endpoint;
		m["data"] = data;

		net::SPacket p;
		p._data = v.serialize(p._size);

		//отослать
		return session->send(p);
	}
}
