#include "minSpanTree.h"
#include "Node.h"
#include "disjoint.h"
#include "BinarySearchTree.h"
#include <iostream>


minSpanTree::minSpanTree(int**  matrixData , Node** e, Node ** solution, int s)
{
    matrix = matrixData;
    size = s;
    edgeArray = e;
    solutionArray = solution;
}

minSpanTree::~minSpanTree()
{
}


void minSpanTree::prim()
{
    std::cout << "Prim: \n";
    BinarySearchTree skew;
    int vertexes[size];
    int min = 0;

    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j] < matrix[i][min])
            {
                min = j;
            }

            vertexes[j] = 0;
        }
    }

    skew.insert(0, min, matrix[0][min]);


    matrix[min][0] = 0;
    matrix[0][min] = 0;


    Node * temp;
    int i = 0;
    int v1 = 0;
    int v2 = 0;

    while (i < size && skew.m_root != nullptr)
    {
        temp = skew.deletemin();
        v1 = temp->getvertex1();
        v2 = temp->getvertex2();

        if (vertexes[v1] != 1 || vertexes[v2] != 1)
        {
            vertexes[v1] = 1;
            vertexes[v2] = 1;
            solutionArray[i] = temp;
            i++;
            if(temp->getvertex1() !=0 || temp->getvertex2() != 0)
            {
              if(temp->getvertex1() < temp->getvertex2())
              {
                std::cout << "("
                          << temp->getvertex1()
                          << " , "
                          << temp->getvertex2()
                          << ")";
              }
              else
              {
                std::cout << "("
                          << temp->getvertex2()
                          << " , "
                          << temp->getvertex1()
                          << ")";
              }
            }
            for (int i = 0; i < size; i++)
            {
                if (matrix[v1][i] != 0)
                {
                    skew.insert(v1, i, matrix[v1][i]);
                    matrix[v1][i] = 0;
                    matrix[i][v1] = 0;
                }
                if (matrix[v2][i] != 0)
                {
                    skew.insert(v2, i, matrix[v2][i]);
                    matrix[v2][i] = 0;
                    matrix[i][v2] = 0;
                }
            }
        }

    }
    std::cout << "\n";
    skew.~BinarySearchTree();
}

void minSpanTree::kruskal()
{
    std::cout << "Kruskal:\n";
    BinarySearchTree skew;
    disjoint d(size);

    int numedges = 0;
    int insert = 0;

    for (int k = 0; k < size; k++)
    {
        for (int l = 0; l < size; l++)
        {
            if (matrix[k][l] != 0)
            {
                insert = matrix[k][l];
                skew.insert(k, l, insert);

                Node * temp = new Node();
                temp -> setedge(insert);
                temp -> setvertex(k, l);
                edgeArray[numedges] = temp;

                numedges++;
            }

        }
    }

    Node * temp;
    int i = 0;

    while (i < size && skew.m_root != nullptr)
    {
        temp = skew.deletemin();

        if (d.findSetParent(temp->getvertex1()) != d.findSetParent(temp->getvertex2()))
        {
            d.merge(temp->getvertex1(), temp->getvertex2());
            solutionArray[i] = temp;
            i++;
            if(temp->getvertex1() !=0 || temp->getvertex2() != 0)
            {
              if(temp->getvertex1() < temp->getvertex2())
              {
                std::cout << "("
                          << temp->getvertex1()
                          << " , "
                          << temp->getvertex2()
                          << ")";
              }
              else
              {
                std::cout << "("
                          << temp->getvertex2()
                          << " , "
                          << temp->getvertex1()
                          << ")";
              }
            }
        }

    }
    std::cout << "\n";
    skew.~BinarySearchTree();


}
