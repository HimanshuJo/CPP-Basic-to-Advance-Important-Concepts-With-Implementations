// Print unique rows in a given Binary matrix
/*
Given a binary matrix, print all unique rows of the given matrix.

Example:

Input:
        {0, 1, 0, 0, 1}
        {1, 0, 1, 1, 0}
        {0, 1, 0, 0, 1}
        {1, 1, 1, 0, 0}

Output:
    0 1 0 0 1
    1 0 1 1 0
    1 1 1 0 0

Explanation:
The rows are r1={0, 1, 0, 0, 1},
r2={1, 0, 1, 1, 0}, r3={0, 1, 0, 0, 1},
r4={1, 1, 1, 0, 0}, As r1 = r3, remove r3
and print the other rows.

Input:
        {0, 1, 0}
        {1, 0, 1}
        {0, 1, 0}

Output:
   0 1 0
   1 0 1

Explanation:
The rows are r1={0, 1, 0},
r2={1, 0, 1}, r3={0, 1, 0} As r1 = r3,
remove r3 and print the other rows.
*/
/*
Trie data structure can be used to solve the above problem.
Trie is an efficient information retrieval data structure.

Using Trie, search complexities can be brought to an optimal limit (key length).
If we store keys in the binary search tree, a well-balanced BST will need time
proportional to M * log N, where M is maximum string length and N is the number of
keys in the tree. Using Trie, we can search the key in O(M) time.

However, the penalty is on Trie storage requirements.
Note: This method will lead to Integer Overflow if the number of columns is large.

Approach:
Since the matrix is boolean, a variant of Trie data structure can be used where
each node will be having two children one for 0 and other for 1.

Insert each row in the Trie. If the row is already there, don’t print the row.
If the row is not there in Trie, insert it in Trie and print it.

Algorithm:

Create a Trie where rows can be stored.
Traverse through the matrix and insert the row into the Trie.
Trie cannot store duplicate entries so the duplicates will be removed
Traverse the Trie and print the rows.
*/

/*
Complexity Analysis: 

Time complexity: O( ROW x COL ). 
To traverse the matrix and insert in the trie the time complexity is O(ROW x COL). 
This method has better time complexity. 
Also, the relative order of rows is maintained while printing but it takes a toll on space.
Auxiliary Space: O( ROW x COL ). 
To store the Trie O(ROW x COL) space complexity is needed.
*/

// Given a binary matrix of M X N of integers,
// you need to return only unique rows of binary array
#include <bits/stdc++.h>
using namespace std;
#define ROW 4
#define COL 5

// A Trie node
class Node
{
public:
	bool isEndOfCol;
	Node *child[2]; // Only two children needed for 0 and 1
} ;


// A utility function to allocate memory
// for a new Trie node
Node* newNode()
{
	Node* temp = new Node();
	temp->isEndOfCol = 0;
	temp->child[0] = temp->child[1] = NULL;
	return temp;
}

// Inserts a new matrix row to Trie.
// If row is already present,
// then returns 0, otherwise insets the row and
// return 1
bool insert(Node** root, int (*Matrix)[COL], int row, int col )
{
	// base case
	if (*root == NULL)
		*root = newNode();

	// Recur if there are more entries in this row
	if (col < COL)
		return insert (&((*root)->child[Matrix[row][col]]), Matrix, row, col + 1);

	else // If all entries of this row are processed
	{
		// unique row found, return 1
		if (!((*root)->isEndOfCol))
			return (*root)->isEndOfCol = 1;

		// duplicate row found, return 0
		return 0;
	}
}

// A utility function to print a row
void printRow(int(*Matrix)[COL], int row)
{
	int i;
	for (i = 0; i < COL; ++i)
		cout << Matrix[row][i] << " ";
	cout << endl;
}

// The main function that prints
// all unique rows in a given matrix.
void findUniqueRows(int (*Matrix)[COL])
{
	Node* root = NULL; // create an empty Trie
	int i;

	// Iterate through all rows
	for (i = 0; i < ROW; ++i)

		// insert row to TRIE
		if (insert(&root, Matrix, i, 0))

			// unique row found, print it
			printRow(Matrix, i);
}

int main()
{
	int Matrix[ROW][COL] = {{0, 1, 0, 0, 1},
		{1, 0, 1, 1, 0},
		{0, 1, 0, 0, 1},
		{1, 0, 1, 0, 0}
	};

	findUniqueRows(Matrix);

	return 0;
}
