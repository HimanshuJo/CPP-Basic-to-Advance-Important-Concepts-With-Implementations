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

/*
Suppose we have fixed some order of fishermen and calculated the values of bi. 
Then, we have the following constraints on bi:

	all values of bi are pairwise distinct;
	for every i, ai divides bi.

Not every possible array b meeting these constraints can be achieved with some order of fishermen, 
but we can show that if we choose an array b with the minimum possible sum among the arrays meeting these two constraints, 
there exists an ordering of fishermen which yields this array b. 

The proof is simple — suppose the ordering of fishermen is the following one: 

the first fisherman is the one with minimum bi, 
the second one — the one with the second minimum bi, and so on. 

It's obvious that if we generate the values of b according to this order, they won't be greater than the values 
in the array we have chosen. And if some value is less than the value in the chosen array b, 
it means that we haven't chosen the array with the minimum possible sum. 

So, we can rephrase the problem as the following one: for each ai, choose the value of bi so that 
it is divisible by ai, all bi are distinct, and their sum is minimized.

Using the pigeonhole principle, we can show that for every ai, we need to consider only the values of
bi among [ai,2⋅ai,3⋅ai,…,n⋅ai]. So, we can formulate the problem as an 
instance of the weighted bipartite matching: build a graph with two parts, where the left part contains n nodes 
representing the values of ai, the right part represents the values of the form k⋅ai where 1≤k≤n, and 
there exists an edge between a vertex in the left part representing the number x and a vertex in the right part 
representing the number y with cost y if and only if y=k⋅x for some integer k∈[1,n]. 

Note that we don't add the edge if k>n because we need to ensure that the size of the graph is O(n^2).

Okay, now we need to solve this weighted matching problem, but how? The number of vertices is O(n^2), 
and the number of edges is O(n^2) as well, so mincost flow will run in O(n^4) or O(n^3logn), which is too much.

Instead, we can notice that the cost of the edges incident to the same vertex in the right part is the same, 
so we can swap the parts of the graph, sort the vertices of the new left part 
(representing the numbers k⋅ai) according to their costs, and run the classical Kuhn's algorithm in sorted order. 

Kuhn's algorithm in its original implementation will always match a vertex if it is possible, 
so it obtains the minimum total cost for the matching if we do it in sorted order.

But this is still O(n^4)! What should we do? Well, there are some implementations of Kuhn's algorithm 
which can run on graphs of size about 105 (sometimes even 106). 

Why can't we use one of these? Unfortunately, not all optimizations that can be used in Kuhn's algorithm go 
together well with the fact that the vertices of the left part have their weights. 

For example, greedy initialization of matching won't work. So we need to choose optimizations carefully.

The model solution uses the following optimization of Kuhn's algorithm: if you haven't found an 
augmenting path, don't reset the values representing which vertices were visited by the algorithm. 
With this optimization, Kuhn's algorithm works in O(M(E+V)), where M is the size of the maximum matching, 
E is the number of edges, and V is the number of vertices. So, this results in a solution with complexity of O(n^3).

I think it's possible to show that some other optimizations of Kuhn can also work, but the one I described is enough.
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

const int sz=1001;
int A[sz];
vector<int>g[sz*sz];
int mt[sz];
bool used[sz*sz];
vector<int>val;

bool kuhn(int x){
    if(used[x]) return false;
    used[x]=true;
    for(auto &y: g[x]){
        if(mt[y]==-1||kuhn(mt[y])){
            mt[y]=x;
            return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    while(t--){
        int N;
        cin>>N;
        for(int i=0; i<N; ++i){
            cin>>A[i];
        }
        for(int i=0; i<N; ++i){
            for(int j=1; j<=N; ++j){
                val.push_back(A[i]*j);
            }
        }
        sort(val.begin(), val.end());
        val.erase(unique(val.begin(), val.end()), val.end());
        int v=val.size();
        ll ans=0;
        for(int i=0; i<N; ++i){
            for(int j=1; j<=N; ++j){
                int k=lower_bound(val.begin(), val.end(), A[i]*j)-val.begin();
                g[k].push_back(i);
            }
        }
        for(int i=0; i<N; ++i){
            mt[i]=-1;
        }
        for(int i=0; i<v; ++i){
            if(kuhn(i)){
                ans+=val[i];
                for(int j=0; j<v; ++j){
                    used[j]=false;
                }
            }
        }
        cout<<ans<<"\n";
    }
}