/*
An efficient way to solve this problem is to use any O(nLogn) sorting algorithm & simply returning the last 3 largest elements.
*/

#include <bits/stdc++.h>
using namespace std;

void find3largest(int arr[], int n){
	
	sort(arr, arr + n); // It uses Tuned Quicksort with avg. case Time complexity = O(nLogn)

	int check = 0;
	int count = 1;
	
	for (int i=1; i<=n; i++) {
		//count<4 because we just need 3 elements
		if (count < 4) {

			if (check != arr[n-i]) {
				// to handle duplicate values
				cout << arr[n - i] << " ";
				check = arr[n - i];
				count++;
			}
		}
		else
			break;
	}
}

int main(){
	
	int arr[] = { 12, 45, 1, -1, 45, 54, 23, 5, 0, -10 };
	int n = sizeof(arr) / sizeof(arr[0]);

	find3largest(arr, n);

}


/*
For arrays, array name arr indicates iterator pointing to first element of array and +n would increment that iterator by n elements. 
In your case, the sort algorithm should take beginning iterator and iterator pointing to one beyond last element.

arr: beginning iterator 
arr+n: ending iterator (one beyond last element)

*/
