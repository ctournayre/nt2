//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_FUNCTIONS_ONES_HPP_INCLUDED
#define NT2_CORE_FUNCTIONS_ONES_HPP_INCLUDED

#include <nt2/sdk/parameters.hpp>
#include <nt2/include/functor.hpp>
#include <nt2/include/constants/one.hpp>
#include <nt2/sdk/meta/constant_adaptor.hpp>
#include <nt2/sdk/meta/generative_hierarchy.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <nt2/core/container/dsl/details/generative.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>

namespace nt2
{
  namespace tag
  {
    struct  ones_
          : ext::generative_<ones_> { typedef ext::generative_<ones_> parent; };
  }

  #define M0(z,n,t)                                       \
  NT2_FUNCTION_IMPLEMENTATION(nt2::tag::ones_, ones, n) \
  /**/

  BOOST_PP_REPEAT_FROM_TO(1,BOOST_PP_INC(BOOST_PP_INC(NT2_MAX_DIMENSIONS)),M0,~)

  #undef M0
}

namespace nt2 { namespace container { namespace ext
{
  //============================================================================
  // Register ones_ as a generative expression
  //============================================================================
  template<class Domain, class Expr, int N>
  struct generator<tag::ones_,Domain,N,Expr>   : generative_generator<Expr>
  {};

  template<class Domain, class Expr, int N>
  struct size_of<tag::ones_,Domain,N,Expr>     : generative_size_of<Expr>
  {};
} } }

#endif
