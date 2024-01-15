#ifndef GRAPH_H
#define GRAPH_H

#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>
#include <stdexcept>
#include <unordered_set>
#include <vector>

class Graph
{
public:
    Graph(int x); // Constructor to initialize the graph with a given number(x) of vertices

public:
    void add_vertex(int vertex);                               // Add a vertex to the graph
    void add_edge(int vertex1, int vertex2);                   // Add an edge between two vertices in the graph
    void print() const;                                        // Print the adjacency list representation of the graph.
    std::vector<int> shortest_path(int curVert, int destVert); // Find the shortest path from a source(curVert) vertex to a destination(destVert) vertex using dfs
    void remove_edge(int vertex1, int vertex2);                // Remove an edge between two vertices in the graph
    std::vector<int> get_neighbors(int vertex) const;          // Get the neighbors of a given vertex
    bool has_edge(int vertex1, int vertex2) const;             // Check if there is an edge between two vertices in the graph
    bool has_vertex(int vertex) const;                         // Check if a vertex exists in the graph
    size_t vertex_count() const;                               // Get the total number of vertices in the graph
    size_t edge_count() const;                                 // Get the total number of edges in the graph
    void bfs(int curVert);                                     // prints graph in Breadth-First Search order
    void remove_vertex(int vertex);                            // Remove a vertex and all its associated edges from the graph

private:
    void dfs(int curVert, int destVert, std::unordered_set<int>& visited, std::vector<int>& path,
             std::vector<int>& short_path) const; // Depth-First Search // helper function for shortest_path function

private:
    std::vector<std::vector<int>> m_graph; // Adjacency list representation of the unweighted graph
};

#endif // GRAPH_H