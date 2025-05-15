#ifndef GRAPH_H
#define GRAPH_H
#include "heap.h"

class Graph {
public:
    Graph(int vertices) {
        numVertices = vertices;
        adjMatrix = new int* [numVertices];
        for (int i = 0; i < numVertices; i++) {
            adjMatrix[i] = new int[numVertices];
            for (int j = 0; j < numVertices; j++) {
                if (i == j) {
                    adjMatrix[i][j] = 0;
                }
                else {
                    adjMatrix[i][j] = INT_MAX; //set to infinity
                }
            }
        }
    }

    ~Graph() {
        for (int i = 0; i < numVertices; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }

    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    }

    /* void printAdjMatrix() {
        for (int u = 0; u < numVertices; u++) {
            for (int v = 0; v < numVertices; v++) {
                std::cout << adjMatrix[u][v] << " ";
            }
        }
    } */
    void primMST() {   // Must print MST edges and total weight
        int parent[numVertices];
        int key[numVertices];
        MinHeap minHeap(numVertices);
        for (int i = 0; i < numVertices; i++) {
            key[i] = INT_MAX;
            parent[i] = -1;
        }
        key[0] = 0;
        for (int i = 0; i < numVertices; i++) {
            minHeap.insert(i, key[i]);
        }

        int iteration = 0;
        while (!minHeap.isEmpty()) {
            int u = minHeap.extractMin();
            for (int v = 0; v < numVertices; v++) {
                if (adjMatrix[u][v] && minHeap.isInMinHeap(v) && adjMatrix[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = adjMatrix[u][v];
                    minHeap.decreaseKey(v, key[v]);
                }
            }
            iteration++;
        }

        std::cout << "Edges: " << std::endl;
        int totalWeight = 0;
        for (int i = 1; i < numVertices; i++) {
            std::cout << parent[i] << " --- " << i << " --> Weight = " << key[i] << std::endl;
            totalWeight += key[i];
        }
        std::cout << "Total MST Weight: " << totalWeight << std::endl;
    }

private:
    int** adjMatrix;
    int numVertices;
};

#endif