// B. Array Recovery
/*
For an array of non-negative integers a of size n, we construct another array d as follows: d1=a1, di=|ai−ai−1| for 2≤i≤n.

Your task is to restore the array a from a given array d, or to report that there are multiple possible arrays.

Input
The first line contains a single integer t (1≤t≤100) — the number of test cases.

The first line of each test case contains one integer n (1≤n≤100) — the size of the arrays a and d.

The second line contains n integers d1,d2,…,dn (0≤di≤100) — the elements of the array d.

It can be shown that there always exists at least one suitable array a under these constraints.

Output
For each test case, print the elements of the array a, if there is only one possible array a. Otherwise, print −1.

Example
input
3
4
1 0 2 5
3
2 6 3
5
0 0 0 0 0

output
1 1 3 8
-1
0 0 0 0 0

Note
In the second example, there are two suitable arrays: [2,8,5] and [2,8,11].
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
        vector<int>ans(N, 0);
        ans[0]=in[0];
        bool flag=false;
        for(int i=1; i<N; ++i){
            int nwval=in[i]+ans[i-1];
            int tochk=abs(in[i]-ans[i-1]);
            if(tochk!=nwval&&abs(tochk-ans[i-1])==in[i]){
                flag=true;
                break;
            } else{
                ans[i]=nwval;
            }
        }
        if(!flag){
            for(auto &vals: ans){
                cout<<vals<<" ";
            }
            cout<<endl;
        } else{
            cout<<"-1\n";
        }
    }
}