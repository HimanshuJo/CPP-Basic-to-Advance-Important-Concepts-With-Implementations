// E. Off by One
/*
There are n points on an infinite plane. 
The i-th point has coordinates (xi,yi) such that xi>0 and yi>0. The coordinates are not necessarily integer.

In one move you perform the following operations:

choose two points a and b (a≠b);
move point a from (xa,ya) to either (xa+1,ya) or (xa,ya+1);
move point b from (xb,yb) to either (xb+1,yb) or (xb,yb+1);
remove points a and b.
However, the move can only be performed if there exists a line that passes through the new coordinates of a, 
new coordinates of b and (0,0).

Otherwise, the move can't be performed and the points stay at their original coordinates (xa,ya) and (xb,yb), respectively.

The numeration of points does not change after some points are removed. Once the points are removed, 
they can't be chosen in any later moves. Note that you have to move both points during the move, 
you can't leave them at their original coordinates.

What is the maximum number of moves you can perform? What are these moves?

If there are multiple answers, you can print any of them.

Input
The first line contains a single integer n (1≤n≤2⋅10^5) — the number of points.

The i-th of the next n lines contains four integers ai,bi,ci,di (1≤ai,bi,ci,di≤10^9). 
The coordinates of the i-th point are xi=aibi and yi=cidi.

Output
In the first line print a single integer c — the maximum number of moves you can perform.

Each of the next c lines should contain a description of a move: two integers a and b (1≤a,b≤n, a≠b) — 
the points that are removed during the current move. There should be a way to move points a and b according to 
the statement so that there's a line that passes through the new coordinates of a, the new coordinates of b and (0,0). 
No removed point can be chosen in a later move.

If there are multiple answers, you can print any of them. You can print the moves and the points in the move in the arbitrary order.

Examples
input
7
4 1 5 1
1 1 1 1
3 3 3 3
1 1 4 1
6 1 1 1
5 1 4 1
6 1 1 1

output
3
1 6
2 4
5 7

input
4
2 1 1 1
1 1 2 1
2 1 1 2
1 2 1 2

output
1
1 2

input
4
182 168 60 96
78 72 45 72
69 21 144 63
148 12 105 6

output
1
2 4
*/
/*
At first the problem sounds like some sort of matching. 
However, it seems like you first want to match each point with either of its moves and then some 
pairs of points to each other. That doesn't sound viable but since the matchings are often connected with graphs, 
the graph idea might come handy.

Let's first consider a pair of matched points. What does it actually mean that there exists a 
line through their new coordinates and (0,0)? It's the same as: the angles of a line through 
the new coordinates of a and (0,0) and a line through the new coordinates of b and (0,0) are the same. 
Angles are the same means that their tangents are the same (and vice versa since we only consider the 
first quadrant of the plane). So we can conclude that y/x+1 or y+1/x of the first point should be equal to any of these of the second point.

Now consider the following graph. Various values of tangents of the lines are the nodes. 
Each point produces an edge between their y/x+1 and y+1/x. What are the matched pairs of points in this graph? 
It's such a pair of edges that they share at least one endpoint.

Building a graph is the slowest part of the solution since you have to use some data structure 
(or at least a sort and a binary search). O(n) is possible with some sort of hashmap but O(nlogn) should be perfectly fine as well.

So we reduced the problem to a more well-known one: given an arbitrary undirected graph, 
find the maximum number of pairs of edges such that each pair shares at least one endpoint 
and each edge is included in no more than one pair.

The upper bound on the answer is the following. Let mi be the number of edges in the i-th connected component. 
Best case we can make ⌊mi2⌋ pairs from it. Let's come up with an algorithm to achieve this bound.

Consider a dfs tree of a component. It's known that a dfs tree of an undirected graph contains no cross edges. 
So if we direct all the edges of a dfs tree downwards (convert all back edges to forward edges), 
each edge will connect some vertex to its descendant.

Imagine we came up with a dfs such that dfs(v) matches all the edges that have their upper node in 
the subtree of v to each other (except one edge in case there is an odd number of them). dfs(root) will solve the task exactly then.

How should that dfs work exactly?

What if there were no forward edges at all? That case is easy since all edges are tree edges. 
We'll try to maintain an invariant that the only unmatched edge is an edge that has v as one of its endpoints. 
If v is a leaf, then there's nothing to match. Otherwise, we go into some child u. If it can't match all its edges, 
then match its remaining edge to an edge (v,u). If it can then remember that we have an edge (v,u) unmatched so far. 
Go into another child w. Same, match our edge with its edge if it has one unmatched. However, if (v,w) 
turned out to get unmatched and (v,u) turned out to be unmatched, then you can match them to each other. 
This way you will be left with at most one unmatched edge after you process all the children, and that edge has its endpoint at v.

Add the forward edges back. Did anything change? Look at the forward edge that has its upper vertex the lowest. 
We can see that it points to a vertex u that has its subtree fully matches. So why don't we treat this forward
edge the same as an edge to a leaf? Forget that u has some subtree of its own and just believe that you can't 
match the edge (v,u) so far. Proceed the same as the easy case.

Since we mark exactly which edges you pair up with which, it's trivial to retrieve the answer.

Overall complexity: O(n)/O(nlogn)
*/

#include<map>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
using ll=long long;
typedef pair<ll, ll>frac;
typedef pair<int, int>pt;

struct Point{
	int a, b, c, d;
};

vector<Point>points;
vector<vector<pt>>gr;
vector<int>seen;
vector<pt>ans;
map<frac, int>mp;

ll gcd(ll A, ll B){
	if(B==0) return A;
	return (gcd(B, A%B));
}

frac norm(ll x, ll y){
	ll g=gcd(x, y);
	return {x/g, y/g};
}

int dfs(int val){
	seen[val]=1;
	int cur=-1;
	for(auto &it: gr[val]){
		int u=it.first, v=it.second;
		if(seen[u]==1) continue;
		int nw=v;
		if(!seen[u]){
			int tmp=dfs(u);
			if(tmp!=-1){
				ans.push_back({nw, tmp});
				nw=-1;
			}
		}
		if(nw!=-1){
			if(cur!=-1){
				ans.push_back({cur, nw});
				cur=-1;
			} else{
				cur=nw;
			}
		}
	}
	seen[val]=2;
	return cur;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	points.resize(n);
	for(int i=0; i<n; ++i){
		cin>>points[i].a>>points[i].b>>points[i].c>>points[i].d;
	}
	gr.resize(2*n);
	for(int i=0; i<n; ++i){
		frac f1=norm((points[i].a+points[i].b)*1ll*points[i].d, points[i].b*1ll*points[i].c);
		frac f2=norm(points[i].a*1ll*points[i].d, (points[i].c+points[i].d)*1ll*points[i].b);
		if(!mp.count(f1)){
			int k=mp.size();
			mp[f1]=k;
		}
		if(!mp.count(f2)){
			int k=mp.size();
			mp[f2]=k;
		}
		gr[mp[f1]].push_back({mp[f2], i});
		gr[mp[f2]].push_back({mp[f1], i});
	}
	seen.resize(mp.size());
	for(int i=0; i<mp.size(); ++i){
		if(!seen[i]){
			dfs(i);
		}
	}
	cout<<ans.size()<<"\n";
	for(auto &it: ans){
		cout<<it.first+1<<" "<<it.second+1<<"\n";
	}
}
