[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
Richard Pak (130109717)

## Description
This program utilizes an adjacency matrix and a minHeap data structure to use Prim's algorithm in finding the minimum spanning
tree (MST) of a graph with multiple vertices and edge weights. Assuming that the vertices of the given graph in main.cpp are 
connected, the program creates an adjacency matrix to hold the edge weights between all the vertices, and uses it to build the 
minHeap, which is a priority queue that keeps track of all the vertices and its edge weights. The minHeap helps retrieve the next vertex 
that connects to our tree with the lowest edge weight.

## Files
- graph.h / graph.cpp
- heap.h / heap.cpp
- main.cpp (unchanged)
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysis


| Operation            | Time Complexity |
|----------------------|-----------------|
| Insert in MinHeap    | O(logn)         |
| Extract Min          | O(logn)         |
| Decrease Key         | O(logn)         |
| Prim’s MST Overall   | O(ElogV)        |

_Explain why your MST implementation has the above runtime._
- Insert in MinHeap (O(logn)): Since there contains a while loop that divides the temp/size variable by half every time the while loop is entered. This make it so that n is the height of the binary heap.
- Extract Min (O(logn)): The function runs at O(1) until it calls the function minHeapify(), which runs at O(logn) due to how it recursively calls itself onto its binary heap. 
- Decrease Key (O(logn)): Similar to the function "Insert in Minheap", this function runs at O(1) until it reaches it's while loop which can iterate as many times as the height of the binary heap.
- Prim's MST Overall (O(ElogV)): The E represents the number of edges in the graph while the V represents the number of vertices in the graph. The E comes from the adjacency matrix as it holds all the edge
                                values of the graph and thus would have a time complexity of O(E) to retrieve a specific vertex with the lowest weighted edge. The logV comes from the minHeap which has a time
                                complexity of O(logn) where n is the height of the tree. In the case of Prim's algorithm, the height of the tree will be the number of vertices in the graph, so the final time complexity
                                of the heap is O(logV). Since the adjacency matrix and heap are different classes, their time complexity multiply together to get the final time complexity of Prim's algorithm, which give us O(ElogV).
                                 

## Test Case Description
Assuming that the given graph is already connected, tested a test case with 10 vertices that have various edges that could be used to create different and valid MST's
Input:  
0 --- 1 (3)
0 --- 2 (4)
0 --- 3 (1)
1 --- 3 (2)
1 --- 4 (5)
2 --- 3 (6)
2 --- 5 (3)
3 --- 4 (5)
3 --- 5 (2)
3 --- 6 (1)
3 --- 7 (3)
4 --- 7 (3)
5 --- 6 (4)
5 --- 8 (2)
6 --- 7 (2)
6 --- 8 (1)
6 --- 9 (5)
7 --- 9 (4)
8 --- 9 (7)

Final MST Edges:
3 --- 1 (2)
5 --- 2 (3)
0 --- 3 (1)
7 --- 4 (3)
3 --- 5 (2)
3 --- 6 (1)
6 --- 7 (2)
6 --- 8 (1)
7 --- 9 (4)
Total MST weight = 19

## Overcome Challenge
My final MST was giving me an incorrect total weight, so I made a function to output my adjacency matrix.
Realized I forgot to set the weight for BOTH variations of how the vertices can be chosen. Therefore, I
implemented the fix in the function "addEdge" by making sure to set the weight for both adjMatrix[u][v] and 
adjMatrix[v][u].