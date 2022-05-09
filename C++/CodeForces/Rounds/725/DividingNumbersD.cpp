
/*
You are given two integers a and b. 

In one turn, you can do one of the following operations:

    Take an integer c (c>1 and a should be divisible by c) and replace a with a/c;

    Take an integer c (c>1 and b should be divisible by c) and replace b with b/c.

Your goal is to make a equal to b using exactly k turns.

For example, the numbers a=36 and b=48 can be made equal in 4 moves:

c=6, divide b by c ⇒ a=36, b=8;
c=2, divide a by c ⇒ a=18, b=8;
c=9, divide a by c ⇒ a=2, b=8;
c=4, divide b by c ⇒ a=2, b=2.

For the given numbers a and b, determine whether it is 
    possible to make them equal using exactly k turns.

Input

The first line contains one integer t
(1≤t≤104). Then t test cases follow.

Each test case is contains three integers a, b and k (1≤a,b,k≤10^9).

Output

For each test case output:

    "Yes", if it is possible to make the numbers a and b equal in exactly k turns;
    "No" otherwise. 

The strings "Yes" and "No" can be output in any case.
Example
Input

8
36 48 2
36 48 3
36 48 4
2 8 1
2 8 2
1000000000 1000000000 1000000000
1 2 1
2 2 1

Output

YES
YES
YES
YES
YES
NO
YES
NO

*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

const int N = 50'000;

bool isPrime[N];
vector<int> primes;

void precalc()
{
    fill(isPrime + 2, isPrime + N, true);
    for (int i = 2; i * i < N; i++)
    {
        for (int j = i * i; j < N; j += i)
        {
            isPrime[j] = false;
        }
    }
    for (int i = 2; i < N; i++)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
        }
    }
}

int calcPrime(int n)
{
    int res = 0;
    for (int i : primes)
    {
        if (i * i > n)
        {
            break;
        }
        while (n % i == 0)
        {
            n /= i;
            res++;
        }
    }
    if (n > 1)
    {
        res++;
    }
    return res;
}

map<int, int> decompose(int n)
{
    map<int, int> a;
    for (int i : primes)
    {
        if (i * i > n)
        {
            break;
        }
        int p = 0;
        while (n % i == 0)
        {
            n /= i;
            p++;
        }
        if (p > 0)
        {
            a[i] = p;
        }
    }
    if (n > 1)
    {
        a[n] = 1;
    }
    return a;
}

bool check(const map<int, int> &divs,
           map<int, int>::const_iterator it,
           map<int, int> &divsA,
           map<int, int> &divsB,
           int low,
           int high,
           int k)
{
    if (it == divs.end())
    {
        return __builtin_popcount(low) <= k && k <= high;
    }
    for (int p = 0; p <= it->second; p++)
    {
        int pa = divsA[it->first];
        int pb = divsB[it->first];
        int nextLow = low;
        if (p != pa)
        {
            nextLow |= 1;
        }
        if (p != pb)
        {
            nextLow |= 2;
        }
        if (check(divs, next(it), divsA, divsB, nextLow, high + pa + pb - 2 * p, k))
        {
            return true;
        }
    }
    return false;
}

void solve()
{
    int a, b, k;
    cin >> a >> b >> k;
    int g = __gcd(a, b);
    int low = 0;
    int high = 0;
    {
        int t;
        int ta = 1;
        while ((t = __gcd(a, g)) != 1)
        {
            a /= t;
            ta *= t;
        }
        high += calcPrime(a);
        if (a != 1)
        {
            low |= 1;
        }
        a = ta;
    }
    {
        int t;
        int tb = 1;
        while ((t = __gcd(b, g)) != 1)
        {
            b /= t;
            tb *= t;
        }
        high += calcPrime(b);
        if (b != 1)
        {
            low |= 2;
        }
        b = tb;
    }
    auto divs = decompose(g);
    auto divsA = decompose(a);
    auto divsB = decompose(b);
    cout << (check(divs, divs.begin(), divsA, divsB, low, high, k) ? "YES" : "NO") << endl;
}

int main()
{
    precalc();

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}