// Find max in a given range, seg tree 0 based indexing
#include<bits/stdc++.h>
using namespace std;

int getMid(int s, int e) {
	return s + (e - s) / 2;
}

int constructSTUtil(int arr[], int ss, int se, int* st, int si) {
	if (ss == se) {
		st[si] = arr[ss];
		return arr[ss];
	}
	int mid = getMid(ss, se);
	st[si] = max(constructSTUtil(arr, ss, mid, st, si * 2 + 1),
	             constructSTUtil(arr, mid + 1, se, st, si * 2 + 2));
	return st[si];
}

int* constructST(int arr[], int n) {
	int x = (int)(ceil(log2(n)));
	int maxSize = 2 * (int)pow(2, x) - 1;
	int* st = new int[maxSize];
	constructSTUtil(arr, 0, n - 1, st, 0);
	return st;
}

int maxUtil(int* st, int ss, int se, int qs, int qe, int node) {
	if (qs <= ss && qe >= se) {
		return st[node];
	}
	if (se < qs || ss > qe) {
		return -1;
	}
	int mid = getMid(ss, se);
	return max(maxUtil(st, ss, mid, qs, qe, 2 * node + 1),
	           maxUtil(st, mid + 1, se, qs, qe, 2 * node + 2));
}

int getMax(int* st, int n, int qs, int qe) {
	if (qs < 0 || qe > n - 1 || qs > qe) {
		cout << "Invalid\n";
		return -1;
	}
	return maxUtil(st, 0, n - 1, qs, qe, 0);
}

void update(int arr[], int* st, int ss, int se, int index, int value, int node) {
	if (index < ss || index > se) {
		cout << "Invalid\n";
		return;
	}
	if (ss == se) {
		arr[index] = value;
		st[index] = value;
	} else {
		int mid = getMid(ss, se);
		if (index >= ss && index <= mid) {
			update(arr, st, ss, mid, index, value, 2 * node + 1);
		} else {
			update(arr, st, mid + 1, se, index, value, 2 * node + 2);
		}
		st[node] = max(st[2 * node + 1], st[2 * node + 2]);
	}
	return;
}

int main() {
	int arr[] {1, 2, 3, 4, 5, 6, 7};
	int qs = 0;
	int qe = 2;
	int* st = constructST(arr, sizeof(arr) / sizeof(arr[0]));
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << getMax(st, n, qs, qe);
}