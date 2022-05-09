// D. Social Network
/*
William arrived at a conference dedicated to cryptocurrencies. 
Networking, meeting new people, and using friends' connections are essential to stay up to date with the latest news from 
the world of cryptocurrencies.

The conference has n participants, who are initially unfamiliar with each other. 
William can introduce any two people, a and b, who were not familiar before, to each other.

William has d conditions, i'th of which requires person xi to have a connection to person yi. 
Formally, two people x and y have a connection if there is such a 
chain p1=x,p2,p3,…,pk=y for which for all i from 1 to k−1 it's true that two people with numbers pi and pi+1 know each other.

For every i (1<=i<=d) William wants you to calculate the maximal number of acquaintances one person can have, 
assuming that William satisfied all conditions 
from 1 and up to and including i and performed exactly i introductions. 
The conditions are being checked after William performed i introductions. 
The answer for each i must be calculated independently. 

It means that when you compute an answer for i, you should assume that no two people have been introduced to each other yet.

input
10 8
1 2
2 3
3 4
1 4
6 7
8 9
8 10
1 4
output
1
2
3
4
5
5
6
8
*/

#include <bits/stdc++.h>
using namespace std;

struct DSU{
	vector<int>parent, rank, size;
	int cntCmp;
	DSU(int n): parent(n+1), rank(n+1, 0), size(n+1, 1), cntCmp(n){
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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, d;
	cin>>n>>d;
	DSU dsu(n);
	int x=0;
	for(int i=0; i<d; ++i){
		int u, v;
		cin>>u>>v;
		if(dsu.same(u, v)) x++;
		else dsu.merge(u, v);
		vector<bool>vis(n+1, false);
		vector<int>vec;
		for(int i=1; i<n+1; ++i){
			if(!vis[dsu.find(i)]){
				vec.push_back(dsu.getSize(i));
				vis[dsu.find(i)]=true;
			}
		}
		sort(vec.begin(), vec.end());
		int m=vec.size();
		vector<bool>vis2(m, false);
		int ans=0;
		int cnt=1+x;
		for(int i_=m-1; i_>=0&&cnt>0; --i_){
			cnt--;
			ans+=vec[i_];
		}
		cout<<ans-1<<"\n";
	}
}

