/*****************************************************************************
 Student:       Ryan Bolesta
 Course:	CSC237
 Assignment:	Project 2
 Due Date:      March 5, 2016
 Instructor:    Dr. Spiegel
 Filename:	CLinkedList.h
 Description:   Contains the function definitions for the member functions of 
		the circular linked list class as well as an associated node
		and iterator class. Member functions support operations for
		inserting and removing from list as well as making deep copies
		of a list. Iterator class provides public interface to the list
		with functions for accessing elements and incrementing iterator
		to the next element. 
*****************************************************************************/

#ifndef CLINKEDLIST_H
#define CLINKEDLIST_H
#include <assert.h>
#include <iostream>
using namespace std;


///Template class prototypes
template <class eltType> class CLinkedList;
template <class eltType> class CListItr;

template <class eltType> class node
{       private:
                node(eltType info, node* link = NULL ) :
						data(info), next(link) {};
                eltType data;
                node *next;
        friend class CLinkedList<eltType>;
        friend class CListItr<eltType>;
};

template <typename eltType> class CLinkedList
{
 public:
  CLinkedList(): last(NULL){}
        /*******************************************************************
        Function:    Constructor
        Member Type: mutator
        Description: The constructor of the class will construct an empty 
                        circular linked list. Sets pointer last to NULL.
        Parameters:  None
        Returns:     n/a      	
        *********************************************************************/
  
  CLinkedList(CLinkedList& cl)
  {     /*******************************************************************
        Function:    Copy Constructor
        Member Type: mutator
        Description: The copy constructor will call the associated copy function
                        and create a deep copy of another linked list object.
        Parameters:  CLinkedList& cl - import/export - the list being copied
        Returns:     n/a      	
        *********************************************************************/
        last = copy( cl.last);}
  

  ~CLinkedList() 
  {     /*******************************************************************
        Function:    ~CLinkedList() (destructor)
        Member Type: mutator
        Description: Destructor will call the associated destroy function which
                        will cycle through the linked list deleting each node
        Parameters:  none
        Returns:     n/a      	
        *********************************************************************/
        destroy(last);}
 
  
  CLinkedList& operator=(const CLinkedList& cl)
  {     /*******************************************************************
        Function:    operator=
        Member Type: mutator
        Description: Uses destroy function to delete last and then uses the copy 
                        function to create a deep copy of the list and assign 
                        it to last.
        Parameters:  CLinkedList& cl - import/export - the object being copied
        Returns:     the object   	
        *********************************************************************/
        if (this != &cl)
        {       destroy(last);
                last = copy(cl.last);
        }
        return *this;
  }

  // Is the CLinkedList empty?
  bool empty() const
  {     /*******************************************************************
        Function:    empty
        Member Type: inspector
        Description: Determines if the linked list is empty
        Parameters:  None
        Returns:     True - if the list is empty
	             False - if the list is not empty	
	*********************************************************************/
        return (last == NULL);}
  
  // Ordered insert/remove
  void insert(eltType x)
  {     /*******************************************************************
        Function:    insert
        Member Type: mutator
        Description: inserts into the linked list in ascending order. Accounts
                        for special case when the list is empty. Ensures that
                        the last node in the list will always point to the first
        Parameters:  eltType x - input - element being inserted into list.
        Returns:     n/a
	*********************************************************************/ 
	
        if (empty()) 
        {       assert(last=new node<eltType>(x,last));
                last->next = last;
                return;
        }  
        if(x > last -> data)
        {
                assert(last->next=new node<eltType>(x,last->next));
                last = last->next;
                return;
        }
  
        node<eltType>*  p = last->next;  
        node<eltType>*  trailp  = last;
        while (p != last && x > p->data)
        {       trailp = p;
                p = p->next;
        }

        trailp->next = new node<eltType>(x,p);
  }
  
/**  NOTE: Wrote find() not realizing it was unneccessary. Kept it here incase 
          it's needed in the future                                         **/
          
/*bool find(eltType x) const
  {       /*******************************************************************
          Function:    find
          Member Type: inspector
          Description: Searches through the list to find if the parameter x is 
                        in the list. Returns true if element is found.
          Parameters:  eltType x - import - the element being searched for
          Returns:     True - if x is found
	               False - if x is not found
	  *********************************************************************
 
        if(empty() || x > last-> data)
                return false; 
        
        if(x == last->data)
                return true;
        
        node<eltType> *p = last->next;
        while(p!=last && p->data > x)
                p = p->next;
        return(x == p->data);
} */
 
  bool remove(eltType x)
  {     /*******************************************************************
        Function:    remove
        Member Type: mutator
        Description: the function will iterate through the list until the element
                        is found and then the node will be deleted. Pointers 
                        will be reassigned accordingly. Special cases for when
                        there is only one node and when the last node in a multi
                        node list get deleted.
        Parameters:  None
        Returns:     True - if x is removed
	             False - if x is not removed
	*********************************************************************/
  
        if(empty() || x > last-> data || x < last->next->data )
                return false; 
             
        node<eltType> *p = last->next;
        node<eltType>*  trailp = last;
   
        while( p->data < x && p!=last)
        {       trailp = p;
                p = p->next;
        }       
        if(x != p->data)
                return false;     
          
        trailp->next = p->next;
        if(x == last->data)
        {       if(p==trailp)
                        last = NULL;
                else
                        last = trailp;    
        }
        delete p;
        return true;
 } 

 private:

  node<eltType>* last;


  node<eltType>* copy(node<eltType> *l)
  {     /*******************************************************************
        Function:    copy
        Member Type: mutator
        Description: Creates a deep copy of another circular linked list object.
                        Recursively calls itself, copying a node each time until
                        it cycles back to the static node pointer rear.
        Parameters:  node<eltType> *l - import - pointer to a node
        Returns:     pointer to a node
	*********************************************************************/     

       if(l == NULL)
                return NULL;
  
       static node<eltType>* rear = l; 
       if(empty())
       {        assert(last=new node<eltType>(l->data, last));  
                last->next = last;
                return(copy(l));
       }
       else if(l->next != rear)
       {        assert(last->next=new node<eltType>(l->next->data, last->next)); 
                last = last->next;
                return(copy(l->next));
       }
       return last->next;       
  }

  void  destroy(node<eltType> *l)
  {     /*******************************************************************
        Function:    destroy
        Member Type: mutator
        Description: Recursively calls itself until it is in the second to last
                        node in the list. Then cycles back deleting each node.
        Parameters:  node<eltType>*l - import - pointer to a node
        Returns:     n/a
	*********************************************************************/
	
        if(l)
        {       if(l->next != last)
                        destroy(l->next);
                delete l;
        }
  }

  friend class CListItr<eltType>;
};

