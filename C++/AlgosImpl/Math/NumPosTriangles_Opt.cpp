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

/*
Efficient Approach: Consider a point Z and find its slope with every other point.
Now, if two points are having the same slope with point Z that means the 3 points are collinear
and they cannot form a triangle. Hence, the number of triangles having Z as one of its points is the number of
ways of choosing 2 points from the remaining points and then subtracting the number of ways of choosing 2 points
from points having the same slope with Z. Since Z can be any point among N points, we have to iterate one more loop.
*/

// C++ implementation of the above approach
#include <bits/stdc++.h>
using namespace std;

// This function returns the required number
// of triangles
int countTriangles(pair<int, int> P[], int N)
{
	// Hash Map to store the frequency of
	// slope corresponding to a point (X, Y)
	map<pair<int, int>, int> mp;
	int ans = 0;

	// Iterate over all possible points
	for (int i = 0; i < N; i++) {
		mp.clear();

		// Calculate slope of all elements
		// with current element
		for (int j = i + 1; j < N; j++) {
			int X = P[i].first - P[j].first;
			int Y = P[i].second - P[j].second;

			// find the slope with reduced
			// fraction
			int g = __gcd(X, Y);
			X /= g;
			Y /= g;
			mp[ { X, Y }]++;
		}
		int num = N - (i + 1);

		// Total number of ways to form a triangle
		// having one point as current element
		ans += (num * (num - 1)) / 2;

		// Subtracting the total number of ways to
		// form a triangle having the same slope or are
		// collinear
		for (auto j : mp)
			ans -= (j.second * (j.second - 1)) / 2;
	}
	return ans;
}

int main()
{
	pair<int, int> P[] = { { 0, 0 }, { 2, 0 }, { 1, 1 }, { 2, 2 } };
	int N = sizeof(P) / sizeof(P[0]);
	cout << countTriangles(P, N) << endl;
	return 0;
}
