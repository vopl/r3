grammar Variant;

options
{
    language = Cpp;
    k=10;
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

}



start
	: variant EOF;

variant
	: Include
	| map
	| array
	| scalar
	;


Include
	:	'include' WS* INCLUDE_STRING
	;

fragment
INCLUDE_STRING
	:	'"' INCLUDE_STRING_VALUE '"'
	;
	
fragment
INCLUDE_STRING_VALUE
	:	(~'"')*
	;

map
	: 
	'{' (mapPair (',' mapPair)* ','?)? '}'
	;
	
mapPair
	: 
		(String|Ident|Null|Bool) (':' | '=' ) variant
	;

array
	: 
	'[' (variant (',' variant)* ','?)? ']'
	;

scalar
	: Null
	| String
	| Uuid
	| Bool
	| Date
	| Time
	| DateTime
	| Float
	| Double
	| Integer;

Null	:	'null';

String
    : '"' ( ESC_SEQ | ~('\\'|'"') )* '"'
    | '\'' ( ESC_SEQ | ~('\\'|'\'') )* '\''
    ;

Uuid
	: '{' UuidValue '}'
	| UuidValue;

fragment
UuidValue :		
	HEX_DIGIT HEX_DIGIT HEX_DIGIT HEX_DIGIT HEX_DIGIT HEX_DIGIT HEX_DIGIT HEX_DIGIT 
	'-'
	HEX_DIGIT HEX_DIGIT HEX_DIGIT HEX_DIGIT 
	'-'
	HEX_DIGIT HEX_DIGIT HEX_DIGIT HEX_DIGIT 
	'-'
	HEX_DIGIT HEX_DIGIT HEX_DIGIT HEX_DIGIT 
	'-'
	HEX_DIGIT HEX_DIGIT HEX_DIGIT HEX_DIGIT HEX_DIGIT HEX_DIGIT HEX_DIGIT HEX_DIGIT HEX_DIGIT HEX_DIGIT HEX_DIGIT HEX_DIGIT 
	;
	
Bool
	: T R U E | T | O N | F A L S E | F | O F F;


Date
	: DIGIT DIGIT DIGIT DIGIT '-' DIGIT DIGIT '-' DIGIT DIGIT;

Time
	: DIGIT DIGIT ':' DIGIT DIGIT ':' DIGIT DIGIT ('.' DIGIT+)?;

DateTime
	: Date (' '|'T') Time;

Float
	: REAL 'f';

Double
	: REAL;

Integer
	: ('0x' HEX_DIGIT+ ('u' IntegerSize?)?)
	| (DIGIT+ (('ui'|'u'|'i') IntegerSize?)?)
	| ('-' DIGIT+ ('i' IntegerSize?)?)
	;

fragment
IntegerSize
	: '8'|'16'|'32'|'64'
	;


Ident
	: ('a'..'z'|'A'..'Z'|'_'|'$') ('a'..'z'|'A'..'Z'|'_'|'$'|'0'..'9')*;

//--------------------------
COMMENT
	: ('/*' .* '*/'
		| ('//'|'#') .* ('\r'|'\n')
	)
	{$channel=HIDDEN;}
	;
	
WHITESPACES  :   WS+ {$channel=HIDDEN;} ;

fragment
WS  :   (' '|'\n'|'\r'|'\t');


fragment
ESC_SEQ
    :   '\\' ('b'|'t'|'n'|'f'|'r'|'\"'|'\''|'\\')
    |   UNICODE_ESC
    |   OCTAL_ESC
    ;

fragment
OCTAL_ESC
    :   '\\' ('0'..'3') ('0'..'7') ('0'..'7')
    |   '\\' ('0'..'7') ('0'..'7')
    |   '\\' ('0'..'7')
    ;

fragment
UNICODE_ESC
    :   '\\' 'u' HEX_DIGIT HEX_DIGIT HEX_DIGIT HEX_DIGIT
    ;

fragment
HEX_DIGIT : ('0'..'9'|'a'..'f'|'A'..'F') ;

fragment
DIGIT : '0'..'9' ;

fragment
REAL
    :   DIGIT+ '.' DIGIT* EXPONENT?
    |   '.' DIGIT+ EXPONENT?
    |   DIGIT+ EXPONENT
    ;

fragment
EXPONENT : ('e'|'E') ('+'|'-')? ('0'..'9')+ ;

//--------------------------















fragment A:('a'|'A');
fragment B:('b'|'B');
fragment C:('c'|'C');
fragment D:('d'|'D');
fragment E:('e'|'E');
fragment F:('f'|'F');
fragment G:('g'|'G');
fragment H:('h'|'H');
fragment I:('i'|'I');
fragment J:('j'|'J');
fragment K:('k'|'K');
fragment L:('l'|'L');
fragment M:('m'|'M');
fragment N:('n'|'N');
fragment O:('o'|'O');
fragment P:('p'|'P');
fragment Q:('q'|'Q');
fragment R:('r'|'R');
fragment S:('s'|'S');
fragment T:('t'|'T');
fragment U:('u'|'U');
fragment V:('v'|'V');
fragment W:('w'|'W');
fragment X:('x'|'X');
fragment Y:('y'|'Y');
fragment Z:('z'|'Z');