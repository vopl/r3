// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_model_Test_hpp_
#define _r3_model_Test_hpp_

#include "r3/schemaBase.hpp"

namespace r3
{
	class Model;
	namespace model
	{
		namespace s_Test
		{
			class Contract;
			typedef boost::shared_ptr<Contract> Contract_ptr;
			
			class Letter;
			typedef boost::shared_ptr<Letter> Letter_ptr;
			
			class ContractSimple;
			typedef boost::shared_ptr<ContractSimple> ContractSimple_ptr;
			
			class ContractComplex;
			typedef boost::shared_ptr<ContractComplex> ContractComplex_ptr;
			
			class Mockup;
			typedef boost::shared_ptr<Mockup> Mockup_ptr;
			
			class Service;
			typedef boost::shared_ptr<Service> Service_ptr;
			
			class Client;
			typedef boost::shared_ptr<Client> Client_ptr;
			
			class ServicePart;
			typedef boost::shared_ptr<ServicePart> ServicePart_ptr;
			
			class Stock;
			typedef boost::shared_ptr<Stock> Stock_ptr;
			
			class Furniture;
			typedef boost::shared_ptr<Furniture> Furniture_ptr;
			
			class Computer;
			typedef boost::shared_ptr<Computer> Computer_ptr;
			
			class Program;
			typedef boost::shared_ptr<Program> Program_ptr;
			
			class WebSite;
			typedef boost::shared_ptr<WebSite> WebSite_ptr;
			
			class People;
			typedef boost::shared_ptr<People> People_ptr;
			
			class Employee;
			typedef boost::shared_ptr<Employee> Employee_ptr;
			
			class Document;
			typedef boost::shared_ptr<Document> Document_ptr;
			
		}
		
		class Test;
		typedef boost::shared_ptr<Test> Test_ptr;
		
		class Test
			: public SchemaBase<Test>
		{
		
		public:
			s_Test::Contract_ptr	_Contract;
			s_Test::Letter_ptr	_Letter;
			s_Test::ContractSimple_ptr	_ContractSimple;
			s_Test::ContractComplex_ptr	_ContractComplex;
			s_Test::Mockup_ptr	_Mockup;
			s_Test::Service_ptr	_Service;
			s_Test::Client_ptr	_Client;
			s_Test::ServicePart_ptr	_ServicePart;
			s_Test::Stock_ptr	_Stock;
			s_Test::Furniture_ptr	_Furniture;
			s_Test::Computer_ptr	_Computer;
			s_Test::Program_ptr	_Program;
			s_Test::WebSite_ptr	_WebSite;
			s_Test::People_ptr	_People;
			s_Test::Employee_ptr	_Employee;
			s_Test::Document_ptr	_Document;
			
		public:
			Test(Model *model, const char *id)
				: SchemaBase<Test>(model, id, "Test")
			{
				init();
			}
			~Test()
			{}
			
			template <class Oper> void enumCategories(Oper o)
			{
				Test *s = (Test *)this;
				o(s, _Contract);
				o(s, _Letter);
				o(s, _ContractSimple);
				o(s, _ContractComplex);
				o(s, _Mockup);
				o(s, _Service);
				o(s, _Client);
				o(s, _ServicePart);
				o(s, _Stock);
				o(s, _Furniture);
				o(s, _Computer);
				o(s, _Program);
				o(s, _WebSite);
				o(s, _People);
				o(s, _Employee);
				o(s, _Document);
			}
			
			template <class C> boost::shared_ptr<C> getCategory();
			
			s_Test::Contract_ptr	getContract()
			{
				return _Contract;
			}
			
			s_Test::Letter_ptr	getLetter()
			{
				return _Letter;
			}
			
			s_Test::ContractSimple_ptr	getContractSimple()
			{
				return _ContractSimple;
			}
			
			s_Test::ContractComplex_ptr	getContractComplex()
			{
				return _ContractComplex;
			}
			
			s_Test::Mockup_ptr	getMockup()
			{
				return _Mockup;
			}
			
			s_Test::Service_ptr	getService()
			{
				return _Service;
			}
			
			s_Test::Client_ptr	getClient()
			{
				return _Client;
			}
			
			s_Test::ServicePart_ptr	getServicePart()
			{
				return _ServicePart;
			}
			
			s_Test::Stock_ptr	getStock()
			{
				return _Stock;
			}
			
			s_Test::Furniture_ptr	getFurniture()
			{
				return _Furniture;
			}
			
			s_Test::Computer_ptr	getComputer()
			{
				return _Computer;
			}
			
			s_Test::Program_ptr	getProgram()
			{
				return _Program;
			}
			
			s_Test::WebSite_ptr	getWebSite()
			{
				return _WebSite;
			}
			
			s_Test::People_ptr	getPeople()
			{
				return _People;
			}
			
			s_Test::Employee_ptr	getEmployee()
			{
				return _Employee;
			}
			
			s_Test::Document_ptr	getDocument()
			{
				return _Document;
			}
			
			
		};
		template <> s_Test::Contract_ptr	Test::getCategory<s_Test::Contract>()
		{
			return _Contract;
		}
		
