// Integers have friends
//Written by emorgan5289 (Runtime: 218ms)
/*
British mathematician John Littlewood once said about Indian mathematician Srinivasa Ramanujan 
that "every positive integer was one of his personal friends."

It turns out that positive integers can also be friends with each other! 
You are given an array a of distinct positive integers.

Define a subarray ai,ai+1,…,aj to be a friend group if and only if there exists an 
integer m≥2 such that aimodm=ai+1modm=…=ajmodm, where xmody denotes the remainder when x is divided by y.

Your friend Gregor wants to know the size of the largest friend group in a.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤2⋅10^4).

Each test case begins with a line containing the integer n (1≤n≤2⋅10^5), the size of the array a.

The next line contains n positive integers a1,a2,…,an (1≤ai≤10^18), representing the 
contents of the array a. It is guaranteed that all the numbers in a are distinct.

It is guaranteed that the sum of n over all test cases is less than 2⋅10^5.

Output
Your output should consist of t lines. Each line should consist of a single integer, 
the size of the largest friend group in a.

Example
input
4
5
1 5 2 4 6
4
8 2 5 10
2
1000 2000
8
465 55 3 54 234 12 45 78

output
3
3
2
6

Note
In the first test case, the array is [1,5,2,4,6]. The largest friend group is [2,4,6], 
since all those numbers are congruent to 0 modulo 2, so m=2.

In the second test case, the array is [8,2,5,10]. The largest friend group is [8,2,5], 
since all those numbers are congruent to 2 modulo 3, so m=3.

In the third case, the largest friend group is [1000,2000]. There are clearly many possible values of m that work.
*/

/*
The key observation is to construct the difference array D of size N−1, 
where D[i]=abs(A[i+1]−A[i]). If a given subarray is a friend group, 
then every difference is a multiple of some m. Since every element of A is distinct, 
the case when D[i]=0 can be ignored.

We can now convert this into a GCD (greatest common divisor) problem. 
It follows that A[i…j] is a friend group if and only if gcd(D[i…j−1])>1. 
Indeed, the value m that we want is equal to this GCD.

To solve the problem, we can use a sparse table or a segment tree to 
find the largest possible subarray beginning at i, and then max over all subarray answers to get the final answer.

The time complexity is O(NlogNlog1018). The first log is for the sparse table, the second is for computing GCDs.

Note that the de facto time complexity may be closer to O(NlogN+Nlog10^18)
*/

#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))
 
template<typename it, typename bin_op>
struct sparse_table {
 
    using T = typename remove_reference<decltype(*declval<it>())>::type;
    vector<vector<T>> t; bin_op f;
 
    sparse_table(it first, it last, bin_op op) : t(1), f(op) {
        int n = distance(first, last);
        t.assign(32-__builtin_clz(n), vector<T>(n));
        t[0].assign(first, last);
        for (int i = 1; i < t.size(); i++)
            for (int j = 0; j < n-(1<<i)+1; j++)
                t[i][j] = f(t[i-1][j], t[i-1][j+(1<<(i-1))]);
    }
 
    // returns f(a[l..r]) in O(1) time
    T query(int l, int r) {
        int h = floor(log2(r-l+1));
        return f(t[h][l], t[h][r-(1<<h)+1]);
    }
};
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> a(n), d(n-1);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n-1; i++)
            d[i] = abs(a[i+1]-a[i]);
        sparse_table g(all(d), [](ll x, ll y){
            return __gcd(x, y);
        });
        int j = 0, ans = 1;
        for (int i = 0; i < n-1; i++) {
            while (j <= i && g.query(j, i) == 1) j++;
            cmax(ans, i-j+2);
        }
        cout << ans << "\n";
    }
}