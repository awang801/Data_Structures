#include "BinarySearchTree.h"
#include <iostream>
#include <fstream>
#include "dijkstra.h"


Dijkstra::Dijkstra(int numVertex, int** matrix)
{
  vertices = numVertex;
  graph = matrix;
}

int* Dijkstra::Calculate()
{
  BinarySearchTree m1(vertices);
  bool* treeVertices = new bool[vertices];
  int* weight = new int[vertices];

  for(int i = 0; i < vertices; i++)
      treeVertices[i] = false;


  for(int i = 1; i <= vertices; i++)
  {
      Node temp = m1.deleteMin();
      int treeVertex = temp.getVertexNum();

      treeVertices[treeVertex] = true;
      for(int j = 0; j < vertices; j++)
      {
          if(graph[treeVertex][j] && (!treeVertices[j]))
          {
              m1.decreaseKey(j, temp.getDistFromTree() +
                             graph[treeVertex][j], temp.getVertexNum());
          }
      }

      weight[treeVertex] = temp.getDistFromTree();
  }
  return weight;
}
