cmake_minimum_required(VERSION 3.10)
project("graph")

#adding required files
file(GLOB_RECURSE SRC_FILES "src/*.cpp")
file(GLOB_RECURSE HPP_FILES "src/*.hpp")
file(GLOB_RECURSE HDR_FILES "src/*.h")

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

add_executable(app ${SRC_FILES} ${HPP_FILES} ${HDR_FILES})

