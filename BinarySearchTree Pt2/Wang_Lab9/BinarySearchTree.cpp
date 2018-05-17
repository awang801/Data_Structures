#include "BinarySearchTree.h"
#include <cmath>
#include <iostream>

BinarySearchTree::BinarySearchTree()
{
    queue = new Node* [10];

    for (int index=0; index < 10; index++)
    {
        queue[index] = NULL;
    }
}
BinarySearchTree::~BinarySearchTree()
{
    delete [] queue;
}


void BinarySearchTree::insert(int value)
{
    //std::cout << "test1\n";
    Node** tempQueue = new Node* [10];
    tempQueue[0] = new Node(value, 0, NULL, NULL, NULL);
    for (int index=1; index < 10; index++)
    {
        tempQueue[index] = NULL;
    }
    queue = merge(queue, tempQueue);
  //  std::cout << "testlast\n";
}

BinarySearchTree::Node** BinarySearchTree::merge(Node** queueOrig, Node** queueTemp)
{
  //std::cout << "test2\n";

    Node** q1 = new Node* [10];
    Node** q2 = new Node* [10];
    for (int index=1; index < 10; index++)
    {
        q1[index] = NULL;
        q2[index] = NULL;
    }
    //std::cout << "test3\n";

    for (int index=0; index < 10; index++)
    {

        Node* newRoot = mergehelper(queueOrig[index], queueTemp[index]);

        if (newRoot == NULL)
        {
            continue;
        }
        else if (newRoot->order == index)
        {
            if (q1[index] == NULL)
                q1[index] = newRoot;
            else
                q2[index] = newRoot;
        }
        else if (index+1 < 10)
        {
            if (q1[index+1] == NULL)
                q1[index+1] = newRoot;
            else
                q2[index+1] = newRoot;
        }
    }

    bool carryEmpty = true;
    for (int index=0; index<10; index++)
    {
        if (q2[index] != NULL)
        {
            carryEmpty = false;
            break;
        }
    }
    //std::cout << "test5\n";
    if (!carryEmpty)
        q1 = merge(q1, q2);
      //  std::cout << "test4\n";

    return q1;



}

BinarySearchTree::Node* BinarySearchTree::mergehelper(Node* root1, Node* root2)
{
    if (root2 == NULL)
    {
        return root1;
    }
    if (root1 == NULL)
    {
        return root2;
    }


    if (root1->key > root2->key)
    {
        swap(root1, root2);
    }

    root1->order += 1;


    if (root1->Child == NULL)
    {
        root1->Child = root2;
        return root1;
    }


    Node* lastChild = root1->Child;
    while (lastChild->rightSibling != NULL)
    {
        lastChild = lastChild->rightSibling;
    }

    lastChild->rightSibling = root2;

    return root1;
}


void BinarySearchTree::swap(Node* &node1, Node* &node2)
{
    Node *temp = node1;
    node1 = node2;
    node2 = temp;

    return;
}

void BinarySearchTree::deletemin()
{
    int min = -1;
    for (int index = 0; index < 10; index++)
    {
        if (queue[index] != NULL)
        {
            if (min == -1 || queue[index]->key < queue[min]->key)
            {
                min = index;
            }
        }
    }

    if (min == -1)
    {
      return;
    }


    if (min == 0)
    {
        Node* temp = queue[min];
        queue[min] = NULL;
        delete temp;
    }


    Node* tempRoot = queue[min];
    Node* child = tempRoot->Child;
    queue[min] = NULL;


    Node** tempQueue = new Node* [10];
    for (int index=0; index < 10; index++)
    {
        if (index >= min)
        {
            tempQueue[index] = NULL;
        }
        else
        {
            tempQueue[index] = child;
            child = child->rightSibling;
            tempQueue[index]->rightSibling = NULL;
        }
    }

    delete tempRoot;
    queue = merge(queue, tempQueue);
}

void BinarySearchTree::levelorder()
{
    for (int order=0; order<10; order++)
    {
        Node* node = queue[order];
        if (node != NULL)
        {
            cout << "---\n";


            levelorderHelper(node);
        }
    }
}

void BinarySearchTree::levelorderHelper(Node* root)
{
    Queue* current = new Queue(NULL, root);
    Queue* next = NULL;

    while (current != NULL)
    {
        Node* node = current->node;

        while (node != NULL)
        {
            cout << node->key << " ";

            if (node->Child != NULL)
            {
                if (next == NULL)
                {
                    next = new Queue(NULL, node->Child);
                }
                else
                {
                }
            }

            node = node->rightSibling;
        }

        if (current->next != NULL)
        {
            Queue* temp = current;
            current = current->next;
            delete temp;
        }
        else
        {
            current = next;
            next = NULL;
            cout << endl;
        }
    }


    return;
}
