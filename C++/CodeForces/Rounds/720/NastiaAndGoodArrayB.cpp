/*

Nastia has received an array of n positive integers as a gift.

She calls such an array a good such that for all i (2≤i≤n) 
takes place gcd(ai−1,ai)=1, where gcd(u,v) 
denotes the greatest common divisor (GCD) of integers u and v

You can perform the operation: select two different indices i,j
(1≤i,j≤n, i≠j) and two integers x,y (1≤x,y≤2⋅10^9) so that min(ai,aj)=min(x,y). 

Then change ai to x and aj to y

The girl asks you to make the array good using at most n operations.

Input

The first line contains a single integer t (1≤t≤10000) — the number of test cases.

The first line of each test case contains a single integer n
(1≤n≤10^5) — the length of the array.

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤10^9) — 
the array which Nastia has received as a gift.

It's guaranteed that the sum of n in one test doesn't exceed 2⋅10^5

Output

For each of t test cases print a single integer k (0≤k≤n) — the number of operations. 
You don't need to minimize this number.

In each of the next k lines print 4 integers i, j, x, y (1≤i≠j≤n, 1≤x,y≤2⋅109) 
so that min(ai,aj)=min(x,y) — in this manner you replace ai with x and aj with y

If there are multiple answers, print any

Example
Input

2
5
9 6 3 11 15
3
7 5 13

Output

2
1 5 11 9
2 5 7 6
0

*/

/*

There are many ways to solve this question

We can use the fact that gcd(i, i + 1) = 1 for any integer i >= 1

let's find the minimum element x of the array a that is located in the position pos
    Then for all integer i (1 <= i <= n) perform the following operation

    (pos, i, x, x + abs(pos- i))

    That's how we replace 
        ai to x + abs(pos - i)

    The main condition:
        min(ai, aj) = min(x, y) is satisfied because apos always equal to x
            and this value is always less than any other element in the array a

Consider the structure of the array a after performing the operations described above

Let's define l = x + pos - i
      and    r = x + i - pos

These are the leftmost and the rightmost elements in the array a, respectively

The array will look like
    [l, l - 1 .... x + 1, x, x + 1, ... r - 1, r]

    Thus we obtain an absolute difference equal to one between all pairs of adjacent numbers

*/

#include <bits/stdc++.h>
typedef long long ll;

#define endl "\n"
#define cust                     \
    ios_base::sync_withstdio(0); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;

void solve()
{

    int n;
    cin >> n;
    int x = 1e9 + 7, pos = -1;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        if (a < x)
        {
            x = a;
            pos = i;
        }
    }

    // x is storing the min element
    // pos is the index where the min element is

    cout << n - 1 << endl;
    for (int i = 0; i < n; ++i)
    {
        if (i == pos)
            continue;
        cout << pos + 1 << ' ' << i + 1 << ' ' << x << ' ' << x + abs(i - pos) << endl;
    }
}

void solve2()
{
    int n;
    cin >> n;
    int arr[n + 1];
    int min = INT_MAX;
    int index;
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
        if (arr[i] < min)
        {
            index = i;
            min = arr[i];
        }
    }

    // if my min is already 1, then I do not need to make the first operation
    // in which I actually change the min value to the first value
    if (index == 1)
    {
        cout << n - 1 << endl;
        for (int i = 2; i <= n; ++i)
        {
            cout << 1 << " " << i << " " << arr[1] << " " << arr[1] + i - 1 << endl;
        }
    }
    else
    {
        cout << n << endl;
        // very first operation that I need to do for the min value
        cout << 1 << " " << index << " " << arr[index] << " " << arr[1] << endl;
        swap(arr[index], arr[1]);
        cout << arr[index] << endl;
        cout << arr[1] << endl;

        for (int i = 2; i <= n; ++i)
        {
            // making the values strictly increasing
            cout << 1 << " " << i << " " << arr[1] << " " << arr[1] + i - 1 << endl;
            arr[i] = arr[1] + i - 1;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        solve2();
    }
    return 0;
}