cmake_minimum_required(VERSION 3.10)
project(OpenGLTest)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLM REQUIRED)

include_directories(${GLM_INCLUDE_DIRS})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(COPY res DESTINATION ${PROJECT_BINARY_DIR})
file(GLOB_RECURSE SRCS "src/*.cpp")

add_executable(myapp ${SRCS})
target_link_libraries(myapp glfw OpenGL::GL GLEW::GLEW)
