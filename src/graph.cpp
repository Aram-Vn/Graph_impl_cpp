#include "graph.h"
#include <iostream>
#include <stdexcept>
#include <unordered_set>
#include <vector>

Graph::Graph(int x) : vec(x, std::vector<int>())
{
}

//-------------------------_add_vertex_---------------------//
void Graph::add_vertex(int vertex)
{
    if (vertex < vec.size())
    {
        std::cout << "in add_vertex\ncan't add vertex" << std::endl;
        return;
    }

    vec.emplace_back(std::vector<int>());
}

//--------------------------_add_edge_-----------------------//
void Graph::add_edge(int vertex1, int vertex2)
{
    if (vertex1 < 0 || vertex1 >= vec.size() || vertex2 < 0 || vertex2 >= vec.size())
    {
        std::cout << "for add_edge\ncant add edge" << std::endl;
        return;
    }

    auto it = std::find(vec[vertex1].begin(), vec[vertex1].end(), vertex2);

    if (it == vec[vertex1].end())
    {
        vec[vertex1].push_back(vertex2);
    }
}

//---------------------------_print_--------------------------//
void Graph::print() const
{
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << i << " -> ";

        for (int j = 0; j < vec[i].size(); ++j)
        {
            std::cout << vec[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

//--------------------------_shortest_path_---------------------//
std::vector<int> Graph::shortest_path(int curVert, int destVert)
{
    if (curVert < 0 || curVert >= vec.size() || destVert < 0 || destVert >= vec.size())
    {
        std::cout << "in shortest_path\ncan't find shortest path" << std::endl;
        std::out_of_range("curVert || destVert is out of rainge");
    }

    std::unordered_set<int> visited;
    std::vector<int> path;
    std::vector<int> short_path;

    dfs(curVert, destVert, visited, path, short_path);

    return short_path;
}

void Graph::dfs(int curVert, int destVert, std::unordered_set<int>& visited, std::vector<int>& path,
                std::vector<int>& short_path)
{
    visited.insert(curVert);
    path.push_back(curVert);

    if (curVert == destVert)
    {
        if (short_path.empty() || path.size() < short_path.size())
        {
            short_path = path;
        }
    }
    else {
        for (int neighbor : vec[curVert])
        {   
            if(visited.find(neighbor) == visited.end())
            {
               dfs(neighbor, destVert, visited, path, short_path);
            }
        }
    }
    path.pop_back();
    visited.erase(curVert);
}

