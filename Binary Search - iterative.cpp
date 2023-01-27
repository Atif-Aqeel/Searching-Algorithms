/*
Note: Here we are using 
		int mid = low + (high – low)/2;

Maybe, you wonder why we are calculating the middle index this way, we can simply add the lower and higher index and divide it by 2.
		int mid = (low + high)/2;

But if we calculate the middle index like this means our code is not 100% correct, it contains bugs.
That is, it fails for larger values of int variables low and high. 
Specifically, it fails if the sum of low and high is greater than the maximum positive int value(231 – 1 ).

The sum overflows to a negative value and the value stays negative when divided by 2. 
In java, it throws ArrayIndexOutOfBoundException.
		int mid = low + (high – low)/2;
		So it’s better to use it like this. This bug applies equally to merge sort and other divide and conquer algorithms.
*/

#include<bits/stdc++.h>
using namespace std;

// A iterative binary search function. It returns location of x in given array arr[l..r] if present, otherwise -1
int binarySearch(int arr[], int l, int r, int x){
	
	while (l <= r) {
		int m = l + (r - l) / 2;

		// Check if x is present at mid
		if (arr[m] == x)
			return m;

		// If x greater, ignore left half
		if (arr[m] < x)
			l = m + 1;

		// If x is smaller, ignore right half
		else
			r = m - 1;
	}

	// if we reach here, then element was not present
	return -1;
}

int main(void){
	
	int arr[] = { 2, 3, 4, 10, 40 };
	int x = 10;
	int n = sizeof(arr) / sizeof(arr[0]);
	
	int result = binarySearch(arr, 0, n - 1, x);
	
	(result == -1)	? cout << "Element is not present in array"	: cout << "Element is present at index " << result;
		
return 0;
}

