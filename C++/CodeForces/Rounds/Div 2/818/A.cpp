// A. Madoka and Strange Thoughts
/*
Madoka is a very strange girl, and therefore she suddenly wondered how many pairs of integers (a,b) 
exist, where 1≤a,b≤n, for which lcm(a,b)gcd(a,b)≤3.

In this problem, gcd(a,b) denotes the greatest common divisor of the numbers a and b, 
and lcm(a,b) denotes the smallest common multiple of the numbers a and b.

Input
The input consists of multiple test cases. The first line contains a single integer t (1≤t≤10^4) — 
the number of test cases. Description of the test cases follows.

The first and the only line of each test case contains the integer n (1≤n≤10^8).

Output
For each test case output a single integer — the number of pairs of integers satisfying the condition.

Example
input
6
1
2
3
4
5
100000000

output
1
4
7
10
11
266666666

Note
For n=1 there is exactly one pair of numbers — (1,1) and it fits.

For n=2, there are only 4 pairs — (1,1), (1,2), (2,1), (2,2) and they all fit.

For n=3, all 9 pair are suitable, except (2,3) and (3,2), since their lcm is 6, 
and gcd is 1, which doesn't fit the condition.
*/

/*
Algo:

Let d=gcd(a,b). Now notice that it's impossible that a=k⋅d for some k>4,
because otherwise lcm will be at least k⋅d>3⋅d. Therefore the only possible cases are the pairs 
listed above and (2⋅d,3⋅d), but in the latter case we have lcm=6⋅d.

The number of the pairs of the first kind is n, of the second kind is 2⋅⌊n/2⌋, 
and of the third kind is 2⋅⌊n/3⌋ (the factor 2 in the latter two formulae arises from the fact that pairs are ordered). 
Therefore, the answer to the problem is n+2⋅(⌊n/2⌋+⌊n/3⌋).
*/

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<int(n+2*(n/2)+2*(n/3))<<endl;
    }
}