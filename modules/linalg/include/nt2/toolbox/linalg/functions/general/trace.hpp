/*******************************************************************************
 *         Copyright 2003-2012 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2011-2012 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_TOOLBOX_LINALG_FUNCTIONS_GENERAL_TRACE_HPP_INCLUDED
#define NT2_TOOLBOX_LINALG_FUNCTIONS_GENERAL_TRACE_HPP_INCLUDED
#include <nt2/include/functions/trace.hpp>
#include <nt2/include/functions/isvector.hpp>

namespace nt2
{
    BOOST_SIMD_FUNCTOR_IMPLEMENTATION( nt2::tag::trace_, tag::cpu_,
                                       (A)(SA)
                                       ,  ((expr_< table_<unspecified_<A>,SA>,nt2::tag::terminal_,boost::mpl::long_<0> >))
                                   )
  {
    typedef typename A:value_type result_type; 
    BOOST_SIMD_FUNCTOR_CALL(1)
    {
      if (isvector(a)) return a(first_index<1>()); 
      return globalSum(diag(a));
    }
  };

}


#endif

// /////////////////////////////////////////////////////////////////////////////
// End of trace.hpp<2>
// /////////////////////////////////////////////////////////////////////////////