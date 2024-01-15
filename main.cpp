#include <graph.h>
#include <iostream>
#include <vector>
#include <weighted_graph.h>

int main()
{
    //-------------------------------WeightedGraph_TEST----------------------------//
    std::cout << "WeightedGraph_TEST\n" << "***************************\n" << std::endl;
    
    WeightedGraph wg(7);

    wg.add_edge(0, 1, 1);
    wg.add_edge(0, 3, 3);
    wg.add_edge(0, 2, 2);

    wg.add_edge(1, 3, 4);

    wg.add_edge(3, 2, 5);
    wg.add_edge(3, 6, 8);
    wg.add_edge(3, 4, 5);

    wg.add_edge(2, 4, 7);
    wg.add_edge(2, 5, 6);

    wg.add_edge(4, 6, 9);

    wg.add_edge(5, 6, 10);

    /*  [0] -----"2"--->[2]----"6"---->[5]----|
        |   \               \                 |
        |    \               \                |
       "1"    "3"            "7"             "10"
        |      \               \              |
        |       >               >             >
      [1]--"4"-->[3] ----"5"--->[4] --"9"--->[6]
                  |                           ^
                  |                           |
                  -----------"8"---------------
    */

    int cur_node = 0;

    std::vector<int> v = wg.dijkstra(cur_node);

    int j = 0;

    for (int i : v)
    {
        if (i == std::numeric_limits<int>::max())
        {
            ++j;
            continue;
        }

        std::cout << "shortest path from  " << cur_node << "  to  " << j << "  is  " << i;
        ++j;
        std::cout << std::endl;
    }
    std::cout << std::endl;

    //---------------------------_UnweightedGraph_TEST_---------------------------------//
    std::cout << "\nUNWeightedGraph_TEST\n" << "***************************\n" << std::endl;
    Graph g(6);

    g.add_vertex(7);

    g.add_edge(0, 1);
    g.add_edge(0, 4);
    g.add_edge(0, 5);

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

    g.remove_vertex(2);
    std::cout << std::endl;

    g.bfs(0);
    g.print();
    // g.remove_edge(0, 1);


    std::vector<int> i;

    // g.print();

    // std::vector<int> v = g.get_neighbors(1);

    // for (int i : v)
    // {
    //     std::cout << i << " ";
    // }
    // std::cout << std::endl;

    // if (g.has_edge(2, 0))
    // {
    //     std::cout << "YES" << std::endl;
    // }
    // else
    // {
    //     std::cout << "NO" << std::endl;
    // }

    // if (g.has_vertex(8))
    // {
    //     std::cout << "YES" << std::endl;
    // }
    // else
    // {
    //     std::cout << "NO" << std::endl;
    // }

    // std::cout << g.vertex_count() << std::endl;
    // std::cout << g.edge_count() << std::endl;

    // g.bfs(0);
}