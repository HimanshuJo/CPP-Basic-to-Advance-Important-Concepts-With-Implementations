/*
std::search:

	is defined in the header file <algorithm> and used to find out the presence of a
	subsequence satisfying a condition (equality if no such predicate is defined)
	with respect to another sequence.

	It searches the sequence [first1, last1) for the first occurrence of the
	subsequence defined by [first2, last2), and returns an iterator to its first element of
	the occurrence, or last1 if no occurrences are found.

	It compares the elements in both ranges sequentially using operator== (version 1) or
	based on any given predicate (version 2).

	A subsequence of [first1, last1) is considered a match only when this is true for all the
	elements of [first2, last2).

	Finally, std::search returns the first of such occurrences.

-------

It can be used in either of the two versions, as depicted below :

	For comparing elements using == :

		ForwardIterator1 search (ForwardIterator1 first1, ForwardIterator1 last1,

		ForwardIterator2 first2, ForwardIterator2 last2);

	-------

	first1:

		Forward iterator to beginning of first container to be searched into.

	last1:

		Forward iterator to end of first container to be searched into.

	first2:

		Forward iterator to the beginning of the subsequence of second container to be searched for.

	last2:

		Forward iterator to the ending of the subsequence of second container to be searched for.

-------

Returns:

	an iterator to the first element of the first occurrence of [first2, last2)
	in [first1, last1), or last1 if no occurrences are found.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Version1 {
public:
	void searchTest() {
		int i, j;

		// Declaring the sequence to be searched into
		vector<int> v1 = { 1, 2, 3, 4, 5, 6, 7 };

		// Declaring the subsequence to be searched for
		vector<int> v2 = { 3, 4, 5 };

		// Declaring an iterator for storing the returning pointer
		vector<int>::iterator i1;

		// Using std::search and storing the result in
		// iterator i1
		i1 = std::search(v1.begin(), v1.end(), v2.begin(), v2.end());

		// checking if iterator i1 contains end pointer of v1 or not
		if (i1 != v1.end()) {
			cout << "vector2 is present at index " << (i1 - v1.begin());
		} else {
			cout << "vector2 is not present in vector1";
		}
	}
};

/*
Output:

vector2 is present at index 2
*/

/*
For comparison based on a predicate (or condition) :

	ForwardIterator1 search (ForwardIterator1 first1, ForwardIterator1 last1,
	                         ForwardIterator2 first2, ForwardIterator2 last2,
	                         BinaryPredicate pred);

	All the arguments are same as previous template, just one more argument is added

	pred:

		Binary function that accepts two elements as arguments
		(one of each of the two containers, in the same order), and returns a value convertible to bool.

		The returned value indicates whether the elements are considered to match in the
		context of this function.

		The function shall not modify any of its arguments.

		This can either be a function pointer or a function object.

	Returns:

		an iterator, to the first element of the first occurrence of [first2, last2)
		satisfying a predicate, in [first1, last1), or last1 if no occurrences are found.
*/

class Version2 {
public:

	struct custComp {
		bool operator()(const int i, const int j) {
			if (i > j) {
				return 1;
			} else {
				return 0;
			}
		}
	};

	void searchTest() {
		int i, j;

		// Declaring the sequence to be searched into
		vector<int> v1 = { 1, 2, 3, 4, 5, 6, 7 };

		// Declaring the subsequence to be compared to based
		// on predicate
		vector<int> v2 = { 3, 4, 5 };

		// Declaring an iterator for storing the returning pointer
		vector<int>::iterator i1;

		// Using std::search and storing the result in
		// iterator i1 based on predicate pred
		i1 = std::search(v1.begin(), v1.end(), v2.begin(), v2.end(), custComp());

		// checking if iterator i1 contains end pointer of v1 or not
		if (i1 != v1.end()) {
			cout << "vector1 elements are greater than vector2 starting "
			     << "from position " << (i1 - v1.begin());
		} else {
			cout << "vector1 elements are not greater than vector2 "
			     << "elements consecutively.";
		}
	}
};

/*
Output:

vector1 elements are greater than vector2 starting from position 3
*/

int main() {
	Version1 obj1;
	Version2 obj2;
	obj1.searchTest();
	cout << "\n-------\n";
	obj2.searchTest();
	cout << "\n-------\n";
}