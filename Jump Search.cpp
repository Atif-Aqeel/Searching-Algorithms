/*
Like Binary Search, Jump Search is a searching algorithm for sorted arrays. 
The basic idea is to check fewer elements (than linear search) by jumping ahead by fixed steps 
or skipping some elements in place of searching all elements.

For example, suppose we have an array arr[] of size n and a block (to be jumped) of size m. 
Then we search in the indexes arr[0], arr[m], arr[2m]?..arr[km] and so on. 
Once we find the interval (arr[km] < x < arr[(k+1)m]), we perform a linear search operation from the index km to find the element x.

Let?s consider the following array: (0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610). The length of the array is 16. 
The Jump search will find the value of 55 with the following steps assuming that the block size to be jumped is 4. 
STEP 1: Jump from index 0 to index 4; 
STEP 2: Jump from index 4 to index 8; 
STEP 3: Jump from index 8 to index 12; 
STEP 4: Since the element at index 12 is greater than 55, we will jump back a step to come to index 8. 
STEP 5: Perform a linear search from index 8 to get the element 55.


What is the optimal block size to be skipped? 
In the worst case, we have to do n/m jumps, and if the last checked value is greater than the element to be searched for, 
we perform m-1 comparisons more for linear search. Therefore, the total number of comparisons in the worst case will be ((n/m) + m-1). 
The value of the function ((n/m) + m-1) will be minimum when m = vn. Therefore, the best step size is m = vn.
*/

#include <bits/stdc++.h>
using namespace std;

int jumpSearch(int arr[], int x, int n){
	
	// Finding block size to be jumped
	int step = sqrt(n);

	// Finding the block where element is present (if it is present)
	int prev = 0;
	while (arr[min(step, n)-1] < x){
		
		prev = step;
		step += sqrt(n);
		if (prev >= n)
			return -1;
	}

	// Doing a linear search for x in block beginning with prev.
	while (arr[prev] < x){
		
		prev++;

		// If we reached next block or end of array, element is not present.
		if (prev == min(step, n))
			return -1;
	}
	
	// If element is found
	if (arr[prev] == x)
		return prev;

	return -1;
}

int main(){
	
	int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610 };
	int x = 55;
	int n = sizeof(arr) / sizeof(arr[0]);
	
	// Find the index of 'x' using Jump Search
	int index = jumpSearch(arr, x, n);

	// Print the index where 'x' is located
	cout << "Number " << x << " is at index " << index;

return 0;
}


/*
Performance in comparison to linear and binary search:
If we compare it with linear and binary search then it comes out then it is better than linear search but not better than binary search.

The increasing order of performance is:
linear search  <  jump search  <  binary search
*/
