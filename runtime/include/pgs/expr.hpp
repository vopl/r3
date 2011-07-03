#ifndef _PGS_EXPR_HPP_
#define _PGS_EXPR_HPP_

#include <boost/shared_ptr.hpp>

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	class ExprImpl;
	typedef boost::shared_ptr<ExprImpl> ExprImpl_ptr;

	//////////////////////////////////////////////////////////////////////////
	class Expr
	{
	protected:
		ExprImpl_ptr _impl;
	};


// 		Logical Operators
// 			AND 
// 			OR 
// 			NOT 
	Expr and(const Expr &a, const Expr &b);
	Expr or(const Expr &a, const Expr &b);
	Expr not(const Expr &a);

// 
// 		Comparison Operators
// 			<  less than 
// 			>  greater than 
// 			<=  less than or equal to 
// 			>=  greater than or equal to 
// 			=  equal 
// 			<> or !=  not equal 
// 			a BETWEEN x AND y
// 			a NOT BETWEEN x AND y
// 			expression IS NULL
// 			expression IS NOT NULL

	Expr lt(const Expr &a, const Expr &b);
	Expr gt(const Expr &a, const Expr &b);
	Expr le(const Expr &a, const Expr &b);
	Expr ge(const Expr &a, const Expr &b);
	Expr eq(const Expr &a, const Expr &b);
	Expr ne(const Expr &a, const Expr &b);
	Expr between(const Expr &a, const Expr &b, const Expr &c);
	Expr isNull(const Expr &a);

// 
// 		Mathematical Functions and Operators
// 			+  addition 2 + 3 5 
// 			-  subtraction 2 - 3 -1 
// 			*  multiplication 2 * 3 6 
// 			/  division (integer division truncates results) 4 / 2 2 
// 			%  modulo (remainder) 5 % 4 1 
// 			^  exponentiation 2.0 ^ 3.0 8 
// 			|/  square root |/ 25.0 5 
// 			||/  cube root ||/ 27.0 3 
// 			!  factorial 5 ! 120 
// 			!!  factorial (prefix operator) !! 5 120 
// 			@  absolute value @ -5.0 5 
// 			&  bitwise AND 91 & 15 11 
// 			|  bitwise OR 32 | 3 35 
// 			#  bitwise XOR 17 # 5 20 
// 			~  bitwise NOT ~1 -2 
// 			<<  bitwise shift left 1 << 4 16 
// 			>>  bitwise shift right 8 >> 2 2 

	Expr plus(const Expr &a, const Expr &b);
	Expr minus(const Expr &a, const Expr &b);
	Expr mul(const Expr &a, const Expr &b);
	Expr div(const Expr &a, const Expr &b);
	Expr mod(const Expr &a, const Expr &b);
	Expr exp(const Expr &a, const Expr &b);
	Expr sqrt(const Expr &a, const Expr &b);
	Expr curt(const Expr &a, const Expr &b);
	Expr fact(const Expr &a);
	Expr abs(const Expr &a);
	Expr band(const Expr &a, const Expr &b);
	Expr bor(const Expr &a, const Expr &b);
	Expr bxor(const Expr &a, const Expr &b);
	Expr bnot(const Expr &a);
	Expr shl(const Expr &a, const Expr &b);
	Expr shr(const Expr &a, const Expr &b);

// 
// 		Mathematical Functions
// 		Trigonometric Functions
// 			function("name", x,y,z)
	Expr func(const char *name);
	Expr func(const char *name, const Expr &a);
	Expr func(const char *name, const Expr &a, const Expr &b);
	Expr func(const char *name, const Expr &a, const Expr &b, const Expr &c);
	Expr func(const char *name, const Expr &a, const Expr &b, const Expr &c, const Expr &d);

// 
// 
// 
// 			string LIKE pattern [ESCAPE escape-character]
// 			string NOT LIKE pattern [ESCAPE escape-character]
	Expr like(const Expr &a, const Expr &b);

