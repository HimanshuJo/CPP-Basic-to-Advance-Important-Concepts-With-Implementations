/*
Lazy Propagation – An optimization to make range updates faster

	When there are many updates and updates are done on a range, we can postpone some updates
	(avoid recursive calls in update) and do those updates only when required.

	Please remember that a node in segment tree stores or represents result of a query for a range of indexes.

	And if this node’s range lies within the update operation range, then all descendants of the node must also be updated.

	For example consider the node with value 27 in above diagram, this node stores sum of values at indexes from 3 to 5.

	If our update query is for range 2 to 5, then we need to update this node and all descendants of this node.

	With Lazy propagation, we update only node with value 27 and postpone updates to its children by storing this update
	information in separate nodes called lazy nodes or values. We create an array lazy[] which represents lazy node.

	Size of lazy[] is same as array that represents segment tree, which is tree[] in below code.

	The idea is to initialize all elements of lazy[] as 0.

	A value 0 in lazy[i] indicates that there are no pending updates on node i in segment tree.

	A non-zero value of lazy[i] means that this amount needs to be added to node i in segment tree before making
	any query to the node.

	Below is modified update method.

	// To update segment tree for change in array
	// values at array indexes from us to ue.

	updateRange(us, ue)
	1) If current segment tree node has any pending
	   update, then first add that pending update to
	   current node.

	2) If current node's range lies completely in
	   update query range.

		....a) Update current node
		....b) Postpone updates to children by setting
		       lazy value for children nodes.

	3) If current node's range overlaps with update
	   range, follow the same approach as above simple
	   update.

		...a) Recur for left and right children.
		...b) Update current node using results of left
		      and right calls.

	Is there any change in Query Function also?

		Since we have changed update to postpone its operations, there may be problems
		if a query is made to a node that is yet to be updated.

		So we need to update our query method also which is getSumUtil in previous post.
		The getSumUtil() now first checks if there is a pending update and if there is, then updates the node.

		Once it makes sure that pending update is done, it works same as the previous getSumUtil()
*/

#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;
#define MAX 1000

int tree[MAX] = {0};
int lazy[MAX] = {0};

void updateRangeUtil(int si, int ss, int se, int us,
                     int ue, int diff)
{
	if (lazy[si] != 0)
	{
		tree[si] += (se - ss + 1) * lazy[si];
		if (ss != se)
		{
			lazy[si * 2 + 1] += lazy[si];
			lazy[si * 2 + 2] += lazy[si];
		}
		lazy[si] = 0;
	}
	if (ss > se || ss > ue || se < us)
		return ;
	if (ss >= us && se <= ue)
	{
		tree[si] += (se - ss + 1) * diff;
		if (ss != se)
		{
			lazy[si * 2 + 1] += diff;
			lazy[si * 2 + 2] += diff;
		}
		return;
	}
	int mid = (ss + se) / 2;
	updateRangeUtil(si * 2 + 1, ss, mid, us, ue, diff);
	updateRangeUtil(si * 2 + 2, mid + 1, se, us, ue, diff);
	tree[si] = tree[si * 2 + 1] + tree[si * 2 + 2];
}

void updateRange(int n, int us, int ue, int diff)
{
	updateRangeUtil(0, 0, n - 1, us, ue, diff);
}

int getSumUtil(int ss, int se, int qs, int qe, int si)
{
	if (lazy[si] != 0)
	{
		tree[si] += (se - ss + 1) * lazy[si];
		if (ss != se)
		{
			lazy[si * 2 + 1] += lazy[si];
			lazy[si * 2 + 2] += lazy[si];
		}
		lazy[si] = 0;
	}
	if (ss > se || ss > qe || se < qs)
		return 0;
	if (ss >= qs && se <= qe)
		return tree[si];
	int mid = (ss + se) / 2;
	return getSumUtil(ss, mid, qs, qe, 2 * si + 1) +
	       getSumUtil(mid + 1, se, qs, qe, 2 * si + 2);
}

int getSum(int n, int qs, int qe)
{
	if (qs < 0 || qe > n - 1 || qs > qe)
	{
		printf("Invalid Input");
		return -1;
	}

	return getSumUtil(0, n - 1, qs, qe, 0);
}

void constructSTUtil(vector<int>&arr, int ss, int se, int si)
{
	if (ss > se)
		return ;
	if (ss == se)
	{
		tree[si] = arr[ss];
		return;
	}
	int mid = (ss + se) / 2;
	constructSTUtil(arr, ss, mid, si * 2 + 1);
	constructSTUtil(arr, mid + 1, se, si * 2 + 2);
	tree[si] = tree[si * 2 + 1] + tree[si * 2 + 2];
}

void constructST(vector<int>&arr, int n)
{
	constructSTUtil(arr, 0, n - 1, 0);
}

int main()
{
	vector<int>arr = {1, 3, 5, 7, 9, 11};
	int n = arr.size();
	constructST(arr, n);
	printf("Sum of values in given range = %d\n",
	       getSum(n, 0, 1));
	updateRange(n, 0, 1, 2);
	printf("Updated sum of values in given range = %d\n",
	       getSum( n, 0, 1));
	return 0;
}
