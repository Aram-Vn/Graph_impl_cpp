#ifndef WEIGHTED_GRAPH_H
#define WEIGHTED_GRAPH_H

#include <iostream>
#include <limits>
#include <utility>
#include <vector>

class WeightedGraph
{
public:
    WeightedGraph(int size); // Constructor to initialize the weighted graph with a given number of vertices

public:
    void add_edge(int vertex, int vertex1, int weight); // Add a weighted edge between two vertices in the graph
    std::vector<int> dijkstra(int curVert);             /* Perform Dijkstra's algorithm to find the shortest paths from a
                                                         * source vertex to all other vertecces */
    void dijkstra_print(int curVert);                   // prints shortest paths from a given node(curVert) to all other vertecces

private:
    void dijkstra_helper(int vertex, std::vector<int>& fast); // Helper function for Dijkstra's algorithm

private:
    std::vector<std::vector<std::pair<int, int>>> m_weighted_graph; /* Adjacency list representation of the weighted
                                                                     * graph Each element is a pair representing a
                                                                     * connected vertex and the weight of the edge */
};

#endif // WEIGHTED_GRAPH_H