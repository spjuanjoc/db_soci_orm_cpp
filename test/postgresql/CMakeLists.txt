## PostgreSQL backend tests target
set(BACKEND_TEST_NAME conan.soci.postgresql.tests)
add_executable(${BACKEND_TEST_NAME} postgresql.test.cpp)


## Compiler options
include(../../cmake/CompilerOptions.cmake)
set_compiler_options(${BACKEND_TEST_NAME})

## Find third-party packages
find_package(Catch2 REQUIRED)
find_package(fmt REQUIRED)
find_package(SOCI REQUIRED)


## Target
target_link_libraries(${BACKEND_TEST_NAME}
  PRIVATE
    ${Catch2_LIBRARIES}
    ${fmt_LIBRARIES}
    ${SOCI_LIBRARIES}
)
target_include_directories(${BACKEND_TEST_NAME} PRIVATE ${Catch2_INCLUDE_DIRS})

## Test
add_test(
  NAME              ${BACKEND_TEST_NAME}
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
  COMMAND           ${BACKEND_TEST_NAME} -d yes --order lex
)
