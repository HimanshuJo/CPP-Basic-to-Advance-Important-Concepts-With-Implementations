#include<vector>
#include<iostream>
#include<cmath>
using namespace std;

int getMid(int s, int e){
	return (s+(e-s)/2);
}

int getSumUtil(vector<int>&st, int ss, int se, int qs, int qe, int sidx){
	if(se<qs||ss>qe) return 0;
	if(ss>=qs&&se<=qe) return st[sidx];
	int mid=getMid(ss, se);
	return (getSumUtil(st, ss, mid, qs, qe, sidx*2+1)+
			getSumUtil(st, mid+1, se, qs, qe, sidx*2+2));
}

int getSum(vector<int>&st, int n, int qs, int qe){
	if(qs<0||qe>n-1||qs>qe){
		cout<<"Invalid "<<endl;
		return -1;
	}
	int ss=0, se=n-1, sidx=0;
	return (getSumUtil(st, ss, se, qs, qe, sidx));
}

void updateValueUtil(vector<int>&st, int ss, int se, int diff, int vidx, int sidx){
	if(ss>vidx||se<vidx) return;
	st[sidx]=st[sidx]+diff;
	if(ss!=se){
		int mid=getMid(ss, se);
		updateValueUtil(st, ss, mid, diff, vidx, sidx*2+1);
		updateValueUtil(st, mid+1, se, diff, vidx, sidx*2+2);
	}
}

void updateValue(vector<int>&arr, vector<int>&st, int n, int vidx, int nwVal){
	if(vidx<0||vidx>n-1){
		cout<<"Invalid "<<endl;
		return;
	}
	int diff=nwVal-arr[vidx];
	arr[vidx]=nwVal;
	int ss=0, se=n-1, sidx=0;
	updateValueUtil(st, ss, se, diff, vidx, sidx);
}

int constructStUtil(vector<int>&arr, vector<int>&st, int ss, int se, int sidx){
	if(ss==se){
		st[sidx]=arr[ss];
		return arr[ss];
	}
	int mid=getMid(ss, se);
	st[sidx]=constructStUtil(arr, st, ss, mid, sidx*2+1)+
			 constructStUtil(arr, st, mid+1, se, sidx*2+2);
	return st[sidx];
}

vector<int> constructSt(vector<int>&arr, int n){
	int x=(int)(ceil(log2(n)));
	int maxSz=2*(int)pow(2, x)-1;
	vector<int>st(maxSz, 0);
	int ss=0, se=n-1, sidx=0;
	constructStUtil(arr, st, ss, se, sidx);
	return st;
}

int main(){
	vector<int>arr{1, 2, 3, 4, 5, 6, 7};
	int n=arr.size();
	vector<int>st=constructSt(arr, n);
	cout<<getSum(st, n, 0, 2)<<endl;
	updateValue(arr, st, n, 0, 5);
	cout<<getSum(st, n, 0, 2)<<endl;
}