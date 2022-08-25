/*
Highway 201 is the most busy street in Rockport. Traffic cars cause a lot of hindrances to races, 
especially when there are a lot of them. The track which passes through this highway can be divided into n sub-tracks. 
You are given an array a where ai represents the number of traffic cars in the i-th sub-track. 
You define the inconvenience of the track as ∑i=1 to n ∑j=i+1 to n |ai−aj|, where |x| is the absolute value of x

You can perform the following operation any (possibly zero) number of times: 
choose a traffic car and move it from its current sub-track to any other sub-track.

Find the minimum inconvenience you can achieve.
Input

The first line of input contains a single integer t(1≤t≤10000) — the number of test cases.

The first line of each test case contains a single integer n
(1≤n≤2⋅10^5).

The second line of each test case contains n integers a1,a2,…,an (0≤ai≤10^9).

It is guaranteed that the sum of n over all test cases does not exceed 2⋅10^5

Output

For each test case, print a single line containing a single integer: the minimum inconvenience 
you can achieve by applying the given operation any (possibly zero) number of times.
Example
Input

3
3
1 2 3
4
0 1 1 0
10
8 3 6 11 5 2 1 7 10 4

Output

0
4
21

Note

For the first test case, you can move a car from the 3-rd sub-track to the 1-st sub-track to obtain 0 inconvenience.

For the second test case, moving any car won't decrease the inconvenience of the track.

*/
/*

In the optimal arrangement, 
the number of traffic cars will be distributed as evenly as possible, i.e., |ai−aj|≤1 for each valid (i,j).

Let's sort the array in non-decreasing order. Let a1=p, an=q, p≤q−2, x elements of the array be equal to p, 
y elements of the array be equal to q, ∑i=x+1 to n−y ∑j=i+1 to n−y aj−ai=r and ∑i=x+1 to n−y ai=s

The inconvenience of the track will be equal to S1=r+x⋅[s−(n−x−y)⋅p]+y⋅[(n−x−y)⋅q−s]+[xy⋅(q−p)]

Suppose we increase a1 by 1 and decrease an by 1. Then, the number of occurrences of p and q will reduce by 1, 
two new elements p+1 and q−1 will be formed, and r and s will remain unchanged. 
In such a case, the new inconvenience of the track will be 

S2=r+(x−1)⋅[s−(n−x−y)⋅p] +(y−1)⋅[(n−x−y)⋅q−s] +[(x−1)⋅(y−1)⋅(q−p)] +[s−(n−x−y)⋅(p+1)] +
[(n−x−y)⋅(q−1)−s] +[(y−1)⋅(q−p−1)] +[(x−1)⋅(q−p−1)] +(x−1)+(y−1)+(q−p−2)

Change in inconvenience, 

Δ=S1−S2=[s−(n−x−y)⋅p]+[(n−x−y)⋅q−s]+[(x+y−1)⋅(q−p)]−[s−(n−x−y)⋅(p+1)] −[(n−x−y)⋅(q−1)−s] −[(y−1)⋅(q−p−1)] 
−[(x−1)⋅(q−p−1)] −(x−1)−(y−1)−(q−p−2)

= 2⋅(n−x−y)+(x+y−1)⋅(q−p)−(x+y−2)⋅(q−p−1)−(x−1)−(y−1)−(q−p−2)

= 2⋅(n−x−y)+(q−p)+(x+y−1)−1−(x−1)−(y−1)−(q−p−2) =2⋅(n−x−y+1)>0 as x+y≤n

So, it follows that if p≤q−2 it is always beneficial to move a traffic car from the sub-track with the
highest number of traffic cars to the sub-track with the lowest number of traffic cars. 

If p=q−1, applying this operation won't change the inconvenience as this will only swap the last and the 
first element of the array leaving everything else unchanged. 

If p=q, all the elements of the array are already equal, meaning that we have 0 inconvenience which is 
the minimum possible. So, there is no point in applying any operation.

Now that we have constructed the optimal arrangement of traffic cars, let's find out the value of minimum 
inconvenience of this optimal arrangement. Finding it naively in O(n^2)will time out.

Notice that in the optimal arrangement we will have some (say x) elements equal to some number p+1 and the other 
(n−x) elements equal to p. Let the sum of all elements in a be sum. 

Then, x=sum mod n and p=⌊sum n⌋. For each pair (p,p+1), we will get an absolute difference of 1 and 
for all other pairs, we will get an absolute difference of 0. 

Number of such pairs with difference 1 is equal to x⋅(n−x). 
So, the minimum inconvenience we can achieve is equal to x⋅(n−x). That's all we need to find out!
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        long long s = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            s += a[i];
        }
        long long k = s % n;
        long long ans = k * (n - k);
        cout << ans << "\n";
    }
}