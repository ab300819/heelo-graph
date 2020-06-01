cmake_minimum_required(VERSION 3.13.0)
project(hello-graph C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

message(STATUS ${CMAKE_SYSTEM_NAME})
if (CMAKE_SYSTEM_NAME MATCHES "Linux")

elseif (CMAKE_SYSTEM_NAME MATCHES "Darwin")

endif ()

find_package(PkgConfig REQUIRED)

pkg_search_module(glut REQUIRED glut)
pkg_search_module(glew REQUIRED glew)
pkg_search_module(GLFW REQUIRED glfw3)

include_directories(
        ${glut_INCLUDE_DIRS}
        ${glew_INCLUDE_DIRS}
        ${GLFW_INCLUDE_DIRS}
)

link_directories(
        ${glut_LIBRARY_DIRS}
        ${glew_LIBRARY_DIRS}
        ${GLFW_LIBRARY_DIRS}
)

add_subdirectory(glad/)

add_executable(hello-graph graph/main.cpp)
target_link_libraries(hello-graph ${GLFW_LIBRARIES} glad)