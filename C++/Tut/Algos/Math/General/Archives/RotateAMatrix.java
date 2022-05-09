/*
Rotate a matrix by 90 degree in clockwise direction without using any extra space

	Given a square matrix, turn it by 90 degrees in a clockwise direction without using any extra space.

	Examples:

	Input:
	1 2 3
	4 5 6
	7 8 9

	Output:
	7 4 1
	8 5 2
	9 6 3

	Input:
	1 2
	3 4

	Output:
	3 1
	4 2

	-------

	 An N x N matrix will have floor(N/2) square cycles.

		For example, a 3 X 3 matrix will have 1 cycle.

			The cycle is formed by its 1st row, last column, last row, and 1st column.

		For each square cycle, we swap the elements involved with the corresponding
		cell in the matrix in the clockwise direction. We just need a temporary variable for this.

	-------

	Let size of row and column be 3.

	During first iteration –

		a[i][j] = Element at first index (leftmost corner top)= 1.
		a[j][n-1-i]= Rightmost corner top Element = 3.
		a[n-1-i][n-1-j] = Rightmost corner bottom element = 9.
		a[n-1-j][i] = Leftmost corner bottom element = 7.

		Move these elements in the clockwise direction.

	During second iteration –
		a[i][j] = 2.
		a[j][n-1-j] = 6.
		a[n-1-i][n-1-j] = 8.
		a[n-1-j][i] = 4.

		Similarly, move these elements in the clockwise direction.

*/
/*
class GFG {

	static int N = 4;

	static void rotate90Clockwise(int a[][]) {
		for (int i = 0; i < N / 2; i++) {
			for (int j = i; j < N - i - 1; j++) {

				// Swap elements of each cycle
				// in clockwise direction
				int temp = a[i][j];
				a[i][j] = a[N - 1 - j][i];
				a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
				a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
				a[j][N - 1 - i] = temp;
			}
		}
	}

	static void printMatrix(int arr[][]) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				System.out.print( arr[i][j] + " ");
			System.out.println();
		}
	}

	public static void main (String[] args) {
		int arr[][] = { { 1, 2, 3, 4 },
			{ 5, 6, 7, 8 },
			{ 9, 10, 11, 12 },
			{ 13, 14, 15, 16 }
		};
		rotate90Clockwise(arr);
		printMatrix(arr);
	}
}
*/
/*

Rotate a matrix by 90 degree without using any extra space in anti-clockwise direction

	Input:
		1  2  3
		4  5  6
		7  8  9

	Output:

		3  6  9
		2  5  8
		1  4  7

	Rotated the input matrix by
	90 degrees in anti-clockwise direction.

	Input:
		1  2  3  4
		5  6  7  8
		9 10 11 12
		13 14 15 16

	Output:
		4  8 12 16
		3  7 11 15
		2  6 10 14
		1  5  9 13

	Rotated the input matrix by
	90 degrees in anti-clockwise direction.

	-------

	Algorithm:

		To solve the given problem there are two tasks.

		1st is finding the 'transpose' and second is 'reversing' the columns without using extra space

    		A transpose of a matrix is when the matrix is flipped over its diagonal,
    		i.e the row index of an element becomes the column index and vice versa.

    		So to find the transpose interchange the elements at position (i, j) with (j, i).

    			Run two loops, the outer loop from 0 to row count and inner loop from 0 to index of the outer loop.

    		To reverse the column of the transposed matrix,

    			run two nested loops, the outer loop from 0 to column count and inner loop
    			from 0 to row count/2, interchange elements at (i, j) with (i, row[count-1-j]),
    			where i and j are indices of inner and outer loop respectively.

*/

import java.util.*;

class GFG {

	// After transpose we swap elements of
	// column one by one for finding left
	// rotation of matrix by 90 degree
	static void reverseColumns(int arr[][]) {
		for (int i = 0; i < arr[0].length; i++)
			for (int j = 0, k = arr[0].length - 1; j < k; j++, k--) {
				int temp = arr[j][i];
				arr[j][i] = arr[k][i];
				arr[k][i] = temp;
			}
	}

	// Function for do transpose of matrix
	static void transpose(int arr[][]) {
		for (int i = 0; i < arr.length; i++)
			for (int j = i; j < arr[0].length; j++) {
				int temp = arr[j][i];
				arr[j][i] = arr[i][j];
				arr[i][j] = temp;
			}
	}

	// Function for print matrix
	static void printMatrix(int arr[][]) {
		for (int i = 0; i < arr.length; i++) {
			for (int j = 0; j < arr[0].length; j++)
				System.out.print(arr[i][j] + " ");
			System.out.println("");
		}
	}

	// Function to anticlockwise rotate
	// matrix by 90 degree
	static void rotate90(int arr[][]) {
		transpose(arr);
		reverseColumns(arr);
	}

	public static void main(String[] args) {
		int arr[][] = { { 1, 2, 3, 4 },
						{ 5, 6, 7, 8 },
						{ 9, 10, 11, 12 },
						{ 13, 14, 15, 16 }
		};

		rotate90(arr);
		printMatrix(arr);
	}
}