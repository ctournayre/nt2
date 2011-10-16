//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef BOOST_SIMD_TOOLBOX_BITWISE_FUNCTIONS_TYPED_BOOL_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_BITWISE_FUNCTIONS_TYPED_BOOL_HPP_INCLUDED
#include <boost/simd/include/simd.hpp>
#include <boost/dispatch/include/functor.hpp>


namespace boost { namespace simd { namespace tag
  {         
    struct typed_bool_ {};
  }
  
  template<class T, class A0> inline
  typename boost::dispatch::meta::call<tag::typed_bool_(A0, boost::dispatch::meta::as_<T>)>::type
  typed_bool(A0 const& a0)
  {
    typename boost::dispatch::make_functor<tag::typed_bool_, A0>::type callee;
    return callee(a0, boost::dispatch::meta::as_<T>() );
  }
} }
 
#endif
