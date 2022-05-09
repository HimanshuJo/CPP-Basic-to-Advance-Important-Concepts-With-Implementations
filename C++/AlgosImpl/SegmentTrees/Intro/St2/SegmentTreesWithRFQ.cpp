// Find frequency of a number in a given range
// seg tree with 0 based indexing
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int N;
vector<int>in;
vector<vector<int>>segTree;

void build(int ss, int se, int idx){
	if(ss==se) segTree[idx]={in[ss]};
	else{
		int mid=(ss+se)/2;
		build(ss, mid, idx*2);
		build(mid+1, se, idx*2+1);
		segTree[idx].resize(se-ss+1);
		auto &L=segTree[idx*2], &R=segTree[idx*2+1];
		merge(begin(L), end(L), begin(R), end(R), begin(segTree[idx]));
	}
}

int query(int qs, int qe, int val, int idx, int ss, int se){
	if(ss>qe||se<qs) return 0;
	if(qs<=ss&&se<=qe){
		auto right=upper_bound(begin(segTree[idx]), end(segTree[idx]), val);
		auto left=lower_bound(begin(segTree[idx]), end(segTree[idx]), val);
		return right-left;
	}
	int mid=(ss+se)/2;
	int ql=query(qs, qe, val, idx*2, ss, mid);
	int qr=query(qs, qe, val, idx*2+1, mid+1, se);
	return ql+qr;
}

int query(int L, int R, int val){
	return query(L, R, val, 1, 0, N-1);
}

int main(){
	in={1, 2, 2, 4, 5, 6, 5, 4, 5, 6, 5};
	N=in.size();
	segTree.resize(4*N-1);
	build(0, N-1, 1);
	cout<<(query(0, 2, 2));
}
