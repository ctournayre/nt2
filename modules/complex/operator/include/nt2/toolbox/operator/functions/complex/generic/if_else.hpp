//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_OPERATOR_FUNCTIONS_SIMD_COMPLEX_GENERIC_IF_ELSE_HPP_INCLUDED
#define NT2_TOOLBOX_OPERATOR_FUNCTIONS_SIMD_COMPLEX_GENERIC_IF_ELSE_HPP_INCLUDED
#include <nt2/include/functions/if_else.hpp>
#include <nt2/include/functions/is_nez.hpp>
#include <nt2/include/constants/zero.hpp>
#include <nt2/sdk/complex/complex.hpp>
#include <nt2/sdk/complex/imaginary.hpp>
#include <nt2/sdk/complex/meta/as_real.hpp>
#include <nt2/include/functions/real.hpp>
#include <nt2/include/functions/imag.hpp>

namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::if_else_, tag::cpu_, (A0)(A1)
                            , (generic_< logical_<A0> >)
                              (generic_< complex_< arithmetic_<A1> > >)
                              (generic_< complex_< arithmetic_<A1> > >)
                            )
  {
    typedef A1 result_type;
    inline result_type operator()(const A0& a0, const A1& a1, const A1&a2) const
    {
      return result_type(if_else(a0, real(a1), real(a2)),
                         if_else(a0, imag(a1), imag(a2)));
    }
  };
  
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::if_else_, tag::cpu_, (A0)(A1)
                            , (generic_< fundamental_<A0> >)
                              (generic_< complex_< arithmetic_<A1> > >)
                              (generic_< complex_< arithmetic_<A1> > >)
                            )
  {
    typedef A1 result_type;
    inline result_type operator()(const A0& a0, const A1& a1, const A1&a2) const
    {
      return if_else( is_nez(a0), a1, a2 );
    }
  };
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::if_else_, tag::cpu_, (A0)(A1)
                            , (generic_< logical_<A0> >)
                              (generic_< imaginary_< arithmetic_<A1> > >)
                              (generic_< imaginary_< arithmetic_<A1> > >)
                            )
  {
    typedef A1 result_type;
    inline result_type operator()(const A0& a0, const A1& a1, const A1&a2) const
    {
      return result_type(if_else(a0, imag(a1), imag(a2)));
    }
  };
  
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::if_else_, tag::cpu_, (A0)(A1)
                            , (generic_< fundamental_<A0> >)
                              (generic_< imaginary_< arithmetic_<A1> > >)
                              (generic_< imaginary_< arithmetic_<A1> > >)
                            )
  {
    typedef A1 result_type;
    inline result_type operator()(const A0& a0, const A1& a1, const A1&a2) const
    {
      return if_else(is_nez(a0), a1, a2 );
    }
  };
  
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::if_else_, tag::cpu_, (A0)(A1)(A2)
                            , (generic_< logical_<A0> >)
                              (generic_< complex_< arithmetic_<A1> > >)
                              (generic_< imaginary_< arithmetic_<A2> > >)
                            )
  {
    typedef A1 result_type;
    inline result_type operator()(const A0& a0, const A1& a1, const A2&a2) const
    {
      typedef typename meta::as_real<result_type>::type rtype;
      return result_type(if_else(a0, a1, result_type(Zero<rtype>(), imag(a2))));
    }
  };
  
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::if_else_, tag::cpu_, (A0)(A1)(A2)
                            , (generic_< fundamental_<A0> >)
                              (generic_< complex_< arithmetic_<A1> > >)
                              (generic_< imaginary_< arithmetic_<A2> > >)
                            )
  {
    typedef A1 result_type;
    inline result_type operator()(const A0& a0, const A1& a1, const A2&a2) const
    {
      return if_else(is_nez(a0), a1, a2 );
    }
  };

  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::if_else_, tag::cpu_, (A0)(A1)(A2)
                            , (generic_< logical_<A0> >)
                              (generic_< imaginary_< arithmetic_<A1> > >)
                              (generic_< complex_< arithmetic_<A2> > >)
                            )
  {
    typedef A1 result_type;
    inline result_type operator()(const A0& a0, const A1& a1, const A2&a2) const
    {
      typedef typename meta::as_real<result_type>::type rtype;
      return result_type(if_else(a0, result_type(Zero<rtype>(), imag(a1)), a2));
    }
  };
  
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::if_else_, tag::cpu_, (A0)(A1)(A2)
                            , (generic_< fundamental_<A0> >)
                              (generic_< imaginary_< arithmetic_<A1> > >)
                              (generic_< complex_< arithmetic_<A2> > >)
                            )
  {
    typedef A1 result_type;
    inline result_type operator()(const A0& a0, const A1& a1, const A2&a2) const
    {
      return if_else(is_nez(a0), a1, a2 );
    }
  };
  
} }

#endif