// B. Best Permutation
/*
Let's define the value of the permutation p of n integers 1, 2, ..., n 
(a permutation is an array where each element from 1 to n occurs exactly once) as follows:

initially, an integer variable x is equal to 0;
	if x<p1, then add p1 to x (set x=x+p1), otherwise assign 0 to x;
	
	if x<p2, then add p2 to x (set x=x+p2), otherwise assign 0 to x;
	
	...
	
	if x<pn, then add pn to x (set x=x+pn), otherwise assign 0 to x;

the value of the permutation is x at the end of this process.

For example, for p=[4,5,1,2,3,6], the value of x changes as follows: 0,4,9,0,2,5,11, 
so the value of the permutation is 11.

You are given an integer n. Find a permutation p of size n with the maximum possible value 
among all permutations of size n. If there are several such permutations, you can print any of them.

Input
The first line contains one integer t (1≤t≤97) — the number of test cases.

The only line of each test case contains one integer n (4≤n≤100).

Output
For each test case, print n integers — the permutation p of size n with the maximum possible value 
among all permutations of size n.

Example
input
3
4
5
6

output
2 1 3 4
1 2 3 4 5
4 5 1 2 3 6
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

bool isValid(vector<int>&vec, int curval){
    int sz=vec.size();
    vector<int>temp;
    temp.push_back(0);
    int bgn=0;
    for(int i=0; i<sz; ++i){
        if(vec[i]>bgn){
            temp.push_back(vec[i]+bgn);
            bgn=vec[i]+bgn;
        } else{
            temp.push_back(0);
            bgn=0;
        }
    }
    return temp.back()>=curval;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>ans(n, 0), ans2(n, 0);
        ans[n-1]=n;
        ans2[n-1]=n;
        for(int i=n-1; i>=1; --i){
            ans[n-2]=i;
            int nwnum=1;
            while(nwnum==i){
                nwnum++;
            }
            for(int x=0; x<n-2; ++x){
                if(nwnum!=i){
                    ans[x]=nwnum;
                } else{
                    nwnum++;
                    ans[x]=nwnum;
                }
                nwnum++;
            }
            int curval=ans[n-1]+ans[n-2];
            if(isValid(ans, curval)){
                break;
            }
        }
        int curfnval=ans[n-1]+ans[n-2];
        for(int i=n-1; i>=1; --i){
            ans2[n-2]=i;
            int nwnum=1;
            while(nwnum==i){
                nwnum++;
            }
            for(int x=n-3; x>=0; --x){
                if(nwnum!=i){
                    ans2[x]=nwnum;
                } else{
                    nwnum++;
                    ans2[x]=nwnum;
                }
                nwnum++;
            }
            int curval=ans2[n-1]+ans2[n-2];
            if(isValid(ans2, curval)){
                break;
            }
        }
        int secfnval=ans2[n-1]+ans2[n-2];
        if(secfnval>curfnval){
            swap(ans, ans2);
        }
        for(auto &vals: ans){
            cout<<vals<<" ";
        }
        cout<<"\n";
    }
}