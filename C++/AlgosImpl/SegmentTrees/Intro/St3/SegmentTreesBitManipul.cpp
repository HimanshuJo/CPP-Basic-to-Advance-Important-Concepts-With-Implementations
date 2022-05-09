#include<bits/stdc++.h>
using namespace std;

int n;
int tree[2*100000];

void build(int arr[]){
	for(int i=0; i<n; ++i){
		tree[n+i]=arr[i];
	}
	for(int i=n-1; i>0; --i){
		tree[i]=tree[i<<1]+tree[i<<1|1];
	}
}

void update(int p, int value){
	tree[n+p]=value;
	p=p+n;
	for(int i=p; i>1; i>>=1){
		tree[i>>1]=tree[i]+tree[i^1];
	}
}

int query(int qs, int qe){
	int res=0;
	for(qs+=n, qe+=n; qs<qe; qs>>=1, qe>>=1){
		if(qs&1){
			res+=tree[qs++];
		}
		if(qe&1){
			res+=tree[qe--];
		}
	}
	return res;
}

int main(){
	int arr[]{1, 2, 3, 4, 5, 6, 7};
	n = sizeof(arr)/sizeof(arr[0]);
	build(arr);
	int qs=0;
	int qe=2; // exclusive
	cout<<query(qs, qe)<<endl;
}