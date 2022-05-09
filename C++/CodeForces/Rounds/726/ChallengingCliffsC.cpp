/*
You are a game designer and want to make an obstacle course. 
The player will walk from left to right. You have n heights of mountains already selected and want 
to arrange them so that the absolute difference of the heights of the first and last mountains 
is as small as possible.

In addition, you want to make the game difficult, and since walking uphill or flat is harder than 
walking downhill, the difficulty of the level will be the number of mountains i (1≤i<n) such that 
hi≤hi+1 where hi is the height of the i-th mountain. You don't want to waste any of the mountains you 
modelled, so you have to use all of them.

From all the arrangements that minimize |h1−hn|, find one that is the most difficult. 
If there are multiple orders that satisfy these requirements, you may find any.

Input

The first line will contain a single integer t (1≤t≤100) — the number of test cases. Then t test cases follow.

The first line of each test case contains a single integer n
(2≤n≤2⋅10^5) — the number of mountains.

The second line of each test case contains n integers h1,…,hn (1≤hi≤109), where 
hi is the height of the i-th mountain.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅10^5

Output

For each test case, output n integers — the given heights in an order that maximizes the difficulty 
score among all orders that minimize |h1−hn|

If there are multiple orders that satisfy these requirements, you may output any.

Example
Input

2
4
4 2 1 2
2
3 1

Output

2 4 1 2 
1 3
*/

/*
Intuition:

    For every i, after re-arranging if a[i] < a[i + 1], then in that case our difficulty will be +1

    We want to maximize the difficulty

    -------

    To solve this optimally, firstly we want to find our first and the last element

        In our array initially we have to find such a pair so that the minimum absolute difference
            between the elements is minimum

        To do that optimally we have to initially sort our array (because of sorting we can find x and y in a single
            loop)

            because suppose x and y are the two elements and x is in the 'i'th position,
                and y will always be in the 'i+1'th position

        For the middle elements, we have to arrange them in a specifc order so that the difficulty level
            would get increased

            if we put the elements in strictly increasing order such that
                a < b < c < d < e, it is for sure at each step the difficulty level will be +1

            In this particular case there will only be two points where the difficulty level will not increase

            -------

            We can do better and put the elements in such an order that the difficulty level will be
                increased in all the levels except one

            How to make such an arrangement:

                First we will start placing all the elements which are greater than the first element
                    just after the first element

                    then we'll place the remaining elements

            e.g.

                ..........x y.......

                Suppose x and y are our pairs, so initially,
                
                    we will place y at the starting position and all the elements after y
                        we will starting placing after y

                    then we'll place all the elements left to x

                    finally x
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
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        int x = 0, y = 1;
        int diff = abs(a[y] - a[x]);
        for (int i = 1; i < n - 1; ++i)
        {
            if (a[i + 1] - a[i] < diff)
            {
                diff = abs(a[i + 1] - a[i]);
                x = i;
                y = i + 1;
            }
        }
        cout << a[x] << " ";
        for (int i = y + 1; i < n; ++i)
        {
            cout << a[i] << " ";
        }
        for (int i = 0; i < x; ++i)
        {
            cout << a[i] << " ";
        }
        cout << a[y] << "\n";
    }
}