cmake_minimum_required(VERSION 3.5)
project(OrderBookDemo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(OrderBookDemo ${SOURCE_FILES})

include_directories(OrderBook)
add_subdirectory(OrderBook)
add_subdirectory(OrderBookTests)

target_link_libraries(OrderBookDemo OrderBook)