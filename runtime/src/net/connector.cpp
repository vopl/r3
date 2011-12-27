#include "pch.h"
#include "connector.hpp"

namespace net
{

	//////////////////////////////////////////////////////////////////////////
	std::string Connector::onSslPassword()
	{
		return "test";
	}

	//////////////////////////////////////////////////////////////////////////
	void Connector::connect_f(Result2<error_code, IChannelPtr> res, const std::string &host, const std::string &service, bool useSsl)
	{
		ILOG("connect to "<<host<<":"<<service<<", ssl="<<useSsl);
		TSslContextPtr sslContext;

		if(useSsl)
		{
			mutex::scoped_lock sl(_mtx);

			if(!_sslContext)
			{
				ILOG("create ssl context");
				sslContext.reset(new TSslContext(io(), ssl::context::sslv23));

				error_code ec;
				sslContext->set_options(
					ssl::context::default_workarounds
					| ssl::context::no_sslv2
					| ssl::context::single_dh_use, ec);
				assert(!ec);
				if(ec)
				{
					WLOG("set_options failed: "<<ec.message()<<"("<<ec.value()<<")");
					res(ec, IChannelPtr());
					return;
				}

				sslContext->set_password_callback(bind(&Connector::onSslPassword, shared_from_this()));
				sslContext->use_certificate_chain_file("server.pem", ec);
				assert(!ec);
				if(ec)
				{
					WLOG("use_certificate_chain_file failed: "<<ec.message()<<"("<<ec.value()<<")");
					res(ec, IChannelPtr());
					return;
				}

				sslContext->use_private_key_file("server.pem", ssl::context::pem, ec);
				assert(!ec);
				if(ec)
				{
					WLOG("use_private_key_file failed: "<<ec.message()<<"("<<ec.value()<<")");
					res(ec, IChannelPtr());
					return;
				}

				sslContext->use_tmp_dh_file("dh512.pem", ec);
				assert(!ec);
				if(ec)
				{
					WLOG("use_tmp_dh_file failed: "<<ec.message()<<"("<<ec.value()<<")");
					res(ec, IChannelPtr());
					return;
				}
				_sslContext = sslContext;
			}
			else
			{
				sslContext = _sslContext;
			}
		}

		error_code ec;
		//��������� �����
		ip::tcp::resolver resolver(io());

		Result2<error_code, ip::tcp::resolver::iterator> resolveRes;
		resolver.async_resolve(
			ip::tcp::resolver::query(host, service),
			resolveRes);
		ec = resolveRes.data1();

		if(ec)
		{
			//�������, ������� ��
			WLOG("async_resolve failed: "<<ec.message()<<"("<<ec.value()<<")");
			res(ec, IChannelPtr());
			return;
		}
		ip::tcp::resolver::iterator riter = resolveRes.data2();
		ip::tcp::resolver::iterator rend = ip::tcp::resolver::iterator();

		//������� �����
		TSocketSslPtr sockSsl;
		TSocketPtr sock;

		if(sslContext)
		{
			sockSsl.reset(new TSocketSsl(io(), *sslContext));
		}
		else
		{
			sock.reset(new TSocket(io()));
		}

		//����������
		ec = error_code();
		for(;;)
		{
			for(; riter!=rend; riter++)
			{
				Result<error_code> cres;

				if(sockSsl)
				{
					sockSsl->lowest_layer().async_connect(*riter, cres);
				}
				else
				{
					sock->async_connect(*riter, cres);
				}

				ec = cres;
				if(!ec)
				{
					break;
				}
				WLOG("async_connect failed: "<<ec.message()<<"("<<ec.value()<<")");
			}

			if(ec || riter==rend)
			{
				//�������, ������� ��
				res(ec, IChannelPtr());
				return;
			}

			if(sockSsl)
			{
				Result<error_code> hres;
				sockSsl->async_handshake(ssl::stream_base::server, hres);
				ec = hres;

				if(ec)
				{
					WLOG("handshake failed: "<<ec.message()<<"("<<ec.value()<<")");
					continue;
				}
				//�����
				WLOG("success");
				res(error_code(), IChannelPtr(new ChannelSocket(sockSsl, sslContext)));
				return;
			}
			else
			{
				//�����
				WLOG("success");
				res(error_code(), IChannelPtr(new ChannelSocket(sock)));
				return;
			}
		}

	}

	//////////////////////////////////////////////////////////////////////////
	Connector::Connector()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	Connector::~Connector()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	Result2<error_code, IChannelPtr> Connector::connect(const char *host, const char *service, bool useSsl)
	{
		async::Result2<error_code, IChannelPtr> res;
		spawn(bind(&Connector::connect_f, shared_from_this(), res, std::string(host), std::string(service), useSsl));
		return res;
	}

}