template <typename eltType> class CListItr
{
 public:
  
  CListItr(const CLinkedList<eltType> &l): itr(l),curr(l.last) {}
        /*******************************************************************
        Function:    constructor
        Member Type: mutator
        Description: Creates a list iterator that consists of a reference to a 
                        circular linked list object.
        Parameters:  CLinkedList - l - imp/exp - reference to linked list object	 
        Returns:     n/a
	*********************************************************************/

  void begin() 
  {     /*******************************************************************
        Function:    begin
        Member Type: mutator
        Description: Increments iterator to the first node in the list with a 
                        precondition that the list is not empty
        Parameters:  none	 
        Returns:     n/a
	*********************************************************************/
        assert(curr!=NULL);
        curr = itr.last->next;
  }
  
  bool isEmpty() const
  {     /*******************************************************************
        Function:    isEmpty
        Member Type: inspector
        Description: Checks if the list is empty and returns true if so
        Parameters:  none 
        Returns:     True - list is empty 
                     False - list has at least one node
	*********************************************************************/
        return(curr==NULL);}
  
  bool isFirstNode() const
  {     /*******************************************************************
        Function:    isFirstNode
        Member Type: inspector
        Description: Checks if the current node is the first node in the list
        Parameters:  none	 
        Returns:     True - current node is the first
                     False - current node is not the first
	*********************************************************************/
        return(!isEmpty()) && (curr==itr.last->next);}
  
  bool isLastNode() const
  {     /*******************************************************************
        Function:    isLastNode
        Member Type: inspector
        Description: Checks if the current node is the last node in the list
        Parameters:  none	 
        Returns:     True - current node is the last
                     False - current node is not the last
	*********************************************************************/
        return((!isEmpty()) && curr==itr.last);}
  
  eltType &operator*()
  {     /*******************************************************************
        Function:    operator*
        Member Type: inspector
        Description: returns the value stored in curr->data
        Parameters:  none	 
        Returns:     the element in curr->data
	*********************************************************************/
        return (curr -> data);}
  
  const eltType &operator*() const
  {     /*******************************************************************
        Function:    operator*
        Member Type: inspector
        Description: returns the value stored in curr->data
        Parameters:  none	 
        Returns:     the element in curr->data
	*********************************************************************/
        assert( curr != NULL );
        return curr->data; } 
  
  CListItr operator++()
  {     /*******************************************************************
        Function:    operator++
        Member Type: mutator
        Description: increments curr to the next node in the list
        Parameters:  none	 
        Returns:     the object
	*********************************************************************/
        assert( curr != NULL );
        curr = curr->next;
        return *this;
  }
  
  CListItr operator++(int d)
  {     /*******************************************************************
        Function:    operator++
        Member Type: mutator
        Description: increments curr to the next node in the list
        Parameters:  int d - dummy int parameter	 
        Returns:     the object
	*********************************************************************/
        CListItr tmp(*this);
        ++(*this);
        return tmp;
  }
  
 private:
  const CLinkedList<eltType> &itr;
  node<eltType> *curr;
};

#endif



