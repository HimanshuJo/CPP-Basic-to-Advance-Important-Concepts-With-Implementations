/*
set::insert:

	is a built-in function in C++ STL which insert elements in the set container or 
	inserts the elements from a position to another position in the set to a different set.

Syntax 1: 
 
	iterator set_name.insert(element)

Parameters: The function accepts a mandatory parameter element which is to be inserted in the set container. 

Return Value: The function returns an iterator pointing to the inserted element in the container.

Time Complexity: log(N) Where ‘N’ is the number of elements in the set 

*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
	set<int> s;
	s.insert(1);
	s.insert(4);
	s.insert(2);
	s.insert(5);
	s.insert(3);

	cout << "The elements in set are: ";
	for (auto it = s.begin(); it != s.end(); it++)
		cout << *it << " ";

	return 0;
}

/*
Output:

The elements in set are: 1 2 3 4 5
*/

/*

Syntax 2: 
 
	iterator set_name.insert(iterator position, element)

Parameters: The function accepts two parameter which are described below: 
 
	element: It specifies the element to be inserted in the set container.

	position: It does not specify the position where the insertion is to be done, 
			  it only points to a position from where the searching operation is to be started for 
			  insertion to make the process faster. 

			  The insertion is done according to the order which is followed by the set container.

-------

Syntax: 
 
	void set_name.insert(iterator position1, iterator position2)

Parameters: The function accepts two parameters position1 and position2 which specifies the range of elements.

			All the elements in the range [position1, last) are inserted in another set container. 

Return Value: No return type => void.
*/ 

/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
	set<int> s1;
	s1.insert(1);
	s1.insert(4);
	s1.insert(2);
	s1.insert(5);
	s1.insert(3);

	cout << "The elements in set1 are: ";
	for (auto it = s1.begin(); it != s1.end(); it++)
		cout << *it << " ";

	set<int> s2;

	// Function to insert one set to another
	// all elements from where 3 is to end is
	// inserted to set2
	s2.insert(s1.find(3), s1.end());

	cout << "\nThe elements in set2 are: ";
	for (auto it = s2.begin(); it != s2.end(); it++)
		cout << *it << " ";

	return 0;
}

Output:

The elements in set1 are: 1 2 3 4 5 
The elements in set2 are: 3 4 5
*/