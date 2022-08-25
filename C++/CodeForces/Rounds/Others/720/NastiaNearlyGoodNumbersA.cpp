/*

Nastia and Nearly Good Numbers

Nastia has 2 positive integers A and B

She defines that:

    The integer is good if it is divisible by A⋅B

    Otherwise, the integer is nearly good, if it is divisible by A

For example, if A=6 and B=4, the integers 24 and 72 are good, the integers 6, 660 and 12 
are nearly good, the integers 16, 7 are neither good nor nearly good.

Find 3 different positive integers x, y, and z such that exactly one of them is good and 
the other 2 are nearly good, and x+y=z.

Input

3
5 3
13 2
7 11

Output

YES
10 50 60
YES
169 39 208
YES
28 154 182

*/

/*

Good -> divisible by A.B

Nearly Good -> divisible by A

We need to find x, y, y

    such that one of them is good and the other two are nearly good, and
        x + y = z

-------

Let's suppose 
    the first number divisible by A is:
        mA,

    and the other number divisible by A is:
        nA

    the number disivible by A.B is:
        oAB

    If we look at the above three numbers, one thing we can notice is that
        among mA, nA and oAB
            oAB is the largest number

    Therefore we can assign:
        oAB as z
        nA as y
        mA as x

    -------

    From the above equation we get that:
        mA + nA = oAB

        this is basically
            A(m + n) = oAB

            => m + n = oB

    As we don't have to optimize the values, therefore let's assume that
        o = 1

        therefore 
            m + n = B

        let's assume
            m = 1

        therefore
            1 + n = B

        Hence
            n = B - 1
    
    Finally our values are:
        m -> 1
        n -> B - 1
        o -> 1

    -------

    Ans = A + (B - 1)A = AB

    -------

    Some edge cases we have to take into account:
        what if B = 1

        there is no way for B = 1 we can find a solution

        -------

        what is B = 2

            our ans in that case will be:
                A + 3A = 4A
    
*/

#include <bits/stdc++.h>
typedef long long ll;

#define endl "\n"
#define cust                     \
    ios_base::sync_withstdio(0); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;

void solve() {
    ll a, b;
    cin >> a, b;

    if (b == 1) {
        cout << "NO" << endl;
    } else if (b == 2) {
        cout << "YES" << endl;
        cout << a << " " << a * 3 << " " << a * 4 << endl;
    } else {
        cout << "YES" << endl;
        cout << a << " " << a * (b - 1ll) << " " << a * b << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        solve();
    }

    return 0;
}