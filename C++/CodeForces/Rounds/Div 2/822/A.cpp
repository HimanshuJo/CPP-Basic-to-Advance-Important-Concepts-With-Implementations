// A. Select Three Sticks
/*
You are given n sticks with positive integral length a1,a2,…,an.

You can perform the following operation any number of times (possibly zero):

choose one stick, then either increase or decrease its length by 1. After each operation, all sticks 
should have positive lengths.

What is the minimum number of operations that you have to perform such that it is possible to select 
three of the n sticks and use them without breaking to form an equilateral triangle?

An equilateral triangle is a triangle where all of its three sides have the same length.

Input
The first line of the input contains a single integer t (1≤t≤100) — the number of test cases. 
The description of the test cases follows.

The first line of each test case contains a single integer n (3≤n≤300) — the number of sticks.

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤10^9) — the lengths of the sticks.

It is guaranteed that the sum of n over all test cases does not exceed 300.

Output
For each test case, print one integer on a single line — the minimum number of operations to be made.

Example
input
4
3
1 2 3
4
7 3 7 3
5
3 4 2 1 1
8
3 1 4 1 5 9 2 6

output
2
4
1
1

Note
In the first test case, you can increase the length of the first stick by 1, then decrease the length of the 
third stick by 1. 

In total, you perform 2 operations, such that the three sticks form an equilateral triangle of side length 2.

In the fourth test case, you can decrease the length of the seventh stick by 1. 
An equilateral triangle of side length 1 can be selected and formed by the second, fourth, and seventh sticks.
*/

#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<queue>
#include<algorithm>
#define endl "\n"
using ll=long long;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int>in(N);
        for(int i=0; i<N; ++i){
            cin>>in[i];
        }
        sort(in.begin(), in.end());
        int ans=INT_MAX;
        for(int i=0; i<N; ++i){
            if(i+2<=N-1){
                int frst=in[i], sec=in[i+1], thrd=in[i+2];
                int tmp1=frst, tmp2=sec, tmp3=thrd;
                int curans=abs(tmp1-frst)+abs(tmp2-frst)+abs(tmp3-frst);
                ans=min(ans, curans);
                tmp1=frst, tmp2=sec, tmp3=thrd;
                curans=abs(tmp1-sec)+abs(tmp2-sec)+abs(tmp3-sec);
                ans=min(ans, curans);
                tmp1=frst, tmp2=sec, tmp3=thrd;
                curans=abs(tmp1-thrd)+abs(tmp2-thrd)+abs(tmp3-thrd);
                ans=min(ans, curans);
            }
        }
        cout<<ans<<endl;
    }
}