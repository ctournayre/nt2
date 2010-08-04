/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#include <nt2/include/functions/abs.hpp>
#include <nt2/sdk/unit/benchmark.hpp>

////////////////////////////////////////////////////////////////////////////////
// Runtime benchmark for functor<abs_>
////////////////////////////////////////////////////////////////////////////////
using nt2::functors::abs_;
using namespace nt2;

////////////////////////////////////////////////////////////////////////////////
// Symmetric range
////////////////////////////////////////////////////////////////////////////////
#define RS(T,V) ((T, -V , V))

////////////////////////////////////////////////////////////////////////////////
// Scalar benchmark
////////////////////////////////////////////////////////////////////////////////
NT2_TIMING( abs_ , RS(float,2000000))
NT2_TIMING( abs_ , RS(double,2000000))
NT2_TIMING( abs_ , RS(int64_t,2000000))
NT2_TIMING( abs_ , RS(int32_t,2000000))
NT2_TIMING( abs_ , RS(int16_t,32768))
NT2_TIMING( abs_ , RS(int8_t,127))
NT2_TIMING( abs_ , ((uint64_t, 0, ~0ULL)) )
NT2_TIMING( abs_ , ((uint32_t, 0, ~0U)) )
NT2_TIMING( abs_ , ((uint16_t, 0, 65535)) )
NT2_TIMING( abs_ , ((uint8_t , 0, 255)) )
