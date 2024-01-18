# WeightedGraph Class

A C++ class for representing a weighted graph with Dijkstra's algorithm for finding shortest paths.

## Constructor

- `WeightedGraph(int size)`: Initializes the weighted graph with a given number of vertices.

## Modifiers

- `add_edge(int vertex, int vertex1, int weight)`: Adds a weighted edge between two vertices in the graph.

## Graph Algorithm

- `dijkstra(int curVert)`: Performs Dijkstra's algorithm to find the shortest paths from a source vertex to all other vertices.

### Private Helper Function

- `dijkstra_helper(int vertex, std::vector<int>& fast)`: Helper function for Dijkstra's algorithm.

## Implementation Details

- The weighted graph is represented using an adjacency list.
- Each element in the adjacency list is a pair representing a connected vertex and the weight of the edge.


