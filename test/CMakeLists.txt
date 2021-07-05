set(TEST_NAME ${PROJECT_NAME}_AllTests)

add_executable(${TEST_NAME} main.test.cpp)
add_test(${TEST_NAME} ${TEST_NAME}) # for ctest

## Compiler options
include(../cmake/CompilerOptions.cmake)
set_project_options(${TEST_NAME})

## Find third-party packages
find_package(Catch2 REQUIRED)

target_link_libraries(${TEST_NAME} PRIVATE fmt::fmt)
target_compile_features(${TEST_NAME} PUBLIC cxx_std_17)
target_include_directories(${TEST_NAME} PRIVATE ${Catch2_INCLUDE_DIRS} ../include)

add_subdirectory(none)
add_subdirectory(empty)
add_subdirectory(sqlite3)
#add_subdirectory(odbc)
#add_subdirectory(mysql)
