#include <iostream>

#include "Graph.h"

int main()
{
    Graph<int> graph ( { { 0, {1, 4} },
                     { 1, {2, 5} },
                     { 2, {3, 4} },
                     { 3, {4, 5} } } );

    graph.traversal_inDepth(2);
    graph.print();

    return 0;
}