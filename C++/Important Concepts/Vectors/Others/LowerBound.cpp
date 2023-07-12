/*
The lower_bound() method in C++:

	is used to return an iterator pointing to the first element in the range [first, last) 
	which has a value not less than val(or >=val). 

	This means that the function returns the index of the next smallest number 
	just greater than or equal to that number. 
	
	If there are multiple values that are equal to val, lower_bound() returns the index of the first such value.

	The elements in the range shall already be sorted or at least partitioned with respect to val.

-------

Templates: 

Syntax 1: 
ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, const T& val);

Syntax 2: 
ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, const T& val, Compare comp);

-------

Parameters: The above methods accept the following parameters.  

	first, last: 

		The range used is [first, last), which contains all the elements between first and last, 
		including the element pointed by first but not the element pointed by last.

	val:

		Value of the lower bound to be searched for in the range.

	comp: 

		Binary function that accepts two arguments (the first of the type pointed by ForwardIterator, 
		and the second, always val), and returns a value convertible to bool. 

		The function shall not modify any of its arguments. 

		This can either be a function pointer or a function object.

-------

Return Value: 

	An iterator to the lower bound of val in the range. 

	If all the elements in the range compare less than val, the function returns last(size of the vector). 

	If all the elements in the range are larger than val, the function returns a pointer to the first element. 

-------

Input: 10 20 30 40 50
Output: lower_bound for element 30 at index 2

Input: 10 20 30 40 50
Output: lower_bound for element 35 at index 3

Input: 10 20 30 40 50
Output: lower_bound for element 55 at index 5

Input: 10 20 30 30 30 40 50
Output: lower_bound for element 30 at index 2
*/

#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
	vector<int>v{10, 20, 30, 30, 30, 40, 50};
	for(unsigned int i=0; i<v.size(); i++)
		cout<<" "<<v[i];
	cout<<"\n";
	int num1=40;
	vector<int>::iterator low1, low2, low3;
	low1=lower_bound(v.begin(), v.end(), num1);
	low2=lower_bound(v.begin(), v.end(), 35);
	low3=lower_bound(v.begin(), v.end(), 55);
	cout<<"\nlower_bound for element 30 at position : "<<(low1 - v.begin());
	cout<<"\nlower_bound for element 35 at position : "<<(low2 - v.begin());
	cout<<"\nlower_bound for element 55 at position : "<<(low3 - v.begin());
	cout<<"\nNum elements less than "<<num1<<" : "<<(low1-v.begin());
	cout<<"\nNum elements greater than equal to "<<num1<<" : "<<((v.size()-(low1-v.begin()))-1);
	return 0;
}

/*
Output:

lower_bound for element 30 at position : 5
lower_bound for element 35 at position : 5
lower_bound for element 55 at position : 7
Num elements less than 40 : 5
Num elements greater than equal to 40 : 1

-------

Time Complexity:  

	The number of comparisons performed is logarithmic. 

	Therefore, the time complexity of the above approach is O(logN), where N = size. (last – first)
*/