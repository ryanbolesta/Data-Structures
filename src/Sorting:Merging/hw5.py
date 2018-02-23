#*****************************************************************************
#Student:       Ryan Bolesta
#Course:		CSC310
#Assignment:	Homework 5
#Due Date:      May 4, 2017
#Instructor:    Dr. Shim
#Filename:		hw5.py
#Description:   Learn scope rules, short circuit, and general aspects of two
#                different programming languages by implementing methods to
#                sort and merge two arrays and then search for items in them.
#*****************************************************************************


#Name:       bubbleSort
#Purpose:    Sorts an array using bubble sort
def bubbleSort( arr ):
	for i in arr:
		for k in range( len( arr ) - 1, i, -1 ):
      			if( arr[k] < arr[k - 1] ):
       				arr[k],arr[k-1]=arr[k-1],arr[k]

#Name:       selectionSort
#Purpose:    Sorts an array using selection sort
def selectionSort( arr ):
   for i in range(len(arr)-1,0,-1):
       maxpos = 0
       for j in range(1,i+1):
           if arr[j]>arr[maxpos]:
        		maxpos = j

       arr[i],arr[maxpos]=arr[maxpos],arr[i]

#Name:       merge
#Purpose:    Merges two sorted arrays and returns the resulting array
def merge( arr1, arr2 ):
	i1 = 0
	i2 = 0
	arr3 = []

	while i1 < len(arr1) and i2 < len(arr2):
		x = arr1[i1]
		y = arr2[i2]
		if(x < y):
			arr3.append(arr1[i1])
			i1+=1
		elif(y < x):
			arr3.append(arr2[i2])
			i2+=1
	while i1 < len(arr1):
		arr3.append(arr1[i1])
		i1+=1
	while i2 < len(arr2):
		arr3.append(arr2[i2])
		i2+=1
	return arr3

#Name:       binarySearch
#Purpose:    Search for an item in the array using binary searching
def binarySearch(arr, key):
	low = 0
	high = len(arr) - 1

	while high >= low:
		middle = (low + high) / 2
		if arr[middle] == key:
			return middle
		if arr[middle] < key:
			low = middle + 1
		if arr[middle] > key:
			high = middle - 1
	return -1

# Name:       linearSearch
# Purpose:    Search for an item in the array using linear searching

def linearSearch(arr, key):
	i = 0
	while i < len(arr) and arr[i] <= key:
		if arr[i] == key:
			return i
		i+=1
	return -1

arr1 = [1, 4, 66, 10, 2, 5, 3, 99, 108]
arr2 = [8, 9, 6, 22, 56, 11]
print "Array 1:\t", arr1
print "Array 2:\t", arr2
bubbleSort(arr1)
print "\nArray 1 (After bubble sort):\t", arr1
selectionSort(arr2)
print "\nArray 2 (After selection sort):\t", arr2
arr3 = merge(arr1, arr2)
print "\nMerged arrays:\t", arr3
x = 0
while x != 666:
	x = input("\nEnter a number to search for: \t")
	i = binarySearch(arr3, x)
	if i != -1:
		print"\nThe number was found in index ", i
	else:
		print"\nThe number was not found"

while x != 888:
	x = input("\nLinear: Enter a number to search for: \t")
	i = linearSearch(arr3, x)
	if i != -1:
		print"\nThe number was found in index ", i
	else:
		print"\nThe number was not found"
