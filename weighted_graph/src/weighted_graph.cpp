#include "weighted_graph.h"



WeightedGraph::WeightedGraph(int size) : vec(size)
{
}

void WeightedGraph::add_edge(int vertex1, int vertex2, int weight)
{
    vec[vertex1].emplace_back(vertex2, weight);
}

std::vector<int> WeightedGraph::dijkstra(int curVert)
{
    std::vector<int> fast(vec.size(), std::numeric_limits<int>::max());
    fast[curVert] = 0;

    dijkstra_helper(curVert, fast);

    return fast;
}

 void WeightedGraph::dijkstra_helper(int vertex, std::vector<int>& fast)
 {
    if (fast[vertex] == std::numeric_limits<int>::max())
    {
        return;
    }

    for (auto neighbor : vec[vertex]) 
    {
        int cur_node = neighbor.first;
        int cur_weight = neighbor.second;

        int sum = fast[vertex] + cur_weight;

        if(sum < fast[cur_node])
        {
            fast[cur_node] = sum;
            dijkstra_helper(cur_node, fast);
        }
    }
}
