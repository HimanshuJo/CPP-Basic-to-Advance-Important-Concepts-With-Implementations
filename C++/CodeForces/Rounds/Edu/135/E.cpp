// E. Red-Black Pepper
/*
Monocarp is going to host a party for his friends. He prepared n dishes and is about to serve them. 
First, he has to add some powdered pepper to each of them — otherwise, the dishes will be pretty tasteless.

The i-th dish has two values ai and bi — its tastiness with red pepper added or black pepper added, 
respectively. Monocarp won't add both peppers to any dish, won't add any pepper multiple times, and won't 
leave any dish without the pepper added.

Before adding the pepper, Monocarp should first purchase the said pepper in some shop. There are m shops 
in his local area. The j-th of them has packages of red pepper sufficient for xj servings and packages of 
black pepper sufficient for yj servings.

Monocarp goes to exactly one shop, purchases multiple (possibly, zero) packages of each pepper in such a 
way that each dish will get the pepper added once, and no pepper is left. 

More formally, if he purchases x red pepper packages and y black pepper packages, then x and y should be 
non-negative and x⋅xj+y⋅yj should be equal to n.

For each shop, determine the maximum total tastiness of the dishes after Monocarp buys pepper packages only 
in this shop and adds the pepper to the dishes. If it's impossible to purchase the packages in the said way, print -1.

Input
The first line contains a single integer n (1≤n≤3⋅10^5) — the number of dishes.

The i-th of the next n lines contains two integers ai and bi (1≤ai,bi≤10^9) — the tastiness of the i-th 
dish with red pepper added or black pepper added, respectively.

The next line contains a single integer m (1≤m≤3⋅10^5) — the number of shops.

The j-th of the next m lines contains two integers xj and yj (1≤xj,yj≤n) — the number of servings the red 
and the black pepper packages are sufficient for in the j-th shop, respectively.

Output
Print m integers. For each shop, print the maximum total tastiness of the dishes after Monocarp buys 
pepper packages only in this shop and adds the pepper to the dishes. 

If it's impossible to purchase the packages so that each dish will get the pepper added once 
and no pepper is left, print -1.

Examples
input
3
5 10
100 50
2 2
4
2 3
1 1
3 2
2 2

output
62
112
107
-1

input
10
3 1
2 3
1 1
2 1
6 3
1 4
4 3
1 3
5 3
5 4
10
8 10
9 3
1 4
2 5
8 3
3 5
1 6
7 2
6 7
3 1

output
26
-1
36
30
-1
26
34
26
-1
36

Note
Consider the first example.

In the first shop, Monocarp can only buy 0 red pepper packages and 1 black pepper package. 
Black pepper added to all dishes will sum up to 10+50+2=62.

In the second shop, Monocarp can buy any number of red and black pepper packages: 0 and 3, 1 and 2, 2 and 1 or 3 and 0. 
The optimal choice turns out to be either 1 and 2 or 2 and 1. 
Monocarp can add black pepper to the first dish, red pepper to the second dish and any pepper to the third dish, 
the total is 10+100+2=112.

In the third shop, Monocarp can only buy 1 red pepper package and 0 black pepper packages. 
Red pepper added to all dishes will sum up to 5+100+2=107.

In the fourth shop, Monocarp can only buy an even total number of packages. 
Since n is odd, it's impossible to get exactly n packages. Thus, the answer is −1.
*/

/*
Let's start by learning how to answer a query (1,1) — all red pepper and black pepper options are available.

Let's iterate over all options to put the peppers and choose the maximum of them. 
First, let's use the red pepper for all dishes. 

Now we want to select some k of them to use black pepper instead of red pepper.
Which ones do we choose? When we switch from the red pepper to the black pepper, 
the total tastiness changes by −ai+bi for the i-th dish. 

They are completely independent of each other, so we want to choose k largest of these values.

Let d1,d2,…,dn be the sequence of values of −ai+bi in a non-increasing order.

Thus, k black peppers will yield the result of ∑i=1n ai+∑i=1k di. 
We can answer a query (1,1) by looking for a maximum in the sequence.

-------

Now consider an arbitrary query. Let p1,p2,…,pt be all options for the amount of available black peppers 
for the query. 

Naively, we could iterate over all of them and choose the maximum one.

However, notice an interesting thing about the sequence of the answers. 
By definition, it is non-strictly convex. 

In particular, one idea that can be extracted from this is the following. 
Find the position of an arbitrary maximum in this sequence. 
Then everything to the left of is is non-increasing. 
Everything to the right of it is non-increasing.

Thus, for a query, it's enough to consider only two options: the one closest to the 
maximum from the left and from the right.

Now we only have to learn how to get these options fast enough. 
For a query (x,y) we want to solve what's called a diophantine equation ax+by=n. 
An arbitrary solution can be obtained by using extended Euclid algorithm. 
Let it be some (a,b). 

Then we would want to check the answer for ax black peppers. 
The amount of solutions to the equation is either infinite or zero. 
If it's infinite, all solutions will be of the form ax+k⋅lcm(x,y) for any integer k. 
Remember that not all the solutions will be in a range [0,n].

-------

Finally, find the two solutions that are the closest to the maximum, check that they are in the range 
[0,n] and print the best answer of them.

Overall complexity: O(nlogn+qlogX).
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<fstream>
#include<functional>
#include<numeric>
using ll=long long;
using namespace std;

ll gcd(ll a, ll b, ll &x, ll &y){
    if(b==0){
        x=1, y=0;
        return a;
    }
    ll x1, y1;
    ll d=gcd(b, a%b, x1, y1);
    x=y1, y=x1-y1*(a/b);
    return d;
}

bool anySolutions(ll a, ll b, ll c, ll &x0, ll &y0, ll &g){
    g=gcd(abs(a), abs(b), x0, y0);
    if(c%g) return false;
    x0*=c/g, y0*=c/g;
    if(a<0) x0=-x0;
    if(b<0) y0=-y0;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    while(t--){
        int n;
        cin>>n;
        vector<int>A(n), B(n);
        for(int i=0; i<n; ++i){
            cin>>A[i]>>B[i];
        }
        ll cur=accumulate(B.begin(), B.end(), 0ll);
        vector<int>diffs(n);
        for(int i=0; i<n; ++i){
            diffs[i]=A[i]-B[i];
        }
        sort(diffs.begin(), diffs.end(), greater<int>());
        vector<ll>bst(n+1);
        for(int i=0; i<n+1; ++i){
            bst[i]=cur;
            if(i<n){
                cur+=diffs[i];
            }
        }
        int mx=max_element(bst.begin(), bst.end())-bst.begin();
        int m;
        cin>>m;
        for(int i=0; i<m; ++i){
            int x, y;
            cin>>x>>y;
            ll x0, y0, g;
            if(!anySolutions(x, y, n, x0, y0, g)){
                cout<<-1<<endl;
                continue;
            }
            ll l=x*1ll*y/g;
            ll red=x0*1ll*x;
            red=red+(max(0ll, mx-red)+l-1)/l*l;
            red=red-max(0ll, red-mx)/l*l;
            ll ans=-1;
            if(red<=n) ans=max(ans, bst[red]);
            red-=l;
            if(red>=0) ans=max(ans, bst[red]);
            cout<<ans<<endl;
        }
    }
}