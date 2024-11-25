cmake_minimum_required(VERSION 3.16)
project(practice CXX)

# Build type
set(CMAKE_BUILD_TYPE "Debug" )
Set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb -DDEBUG")
Set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

include_directories(include)
add_subdirectory(src)


