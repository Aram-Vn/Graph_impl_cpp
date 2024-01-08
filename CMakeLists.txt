cmake_minimum_required(VERSION 3.10)
project("Graph")

add_subdirectory("unweighted_graph")
set(UNWEIGHTED_GRAPH_INCLUDE_DIRS unweighted_graph/src)
add_subdirectory("weighted_graph")
set(WEIGHTED_GRAPH_INCLUDE_DIRS weighted_graph/src)

add_executable(app "main.cpp")
target_include_directories(app PRIVATE ${UNWEIGHTED_GRAPH_INCLUDE_DIRS})
target_include_directories(app PRIVATE ${WEIGHTED_GRAPH_INCLUDE_DIRS})
target_link_libraries(app Unweighted_Graph)
target_link_libraries(app Weighted_Graph)