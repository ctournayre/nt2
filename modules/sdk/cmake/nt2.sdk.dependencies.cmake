################################################################################
#         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
#         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
#
#          Distributed under the Boost Software License, Version 1.0.
#                 See accompanying file LICENSE.txt or copy at
#                     http://www.boost.org/LICENSE_1_0.txt
################################################################################

include(nt2.boost)
IF(NOT Boost_FOUND)
  SET(NT2_SDK_DEPENDENCIES_FOUND 0)
  RETURN()
ENDIF()

FIND_PACKAGE(NT2 COMPONENTS extension)

IF(NOT NT2_FOUND)
  SET(NT2_SDK_DEPENDENCIES_FOUND 0)
  RETURN()
ENDIF()

include(nt2.simd)

SET(NT2_SDK_DEPENDENCIES_FOUND 1)
SET(NT2_SDK_DEPENDENCIES_INCLUDE_DIR ${Boost_INCLUDE_DIRS} ${NT2_INCLUDE_DIR})
SET(NT2_SDK_DEPENDENCIES_LIBRARY_DIR ${Boost_LIBRARY_DIRS})
SET(NT2_SDK_DEPENDENCIES_FLAGS ${NT2_FLAGS})
SET(NT2_SDK_FLAGS ${NT2_CXX_SIMD_FLAGS})
SET(NT2_SDK_LIBRARIES nt2)