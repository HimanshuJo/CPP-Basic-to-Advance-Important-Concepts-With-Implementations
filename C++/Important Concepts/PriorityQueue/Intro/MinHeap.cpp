/*
In C++ STL, there is priority_queue that can directly be used to implement Max Heap	
*/

// Priority Queue is by default a Max heap
#include<bits/stdc++.h>
using namespace std;

int main() {
	priority_queue<int> pq;
	pq.push(5);
	pq.push(1);
	pq.push(10);
	pq.push(30);
	pq.push(20);
	while (pq.empty() == false) {
		cout << pq.top() << " ";
		pq.pop();
	}
	return 0;
}
/*
Output

	30 20 10 5 1
*/
/*
Since elements are printed in descending order, we have a max heap by default.
 
How to implement Min Heap? 
	
	priority_queue supports a constructor that requires two extra arguments to make it min-heap. 
 

		priority_queue <Type, vector<Type>, ComparisonType > min_heap;

The third parameter, ‘Comparison Type’ can either be a function or factor (aka function object)
that must have bool as return-type and must have 2 arguments.
*/
/*
// use of priority_queue to implement min heap
#include<bits/stdc++.h>
using namespace std;

int main() {
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(5);
	pq.push(1);
	pq.push(10);
	pq.push(30);
	pq.push(20);
	while (pq.empty() == false) {
		cout << pq.top() << " ";
		pq.pop();
	}
	return 0;
}
*/
/*
Output : 

	1 5 10 20 30 
*/
/*
Another method for making min-heap using default priority_queue:

	This is frequently used in Competitive Programming. 

	We first multiply all elements with (-1). 
		Then we create a max heap (max heap is the default for priority queue). 

		When we access the data and want to print it we simply multiply those elements 
		with (-1) again.
*/
/*
// C++ Program to implement min heap
// using default priority_queue(max-heap)

#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int arr[] = { 25, 7, 9, 15, 20, 36, 50 };

	// default priority_queue using max-heap
	priority_queue<int> pq;

	// size of the array
	int n = sizeof(arr) / sizeof(arr[0]);

	// multiply -1 with all elements while
	// inserting
	for (int i = 0; i < n; i++) {
		pq.push((-1) * arr[i]);
	}

	// multiply all elements with -1 while
	// retrive the elements
	while (!pq.empty()) {
		cout << (pq.top()) * (-1) << " ";
		pq.pop();
	}

	return 0;
}

Output

	7 9 15 20 25 36 50 
*/
/*
How to make a min-heap of user-defined class? 

	Let us consider below example where we build a min-heap of 2 D points ordered by X-axis.

*/
/*
// priority_queue to implement min heap for user defined class
#include <bits/stdc++.h>
using namespace std;

class Point
{
    int x;
    int y;

public:
    Point(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
    int getX() const
    {
        return x;
    }
    int getY() const
    {
        return y;
    }
};

class MyComparator
{
public:
    int operator()(const Point &p1, const Point &p2)
    {
        return p1.getX() > p2.getX();
    }
};

int main()
{
    // creating priority queue of points (order by x coordinates)
    // MyComparator optional and additional argument
    priority_queue<Point, vector<Point>, MyComparator> pq;
    pq.push(Point(10, 2));
    pq.push(Point(2, 1));
    pq.push(Point(1, 5));
    while (pq.empty() == false)
    {
        Point p = pq.top();
        cout << "(" << p.getX() << ", " << p.getY() << ")";
        cout << "\n";
        pq.pop();
    }
    return 0;
}

Output : 

	(1, 5)
	(2, 1)
	(10, 2)
*/