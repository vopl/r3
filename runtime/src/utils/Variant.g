grammar Variant;

options
{
    language = Cpp;
}

@parser::header
{
   #include "pch.hpp"
}

@parser::includes
{
   #include "VariantLexer.hpp"
}


@lexer::header
{
   #include "pch.hpp"
}

@lexer::includes
{
//   #include <iostream>
//   #include "helpers.hpp"
}


@lexer::namespace {	utils }
@parser::namespace{	utils }

@lexer::traits 
{
	class VariantLexer; 
	class VariantParser; 

	template<class ImplTraits>
	class UserTraits : public antlr3::CustomTraitsBase<ImplTraits>
	{
	public:
	    //for using the token stream which deleted the tokens, once it is reduced to a rule
		//but it leaves the start and stop tokens. So they can be accessed as usual
		static const bool TOKENS_ACCESSED_FROM_OWNING_RULE = false;
	};

	typedef antlr3::Traits< VariantLexer, VariantParser, UserTraits > VariantLexerTraits;
	typedef VariantLexerTraits VariantParserTraits;

	/* If you don't want the override it is like this.
	   class VariantLexer;
	   class VariantParser;
	   typedef antlr3::Traits< VariantLexer, VariantParser > VariantLexerTraits;
	   typedef VariantLexerTraits VariantParserTraits;
	 */
}


start
	: variant EOF;

variant
	: include
	| map
	| array
	| scalar
	;

include
	:	KW_INCLUDE  INCLUDE_STRING
	;

KW_INCLUDE
	:	'include'
	;
	
INCLUDE_STRING
	:	'"' INCLUDE_STRING_VALUE '"'
	;

fragment
INCLUDE_STRING_VALUE
	:	~'"'*
	;

map
	scope 
	{
		std::string _key; 
		//Variant	_value;
	}
	: 
	'{' (mapPair (',' mapPair)* ','?)? '}'
	;
	
mapPair
	: 
	key=mapPairKey (':' | '=' ) value=variant {$map::_key=$key.text; }
	;

mapPairKey
	:	IDENT|string
	;
	
array
	: 
	'[' (variant (',' variant)* ','?)? ']'
	;

scalar
	: null
	| string
	| uuid
	| bool_
	| dateTimeScope
	| dateScope
	| timeScope
	| float_
	| double_
	| integer
	;

IDENT
	: 
	(('a'..'z'|'A'..'Z'|'_'|'$') ('a'..'z'|'A'..'Z'|'0'..'9'|'_'|'$')*)
    ;

	

null
	: 'null';

string
	: '2STUB';

uuid
	: '3STUB';

bool_
	: 'sdfgsdf';

dateTimeScope
	: '5STUB';

dateScope
	: '6STUB';

timeScope
	: '7STUB';

float_
	: '8STUB';

double_
	: '9STUB';

integer
	: '10STUB';

//--------------------------
CMT
	: '/*' .* '*/'
	| '//' .* ('\r'|'\n')
	{$channel=HIDDEN;}
	;
	
WS  :   (' '|'\n'|'\r'|'\t')+ {$channel=HIDDEN;} ;
