/*
Priority queues are a type of container adapters, specifically designed such that 
the first element of the queue is the greatest of all elements in the queue and elements 
are in non increasing order (hence we can see that each element of the queue has a 
priority {fixed order}).

-------

How to create a min heap for priority queue? 

// Syntax to create a min heap for priority queue 
priority_queue <int, vector<int>, greater<int>> g = gq; 
*/
/*
// C++ program to demonstrate min heap
#include <iostream>
#include <queue>

using namespace std;

void showpq(priority_queue<int, vector<int>, greater<int>> gq)
{
	priority_queue<int, vector<int>, greater<int>> g = gq;
	while (!g.empty()) {
		cout << '\t' << g.top();
		g.pop();
	}
	cout << '\n';
}

int main()
{
	priority_queue<int, vector<int>, greater<int>> gquiz;
	gquiz.push(10);
	gquiz.push(30);
	gquiz.push(20);
	gquiz.push(5);
	gquiz.push(1);

	cout << "The priority queue gquiz is : ";
	showpq(gquiz);

	cout << "\ngquiz.size() : " << gquiz.size();
	cout << "\ngquiz.top() : " << gquiz.top();

	cout << "\ngquiz.pop() : ";
	gquiz.pop();
	showpq(gquiz);

	return 0;
}
*/
/*
Output: 

The priority queue gquiz is: 1 5 10 20 30

gquiz.size(): 5
gquiz.top(): 1
gquiz.pop(): 5 10 20 30
*/
/*
Methods of priority queue are: 

    priority_queue::empty() in C++ STL

    	empty() function returns whether the queue is empty.

    -------

    priority_queue::size() in C++ STL

    	size() function returns the size of the queue.

    -------

    priority_queue::top() in C++ STL

    	Returns a reference to the top most element of the queue

    -------

    priority_queue::push() in C++ STL

    	push(g) function adds the element ‘g’ at the end of the queue.

    -------

    priority_queue::pop() in C++ STL:

    	pop() function deletes the first element of the queue.

    -------

    priority_queue::swap() in C++ STL:

    	This function is used to swap the contents of one priority queue with another 
    		priority queue of same type and size.

    -------

    priority_queue::emplace() in C++ STL

    	This function is used to insert a new element into the priority queue container, 
    	
    	the new element is added to the top of the priority queue.

    -------

    priority_queue value_type in C++ STL

    	Represents the type of object stored as an element in a priority_queue. 

    	It acts as a synonym for the template parameter.
*/

// Note that by default C++ creates a max-heap
// for priority queue
#include <iostream>
#include <queue>

using namespace std;

void showpq(priority_queue<int> gq)
{
	priority_queue<int> g = gq;
	while (!g.empty()) {
		cout << '\t' << g.top();
		g.pop();
	}
	cout << '\n';
}

int main()
{
	priority_queue<int> gquiz;
	gquiz.push(10);
	gquiz.push(30);
	gquiz.push(20);
	gquiz.push(5);
	gquiz.push(1);

	cout << "The priority queue gquiz is : ";
	showpq(gquiz);

	cout << "\ngquiz.size() : " << gquiz.size();
	cout << "\ngquiz.top() : " << gquiz.top();

	cout << "\ngquiz.pop() : ";
	gquiz.pop();
	showpq(gquiz);

	return 0;
}

/*
Output: 

The priority queue gquiz is: 30 20 10 5 1

gquiz.size(): 5
gquiz.top(): 30
gquiz.pop(): 20 10 5 1
*/