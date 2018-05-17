#ifndef NODE_H
#define NODE_H
template<typename T>
class Node
{
private:
    T m_value;
    Node<T>* m_prev;
    Node<T>* m_next;
    bool m_flag;
public:
    Node();
    /**  @pre none
    *   @post Creates a node, m_value set to val, m_next set to nullptr
    *   @return a Node containing val
    */
    Node<T>* getnext() const;
    /** @pre none
    *   @post none
    *   @return Returns m_next
    */
    Node<T>* getprev() const;
    /** @pre none
    *   @post none
    *   @return Returns m_prev
    */
    T getValue() const;
    /** @pre none
    *   @post none
    *   @return Returns m_value
    */
    void setnext(Node<T>* next);
    /** @pre next is pointing to a valid Node or nullptr
    *   @post m_next points to next
    *   @return none
    */
    void setprev(Node<T>* next);
    /** @pre none
    *   @post sets m_value to val
    *   @return none
    */
    void setvalue(T value);
    /** @pre none
    *   @post Sets m_value to val
    *   @return none
    */
    void setflag(bool flag);

    bool getflag();

};
#include "Node.hpp"
#endif // NODE_H
