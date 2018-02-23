/*****************************************************************************
 Student:       Ryan Bolesta
 Course:	CSC310
 Assignment:	Homework 5
 Due Date:      May 4, 2017
 Instructor:    Dr. Shim
 Filename:	homework5.java
 Description:   Learn scope rules, short circuit, and general aspects of two
                different programming languages by implementing methods to
                sort and merge two arrays and then search for items in them.
*****************************************************************************/

import java.util.Scanner;

public class homework5 {

    public static void main(String[] args) {

        int MAXSIZE = 30;

        int[] arr1 = new int[] {1, 4, 66, 10, 2, 5, 3, 99, 108};
        int[] arr2 = new int[] {8, 9, 6, 22, 56, 11};
        int[] arr3 = new int[(arr1.length + arr2.length)] ;
        //Print arrays
        System.out.print("Array 1:\t");
        printArray(arr1);
        System.out.print("\nArray 2:\t");
        printArray(arr2);
        System.out.print("\n\n");

        //Bubble sort
        bubbleSort(arr1);
        System.out.print("Array 1 (After Bubble Sort):\t");
        printArray(arr1);
        System.out.print("\n\n");

        //Selection Sort
        selectionSort(arr2);
        System.out.print("Array 2 (After Selection Sort):\t");
        printArray(arr2);
        System.out.print("\n\n");

        //Merge Arrays
        arr3 = merge(arr1, arr2);
        System.out.print("Merged Arrays:\t");
        printArray(arr3);

        int x = 0;
        while(x != 666){
                System.out.print("\n\nEnter a number to search for");
                Scanner reader = new Scanner(System.in);
                x = reader.nextInt();
                int i = binarySearch(arr3, x);
                if(i != -1)
                        System.out.print("\nThe number was found in index " + i);
                else
                        System.out.print("\nThe number was not found");
        }

	while(x != 888){
                System.out.print("\n\nLinear: Enter a number to search for");
                Scanner reader = new Scanner(System.in);
                x = reader.nextInt();
                int i = linearSearch(arr3, x);
                if(i != -1)
                        System.out.print("\nThe number was found in index " + i);
                else
                        System.out.print("\nThe number was not found");
        }

    }

    /*************************************************************************
    Name:       linearSearch
    Purpose:    Search for an item in the array using linear searching
    **************************************************************************/
    public static int linearSearch(int[] arr, int key){

	int i = 0;
		  while(i < arr.length && arr[i] <= key){
                        if(arr[i] == key)
                                return i;
		  	i++;
		  }

         	return -1;
    }

    /*************************************************************************
    Name:       binarySearch
    Purpose:    Search for an item in the array using binary searching
    **************************************************************************/
    public static int binarySearch(int[] arr, int key){

            int low = 0;
            int high = arr.length - 1;

            while(high >= low) {
                    int middle = (low + high) / 2;
                    if(arr[middle] == key) {
                          return middle;
                    }
                    if(arr[middle] < key) {
                          low = middle + 1;
                    }
                    if(arr[middle] > key) {
                          high = middle - 1;
                    }
                }
            return -1;
    }

    /*************************************************************************
    Name:       merge
    Purpose:    Merges two sorted arrays and returns the resulting array
    **************************************************************************/
    public static int[] merge(int[] arr1, int[] arr2) {
          int[] arr3 = new int[(arr1.length + arr2.length)] ;
          int x, y;
          int i1 = 0;
          int i2 = 0;
          int i3 = 0;

          while(i1 < arr1.length && i2 < arr2.length){
                x = arr1[i1];
                y = arr2[i2];
                if(x < y){
                        arr3[i3] = arr1[i1];
                        i1++;
                }
                else if (y < x){
                        arr3[i3] = arr2[i2];
                        i2++;
                }
                i3++;
         }
         while(i1 < arr1.length){
                 arr3[i3] = arr1[i1];
                 i1++;
                 i3++;
         }
         while(i2 < arr2.length){
                 arr3[i3] = arr2[i2];
                 i2++;
                 i3++;
         }
         return arr3;

    }

    /*************************************************************************
    Name:       selectionSort
    Purpose:    Sorts an array using selection sort
    **************************************************************************/
    public static void selectionSort(int[] arr) {

            for (int i = 0; i < arr.length - 1; i++)
            {
                    int index = i;
                    for (int j = i + 1; j < arr.length; j++){
                            if (arr[j] < arr[index]){
                                    index = j;
                            }
                    }
                    int smallerNumber = arr[index];
                    arr[index] = arr[i];
                    arr[i] = smallerNumber;
            }

    }

    /*************************************************************************
    Name:       bubbleSort
    Purpose:    Sorts an array using bubble sort
    **************************************************************************/
    public static void bubbleSort(int[] arr) {
            int n = arr.length;
            int temp;
            boolean swapped = false;

            do{
                    swapped = false;
                    for(int i = 1; i < n; i++){
                            if(arr[i-1] > arr[i]){
                                   temp = arr[i-1];
                                   arr[i-1] = arr[i];
                                   arr[i] = temp;
                                   swapped = true;
                            }
                    }
            }while(swapped);


    }

    /*************************************************************************
    Name:       printArray
    Purpose:    Loops through an array via indexing, printing each element.
    **************************************************************************/
    public static void printArray(int[] arr) {

        for(int i = 0; i < arr.length; i++){
                if (i > 0) {
                        System.out.print(", ");
                }

                System.out.print(arr[i]);
        }

    }
}
