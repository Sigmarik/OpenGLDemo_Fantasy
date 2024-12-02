# Projects Settings
cmake_minimum_required(VERSION 3.12)

# set(CMAKE_CXX_COMPILER "C:/MinGW/bin/g++.exe")
# set(CMAKE_C_COMPILER "C:/MinGW/bin/gcc.exe")
project(OpenGLDemo)

file(GLOB OpenGLDemo_SRC CONFIGURE_DEPENDS "src/*.h" "src/*.cpp")

set(CMAKE_CXX_FLAGS "-Wall -Wno-dev -Os -s")

add_executable(OpenGLDemo ${OpenGLDemo_SRC})

set_property(TARGET OpenGLDemo PROPERTY CXX_STANDARD 11)
target_compile_options(OpenGLDemo PRIVATE -Wall)

add_definitions(-DGLEW_STATIC)
add_subdirectory(lib/glfw EXCLUDE_FROM_ALL)
add_subdirectory(lib/glew EXCLUDE_FROM_ALL)
add_subdirectory(lib/glm EXCLUDE_FROM_ALL)

target_link_libraries(OpenGLDemo
  PRIVATE glfw
  PRIVATE libglew_static
  PRIVATE glm
)

configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/src/asset.hpp.in
  ${CMAKE_CURRENT_BINARY_DIR}/src/asset.hpp
)
target_include_directories(OpenGLDemo
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)
