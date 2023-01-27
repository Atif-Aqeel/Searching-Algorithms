/*
We can use Partial Sort of C++ STL. 
partial_sort uses Heapselect, which provides better performance than Quickselect for small M. 
As a side effect, the end state of Heapselect leaves you with a heap, which means that you get the first half of the Heapsort algorithm “for free”. 
The complexity is “approximately” O(N log(M)), where M is distance(middle-first).


std::sort is used for sorting the elements present within a container. 
One of the variants of this is std::partial_sort, which is used for sorting not the entire range, but only a sub-part of it.
It rearranges the elements in the range [first, last), 
in such a way that the elements before middle are sorted in ascending order, whereas the elements after middle are left without any specific order.

-std::sort() vs std::partial_sort(): 
--Some of you might think that why are we using std::partial_sort, in place we can use std::sort() for the limited range, 
  -but remember, if we use std::sort with a partial range, then only elements within that range will be considered for sorting, 
   while all other elements outside the range will not be considered for this purpose, 
  -whereas with std::partial_sort(), all the elements will be considered for sorting.

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	
    vector<int> V = { 11, 65, 193, 36, 209, 664, 32 };
    partial_sort( V.begin(), V.begin() + 3, V.end(), greater<int>() );
 
    cout << "first = " << V[0] << "\n";
    cout << "second = " << V[1] << "\n";
    cout << "third = " << V[2] << "\n";
    
return 0;
}











/*
Vectors are sequence containers representing arrays that can change in size.
Just like arrays, vectors use contiguous storage locations for their elements, 
which means that their elements can also be accessed using offsets on regular pointers to its elements, and just as efficiently as in arrays. 
But unlike arrays, their size can change dynamically, with their storage being handled automatically by the container.

*/
