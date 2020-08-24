CMAKE_MINIMUM_REQUIRED(VERSION 3.17.3)

SET(PROJECT_NAME simbullet)
PROJECT(${PROJECT_NAME})

# SET( CMAKE_VERBOSE_MAKEFILE OFF)

################################################################################
# Download and unpack bullet3 at configure time
configure_file(CMakeLists.txt.in bullet3-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
      RESULT_VARIABLE result
      WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bullet3-download )
if(result)
      message(FATAL_ERROR "CMake step for bullet3 failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
      RESULT_VARIABLE result
      WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bullet3-download )
if(result)
      message(FATAL_ERROR "Build step for bullet3 failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(bullet3_force_shared_crt ON CACHE BOOL "" FORCE)

# Add bullet3 directly to our build.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/bullet3-src
      ${CMAKE_CURRENT_BINARY_DIR}/bullet3-build)
            # EXCLUDE_FROM_ALL)

################################################################################
# FIND_PACKAGE( Eigen3 REQUIRED )

SET(DEP_INCLUDE_DIRS 
      "${CMAKE_CURRENT_SOURCE_DIR}"
      )
SET(DEP_LIBS 
      )


IF(APPLE)
      find_library(COCOA NAMES Cocoa)
      MESSAGE(${COCOA})
      SET(DEP_LIBS ${DEP_LIBS} ${COCOA} ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY})

ELSE(APPLE)
      INCLUDE_DIRECTORIES(
            ${BULLET_PHYSICS_SOURCE_DIR}/btgui/OpenGLWindow/GlewWindows
      )
      ADD_DEFINITIONS("-DGLEW_INIT_OPENGL11_FUNCTIONS=1")
      ADD_DEFINITIONS("-DGLEW_STATIC")
      ADD_DEFINITIONS("-DGLEW_DYNAMIC_LOAD_ALL_GLX_FUNCTIONS=1")

      SET(DEP_LIBS ${DEP_LIBS}  pthread ${DL} )
ENDIF(APPLE)


SET(DEP_BULLET_INCLUDE_DIRS 
      ${BULLET_PHYSICS_SOURCE_DIR}/src
      )
SET(DEP_BULLET_LIBS 
      BulletDynamics
      BulletCollision 
      LinearMath 
      # ${BULLET_LIBRARIES}
      OpenGLWindow 
      Bullet3Common 
      )

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
