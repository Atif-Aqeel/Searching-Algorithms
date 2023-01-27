/*
Find the first repeating element in an array of integers using Hashset

The idea is to traverse the given array arr[] from right to left and update the minimum index whenever, 
an already visited element has been found. To check if the element was already visited Hashset can be used. 

Follow the steps below to implement the idea:

-Initialize an empty Hashset myset and a variable min with -1.  
-Run a for loop for each index of array arr[] from N – 1 to 0.
	-If the current element is present in myset then update min with i.
	-Else insert arr[i] in myset. 
-Return min.

*/

#include <bits/stdc++.h>
using namespace std;

void printFirstRepeating(int arr[], int n){
	
	// Initialize index of first repeating element
	int min = -1;

	// Creates an empty hashset
	set<int> myset;

	// Traverse the input array from right to left
	for (int i=n-1; i>=0; i--) {
		
		// If element is already in hash set, update min
		if (myset.find(arr[i]) != myset.end())
			min = i;

		else 
			// Else add element to hash set
			myset.insert(arr[i]);
	}

	// Print the result
	if (min != -1)
		cout << "The first repeating element is "
			<< arr[min];
	else
		cout << "There are no repeating elements";
}

int main(){
	
	int arr[] = { 10, 5, 3, 4, 3, 5, 6 };

	int n = sizeof(arr) / sizeof(arr[0]);
	printFirstRepeating(arr, n);
	
}







/*
Naive Approach:
Run two nested loops, the outer loop picks an element one by one, and the inner loop checks whether the element is repeated or not. 
Once a repeating element is found, break the loops and print the element.

Using Sorting:
Store the elements of arr[] in a duplicate array temp[], sort temp[] and traverse arr[] from 0 to N – 1, 
Simultaneously check the count of this element in temp[] and if the current element arr[i] has more than one occurrence then return arr[i].
Follow the steps below to Implement the idea: 

-Copy the given array to an auxiliary array temp[] and sort temp array. 
-Traverse the input array arr[] from 0 to N – 1. 
	-For every element, count its occurrences in temp[] using binary search.
	-If the count of occurrence of current element is more than one, then return the current element.
-If no repeating element is found print “No Repeating Number Found”.

*/
