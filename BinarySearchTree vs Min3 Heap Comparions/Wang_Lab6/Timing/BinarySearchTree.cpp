#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
    m_root = nullptr;
    size = 0;
}

BinarySearchTree::~BinarySearchTree()
{
    while(size != 0)
    {
        deletemin();
    }
}

Node* BinarySearchTree::search(int num, Node* subtree)
{
    if (subtree == nullptr)
    {
        return (subtree);
    }
    else if (subtree -> getvalue() == num)
    {
        return (subtree);
    }
    else if (subtree -> getvalue() > num)
    {
        search(num, subtree -> getleft());
    }
    else if (subtree -> getvalue() < num)
    {
        search(num, subtree -> getright());
    }
}

void BinarySearchTree::insert(int num)
{
    if (m_root == nullptr)
    {
        m_root = new Node();
        m_root -> setvalue(num);
        size++;
    }
    else
    {
        insertHelper(num, m_root);
    }
}

void BinarySearchTree::insertHelper(int num, Node *subtree)
{
  if (subtree -> getvalue() > num)
    {
        if (subtree -> getleft() == nullptr)
        {
            Node* temp = nullptr;
            temp = new Node();
            temp -> setvalue(num);
            subtree -> setleft(temp);
            size++;
        }
        else
        {
            Node* temp = nullptr;
            temp = subtree;
            temp = temp -> getleft();
            insertHelper(num, temp);
        }
    }
    else if (subtree -> getvalue() <= num)
    {
        if (subtree -> getright() == nullptr)
        {
            Node* temp = nullptr;
            temp = new Node();
            temp -> setvalue(num);
            subtree -> setright(temp);
            size++;
        }
        else
        {
            Node* temp = nullptr;
            temp = subtree;
            temp = temp -> getright();
            insertHelper(num, temp);
        }
    }
}

void BinarySearchTree::remove(int num)
{
    if (m_root == nullptr)
    {
        //std::cout << "Nothing to delete";
    }
    else if (search(num, m_root) == nullptr)
    {
        //std::cout << num << " is not in the tree";
    }
    else
    {
        while(search(num, m_root) != nullptr)
        {
            removeHelper(num, m_root, nullptr);
        }
    }
}

void BinarySearchTree::removeHelper(int num, Node *subtree, Node* parent)
{
    if (subtree -> getvalue() == num)
    {
        if (subtree -> getright() == nullptr && subtree -> getleft() == nullptr)
        {
            if(parent -> getright() == subtree)
            {
                parent -> setright(nullptr);
            }
            else
            {
                parent -> setleft(nullptr);
            }

            delete subtree;
            subtree = nullptr;
            size--;
        }
        else if (subtree -> getleft() == nullptr)
        {
            Node* temp = nullptr;
            temp = subtree;
            subtree = subtree -> getright();
            if (parent != nullptr)
            {
                if (parent -> getleft() == temp)
                {
                    parent -> setleft(subtree);
                }
                else
                {
                    parent -> setright(subtree);
                }
            }
            delete temp;
            temp = nullptr;
            size--;
        }
        else if (subtree -> getright() == nullptr)
        {
            Node* temp = nullptr;
            temp = subtree;
            subtree = subtree -> getleft();
            if (parent != nullptr)
            {
                if (parent -> getleft() == temp)
                {
                    parent -> setleft(subtree);
                }
                else
                {
                    parent -> setright(subtree);
                }

            }
            delete temp;
            temp = nullptr;
            size--;
        }
        else
        {
            Node* temp = nullptr;
            temp = subtree -> getright();
            while (temp -> getleft() != nullptr)
            {
                temp = temp -> getleft();
            }
            int change = temp -> getvalue();

            if (temp -> getright() != nullptr)
            {
                if (subtree -> getright() == temp)
                {
                    subtree -> setright(temp -> getright());
                    delete temp;
                    temp = nullptr;
                }
                else
                {
                    Node* temp2 = nullptr;
                    temp2 = subtree -> getright();
                    while (temp2 -> getleft() != temp)
                    {
                        temp2 = temp2 -> getleft();
                    }
                    temp2 -> setleft(temp -> getright());
                    delete temp;
                    temp = nullptr;
                }

                subtree -> setvalue(change);
                size--;
            }
            else
            {
                Node* temp2 = nullptr;
                temp2 = subtree -> getright();
                while (temp2 -> getleft() != temp)
                {
                    temp2 = temp2 -> getleft();
                }
                temp2 -> setleft(nullptr);
                delete temp;
                temp = nullptr;
                subtree -> setvalue(change);
                size--;
            }
        }
    }
    else if (subtree -> getvalue() > num)
    {
        removeHelper(num, subtree -> getleft(), subtree);
    }
    else if (subtree -> getvalue() < num)
    {
        removeHelper(num, subtree -> getright(), subtree);
    }
}



