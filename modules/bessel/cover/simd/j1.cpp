//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 bessel toolbox - j1/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// cover test behavior of bessel components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 16/02/2011
/// 
#include <nt2/toolbox/bessel/include/functions/j1.hpp>
#include <nt2/include/functions/ulpdist.hpp>
#include <nt2/include/functions/max.hpp>
extern "C" {long double cephes_j1l(long double);}

#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/meta/as_integer.hpp>
#include <nt2/sdk/meta/as_floating.hpp>
#include <nt2/sdk/meta/as_signed.hpp>
#include <nt2/sdk/meta/upgrade.hpp>
#include <nt2/sdk/meta/downgrade.hpp>
#include <nt2/sdk/meta/scalar_of.hpp>
#include <boost/dispatch/meta/as_floating.hpp>
#include <boost/type_traits/common_type.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>

#include <nt2/toolbox/constant/constant.hpp>
#include <nt2/sdk/meta/cardinal_of.hpp>
#include <nt2/include/functions/splat.hpp>

#include <nt2/include/functions/load.hpp>
#include <nt2/toolbox/constant/constant.hpp>


NT2_TEST_CASE_TPL ( j1_real__1_0,  NT2_SIMD_REAL_TYPES)
{
  using nt2::j1;
  using nt2::tag::j1_;
  using nt2::load; 
  using boost::simd::native;
  using nt2::meta::cardinal_of;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename nt2::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename nt2::meta::call<j1_(vT)>::type r_t;
  typedef typename nt2::meta::call<j1_(T)>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  double ulpd;
  ulpd=0.0;

  // random verifications
  static const nt2::uint32_t NR = NT2_NB_RANDOM_TEST;
  {
    NT2_CREATE_BUF(tab_a0,T, NR, T(0), T(10));
    double ulp0, ulpd ; ulpd=ulp0=0.0;
    for(nt2::uint32_t j = 0; j < NR;j+=cardinal_of<n_t>::value)
      {
        vT a0 = load<vT>(&tab_a0[0],j);
        r_t v = j1(a0);
        for(nt2::uint32_t i = 0; i< cardinal_of<n_t>::value; i++)
        {
          
          NT2_TEST_ULP_EQUAL( v[i],ssr_t(nt2::j1 (a0[i])), 350);
          ulp0 = nt2::max(ulpd,ulp0);
        }
      }
    std::cout << "max ulp found is: " << ulp0 << std::endl;
  }
} // end of test for floating_
