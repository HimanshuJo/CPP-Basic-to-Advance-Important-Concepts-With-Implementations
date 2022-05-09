// Pure Straight
/*
Given is a sequence of N positive integers A=(A1,A2,…,AN), where each Ai is 1, 2, …, or K.
You can do the following operation on this sequence any number of times.

Swap two adjacent elements, that is, choose i and j such that ∣i−j∣=1 and swap Ai and Aj
Find the minimum number of operations needed to make A satisfy the following condition.

A contains (1,2,…,K) as a contiguous subsequence, that is, there is a positive 
integer n at most N−K+1 such that An=1, An+1=2, …, and An+K−1=K.

Sample Input 3 
8 4
4 2 3 2 4 2 1 4
Sample Output 3 
5

*/
#include<bits/stdc++.h>
#define popcnt __builtin_popcount
using namespace std;

int calcCost(vector<int>vec, int K, int INF, int hf){
    for(int i=0; i<K; ++i){
        if(vec[i]==-1){
            return INF;
        }
    }
    int cost=0;
    for(int i=0; i<K; ++i){
        for(int j=0; j<i; ++j){
            cost+=vec[j]>vec[i];
        }
    }
    sort(vec.begin(), vec.end());
    for(int i=0; i<K; ++i){
        int toChk=vec[hf]-hf+i;
        cost+=abs(toChk-vec[i]);
    }
    return cost;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
    cin>>N>>K;
    vector<int>A(N);
    for(int i=0; i<N; ++i){
        cin>>A[i];
    }
    int INF=1<<30;
    int ans=INF;
    int hf=K/2;
    for(int x=0; x<N; ++x){
        vector<int>Ld(K, -1), Rd(K, -1);
        for(int i=0; i<x+1; ++i){
            Ld[A[i]-1]=i;
        }
        for(int i=N-1; i>=x; --i){
            Rd[A[i]-1]=i;
        }
        for(int y=0; y<(1<<K); ++y){
            if(popcnt(y)!=hf){
                continue;
            }
            vector<int>vec(K);
            for(int i=0; i<K; ++i){
                vec[i]=(y&(1<<i)?Ld[i]:Rd[i]);
            }
            ans=min(ans, calcCost(vec, K, INF, hf));
        }
    }
    cout<<ans<<"\n";
}