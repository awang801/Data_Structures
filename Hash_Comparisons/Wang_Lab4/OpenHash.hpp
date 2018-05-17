#include <iostream>
template <typename T>
OpenHash<T>::OpenHash()
{
m_front = nullptr;
m_size = 0;
m_back = nullptr;
hashSize = 0;
hashArray = new Node<T>*[0];
}

template<typename T>
OpenHash<T>::OpenHash(long size)
{
    hashSize = size;
    hashArray = new Node<T>*[hashSize];
    for (long i = 0; i < hashSize; i++)
    {
        hashArray[i] = nullptr;
    }
}

template<typename T>
OpenHash<T>::~OpenHash()
{
    delete hashArray;
}
template <typename T>
bool OpenHash<T>::isempty() const
{
    if(m_size==0)
    {
        return(true);
    }
    else
    {
        return(false);
    }
}
template <typename T>
long OpenHash<T>::size()const
{
    return (m_size);
}
//add to front function.

template <typename T>
void OpenHash<T>::insert(T value)
{
    Node<T>* n = new Node<T>();
    n->setvalue(value);

    if(find(value) == nullptr)
    {
        long tempKey = hash(value);
        //list is empty conditional
        if(hashArray[tempKey] == nullptr)
        {

            hashArray[tempKey] = n;
        }

        //list is not empty
        else
        {
            Node<T>* secondNode= new Node<T>();
            secondNode = hashArray[tempKey];
            hashArray[tempKey] = n;
            hashArray[tempKey]->setnext(secondNode);
            secondNode->setprev(hashArray[tempKey]);
        }

        m_size++;
    }
    else
    {

    }
}
//prlong list function
template<typename T>
void OpenHash<T>::print()const
{
    for (long i = 0; i < hashSize; i++) {
        std::cout << i << ": ";
        Node<T>* currPtr = hashArray[i];
        while (currPtr != NULL) {
            std::cout << currPtr->getValue() << " ";
            currPtr = currPtr->getnext();
        }
        std::cout << std::endl;
    }
}
template<typename T>
Node<T>* OpenHash<T>::find(T value)
{
    long tempKey = hash(value);
    Node<T>* temp = hashArray[tempKey];

    while(temp != nullptr)
    {
        if(temp->getValue() == value)
        {
            return(temp);
        }
        temp = temp->getnext();
    }
return(nullptr);
}
template<typename T>
bool OpenHash<T>::deletenode(T value)
{
    Node<T>* temp = find(value);
    if (temp== nullptr)
    {
        return(false);
    }
    else
    {
        long tempKey = hash(value);

        //only one in key
        if(temp->getnext() == nullptr && temp->getprev() == nullptr)
        {
            hashArray[tempKey] = nullptr;
        }

        //last in key
        else if (temp->getnext() == nullptr)
        {
            Node<T>* tempPrev = temp->getprev();
            tempPrev->setnext(nullptr);
            delete temp;
        }

        //first in key
        else if (temp->getprev() == nullptr)
        {
            hashArray[tempKey] = temp->getnext();
            delete temp;
        }

        //everything else
        else
        {
            Node<T>* tempPrev = temp->getprev();
            Node<T>* tempNext = temp->getnext();
            tempNext->setprev(tempPrev);
            tempPrev->setnext(tempNext);
            delete temp;
        }
        return(true);
    }

}

template<typename T>
long OpenHash<T>::hash(T value)
{
    return(value%hashSize);
}


