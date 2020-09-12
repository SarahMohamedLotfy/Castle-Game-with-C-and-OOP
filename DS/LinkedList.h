#pragma once
#include"node.h"
template<class T>
class LinkedList
{
	 node<T>*head; // pointer to the first element  of the list
	node<T>	*tail;// pointr to the last element of the list
	node<T>*ref;
	int count;
	void FrontBackSplit(node<T>* source, node<T>** frontRef, node<T>** backRef);
	node<T>* SortedMerge(node<T>* a , node<T>* b);

public:
	LinkedList(void);
	bool empty();
	void append(T * val);
	void deleteval(T*);
	int searchval(T*);
	T*getvalue(int);
	void clearlist();
	
	
	void MergeSort(node<T>** headRef);
	void MergeSort();
	void beginref();
	T* getref();
	void advance();
	~LinkedList(void);
};
