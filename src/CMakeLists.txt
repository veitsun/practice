# Collect all .cpp in the src directory
file(GLOB HELLOlib_src_cpp ${PROJECT_SOURCE_DIR}/src/*.cpp)

# Combine both lists into HELLOlib_src
set(HELLOlib_src ${HELLOlib_src_cpp})

# Create a static library from the collected source files
add_library(SUNWEI SHARED  ${HELLOlib_src})

add_executable(sunwei ../sunwei.cpp)
add_executable(spp ../spp.cpp)


target_link_libraries(sunwei PRIVATE SUNWEI)
target_link_libraries(spp PRIVATE SUNWEI)
