/*
Linear Search is defined as a sequential search algorithm that starts at one end and goes through each element of a list 
until the desired element is found, otherwise the search continues till the end of the data set. It is the easiest searching algorithm

Given an array arr[] of N elements, the task is to write a function to search a given element x in arr[].
Follow the given steps to solve the problem:
1-Set the first element of the array as the current element.
2-If the current element is the target element, return its index.
3-If the current element is not the target element and if there are more elements in the array, set the current element to the next element and repeat step 2.
4-If the current element is not the target element and there are no more elements in the array, return -1 to indicate that the element was not found.
*/

#include <bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int N, int x){
	
	for (int i = 0; i < N; i++)
		if (arr[i] == x)
			return i;
	return -1;
}

int main(void){
	
	int arr[] = { 2, 3, 4, 10, 40 };
	int x = 10;
	int N = sizeof(arr) / sizeof(arr[0]);

	int result = linearSearch(arr, N, x);
	(result == -1) 		? cout << "Element is not present in array"		: cout << "Element "<<x<<" is present at index " << result;

return 0;
}
