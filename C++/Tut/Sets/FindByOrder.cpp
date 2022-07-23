/*
The find_by_order() is a built-in function of Ordered Set which is a 
Policy Based Data Structure in C++. 

Policy-based data structures are not part of the C++ Standard Template Library but the g++ compiler supports them.

Ordered Set is a policy-based data structure in g++ that maintains unique elements in sorted order. 
It performs all the operations as performed by Set in STL in O(logN) complexity. 

In addition to that, the following two operations are also performed in O(logN) complexity:

order_of_key (K): Number of items strictly smaller than K.

find_by_order(k): Kth element in a Set (counting from zero).

The find_by_order() function accepts a key, say K, as an argument and returns 
the iterator to the Kth largest element in the Set.

Examples:

Considering a Set S = {1, 5, 6, 17, 88}, 
s.find_by_order(0): Returns the 0th largest element, i.e. the minimum element, i.e. 1.
s.find_by_order(2): Returns the 2nd largest element, i.e. 6.

Note: If K >= N, where N is the size of the set, then the function returns either 0 or in 
some compilers, the iterator to the smallest element. 
*/

// C++ program to implement find_by_order()
// for Policy Based Data Structures

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

// Declaring Ordered Set
typedef tree<int, null_type, less<int>, rb_tree_tag,
		tree_order_statistics_node_update>
	pbds;

int main()
{

	int arr[] = {1, 5, 6, 17, 88};
	int n = sizeof(arr)/sizeof(arr[0]);

	pbds S;

	for (int i = 0; i < n; i++) {
		S.insert(arr[i]);
	}

	// Returns iterator to 0-th
	// largest element in the set
	cout << *S.find_by_order(0) << " ";

	// Returns iterator to 2-nd
	// largest element in the set
	cout << *S.find_by_order(2);

	return 0;
}

/*
Output: 1 6

Time Complexity: O(n*log(n))
Auxiliary Space: O(n)
*/