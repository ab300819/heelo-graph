cmake_minimum_required(VERSION 3.13.0)
project(hello-graph C CXX)

set(CMAKE_CXX_STANDARD 20)

if (CMAKE_SYSTEM_NAME MATCHES "Linux")
    message(STATUS "Current Platform: ${CMAKE_SYSTEM_NAME}")
elseif (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    message(STATUS "Current Platform: ${CMAKE_SYSTEM_NAME}")

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

elseif (CMAKE_SYSTEM_NAME MATCHES "Windows")
    message(STATUS "Current Platform: ${CMAKE_SYSTEM_NAME}")

    set(GLFW_PREFIX "C:/Users/mengshen/Documents/source/GLFW")
    set(glfw3_DIR ${GLFW_PREFIX}/lib/cmake/glfw3)
    
    find_package(glfw3 REQUIRED)
    include_directories(${GLFW_PREFIX}/include)
    set(GLFW_LIBRARIES glfw)

else ()
    message(STATUS "Unknown Platform")
endif ()

add_subdirectory(glad/)

add_executable(hello_window_clear "graph/hello_window_clear.cpp")
target_link_libraries(hello_window_clear ${GLFW_LIBRARIES} glad)

add_executable(hello_triangle_indexed "graph/hello_triangle_indexed.cpp")
target_link_libraries(hello_triangle_indexed ${GLFW_LIBRARIES} glad)

add_executable(test "graph/test.cpp")
