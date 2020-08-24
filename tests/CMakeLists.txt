add_executable(test_sim1 test_sim1.cpp)
target_link_libraries(test_sim1 ${LIBRARY_NAME})

# install(
#   TARGETS test_sim1
#   # EXPORT ${PROJECT_EXPORT} # uncomment in order to export target
#   RUNTIME DESTINATION bin
#   COMPONENT "${INSTALL_BIN_DIR}"
# )

################################################################################
# Standalone BasicExampleGui using OpenGL (but not the example browser)

# INCLUDE_DIRECTORIES(
#         ${BULLET_PHYSICS_SOURCE_DIR}/src
#         ${BULLET_PHYSICS_SOURCE_DIR}/btgui
#         ${BULLET_PHYSICS_SOURCE_DIR}/examples
#         ${BULLET_PHYSICS_SOURCE_DIR}/examples/ThirdPartyLibs/glad
# )


# SET(AppBasicExampleGui2_SRCS
#     ${BULLET_PHYSICS_SOURCE_DIR}/examples/BasicDemo/BasicExample.cpp
#     ${BULLET_PHYSICS_SOURCE_DIR}/build3/bullet.rc
# 	${PROJECT_SOURCE_DIR}/tests/main_opengl_single_example.cpp
#     ${BULLET_PHYSICS_SOURCE_DIR}/examples/ExampleBrowser/OpenGLGuiHelper.cpp
#     ${BULLET_PHYSICS_SOURCE_DIR}/examples/ExampleBrowser/GL_ShapeDrawer.cpp
#     ${BULLET_PHYSICS_SOURCE_DIR}/examples/ExampleBrowser/CollisionShape2TriangleMesh.cpp
# 	${BULLET_PHYSICS_SOURCE_DIR}/examples/Utils/b3Clock.cpp
# )

#this define maps StandaloneExampleCreateFunc to the right 'CreateFunc'
# ADD_DEFINITIONS(-DB3_USE_STANDALONE_EXAMPLE)

# LINK_LIBRARIES(
#         BulletDynamics BulletCollision LinearMath OpenGLWindow Bullet3Common 
# )

#some code to support OpenGL and Glew cross platform
# IF (WIN32)
#         INCLUDE_DIRECTORIES(
#              ${BULLET_PHYSICS_SOURCE_DIR}/btgui/OpenGLWindow/GlewWindows
#         )
#         ADD_DEFINITIONS(-DGLEW_STATIC)
# 	LINK_LIBRARIES( ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY} )
# ELSE(WIN32)
#         IF(APPLE)
#                 find_library(COCOA NAMES Cocoa)
#                 MESSAGE(${COCOA})
#                 link_libraries(${COCOA} ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY})

#         ELSE(APPLE)
#                 INCLUDE_DIRECTORIES(
#                         ${BULLET_PHYSICS_SOURCE_DIR}/btgui/OpenGLWindow/GlewWindows
#                 )
#                 ADD_DEFINITIONS("-DGLEW_INIT_OPENGL11_FUNCTIONS=1")
#                 ADD_DEFINITIONS("-DGLEW_STATIC")
#                 ADD_DEFINITIONS("-DGLEW_DYNAMIC_LOAD_ALL_GLX_FUNCTIONS=1")

#                 LINK_LIBRARIES(  pthread ${DL} )
#         ENDIF(APPLE)
# ENDIF(WIN32)


# ADD_EXECUTABLE(AppBasicExampleGui2
#                 ${AppBasicExampleGui2_SRCS}
# )


# IF (INTERNAL_ADD_POSTFIX_EXECUTABLE_NAMES)
#                         SET_TARGET_PROPERTIES(AppBasicExampleGui PROPERTIES  DEBUG_POSTFIX "_Debug")
#                         SET_TARGET_PROPERTIES(AppBasicExampleGui PROPERTIES  MINSIZEREL_POSTFIX "_MinsizeRel")
#                         SET_TARGET_PROPERTIES(AppBasicExampleGui PROPERTIES  RELWITHDEBINFO_POSTFIX "_RelWithDebugInfo")
# ENDIF(INTERNAL_ADD_POSTFIX_EXECUTABLE_NAMES)


