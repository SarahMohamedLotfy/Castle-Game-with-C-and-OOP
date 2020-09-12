#include "node.h"

template < class T>
node<T>::node(void)
{
	next=nullptr; // make the next pointer pointed on null
}
template < class T>
node<T>::node(T*n)
{
	next=nullptr;
	value=n;
}
template < class T>
void node<T>::setnext(node<T>* n) 
{
	next=n;
}
template < class T>
void node<T>::setvalue(T* n) // set the data of the node to the value sent to the function
{
	value=n;
}
template < class T>
T*node<T>::getvalue() // get the value of the data of the node 
{
	return value;
}
template < class T>
node<T>*node<T>::getnext() // get the next pointer of the node
{
	return next;
}
template < class T>
node<T>::~node(void)
{
}