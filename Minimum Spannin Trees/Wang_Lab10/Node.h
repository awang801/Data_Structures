/**
*	@file : Node.h
*	@author : Alan Wang
*	@date : 4/15/15
*	Purpose: Node.h is the header file for the Node class
*/

#ifndef NODE_H
#define NODE_H

class Node
{
private:
    int m_value;
    Node* m_left;
    Node* m_right;
    Node* m_parent;
    int v1;
    int v2;
    int e;
public:
    Node();
    /**  @pre none
    *   @post Creates a node, m_value set to val, m_left set to nullptr
    *   @return a Node containing val
    */
    Node(const Node& other);
    /**  @pre a populated tree passed in
    *   @post recursively copies other to a new pointer.
    *   @return a copied version fo the original tree passed in.
    */
    Node* getleft() const;
    /** @pre none
    *   @post none
    *   @return Returns m_next
    */
    Node* getright() const;
    /** @pre none
    *   @post none
    *   @return Returns m_prev
    */
    int getvalue() const;
    /** @pre none
    *   @post none
    *   @return Returns m_value
    */
    void setleft(Node* next);
    /** @pre next is pointing to a valid Node or nullptr
    *   @post m_next points to next
    *   @return none
    */
    void setright(Node* next);
    /** @pre none
    *   @post sets m_value to val
    *   @return none
    */
    void setvalue(int value);
    /** @pre none
    *   @post Sets m_value to val
    *   @return none
    */
    void setvertex(int vertex1, int vertex2);
    void setedge(int edge);
    int getvertex1();
    int getvertex2();
    void setparent(Node* next);
    int getedge();
    Node* getparent();
};

#endif // NODE_H
