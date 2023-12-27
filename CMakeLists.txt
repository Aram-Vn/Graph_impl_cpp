cmake_minimum_required(VERSION 3.10)
project("graph")

# Unweighted graph
file(GLOB_RECURSE SRC_FILES "unweighted_graph/src/*.cpp")
file(GLOB_RECURSE HPP_FILES "unweighted_graph/src/*.hpp")
file(GLOB_RECURSE HDR_FILES "unweighted_graph/src/*.h")

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

add_executable(u_graph_app ${SRC_FILES} ${HPP_FILES} ${HDR_FILES})

# Weighted graph
file(GLOB_RECURSE W_SRC_FILES "weighted_graph/src/*.cpp")
file(GLOB_RECURSE W_HPP_FILES "weighted_graph/src/*.hpp")
file(GLOB_RECURSE W_HDR_FILES "weighted_graph/src/*.h")

add_executable(w_graph_app ${W_SRC_FILES} ${W_HPP_FILES} ${W_HDR_FILES})
