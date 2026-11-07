cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME Kumometry1.0)
project(${PROJECT_NAME} VERSION 1.0 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(Vector STATIC 
    src/Vector2.cpp
)

add_executable (MyApp
	examples/main.cpp
)

enable_testing()

add_executable (geometry_tests
    tests/geometry_test.cc
)

target_link_libraries(MyApp PRIVATE Vector)

target_link_libraries(geometry_tests PRIVATE Vector
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(geometry_tests)

target_include_directories(Vector PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
