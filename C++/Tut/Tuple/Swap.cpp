// swap() :- The swap(), swaps the elements of the two different tuples.

#include<iostream>
#include<tuple>
using namespace std;

int main()
{
	tuple <int, char, float> tup1(20, 'g', 17.5);
	tuple <int, char, float> tup2(10, 'f', 15.5);
	cout << "The first tuple elements before swapping are : ";
	cout <<  get<0>(tup1) << " " << get<1>(tup1) << " "
	     <<  get<2>(tup1) << endl;
	cout << "The second tuple elements before swapping are : ";
	cout <<  get<0>(tup2) << " " << get<1>(tup2) << " "
	     <<  get<2>(tup2) << endl;

	// Swapping tup1 values with tup2
	tup1.swap(tup2);

	cout << "The first tuple elements after swapping are : ";
	cout <<  get<0>(tup1) << " " << get<1>(tup1) << " "
	     <<  get<2>(tup1) << endl;
	cout << "The second tuple elements after swapping are : ";
	cout <<  get<0>(tup2) << " " << get<1>(tup2) << " "
	     <<  get<2>(tup2) << endl;

	return 0;
}

/*
Output:

The first tuple elements before swapping are : 20 g 17.5
The second tuple elements before swapping are : 10 f 15.5
The first tuple elements after swapping are : 10 f 15.5
The second tuple elements after swapping are : 20 g 17.5
*/