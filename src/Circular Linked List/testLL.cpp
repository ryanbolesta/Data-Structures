/*****************************************************************************
 Student:       Ryan Bolesta
 Course:	CSC237
 Assignment:	Project 2
 Due Date:      March 5, 2016
 Instructor:    Dr. Spiegel
 Filename:	testLL.cpp
 Description:   Test driver for the circular linked list class. This file
                creates a integer circular linked list object and then prompts 
                the user with options to perform on the object. Options include 
                inserting an integer to the list, removing an integer from the 
                list, and printing the list in either ascending or descending 
                order.
*****************************************************************************/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include "CLinkedList.h"
#include <stdio.h>

using namespace std;

///Displays menu for inserting and removing elements in the list, as well as 
///      printing in ascending or descending order. Exit option also available.
///      recursively calls itself until user chooses to exit.
void displayMenu(CLinkedList<int>& list);

///Prompts user to enter an integer to add to the list through calls
///     to the list's members functions. Updated list is printed.
void insertInt(CLinkedList<int>& list);

///Prompts user to enter an integer to remove from the list through calls
///     to the list's members functions. Updated list is printed.
void removeInt(CLinkedList<int>& list);

///Prints the circular linked list in ascending using the list iterator and
///     a do while loop.
void printForwards(CLinkedList<int>& list);

///     With help of the countElts() function, list is printed in descending order
///     via a do while loop that cycles the iterator through the list to the
///     next node that hasn't been printed and then prints it.
void printBackwards(CLinkedList<int>& list);

///Helper function for printing the list backwards. Loops through the circular
///     linked list object and returns the number of elements in the object.
int countElts(CListItr<int> it);

int main()
{
        CLinkedList<int> testList; 
        displayMenu(testList);
 
        /* TEST CALLS
        CLinkedList<int> numbers;
        numbers.insert(8);
        numbers.insert(5);
        numbers.insert(6);
        CLinkedList<int> numbers2;
        cout<<endl<<endl;
        CLinkedList<int> cctest1;///(numbers);
        cctest1 = numbers;
        printForwards(numbers);
        cout<<endl;
        printForwards(cctest1);
        cout<<endl;
        numbers = numbers2;
        printBackwards(numbers); */
}

void displayMenu(CLinkedList<int>& list)
{       /*********************************************************************
        Function:    displayMenu
        Description: Displays menu for inserting and removing elements in the 
                        list, as well as printing in ascending or descending 
                        order. Exit option also available. Recurively calls
                        itself until user exits.
        Parameters:  CLinkedList<int>& list - import/export - the object
        Returns:     n/a
        **********************************************************************/

        char cmd;
        cout<<"\n\nCircular Linked List Test Driver"<<endl
                <<"I)nsert Integer\nR)emove Integer\nF)orward Print\n"
                <<"B)ackward Print\nE)xit\n";
        cin>>cmd;
  
        switch(cmd)
        {       case'I':
                case'i':
                        insertInt(list);
                        break;
                case'R':
                case'r':
                        removeInt(list);
                        break;
                case'F':
                case'f':
                        printForwards(list);
                        break;
                case'B':
                case'b':
                        printBackwards(list);
                        break;
                case'E':
                case'e':
                        exit(0);
                        break;
                default:
                        cout<<"Invalid character try again\n";      
        }
        displayMenu(list);
}

void insertInt(CLinkedList<int>& list)
{       /*********************************************************************
        Function:    insertInt
        Description: Prompts user to enter an integer to add to the list through
                        calls to the list's members functions. Updated list is 
                        printed.
        Parameters:  CLinkedList<int>& list - import/export - the object
        Returns:     n/a
        **********************************************************************/
        int num = 0;
        cout<<"Enter an integer to add to the circular linked list\n";
        cin>>num;
 
        list.insert(num);
        cout<<"Integer added\nUpdated list is:  ";
        printForwards(list);
}

void removeInt(CLinkedList<int>& list)
{       /*********************************************************************
        Function:    removeInt
        Description: Prompts user to enter an integer to remove from the list 
                        through calls to the list's members functions. Updated 
                        list is printed.
        Parameters:  CLinkedList<int>& list - import/export - the object
        Returns:     n/a
        **********************************************************************/

        int num = 0;
        cout<<"Enter an integer to remove from the circular linked list\n";
        cin>>num;
        
        if(list.remove(num))
        {       cout<<"Integer removed successfully\nUpdated list is:  ";
                printForwards(list);
        }
 
        else
                cout<<"Integer not found in the list";  
}

void printForwards(CLinkedList<int>& list)
{       /*********************************************************************
        Function:    printForwards
        Description: Prints the circular linked list in ascending using the 
                        list iterator and a do while loop. Loop stops when
                        iterator cycles back to the beginning of the list
        Parameters:  CLinkedList<int>& list - import/export - the object
        Returns:     n/a
        **********************************************************************/
        
        CListItr<int> iter(list);
 
        if(iter.isEmpty() == false)
        {       iter.begin();
                do
                {
                        cout<<iter.operator*()<<' ';
                        iter++;
                }while( iter.isFirstNode()==false );
        }
}

void printBackwards(CLinkedList<int>& list)
{       /*********************************************************************
        Function:    printBackwards
        Description: With help of the countElts() function, list is printed in 
                        descending order via a do while loop that cycles the 
                        iterator through the list to the next node that hasn't 
                        been printed. Stops when iterator stops back at the 
                        last node.
        Parameters:  CLinkedList<int>& list - import/export - the object
        Returns:     n/a
        **********************************************************************/

        CListItr<int> iter(list);
 
        if(iter.isEmpty() == false)
        {       iter.begin();
                int counter = countElts(iter);
                do
                {       int i = counter - 1;
                        for(; i!=0; i--, iter++);
                        cout<<*iter<<' ';
                }while(iter.isFirstNode()==false);
        }
}

int countElts (CListItr<int> it)
{       /*********************************************************************
        Function:    countElts
        Description: Helper function for printing the list backwards. Loops 
                        through the circular linked list object and returns the 
                        number of elements in the object.
        Parameters:  CListItr it - import - the list iterator 
        Returns:     int - counter - number of elements in list
        **********************************************************************/

        int counter = 0;
        do
        {       it++;
                counter++;
        }while( it.isFirstNode()==false );
        
        return counter;   
}        


