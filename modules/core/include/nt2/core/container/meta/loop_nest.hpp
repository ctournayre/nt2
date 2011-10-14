//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_CONTAINER_META_LOOP_NEST_HPP_INCLUDED
#define NT2_CORE_CONTAINER_META_LOOP_NEST_HPP_INCLUDED

#include <boost/fusion/include/size.hpp>
#include <boost/fusion/include/array.hpp>

namespace nt2 { namespace meta
{
  // loop nest generator
  template<std::size_t N>
  struct for_each_impl
  {
    template<class Bases, class Sizes, class Position, class F>
    BOOST_DISPATCH_FORCE_INLINE
    static void call(Bases const& bases, Sizes const& sz, Position& pos, F const& f)
    {
      for(pos[N-1] = bases[N-1]; pos[N-1] != bases[N-1] + sz[N-1]; ++pos[N-1])
          for_each_impl<N-1>::call(bases, sz, pos, f);
    }
  };

  template<>
  struct for_each_impl<0>
  {
    template<class Bases, class Sizes, class Position, class F>
    BOOST_DISPATCH_FORCE_INLINE
    static void call(Bases const&, Sizes const&, Position& pos, F const& f)
    {
        return f(pos);
    }
  };

  template<class Bases, class Sizes, class F>
  BOOST_DISPATCH_FORCE_INLINE
  void for_each(Bases const& bases, Sizes const& sz, F const& f)
  {
    static const std::size_t nb_dims = boost::fusion::result_of::size<Sizes>::value;

    boost::array<std::size_t, nb_dims> position;
    for_each_impl<nb_dims>::call(bases, sz, position, f);
  }
} }

#endif