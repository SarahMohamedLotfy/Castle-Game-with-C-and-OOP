#pragma once
#include"../Enemies\Enemy.h"
template<class T>
class node
{
	T*value; // data of the node 
	node<T>*next; // the next pointer of the node
public:
	node(void);
	node(T*);
	void setnext(node<T>*); 
	void setvalue(T*);
	T*getvalue();
	node<T>*getnext();
	~node(void);
};

