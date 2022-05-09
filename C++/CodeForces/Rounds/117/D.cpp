// D. X-Magic Pair
/*
You are given a pair of integers (a,b) and an integer x.

You can change the pair in two different ways:

set (assign) a:=|a−b|;
set (assign) b:=|a−b|,
where |a−b| is the absolute difference between a and b.
The pair (a,b) is called x-magic if x is obtainable either as a or as b using only the given operations 
(i.e. the pair (a,b) is x-magic if a=x or b=x after some number of operations applied). 

You can apply the operations any number of times (even zero).

Your task is to find out if the pair (a,b) is x-magic or not.

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤104) — the number of test cases. The next t lines describe test cases.

The only line of the test case contains three integers a, b and x (1≤a,b,x≤10^18).

Output
For the i-th test case, print YES if the corresponding pair (a,b) is x-magic and NO otherwise.

Example
input
8
6 9 3
15 38 7
18 8 8
30 30 30
40 50 90
24 28 20
365 216 52
537037812705867558 338887693834423551 3199921013340

output
YES
YES
YES
YES
NO
YES
YES
YES
*/
/*
Solution:

This problem has a GCD-based solution.

Firstly, lets' try to solve it naively. Always suppose that a>b. If this is not true, 
let's swap a and b. Firstly, if b>a−b, let's do b:=a−b. Okay, now let's subtract b from a until b≥a−b again 
and repeat this algorithm till a=0 or b=0. If, after some step, we get a=x or b=x, we are done, and the answer is YES. 

If a=0 or b=0, and we didn't get x then the answer is NO.

Okay, we can see that we always subtract the minimum possible b from a and trying to maintain this condition. 
It can be proven that this algorithm yields all possible integers that are obtainable by any sequence of the operations 
from the problem statement (either in a or in b).

Now we have to speed up this solution somehow. Obviously, most operations are redundant for us in this particular problem.

The first thing is that we can skip all operations till b becomes greater than a−b. The number of such operations is ⌊a−b/2b⌋. 
And the second thing is that we can skip all operations till we get x in a. The number of such operations is ⌊a−x/b⌋. 

For simplicity, this part can be also written as ⌊a−x/2b⌋. This doesn't affect the time complexity much, but the 
formula for the final number of operations we can skip will be simpler. 

This number equals cnt=max(1,⌊a−max(b,x)/2b⌋) (in fact, we take the minimum between two values written above, 
because we don't want to skip any of these two cases). 

So, we can transform the pair (a,b) to the pair (a−b∗cnt,b) and continue this algorithm.

There are also simpler approaches using the same idea but in a cooler way.

Time complexity: O(loga) per test case.

#include <bits/stdc++.h>

using namespace std;

bool get(long long a, long long b, long long x) {
    if (a == x || b == x) return true;
    if (a < b) swap(a, b);
    if (b > a - b) b = a - b;
    if (x > max(a, b) || a == 0 || b == 0) return false;
    long long cnt = max(1ll, (a - max(x, b)) / (2 * b));
    return get(a - b * cnt, b, x);
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    
    int t;
    cin >> t;
    while (t--) {
        long long a, b, x;
        cin >> a >> b >> x;
        if (get(a, b, x)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
*/

#include<vector>
#include<iostream>
using ll=long long;
using namespace std;

bool dfs(long long a,long long b,long long x) {
	if(a>b) swap(a, b);
	if (x>b || !a) return false;
	if ((b-x)%a==0) return true;
	return dfs(a, b%a, x);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		ll a, b, x;
		cin>>a>>b>>x;
		cout<<((dfs(a, b, x))==1?"YES":"NO")<<"\n";
	}
}