		template <> s_Test::Letter_ptr	Test::getCategory<s_Test::Letter>()
		{
			return _Letter;
		}
		
		template <> s_Test::ContractSimple_ptr	Test::getCategory<s_Test::ContractSimple>()
		{
			return _ContractSimple;
		}
		
		template <> s_Test::ContractComplex_ptr	Test::getCategory<s_Test::ContractComplex>()
		{
			return _ContractComplex;
		}
		
		template <> s_Test::Mockup_ptr	Test::getCategory<s_Test::Mockup>()
		{
			return _Mockup;
		}
		
		template <> s_Test::Service_ptr	Test::getCategory<s_Test::Service>()
		{
			return _Service;
		}
		
		template <> s_Test::Client_ptr	Test::getCategory<s_Test::Client>()
		{
			return _Client;
		}
		
		template <> s_Test::ServicePart_ptr	Test::getCategory<s_Test::ServicePart>()
		{
			return _ServicePart;
		}
		
		template <> s_Test::Stock_ptr	Test::getCategory<s_Test::Stock>()
		{
			return _Stock;
		}
		
		template <> s_Test::Furniture_ptr	Test::getCategory<s_Test::Furniture>()
		{
			return _Furniture;
		}
		
		template <> s_Test::Computer_ptr	Test::getCategory<s_Test::Computer>()
		{
			return _Computer;
		}
		
		template <> s_Test::Program_ptr	Test::getCategory<s_Test::Program>()
		{
			return _Program;
		}
		
		template <> s_Test::WebSite_ptr	Test::getCategory<s_Test::WebSite>()
		{
			return _WebSite;
		}
		
		template <> s_Test::People_ptr	Test::getCategory<s_Test::People>()
		{
			return _People;
		}
		
		template <> s_Test::Employee_ptr	Test::getCategory<s_Test::Employee>()
		{
			return _Employee;
		}
		
		template <> s_Test::Document_ptr	Test::getCategory<s_Test::Document>()
		{
			return _Document;
		}
		
		
	}
}

#include "r3/model/Test/Contract.hpp"
#include "r3/model/Test/Letter.hpp"
#include "r3/model/Test/ContractSimple.hpp"
#include "r3/model/Test/ContractComplex.hpp"
#include "r3/model/Test/Mockup.hpp"
#include "r3/model/Test/Service.hpp"
#include "r3/model/Test/Client.hpp"
#include "r3/model/Test/ServicePart.hpp"
#include "r3/model/Test/Stock.hpp"
#include "r3/model/Test/Furniture.hpp"
#include "r3/model/Test/Computer.hpp"
#include "r3/model/Test/Program.hpp"
#include "r3/model/Test/WebSite.hpp"
#include "r3/model/Test/People.hpp"
#include "r3/model/Test/Employee.hpp"
#include "r3/model/Test/Document.hpp"

#endif
