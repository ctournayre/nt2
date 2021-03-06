//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_SDK_COMPLEX_META_AS_DRY_HPP_INCLUDED
#define NT2_SDK_COMPLEX_META_AS_DRY_HPP_INCLUDED

#include <boost/dispatch/meta/scalar_of.hpp>
#include <boost/dispatch/meta/factory_of.hpp>
#include <boost/mpl/apply.hpp>
#include <complex>

namespace nt2
{
  template<class T>
  struct dry;
  
  template<class T>
  struct imaginary;
}

namespace nt2 { namespace details
{
  template<class T, class F>
  struct as_dry
   : boost::mpl::apply1<F, dry<T> >
  {
  };
  
  template<class T, class F>
  struct as_dry< std::complex<T>, F >
   : boost::mpl::apply1<F, dry<T> >
  {
  };
  
  template<class T, class F>
  struct as_dry< dry<T>, F >
   : boost::mpl::apply1<F, dry<T> >
  {
  };
  
  template<class T, class F>
  struct as_dry< imaginary<T>, F >
   : boost::mpl::apply1<F, dry<T> >
  {
  };
} }

namespace nt2 { namespace meta
{
  template<class T>
  struct as_dry
    : details::as_dry< typename boost::dispatch::meta::
                             scalar_of<T>::type
                           , typename boost::dispatch::meta::
                             factory_of<T, typename boost::dispatch::meta::
                                           scalar_of<T>::type
                                       >::type
                           >
  {
  };
} }

#endif
