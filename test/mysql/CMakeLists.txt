cmake_minimum_required(VERSION 3.1)

# SQLite3 tests target
set(BACKEND_TEST_NAME conan.soci.mysql.tests)
add_executable(${BACKEND_TEST_NAME} ../main.test.cpp mysql.test.cpp)
target_compile_features(${BACKEND_TEST_NAME} PUBLIC cxx_std_17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_target_link_libraries(${BACKEND_TEST_NAME}
    CONAN_PKG::fmt
    CONAN_PKG::soci_core
    CONAN_PKG::soci_mysql
    CONAN_PKG::mysqlclient
    pthread
    dl
    )

enable_testing()
add_test(NAME ${BACKEND_TEST_NAME}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMAND ${BACKEND_TEST_NAME})
