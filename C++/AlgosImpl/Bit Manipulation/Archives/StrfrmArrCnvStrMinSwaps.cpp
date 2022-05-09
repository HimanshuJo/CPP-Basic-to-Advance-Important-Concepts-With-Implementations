/*
Find the string from an array that can be converted to a string S with minimum number of swaps

Given a string S and an array of strings arr[] of length N and M respectively,
the task is to find the string from the given array to the string S by swapping
minimum number of characters. If no string can be converted to S, print -1.

Examples:

Input: S = “abc”, arr[] = {“acb”, “xyz”}
Output: acb
Explanation:
The string “acb” can be converted to “abc” by swapping 1 pair of characters “acb”  -> “abc“.
The string”xyz” cannot be converted to “abc”.

Input: S = “abc”, arr[] = {“ab”, “xy”, “cb”}
Output: -1
*/
/*
Approach:

	The problem can be solved by searching for anagrams of S from the given array of
	strings and then, for every such string, find the minimum number of character swaps
	required to convert the string to S.
*/
/*
Follow the steps below to solve the problem:
	
	Traverse the array of strings and for each string present in the array,
		check if it is an anagram of S or not.

	If no such string is found, then print -1.

	Otherwise, find the minimum number of swaps required to convert the current string into S,
		by iterating over the characters of the current string, say S1.

	Store the position of characters in S1 in 26 lists.

		For each character in S1, append its index to its corresponding list, i.e.,
		list 0 stores all positions of the character ‘a’.

		Similarly, list 1 stores all positions of ‘b’ and so on.

	After complete traversal of the string S1,
	iterate over the characters of the string S in reverse and for each character,
	say S[j], get its respective index from the given array of lists, say temp.

	Now, the optimal move is to move the character at the last index in temp to the index j.

	This is optimal because:

		Characters are being moved in every move. Hence, no move is being wasted.

		The last index in temp would be closer to j than other indices as the string is
		being iterated in reverse.

		To optimize, a Fenwick tree can be used to determine the modified positions of
			characters in S1, in case of any swaps.
*/
/*
Illustration:

Suppose, S = “abca”, S1 = “cbaa”
Below is the list generated for S1:
List for ‘a’ = {2, 3}
List for ‘b’ = {1}
List for ‘c’ = {0}
Iterate over the characters of S, in reverse, by initializing minMoves with 0.

S = “abca”, i = 3
Remove last index from list corresponding to ‘a’, i.e. 3.
Search the Fenwick Tree to check if there are any indices to the left of this index
in the Fenwick Tree or not.
Since the tree is empty now, no need to shift this index.
Add index 3 to the Fenwick Tree.
minMoves += (i – index) = (3 – 3). Therefore, minMoves = 0

S = “abca”, i = 2
Remove the last index from list corresponding to ‘c’, i.e. 0.
Search the Fenwick Tree to check if there are any indices to the left of this index
in the Fenwick Tree or not.
Since the only index in the tree is 3, and it is to the right of 0, no need to shift this index.
Add index 0 to the Fenwick Tree.
minMoves += (i – index) = (2 – 0). Therefore, minMoves = 2

S = “abca”, i = 1
Remove last index from list corresponding to ‘b’, i.e. 1.
Search the Fenwick Tree to check if there are any indices to the left of this index
in the Fenwick Tree or not.
The count obtained is 1, i.e. there was one character to the left of index 1,
which is now, towards it’s right.
Add index 1 to the Fenwick Tree.
new index = 1 – leftShit = 1 – 1 = 0
minMoves += (i – new index) = 1 – 0 = 3

S = “abca”, i= 0
Remove last index from list corresponding to ‘a’, i.e. 2.
Search the Fenwick Tree to check if there are any indices to the left of this index in the Fenwick tree or not.
The count obtained is 2, i.e. there were two characters to the left of index 2, which is now, towards its right.
Add index 2 to the Fenwick Tree.
new index = 2 – leftShit = 2 – 2 = 0
minMoves+= (i-new index) = 0 – 0 = 3
*/

