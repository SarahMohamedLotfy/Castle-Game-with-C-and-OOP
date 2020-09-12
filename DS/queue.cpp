#include "queue.h"
#include"../Enemies\Enemy.h"


#include<iostream>
template < class T>
queue<T>::queue(void)
{
	back=NULL; 
	front =NULL;
	count =0;
}
template < class T>
void queue<T>::enqueue(T*ele) // add an element to the queue list
{
	node<T>*p=new node<T>; // make a node 
	p->setvalue(ele); //make the data of the node equal to the value of the element 
	p->setnext(NULL); // make the next pointer of the node points to null
	if((front == NULL)&&(back == NULL)) // if the queue list is empty
	{
		front=p; // make the front pointer points to the newnode
		back=p; // make the back pointer points to the newnode
	}
	else
	{
		back->setnext(p); // make the next  pointer of last node  points to the newnode
		back=p; // make the back pointer points to the newnode
	}
	count++;
}
template < class T>
T* queue<T>::dequeue() // delete a node from the queue list
{
	node<T>*p; 
	T*q;
	if(front != back)
	{
		p=front;
		front=front->getnext();
		count--;
	}
	else if((front == NULL)&&(back == NULL))
	{
		return NULL;
	}
	else
	{
		p=front;
		front=NULL;
		back=NULL;
		count--;
	}
	q=p->getvalue();
	delete p;
	return q;
}
template < class T>
void queue<T>::clearlist()
{
	for (int i = 1; i <= count; i++)
	{
		node<T>* n;
		n=front;
		front=front->getnext();
		if(n!=nullptr)
			delete n;
	}
	front=back=nullptr;
	count=0;
}
template < class T>
T* queue<T>:: getfront() // return the value of the first element of the queue list
{
	if(front==NULL) 
	{
		return NULL;
	}
	else
	{
		return front->getvalue();

	}
}
template < class T>
queue<T>::~queue(void)
{
}
