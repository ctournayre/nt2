################################################################################
#         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
#         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
#
#          Distributed under the Boost Software License, Version 1.0.
#                 See accompanying file LICENSE.txt or copy at
#                     http://www.boost.org/LICENSE_1_0.txt
################################################################################

################################################################################
# Fix CMAKE_BUILD_TYPE
################################################################################
INCLUDE(NT2Module)
nt2_setup_variant()

################################################################################
# Check for special options
################################################################################
INCLUDE(options/nt2.extra.warnings)

################################################################################
# Log current choice
################################################################################
IF( ${CMAKE_BUILD_TYPE} STREQUAL Release )
MESSAGE( STATUS "[nt2] build type: Release (${CMAKE_CXX_FLAGS_RELEASE})" )
ENDIF()

IF( ${CMAKE_BUILD_TYPE} STREQUAL Debug )
MESSAGE( STATUS "[nt2] build type: Debug (${CMAKE_CXX_FLAGS_DEBUG})" )
ENDIF()

IF( ${CMAKE_BUILD_TYPE} STREQUAL RelWithDebInfo )
MESSAGE( STATUS "[nt2] build type: RelWithDebInfo (${CMAKE_CXX_FLAGS_RELWITHDEBINFO})" )
ENDIF()

IF( ${CMAKE_BUILD_TYPE} STREQUAL MinSizeRel )
MESSAGE( STATUS "[nt2] build type: MinSizeRel (${CMAKE_CXX_FLAGS_MINSIZEREL})" )
ENDIF()
