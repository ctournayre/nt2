//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 arithmetic toolbox - tofloat/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of arithmetic components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created by jt the 04/12/2010
/// modified by jt the 06/04/2011
#include <nt2/sdk/memory/is_aligned.hpp>
#include <nt2/sdk/memory/aligned_type.hpp>
#include <nt2/sdk/memory/load.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/constant/real.hpp>
#include <nt2/sdk/constant/infinites.hpp>
#include <nt2/include/functions/max.hpp>
#include <nt2/toolbox/arithmetic/include/tofloat.hpp>

NT2_TEST_CASE_TPL ( tofloat_real__1_0,  NT2_REAL_TYPES)
{
  using nt2::tofloat;
  using nt2::tag::tofloat_;
  using nt2::load; 
  using nt2::simd::native;
  using nt2::meta::cardinal_of;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename nt2::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename nt2::meta::call<tofloat_(vT)>::type r_t;
  typedef typename nt2::meta::call<tofloat_(T)>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_EQUAL(tofloat(nt2::Inf<vT>())[0], nt2::Inf<sr_t>());
  NT2_TEST_EQUAL(tofloat(nt2::Minf<vT>())[0], nt2::Minf<sr_t>());
  NT2_TEST_EQUAL(tofloat(nt2::Mone<vT>())[0], nt2::Mone<sr_t>());
  NT2_TEST_EQUAL(tofloat(nt2::Nan<vT>())[0], nt2::Nan<sr_t>());
  NT2_TEST_EQUAL(tofloat(nt2::One<vT>())[0], nt2::One<sr_t>());
  NT2_TEST_EQUAL(tofloat(nt2::Zero<vT>())[0], nt2::Zero<sr_t>());
} // end of test for real_

NT2_TEST_CASE_TPL ( tofloat_uint32_t_1_0,  (uint32_t))
{
  using nt2::tofloat;
  using nt2::tag::tofloat_;
  using nt2::load; 
  using nt2::simd::native;
  using nt2::meta::cardinal_of;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename nt2::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename nt2::meta::call<tofloat_(vT)>::type r_t;
  typedef typename nt2::meta::call<tofloat_(T)>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_EQUAL(tofloat(nt2::One<vT>())[0], nt2::One<sr_t>());
  NT2_TEST_EQUAL(tofloat(nt2::Zero<vT>())[0], nt2::Zero<sr_t>());
} // end of test for uint32_t

NT2_TEST_CASE_TPL ( tofloat_uint64_t_1_0,  (nt2::uint64_t))
{
  using nt2::tofloat;
  using nt2::tag::tofloat_;
  using nt2::load; 
  using nt2::simd::native;
  using nt2::meta::cardinal_of;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename nt2::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename nt2::meta::call<tofloat_(vT)>::type r_t;
  typedef typename nt2::meta::call<tofloat_(T)>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_EQUAL(tofloat(nt2::One<vT>())[0], nt2::One<sr_t>());
  NT2_TEST_EQUAL(tofloat(nt2::Zero<vT>())[0], nt2::Zero<sr_t>());
} // end of test for uint64_t

NT2_TEST_CASE_TPL ( tofloat_int32_t_1_0,  (nt2::int32_t))
{
  using nt2::tofloat;
  using nt2::tag::tofloat_;
  using nt2::load; 
  using nt2::simd::native;
  using nt2::meta::cardinal_of;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename nt2::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename nt2::meta::call<tofloat_(vT)>::type r_t;
  typedef typename nt2::meta::call<tofloat_(T)>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  double ulpd;
  ulpd=0.0;

 
  // specific values tests
  NT2_TEST_EQUAL(tofloat(nt2::Mone<vT>())[0], nt2::Mone<sr_t>());
  NT2_TEST_EQUAL(tofloat(nt2::One<vT>())[0], nt2::One<sr_t>());
  NT2_TEST_EQUAL(tofloat(nt2::Zero<vT>())[0], nt2::Zero<sr_t>());
} // end of test for int32_t

NT2_TEST_CASE_TPL ( tofloat_int64_t_1_0,  (nt2::int64_t))
{
  using nt2::tofloat;
  using nt2::tag::tofloat_;
  using nt2::load; 
  using nt2::simd::native;
  using nt2::meta::cardinal_of;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename nt2::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename nt2::meta::call<tofloat_(vT)>::type r_t;
  typedef typename nt2::meta::call<tofloat_(T)>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_EQUAL(tofloat(nt2::Mone<vT>())[0], nt2::Mone<sr_t>());
  NT2_TEST_EQUAL(tofloat(nt2::One<vT>())[0], nt2::One<sr_t>());
  NT2_TEST_EQUAL(tofloat(nt2::Zero<vT>())[0], nt2::Zero<sr_t>());
} // end of test for int64_t