/*
Given a binary tree (not a binary search tree) and two values say n1 and n2,
we have to write a program to find all the least common ancestor

Definition of Lowest Common Ancestor or LCA (wiki):

	Let T be a rooted tree.

	The lowest common ancestor between two nodes n1 and n2 is defined as the lowest node in T that has both
		n1 and n2 as descendants (where we allow a node to be descendant of itself)

	The LCA of n1 and n2 in T is the shared ancestor of n1 and n2 that is located farthest from the root.

	Computation of lowest common ancestor may be useful, for instance, as part of a procedure for determining
		the distance between pairs of nodes in a tree

		The distance from n1 and n2 can be computed as

			the distance from the root to n1,

			plus the distance from root to n2,

			minus twice the distance from the root to their LCA

		-------

		=> dist(n1, n2) = dist(r, n1) + dist(r, n2) - 2 * dist(r, LCA(n1, n2))

-------

Method 1: By Sorting root to n1 and root to n2 paths

	Following a simple O(n) algorithm to find the LCA of n1 and n2

		a. Find a path from the root to n1, and store it in a vector or an array

		b. Find a path from the root to n2 and store it in a vector or an array

		c. Traverse both the paths till the values in the arrays are same

			Return the common element just before the mismatch
*/
/*
import java.util.ArrayList;
import java.util.List;

class Node {
	int data;
	Node left, right;

	Node(int value) {
		data = value;
		left = right = null;
	}
}

public class BinaryTreeLCA_SOl1 {
	Node root;
	private List<Integer> path1 = new ArrayList<>();
	private List<Integer> path2 = new ArrayList<>();

	// Finding paths from root node to a given node of the tree
	int findLCA(int n1, int n2) {
		path1.clear();
		path2.clear();
		return findLCAInternal(root, n1, n2);
	}

	private int findLCAInternal(Node root, int n1, int n2) {
		if (!findPath(root, n1, path1) || !findPath(root, n2, path2)) {
			System.out.println((path1.size() > 0) ? "n1 is present" : "n1 is missing");
			System.out.println((path2.size() > 0) ? "n2 is present" : "n2 is missing");
			return -1;
		}
		for (int i = 0; i < path1.size() && i < path2.size(); ++i) {
			if (!path1.get(i).equals(path2.get(i))) {
				break;
			}
		}
		return path1.get(i - 1);
	}

	// Finding the paths from root node to given node of the tree
	// It stores path in a path vector, and return true if path exists otherwise false
	private boolean findPath(Node root, int n, List<Integer> path) {
		// Base case
		if (root == null) {
			return false;
		}

		// Stores the node. The node will be remove if not in the path from the root to n
		path.add(root.data);
		if (root.data == n) {
			return true;
		}
		if (root.left != null && findPath(root.left, n, path)) {
			return true;
		}
		if (root.right != null && findPath(root.right, n, path)) {
			return true;
		}
		// If not present in subtree rooted with root, remove root from path[] and return false
		path.remove(path.size() - 1);
		return false;
	}
}

-------

Time Complexity: The time complexity of the above solution is O(n).

	The tree is traversed twice, and then path arrays are compared.

*/

// C++ Program for Lowest Common Ancestor in a Binary Tree
// A O(n) solution to find LCA of two given values n1 and n2
#include <iostream>
#include <vector>

using namespace std;

// A Binary Tree node
struct Node
{
	int key;
	struct Node *left, *right;
};

// Utility function creates a new binary tree node with given key
Node * newNode(int k)
{
	Node *temp = new Node;
	temp->key = k;
	temp->left = temp->right = NULL;
	return temp;
}

// Finds the path from root node to given root of the tree, Stores the
// path in a vector path[], returns true if path exists otherwise false
bool findPath(Node *root, vector<int> &path, int k)
{
	// base case
	if (root == NULL) return false;

	// Store this node in path vector. The node will be removed if
	// not in path from root to k
	path.push_back(root->key);

	// See if the k is same as root's key
	if (root->key == k)
		return true;

	// Check if k is found in left or right sub-tree
	if ( (root->left && findPath(root->left, path, k)) ||
	        (root->right && findPath(root->right, path, k)) )
		return true;

	// If not present in subtree rooted with root, remove root from
	// path[] and return false
	path.pop_back();
	return false;
}

// Returns LCA if node n1, n2 are present in the given binary tree,
// otherwise return -1
int findLCA(Node *root, int n1, int n2)
{
	// to store paths to n1 and n2 from the root
	vector<int> path1, path2;

	// Find paths from root to n1 and root to n1. If either n1 or n2
	// is not present, return -1
	if (!findPath(root, path1, n1) || !findPath(root, path2, n2))
		return -1;

	/* Compare the paths to get the first different value */
	int i;
	for (i = 0; i < path1.size() && i < path2.size() ; i++)
		if (path1[i] != path2[i])
			break;
	return path1[i - 1];
}

int main()
{
	// Let us create the Binary Tree shown in above diagram.
	Node * root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	cout << "LCA(4, 5) = " << findLCA(root, 4, 5);
	cout << "nLCA(4, 6) = " << findLCA(root, 4, 6);
	cout << "nLCA(3, 4) = " << findLCA(root, 3, 4);
	cout << "nLCA(2, 4) = " << findLCA(root, 2, 4);
	return 0;
}

/*
Output:

LCA(4, 5) = 2
LCA(4, 6) = 1
LCA(3, 4) = 1
LCA(2, 4) = 2
*/