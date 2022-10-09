// D. Reset K Edges
/*
You are given a rooted tree, consisting of n vertices. The vertices are numbered from 1 to n, the root is the vertex 1.

You can perform the following operation at most k times:

choose an edge (v,u) of the tree such that v is a parent of u;
remove the edge (v,u);
add an edge (1,u) (i.e. make u with its subtree a child of the root).
The height of a tree is the maximum depth of its vertices, and the depth of a vertex is the number 
of edges on the path from the root to it. For example, the depth of vertex 1 is 0, since it's the root, 
and the depth of all its children is 1.

What's the smallest height of the tree that can be achieved?

Input
The first line contains a single integer t (1≤t≤10^4) — the number of testcases.

The first line of each testcase contains two integers n and k (2≤n≤2⋅10^5; 0≤k≤n−1) — the number of vertices in 
the tree and the maximum number of operations you can perform.

The second line contains n−1 integers p2,p3,…,pn (1≤pi<i) — the parent of the i-th vertex. Vertex 1 is the root.

The sum of n over all testcases doesn't exceed 2⋅10^5.

Output
For each testcase, print a single integer — the smallest height of the tree that can achieved by performing at most k operations.

Example
input
5
5 1
1 1 2 2
5 2
1 1 2 2
6 0
1 2 3 4 5
6 1
1 2 3 4 5
4 3
1 1 1

output
2
1
5
3
1
*/

/*
Start with the following. Let's look at the input format and consider what the operation 
actually does to it. Since it only changes the parent of some vertex, it modifies only one value in it. 

Moreover, it just assigns it to 1. Thus, the goal is to assign at most k values of parents to 1 to minimize the 
resulting height of the tree.

In particular, that implies that we can freely rearrange the operations, since the assignments don't depend on each other.

One more conclusion. Imagine we have already built some answer. One by one, we moved some 
subtrees to be children of the root. It could happen that we first moved some subtree of a vertex u and 
then applied the operation to an edge inside the subtree of u. 

Let's show that it's always possible to rearrange the operations in the answer to avoid that. 
Just apply the operations in order of decreasing the depth of the vertex u.

If we knew what height h we want to get, we could have been making sure that cut subtree u has 
height at most h−1 (since it gets increased by 1 when glueing it to the root), then pretending that 
that subtree doesn't exist anymore.

Moreover, it's always required to cut subtrees with height at most h−1. If you cut a higher subtree, 
then the answer can't be smaller than h+1, since we rearranged the operation to not touch that subtree anymore.

Well, let's fix that height h if we wanted that. Let's try the solve the opposite problem. 
How many operations will it require to make the tree height at most h? Obviously, the values for 
this problem are non-increasing — the greater we allow the height to be, the less operations it will require. 

-------

Thus, we will be able to apply binary search to it to find the smallest height we can achieve with at most k operations.

Now we want to be choosing the subtrees of height at most h−1 repeatedly and cutting them off until 
the height of the tree becomes at most h.

Let's think greedily. If the height of the tree is not at most h yet, then there exists a 
vertex with the depth greater than h. Let's look at the deepest of them. 
That leaf has to be cut in some subtree. Otherwise, the tree won't become any less higher.

What subtree is the best for it? What options do we have? That vertex itself and all its parents up until h−1 above. 
It's always optimal to cut the highest of them — the (h−1)-st parent, since it will 
remove at least all the vertices of any other cut and some other vertices along with them. 

It's also always possible to remove the (h−1)-st parent, since it will always have height exactly h−1. 
The vertex we are looking at is the deepest in the entire tree — there are no deeper vertices 
in the subtree of the (h−1)-st parent.

Thus, the strategy is to keep cutting the (h−1)-st parent of the deepest vertex until the 
tree becomes at most h height.

-------

Now about the implementation details.

First, we can process the vertices from the deepest upwards in their order in the original tree. 
The operation only removes some vertices but doesn't change the depth of the remaining ones.
For example, you can do a bfs from the root to find the order.

Now the (h−1)-st parent. Let's find it for each vertex before starting the process.
Run a dfs and maintain the stack of the ascendants. When going down the child, append it to the stack. 
What exiting, pop from the stack. Now you can just look at the (h−1)-st element from the top of the stack. 
To be able to do that, simulate the stack with a vector (C++) or a list (Python).

Finally, we would have to determine if the current vertex in the order is removed or not. 
For that, we could maintain a boolean array used for the removed vertices. 

Once you apply the operation, run the dfs from the removed vertex and mark all the newly 
removed descendants of it in used. If you don't go into already marked vertices, there will be no more than n calls of the dfs.

The number of cut vertices is the answer for the fixed height h.

Overall complexity: O(nlogn) per testcase.
*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

void init(vector<vector<int>>&gr, vector<int>&pd, vector<int>&st, int node, int mid){
    st.push_back(node);
    if(int(st.size())-mid>=0){
        pd[node]=st[st.size()-mid];
    }
    for(auto &nei: gr[node]){
        init(gr, pd, st, nei, mid);
    }
    st.pop_back();
}

void dfs(vector<vector<int>>&gr, vector<int>&seen, int curnode){
    seen[curnode]=1;
    for(auto &nei: gr[curnode]){
        if(!seen[nei]){
            dfs(gr, seen, nei);
        }
    }
}

int get(vector<vector<int>>&gr, int mid, int N, int K){
    vector<int>pd(N, -1), st;
    init(gr, pd, st, 0, mid);
    vector<int>ord, H(N);
    queue<int>q;
    q.push(0);
    while(!q.empty()){
        int curnode=q.front();
        q.pop();
        ord.push_back(curnode);
        for(auto &nei: gr[curnode]){
            q.push(nei);
            H[nei]=H[curnode]+1;
        }
    }
    reverse(ord.begin(), ord.end());
    int res=0;
    vector<int>seen(N, 0);
    for(auto &vals: ord){
        if(!seen[vals]&&H[vals]>mid){
            res++;
            dfs(gr, seen, pd[vals]);
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int N, K;
        cin>>N>>K;
        vector<vector<int>>gr(N);
        for(int i=1; i<N; ++i){
            int parent;
            cin>>parent;
            --parent;
            gr[parent].push_back(i);
        }
        int left=1, right=N-1;
        int ans=N;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(get(gr, mid, N, K)<=K){
                ans=mid;
                right=mid-1;
            } else{
                left=mid+1;
            }
        }
        cout<<ans<<endl;
    }
}