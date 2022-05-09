// Tree Degree Subset Sum
/*
Problem Statement
Given is a tree with N vertices. 
The vertices are numbered 1 through N, and the i-th edge connects 
Vertex Ai and Vertex Bi

Find the number of pairs of integers (x,y) that satisfy 
the following conditions.

0≤x≤N
There is a way to choose exactly x vertices from the tree 
so that the sum of their degrees equals y

Sample Input 1 

3
1 2
2 3

Sample Output 1 

6
The following six pairs (x,y) satisfy the conditions.

x=0,y=0
x=1,y=1
x=1,y=2
x=2,y=2
x=2,y=3
x=3,y=4
x=2,y=3, for example, satisfies the condition because choosing 
Vertex 1 and Vertex 2 achieves the total degree of 3.
*/

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int maxx=200001;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>deg(n, -1);
    for (int i=0; i<n-1; ++i){
        int a, b;
        cin>>a>>b;
        --a, --b;
        deg[a]++;
        deg[b]++;
    }
    sort(deg.begin(), deg.end());
    map<int, int>dFreq;
    for (int d: deg){
        dFreq[d]++;
    }
    int tot=n-2;
    vector<int>dp(tot+1, 1e8);
    dp[0]=0;
    for (auto &entry: dFreq){
        int d=entry.first;
        int f=entry.second;
        if (d==0){
            continue;
        }
        for (int res=0; res<d; ++res){
            int top=(tot/d)*d+res;
            if (tot%d!=0){
                top=(tot/d)*d+res;
            } else {
                top=tot+res;
            }
            while (top>tot){
                top-=d;
            }
            if (top<0){
                continue;
            }
            multiset<int>dpS;
            for (int j=0; j<=f; ++j){
                if (top>=j*d){
                    dpS.insert(dp[top-j*d]+j);
                }
            }
            int i=0;
            while (true){
                int z=min(dp[top-i*d], (*dpS.begin())-i);
                dpS.erase(dpS.find(dp[top-i*d]+i));
                dp[top-i*d]=z;
                i+=1;
                if (top-i*d<0){
                    break;
                }
                if (top>=(i+f)*d){
                    dpS.insert(dp[top-(i+f)*d]+(i+f));
                }
            }
        }
    }
    ll ans=0;
    for (int i=0; i<=tot; ++i){
        if (dp[i]>n){
            continue;
        }
        ans+=n-dp[tot-i]-dp[i]+1;
    }
    cout<<ans;
}