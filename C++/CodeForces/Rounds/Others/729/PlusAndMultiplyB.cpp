
// Plus and Multiply
/*
There is an infinite set generated as follows:

1 is in this set.

If x is in this set, x⋅a and x+b both are in this set.

For example, when a=3 and b=6, the five smallest elements of the set are:

1,
3 (1 is in this set, so 1⋅a = 3 is in this set),
7 (1 is in this set, so 1+b = 7 is in this set),
9 (3 is in this set, so 3⋅a = 9 is in this set),
13 (7 is in this set, so 7+b = 13 is in this set)

Given positive integers a, b, n, determine if n is in this set.

Input

The input consists of multiple test cases. The first line contains an integer t (1≤t≤10^5) — the number of test cases. 
The description of the test cases follows.

The only line describing each test case contains three integers n, a, b (1≤n,a,b≤10^9) separated by a single space.
Output

For each test case, print "Yes" if n is in this set, and "No" otherwise. You can print each letter in any case.

Output

For each test case, print "Yes" if n is in this set, and "No" otherwise. You can print each letter in any case.
Example
Input

5
24 3 5
10 3 6
2345 1 4
19260817 394 485
19260817 233 264

Output

Yes
No
Yes
No
Yes

Note

In the first test case, 24 is generated as follows:

1 is in this set, so 3 and 6 are in this set;
3 is in this set, so 9 and 8 are in this set;
8 is in this set, so 24 and 13 are in this set. 

Thus we can see 24 is in this set.

The five smallest elements of the set in the second test case is described in statements. 
    We can see that 10 isn't among them.
*/

/*
    According to the question, if there is a number (let's say 'x') that exists in the set, then with x
        x*a and x+b will also exists

        suppose we take x*a = c, and x+b = d

        Now suppose our array looks like this:

            1, c, d, _, _, _, _, _, _, ...

        Now for c again the elements that will exists are:
            c*a and c+b

        for d:

            d*a and d+b

        and so on

    -------

    Suppose there is a number 'z' that exists in the set
        we've to observe here just one thing:
            z will be in the format
                z = a^x + y*b

        How to find the equation for z:

            suppose z = 1*a*a*a+b*a*a+b
                the operations will always follow the direction from left to right

                => z = a^3 + b*a*a + b
                     = (a^3 + b)*a*a + b
                     = (a^4 + ba)*a + b
                     = (a^5 + a^2b) + b
                     = (a^5 + a^2b + b)
                     = a^5 + (a^2 + 1)b

                Hence the above equation follows the pattern:

                    a^x + yb
                        here x = 5, and y = (a^2+1)

    -------

    Now from here we have two options:

        either we remove -b from the equation until we are left with a^x

            finally we check whether the end number is in (a^something) or not

        But here there are chances of TLE

    The other thing what we can do is that:

        z = a^x + yb

            here we will remove a^x and for the remaining number we'll check whether the remaining
                number is divisible by b or not

        How to remove a^x

            first we'll try:
                z - a^0, suppose it is L (we'll check here whether it is divisible by b or not)
            if not, then we'll try
                z - a^1 and so on
*/

#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {   
        ll a, b, n;
        cin >> n >> a >> b;
        ll s = 1;
        int flag = 0;
        /*
            Suppose a=1, then we've a problem because then we'll be taking firstly
                a^0, then a^1, a^2 and so on and no matter what power do we use it'll always remain 1
            (so here we'll face an infinite loop in this case)

            if a == 1, then n  = 1^x + yb
                       =>  n-1 = yb

                      hence, n in our answer will only exist when y is a whole number
                        so, we'll check if (n-1)/b exists then y exist
        */
        if (a == 1)
        {
            if ((n - 1) % b == 0)
            {
                cout << "YES"
                     << "\n";
            }
            else
            {
                cout << "NO"
                     << "\n";
            }
            continue;
        }
        /*
            Else the other case, where we've to remove a^x
            in the s initially we'll store a^0
            then a^1, a^2 and so on
        */
        while (s <= n)
        {
            /*
                here n is in the format:
                    n = a^x + yb
                    if we perform (a^x + yb) - s and the result is equal to a^x then
                        yb is divisible by b
            */
            if ((n - s) % b == 0)
            {
                flag = 1;
                break;
            }
            s *= a;
        }
        if (flag)
        {
            cout << "YES"
                 << "\n";
        }
        else
        {
            cout << "NO"
                 << "\n";
        }
    }
}