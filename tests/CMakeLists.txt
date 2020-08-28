add_executable(test_sim1 test_sim1.cpp)
target_link_libraries(test_sim1 ${LIBRARY_NAME})

# install(
#   TARGETS test_sim1
#   # EXPORT ${PROJECT_EXPORT} # uncomment in order to export target
#   RUNTIME DESTINATION bin
#   COMPONENT "${INSTALL_BIN_DIR}"
# )



# INCLUDE_DIRECTORIES(
#         ${BULLET_PHYSICS_SOURCE_DIR}/src
#         ${BULLET_PHYSICS_SOURCE_DIR}/examples
#         ${BULLET_PHYSICS_SOURCE_DIR}/examples/ThirdPartyLibs/glad
# )

# SET(AppBasicExampleGui2_SRCS
#     ${BULLET_PHYSICS_SOURCE_DIR}/examples/BasicDemo/BasicExample.cpp
#     ${BULLET_PHYSICS_SOURCE_DIR}/build3/bullet.rc
#     ${BULLET_PHYSICS_SOURCE_DIR}/examples/ExampleBrowser/OpenGLGuiHelper.cpp
#     ${BULLET_PHYSICS_SOURCE_DIR}/examples/ExampleBrowser/GL_ShapeDrawer.cpp
#     ${BULLET_PHYSICS_SOURCE_DIR}/examples/ExampleBrowser/CollisionShape2TriangleMesh.cpp
#     ${BULLET_PHYSICS_SOURCE_DIR}/examples/Utils/b3Clock.cpp
#     ${BULLET_PHYSICS_SOURCE_DIR}/examples/Vehicles/Hinge2Vehicle.cpp
# )

# #this define maps StandaloneExampleCreateFunc to the right 'CreateFunc'
# ADD_DEFINITIONS(-DB3_USE_STANDALONE_EXAMPLE)

# add_executable(opengl_example opengl_example.cpp ${AppBasicExampleGui2_SRCS})
# target_link_libraries(opengl_example ${LIBRARY_NAME} ${DEP_LIBS})
