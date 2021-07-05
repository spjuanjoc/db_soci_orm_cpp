## SQLite3 backend tests target
set(BACKEND_TEST_NAME conan.soci.sqlite3.tests)
add_executable(${BACKEND_TEST_NAME} ../main.test.cpp sqlite3.test.cpp)


## Compiler options
include(../../cmake/CompilerOptions.cmake)
set_project_options(${BACKEND_TEST_NAME})


## Target
target_link_libraries(${BACKEND_TEST_NAME}
  PRIVATE
    fmt::fmt
    soci::soci
    SQLite::SQLite
)
target_compile_features(${BACKEND_TEST_NAME} PUBLIC cxx_std_17)
target_include_directories(${BACKEND_TEST_NAME} PRIVATE ${Catch2_INCLUDE_DIRS})


## Test
add_test(NAME ${BACKEND_TEST_NAME}
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
  COMMAND ${BACKEND_TEST_NAME} -d yes --order decl
)
