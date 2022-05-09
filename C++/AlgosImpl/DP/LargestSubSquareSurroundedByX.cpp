/*
Given a matrix where every element is either ‘O’ or ‘X’, find the largest subsquare 
surrounded by ‘X’.
In the below article, it is assumed that the given matrix is also a square matrix.
The code given below can be easily extended for rectangular matrices.

Input: mat[N][N] = { {'X', 'O', 'X', 'X', 'X'},
                     {'X', 'X', 'X', 'X', 'X'},
                     {'X', 'X', 'O', 'X', 'O'},
                     {'X', 'X', 'X', 'X', 'X'},
                     {'X', 'X', 'X', 'O', 'O'},
                    };
Output: 3
The square submatrix starting at (1, 1) is the largest
submatrix surrounded by 'X'

Input: mat[M][N] = { {'X', 'O', 'X', 'X', 'X', 'X'},
                     {'X', 'O', 'X', 'X', 'O', 'X'},
                     {'X', 'X', 'X', 'O', 'O', 'X'},
                     {'X', 'X', 'X', 'X', 'X', 'X'},
                     {'X', 'X', 'X', 'O', 'X', 'O'},
                    };
Output: 4
The square submatrix starting at (0, 2) is the largest
submatrix surrounded by 'X'

A Simple Solution is to consider every square submatrix and check whether is has all corner 
edges filled with ‘X’.
The time complexity of this solution is O(N^4).

We can solve this problem in O(N^3) time using extra space.
The idea is to create two auxiliary arrays hor[N][N] and ver[N][N].
The value stored in hor[i][j] is the number of horizontal continuous ‘X’ characters till 
mat[i][j] in mat[][].
Similarly, the value stored in ver[i][j] is the number of vertical continuous ‘X’ 
characters till mat[i][j] in mat[][].

Example:

mat[6][6] =  X  O  X  X  X  X
             X  O  X  X  O  X
             X  X  X  O  O  X
             O  X  X  X  X  X
             X  X  X  O  X  O
             O  O  X  O  O  O

hor[6][6] = 1  0  1  2  3  4
            1  0  1  2  0  1
            1  2  3  0  0  1
            0  1  2  3  4  5
            1  2  3  0  1  0
            0  0  1  0  0  0

ver[6][6] = 1  0  1  1  1  1
            2  0  2  2  0  2
            3  1  3  0  0  3
            0  2  4  1  1  4
            1  3  5  0  2  0
            0  0  6  0  0  0

Once we have filled values in hor[][] and ver[][], we start from the bottommost-rightmost 
corner of matrix and move toward the
leftmost-topmost in row by row manner. For every visited entry mat[i][j], we compare 
the values of hor[i][j] and ver[i][j],
and pick the smaller of two as we need a square. Let the smaller of two be ‘small’.
After picking smaller of two, we check if both ver[][] and hor[][] for left and up 
edges respectively.
If they have entries for the same, then we found a subsquare. Otherwise we try for small-1.
*/

/*
Optimized approach:

A more optimized solution would be to pre-compute the number of contiguous 
‘X’ horizontally and vertically,
in a matrix of pairs named dp. Now  for every entry of dp we have a pair (int, int) 
which denotes the
maximum contiguous ‘X’ till that point, i.e.

dp[i][j].first denotes contiguous ‘X’ taken horizontally till that point.
dp[i][j].second denotes contiguous ‘X’ taken vertically till that point.
Now, a square can be formed with dp[i][j] as the bottom right corner, having sides 
atmost of length, min(dp[i][j].first, dp[i][j].second)

So, we make another matrix maxside, which will denote the maximum square side formed 
having the bottom
right corner as arr[i][j]. We’ll try to get some intuition from the properties of a 
square, i.e. all the sides of the square are equal.

Let’s store maximum value that can be obtained, as val = min(dp[i][j].first, dp[i][j].second).

From point (i, j), we traverse back horizontally by distance Val,
and check if the minimum vertical contiguous ‘X’ till that point is equal to Val.

Similarly, we traverse back vertically by distance Val,
and check if the minimum horizontal contiguous ‘X’ till that point is equal to Val?

Here we are making use of the fact that all sides of square are equal.

Input Matrix:

X  O  X  X  X  X

X  O  X  X  O  X

X  X  X  O  O  X

O  X  X  X  X  X

X  X  X  O  X  O

O  O  X  O  O  O

Value of matrix dp:

(1,1) (0,0) (1,1) (2,7) (3,1) (4,1)

(1,2) (0,0) (1,2) (2,8) (0,0) (1,2)

(1,3) (2,1) (3,3) (0,0) (0,0) (1,3)

(0,0) (1,2) (2,4) (3,1) (4,1) (5,4)

(1,1) (2,3) (3,5) (0,0) (1,2) (0,0)

(0,0) (0,0) (1,6) (0,0) (0,0) (0,0)
*/

