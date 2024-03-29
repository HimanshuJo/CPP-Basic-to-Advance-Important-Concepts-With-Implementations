/*
map::cbegin() is a built-in function in C++ STL which returns a 
constant iterator referring to the first element in the map container. 

Since map container contains the element in an ordered way, cbegin() 
will point to that element that will come first according to the container’s 
sorting criterion.

Syntax:

map_name.cbegin()
Parameters: The function does not accept any parameter.

Return Value: The function returns a constant iterator referring to the 
first element in the map container.

-------

map::cend() is a built-in function in C++ STL which returns a 
constant iterator pointing to the theoretical element that follows 
last element in the multimap. 

Since map container contains the element in an ordered way, cend() 
will point to that follows the last element according to the container’s 
sorting criterion.

Syntax:

map_name.cend()

Parameters: The function does not accept any parameter.

Return Value: The function returns a constant iterator pointing to the 
theoretical element that follows the last element in the map.
*/

// C++ program to illustrate
// the map::cbegin() and map::cend() function
#include <bits/stdc++.h>
using namespace std;

int main()
{

	// initialize container
	map<int, int> mp;

	// insert elements in random order
	mp.insert({ 2, 30 });
	mp.insert({ 1, 40 });
	mp.insert({ 3, 60 });
	mp.insert({ 4, 20 });
	mp.insert({ 5, 50 });

	auto ite = mp.cbegin();

	cout << "The first element is: ";
	cout << "{" << ite->first << ", "
		 << ite->second << "}\n";

	// prints the elements
	cout << "\nThe map is : \n";
	cout << "KEY\tELEMENT\n";
	for (auto itr = mp.cbegin(); itr != mp.cend(); ++itr) {
		cout << itr->first
			 << '\t' << itr->second << '\n';
	}
	return 0;
}

/*
Output:

The first element is: {1, 40}

The map is : 
KEY    ELEMENT
1    40
2    30
3    60
4    20
5    50
*/