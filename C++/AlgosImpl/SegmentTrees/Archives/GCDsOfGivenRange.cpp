#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

vector<int>st;

int gcd(int A, int B){
	if(B==0) return A;
	return gcd(B, A%B);
}

int getMid(int s, int e){
	return (s+(e-s)/2);
}

int findGCDUtil(int ss, int se, int qs, int qe, int sidx){
	if(ss>qe||se<qs) return 0;
	if(ss>=qs&&se<=qe) return st[sidx];
	int mid=getMid(ss, se);
	return gcd(findGCDUtil(ss, mid, qs, qe, sidx*2+1), 
	           findGCDUtil(mid+1, se, qs, qe, sidx*2+2));
}

int findGCD(int qs, int qe, int n){
	if(qs<0||qe>n-1||qs>qe){
		cout<<"Invalid "<<endl;
		return -1;
	}
	int ss=0, se=n-1, sidx=0;
	return findGCDUtil(ss, se, qs, qe, sidx);
}

int constructStUtil(vector<int>&arr, int ss, int se, int sidx){
	if(ss==se){
		st[sidx]=arr[ss];
		return st[sidx];
	}
	int mid=getMid(ss, se);
	st[sidx]=gcd(constructStUtil(arr, ss, mid, sidx*2+1), 
		         constructStUtil(arr, mid+1, se, sidx*2+2));
	return st[sidx];
}

vector<int> constructSt(vector<int>&arr, int n){
	int h=(int)(ceil(log2(n)));
	int maxSz=2*(int)pow(2, h)-1;
	st.resize(maxSz);
	int ss=0, se=n-1, sidx=0;
	constructStUtil(arr, ss, se, sidx);
	return st;
}

int main(){
	vector<int>arr{2, 3, 60, 90, 50};
	int n=arr.size();
	constructSt(arr, n);
	int l=0, r=2;
	cout<<findGCD(l, r, n)<<endl;
	return 0;
}