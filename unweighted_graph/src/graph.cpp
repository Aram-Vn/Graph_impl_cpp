#include "graph.h"
#include <cstddef>
#include <iostream>
#include <queue>
#include <stdexcept>
#include <type_traits>
#include <unordered_set>
#include <vector>

Graph::Graph(int x) : m_graph(x, std::vector<int>())
{
}

//-------------------------_add_vertex_---------------------//
void Graph::add_vertex(int vertex)
{
    try
    {
        if (vertex > m_graph.size() + 1 || vertex < 0)
        {
            std::cout << "can't add vertex " << vertex << std::endl;
            throw std::out_of_range("in add_vertex\n");
        }

        m_graph.emplace_back(std::vector<int>());
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

//--------------------------_add_edge_-----------------------//
void Graph::add_edge(int vertex1, int vertex2)
{
    if (vertex1 < 0 || vertex1 >= m_graph.size() || vertex2 < 0 || vertex2 >= m_graph.size())
    {
        throw std::out_of_range("\nfor add_edge\ncant add edge");
    }

    auto it = std::find(m_graph[vertex1].begin(), m_graph[vertex1].end(), vertex2);

    if (it == m_graph[vertex1].end())
    {
        m_graph[vertex1].push_back(vertex2);
    }
}

//---------------------------_print_--------------------------//
void Graph::print() const
{
    for (int i = 0; i < m_graph.size(); ++i)
    {
        std::cout << i << " -> ";

        for (int j = 0; j < m_graph[i].size(); ++j)
        {
            std::cout << m_graph[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

//--------------------------_shortest_path_---------------------//
std::vector<int> Graph::shortest_path(int curVert, int destVert)
{
    if (curVert < 0 || curVert >= m_graph.size() || destVert < 0 || destVert >= m_graph.size())
    {
        throw std::out_of_range("\nin shortest_path\ncurVert || destVert is out of rainge");
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
        for (int neighbor : m_graph[curVert])
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
    if (vertex1 < 0 || vertex1 >= m_graph.size() || vertex2 < 0 || vertex2 >= m_graph.size())
    {
        throw std::out_of_range("\nfor remove_edge\ncant remove edge");
    }

    auto newEnd = std::remove(m_graph[vertex1].begin(), m_graph[vertex1].end(), vertex2);
    m_graph[vertex1].erase(newEnd, m_graph[vertex1].end());
}

//---------------------------_get_neighbors_------------------------//
std::vector<int> Graph::get_neighbors(int vertex) const
{
    if (vertex < 0 || vertex >= m_graph.size())
    {
        throw std::out_of_range("\nfor get_neighbors\ncan't find neighbor");
    }

    return m_graph[vertex];
}

//---------------------------_has_edge_-----------------------------//
bool Graph::has_edge(int vertex1, int vertex2) const
{
    if (vertex1 < 0 || vertex1 >= m_graph.size() || vertex2 < 0 || vertex2 >= m_graph.size())
    {
        throw std::out_of_range("\nfor remove_edge\ncant find edge");
    }

    auto it = std::find(m_graph[vertex1].begin(), m_graph[vertex1].end(), vertex2);

    if (it != m_graph[vertex1].end())
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
    if (vertex < 0 || vertex >= m_graph.size())
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
    return m_graph.size() - 1;
}

//------------------------------_edge_count_-------------------------//
size_t Graph::edge_count() const
{
    size_t count = 0;

    for (int i = 0; i < m_graph.size(); ++i)
    {
        for (int j = 0; j < m_graph[i].size(); ++j)
        {
            ++count;
        }
    }

    return count;
}

//------------------------------_bfs_---------------------------------//
void Graph::bfs(int curVert)
{
    std::unordered_set<int> visited;
    std::queue<int> nodes;

    nodes.push(curVert);
    visited.insert(curVert);

    while (!nodes.empty())
    {
        int tmp = nodes.front();
        std::cout << tmp << " ";
        nodes.pop();

        for (int neighbor : m_graph[tmp])
        {
            if (visited.find(neighbor) == visited.end())
            {
                nodes.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }
    std::cout << std::endl;
}

//----------------------------_remove_vertex_--------------------------//
void Graph::remove_vertex(int vertex)
{
    if (vertex < 0 || vertex >= m_graph.size())
    {
        throw std::out_of_range("\nfor remove_vertex\ncant remove_vertex");
    }

    for (int i = 0; i < m_graph.size(); ++i)
    {
        this->remove_edge(i, vertex);
    }

    for (int i = vertex; i < m_graph.size(); ++i)
    {
        for (int j = 0; j < m_graph[i].size(); ++j)
        {
            if (m_graph[i][j] > vertex)
            {
                m_graph[i][j]--;
            }
        }
    }

    m_graph.erase(m_graph.begin() + vertex);
}