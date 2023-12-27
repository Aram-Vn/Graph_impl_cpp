#include "graph.h"
#include <iostream>
#include <vector>

int main()
{
    Graph g(6);
    g.add_vertex(7);

    g.add_edge(0, 1);
    g.add_edge(0, 4);
    g.add_edge(0, 5);
    g.add_edge(0, 6);
    g.add_edge(1, 0);
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(2, 1);
    g.add_edge(2, 3);
    g.add_edge(3, 1);
    g.add_edge(3, 2);
    g.add_edge(3, 4);
    g.add_edge(3, 5);
    g.add_edge(4, 0);
    g.add_edge(4, 3);
    g.add_edge(4, 3);
    g.add_edge(5, 0);
    g.add_edge(5, 3);

    g.print();

    g.remove_edge(0, 1);

    g.print();

    std::vector<int> v = g.get_neighbors(1);

    for(int i : v)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    if(g.has_edge(2, 0))
    {
        std::cout << "YES" << std::endl;
    }
    else {
        std::cout << "NO" << std::endl; 
    }

   if(g.has_vertex(8))
    {
        std::cout << "YES" << std::endl;
    }
    else {
        std::cout << "NO" << std::endl; 
    }

    std::cout << g.vertex_count() << std::endl;
    std::cout << g.edge_count() << std::endl;
}
