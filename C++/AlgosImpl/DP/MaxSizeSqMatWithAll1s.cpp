// Given a binary matrix, find out the maximum size square sub-matrix with all 1s.
/*
Algorithm:
Let the given binary matrix be M[R][C].
The idea of the algorithm is to construct an auxiliary size matrix S[][] in which 
each entry S[i][j] represents
size of the square sub-matrix with all 1s including M[i][j] where M[i][j] is the rightmost 
and bottom-most entry in sub-matrix.

1) Construct a sum matrix S[R][C] for the given M[R][C].
     a)    Copy first row and first columns as it is from M[][] to S[][]
     b)    For other entries, use following expressions to construct S[][]
         If M[i][j] is 1 then S[i][j] = min(S[i][j-1], S[i-1][j], S[i-1][j-1]) + 1
         Else If M[i][j] is 0
                 S[i][j] = 0
2) Find the maximum entry in S[R][C]
3) Using the value and coordinates of maximum entry in S[i], print
   sub-matrix of M[][]
*/

// Time Complexity: O(m*n) where m is number of rows and n is number of columns in the given matrix.
// Auxiliary Space: O(m*n) where m is number of rows and n is number of columns in the given matrix.

// C++ code for Maximum size square
// sub-matrix with all 1s
#include <bits/stdc++.h>
#define bool int
#define R 6
#define C 5
using namespace std;

void printMaxSubSquare(bool M[R][C])
{
	int i, j;
	int S[R][C];
	int max_of_s, max_i, max_j;

	/* Set first column of S[][]*/
	for (i = 0; i < R; i++)
		S[i][0] = M[i][0];

	/* Set first row of S[][]*/
	for (j = 0; j < C; j++)
		S[0][j] = M[0][j];

	/* Construct other entries of S[][]*/
	for (i = 1; i < R; i++)
	{
		for (j = 1; j < C; j++)
		{
			if (M[i][j] == 1)
				S[i][j] = min(S[i][j - 1], min(S[i - 1][j], S[i - 1][j - 1])) + 1;
			else
				S[i][j] = 0;
		}
	}

	/* Find the maximum entry, and indexes of maximum entry
		in S[][] */
	max_of_s = S[0][0]; max_i = 0; max_j = 0;
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			if (max_of_s < S[i][j])
			{
				max_of_s = S[i][j];
				max_i = i;
				max_j = j;
			}
		}
	}

	cout << "Maximum size sub-matrix is: \n";
	for (i = max_i; i > max_i - max_of_s; i--)
	{
		for (j = max_j; j > max_j - max_of_s; j--)
		{
			cout << M[i][j] << " ";
		}
		cout << "\n";
	}
}

// Brute Force Time: O((mn)^2)
/*
public class Solution {
    public int maximalSquare(char[][] matrix) {
        int rows = matrix.length, cols = rows > 0 ? matrix[0].length : 0;
        int maxsqlen = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    int sqlen = 1;
                    boolean flag = true;
                    while (sqlen + i < rows && sqlen + j < cols && flag) {
                        for (int k = j; k <= sqlen + j; k++) {
                            if (matrix[i + sqlen][k] == '0') {
                                flag = false;
                                break;
                            }
                        }
                        for (int k = i; k <= sqlen + i; k++) {
                            if (matrix[k][j + sqlen] == '0') {
                                flag = false;
                                break;
                            }
                        }
                        if (flag)
                            sqlen++;
                    }
                    if (maxsqlen < sqlen) {
                        maxsqlen = sqlen;
                    }
                }
            }
        }
        return maxsqlen * maxsqlen;
    }
}
*/


/* Driver code */
int main()
{
	bool M[R][C] = {{0, 1, 1, 0, 1},
		{1, 1, 0, 1, 0},
		{0, 1, 1, 1, 0},
		{1, 1, 1, 1, 0},
		{1, 1, 1, 1, 1},
		{0, 0, 0, 0, 0}
	};

	printMaxSubSquare(M);
}
