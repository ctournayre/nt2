//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_BENCH_MODULE "nt2 bitwise toolbox - lo/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// timing Test behavior of bitwise components in scalar mode
//////////////////////////////////////////////////////////////////////////////
#include <nt2/toolbox/bitwise/include/lo.hpp>
#include <nt2/sdk/constant/infinites.hpp>
#include <nt2/sdk/unit/benchmark.hpp>
#include <cmath>


//////////////////////////////////////////////////////////////////////////////
// scalar runtime benchmark for functor<lo_> from bitwise
//////////////////////////////////////////////////////////////////////////////
using nt2::tag::lo_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, T(V1) ,T(V2))

namespace n1 {
  typedef float T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(lo_,(RS(T,T(0),T(10))))
}
namespace n2 {
  typedef double T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(lo_,(RS(T,T(0),T(10))))
}

#undef RS
