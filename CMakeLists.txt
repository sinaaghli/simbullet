CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

SET(PROJECT_NAME simbullet)
PROJECT(${PROJECT_NAME})

# SET( CMAKE_VERBOSE_MAKEFILE OFF)

################################################################################
FIND_PACKAGE( Bullet REQUIRED )

SET(DEP_INCLUDE_DIRS 
      ${BULLET_INCLUDE_DIR})

SET(DEP_LIBS 
      ${BULLET_LIBRARIES})
################################################################################

# Set variables
include(${CMAKE_SOURCE_DIR}/cmake/SetEnv.cmake)

# Library sources
add_subdirectory(${LIBRARY_FOLDER})

# Library examlsples
add_subdirectory(tests)

# Install targets
include(${CMAKE_SOURCE_DIR}/cmake/InstallConfig.cmake)

#  ################################################################################
# # Create 'test' make target using ctest
# option(BUILD_TESTS "Build tests." ON)
# if(BUILD_TESTS)
#     ENABLE_TESTING()
#     ADD_SUBDIRECTORY( test )
# endif()

#  ###########################
