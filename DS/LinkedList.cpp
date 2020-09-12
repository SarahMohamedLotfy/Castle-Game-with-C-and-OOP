#include "LinkedList.h"
#include"node.cpp"

template < class T>
LinkedList<T>::LinkedList(void)
{
	head=tail=nullptr;
	
	count=0;
}
template < class T>
void LinkedList<T>::append(T* n)
{
	node<T>*insert=new node<T>(n);
	if(empty())
	{
		
		head=tail=insert;
	}
	else
	{
		tail->setnext(insert);
		tail=insert;
	}
	count++;
}
template < class T>
bool LinkedList<T>::empty()
{
	return(count==0);
}
template < class T>
void LinkedList<T>::deleteval(T* n)
{
	int x=searchval(n);
	node<T>*deleted;
	if(x==0)
	{
		deleted=head;
		head=head->getnext();
		count--;
	}
	else if(x==count-1)
	{
		deleted=tail;
		node<T>* temp=head;
		for(int i=0;i<x-1;i++)
		{
			temp=temp->getnext();
		}
		tail=temp;
		count--;
		tail->setnext(NULL);
		if(count==1)
			head=tail;
	}
	else
	{
		node<T>*temp=head;
		for(int i=0;i<x-1;i++)
		{
			temp=temp->getnext();
		}
		deleted=temp->getnext();
		temp->setnext(deleted->getnext());
		count--;
	}
	if(count==0)
	{
		head=tail=nullptr;
	}
	//delete deleted;
}
template < class T>
int LinkedList<T>::searchval(T* x)
{
	int ind=-1;
	node<T>*h=head;
	for(int i=0;i<count;i++)
	{
		if(h->getvalue()==x)
			return i;
		h=h->getnext();
	}
	return ind;
}
template < class T>
void LinkedList<T>:: MergeSort(node<T>** headRef)
{
node<T>* h = *headRef;
node<T>* a;
node<T>* b;

if ((h == NULL) || (h->getnext() == NULL))
{
    return;
}
 
FrontBackSplit(h, &a, &b); 
 

MergeSort(&a);
MergeSort(&b);

*headRef = SortedMerge(a, b);
}

template < class T>
 void LinkedList<T>:: MergeSort()
{
node<T>* h = head;
node<T>* a;
node<T>* b;
 
/* Base case -- length 0 or 1 */
if ((h == NULL) || (h->getnext() == NULL))
{
    return;
}
 
/* Split head into 'a' and 'b' sublists */
FrontBackSplit(h, &a, &b); 
 
/* Recursively sort the sublists */
MergeSort(&a);
MergeSort(&b);
 
/*  merge the two sorted lists together */
head = SortedMerge(a, b);
}
template < class T>
node<T>* LinkedList<T>:: SortedMerge(node<T>* a, node<T>* b)
{
node<T>* result = NULL;
 
/* Base cases */
if (a == NULL)
    return(b);
else if (b==NULL)
    return(a);
 
/* Pick either a or b, and recur */
if (*(a->getvalue()) >= *(b->getvalue()))
{
    result = a;
    result->setnext( SortedMerge(a->getnext(), b));
}
else
{
    result = b;
    result->setnext (SortedMerge(a, b->getnext()));
}
return(result);
}
 

template < class T>
void LinkedList<T>:: FrontBackSplit(node<T>* source,   node<T>** frontRef, node<T>** backRef)
{
        node<T>* fast;
       node<T>* slow;
    slow = source;
    fast = source->getnext();
 
    /* Advance 'fast' two node<T>s, and advance 'slow' one node<T> */
    while (fast != NULL)
    {
    fast = fast->getnext();
    if (fast != NULL)
    {
        slow = slow->getnext();
        fast = fast->getnext();
    }
    }
 
    /* 'slow' is before the midpoint in the list, so split it in two
    at that point. */
    *frontRef = source;
    *backRef = slow->getnext();
    slow->setnext(NULL);
}

template < class T>
T* LinkedList<T>::getvalue(int i)
{
	int j=2;
	if(i==1)
	{
		return (head->getvalue());
	}
	else if(i==count)
	{
		return (tail->getvalue());
	}
	else if(count==1)
		return (head->getvalue());
	else
	{
		node<T>*p;
		p=head->getnext();
		if(i<count)
		{	
			while ((p->getnext())!=NULL)
			{
				if(j==i)
				{
					return (p->getvalue());
				}
				else
				{
					p=p->getnext();
				}
				j++;
			}
		}
	}
}


template < class T>
void LinkedList<T>::beginref()
{
	ref=head;
}

 template < class T>
void LinkedList<T>::advance()
{
	ref=ref->getnext();
}

template < class T>
T* LinkedList<T>::getref()
{
	return ref->getvalue();
}

template < class T>
void LinkedList<T>::clearlist()
{
	for (int i = 1; i <= count; i++)
	{
		node<T>* n;
		n=head;
		head=head->getnext();
		if(n!=nullptr)
			delete n;
	}
	head=tail=nullptr;
	count=0;
}
template < class T>
LinkedList<T>::~LinkedList(void)
{
	clearlist();
	count=0;
}