// 
// 			string SIMILAR TO pattern [ESCAPE escape-character]
// 			string NOT SIMILAR TO pattern [ESCAPE escape-character]
	Expr similar(const Expr &a, const Expr &b);
// 
// 			Regular Expression Match Operators
// 			~  Matches regular expression, case sensitive 'thomas' ~ '.*thomas.*' 
// 			~*  Matches regular expression, case insensitive 'thomas' ~* '.*Thomas.*' 
// 			!~  Does not match regular expression, case sensitive 'thomas' !~ '.*Thomas.*' 
// 			!~*  Does not match regular expression, case insensitive 'thomas' !~* '.*vadim.*' 
	Expr re_cs(const Expr &a, const Expr &b);
	Expr re_ci(const Expr &a, const Expr &b);

// 
// 
// 			CASE WHEN condition THEN result
// 				 [WHEN ...]
// 				 [ELSE result]
// 			END
	Expr casec(const Expr &c1, const Expr &r1);
	Expr casec(const Expr &c1, const Expr &r1, const Expr &el);
	Expr casec(const Expr &c1, const Expr &r1, const Expr &c2, const Expr &r2);
	Expr casec(const Expr &c1, const Expr &r1, const Expr &c2, const Expr &r2, const Expr &el);
	Expr casec(const Expr &c1, const Expr &r1, const Expr &c2, const Expr &r2, const Expr &c3, const Expr &r3);
	Expr casec(const Expr &c1, const Expr &r1, const Expr &c2, const Expr &r2, const Expr &c3, const Expr &r3, const Expr &el);
	Expr casec(const Expr &c1, const Expr &r1, const Expr &c2, const Expr &r2, const Expr &c3, const Expr &r3, const Expr &c4, const Expr &r4);
	Expr casec(const Expr &c1, const Expr &r1, const Expr &c2, const Expr &r2, const Expr &c3, const Expr &r3, const Expr &c4, const Expr &r4, const Expr &el);

// 
// 			CASE expression
// 				WHEN value THEN result
// 				[WHEN ...]
// 				[ELSE result]
// 			END
	Expr casee(const Expr &e, const Expr &v1, const Expr &r1);
	Expr casee(const Expr &e, const Expr &v1, const Expr &r1, const Expr &el);
	Expr casee(const Expr &e, const Expr &v1, const Expr &r1, const Expr &v2, const Expr &r2);
	Expr casee(const Expr &e, const Expr &v1, const Expr &r1, const Expr &v2, const Expr &r2, const Expr &el);
	Expr casee(const Expr &e, const Expr &v1, const Expr &r1, const Expr &v2, const Expr &r2, const Expr &v3, const Expr &r3);
	Expr casee(const Expr &e, const Expr &v1, const Expr &r1, const Expr &v2, const Expr &r2, const Expr &v3, const Expr &r3, const Expr &el);
	Expr casee(const Expr &e, const Expr &v1, const Expr &r1, const Expr &v2, const Expr &r2, const Expr &v3, const Expr &r3, const Expr &v4, const Expr &r4);
	Expr casee(const Expr &e, const Expr &v1, const Expr &r1, const Expr &v2, const Expr &r2, const Expr &v3, const Expr &r3, const Expr &v4, const Expr &r4, const Expr &el);

// 
// 			expression IN (subquery)
// 			expression NOT IN (subquery)
	Expr in(const Expr &a, const Expr &v1);
	Expr in(const Expr &a, const Expr &v1, const Expr &v2);
	Expr in(const Expr &a, const Expr &v1, const Expr &v2, const Expr &v3);
	Expr in(const Expr &a, const Expr &v1, const Expr &v2, const Expr &v3, const Expr &v4);

// 
// 			expression operator ANY (subquery)
// 
// 			x =any(array)
	Expr any(const Expr &a);

	Expr list(const Expr &v1, const Expr &v2);

}
#endif
