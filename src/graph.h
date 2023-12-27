#ifndef GRAPH_H
#define GRAPH_H

#include <algorithm>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <unordered_set>
#include <vector>

class Graph
{
public:
    Graph(int x); //

public:
    void add_vertex(int vertex);                               //
    void add_edge(int vertex1, int vertex2);                   //
    void print() const;                                        //
    std::vector<int> shortest_path(int curVert, int destVert); //

    void remove_vertex(int vertex);
    void remove_edge(int vertex1, int vertex2);
    std::vector<int> get_neighbors(int vertex);
    bool has_edge(int vertex1, int vertex2) const;
    bool has_vertex(int vertex) const;
    size_t vertex_count() const;
    size_t edge_count() const;
        // connected_components();

private:
    void dfs(int curVert, int destVert, std::unordered_set<int>& visited, std::vector<int>& path,
             std::vector<int>& short_path);

private:
    std::vector<std::vector<int>> vec;
};

#endif // GRAPH_H