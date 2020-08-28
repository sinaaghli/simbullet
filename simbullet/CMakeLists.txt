# Set SOURCES variable
ADD_DEFINITIONS(-DB3_USE_STANDALONE_EXAMPLE)
file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${BULLET_PHYSICS_SOURCE_DIR}/examples/BasicDemo/BasicExample.cpp
    ${BULLET_PHYSICS_SOURCE_DIR}/build3/bullet.rc
    ${BULLET_PHYSICS_SOURCE_DIR}/examples/ExampleBrowser/OpenGLGuiHelper.cpp
    ${BULLET_PHYSICS_SOURCE_DIR}/examples/ExampleBrowser/GL_ShapeDrawer.cpp
    ${BULLET_PHYSICS_SOURCE_DIR}/examples/ExampleBrowser/CollisionShape2TriangleMesh.cpp
    ${BULLET_PHYSICS_SOURCE_DIR}/examples/Utils/b3Clock.cpp
)

# Set HEADERS variable
file(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

include(${CMAKE_SOURCE_DIR}/cmake/LibraryConfig.cmake)