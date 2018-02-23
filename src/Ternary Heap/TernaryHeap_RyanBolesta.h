/****************************************************************************
   Author:               Ryan Bolesta
   Due Date:             November 17, 2016
   Course:               CSC402
   Professor Name:       Dr. Zhang
   Assignment:           #4
   File Name:            TernaryHeap_RyanBolesta.cpp
   Purpose:              Ternary Heap class contains functions for building
			 and altering a ternary heap. The maximum item in the
			 heap is at the root and is returned via findMax.
*****************************************************************************/

#ifndef TERNARY_HEAP_H
#define TERNARY_HEAP_H

#include "dsexceptions.h"
#include <vector>
#include <algorithm>
using namespace std;

// TernaryHeap class
//
// CONSTRUCTION: with an optional capacity (that defaults to 100)
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// deleteMax( maxItem )   --> Remove (and optionally return) largest item
// Comparable findMax( )  --> Return largest item
// bool isEmpty( )        --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// ******************ERRORS********************************
// Throws UnderflowException as warranted

template <typename Comparable>
class TernaryHeap
{
  public:
    explicit TernaryHeap( int capacity = 100 )
      : array( capacity + 1 ), currentSize( 0 )
    {
    }

    explicit TernaryHeap( const vector<Comparable> & items )
      : array( items.size( ) + 10 ), currentSize( items.size( ) )
    {
        for( int i = 0; i < items.size( ); i++ )
            array[ i + 1 ] = items[ i ];
        buildHeap( );
    }

    bool isEmpty( ) const
      { return currentSize == 0; }

    /**
     * Find the smallest item in the priority queue.
     * Return the smallest item, or throw Underflow if empty.
     */
    const Comparable & findMax( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException();
        return array[ 0 ];
    }
    /**
     * Insert item x, allowing duplicates.
     */
    void insert( const Comparable & x )
    {
        if( currentSize == array.size( ) - 1 )
            array.resize( array.size( ) * 2 );

            //Percolate up
        // int hole = ++currentSize;
        // for( ; hole > 1 && x > array[ hole / 2 ]; hole /= 2 )
        //     array[ hole ] = array[ hole / 2 ];
        // array[ hole ] = x;

        /*******TERNARY VERSION ******/
        int hole = currentSize;
        currentSize++;
        while (hole != 0 && array[(hole - 1) / 3] < x)
         {
             array[hole] = array[(hole - 1) / 3];
             hole = (hole - 1) / 3;
         }
        array[ hole ] = x;
    }

    /**
     * Remove the maximum item.
     * Throws UnderflowException if empty.
     */
    void deleteMax( )
    {
        if( isEmpty( ) )
            throw UnderflowException( );

	currentSize--;
        array[ 0 ] = array[ currentSize];
        percolateDown( 0 );
    }

    void makeEmpty( )
      { currentSize = 0; }

  private:
    int                currentSize;  // Number of elements in heap
    vector<Comparable> array;        // The heap array

    /**
     * Establish heap order property from an arbitrary
     * arrangement of items. Runs in linear time.
     */
    void buildHeap( )
    {
        for( int i = currentSize / 2; i > 0; i-- )
            percolateDown( i );
    }

    /**
     * Internal method to percolate down in the heap.
     * hole is the index at which the percolate begins.
     */
    void percolateDown( int hole )
    {
        int lchild, mchild, rchild;
	int holder = hole;

        while((3 * hole) + 1 < currentSize+1){
		lchild = (3 * hole) + 1;
                mchild = (3 * hole) + 2;
                rchild = (3 * hole) + 3;
		holder = lchild;

		if(mchild < currentSize){
			if(array[mchild] > array[lchild])
				holder = mchild;//array[mchild];
		}
		if(rchild < currentSize){
			if(array[rchild] > array[mchild] && array[rchild] > array[lchild])
				holder = rchild;
		}

		if(array[holder] > array[hole])
			swap(array[holder], array[hole]);

		hole = holder;
        }//end while
}
};

#endif
