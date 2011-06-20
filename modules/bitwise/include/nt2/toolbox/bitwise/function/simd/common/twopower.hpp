//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_BITWISE_FUNCTION_SIMD_COMMON_TWOPOWER_HPP_INCLUDED
#define NT2_TOOLBOX_BITWISE_FUNCTION_SIMD_COMMON_TWOPOWER_HPP_INCLUDED
#include <nt2/sdk/meta/as_real.hpp>
#include <nt2/include/constants/properties.hpp>
#include <nt2/include/constants/digits.hpp>
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/shli.hpp>
#include <nt2/include/functions/fast_ldexp.hpp>
#include <nt2/sdk/meta/adapted_traits.hpp>


/////////////////////////////////////////////////////////////////////////////
// Implementation when type  is arithmetic_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::twopower_, tag::cpu_,
                           (A0)(X),
                           ((simd_<integer_<A0>,X>))
                          );

namespace nt2 { namespace ext
{
  template<class X, class Dummy>
  struct call<tag::twopower_(tag::simd_<tag::integer_, X> ),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)>  : meta::strip<A0>{};//

    NT2_FUNCTOR_CALL(1)
    {
      return shift_left(One<A0>(), a0);
    }

  };
} }

#endif
