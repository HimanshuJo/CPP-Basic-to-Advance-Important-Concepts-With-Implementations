
/*
    So in our question we have a function, f(i) = x
        where x is that smallest integer that is not the divisor of i
    e.g. f(12) = 5
            as 1 divides 12
               2 also divides 12
               3 also divides 12
               4 also divides 12, but 5 doesn't divide 12      

    We need to find  ∑i=1 to n f(i)

    -------

    Intuition:

        We have given that f(i) = x, therefore the numbers from 1 till x-1 all will divide i (or are the divisors of i)

        e.g. f(12) = 5

            hence the numbers from 1 till 4 are the divisors of 12

            so it's nothing but 12 is the LCM of (1, 2, 3, 4)

        * Therefore the first number whose f(i) = 5 will be 12, now we need to find the next of such numbers

        What will be the next few numbers whose f(i) = 5 will be:
            24 (which is nothing but 12 * 2)
            36 (which is nothing but 12 * 3)
            48 (which is nothing but 12 * 4)

        However, if we again move here 12 steps further, we'll get 60
            but 60 is divided by 5

        -------

        So how many numbers are there between 1 till n, whose f(i) = 5
            we can happily include all the numbers starting from 12 then 12 steps further, but we can't take
                the 5'th of such number (e.g. 60)

                again we can continue after that
                    e.g. 12 * 6 = 72
                         12 * 7 = 84
                         12 * 8 = 96
                         12 * 9 = 108

                    however, again 12 * 10 is divided by 5 therefore we have to exclude it

        Now we have to calculate between 1 to n, how many time 12 will come:
            that will be: n/12

            suppose n = 40
                n/12 = 3 (between 1 till 40, 12 comes 3 times; those are 12, 24, 36) <- here we don't have 60
                    so no need to remove that

            suppose n=90, here 12 will come 90/12 = 7
                (12, 24, 36, 48, 60, 72, 84)

            Now here we've to remove every 5'th number (here only 60 will be removed)

        -------

        How to calculate which number we've to remove:

            If we notice closely 60 is nothing but lcm of (1, 2, 3, 4, 5)
                therefore between 1 till n every 60th number we've to remove

        -------

        Suppose n = 130, here 12 will come 130/12 = 10 times

                         hee 60 will come 130/60 = 2 times

            Therefore, we have to remove 2 numbers from 10

        -------

        Therefore until now we've calculate from 1 till n how many numbers are there whose
            f(i) = x (in the above example x = 5)

        our formula is:

            n/lcm(1 .. till x-1) - n/lcm(1 .. till x)

        Suppose we got to know that from 1 till n suppose there are 6 numbers,
            whose f(i) = 5

            in the question we just have to find ∑i=1 to n f(i)

                so for all these 6 numbers there contribution in the answer is:
                    ans += 5*6

            To calculate f(i) = x (we won't calculate x by placing the values of i, rather we will calculate
                for a particular x how many i's are there)

        -------

        We'll be iterating starting from 2, 3, 4, 5, ....

            We will calculate how many i's are there, for which x = 2
                              how many i's are there, for which x = 3 and so on

            the loop will end even before reaching 100


*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int lcm = 1;
        int res = 0;
        for (int i = 2;; i++)
        {
            int temp1 = n / lcm;
            lcm = lcm * i / __gcd(lcm, i);
            int temp2 = n / lcm;
            res += (temp1 - temp2) * i;
            res %= MOD;
            if (lcm > n)
                break;
        }
        cout << res << '\n';
    }
    return 0;
}