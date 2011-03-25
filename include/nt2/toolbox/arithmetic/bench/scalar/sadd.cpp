//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#include <nt2/toolbox/arithmetic/include/sadd.hpp>
#include <nt2/sdk/unit/benchmark.hpp>
#include <cmath>


//////////////////////////////////////////////////////////////////////////////
// scalar runtime benchmark for functor<sadd_> from arithmetic
//////////////////////////////////////////////////////////////////////////////
using nt2::tag::sadd_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, T(V1) ,T(V2))

namespace n1 {
  typedef int8_t T;
  NT2_TIMING(nt2::tag::sadd_,(RS(T,T(-100),T(100)))(RS(T,T(-100),T(100))))
}
namespace n2 {
  typedef int16_t T;
  NT2_TIMING(nt2::tag::sadd_,(RS(T,T(-100),T(100)))(RS(T,T(-100),T(100))))
}
namespace n3 {
  typedef int32_t T;
  NT2_TIMING(nt2::tag::sadd_,(RS(T,T(-100),T(100)))(RS(T,T(-100),T(100))))
}
namespace n4 {
  typedef int64_t T;
  NT2_TIMING(nt2::tag::sadd_,(RS(T,T(-100),T(100)))(RS(T,T(-100),T(100))))
}
namespace n5 {
  typedef uint8_t T;
  NT2_TIMING(nt2::tag::sadd_,(RS(T,T(0),T(100)))(RS(T,T(0),T(100))))
}
namespace n6 {
  typedef uint16_t T;
  NT2_TIMING(nt2::tag::sadd_,(RS(T,T(0),T(100)))(RS(T,T(0),T(100))))
}
namespace n7 {
  typedef uint32_t T;
  NT2_TIMING(nt2::tag::sadd_,(RS(T,T(0),T(100)))(RS(T,T(0),T(100))))
}
namespace n8 {
  typedef uint64_t T;
  NT2_TIMING(nt2::tag::sadd_,(RS(T,T(0),T(100)))(RS(T,T(0),T(100))))
}

#undef RS