#pragma once
#include"node.h"
template<class T>
class queue
{
	node<T>*back; // pointer to the last element of the queue list
	node<T>*front;  // pointer to the first element of the queue list
	int count;
public:
	queue(void);
	void enqueue(T*);
	T* dequeue();
	T* getfront();
	void clearlist();
	~queue(void);
};

