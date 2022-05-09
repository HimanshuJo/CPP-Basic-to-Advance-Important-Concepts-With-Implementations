// Unique Subsequence
/*
Problem Statement
Given is a sequence of N integers A1,A2,⋯,AN

Find the number of non-empty subsequences s of A satisfying 
the following condition, modulo 998244353.

There is only one way to extract s from A. 
Formally, there uniquely exists a sequence of indices 
1≤idx(1)<idx(2)<⋯<idx(k)≤N such that

A_idx(i)=si(1≤i≤k), where s=(s1,s2,⋯,sk)

Sample Input 1 

3
1 2 1

Sample Output 1 

5
The following five subsequences satisfy the condition.

(1,1)
(1,2)
(1,2,1)
(2)
(2,1)
The subsequence (1) does not satisfy the condition since 
there are two ways to extract it.
*/

#include <bits/stdc++.h>
using namespace std;
constexpr int P = 998244353;
const int maxx=200001;
using i64 = long long;
// assume -P <= x < 2P
int norm(int x)
{
    if (x < 0)
    {
        x += P;
    }
    if (x >= P)
    {
        x -= P;
    }
    return x;
}
template <class T>
T power(T a, int b)
{
    T res = 1;
    for (; b; b /= 2, a *= a)
    {
        if (b % 2)
        {
            res *= a;
        }
    }
    return res;
}
struct Z
{
    int x;
    Z(int x = 0) : x(norm(x)) {}
    int val() const
    {
        return x;
    }
    Z operator-() const
    {
        return Z(norm(P - x));
    }
    Z inv() const
    {
        assert(x != 0);
        return power(*this, P - 2);
    }
    Z &operator*=(const Z &rhs)
    {
        x = i64(x) * rhs.x % P;
        return *this;
    }
    Z &operator+=(const Z &rhs)
    {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs)
    {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs)
    {
        return *this *= rhs.inv();
    }
    friend Z operator*(const Z &lhs, const Z &rhs)
    {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs)
    {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs)
    {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs)
    {
        Z res = lhs;
        res /= rhs;
        return res;
    }
};

template <typename T>
struct Fenwick
{
    const int n;
    std::vector<T> a;
    Fenwick(int n) : n(n), a(n) {}
    void add(int x, T v)
    {
        for (int i = x + 1; i <= n; i += i & -i)
        {
            a[i - 1] += v;
        }
    }
    T sum(int x)
    {
        T ans = 0;
        for (int i = x; i > 0; i -= i & -i)
        {
            ans += a[i - 1];
        }
        return ans;
    }
    T rangeSum(int l, int r)
    {
        return sum(r) - sum(l);
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    vector<int>a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        a[i]--;
    }

    Fenwick<Z> fen(maxx);
    fen.add(maxx-1, 1);

    int f[maxx];
    std::fill(f, f + (maxx-1), maxx-1);

    Z dp[maxx];

    for (int i = n - 1; i >= 0; i--)
    {
        dp[i] = fen.sum(f[a[i]] + 1);
        if (f[a[i]] < n)
        {
            fen.add(f[a[i]], -dp[f[a[i]]]);
        }
        f[a[i]] = i;
        fen.add(i, dp[i]);
    }

    Z res;
    for (int i = 0; i < n; i++)
    {
        if (f[i] < n)
        {
            res += dp[f[i]];
        }
    }

    std::cout << res.val() << "\n";

    return 0;
}
