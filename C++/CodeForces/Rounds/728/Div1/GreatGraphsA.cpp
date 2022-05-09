// Great Graphs
/*
Farmer John has a farm that consists of n pastures connected by one-directional roads.
Each road has a weight, representing the time it takes to go from the start to the end of the road.
The roads could have negative weight, where the cows go so fast that they go back in time!
However, Farmer John guarantees that it is impossible for the cows to get stuck in a time loop, 
where they can infinitely go back in time by traveling across a sequence of roads.
Also, each pair of pastures is connected by at most one road in each direction.

Unfortunately, Farmer John lost the map of the farm. All he remembers is an array d, 
where di is the smallest amount of time it took the cows to reach the i-th pasture from 
pasture 1 using a sequence of roads.
The cost of his farm is the sum of the weights of each of the roads, 
and Farmer John needs to know the minimal cost of a farm that is consistent with his memory.

Input

The first line contains one integer t (1≤t≤10^4) — the number of test cases. Then t cases follow.

The first line of each test case contains a single integer n
(1≤n≤10^5) — the number of pastures.

The second line of each test case contains n space separated integers d1,d2,…,dn (0≤di≤10^9) — 
the array d. It is guaranteed that d1=0

It is guaranteed that the sum of n over all test cases does not exceed 10^5

Output

For each test case, output the minimum possible cost of a farm that is consistent 
with Farmer John's memory.
*/

/*
Intuition:

    Suppose we have n = 3, and the input we have is 0, 2, 3

        That means that if we have some king of directed graph that has three nodes
                1   2   3

                then we know that the shortest distance from:
                    1 to 1 = 0
                    1 to 2 = 2
                    1 to 3 = 3

        Our goal is to add as many directed edges as possible such that the sum of all the weights
            is minimized

            In the special cases, we're allowed to have edges of negative weight

            However, we can't have any negative cycles

    -------

    Because the fact that we can add negative edge weights to minimize the answer, it's logical
        to think of having edges between all the possible pairs

    In total we can add (n (n - 1)) edges to a graph of size n, as it's a directed graph

    Logically thinking, we wan to be able to add all (n (n - 1)) edges, but we can't add negative
        edges carelessly, as we have to maintain teh shortest distance

    -------

    We can visualize the graph as follows:

        If I were to re-label the graph and all its nodes with different node values, how can I do that

            e.g.n=3 array is {0, 3, 1}

                then we know that the shortest distance from:
                    1 to 1 = 0
                    1 to 2 = 3
                    1 to 3 = 1

            We can essentially re-label the node 2 to 3 and node 3 to 2

                that will just change our array to 0, 1, 3 (it is still the same problem)

                we don't really care about what nodes are assigned what, all we care about the 
                    distances, as all the time we have the distance from the starting node

        -------
        
        So we can sort the array in an increasing order

            e.g. n=4 array is {0, a, b, c, d}
                    and because we sorted our array so we know that:
                        0<=a<=b<=c

        So we can arrange the array elements as a line

            1 -> 2 -> 3 -> 4 -> 5

            from 1 to 2 we can assign the edge of +a
            from 2 to 3 we can assign the edge of +(b - a)
            from 3 to 4 we can assign the edge of +(c - b)

            This arrangement will satisfy all the shortest distance criteria
                because there is only one possible path from 1 to any other node
        
        -------

        How to assign the negative edges so that we minimize all of the edge weights
            while keeping the shortest distance valid:

            Suppose we are at some node that is not 1, and we want to go back to the initial
                state we're on

                suppose we are 3 and want to go back to 1

                    so from 1 to 3, we traveled b
                    to go back we have to travel -b

                similarly suppose we are 2 and current distance we have travelled is a
                    to go back we have to travel -a

                similarly, suppose we are node 4 and want to go back to node 2
                    to go back we have to travel:

                        from 2 -> 3 we travelled b-a
                        from 3 -> 4 we travelled c-b

                        so to go back -(b -a + c - b) = -(c - a) = a - c

        -------

        Now we've realized that the sum of all the negative edge weights is a sum multiple
            of these differences

            e.g:

                -a -> is difference of 0 and a

            every negative edge can essentially be visualize as a range (as if, how many positive
                weight edges it is covering while going back)

            and we want to figure out for each of these differences, how many ranges does it cover by

        -------

        The way we can do that is for every difference, we can just count how many:
            left-end points exists and
            right-end points exists

            e.g. for the first edge of 0-a, we know that:
                    there is only one choice of a node so that we can represent that as a left-end point
                    and three choices for a node so that we can represent that as a right-end point

                    therefore we perform: (0-a) * 1 * 3
                    similarly for (a-b): (a-b) * 2 * 2
*/

#include <cstdio>
#include <algorithm>
using ll = long long;
using namespace std;
int t, n, d[100001];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        int max = 0;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", d + i);
        }
        sort(d + 1, d + n + 1);
        ll ans = d[n];
        for (int i = n; i >= 0; --i)
        {
            ans += 1ll * d[i] * (n - i);
            ans -= 1ll * d[i] * (i - 1);
        }
        printf("%lld\n", ans);
    }
}