// A C++ program to find the largest subsquare
// surrounded by 'X' in a given matrix of 'O' and 'X'
#include <bits/stdc++.h>
using namespace std;

// Size of given matrix is N X N
#define N 7

int maximumSubSquare(int arr[][N])
{
    pair<int, int> dp[7][7];
    int maxside[7][7];

    // Initialize maxside with 0
    memset(maxside, 0, sizeof(maxside));

    int x = 0, y = 0;

    // Fill the dp matrix horizontally.
    // for contiguous 'X' increment the value of x,
    // otherwise make it 0
    for (int i = 0; i < N; i++)
    {
        x = 0;
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] == 'X')
                x += 1;
            else
                x = 0;
            dp[i][j].first = x;
        }
    }

    cout << "After Horizontal: " << endl;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << (dp[i][j].first) << "," << (dp[i][j].second) << " ";
        }
        cout << endl;
    }

    cout << "-------\n";


    // Fill the dp matrix vertically.
    // For contiguous 'X' increment the value of y,
    // otherwise make it 0
    for (int i = 0; i < N; i++)
    {
        y = 0;
        for (int j = 0; j < N; j++)
        {
            if (arr[j][i] == 'X')
                y += 1;
            else
                y = 0;
            dp[j][i].second = y;
        }
    }

    cout << "After Vertical: " << endl;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << (dp[i][j].first) << "," << (dp[i][j].second) << " ";
        }
        cout << endl;
    }


    cout << "-------\n";

    // Now check , for every value of (i, j) if sub-square
    // is possible,
    // traverse back horizontally by value val, and check if
    // vertical contiguous
    // 'X'enfing at (i , j-val+1) is greater than equal to
    // val.
    // Similarly, check if traversing back vertically, the
    // horizontal contiguous
    // 'X'ending at (i-val+1, j) is greater than equal to
    // val.
    int maxval = 0, val = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            val = min(dp[i][j].first, dp[i][j].second);
            if (dp[i][j - val + 1].second >= val && dp[i - val + 1][j].first >= val)
                maxside[i][j] = val;
            else
                maxside[i][j] = 0;

            // store the final answer in maxval
            maxval = max(maxval, maxside[i][j]);
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << (dp[i][j].first) << "," << (dp[i][j].second) << " ";
        }
        cout << endl;
    }

    // return the final answe.
    return maxval;
}

// Driver code
int main()
{
    int mat[][N] = {
        { 'X', 'O', 'X', 'X', 'X', 'X' },
        { 'X', 'O', 'X', 'X', 'O', 'X' },
        { 'X', 'X', 'X', 'O', 'O', 'X' },
        { 'O', 'X', 'X', 'X', 'X', 'X' },
        { 'X', 'X', 'X', 'O', 'X', 'O' },
        { 'O', 'O', 'X', 'O', 'O', 'O' },
    };

    int mat2[][N] = {
        { 'O', 'O', 'O', 'O', 'O', 'O', 'X' },
        { 'O', 'O', 'O', 'X', 'X', 'X', 'X' },
        { 'O', 'O', 'O', 'X', 'X', 'X', 'X' },
        { 'O', 'O', 'O', 'X', 'X', 'X', 'X' },
        { 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
        { 'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        { 'O', 'O', 'O', 'O', 'O', 'O', 'O'}
    };

    // Function call
    cout << maximumSubSquare(mat2);
    return 0;
}
