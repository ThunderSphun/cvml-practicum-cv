cmake_minimum_required(VERSION 3.22)
project(practicum)

set(CMAKE_CXX_STANDARD 14)

set(OpenCV_DIR "OpenCV")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(practicum main.cpp)

set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs opencv_objdetect)
target_link_libraries(practicum PRIVATE ${OpenCV_LIBS})