// LIS to Original Sequence
/*
Problem Statement
Given are an integer N and a monotonically increasing sequence of K 
integers A=(A1,A2,⋯,AK). 
Find the lexicographically smallest permutation P of (1,2,⋯,N) 
that satisfies the following condition.

A is a longest increasing subsequence of P (a monotonically 
increasing subsequence of P with the maximum possible length). 
It is fine if P has multiple 
longest increasing subsequences, one of which is A.

From the Constraints of this problem, we can prove that there always exists a P 
that satisfies the condition.

Constraints
1≤K≤N≤2×10^5
 
1≤A1<A2<⋯<AK≤N
All values in input are integers.

Sample Input 1 

3 2
2 3

Sample Output 1 

2 1 3
A is a longest increasing subsequence of P 
when P=(2,1,3),(2,3,1). The answer is the lexicographically 
smallest of the two, or (2,1,3).
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while (t--){
        int N, K;
        cin>>N>>K;
        vector<int>A(K);
        vector<int>res;
        for (int i=0; i<K; ++i){
            cin>>A[i];
            A[i]--;
        }
        A.pop_back();
        if (K==1){
            for (int i=N; i>0; --i){
                cout<<i<<" ";
            }
            continue;
        }
        vector<int>seen(N, 0);
        for (int x: A){
            seen[x]=1;
        }
        int curr=0;
        for (int num: A){
            res.push_back(num);
            while (curr<num&&seen[curr]){
                curr++;
            }
            if (curr<num&&!seen[curr]){
                res.push_back(curr);
                seen[curr]=1;
            }
        }
        for (int i=N-1; i>=0; --i){
            if (!seen[i]){
                res.push_back(i);
                seen[i]=1;
            }
        }
        for (int num: res){
            cout<<num+1<<" ";
        }
    }
}