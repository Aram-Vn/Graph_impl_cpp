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
    void print();                                              //
    std::vector<int> shortest_path(int curVert, int destVert); //

    std::vector<int> get_neighbors(int vertex);
    bool has_edge(int vertex1, int vertex2);
    bool has_vertex(int vertex);

        private : void dfs(int curVert, int destVert, std::unordered_set<int>& visited, std::vector<int>& path,
                           std::vector<int>& short_path);

private:
    std::vector<std::vector<int>> vec;
};

#endif // GRAPH_H