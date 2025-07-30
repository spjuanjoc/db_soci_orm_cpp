cmake_minimum_required(VERSION 3.24)

project(db_soci_orm_cpp
  VERSION "0.1.0"
  LANGUAGES CXX
)

option(ENABLE_PCH   "Enable Precompiled Headers"  False)
option(ENABLE_TESTS "Enable tests"                True)


set(SOURCES src/main.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})


## Compiler options
include(cmake/CompilerOptions.cmake)
set_compiler_options(${PROJECT_NAME})


## Find third-party packages
find_package(fmt REQUIRED)
find_package(SOCI REQUIRED)


## Target
target_include_directories(${PROJECT_NAME}
  SYSTEM PRIVATE # These directories must be placed before other non-system directories
    ${fmt_INCLUDE_DIRS}
    ${SOCI_INCLUDE_DIRS}
  PUBLIC
    include
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    ${fmt_LIBRARIES}
    ${SOCI_LIBRARIES}
)


## Check custom options
if (ENABLE_PCH) # Since CMake 3.15
  target_precompile_headers(${PROJECT_NAME} INTERFACE <vector> <string> <map> <utility>)
  message("PCH enabled")
endif ()

if (ENABLE_TESTS)
  message(STATUS "Tests enabled")
  enable_testing() # Must be placed before add_subdirectory
  add_subdirectory(test)
endif ()


## Install commands
install(TARGETS ${PROJECT_NAME}
  RUNTIME DESTINATION "/opt/${PROJECT_NAME}"
)

set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Juan Jose Castellanos <juancho.312@hotmail.com>")
include(CPack)
