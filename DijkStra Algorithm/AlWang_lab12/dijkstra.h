#ifndef DIJKSTRA
#define DIJKSTRA

#include <iostream>
class Dijkstra
{
  public:
    Dijkstra(int numVertex, int** matrix);
    int* Calculate();
  private:
    int vertices;
    int** graph;
};


#endif
