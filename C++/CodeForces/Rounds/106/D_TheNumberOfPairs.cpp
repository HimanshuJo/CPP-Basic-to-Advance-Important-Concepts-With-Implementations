// D. The Number of Pairs
/*
You are given three positive (greater than zero) integers c, d and x.

You have to find the number of pairs of positive integers (a,b) such that 
equality c⋅lcm(a,b)−d⋅gcd(a,b)=x holds. 

Where lcm(a,b) is the least common multiple of a and b and gcd(a,b) is the greatest common divisor of a and b.

Input
The first line contains one integer t (1≤t≤10^4) — the number of test cases.

Each test case consists of one line containing three integer c, d and x (1≤c,d,x≤10^7).

Output
For each test case, print one integer — the number of pairs (a,b) such that the above equality holds.

Example
input
4
1 1 3
4 2 6
3 3 7
2 7 25

output
4
3
0
8

Note
In the first example, the correct pairs are: (1,4), (4,1), (3,6), (6,3).

In the second example, the correct pairs are: (1,2), (2,1), (3,3).

*/
/*
Let's represent a as Ag and b as Bg, where g=gcd(a,b) and gcd(A,B)=1. 
By definition lcm(a,b)=ab/g, so we can represent lcm(a,b) as Ag⋅Bg/g=ABg.

Now we can rewrite the equation from the statement as follows: 
c⋅ABg−d⋅g=x⟹g(c⋅AB−d)=x. 

Since the left-hand side is divisible by g, the right-hand side should also be divisible. 
So we can iterate over g as divisors of x. 

If the right-hand side of c⋅AB=x/g+d is not divisible by c then we can skip such g. 
AB=(x/g+d)/c (let's denote as k). 
If k has some prime divisor p then exactly one of A and B should be divisible by p 
because gcd(A,B)=1 (A and B have no common divisors). 
So there are 2^the number of prime divisors of k pairs of A and B for 
current value of g.

We can precalculate the minimum prime divisor for each number up to 2⋅10^7 
(the maximum value of k that you may need) in O(2⋅10^7loglog(2⋅10^7)) using Eratosthenes sieve. 
Now we can solve the problem in O(x−−√logx) for each testcase, 

but that's not fast enough. To speed up this approach, we can precalculate the number of 
prime divisors for each number up to 2⋅10^7. Let's denote mindi as the minimum prime divisor of 
i and vali as the number of prime divisors of i. 

Then vali=vali/mindi plus 1 if mindi≠mindi/mindi. 
Now, to solve the problem, we only need to iterate over the divisors of x, 
so the time complexity is O(√x) per testcase.
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 2e7 + 13;

int main() {
  vector<int> mind(N, -1), val(N);
  mind[1] = 1;
  for (int i = 2; i < N; ++i) if (mind[i] == -1)
    for (int j = i; j < N; j += i) if (mind[j] == -1)
      mind[j] = i;
  for (int i = 2; i < N; ++i) {
    int j = i / mind[i];
    val[i] = val[j] + (mind[i] != mind[j]);
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int c, d, x;
    scanf("%d%d%d", &c, &d, &x);
    int ans = 0;
    for (int i = 1; i * i <= x; ++i) {
      if (x % i != 0) continue;
      int k1 = x / i + d; 
      if (k1 % c == 0) ans += 1 << val[k1 / c];
      if (i * i == x) continue;
      int k2 = i + d;
      if (k2 % c == 0) ans += 1 << val[k2 / c]; 
    }
    printf("%d\n", ans);
  }
}