#include <bits/stdc++.h>
using namespace std;

// Function to check is two
// strings are anagrams
bool checkIsAnagram(vector<int> charCountS, vector<int> charCountS1)
{
	for (int i = 0; i < 26; i++)
	{
		if (charCountS[i] != charCountS1[i])
			return false;
	}
	return true;
}

// Function to return the frequency of
// characters in the array of strings
vector<int> getCharCount(string S)
{
	vector<int> charCount(26, 0);

	for (char i : S)
		charCount[i - 'a']++;

	return charCount;
}

// Function to return the count of
// indices to the left of this index
int get(vector<int> &fenwickTree, int index)
{
	int leftShift = 0;
	leftShift += fenwickTree[index];

	while (index > 0)
	{
		index -= (-index) & index;
		leftShift += fenwickTree[index];
	}
	return leftShift;
}

// Update function of Fenwick Tree
void update(vector<int> &fenwickTree, int index)
{
	while (index < fenwickTree.size())
	{
		fenwickTree[index]++;
		index += (-index) & index;
	}
}

// Function to get all positions of
// characters present in the string S1
vector<vector<int>> getPositions(string S)
{

	//@SuppressWarnings("unchecked")
	vector<vector<int>> charPositions(26);

	for (int i = 0; i < S.size(); i++)
		charPositions[i - 'a'].push_back(i);

	return charPositions;
}

// Function to return the minimum number
// of swaps required to convert S1 to S
int findMinMoves(string S, string S1)
{

	// cout<<"run\n";
	// Stores number of swaps
	int minMoves = 0;

	// Initialize Fenwick Tree
	vector<int> fenwickTree(S.size() + 1);

	// Get all positions of characters
	// present in the string S1
	vector<int> charPositions[26];
	int j = 0;
	for (char i : S1)
	{
		charPositions[i - 'a'].push_back(j);
		j++;
	}

	// cout<<charPositions[2].size()<<endl;

	// Traverse the given string in reverse
	for (int i = S.size() - 1; i >= 0; i--)
	{

		// Get the list corresponding
		// to character S[i]
		vector<int> temp = charPositions[S[i] - 'a'];

		// Size of the list
		int size = temp.size() - 1;

		// Get and remove last
		// indices from the list
		int index = temp[size] + 1;
		charPositions[S[i] - 'a'].pop_back();

		//temp.pop_back();

		// Count of indices to
		// the left of this index
		int leftShift = get(fenwickTree, index);

		// Update Fenwick T ree
		update(fenwickTree, index);

		// Shift the index to it's left
		index -= leftShift;

		// Update moves
		minMoves += abs(i - index + 1);
	}

	// Return moves
	return minMoves;
}

// Function to find anagram of S
// requiring minimum number of swaps
string getBeststring(string S, vector<string> group)
{

	// Initialize variables
	bool isAnagram = false;
	string beststring = "";
	int minMoves = INT_MAX;

	// Count frequency of characters in S
	vector<int> charCountS = getCharCount(S);

	// Traverse the array of strings
	for (string S1 : group)
	{

		// Count frequency of characters in S1
		vector<int> charCountS1 = getCharCount(S1);

		// cout<<S1<<endl;
		// Check if S1 is anagram of S
		bool anagram = checkIsAnagram(charCountS, charCountS1);
		//cout<<anagram<<endl;

		// If not an anagram of S
		if (anagram == 0)
			continue;

		isAnagram = true;

		// Count swaps required
		// to convert S to S1
		int moves = findMinMoves(S, S1);
		//cout<<moves<<endl;

		// Count minimum number of swaps
		if (moves < minMoves)
		{
			minMoves = moves;
			beststring = S1;
		}
	}

	// If no anagram is found, print -1
	return (isAnagram) ? beststring : "-1";
}

// Driver Code
int main()
{
	// Given string
	string S = "abcdac";

	// Given array of strings
	vector<string> arr = { "cbdaca",
	                       "abcacd",
	                       "abcdef"
	                     };

	string beststring = getBeststring(S, arr);
	cout << (beststring) << endl;
}
