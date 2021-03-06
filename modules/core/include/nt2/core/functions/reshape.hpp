//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_FUNCTIONS_RESHAPE_HPP_INCLUDED
#define NT2_CORE_FUNCTIONS_RESHAPE_HPP_INCLUDED

/*!
 * \file
 * \brief Defines and implements the nt2::reshape function
 */

#include <nt2/include/functor.hpp>
#include <nt2/sdk/meta/reshaping_hierarchy.hpp>
#include <nt2/core/container/dsl/details/reshaping.hpp>

namespace nt2
{
  namespace tag
  {
    struct reshape_ : ext::reshaping_<reshape_>
    {
      typedef ext::reshaping_<reshape_> parent;
    };
  }

  //============================================================================
  /*!
   * reshape an expression while keeping its numel constant
   *
   * \param xpr   Expression to reshape
   * \param size  New size of the expression
   */
  //============================================================================
  #define M0(z,n,t)                                       \
  NT2_FUNCTION_IMPLEMENTATION(nt2::tag::reshape_, reshape, n) \
  NT2_FUNCTION_IMPLEMENTATION_SELF(nt2::tag::reshape_, reshape, n)      \
  /**/

  BOOST_PP_REPEAT_FROM_TO(2,BOOST_PP_INC(BOOST_PP_INC(NT2_MAX_DIMENSIONS)),M0,~)

  #undef M0
}

namespace nt2 { namespace container { namespace ext
{
  template<class Domain, class Expr>
  struct  generator<nt2::tag::reshape_,Domain,2,Expr>
        : reshaping_generator<Expr>
  {};

  template<class Domain, class Expr>
  struct  size_of<nt2::tag::reshape_,Domain,2,Expr>
        : reshaping_size_of<Expr>
  {};
} } }
#endif
