// B. MEX and Array
/*
Let there be an array b1,b2,…,bk. Let there be a partition of this array into segments 
[l1;r1],[l2;r2],…,[lc;rc], where l1=1, rc=k, and for any 2≤i≤c holds that ri−1+1=li. 

In other words, each element of the array belongs to exactly one segment.

Let's define the cost of a partition as
	
	c+∑i=1cmex({bli,bli+1,…,bri}),

where mex of a set of numbers S is the smallest non-negative integer that does not occur in the set S. 
In other words, the cost of a partition is the number of segments plus the sum of MEX over all segments. 
Let's define the value of an array b1,b2,…,bk as the maximum possible cost over all partitions of this array.

You are given an array a of size n. Find the sum of values of all its subsegments.

An array x is a subsegment of an array y if x can be obtained from y by deletion of several 
(possibly, zero or all) elements from the beginning and several (possibly, zero or all) elements from the end.

Input
The input contains several test cases. The first line contains one integer t (1≤t≤30) — the number of test cases.

The first line for each test case contains one integer n (1≤n≤100) — the length of the array.

The second line contains a sequence of integers a1,a2,…,an (0≤ai≤10^9) — the array elements.

It is guaranteed that the sum of the values n over all test cases does not exceed 100.

Output
For each test case print a single integer — the answer to the problem.

Example
input
4
2
1 2
3
2 0 1
4
2 0 5 1
5
0 1 1 0 1

output
4
14
26
48
Note
In the second test case:

The best partition for the subsegment [2,0,1]: [2],[0,1]. The cost of this partition equals to 2+mex({2})+mex({0,1})=2+0+2=4.
The best partition for the subsegment [2,0]: [2],[0]. The cost of this partition equals to 2+mex({2})+mex({0})=2+0+1=3
The best partition for the subsegment [2]: [2]. The cost of this partition equals to 1+mex({2})=1+0=1.
The best partition for the subsegment [0,1]: [0,1]. The cost of this partition equals to 1+mex({0,1})=1+2=3.
The best partition for the subsegment [0]: [0]. The cost of this partition equals to 1+mex({0})=1+1=2.
The best partition for the subsegment [1]: [1]. The cost of this partition equals to 1+mex({1})=1+0=1.
The sum of values over all subsegments equals to 4+3+1+3+2+1=14.
*/
/*
Solution:

We show, that replacing a segment of length k (k>1) with segments of length 1 does not decrease the cost of the partition. 

Consider two cases:

The segment does not contain 0.
The segment contains 0.

In the first case the contribution of the segment equals to 1 (because mex=0), but the contribution of k segments of 
length 1 equals to k. So the cost increased. 

In the second case the contribution of the segment equals to 1+mex<=1+k, but the contribution of the segments of 
length 1 would be at least 1+k, so the cost has not decreased.

Then it is possible to replace all segments of length more than 1 by segments of length 1 and not decrease the cost. 
So the value of the array b1,b2,…,bk equals to ∑i=1 to k (1+mex({bi})) = k + (the number of zeros in the array).

To calculate the total value of all subsegments, you need to calculate the total length of all subsegments and the 
contribution of each 0. The total length of all subsegments equals to n⋅(n+1)⋅(n+2)/6.

The contribution of a zero in the position i equals to i⋅(n−i+1). This solution works in O(n), 
but it could be implemented less efficiently.

There is also another solution, which uses dynamic programming: let dpl,r is the value of the array al,al+1,…,ar. 
Then dpl,r=max(1+mex({al,al+1,…,ar}),maxr−1c=l(dpl,c+dpc+1,r)). 

This solution can be implemented in O(n^3) or in O(n^4).
*/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& u : a)
            cin >> u;
 
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (i + 1) * (n - i);
            if (a[i] == 0)
                ans += (i + 1) * (n - i);
        }
        cout << ans << '\n';
    }
}