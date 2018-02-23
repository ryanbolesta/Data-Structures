//cLinkedList.cpp

#include <assert.h>
#include <iostream>
#include "CLinkedList.h"
using namespace std;

// Construct empty LinkedList
template <typename eltType> CLinkedList<eltType>::CLinkedList() : last(NULL)
{}

// Copy constructor. copy() does the deep copy
template <typename eltType> CLinkedList<eltType>::CLinkedList
                                                (CLinkedList<eltType> &cl)
{last = copy( cl.last );}

template <typename eltType> CLinkedList<eltType>::~CLinkedList()
{destroy(last);}

// Assignment operator: copy() does the deep copy
template <typename eltType> CLinkedList<eltType>
	&CLinkedList<eltType>::operator =(const CLinkedList<eltType>& cl)
{ if (this != &cl)
    {       destroy(last);
      head = copy(cl.last);
    }
  return *this;
}

template <typename eltType>
	void CLinkedList<eltType>::insert(eltType x)
{ if (empty()) {
    assert(last=new node<eltType>(x,last));
    last->next = last;
    return;
  }  

  
  if(x > last->data)
  {
     assert(last->next=new node<eltType>(x,last->next));
     last = last->next;
     return;
  }

  assert(last->next=new node<eltType>(x,last->next));
  
 } 

// Inline: Look into this.
template <typename eltType> inline bool CLinkedList<eltType>::empty()
{return (last == NULL);}

template <typename eltType> void CLinkedList<eltType>::destroy(node<eltType> *l)
{       while (l != NULL)
    {       node<eltType> *doomed = l;
      l = l->next;
      delete doomed;
    }
}

template <typename eltType>
node<eltType>* LinkedList<eltType>::copy(node<eltType> *l)
{       node<eltType>* first = NULL;    // ptr to beginning of copied LinkedList
        node<eltType>* tail = NULL;     // ptr to last item insert in the copy
        
  if (l != NULL)
    {       assert((first=tail=new node<eltType>(l->data,NULL)) != NULL);
      for (node<eltType>* source=l->next;source!=NULL;
	   source=source->next,tail=tail->next)
	{       tail->next = new node<eltType>(source->data,NULL);
	  assert(tail->next);
	}
    }
  return first;
}

///Output a linked list, using a list iterator
/*template <typename eltType> ostream& operator<<(ostream &os,const CLinkedList<eltType> &l)
{
  CListItr<eltType> lt(l);
  lt.begin();
  
  while ( lt.isLastNode() == False ) {
    os << lt*;
    lt++;
  }
  return os;
}
*/

/* ****************************************************************
************** List Iterator Implementations *******************
****************************************************************/

// Construct a list iterator. It consists of:
//       a reference to a linked list object
//       a pointer to the actual list, initially pointing to its head
template <typename eltType>
CListItr<eltType>::CListItr(const CLinkedList<eltType> &l): itr(l)
{}

// Set curr to point at itr's head
template <typename eltType> void CListItr<eltType>::begin(void)
{curr = itr.last->next;}

template <typename eltType> bool CListItr<eltType>::isEmpty(void)
{return(curr==NULL);}

//isFirstNode() - returns whether the present node is first in the list
template <typename eltType> bool CListItr<eltType>::isFirstNode(void)
{return(curr==last->next);}

//isLastNode() - returns whether the present node is last in the list
template <typename eltType> bool CListItr<eltType>::isLastNode(void)
{return(curr==last);}


//get for current location
template <typename eltType> eltType &CListItr<eltType>::operator*(void)
{return (curr -> data);}


template <typename eltType> eltType &CListItr<eltType>::operator*(void) const
{assert( curr != NULL );
  return curr->data;
}

template <typename eltType> void CListItr<eltType>::operator++(void)
{
  assert( curr != last );
  curr = curr->next;
}

template <typename eltType> void CListItr<eltType>::operator++(int num)
{
  if(isEmpty())
        return;
  
  for( ;curr!=last || num!=0; num--)
        curr = curr->next;
                
  
}

template class node<int>;
template class CLinkedList<int>;
template class CListItr<int>;

  
        
  
    

