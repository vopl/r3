#ifndef _PGS_EXPRESSION_HPP_
#define _PGS_EXPRESSION_HPP_

#include <boost/shared_ptr.hpp>
#include "pgc/api.h"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	class ExpressionImpl;
	typedef boost::shared_ptr<ExpressionImpl> ExpressionImplPtr;

	//////////////////////////////////////////////////////////////////////////
	class PG_API Expression
	{
	protected:
		typedef ExpressionImplPtr ImplPtr;
		ImplPtr _impl;
	};


	// 		Logical Operators
	// 			AND 
	// 			OR 
	// 			NOT 
	Expression and_(const Expression &a, const Expression &b);
	Expression or_(const Expression &a, const Expression &b);
	Expression not_(const Expression &a);

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

	Expression lt(const Expression &a, const Expression &b);
	Expression gt(const Expression &a, const Expression &b);
	Expression le(const Expression &a, const Expression &b);
	Expression ge(const Expression &a, const Expression &b);
	Expression eq(const Expression &a, const Expression &b);
	Expression ne(const Expression &a, const Expression &b);
	Expression between(const Expression &a, const Expression &b, const Expression &c);
	Expression isNull(const Expression &a);

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

	Expression plus(const Expression &a, const Expression &b);
	Expression minus(const Expression &a, const Expression &b);
	Expression mul(const Expression &a, const Expression &b);
	Expression div(const Expression &a, const Expression &b);
	Expression mod(const Expression &a, const Expression &b);
	Expression exp(const Expression &a, const Expression &b);
	Expression sqrt(const Expression &a, const Expression &b);
	Expression curt(const Expression &a, const Expression &b);
	Expression fact(const Expression &a);
	Expression abs(const Expression &a);
	Expression band(const Expression &a, const Expression &b);
	Expression bor(const Expression &a, const Expression &b);
	Expression bxor(const Expression &a, const Expression &b);
	Expression bnot(const Expression &a);
	Expression shl(const Expression &a, const Expression &b);
	Expression shr(const Expression &a, const Expression &b);

	// 
	// 		Mathematical Functions
	// 		Trigonometric Functions
	// 			function("name", x,y,z)
	Expression func(const char *name);
	Expression func(const char *name, const Expression &a);
	Expression func(const char *name, const Expression &a, const Expression &b);
	Expression func(const char *name, const Expression &a, const Expression &b, const Expression &c);
	Expression func(const char *name, const Expression &a, const Expression &b, const Expression &c, const Expression &d);

	// 
	// 
	// 
	// 			string LIKE pattern [ESCAPE escape-character]
	// 			string NOT LIKE pattern [ESCAPE escape-character]
	Expression like(const Expression &a, const Expression &b);

	// 
	// 			string SIMILAR TO pattern [ESCAPE escape-character]
	// 			string NOT SIMILAR TO pattern [ESCAPE escape-character]
	Expression similar(const Expression &a, const Expression &b);
	// 
	// 			Regular Expressionession Match Operators
	// 			~  Matches regular expression, case sensitive 'thomas' ~ '.*thomas.*' 
	// 			~*  Matches regular expression, case insensitive 'thomas' ~* '.*Thomas.*' 
	// 			!~  Does not match regular expression, case sensitive 'thomas' !~ '.*Thomas.*' 
	// 			!~*  Does not match regular expression, case insensitive 'thomas' !~* '.*vadim.*' 
	Expression re_cs(const Expression &a, const Expression &b);
	Expression re_ci(const Expression &a, const Expression &b);

	// 
	// 
	// 			CASE WHEN condition THEN result
	// 				 [WHEN ...]
	// 				 [ELSE result]
	// 			END
	Expression casec(const Expression &c1, const Expression &r1);
	Expression casec(const Expression &c1, const Expression &r1, const Expression &el);
	Expression casec(const Expression &c1, const Expression &r1, const Expression &c2, const Expression &r2);
	Expression casec(const Expression &c1, const Expression &r1, const Expression &c2, const Expression &r2, const Expression &el);
	Expression casec(const Expression &c1, const Expression &r1, const Expression &c2, const Expression &r2, const Expression &c3, const Expression &r3);
	Expression casec(const Expression &c1, const Expression &r1, const Expression &c2, const Expression &r2, const Expression &c3, const Expression &r3, const Expression &el);
	Expression casec(const Expression &c1, const Expression &r1, const Expression &c2, const Expression &r2, const Expression &c3, const Expression &r3, const Expression &c4, const Expression &r4);
	Expression casec(const Expression &c1, const Expression &r1, const Expression &c2, const Expression &r2, const Expression &c3, const Expression &r3, const Expression &c4, const Expression &r4, const Expression &el);

	// 
	// 			CASE expression
	// 				WHEN value THEN result
	// 				[WHEN ...]
	// 				[ELSE result]
	// 			END
	Expression casee(const Expression &e, const Expression &v1, const Expression &r1);
	Expression casee(const Expression &e, const Expression &v1, const Expression &r1, const Expression &el);
	Expression casee(const Expression &e, const Expression &v1, const Expression &r1, const Expression &v2, const Expression &r2);
	Expression casee(const Expression &e, const Expression &v1, const Expression &r1, const Expression &v2, const Expression &r2, const Expression &el);
	Expression casee(const Expression &e, const Expression &v1, const Expression &r1, const Expression &v2, const Expression &r2, const Expression &v3, const Expression &r3);
	Expression casee(const Expression &e, const Expression &v1, const Expression &r1, const Expression &v2, const Expression &r2, const Expression &v3, const Expression &r3, const Expression &el);
	Expression casee(const Expression &e, const Expression &v1, const Expression &r1, const Expression &v2, const Expression &r2, const Expression &v3, const Expression &r3, const Expression &v4, const Expression &r4);
	Expression casee(const Expression &e, const Expression &v1, const Expression &r1, const Expression &v2, const Expression &r2, const Expression &v3, const Expression &r3, const Expression &v4, const Expression &r4, const Expression &el);

	// 
	// 			expression IN (subquery)
	// 			expression NOT IN (subquery)
	Expression in(const Expression &a, const Expression &v1);
	Expression in(const Expression &a, const Expression &v1, const Expression &v2);
	Expression in(const Expression &a, const Expression &v1, const Expression &v2, const Expression &v3);
	Expression in(const Expression &a, const Expression &v1, const Expression &v2, const Expression &v3, const Expression &v4);

	// 
	// 			expression operator ANY (subquery)
	// 
	// 			x =any(array)
	Expression any(const Expression &a);

	Expression list(const Expression &v1, const Expression &v2);

}
#endif
