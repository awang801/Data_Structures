#include "Node.h"

#ifndef DISJOINT_H
#define DISJOINT_H

class disjoint
{
private:
  int m_size;

 public:
   disjoint(int size);
   void merge(int v1, int v2);

   int findSetParent(int v);
   int findHelper(Node* v);

   Node ** set;

};

#endif
