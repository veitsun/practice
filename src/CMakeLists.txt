# Collect all .cpp in the src directory
file(GLOB HELLOlib_SRC_CPP ${PROJECT_SOURCE_DIR}/src/*.cpp)

# Combine both lists into HELLOlib_src
set(HELLOlib_SRC ${HELLOlib_SRC_CPP})


find_path(INCLUDE_DIR Harem.h HINTS ${CMAKE_SOURCE_DIR}/include)
if(NOT INCLUDE_DIR)
  message(FATAL_ERROR "Harem.h not found !")
endif()

include_directories(INCLUDE_DIR)


# Create a static library from the collected source files
add_library(SUNWEI SHARED  ${HELLOlib_SRC})
target_include_directories(SUNWEI PUBLIC ${INCLUDE_DIR})
