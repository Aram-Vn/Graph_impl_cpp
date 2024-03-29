#include "weighted_graph.h"

WeightedGraph::WeightedGraph(int size) : m_weighted_graph(size)
{
}

void WeightedGraph::add_edge(int vertex1, int vertex2, int weight)
{
    m_weighted_graph[vertex1].emplace_back(vertex2, weight);
}

std::vector<int> WeightedGraph::dijkstra(int curVert)
{
    std::vector<int> fast(m_weighted_graph.size(), std::numeric_limits<int>::max());
    fast[curVert] = 0;

    dijkstra_helper(curVert, fast);

    return fast;
}

void WeightedGraph::dijkstra_print(int curVert)
{
    std::vector<int> v = this->dijkstra(curVert);

    int j = 0;

    for (int i : v)
    {
        if (i == std::numeric_limits<int>::max())
        {
            ++j;
            continue;
        }

        std::cout << "shortest path from  " << curVert << "  to  " << j << "  is  " << i;
        ++j;
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void WeightedGraph::dijkstra_helper(int vertex, std::vector<int>& fast)
{
    if (fast[vertex] == std::numeric_limits<int>::max())
    {
        return;
    }

    for (auto neighbor : m_weighted_graph[vertex])
    {
        int cur_node = neighbor.first;
        int cur_weight = neighbor.second;

        int sum = fast[vertex] + cur_weight;

        if (sum < fast[cur_node])
        {
            fast[cur_node] = sum;
            dijkstra_helper(cur_node, fast);
        }
    }
}
