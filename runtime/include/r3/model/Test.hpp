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
			class Base4fields;
			typedef boost::shared_ptr<Base4fields> Base4fields_ptr;
			
			class Client;
			typedef boost::shared_ptr<Client> Client_ptr;
			
			class Computer;
			typedef boost::shared_ptr<Computer> Computer_ptr;
			
			class Contract;
			typedef boost::shared_ptr<Contract> Contract_ptr;
			
			class ContractComplex;
			typedef boost::shared_ptr<ContractComplex> ContractComplex_ptr;
			
			class ContractSimple;
			typedef boost::shared_ptr<ContractSimple> ContractSimple_ptr;
			
			class Derived4fields;
			typedef boost::shared_ptr<Derived4fields> Derived4fields_ptr;
			
			class Document;
			typedef boost::shared_ptr<Document> Document_ptr;
			
			class Employee;
			typedef boost::shared_ptr<Employee> Employee_ptr;
			
			class Furniture;
			typedef boost::shared_ptr<Furniture> Furniture_ptr;
			
			class Letter;
			typedef boost::shared_ptr<Letter> Letter_ptr;
			
			class Mockup;
			typedef boost::shared_ptr<Mockup> Mockup_ptr;
			
			class People;
			typedef boost::shared_ptr<People> People_ptr;
			
			class Program;
			typedef boost::shared_ptr<Program> Program_ptr;
			
			class Service;
			typedef boost::shared_ptr<Service> Service_ptr;
			
			class ServicePart;
			typedef boost::shared_ptr<ServicePart> ServicePart_ptr;
			
			class Stock;
			typedef boost::shared_ptr<Stock> Stock_ptr;
			
			class WebSite;
			typedef boost::shared_ptr<WebSite> WebSite_ptr;
			
		}
		
		class Test;
		typedef boost::shared_ptr<Test> Test_ptr;
		
		class Test
			: public SchemaBase<Test>
		{
		
		private:
			s_Test::Base4fields_ptr	_Base4fields;
			s_Test::Client_ptr	_Client;
			s_Test::Computer_ptr	_Computer;
			s_Test::Contract_ptr	_Contract;
			s_Test::ContractComplex_ptr	_ContractComplex;
			s_Test::ContractSimple_ptr	_ContractSimple;
			s_Test::Derived4fields_ptr	_Derived4fields;
			s_Test::Document_ptr	_Document;
			s_Test::Employee_ptr	_Employee;
			s_Test::Furniture_ptr	_Furniture;
			s_Test::Letter_ptr	_Letter;
			s_Test::Mockup_ptr	_Mockup;
			s_Test::People_ptr	_People;
			s_Test::Program_ptr	_Program;
			s_Test::Service_ptr	_Service;
			s_Test::ServicePart_ptr	_ServicePart;
			s_Test::Stock_ptr	_Stock;
			s_Test::WebSite_ptr	_WebSite;
			
		public:
			Test(Model *model, const char *id);
			~Test();
			
			template <class Oper> void enumCategories(Oper o);
			template <class C> boost::shared_ptr<C> getCategory();
			
			s_Test::Base4fields_ptr	getBase4fields();
			s_Test::Client_ptr	getClient();
			s_Test::Computer_ptr	getComputer();
			s_Test::Contract_ptr	getContract();
			s_Test::ContractComplex_ptr	getContractComplex();
			s_Test::ContractSimple_ptr	getContractSimple();
			s_Test::Derived4fields_ptr	getDerived4fields();
			s_Test::Document_ptr	getDocument();
			s_Test::Employee_ptr	getEmployee();
			s_Test::Furniture_ptr	getFurniture();
			s_Test::Letter_ptr	getLetter();
			s_Test::Mockup_ptr	getMockup();
			s_Test::People_ptr	getPeople();
			s_Test::Program_ptr	getProgram();
			s_Test::Service_ptr	getService();
			s_Test::ServicePart_ptr	getServicePart();
			s_Test::Stock_ptr	getStock();
			s_Test::WebSite_ptr	getWebSite();
			
		};
		
		
		//////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////
		inline Test::Test(Model *model, const char *id)
			: SchemaBase<Test>(model, id, "Test")
		{
			init();
		}
		inline Test::~Test()
		{
		}
		
		template <class Oper> void Test::enumCategories(Oper o)
		{
			Test *s = (Test *)this;
			o(s, _Base4fields);
			o(s, _Client);
			o(s, _Computer);
			o(s, _Contract);
			o(s, _ContractComplex);
			o(s, _ContractSimple);
			o(s, _Derived4fields);
			o(s, _Document);
			o(s, _Employee);
			o(s, _Furniture);
			o(s, _Letter);
			o(s, _Mockup);
			o(s, _People);
			o(s, _Program);
			o(s, _Service);
			o(s, _ServicePart);
			o(s, _Stock);
			o(s, _WebSite);
		}
		
		template <> inline s_Test::Base4fields_ptr	Test::getCategory<s_Test::Base4fields>()
		{
			return _Base4fields;
		}
		
		template <> inline s_Test::Client_ptr	Test::getCategory<s_Test::Client>()
		{
			return _Client;
		}
		
		template <> inline s_Test::Computer_ptr	Test::getCategory<s_Test::Computer>()
		{
			return _Computer;
		}
		
		template <> inline s_Test::Contract_ptr	Test::getCategory<s_Test::Contract>()
		{
			return _Contract;
		}
		
		template <> inline s_Test::ContractComplex_ptr	Test::getCategory<s_Test::ContractComplex>()
		{
			return _ContractComplex;
		}
		
		template <> inline s_Test::ContractSimple_ptr	Test::getCategory<s_Test::ContractSimple>()
		{
			return _ContractSimple;
		}
		
		template <> inline s_Test::Derived4fields_ptr	Test::getCategory<s_Test::Derived4fields>()
		{
			return _Derived4fields;
		}
		
		template <> inline s_Test::Document_ptr	Test::getCategory<s_Test::Document>()
		{
			return _Document;
		}
		
		template <> inline s_Test::Employee_ptr	Test::getCategory<s_Test::Employee>()
		{
			return _Employee;
		}
		
		template <> inline s_Test::Furniture_ptr	Test::getCategory<s_Test::Furniture>()
		{
			return _Furniture;
		}
		
		template <> inline s_Test::Letter_ptr	Test::getCategory<s_Test::Letter>()
		{
			return _Letter;
		}
		
		template <> inline s_Test::Mockup_ptr	Test::getCategory<s_Test::Mockup>()
		{
			return _Mockup;
		}
		
		template <> inline s_Test::People_ptr	Test::getCategory<s_Test::People>()
		{
			return _People;
		}
		
		template <> inline s_Test::Program_ptr	Test::getCategory<s_Test::Program>()
		{
			return _Program;
		}
		
		template <> inline s_Test::Service_ptr	Test::getCategory<s_Test::Service>()
		{
			return _Service;
		}
		
		template <> inline s_Test::ServicePart_ptr	Test::getCategory<s_Test::ServicePart>()
		{
			return _ServicePart;
		}
		
		template <> inline s_Test::Stock_ptr	Test::getCategory<s_Test::Stock>()
		{
			return _Stock;
		}
		
		template <> inline s_Test::WebSite_ptr	Test::getCategory<s_Test::WebSite>()
		{
			return _WebSite;
		}
		
		
		inline s_Test::Base4fields_ptr	Test::getBase4fields()
		{
			return _Base4fields;
		}
		
		inline s_Test::Client_ptr	Test::getClient()
		{
			return _Client;
		}
		
		inline s_Test::Computer_ptr	Test::getComputer()
		{
			return _Computer;
		}
		
		inline s_Test::Contract_ptr	Test::getContract()
		{
			return _Contract;
		}
		
		inline s_Test::ContractComplex_ptr	Test::getContractComplex()
		{
			return _ContractComplex;
		}
		
		inline s_Test::ContractSimple_ptr	Test::getContractSimple()
		{
			return _ContractSimple;
		}
		
		inline s_Test::Derived4fields_ptr	Test::getDerived4fields()
		{
			return _Derived4fields;
		}
		
		inline s_Test::Document_ptr	Test::getDocument()
		{
			return _Document;
		}
		
		inline s_Test::Employee_ptr	Test::getEmployee()
		{
			return _Employee;
		}
		
		inline s_Test::Furniture_ptr	Test::getFurniture()
		{
			return _Furniture;
		}
		
		inline s_Test::Letter_ptr	Test::getLetter()
		{
			return _Letter;
		}
		
		inline s_Test::Mockup_ptr	Test::getMockup()
		{
			return _Mockup;
		}
		
		inline s_Test::People_ptr	Test::getPeople()
		{
			return _People;
		}
		
		inline s_Test::Program_ptr	Test::getProgram()
		{
			return _Program;
		}
		
		inline s_Test::Service_ptr	Test::getService()
		{
			return _Service;
		}
		
		inline s_Test::ServicePart_ptr	Test::getServicePart()
		{
			return _ServicePart;
		}
		
		inline s_Test::Stock_ptr	Test::getStock()
		{
			return _Stock;
		}
		
		inline s_Test::WebSite_ptr	Test::getWebSite()
		{
			return _WebSite;
		}
		
		
	}
}

#include "r3/model/Test/Base4fields.hpp"
#include "r3/model/Test/Client.hpp"
#include "r3/model/Test/Computer.hpp"
#include "r3/model/Test/Contract.hpp"
#include "r3/model/Test/ContractComplex.hpp"
#include "r3/model/Test/ContractSimple.hpp"
#include "r3/model/Test/Derived4fields.hpp"
#include "r3/model/Test/Document.hpp"
#include "r3/model/Test/Employee.hpp"
#include "r3/model/Test/Furniture.hpp"
#include "r3/model/Test/Letter.hpp"
#include "r3/model/Test/Mockup.hpp"
#include "r3/model/Test/People.hpp"
#include "r3/model/Test/Program.hpp"
#include "r3/model/Test/Service.hpp"
#include "r3/model/Test/ServicePart.hpp"
#include "r3/model/Test/Stock.hpp"
#include "r3/model/Test/WebSite.hpp"

#endif
