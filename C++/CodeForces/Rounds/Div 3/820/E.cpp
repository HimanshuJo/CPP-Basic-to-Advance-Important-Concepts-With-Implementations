// E. Guess the Cycle Size
/*
This is an interactive problem.

I want to play a game with you...

We hid from you a cyclic graph of n vertices (3≤n≤10^18). A cyclic graph is an undirected graph of n 
vertices that form one cycle. Each vertex belongs to the cycle, i.e. the length of the cycle 
(the number of edges in it) is exactly n. The order of the vertices in the cycle is arbitrary.

You can make queries in the following way:

"? a b" where 1≤a,b≤10^18 and a≠b. In response to the query, the interactor outputs on a separate line 
the length of random of two paths from vertex a to vertex b, or -1 if max(a,b)>n. 

The interactor chooses one of the two paths with equal probability. The length of the path —is 
the number of edges in it.

You win if you guess the number of vertices in the hidden graph (number n) by making no more than 50 queries.

Note that the interactor is implemented in such a way that for any ordered pair (a,b), 
it always returns the same value for query "? a b", no matter how many such queries. 

Note that the "? b a" query may be answered differently by the interactor.

The vertices in the graph are randomly placed, and their positions are fixed in advance.

Hacks are forbidden in this problem. The number of tests the jury has is 50.

Interaction
You can make no more than 50 of queries. To make a query, output on a separate line:

"? a b", where 1≤a,b≤1018 and a≠b. In response to the query, the interactor will output on a 
separate line the length of a random simple path from vertex a to vertex b (not to be confused 
with the path from b to a), or −1 if max(a,b)>n. 

The interactor chooses one of the two paths with equal probability.

If your program gets a number 0 as a result of a query, it means that the verdict for your solution 
is already defined as "wrong answer" (for example, you made more than 50 queries or made an invalid query). 
In this case, your program should terminate immediately. Otherwise, in this scenario you may get 
a random verdict "Execution error", "Exceeded time limit" or some other verdict instead of "Wrong answer".

The answer, like queries, print on a separate line. The output of the answer is not counted as a 
query when counting them. To print it, use the following format:

"! n": the expected size of the hidden graph (3≤n≤10^18).
After that, your program should terminate.

After the output of the next query, be sure to use stream cleaning functions so that some 
of your output is not left in some buffer. For example, in C++ you should use function 
flush(stdout), in Java call System.out.flush(), in Pascal flush(output) and stdout.flush() for Python.

Note that the interactor is implemented in such a way that for any ordered pair (a,b), 
it always returns the same value for query "? a b", no matter how many such queries. 

Note that the "? b a" query may be answered differently by the interactor.

The vertices in the graph are randomly placed, and their positions are fixed in advance.

Hacks are forbidden in this problem. The number of tests the jury has is 50.

Example
input

1

2

-1

output
? 1 2

? 1 3

? 1 4

! 3
*/

/*
The implication was that the solution works correctly with some high probability. 
So we tried to give such constraints so that the solution probability is very high.

The idea: we will output queries of the form (1,n) and (n,1), gradually increasing n from 2. 
If we get an answer to query −1 the first time, then the size of the graph is exactly n−1.

Otherwise, let the answer to the first query be x and the answer to the second query be y.

With probability 12,x≠y. In this case, we can output the answer: x+y, since there 
are a total of two different paths from vertex 1 to n and we recognized them. 

Accordingly the total length of paths will be the size of the cyclic graph.

But with probability 12,x=y. In this case we must continue the algorithm. 
At most we can make 25 of such attempts.

Let's calculate the probability of finding the correct graph size: p=1−(1/2)^25.

That is, we "lucky" on one test with probability p≈0.99999997. 
But we should have "lucky" on 50 tests. We get: P=p^50≈0.99999851.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#define endl "\n"
using ll=long long;
using namespace std;

ll query(ll vertA, ll vertB){
    cout<<"? "<<vertA<<" "<<vertB<<endl;
    ll x;
    cin>>x;
    return x;
}

int main(){
    int max_queries=50;
    int bgn=1;
    ll ans=0;
    for(int i=2; i<=max_queries/2; ++i){
        ll pth1=query(bgn, i);
        ll pth2=query(i, bgn);
        if(pth1==-1){
            ans=i-1;
            break;
        }
        if(pth1!=pth2){
            ans=pth1+pth2;
            break;
        }
    }
    cout<<"! "<<ans<<endl;
}