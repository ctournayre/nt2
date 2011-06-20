//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_BITWISE_FUNCTION_SIMD_COMMON_RSHL_HPP_INCLUDED
#define NT2_TOOLBOX_BITWISE_FUNCTION_SIMD_COMMON_RSHL_HPP_INCLUDED
#include <nt2/sdk/meta/size.hpp>
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/shli.hpp>
#include <nt2/include/functions/shri.hpp>  
#include <nt2/include/functions/is_gtz.hpp>  



/////////////////////////////////////////////////////////////////////////////
// Implementation when type  is arithmetic_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH_IF(tag::rshl_, tag::cpu_,
			 (A0)(A1)(X),
			 (boost::mpl::equal_to<boost::mpl::sizeof_<A0>,boost::mpl::sizeof_<A1> >),
			 (tag::rshl_(tag::simd_<tag::arithmetic_,X>, tag::simd_<tag::integer_,X>)), 
			 ((simd_<arithmetic_<A0>,X>))
			 ((simd_<integer_<A1>,X>))
                       );

namespace nt2 { namespace ext
{
  template<class X, class Dummy>
  struct call<tag::rshl_(tag::simd_<tag::arithmetic_, X> ,
                         tag::simd_<tag::integer_, X> ),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0,A1)>
      : meta::strip<A0>{};//

    NT2_FUNCTOR_CALL(2)
    {
      return map(functor<tag::rshl_>(), a0, a1);
    }

  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type  is arithmetic_ and A1 is scalar
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::rshl_, tag::cpu_,
		      (A0)(A1)(X),
		      ((simd_<arithmetic_<A0>,X>))
		      ((integer_<A1>))
		      );

namespace nt2 { namespace ext
{
  template<class X, class Dummy>
  struct call<tag::rshl_(tag::simd_<tag::arithmetic_, X> ,
                         tag::integer_ ),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0,A1)>
      : meta::strip<A0>{};//

    NT2_FUNCTOR_CALL(2)
    {
      if (is_gtz(a1)) return shli(a0, a1);  else return shri(a0, -a1); 
    }

  };
} }
#endif
