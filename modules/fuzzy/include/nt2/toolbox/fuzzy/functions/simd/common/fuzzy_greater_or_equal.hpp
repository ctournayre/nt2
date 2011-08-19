//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_FUZZY_FUNCTIONS_SIMD_COMMON_FUZZY_GREATER_OR_EQUAL_HPP_INCLUDED
#define NT2_TOOLBOX_FUZZY_FUNCTIONS_SIMD_COMMON_FUZZY_GREATER_OR_EQUAL_HPP_INCLUDED
#include <nt2/sdk/meta/adapted_traits.hpp>
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/max.hpp>
#include <nt2/include/functions/abs.hpp>
/////////////////////////////////////////////////////////////////////////////
// Implementation when type  is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION(nt2::tag::fuzzy_greater_or_equal_, tag::cpu_,
                                         (A0)(X),
                                         ((simd_<arithmetic_<A0>,X>))
                                         ((simd_<arithmetic_<A0>,X>))
                                         ((simd_<arithmetic_<A0>,X>))
                                        )
  {
    typedef A0 result_type;
    NT2_FUNCTOR_CALL_REPEAT(3)
    {
      return ge(a0,a1-max(abs(a0),abs(a1))*a2);
    }
  };
} }
#endif