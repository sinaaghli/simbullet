# Ensure that ${simbullet_INCLUDE_DIR} is first on search path
INCLUDE_DIRECTORIES( BEFORE ${simbullet_INCLUDE_DIR} )
INCLUDE_DIRECTORIES( BEFORE ${simbullet_LIBRARIES} )

# Tests to run
SET( TEST_SOURCES test_sim1)

FOREACH(test_src ${TEST_SOURCES})
  ADD_EXECUTABLE( ${test_src} ${test_src}.cpp)
  message("library --> ${simbullet_LIBRARIES}")
  target_link_libraries( ${test_src} ${LIBRARY_NAME} )
  ADD_TEST( ${test_src} ${test_src} )
ENDFOREACH(test_src)
