SET(PROJECT_NAME simbullet)

PROJECT(${PROJECT_NAME})
CMAKE_MINIMUM_REQUIRED(VERSION 3.0.0)

SET( CMAKE_VERBOSE_MAKEFILE OFF)

################################################################################
# Release by default
# Turn on Debug with "-DCMAKE_BUILD_TYPE=Debug"
IF( NOT CMAKE_BUILD_TYPE )
   SET( CMAKE_BUILD_TYPE Release )
ENDIF()

IF( CMAKE_COMPILER_IS_GNUCXX )
#    SET(CMAKE_CXX_FLAGS_DEBUG  "-O0 -g")
#    SET(CMAKE_CXX_FLAGS_RELEASE "-O3")

   ADD_DEFINITIONS("-Wall -Werror")
ENDIF()

################################################################################
# Add local path for finding packages, set the local version first
SET(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
include( install_package )

################################################################################
# Create variables used for exporting (from build tree) in simbulletConfig.cmake
# SET( simbullet_LIBRARIES "" )
SET( simbullet_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include )

################################################################################
FIND_PACKAGE( Bullet REQUIRED )

################################################################################
SET( SOURCE_DIR "src")

SET( SOURCES    
        ${SOURCE_DIR}/simbullet.cpp
    )

SET( HEADERS    
        ${simbullet_INCLUDE_DIR}/simbullet/simbullet.h
    )

# Add sources as custom target so that they are shown in IDE's
# ADD_CUSTOM_TARGET( libsimbullet SOURCES ${SOURCES} )
include_directories( ${simbullet_INCLUDE_DIR} ${BULLET_INCLUDE_DIR})

set( LIBRARY_NAME ${PROJECT_NAME} )
add_library( ${LIBRARY_NAME} SHARED ${SOURCES} ${HEADERS})
target_link_libraries( ${LIBRARY_NAME} ${BULLET_LIBRARIES})


################################################################################
OPTION( EXPORT_simbullet
  "Should the simbullet package be exported for use by other software" OFF)

# Export package for use from the build tree
IF( EXPORT_simbullet )
  EXPORT( PACKAGE simbullet )
ENDIF()

# Create the simbulletConfig.cmake file for other cmake projects.
# ... for the build tree
SET( CONFIG_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
SET( CONFIG_DIR ${CMAKE_CURRENT_BINARY_DIR})
CONFIGURE_FILE( ${CMAKE_CURRENT_SOURCE_DIR}/simbulletConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/simbulletConfig.cmake @ONLY )

#     set(main_lib_dest "lib/")
#     # set(include_dest "include/}")
 file( GLOB SIMBULLET_HEADERS "simbullet/*.h")
# install(TARGETS ${LIBRARY_NAME} DESTINATION "${main_lib_dest}")
#     # install(FILES ${SIMBULLET_HEADERS} DESTINATION "${include_dest}")
#     install(DIRECTORY "${simbullet_INCLUDE_DIR}/"
#         DESTINATION "include"
#         FILES_MATCHING
#         PATTERN "*.h"
# )
    # install(FILES ${CMAKE_CURRENT_BINARY_DIR}/config_impl.hpp DESTINATION "${include_dest}")
    
    # -- Install configuration: "Release"
    # -- Up-to-date: /usr/local/include
    # -- Up-to-date: /usr/local/include/simbullet
    # -- Up-to-date: /usr/local/include/simbullet/simbullet.h
    # -- Up-to-date: /usr/local/lib/libsimbullet.dylib
    # -- Up-to-date: /usr/local/lib/pkgconfig/simbullet.pc
    # -- Installing: /usr/local/lib/cmake/simbullet/simbulletConfig.cmake
    # -- Installing: /usr/local/lib/cmake/simbullet/simbulletTargets.cmake
    # -- Up-to-date: /usr/local/lib/cmake/simbullet/simbulletConfigVersion.cmake
    # -- Up-to-date: /usr/local/share/simbullet/Findsimbullet.cmake

    
    
# install files and create Findsimbullet.cmake and simbullet.pc pkg-config files
install_package(
    PKG_NAME simbullet
    LIB_NAME ${LIBRARY_NAME}
    VERSION 1.0
    DESCRIPTION "simple c++ wrapper for bullet physics engine."
    INSTALL_INCLUDE_DIR true
    # INSTALL_GENERATED_HEADERS "${CMAKE_CURRENT_BINARY_DIR}/include/simbullet/simbulletConfig.h"
    DESTINATION ${CMAKE_INSTALL_PREFIX}
    INCLUDE_DIRS ${simbullet_INCLUDE_DIR}
    LINK_LIBS ${BULLET_LIBRARIES}
    # PACKAGE_LIB_NAME ${LIBRARY_NAME}
    # TARGETS ${LIBRARY_NAME} DESTINATION lib
    # PACKAGE_LINK_DIRS ${CMAKE_INSTALL_LIBDIR}
    )

set( simbullet_DIR ${CMAKE_CURRENT_BINARY_DIR} )
set( simbullet_LIBRARIES ${BULLET_LIBRARIES} ${LIBRARY_NAME} )
set( simbullet_INCLUDE_DIRS ${simbullet_INCLUDE_DIR} )
link_libraries( ${BULLET_LIBRARIES} ${LIBRARY_NAME} )
###########################
 include(${CMAKE_MODULE_PATH}/cmake_uninstall.cmake.in)

 add_custom_target(uninstall
     COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)

 ################################################################################
# Create 'test' make target using ctest
option(BUILD_TESTS "Build tests." ON)
if(BUILD_TESTS)
    ENABLE_TESTING()
    ADD_SUBDIRECTORY( test )
endif()

 ###########################