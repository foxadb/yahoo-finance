cmake_minimum_required(VERSION 3.6.3)
project(yahoo-finance CXX)

# Enable C+11
set(CMAKE_CXX_STANDARD 11)

# Add the library source files
file(GLOB LIB_SOURCES src/*.cpp)
file(GLOB LIB_HEADERS src/*.hpp )
add_library(yahoo-finance ${LIB_SOURCES} ${LIB_HEADERS})
