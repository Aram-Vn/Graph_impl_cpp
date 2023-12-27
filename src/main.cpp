#include "graph.h"
#include <vector>

int main()
{
    Graph  g(6);
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

    std::vector<int> res;
    res =g.shortest_path(0,2);

    for(auto i : res) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
