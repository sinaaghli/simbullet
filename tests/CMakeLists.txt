add_executable(test_sim1 test_sim1.cpp)
target_link_libraries(test_sim1 ${LIBRARY_NAME})

# install(
#   TARGETS test_sim1
#   # EXPORT ${PROJECT_EXPORT} # uncomment in order to export target
#   RUNTIME DESTINATION bin
#   COMPONENT "${INSTALL_BIN_DIR}"
# )

