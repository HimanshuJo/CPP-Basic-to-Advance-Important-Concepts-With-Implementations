/*
upper_bound():

	is a standard library function in C++ defined in the header.

	It returns an iterator pointing to the first element in the range [first, last)
	that is greater than value, or last if no such element is found.

	The elements in the range shall already be sorted or at least partitioned with respect to val.

-------

Syntax 1:

	ForwardIterator upper_bound (ForwardIterator first, ForwardIterator last, const T& val);

Syntax 2:

	ForwardIterator upper_bound (ForwardIterator first, ForwardIterator last, const T& val, Compare comp);

-------

first, last:

	The range used is [first, last), which contains all the elements between first and last,
	including the element pointed by first but not the element pointed by last.

-------

val:

	Value of the upper bound to search for in the range.

comp:

	Binary function that accepts two arguments (the first of the type pointed by ForwardIterator, and the second, always val),
	and returns a value convertible to bool.

	The function shall not modify any of its arguments.

	This can either be a function pointer or a function object.

Return type:

	An iterator to the upper bound of val in the range.

	If all the element in the range compare less than val, the function returns last.

-------

Examples :

Input : 10 20 30 30 40 50
Output : upper_bound for element 30 is at index 4

Input : 10 20 30 40 50
Output : upper_bound for element 45 is at index 4

Input : 10 20 30 40 50
Output : upper_bound for element 60 is at index 5
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int>v{10, 20, 30, 40, 50};
	int num1=40, num2=40;
	for(int i=0; i<v.size(); i++)
		cout<<" "<<v[i];
	cout<<"\n";
	vector<int>::iterator upper1, upper2;
	upper1=upper_bound(v.begin(), v.end(), num1);
	upper2=upper_bound(v.begin(), v.end(), 45);
	cout<<"\nupper_bound for element 35 is at position : "<<(upper1-v.begin());
	cout<<"\nupper_bound for element 45 is at position : "<<(upper2-v.begin());
	cout<<"\nNum elements less than the element "<<num1<<" : "<<(upper1-v.begin());
	cout<<"\nNum elements greater than the element "<<num1<<" : "<<(v.size()-(upper1-v.begin()));
	return 0;
}

/*
Output:

10 20 30 40 50

upper_bound for element 35 is at position : 4
upper_bound for element 45 is at position : 4
Num elements less than the element 40 : 4
Num elements greater than the element 40 : 1
*/