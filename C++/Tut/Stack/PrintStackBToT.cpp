/*
Given a stack s, the task is to print the elements of the stack from 
bottom to top, such that the elements are still present in the stack 
without their order being changed in the stack.

Examples: 

Input : 
       
       
|   4    |
|   3    |
|   2    |
|   1    |
|________|

Output: 1 2 3 4

Approach 1 (Recursion): 

	The idea is to pop the element of the stack and call the 
    recursive function PrintStack. 

	Once the stack becomes empty start printing the element which 
    was popped last and the last element that was popped was the 
    bottom-most element. 

	Thus, elements will be printed from bottom to top. 

	Now push back the element that was printed, this will preserve 
    the order of the elements in the stack.
*/

#include <bits/stdc++.h>
using namespace std;

// Recursive function to print stack elements
// from bottom to top without changing
// their order
void PrintStack1(stack<int> s)
{
	// If stack is empty then return
	if (s.empty())
		return;
	
	int x = s.top();

	// Pop the top element of the stack
	s.pop();

	// Recursively call the function PrintStack
	PrintStack1(s);

	// Print the stack element starting
	// from the bottom
	cout << x << " ";

	// Push the same element onto the stack
	// to preserve the order
	s.push(x);
}

// Function to print stack elements
// from bottom to top without changing
// their order using another temporary stack
void PrintStack2(stack<int> s)
{
	stack<int> temp;
	while (s.empty() == false)
	{
		temp.push(s.top());
		s.pop();
	}

	while (temp.empty() == false)
	{
		int t = temp.top();
		cout << t << " ";
		temp.pop();

		// To restore contents of
		// the original stack.
		s.push(t);
	}
}

int main()
{
	stack<int> s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	PrintStack1(s);

    cout<<endl;

    stack<int> s2;
	s2.push(1);
	s2.push(2);
	s2.push(3);
	s2.push(4);

	PrintStack2(s2);

	return 0;
}

/*
Output: 

1 2 3 4

-------

1 2 3 4
*/
