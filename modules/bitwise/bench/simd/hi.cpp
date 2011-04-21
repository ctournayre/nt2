//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_BENCH_MODULE "nt2 bitwise toolbox - hi/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// timing Test behavior of bitwise components in simd mode
//////////////////////////////////////////////////////////////////////////////
#include <nt2/toolbox/bitwise/include/hi.hpp>
#include <nt2/sdk/unit/benchmark.hpp>
#include <nt2/sdk/unit/bench_includes.hpp>
#include <cmath>
typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;

//////////////////////////////////////////////////////////////////////////////
// simd runtime benchmark for functor<hi_> from bitwise
//////////////////////////////////////////////////////////////////////////////
using nt2::tag::hi_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, (V1) ,(V2))

namespace n1 {
  typedef float T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  NT2_TIMING(hi_,(RS(vT,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2)))
}
namespace n2 {
  typedef double T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  NT2_TIMING(hi_,(RS(vT,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2)))
}
namespace n3 {
  typedef uint64_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  NT2_TIMING(hi_,(RS(vT,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2)))
}
namespace n4 {
  typedef int64_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  NT2_TIMING(hi_,(RS(vT,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2)))
}
namespace n5 {
  typedef uint32_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  NT2_TIMING(hi_,(RS(vT,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2)))
}
namespace n6 {
  typedef int32_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  NT2_TIMING(hi_,(RS(vT,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2)))
}
namespace n7 {
  typedef uint16_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  NT2_TIMING(hi_,(RS(vT,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2)))
}
namespace n8 {
  typedef int16_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  NT2_TIMING(hi_,(RS(vT,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2)))
}

#undef RS