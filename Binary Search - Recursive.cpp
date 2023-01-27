/*
Step-by-step Binary Search Algorithm: We basically ignore half of the elements just after one comparison.
-Compare x with the middle element.
-If x matches with the middle element, we return the mid index.
-Else If x is greater than the mid element, then x can only lie in the right half subarray after the mid element. So we recur for the right half.
-Else (x is smaller) recur for the left half.
*/

#include<bits/stdc++.h>
using namespace std;

// A recursive binary search function. It returns location of x in given array arr[l..r] is present, otherwise -1
int binarySearch(int arr[], int l, int r, int x){
	
	if (r >= l) {
		int mid = l + (r - l) / 2; 	// Avoid overflow, same as M=(L+R)/2

		// If the element is present at the middle itself
		if (arr[mid] == x)
			return mid;

		// If element is smaller than mid, then it can only be present in left subarray
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);

		// Else the element can only be present in right subarray
		return binarySearch(arr, mid + 1, r, x);
	}

	// We reach here when element is not present in array
	return -1;
}

int main(void){
	
	int arr[] = { 2, 3, 4, 10, 40 };
	int x = 10;
	int n = sizeof(arr) / sizeof(arr[0]);
	
	int result = binarySearch(arr, 0, n - 1, x);
	
	(result == -1)		? cout << "Element is not present in array"		: cout << "Element is present at index " << result;

return 0;
}

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
