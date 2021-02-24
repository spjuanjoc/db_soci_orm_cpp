set(TEST_NAME ${PROJECT_NAME}_AllTests)
add_definitions(-DGTEST_LANGUAGE_CXX11)

add_executable(${TEST_NAME} main.test.cpp)

# ---
# target instructions must be set after add_executable or add_library instructions
target_compile_options(${TEST_NAME} INTERFACE ${PROJECT_OPTIONS})
# Get the sources
#file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.test.cpp)
#target_sources(${TEST_NAME} PUBLIC ${TEST_SOURCES})
# Get the headers
#set(INCLUDES include)
#include_directories(PUBLIC ${INCLUDES})
#target_include_directories(${TEST_NAME} PUBLIC ${INCLUDES})

target_compile_features(${TEST_NAME} PRIVATE cxx_std_17)

if (ENABLE_CONAN)
  message("** Conan libs: ${CONAN_LIBS}")

  include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
#  conan_basic_setup(TARGETS)
  conan_target_link_libraries(${TEST_NAME} ${CONAN_LIBS})
endif ()

add_subdirectory(none)
add_subdirectory(empty)
add_subdirectory(sqlite3)
#add_subdirectory(odbc)
#add_subdirectory(mysql)

add_test(NAME ${TEST_NAME}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMAND ${TEST_NAME})
