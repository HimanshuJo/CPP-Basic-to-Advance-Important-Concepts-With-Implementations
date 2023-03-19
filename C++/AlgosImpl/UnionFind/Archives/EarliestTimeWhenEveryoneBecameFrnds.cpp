// The Earliest Moment When Everyone Become Friends
/*
Given a group of N people, each having a unique ID value from 
0 to (N – 1) and an array arr[] of M elements of the 
form {U, V, time} representing that the person U will 
become acquainted with person V at the given time. 
Let’s say that person U is acquainted with person V if
U is friends with V, or U is a friend of someone acquainted 
with V. The task is to find the earliest time at which every 
person became acquainted with each other.

Input: N = 4, arr[] = {{0, 1, 2}, {1, 2, 3}, {2, 3, 4}}
Output: 4
Explanation: Initially, the number of people are 4, i.e, {0}, {1}, {2}, {3}. 

	At time = 2, {0} and {1} became friends. Therefore, the group of acquainted people becomes {0, 1}, {2}, {3}.
	At time = 3, {1} and {2} became friends. Therefore, the group of acquainted people becomes {0, 1, 2}, {3}.
	At time = 4, {2} and {3} became friends. Therefore, the group of acquainted people becomes {0, 1, 2, 3}.

Hence, at time = 4, every person became acquainted with each other.

Input: N = 6, arr[] = {{0, 1, 4}, {3, 4, 5}, {2, 3, 14}, {1, 5, 24}, {2, 4, 12}, {0, 3, 42}, {1, 2, 41}, {4, 5, 11}}
Output: 24
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int parent[1000], sz[1000];

void initialize(int N){
	for(int i=0; i<=N; ++i){
		parent[i]=i;
		sz[i]=1;
	}
}

int root(int node){
	if(parent[node]==node) return node;
	return (parent[node]=root(parent[node]));
}

void connect(int a, int b){
	a=root(a), b=root(b);
	if(a!=b){
		if(sz[a]<sz[b]){
			swap(a, b);
		}
		sz[a]+=sz[b];
		parent[b]=a;
	}
}

bool custComp(vector<int>&A, vector<int>&B){
	return (A[2]<=B[2]);
}

bool isValid(int N){
	set<int>st;
	for(int i=0; i<N; ++i){
		st.insert(parent[i]);
	}
	return (st.size()==1);
}

int countEarliestTime(vector<vector<int>>&arr, int N){
	sort(arr.begin(), arr.end(), custComp);
	int ans=0;
	initialize(N);
	for(vector<int> vals: arr){
		connect(vals[0], vals[1]);
		connect(vals[1], vals[0]);
		ans=vals[2];
		if(isValid(N)) return ans;
	}	
	return ans;
}

int main(){
	int N=6;
	vector<vector<int>>arr{ { 0, 1, 4 }, { 3, 4, 5 },
            				{ 2, 3, 14 }, { 1, 5, 24 },
            				{ 2, 4, 12 }, { 0, 3, 42 },
            				{ 1, 2, 41 }, { 4, 5, 11 } };
	int ans=countEarliestTime(arr, N);
	cout<<ans<<endl;	
}
