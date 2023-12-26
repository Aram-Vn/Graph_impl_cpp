#include <algorithm>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <unordered_set>
#include <vector>

class Graf
{
    std::vector<std::vector<int>> vec;

public:
    Graf(int x) : vec(x, std::vector<int>()) {}

    void add_verdex(int vertex)
    {
        if (vertex < vec.size())
        {
            return;
        }

        vec.push_back(std::vector<int>());
    }

    void add_edges(int vertex1, int vertex2)
    {
        if (vertex1 < 0 || vertex1 >= vec.size() || vertex2 < 0 | vertex2 >= vec.size())
        {
            return;
        }

        auto it = std::find(vec[vertex1].begin(), vec[vertex1].end(), vertex2);
        if (it == vec[vertex1].end())
        {
            vec[vertex1].push_back(vertex2);
        }
    }

    void print()
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

    std::vector<int> shortP(int curVert, int endVert)
    {
        std::unordered_set<int> visited;
        std::vector<int> path;
        std::vector<int> short_path;

        dfs(curVert, endVert, visited, path, short_path);

        return short_path;
    }

    void dfs(int curVert, int endVert, std::unordered_set<int>& visited, std::vector<int>& path,
             std::vector<int>& short_path)
    {
        visited.insert(curVert);
        path.push_back(curVert);

        if (curVert == endVert)
        {
            if (short_path.empty() || path.size() < short_path.size()) {}
        }
    }
};

int main()
{
    Graf g(6);

    g.add_edges(0, 1);
    g.add_edges(0, 4);
    g.add_edges(0, 5);
    g.add_edges(1, 0);
    g.add_edges(1, 2);
    g.add_edges(1, 3);
    g.add_edges(2, 1);
    g.add_edges(2, 3);
    g.add_edges(3, 1);
    g.add_edges(3, 2);
    g.add_edges(3, 4);
    g.add_edges(3, 5);
    g.add_edges(4, 0);
    g.add_edges(4, 3);
    g.add_edges(4, 3);
    g.add_edges(5, 0);
    g.add_edges(5, 3);

    g.print();
}