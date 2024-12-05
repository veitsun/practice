cmake_minimum_required(VERSION 3.16)
project(practice CXX)

# Build type
set(CMAKE_BUILD_TYPE "Debug" )
Set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb -DDEBUG")
Set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
set(CMAKE_EXPORT_COMPILE_COMMANDS on)


include_directories(${INCLUDE_DIR})
add_subdirectory(src)


add_executable(sunwei sunwei.cpp)
add_executable(spp spp.cpp)
add_executable(spp1 spp1.cpp)

target_include_directories(sunwei PUBLIC ${INCLUDE_DIR})
target_include_directories(spp PUBLIC ${INCLUDE_DIR})
target_include_directories(spp1 PUBLIC ${INCLUDE_DIR})



target_link_libraries(sunwei PRIVATE SUNWEI pthread)
target_link_libraries(spp PRIVATE SUNWEI pthread)
target_link_libraries(spp1 PRIVATE SUNWEI pthread)

