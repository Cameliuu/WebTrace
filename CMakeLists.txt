cmake_minimum_required(VERSION 3.25)
project(WebTrace)

set(CMAKE_CXX_STANDARD 17)

add_executable(WebTrace main.cpp App/app.cpp Color/color.cpp Image/image.cpp)
