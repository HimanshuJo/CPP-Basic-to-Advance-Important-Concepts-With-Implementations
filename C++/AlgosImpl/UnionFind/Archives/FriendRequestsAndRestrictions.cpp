#include<vector>
#include<iostream>
using namespace std;

/*
class UnionFind {
public:
	vector<int>parent;

	UnionFind(int n) {
		parent.resize(n + 1, -1);
	}

	int find(int x) {
		int root = x;
		while (parent[root] >= 0) {
			root = parent[root];
		}
		while (parent[x] >= 0) {
			int next = parent[x];
			parent[x] = root;
			x = next;
		}
		return root;
	}

	void doUnion(int x, int y) {
		int root1 = find(x);
		int root2 = find(y);
		if (root1 == root2) return;
		if (parent[root1] < parent[root2]) {
			parent[root1] += parent[root2];
			parent[root2] = root1;
		} else {
			parent[root2] += parent[root1];
			parent[root1] = root2;
		}
	}
};
*/

struct UnionFind{
	vector<int>parent, rank, size;
	int cntCmp;
	UnionFind(int n): parent(n+1), rank(n+1, 0), size(n+1, 1), cntCmp(n){
		for(int i=1; i<=n; ++i){
			parent[i]=i;
		}
	}

	int find(int i){
		return (parent[i]==i?i:(parent[i]=find(parent[i])));
	}

	bool same(int i, int j){
		return find(i)==find(j);
	}

	int getSize(int i){
		return size[find(i)];
	}

	int count(){
		return cntCmp;
	}

	void merge(int i, int j){
		if((i=find(i))==(j=find(j))) return;
		else cntCmp--;
		if(rank[i]>rank[j])
			swap(i, j);
		parent[i]=j;
		size[j]+=size[i];
		if(rank[i]==rank[j]) rank[j]++;
	}
};

class Solution {
public:
	vector<bool>frequests(int n, vector<vector<int>>&restrictions, vector<vector<int>>requests) {
		int m = requests.size();
		vector<bool>ans(m, 0);
		UnionFind unionFind(n);
		for (int i = 0; i < m; ++i) {
			UnionFind temp = unionFind;
			temp.merge(requests[i][0], requests[i][1]);
			bool flag = true;
			for (vector<int>&vec : restrictions) {
				if (temp.find(vec[0]) == temp.find(vec[1])) {
					flag = false;
					break;
				}
			}
			if (flag) {
				ans[i] = true;
				unionFind.merge(requests[i][0], requests[i][1]);
			}
		}
		return ans;
	}
};

int main(){
	vector<vector<int>>restrictions{{0,1}, {1,2}, {2,3}};
	vector<vector<int>>requests{{0,4}, {1,2}, {3,1}, {3,4}};
	Solution obj;
	vector<bool>ans=obj.frequests(5, restrictions, requests);
	for(bool b: ans){
		cout<<(b==1?"true ":"false ");
	}
}

// true false true false 