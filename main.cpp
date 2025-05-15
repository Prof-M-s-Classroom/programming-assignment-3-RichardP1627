#include <iostream>
#include "graph.h"

int main() {
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    /* Test case with 10 vertices and various edges that could create different and valid MST's
    Graph g(10);
    g.addEdge(0, 1, 3);
    g.addEdge(0, 2, 4);
    g.addEdge(0, 3, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 3, 6);
    g.addEdge(2, 5, 3);
    g.addEdge(3, 4, 5);
    g.addEdge(3, 5, 2);
    g.addEdge(3, 6, 1);
    g.addEdge(3, 7, 3);
    g.addEdge(4, 7, 3);
    g.addEdge(5, 6, 4);
    g.addEdge(5, 8, 2);
    g.addEdge(6, 7, 2);
    g.addEdge(6, 8, 1);
    g.addEdge(6, 9, 5);
    g.addEdge(7, 9, 4);
    g.addEdge(8, 9, 7);
    */
    //g.printAdjMatrix();
    g.primMST();

    return 0;
}