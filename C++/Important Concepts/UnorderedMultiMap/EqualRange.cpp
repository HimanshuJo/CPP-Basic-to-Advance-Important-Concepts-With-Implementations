/*
unordered_multimap::equal_range() is a built-in function in C++ STL which returns the 
range in which all the element’s key is equal to a key. 

	It returns a pair of iterators where the first is an iterator pointing to the lower 
    bound of the range and second is an iterator pointing to the upper bound of the range. 

	If there is no element equal to a given value in the container, 
    then it returns a pair where both lower and upper bound points to the position past 
    the end of the container or unordered_multimap.end().

Syntax:

	unordered_multimap_name.equal_range(k)

Parameters: 
	
	The function accepts a mandatory parameter k. The range returned will have the elements 
    with key k.

Return Value: 

	It returns a pair of iterators.
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	unordered_multimap<int, int> sample;
	sample.insert({ 1, 2 });
	sample.insert({ 1, 2 });
	sample.insert({ 2, 3 });
	sample.insert({ 3, 4 });
	sample.insert({ 2, 6 });

	// iterator of pairs pointing to range
	// which includes 1 and print by iterating in range
	auto itr = sample.equal_range(1);
	cout << "Elements with Key 1: ";
	for (auto it = itr.first; it != itr.second; it++) {
		cout << it->second << " ";
	}

	cout << endl;

	// iterator of pairs pointing to range
	// which includes 2 and print by iterating in range
	itr = sample.equal_range(2);
	cout << "Elements with Key 2: ";
	for (auto it = itr.first; it != itr.second; it++) {
		cout << it->second << " ";
	}
	
	cout << endl;
	itr = sample.equal_range(3);
	cout << "Elements with Key 3: ";
	for (auto it = itr.first; it != itr.second; it++) {
		cout << it->second << " ";
	}
	return 0;
}

/*
Output:

Elements with Key 1: 2 2 
Elements with Key 2: 6 3 
Elements with Key 3: 4 
*/