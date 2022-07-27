/*
std::count()

	returns number of occurrences of an element in a given range.

	Returns the number of elements in the range [first, last) that compare equal to val.

-------

// Returns count of occurrences of value in range [begin, end]

	int count(Iterator first, Iterator last, T &val)

	first, last : Input iterators to the initial and final positions of the sequence of elements.

	val : Value to match

-------

Complexity It’s order of complexity O(n).

Compares once each element with the particular value.
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Version1 {
public:
	void countTest() {
		int arr[] = { 3, 2, 1, 3, 3, 5, 3 };
		int n = sizeof(arr) / sizeof(arr[0]);
		cout << "Number of times 3 appears : "
		     << count(arr, arr + n, 3);
	}
};

// Number of times 3 appears : 4

class Version2 {
public:
	void countTest() {
		vector<int> vect{ 3, 2, 1, 3, 3, 5, 3 };
		cout << "Number of times 3 appears : "
		     << count(vect.begin(), vect.end(), 3);
	}
};

// Number of times 3 appears : 4

class Version3 {
public:
	void countTest() {
		string str = "geeksforgeeks";
		cout << "Number of times 'e' appears : "
		     << count(str.begin(), str.end(), 'e');
	}
};

// Number of times 'e' appears : 4

int main() {
	Version1 obj1;
	Version2 obj2;
	Version3 obj3;
	obj1.countTest();
	cout << "\n-------\n";
	obj2.countTest();
	cout << "\n-------\n";
	obj3.countTest();
	cout << "\n-------\n";
}