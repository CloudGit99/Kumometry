cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME Kumometry1.0)
project(${PROJECT_NAME} VERSION 1.0 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(Vector STATIC 
    src/Vector2.cpp
)

add_executable (MyApp
	examples/main.cpp
)

target_link_libraries(MyApp PRIVATE Vector)

target_include_directories(Vector PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
