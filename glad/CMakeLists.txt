cmake_minimum_required(VERSION 3.13.0)
project(glad C)



include_directories("include")
add_library(glad src/glad.c)

target_include_directories(glad PUBLIC include/)