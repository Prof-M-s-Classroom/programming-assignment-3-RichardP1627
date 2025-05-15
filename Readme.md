[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
Richard Pak (130109717)

## Description
This program utilizes an adjacency matrix and a minHeap data structure to use Prim's algorithm in finding the minimum spanning
tree (MST) of a graph with multiple vertices and edge weights. Assuming that the vertices of the given graph in main.cpp are 
connected, the program creates an adjecency matrix to hold the edge weights between all the vertices, and uses it to build the 
minHeap, which is a priority queue that keeps track of all the vertices and its edge weights.

## Files
- graph.h / graph.cpp
- heap.h / heap.cpp
- main.cpp (unchanged)
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysis


| Operation            | Time Complexity   |
|----------------------|-------------------|
| Insert in MinHeap    |                   |
| Extract Min          |                   |
| Decrease Key         |                   |
| Prim’s MST Overall   |                   |

_Explain why your MST implementation has the above runtime._

## Test Case Description

Input:  