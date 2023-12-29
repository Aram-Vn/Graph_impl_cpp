#ifndef WEIGHTED_GRAPH_H
#define WEIGHTED_GRAPH_H

#include <iostream>
#include <utility>
#include <vector>
#include <limits>

class WeightedGraph
{
public:
    WeightedGraph(int size);

public:
    void add_edge(int vertex, int vertex1, int weight);
    std::vector<int> dijkstra(int curVert);

private:
    void dijkstra_helper(int vertex, std::vector<int>& fast);

private:
    std::vector<std::vector<std::pair<int, int>>> vec;
};

#endif // WEIGHTED_GRAPH_H