/****************************************************************************
   Author:               Ryan Bolesta
   Due Date:             November 17, 2016
   Course:               CSC402
   Professor Name:       Dr. Zhang
   Assignment:           #4
   File Name:            Selection_RyanBolesta.cpp
   Purpose:              Program uses the TernaryHeap class to build a ternary
			 heap of all of the numbers in the file numbers.dat.
			 Then the user enters a number to find the kth largest
			 number. Through a loop of deleteMax operations on the
			 heap, the largest number is now at the root. So a
			 findmax operation returns the kth largest number.
*****************************************************************************/

#include <iostream>
#include "TernaryHeap_RyanBolesta.h"
#include <fstream>
#include <sstream>
using namespace std;

int main( )
{
    TernaryHeap<int> h;
    int x, k;
    ifstream infile;
    infile.open("numbers.dat");

    while (infile>>x)
            h.insert(x);

    cout << "\nEnter the value for k:  ";
    cin>>k;

    if(k < 1 || k > 400){
	    cout<<"****ERROR***** value for K must be > 0 and < 401"<<endl;
	    exit(0);
    }

    for(int i = k; i>1; i--)
            h.deleteMax();

    cout<<"The kth ("<<k<<") largest number in numbers.dat is "<<h.findMax()<<endl<<endl;

    return 0;
}
