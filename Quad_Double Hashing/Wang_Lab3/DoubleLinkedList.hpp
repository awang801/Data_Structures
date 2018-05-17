#include <iostream>
template <typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
m_front = nullptr;
m_size = 0;
m_back = nullptr;
hashSize = 0;
hashArray = new Node<T>*[0];
bool flag = false;
int type = 0;
}

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList(int size)
{
    hashSize = size;
    hashArray = new Node<T>*[hashSize];
    for (int i = 0; i < hashSize; i++)
    {
        hashArray[i] = nullptr;
    }
}

template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
    Node<T>* tempPtr = m_front;
	while(tempPtr != nullptr)
	{
        m_front = m_front->getnext();
		delete tempPtr;
		tempPtr = m_front;
	}
}
template <typename T>
bool DoubleLinkedList<T>::isempty() const
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
int DoubleLinkedList<T>::size()const
{
    return (m_size);
}
//add to front function.

template <typename T>
bool DoubleLinkedList<T>::insert(T value)
{
    int i = 0;
    int tempKey = hash(value, i);
    int hashFull = 0;
    int found = find(value);
    Node<T>* n = new Node<T>();
    n->setvalue(value);

    for (int i = 0; i <hashSize; i++)
    {
        if(hashArray[i] == nullptr)
        {
            hashFull ++;
        }
        else
        {
            if(hashArray[i]->getValue() == -1)
            {
                hashFull ++;
            }
        }
    }
    if(hashFull != 0)
    {
        if(found == -1)
        {
            tempKey = hash(tempKey, i);
            hashArray[tempKey] = n;
            return(true);
        }
        else
        {
            return(false);
        }
    }
    else
    {
        return(false);
    }
}
//print list function
template<typename T>
void DoubleLinkedList<T>::print()const
{
    for (int i = 0; i < hashSize; i++) {
        std::cout << i << ": ";
        Node<T>* currPtr = hashArray[i];
        while (currPtr != NULL) {
            if(currPtr->getflag())
            {
                std::cout << currPtr->getValue() << " " << "flag = true";
            }
            else
            {
                std::cout << currPtr->getValue() << " " << "flag = false";
            }
            currPtr = currPtr->getnext();
        }
        std::cout << std::endl;
    }
}
template<typename T>
int DoubleLinkedList<T>::find(T value)
{
    for(int i = 0; i<hashSize; i++)
    {
        if(hashArray[i] == nullptr)
        {
            return(-1);
        }
        else
        {
            if(hashArray[i]->getValue() == value)
            {
                return(i);
            }
        }
    }
    return(-1);
}

template<typename T>
bool DoubleLinkedList<T>::deletenode(T value)
{
    int tempKey = find(value);
    if (tempKey== -1)
    {
        return(false);
    }
    else
    {
        hashArray[tempKey]->setvalue(-1);
        hashArray[tempKey]->setflag(true);
        return(true);
    }

}

template<typename T>
int DoubleLinkedList<T>::hash(T value, int i)
{
    int fi = value%hashSize;
    int tempkey = value%hashSize;
    if(type == 1)
    {

        while(contains(tempkey))
        {
            tempkey = (fi + (i*i))%hashSize;
            i++;
        }
        return tempkey;
    }
    if (type == 2)
    {
        int fi = value%hashSize;
        int hx = 5-(value%5);
        while(contains(tempkey))
        {
            if(i==0)
            {
                return(fi);
            }
            else if (i == 1)
            {
                return hx;
            }
            else
            {

                tempkey = (((i-1)*hx) + fi) %hashSize;
            }
        }
        return tempkey;
    }
}

template<typename T>
void DoubleLinkedList<T>::setHashType(int hType)
{
    type = hType;
}

template<typename T>
bool DoubleLinkedList<T>::contains(int key)
{
    if(hashArray[key] == nullptr)
    {
        return(false);
    }
    else
    {
        if(hashArray[key]->getValue() == -1)
        {
            return (false);
        }
        else
        {
            return(true);
        }
    }
}
