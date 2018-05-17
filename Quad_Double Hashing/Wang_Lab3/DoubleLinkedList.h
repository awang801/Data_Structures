#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include "Node.h"
#include <stdexcept>

template<typename T>
class DoubleLinkedList
{
private:
Node<T>* m_front;
Node<T>* m_back;
int m_size;
int hashSize;
Node<T>** hashArray;
bool flag;
int type;

public:
DoubleLinkedList();
/**  @pre none
*   @post Creates an empty list
*   @return Returns an empty list
*/

DoubleLinkedList(int  size);

~DoubleLinkedList();
/**  @pre none
*   @post Deallocates all nodes in the list
*   @return none
*/
bool isempty() const;
/**  @pre none
*   @post none
*   @return Returns true if list is empty, false otherwise
*/
int size() const;
/**  @pre none
*   @post none
*   @return Returns the size
*/
bool insert(T value);
/**  @pre none
*   @post The val is added to the end of the list
*   @return none
*/
bool deletenode(T value);
/**  @pre none
*   @post the value is removed from the list
*   @return Returns true if the value was removed, false otherwise.
*/
int find(T value);
/**  @pre none
*   @post none
*   @return Returns true if there at least one occurence of val in the list, false otherwise
*/
void print() const;
/**  @pre none
*   @post The values in the list are printed.
*   @return none
*/

int hash(T value, int i);
/**  @pre populated list
*   @post none
*   @return index for the key
*/

bool contains(int key);

void setHashType(int hType);


};
#include "DoubleLinkedList.hpp"
#endif //DOUBLELINKEDLIST.H

