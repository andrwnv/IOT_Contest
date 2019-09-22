#include <iostream>

#include "Graph.h"

int main()
{
    Graph<int> graph ( { { 0, {1, 4} },
                     { 1, {2, 5} },
                     { 2, {3, 4} },
                     { 3, {4, 5} } } );

    graph.traversal_in_depth(2);
    std::cout << std::endl << std::endl;
    graph.traversal_in_breadth(0);

    return 0;
}