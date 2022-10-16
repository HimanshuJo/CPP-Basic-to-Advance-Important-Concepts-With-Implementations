// D. Coprime
/*
Given an array of n positive integers a1,a2,…,an (1≤ai≤1000). Find the maximum value of i+j 
such that ai and aj are coprime,† or −1 if no such i, j exist.

For example consider the array [1,3,5,2,4,7,7]. The maximum value of i+j that can be obtained 
is 5+7, since a5=4 and a7=7 are coprime.

† Two integers p and q are coprime if the only positive integer that is a divisor of both of 
them is 1 (that is, their greatest common divisor is 1).

Input
The input consists of multiple test cases. The first line contains an integer t (1≤t≤10) — 
the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer n (2≤n≤2⋅10^5) — the length of the array.

The following line contains n space-separated positive integers a1, a2,..., an (1≤ai≤1000) — the elements of the array.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅10^5.

Output
For each test case, output a single integer  — the maximum value of i+j such that i and j satisfy the condition 
that ai and aj are coprime, or output −1 in case no i, j satisfy the condition.

Example
input
6
3
3 2 1
7
1 3 5 2 4 7 7
5
1 2 3 4 5
3
2 2 4
6
5 4 3 15 12 16
5
1 2 2 3 6

output
6
12
9
-1
10
7
Note
For the first test case, we can choose i=j=3, with sum of indices equal to 6, since 1 and 1 are coprime.

For the second test case, we can choose i=7 and j=5, with sum of indices equal to 7+5=12, since 7 and 4 are coprime.
*/

/*
Note that the array has at most 1000 distinct elements, since ai≤1000. 
For each value, store the largest index it is in. 
Then we can brute force all pairs of values, and find the coprime pair with largest sum of indices.

The time complexity is O(ai^2logai+n) per testcase.
*/

#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<queue>
#include<algorithm>
#include<unordered_map>
#define endl "\n"
using ll=long long;
using namespace std;

int calGCD(int A, int B){
    if(B==0) return A;
    return calGCD(B, A%B);
}

bool areCoprime(int A, int B){
    return calGCD(A, B)==1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>in(n);
        unordered_map<int, int>mp;
        for(int i=0; i<n; ++i){
            cin>>in[i];
            mp[in[i]]=i;
        }
        vector<int>all;
        for(auto &entries: mp){
            all.push_back(entries.second);
        }
        sort(all.begin(), all.end());
        int sz=all.size();
        int curmaxx=0;
        for(int i=sz-1; i>=0; --i){
            for(int j=i; j>=0; --j){
                if(areCoprime(in[all[i]], in[all[j]])){
                    curmaxx=max(curmaxx, all[i]+1+all[j]+1);
                    break;
                }
            }
        }
        cout<<(curmaxx==0?-1:curmaxx)<<endl;
    }
}