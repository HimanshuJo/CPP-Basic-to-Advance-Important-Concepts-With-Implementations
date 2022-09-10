// F. Fishermen
/*
There are n fishermen who have just returned from a fishing trip. The i-th fisherman has caught a fish of size ai.

The fishermen will choose some order in which they are going to tell the size of the fish they caught 
(the order is just a permutation of size n). However, they are not entirely honest, and 
they may "increase" the size of the fish they have caught.

Formally, suppose the chosen order of the fishermen is [p1,p2,p3,…,pn]. 
Let bi be the value which the i-th fisherman in the order will tell to the other fishermen. 
The values bi are chosen as follows:

the first fisherman in the order just honestly tells the actual size of the fish he has caught, so b1=ap1;

every other fisherman wants to tell a value that is strictly greater than the value told 
by the previous fisherman, and is divisible by the size of the fish that the fisherman has caught. 
So, for i>1, bi is the smallest integer that is both strictly greater than bi−1 and divisible by api.

For example, let n=7, a=[1,8,2,3,2,2,3]. If the chosen order is p=[1,6,7,5,3,2,4], then:

b1=ap1=1;
b2 is the smallest integer divisible by 2 and greater than 1, which is 2;
b3 is the smallest integer divisible by 3 and greater than 2, which is 3;
b4 is the smallest integer divisible by 2 and greater than 3, which is 4;
b5 is the smallest integer divisible by 2 and greater than 4, which is 6;
b6 is the smallest integer divisible by 8 and greater than 6, which is 8;
b7 is the smallest integer divisible by 3 and greater than 8, which is 9.

You have to choose the order of fishermen in a way that yields the minimum possible ∑i=1nbi.

Input
The first line contains one integer n (1≤n≤1000) — the number of fishermen.

The second line contains n integers a1,a2,…,an (1≤ai≤10^6).

Output
Print one integer — the minimum possible value of ∑i=1nbi you can obtain by choosing the order of fishermen optimally.

Examples
input
7
1 8 2 3 2 2 3

output
33

input
10
5 6 5 6 5 6 5 6 5 6

output
165
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include <fstream>
using namespace std;

void returnNwVec(vector<int>&vec, vector<int>&in){
    int sz=in.size();
    vector<int>temp(sz, 0);
    for(int i=0; i<sz; ++i){
        temp[i]=in[vec[i]];
    }
    for(int i=1; i<sz; ++i){
        if(temp[i]<=temp[i-1]){
            while(temp[i]<=temp[i-1]){
                temp[i]++;
            }
            while(temp[i]%in[vec[i]]!=0){
                temp[i]++;
            }
        }
    }
    swap(vec, temp);
}

void dfs(vector<int>&vec, vector<vector<int>>&res, vector<int>curpermu, int n){
	if(curpermu.size()==n){
		res.push_back(curpermu);
	} else{
		for(int i=0; i<n; ++i){
			auto it=find(curpermu.begin(), curpermu.end(), vec[i]);
			if(it!=curpermu.end()) continue;
			curpermu.push_back(vec[i]);
			dfs(vec, res, curpermu, n);
			curpermu.pop_back();
		}
	}
}
vector<vector<int>> genallpermus(vector<int>&vec, int n){
    vector<vector<int>>res;
    vector<int>curpermu;
    dfs(vec, res, curpermu, n);
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    while(t--){
        int n;
        cin>>n;
        vector<int>in(n, 0);
        for(int i=0; i<n; ++i){
            cin>>in[i];
        }
        vector<int>intemp;
        for(int i=0; i<n; ++i){
            intemp.push_back(i);
        }
        vector<vector<int>>allpermus=genallpermus(intemp, n);
        long long res=LONG_MAX;
        for(auto &entries: allpermus){
            returnNwVec(entries, in);
            long long cursm=0;
            for(auto &vals: entries){
                cursm+=vals;
            }
            res=min(res, cursm);
        }
        cout<<res<<"\n";
    }
}