/*
The set::find:

	is a built-in function in C++ STL which returns an iterator to the element which is searched in the set container.

	If the element is not found, then the iterator points to the position just after the last element in the set. 

-------

Syntax: 
 
	set_name.find(element) 

Parameters: 

	The function accepts one mandatory parameter element which specifies the element to be searched in the set container. 

Return Value: 

	The function returns an iterator which points to the element which is searched in the set container.

	If the element is not found, then the iterator points to the position just after the last element in the set.

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

	// iterator pointing to
	// position where 3 is
	auto pos = s.find(3);
	cout << "The set elements after 3 are: ";
	for (auto it = pos; it != s.end(); it++)
		cout << *it << " ";

	return 0;
}

/*
Output:

The set elements after 3 are: 3 4 5

*/

/*
Time Complexity: The time complexity of set_name.find( key ) is O( log N ).

If the element is not found in the set, the (*pos) will point to 'last index of the set + 1'
*/

/*
#include<bits/stdc++.h>
using namespace std;

int main(){
	set<int>s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(8);
	s.insert(5);
	auto pos=s.find(13);
	cout<<"pos here: "<<(*pos)<<endl;
	for (auto it=pos; it!=s.end(); ++it){
		cout<<(*it)<<" ";
	}
	return 0;
}

Output:

pos here: 5
*/