#include <iostream>
template <typename T>
Node<T>::Node()
{
    m_prev = nullptr;
    m_next = nullptr;
    m_value = T();
    m_flag = false;
}
template <typename T>
T Node<T>::getValue() const
{
	return(m_value);
}
template <typename T>
void Node<T>::setvalue(T val)
{
	m_value = val;
}
template<typename T>
void Node<T>::setprev(Node<T>* next)
{
        m_prev=next;
}
template <typename T>
Node<T>* Node<T>::getnext() const
{
	return(m_next);
}
template <typename T>
Node<T>* Node<T>::getprev() const
{
	return(m_prev);
}
template <typename T>
void Node<T>::setnext(Node<T>* next)
{
	m_next = next;
}
template<typename T>
void Node<T>::setflag(bool flag)
{
    m_flag = flag;
}
template<typename T>
bool Node<T>::getflag()
{
    return(m_flag);
}
