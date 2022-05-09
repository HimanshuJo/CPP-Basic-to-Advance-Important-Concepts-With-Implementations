// Number of possible Triangles in a Cartesian coordinate system
/*
Given n points in a Cartesian coordinate system. Count the number of triangles formed.

Examples:
Input  : point[] = {(0, 0), (1, 1), (2, 0), (2, 2)
Output : 3
Three triangles can be formed from above points.

A simple solution is to check if the determinant of the three points selected is non-zero or not. T
he following determinant gives the area of a Triangle (Also known as Cramer’s rule).
Area of the triangle with corners at (x1, y1), (x2, y2) and (x3, y3) is given by:

{Area = \pm \frac{1}{2}\begin{bmatrix} x1 & y1 & 1\\ x2 & y2 & 1\\ x3 & y3 & 1 \end{bmatrix}}

We can solve this by taking all possible combination of 3 points and finding the determinant
*/

// C++ program to count number of triangles that can
// be formed with given points in 2D
#include <bits/stdc++.h>
using namespace std;

// A point in 2D
struct Point
{
	int x, y;
};

// Returns determinant value of three points in 2D
int det(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return x1 * (y2 - y3) - y1 * (x2 - x3) + 1 * (x2 * y3 - y2 * x3);
}

// Returns count of possible triangles with given array
// of points in 2D.
int countPoints(Point arr[], int n)
{
	int result = 0; // Initialize result

	// Consider all triplets of points given in inputs
	// Increment the result when determinant of a triplet
	// is not 0.
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			for (int k = j + 1; k < n; k++)
				if (det(arr[i].x, arr[i].y, arr[j].x, arr[j].y, arr[k].x, arr[k].y))
					result++;

	return result;
}

// Time Complexity: O(n^{3})
int main()
{
	Point arr[] = {{0, 0}, {1, 1}, {2, 0}, {2, 2}};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << countPoints(arr, n);
	return 0;
}
