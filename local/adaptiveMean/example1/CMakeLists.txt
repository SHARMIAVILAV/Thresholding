cmake_minimum_required(VERSION 3.13)
# project(first)

set(CMAKE_CXX_STANDARD 11)

# add_executable(first first.cpp)
# # Add the include directories for your project
# target_include_directories(first PRIVATE opencv2/highgui/highgui.hpp)

cmake_minimum_required(VERSION 2.8)




project( adaptiveMean_eg1 )

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( adaptiveMean_eg1 adaptiveMean_eg1.cpp )

target_link_libraries( adaptiveMean_eg1 ${OpenCV_LIBS})