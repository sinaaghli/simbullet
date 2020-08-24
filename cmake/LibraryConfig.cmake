# Select library type
set(_PN ${PROJECT_NAME})
option(BUILD_SHARED_LIBS "Build ${_PN} as a shared library." ON)
if(BUILD_SHARED_LIBS)
  set(LIBRARY_TYPE SHARED)
else()
  set(LIBRARY_TYPE STATIC)
endif()

# Set a default build type if none was specified
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to 'Release'.")
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)

  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
    "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

# Target
add_library(${LIBRARY_NAME} ${LIBRARY_TYPE} ${SOURCES} ${HEADERS} ${DEP_INCLUDE_DIRS})
target_include_directories(${LIBRARY_NAME} SYSTEM BEFORE INTERFACE     
    "$<BUILD_INTERFACE:${DEP_INCLUDE_DIRS}>"
    ${CMAKE_INSTALL_PREFIX}/${INCLUDE_INSTALL_DIR}
    )
target_link_libraries(${LIBRARY_NAME} "$<BUILD_INTERFACE:${DEP_LIBS}>")
# target_link_libraries(${LIBRARY_NAME} ${DEP_LIBS})

# SET( PROJECT_EXPORT ${PROJECT_EXPORT} BulletDynamics)
SET( PROJECT_EXPORT ${PROJECT_EXPORT})

# Install library
install(TARGETS ${LIBRARY_NAME} 
  EXPORT ${PROJECT_EXPORT} 
  RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin
  LIBRARY DESTINATION "${INSTALL_LIB_DIR}" COMPONENT shlib
  ARCHIVE DESTINATION "${INSTALL_LIB_DIR}" COMPONENT stlib
  COMPONENT dev)

# Create 'version.h'
configure_file(version.h.in
  "${CMAKE_CURRENT_BINARY_DIR}/version.h" @ONLY)
set(HEADERS ${HEADERS} ${CMAKE_CURRENT_BINARY_DIR}/version.h)

# Install headers
install(FILES ${HEADERS}
  DESTINATION "${INSTALL_INCLUDE_DIR}/${LIBRARY_FOLDER}" )
