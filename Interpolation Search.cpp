/*
Uniform distributions are probability distributions with equally likely outcomes. 
In a discrete uniform distribution, outcomes are discrete and have the same probability. 
In a continuous uniform distribution, outcomes are continuous and infinite. 
In a normal distribution, data around the mean occur more frequently.

Usually an array is considered as uniformly distributed when the difference between the elements are equal or almost same. 
Example 1: 1,2,3,4,5,6 (Difference is 1) 
Example 2: 10,20,31,40,55,60,73,80 (Here the difference between the two adjacent elements are almost close to 10).

-The Interpolation Search is an improvement over Binary Search for instances, where the values in a sorted array are uniformly distributed. 
-Interpolation constructs new data points within the range of a discrete set of known data points. 
-Binary Search always goes to the middle element to check. On the other hand, interpolation search may go to different locations according to the value of the 
 key being searched. For example, if the value of the key is closer to the last element, interpolation search is likely to start search toward the end side.


To find the position to be searched, it uses the following formula. 
// The idea of formula is to return higher value of pos when element to be searched is closer to arr[hi]. And smaller value when closer to arr[lo]
	pos = lo + [ {(x-arr[lo])*(hi-lo) }/{ (arr[hi]-arr[Lo]) }]
	arr[] ==> Array where elements need to be searched
	x     ==> Element to be searched
	lo    ==> Starting index in arr[]
	hi    ==> Ending index in arr[]


Algorithm 
Step1: In a loop, calculate the value of “pos” using the probe position formula. 
Step2: If it is a match, return the index of the item, and exit. 
Step3: If the item is less than arr[pos], calculate the probe position of the left sub-array. Otherwise, calculate the same in the right sub-array. 
Step4: Repeat until a match is found or the sub-array reduces to zero.

*/

//interpolation search with recursion
#include <bits/stdc++.h>
using namespace std;

// If x is present in arr[0..n-1], then returns index of it, else returns -1.
int interpolationSearch(int arr[], int lo, int hi, int x){
	
	int pos;

	// Since array is sorted, an element present in array must be in range defined by corner
	if (lo <= hi && x >= arr[lo] && x <= arr[hi]) {

		// Probing the position with keeping uniform distribution in mind.
		pos = lo + (  ((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo])  );
			
				/*	pos = lo + [ (x-arr[lo])*(hi-lo) / (arr[hi]-arr[Lo]) ]
					arr[] ==> Array where elements need to be searched
					x     ==> Element to be searched
					lo    ==> Starting index in arr[]
					hi    ==> Ending index in arr[]
				*/

		// Condition of target found
		if (arr[pos] == x)
			return pos;

		// If x is larger, x is in right sub array
		if (arr[pos] < x)
			return interpolationSearch(arr, pos + 1, hi, x);

		// If x is smaller, x is in left sub array
		if (arr[pos] > x)
			return interpolationSearch(arr, lo, pos - 1, x);
	}
	return -1;
}

int main(){

	int arr[] = { 10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47 };

	int n = sizeof(arr) / sizeof(arr[0]);

	// Element to be searched
	int x = 18;
	int index = interpolationSearch(arr, 0, n - 1, x);

	// If element was found
	if (index != -1)
		cout << "Element found at index " << index;
	else
		cout << "Element not found.";

return 0;
}
