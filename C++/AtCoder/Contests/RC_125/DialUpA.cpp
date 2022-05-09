/*
Problem Statement
Snuke has a sequence of N integers a=(a1,a2,⋯,aN) consisting of 0s and 1s, 
and an empty integer sequence b. The initial state ai=Si is given to you as input.

Snuke can do the following three operations any number of times in any order.

Shift a to the right. In other words, replace a with (aN,a1,a2,⋯,aN−1).

Shift a to the left. In other words, replace a with (a2,a3,⋯,aN,a1).

Append the current value of a1 at the end of b.

You are also given a sequence of M integers T=(T1,T2,⋯,TM). 
Determine whether it is possible to make b equal to T. If it is possible, 
find the minimum number of operations needed to do so.

Sample Input 1 

3 4
0 0 1
0 1 1 0

Sample Output 1 

6
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while (t--){
        int N, M;
        cin>>N>>M;
        vector<int>s(N), t(M);
        for (int i=0; i<N; ++i){
            cin>>s[i];
        }
        for (int i=0; i<M; ++i){
            cin>>t[i];
        }
        int minDiff=N;
        for (int i=0; i<N; ++i){
            if (s[i]!=s[0]){
                minDiff=min(minDiff, i);
                minDiff=min(minDiff, N-i);
            }
        }
        int cnt=0;
        if (t[0]!=s[0]){
            cnt++;
        }
        for (int i=0; i+1<M; ++i){
            if (t[i]!=t[i+1]){
                cnt++;
            }
        }
        if (cnt==0){
            cout<<M<<"\n";
        } else if (minDiff>=N){
            cout<<-1<<"\n";
        } else {
            int ans=(minDiff-1)+cnt+M;
            cout<<ans<<"\n";
        }
    }
}