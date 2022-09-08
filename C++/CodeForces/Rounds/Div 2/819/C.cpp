// C. Jatayu's Balanced Bracket Sequence
/*
Last summer, Feluda gifted Lalmohan-Babu a balanced bracket sequence s of length 2n.

Topshe was bored during his summer vacations, and hence he decided to draw an 
undirected graph of 2n vertices using the balanced bracket sequence s. 

For any two distinct vertices i and j (1≤i<j≤2n), Topshe draws an edge 
(undirected and unweighted) between these two nodes if and only if the 
subsegment s[i…j] forms a balanced bracket sequence.

Determine the number of connected components in Topshe's graph.

See the Notes section for definitions of the underlined terms.

Input
Each test contains multiple test cases. The first line contains a single 
integer t (1≤t≤10^5) — the number of test cases. Description of the test cases follows.

The first line of each test case contains a single integer n (1≤n≤10^5) — the number of 
opening brackets in string s.

The second line of each test case contains a string s of length 2n — 
a balanced bracket sequence consisting of n opening brackets "(", and n closing brackets ")".

It is guaranteed that the sum of n over all test cases does not exceed 10^5.

Output
For each test case, output a single integer — the number of connected components in Topshe's graph.

Example
input
4
1
()
3
()(())
3
((()))
4
(())(())

output
1
2
3
3

Note
Sample explanation:

In the first test case, the graph constructed from the bracket sequence (), 
is just a graph containing nodes 1 and 2 connected by a single edge.

In the second test case, the graph constructed from the bracket sequence ()(()) 
would be the following (containing two connected components):
*/

/*
Claim: The answer is one more than the number of occurrences of the substring 
"((" in the balanced bracket sequence given (considering overlapping occurrences as well).

Proof: Observe the behavior of the lowest index k of any connected component. 
The properties that would hold true are:

sk= '('. This is because for all edges connecting indices i and j such that 
i<j, si= '(' and sj= ')'.
k=1 is the lowest index for its connected component.

For k>1, k is a lowest index for a connected component if and only if sk−1= '('. This is because:

if sk−1= ')', then for any matching bracket sj1 of sk−1 (j1<k−1) and for any matching 
bracket sj2 of sk (j2>k), there must be edges (j1,j2) and (k,j2). 

This means that j1 (which is less than k) is in the connected component of k. [Contradiction]

if sk−1= '(', then we can prove that there cannot be a smaller index in the 
connected component of k. 

For the sake of contradiction, assume that there exists a smaller index a in the 
same connected component. This means, there is an edge (a,b), such that a<k and b>k is 
in the connected component of k. Let pi be the number of '(' minus the the number of ')' 
in the prefix s[1…i] (consider p0=0 for the empty prefix). 

Observe that for all edges (i,j), (i<j), it holds that pj=pi−1 and for all i′, 
i≤i′≤j, we must have pi′≥pj. This means that for a connected component C, 
for all i∈C, si= '(', pi is constant. Hence pk=pa. 

Further we have pb=pa−1 and pk−2=pk−1−1=pk−2=pb−1. This implies a<(k−1), 
hence a≤(k−2)≤b, however, pk−2=pb−1<pb. [Contradiction]

Therefore for each '(' preceded by another '(', we have one such connected 
component (so we add the occurrences of the substring "((" to our answer).

However, we missed the connected component of node 1 (so we add 1 to our answer). [Proved]

Hence we can solve it in O(n).
*/

#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int ans=1;
        for(int i=1; i<2*n; ++i){
            if(s[i]=='('&&s[i-1]=='('){
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
}