/*							ellpjf.c
 *
 *	Jacobian Elliptic Functions
 *
 *
 *
 * SYNOPSIS:
 *
 * float u, m, sn, cn, dn, phi;
 * int ellpj();
 *
 * ellpj( u, m, _&sn, _&cn, _&dn, _&phi );
 *
 *
 *
 * DESCRIPTION:
 *
 *
 * Evaluates the Jacobian elliptic functions sn(u|m), cn(u|m),
 * and dn(u|m) of parameter m between 0 and 1, and real
 * argument u.
 *
 * These functions are periodic, with quarter-period on the
 * real axis equal to the complete elliptic integral
 * ellpk(1.0-m).
 *
 * Relation to incomplete elliptic integral:
 * If u = ellik(phi,m), then sn(u|m) = sin(phi),
 * and cn(u|m) = cos(phi).  Phi is called the amplitude of u.
 *
 * Computation is by means of the arithmetic-geometric mean
 * algorithm, except when m is within 1e-9 of 0 or 1.  In the
 * latter case with m close to 1, the approximation applies
 * only for phi < pi/2.
 *
 * ACCURACY:
 *
 * Tested at random points with u between 0 and 10, m between
 * 0 and 1.
 *
 *            Absolute error (* = relative error):
 * arithmetic   function   # trials      peak         rms
 *    IEEE      sn          10000       1.7e-6      2.2e-7
 *    IEEE      cn          10000       1.6e-6      2.2e-7
 *    IEEE      dn          10000       1.4e-3      1.9e-5
 *    IEEE      phi         10000       3.9e-7*     6.7e-8*
 *
 *  Peak error observed in consistency check using addition
 * theorem for sn(u+v) was 4e-16 (absolute).  Also tested by
 * the above relation to the incomplete elliptic integral.
 * Accuracy deteriorates when u is large.
 *
 */

/*							ellpj.c		*/


/*
Cephes Math Library Release 2.2:  July, 1992
Copyright 1984, 1987, 1992 by Stephen L. Moshier
Direct inquiries to 30 Frost Street, Cambridge, MA 02140
*/

#include "mconf.h"
extern float PIO2F, MACHEPF;

#define fabsf(x) ( (x) < 0 ? -(x) : (x) )

#ifdef ANSIC
float cephes_sqrtf(float), cephes_sinf(float), cephes_cosf(float), cephes_asinf(float), cephes_tanhf(float);
float cephes_sinhf(float), cephes_coshf(float), cephes_atanf(float), cephes_expf(float);
#else
float cephes_sqrtf(), cephes_sinf(), cephes_cosf(), cephes_asinf(), cephes_tanhf();
float cephes_sinhf(), cephes_coshf(), cephes_atanf(), cephes_expf();
#endif

#ifdef ANSIC
int cephes_ellpjf( float uu, float mm,
   float *sn, float *cn, float *dn, float *ph )
#else
int cephes_ellpjf( uu, mm, sn, cn, dn, ph )
double uu, mm;
float *sn, *cn, *dn, *ph;
#endif
{
float u, m, ai, b, phi, t, twon;
float a[10], c[10];
int i;

u = uu;
m = mm;
/* Check for special cases */

if( m < 0.0f || m > 1.0f )
	{
	cephes_mtherr( "ellpjf", DOMAIN );
	return(-1);
	}
if( m < 1.0e-5f )
	{
	t = cephes_sinf(u);
	b = cephes_cosf(u);
	ai = 0.25f * m * (u - t*b);
	*sn = t - ai*b;
	*cn = b + ai*t;
	*ph = u - ai;
	*dn = 1.0f - 0.5f*m*t*t;
	return(0);
	}

if( m >= 0.99999f )
	{
	ai = 0.25f * (1.0f-m);
	b = cephes_coshf(u);
	t = cephes_tanhf(u);
	phi = 1.0f/b;
	twon = b * cephes_sinhf(u);
	*sn = t + ai * (twon - u)/(b*b);
	*ph = 2.0f*cephes_atanf(cephes_expf(u)) - PIO2F + ai*(twon - u)/b;
	ai *= t * phi;
	*cn = phi - ai * (twon - u);
	*dn = phi + ai * (twon + u);
	return(0);
	}


/*	A. G. M. scale		*/
a[0] = 1.0;
b = cephes_sqrtf(1.0f - m);
c[0] = cephes_sqrtf(m);
twon = 1.0f;
i = 0;

while( fabsf( (c[i]/a[i]) ) > MACHEPF )
	{
	if( i > 8 )
		{
/*		cephes_mtherr( "ellpjf", OVERFLOW );*/
		break;
		}
	ai = a[i];
	++i;
	c[i] = 0.5f * ( ai - b );
	t = cephes_sqrtf( ai * b );
	a[i] = 0.5f * ( ai + b );
	b = t;
	twon += twon;
	}


/* backward recurrence */
phi = twon * a[i] * u;
do
	{
	t = c[i] * cephes_sinf(phi) / a[i];
	b = phi;
	phi = 0.5f * (cephes_asinf(t) + phi);
	}
while( --i );

*sn = cephes_sinf(phi);
t = cephes_cosf(phi);
*cn = t;
*dn = t/cephes_cosf(phi-b);
*ph = phi;
return(0);
}
