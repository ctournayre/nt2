/*							chbevlf.c
 *
 *	Evaluate Chebyshev series
 *
 * 
 *
 * SYNOPSIS:
 *
 * int N;
 * float x, y, coef[N], chebevlf();
 *
 * y = cephes_chbevlf( x, coef, N );
 *
 *
 *
 * DESCRIPTION:
 *
 * Evaluates the series
 *
 *        N-1
 *         - '
 *  y  =   >   coef[i] T (x/2)
 *         -            i
 *        i=0
 *
 * of Chebyshev polynomials Ti at argument x/2.
 *
 * Coefficients are stored in reverse order, i.e. the zero
 * order term is last in the array.  Note N is the number of
 * coefficients, not the order.
 *
 * If coefficients are for the interval a to b, x must
 * have been transformed to x -> 2(2x - b - a)/(b-a) before
 * entering the routine.  This maps x from (a, b) to (-1, 1),
 * over which the Chebyshev polynomials are defined.
 *
 * If the coefficients are for the inverted interval, in
 * which (a, b) is mapped to (1/b, 1/a), the transformation
 * required is x -> 2(2ab/x - b - a)/(b-a).  If b is infinity,
 * this becomes x -> 4a/x - 1.
 *
 *
 *
 * SPEED:
 *
 * Taking advantage of the recurrence properties of the
 * Chebyshev polynomials, the routine requires one more
 * addition per loop than evaluating a nested polynomial of
 * the same degree.
 *
 */
/*							chbevl.c	*/

/*
Cephes Math Library Release 2.0:  April, 1987
Copyright 1985, 1987 by Stephen L. Moshier
Direct inquiries to 30 Frost Street, Cambridge, MA 02140
*/
#include "mconf.h"
#ifdef ANSIC
float cephes_chbevlf( float x, float *array, int n )
#else
float cephes_chbevlf( x, array, n )
float x;
float *array;
int n;
#endif
{
  float b0, b1, b2;
  const float *p;
int i;
p = array;
b0 = *p++;
b1 = 0.0;
i = n - 1;

do
	{
	b2 = b1;
	b1 = b0;
	b0 = x * b1  -  b2  + *p++;
	}
while( --i );
 
return( 0.5f*(b0-b2) );
}
