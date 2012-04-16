/*******************************************************************************
 *         Copyright 2003-2012 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2012 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_TOOLBOX_LINALG_FUNCTIONS_FREQSPACE2_HPP_INCLUDED
#define NT2_TOOLBOX_LINALG_FUNCTIONS_FREQSPACE2_HPP_INCLUDED
#include <nt2/include/functor.hpp>

/*!
 * \ingroup algebra
 * \defgroup algebra_freqspace2 freqspace2
 *
 * \par Description
 * Elementary Least square
 *
 * \par Header file
 * 
 * \code
 * #include <nt2/include/functions/freqspace2.hpp>
 * \endcode
 * 
 *   tie(f1,f2) = freqspace2(n, as_<T>) returns the 2-d frequency range vectors
 *                              f1 and f2 for an n-by-n matrix.
 *   tie(f1,f2) = freqspace2(m, n, as_<T>) or  freqspace2(of_size(m, n), as_<T>)
                                returns the 2-d frequency range 
 *                              vectors for an m-by-n matrix.
 *
 *  this means for n odd,  f = _(-1+1/n,2/n,1-1/n).
 *                 n even, f = _(-1    ,2/n,1-2/n).
 *
 *    tie(f1,f2) = freqspace2(...,_, as_<T>) is equivalent to
 *    tie(f1,f2) = freqspace2(..., as_<T>);  tie(f1,f2) = meshgrid(f1,f2);
 *
**/
//==============================================================================
// freqspace2 actual class forward declaration
//==============================================================================

namespace nt2 { namespace tag
  {         
    /*!
     * \brief Define the tag freqspace2_ of functor freqspace2
     *        in namespace nt2::tag for toolbox algebra
    **/
    struct freqspace2_ : ext::unspecified_<freqspace2_> { typedef ext::unspecified_<freqspace2_> parent; };
  }
  
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::freqspace2_, freqspace2, 2)
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::freqspace2_, freqspace2, 3)
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::freqspace2_, freqspace2, 4)

}

#endif

