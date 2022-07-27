/*
Array:

	An array is a collection of items stored at contiguous memory locations.

	It is to store multiple items of the same type together.

	This makes it easier to get access to the elements stored in it by the position of each element.

-------

Vectors:

	Vectors are known as dynamic arrays with the ability to resize itself automatically when an
		element is inserted or deleted, with their storage being handled automatically by the container automatically.

-------

Array of Vectors:

	Therefore, array of vectors is two dimensional array with fixed number of rows
		where each row is vector of variable length.

	Each index of array stores a vector which can be traversed and accessed using iterators.

		vector <data_type> V[size];
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> v[5];

void insertionInArrayOfVectors()
{
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			v[i].push_back(j);
		}
	}
}

void printElements()
{
	for (int i = 0; i < 5; i++) {
		cout << "Elements at index " << i << ": ";
		for (auto it = v[i].begin(); it != v[i].end(); it++) {
			// (*it) is used to get the
			// value at iterator is
			// pointing
			cout << *it << ' ';
		}
		cout << endl;
	}
}

void arrayOfVectors()
{
	insertionInArrayOfVectors();
	printElements();
}

int main()
{
	arrayOfVectors();
	return 0;
}

/*
Output:

	Elements at index 0: 1 2 3 4
	Elements at index 1: 2 3 4
	Elements at index 2: 3 4
	Elements at index 3: 4
	Elements at index 4:
*/