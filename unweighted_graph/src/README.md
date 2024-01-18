# Graph Class

A C++ class for representing an unweighted graph with essential operations.

## Constructor

- `Graph(int x)`: Initializes the graph with a given number (x) of vertices.

## Modifiers

- `add_vertex(int vertex)`: Adds a vertex to the graph.
- `add_edge(int vertex1, int vertex2)`: Adds an edge between two vertices in the graph.
- `remove_edge(int vertex1, int vertex2)`: Removes an edge between two vertices in the graph.
- `remove_vertex(int vertex)`: Removes a vertex and its associated edges from the graph.

## Graph Operations

- `print() const`: Prints the adjacency list representation of the graph.
- `shortest_path(int curVert, int destVert)`: Finds the shortest path from a source (curVert) vertex to a destination (destVert) vertex using DFS.
- `get_neighbors(int vertex) const`: Gets the neighbors of a given vertex.
- `has_edge(int vertex1, int vertex2) const`: Checks if there is an edge between two vertices in the graph.
- `has_vertex(int vertex) const`: Checks if a vertex exists in the graph.
- `vertex_count() const`: Gets the total number of vertices in the graph.
- `edge_count() const`: Gets the total number of edges in the graph.
- `bfs(int curVert)`: Prints the graph in Breadth-First Search order.

## Private Helper Function

- `dfs(int curVert, int destVert, std::unordered_set<int>& visited, std::vector<int>& path, std::vector<int>& short_path) const`: Depth-First Search helper function for the `shortest_path` function.\

---