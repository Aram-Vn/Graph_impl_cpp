cmake_minimum_required(VERSION 3.10)
project("WeightedGraph")

# Unweighted graph
file(GLOB_RECURSE SRC_FILES "src/*.cpp")
#file(GLOB_RECURSE HPP_FILES "src/*.hpp")
file(GLOB_RECURSE HDR_FILES "src/*.h")

add_library(Weighted_Graph ${SRC_FILES} ${HDR_FILES})

set_property(TARGET Weighted_Graph PROPERTY CXX_STANDARD 17)