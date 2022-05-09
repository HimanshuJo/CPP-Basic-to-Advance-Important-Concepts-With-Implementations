#include<bits/stdc++.h>
#define sz(x) x.size()
#define pb push_back
#define left 2*i+1
#define right 2*i+2
using namespace std;

const int maxn = 100005;
vector<vector<int>>gr(maxn);
vector<int>E;
vector<int>L;
int H[maxn];
int level[maxn];

int st[5 * maxn];

void add_edge(int u, int v) {
	gr[u].pb(v);
	gr[v].pb(u);
}

void leveling(int src) {
	for (int i = 0; i < sz(gr[src]); ++i) {
		int des = gr[src][i];
		if (!level[des]) {
			level[des] = level[src] + 1;
			leveling(des);
		}
	}
}

bool visited[maxn];

void dfs(int src) {
	E.pb(src);
	visited[src] = 1;
	for (int i = 0; i < sz(gr[src]); ++i) {
		int des = gr[src][i];
		if (!visited[des]) {
			dfs(des);
			E.pb(src);
		}
	}
}

void fill_L(int n) {
	for (int i = 0; i < sz(E); ++i) {
		L.pb(level[E[i]]);
	}
}

void fill_H(int n) {
	for (int i = 0; i <= n; ++i) {
		H[i] = -1;
		for (int i = 0; i < sz(E); ++i) {
			if (H[E[i]] == -1) {
				H[E[i]] = i;
			}
		}
	}
}

int RMQ(int ss, int se, int qs, int qe, int i) {
	if (ss > se) return -1;
	if (se < qs || qe < ss) return -1;
	if (qs <= ss && se <= qe) return st[i];
	int mid = (ss + se) >> 1;
	int st = RMQ(ss, mid, qs, qe, left);
	int en = RMQ(mid + 1, se, qs, qe, right);
	if (st != -1 && en != -1) {
		if (L[st] < L[en]) {
			return st;
		}
		return en;
	} else if (st != -1) return st;
	else if (en != -1) return en;
	return 0;
}

void segTreeConstruct(int ss, int se, int i) {
	if (ss > se) return;
	if (ss == se) {
		st[i] = ss;
		return;
	}
	int mid = (ss + se) >> 1;
	segTreeConstruct(ss, mid, left);
	segTreeConstruct(mid + 1, se, right);
	if (L[st[left]] < L[st[right]]) {
		st[i] = st[left];
	} else st[i] = st[right];
}

int LCA(int x, int y) {
	if (H[x] > H[y])
		swap(x, y);
	return E[RMQ(0, sz(L) - 1, H[x], H[y], 0)];
}

int main() {
	ios::sync_with_stdio(0);

	// n=number of nodes in the tree
	// q=number of queries to answer
	int n = 15, q = 5;

	// making the tree
	/*
	                 1
	               / | \
	              2  3  4
	                 |   \
	                 5    6
	               / |  \
	             8   7    9 (right of 5)
	               / | \   | \
	             10 11 12 13 14
	                    |
	                    15
	*/
	add_edge(1, 2);
	add_edge(1, 3);
	add_edge(1, 4);
	add_edge(3, 5);
	add_edge(4, 6);
	add_edge(5, 7);
	add_edge(5, 8);
	add_edge(5, 9);
	add_edge(7, 10);
	add_edge(7, 11);
	add_edge(7, 12);
	add_edge(9, 13);
	add_edge(9, 14);
	add_edge(12, 15);

	level[1] = 1;
	leveling(1);

	dfs(1);

	fill_L(n);

	fill_H(n);

	segTreeConstruct(0, sz(L) - 1, 0);

	cout << LCA(10, 15) << endl;
	cout << LCA(11, 14) << endl;

	return 0;
}