void BinarySearchTree::deletemin()
{
    if (m_root == nullptr)
    {
        return;
    }
    else if (m_root -> getleft() == nullptr && m_root -> getright() == nullptr)
    {
       delete m_root;
       m_root = nullptr;
       size--;
    }
    else if (m_root -> getleft() == nullptr)
    {
        Node* temp = nullptr;
        temp = m_root;
        m_root = m_root -> getright();
        delete temp;
        temp = nullptr;
        size--;
    }
    else
    {
        Node* temp = nullptr;
        temp = m_root;
        while (temp -> getleft() != nullptr)
        {
            temp = temp -> getleft();
        }
        if (m_root -> getleft() == temp)
        {
            if (temp -> getright() != nullptr)
            {
                m_root -> setleft(temp -> getright());
            }
            else
            {
                m_root -> setleft(nullptr);
            }
            delete temp;
            temp = nullptr;
            size--;
        }
        else if (temp -> getright() != nullptr)
        {
            Node* temp2 = nullptr;
            temp2 = m_root;
            while (temp2 -> getleft() != temp)
            {
                temp2 = temp2 -> getleft();
            }
            temp2 -> setleft(temp -> getright());
            delete temp;
            temp = nullptr;
            size--;
        }
        else
        {
            Node* temp2 = nullptr;
            temp2 = m_root;
            while (temp2 -> getleft() != temp)
            {
                temp2 = temp2 -> getleft();
            }
            temp2 -> setleft(nullptr);
            delete temp;
            temp = nullptr;
            size--;
        }
    }
}

void BinarySearchTree::deletemax()
{
    if (m_root == nullptr)
    {
        return;
    }
    else if (m_root -> getright() == nullptr && m_root -> getleft() == nullptr)
    {
        delete m_root;
        m_root = nullptr;
        size--;
    }
    else if(m_root ->getright() == nullptr)
    {
        Node* temp = nullptr;
        temp = m_root;
        m_root = m_root ->getleft();
        delete temp;
        temp = nullptr;
        size--;
    }
    else
    {
        Node* temp = nullptr;
        temp = m_root;
        while(temp -> getright() != nullptr)
        {
            temp = temp -> getright();
        }
        if (m_root -> getleft() == temp)
        {
            if (temp -> getleft() != nullptr)
            {
                m_root -> setright(temp -> getleft());
            }
            else
            {
                m_root ->setright(nullptr);
            }
            delete temp;
            temp = nullptr;
            size--;
        }
        else if (temp -> getleft() != nullptr)
        {
            Node* temp2 = nullptr;
            temp2 = m_root;
            while (temp2 -> getright() != temp)
            {
                temp2 = temp2 -> getright();
            }
            temp2 -> setright(temp -> getleft());
            delete temp;
            temp = nullptr;
            size--;
        }
        else
        {
            Node* temp2 = nullptr;
            temp2 = m_root;
            while (temp2 -> getright() != temp)
            {
                temp2 = temp2 -> getright();
            }
            temp2 -> setright(nullptr);
            delete temp;
            temp = nullptr;
            size--;
        }
    }
}

void BinarySearchTree::inorder(Node* subtree)
{
    if (subtree != nullptr)
    {
        inorder(subtree -> getleft());
        std::cout << subtree -> getvalue() << " ";
        inorder(subtree -> getright());
    }
}


void BinarySearchTree::preorder(Node *subtree)
{
    if (subtree != nullptr)
    {
        std::cout << subtree -> getvalue() << " ";
        preorder(subtree -> getleft());
        preorder(subtree -> getright());
    }
}



void BinarySearchTree::levelorder(Node *subtree)
{
    if (m_root == nullptr)
    {
        return;
    }
    else
    {
        Node* tempArray[size];
        for(int i = 0; i < size; i++)
        {
            tempArray[i] = nullptr;
        }
        int place = 0;
        int insert = 1;
        tempArray[place] = subtree;
        bool e = true;
        while (e)
        {
            Node* temp = nullptr;
            temp = tempArray[place];
            std::cout << temp -> getvalue() << " ";
            place++;
            if(temp -> getleft() != nullptr)
            {
                tempArray[insert] = temp -> getleft();
                insert++;
            }
            if(temp -> getright() != nullptr)
            {
                tempArray[insert] = temp -> getright();
                insert++;
            }
            if(place == size)
            {
                e = false;
            }
            else if (tempArray[place] == nullptr)
            {
                e = false;
            }


        }
    }

}
