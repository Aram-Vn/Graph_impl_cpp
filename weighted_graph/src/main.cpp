#include "weighted_graph.h"
#include <iostream>
#include <vector>

int main()
{
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
}