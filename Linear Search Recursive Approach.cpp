/*
Linear Search Recursive Approach:
Follow the given steps to solve the problem:
-If the size of the array is zero then, return -1, representing that the element is not found. This can also be treated as the base condition of a recursion call.
-Otherwise, check if the element at the current index in the array is equal to the key or not i.e, arr[size – 1] == key
	-If equal, then return the index of the found key.
*/

#include<bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int size, int key){
	
	if (size == 0) {
		return -1;
	}
				//arr[size-1] => show current index of array as array index start from 0
	else if (arr[size - 1] == key) {
		// Return the index of found key.
		return size - 1;
	}
	else {
		int ans = linearSearch(arr, size - 1, key);
		return ans;
	}
}

int main(){
	
	int arr[5] = {5, 15, 6, 9, 4 };
	int key = 9; 

	int ans = linearSearch(arr, 5, key);
	
	if (ans == -1) {
		cout << "The element " << key << " is not found."	<< endl;
	}
	else {
		cout << "The element " << key << " is found at "	<< ans << " index of the given array." << endl;
	}

return 0;
}
