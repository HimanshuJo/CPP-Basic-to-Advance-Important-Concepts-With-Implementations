/*
Given an array [] and an integer X, the task is to find the longest subarray such that
	the sum of its elements isn't divisible by X

	Input: arr[] = {1, 2, 3} X = 3 
	Output: 2 3

	Explanation: 
		The subarray {2, 3} has a sum of elements 5, which isn’t divisible by 3.

	Input: arr[] = {2, 6} X = 2
	Output: -1 

	Explanation: 
		All possible subarrays {1}, {2}, {1, 2} have an even sum. 
		Therefore, the answer is -1. 
*/

#include<iostream>
#include<climits>
#include<vector>
using namespace std;

vector<int> lngstSubArrayNotDivByX(vector<int>&in, int N, int X){
    int cnt=0;
    for(int i=0; i<N; ++i){
        if(in[i]%X==0) cnt++;
    }
    if(cnt==N) return {-1};
    vector<int>prefSum(N, 0);
    vector<int>suffSum(N, 0);
    prefSum[0]=in[0];
    for(int i=1; i<N; ++i){
        prefSum[i]=prefSum[i-1]+in[i];
    }
    suffSum[N-1]=in[N-1];
    for(int i=N-2; i>=0; --i){
        suffSum[i]=suffSum[i+1]+in[i];
    }
    int bgnidx=0, endidx=N-1, ans=0;
    for(int i=0; i<N; ++i){
        if(suffSum[i]%X!=0&&(ans<(N-1))){
            bgnidx=i, endidx=N-1, ans=max(ans, N-i);
        }
        if(prefSum[i]%X!=0&&(ans<(N-1))){
            bgnidx=0, endidx=i, ans=max(ans, i+1);
        }
    }
    vector<int>fnres;
    for(int i=bgnidx; i<=endidx; ++i){
        fnres.push_back(in[i]);
    }
    return fnres;
}

int main(){
    vector<int>in{2, 6};
    int N=2, X=2;
    vector<int>res=lngstSubArrayNotDivByX(in, N, X);
    for(auto &vals: res)
        cout<<vals<<" ";
}