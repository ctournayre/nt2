//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#include <nt2/toolbox/models/include/model_three_branches.hpp>
#include <nt2/sdk/unit/benchmark.hpp>

//////////////////////////////////////////////////////////////////////////////
// Runtime benchmark for functor<model_three_branches_> from models
//////////////////////////////////////////////////////////////////////////////
using nt2::functors::model_three_branches_;

//////////////////////////////////////////////////////////////////////////////
// bench/simd
// E.G:
// NT2_TIMING( model_three_branches_ , ((nt2::simd::native<float,nt2::tag::sse_>, -10, 10)) ) 
//           )
//////////////////////////////////////////////////////////////////////////////