#include "graph.h"
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <type_traits>
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
                std::vector<int>& short_path) const
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
    else
    {
        for (int neighbor : vec[curVert])
        {
            if (visited.find(neighbor) == visited.end())
            {
                dfs(neighbor, destVert, visited, path, short_path);
            }
        }
    }
    path.pop_back();
    visited.erase(curVert);
}

//-----------------------------_remove_edge_----------------------//
void Graph::remove_edge(int vertex1, int vertex2)
{
    if (vertex1 < 0 || vertex1 >= vec.size() || vertex2 < 0 || vertex2 >= vec.size())
    {
        throw std::out_of_range("for remove_edge\ncant add edge");
    }

    auto newEnd = std::remove(vec[vertex1].begin(), vec[vertex1].end(), vertex2);
    vec[vertex1].erase(newEnd, vec[vertex1].end());
}

//---------------------------_get_neighbors_------------------------//
std::vector<int> Graph::get_neighbors(int vertex) const
{
    if (vertex < 0 || vertex >= vec.size())
    {
        throw std::out_of_range("for get_neighbors\ncan't add edge");
    }

    return vec[vertex];
}

//---------------------------_has_edge_-----------------------------//
bool Graph::has_edge(int vertex1, int vertex2) const
{
    if (vertex1 < 0 || vertex1 >= vec.size() || vertex2 < 0 || vertex2 >= vec.size())
    {
        throw std::out_of_range("for remove_edge\ncant add edge");
    }

    auto it = std::find(vec[vertex1].begin(), vec[vertex1].end(), vertex2);

    if (it != vec[vertex1].end())
    {
        return true;
    }
    else
    {
        return false;
    }
}

//-----------------------------_has_vertex_--------------------------//
bool Graph::has_vertex(int vertex) const
{
    if (vertex < 0 || vertex >= vec.size())
    {
        return false;
    }
    else
    {
        return true;
    }
}

//------------------------------_vertex_count_-----------------------//
size_t Graph::vertex_count() const
{
    return vec.size() - 1;
}

//------------------------------_edge_count_-------------------------//
size_t Graph::edge_count() const
{
    size_t count = 0;

    for (int i = 0; i < vec.size(); ++i)
    {
        for (int j = 0; j < vec[i].size(); ++j)
        {
            ++count;
        }
    }

    return count;
}