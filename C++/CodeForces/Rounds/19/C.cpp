// C. Andrew and Stones
/*
Andrew has n piles with stones. The i-th pile contains ai stones. 
He wants to make his table clean so he decided to put every stone either to the 1-st or the n-th pile.

Andrew can perform the following operation any number of times: 
choose 3 indices 1≤i<j<k≤n, such that the j-th pile contains at least 2 stones, then he takes 2 stones from the 
pile j and puts one stone into pile i and one stone into pile k.

Tell Andrew what is the minimum number of operations needed to move all the stones to piles 1 and n, or determine if it's impossible.

Input
The input contains several test cases. The first line contains one integer t (1≤t≤10000) — the number of test cases.

The first line for each test case contains one integer n (3≤n≤10^5) — the length of the array.

The second line contains a sequence of integers a1,a2,…,an (1≤ai≤10^9) — the array elements.

It is guaranteed that the sum of the values n over all test cases does not exceed 10^5.

Output
For each test case print the minimum number of operations needed to move stones to piles 1 and n, or print −1 if it's impossible.

Example
input
4
5
1 2 2 3 6
3
1 3 1
3
1 2 1
4
3 1 1 2

output
4
-1
1
-1 

Note
In the first test case, it is optimal to do the following:

Select (i,j,k)=(1,2,5). The array becomes equal to [2,0,2,3,7].
Select (i,j,k)=(1,3,4). The array becomes equal to [3,0,0,4,7].
Twice select (i,j,k)=(1,4,5). The array becomes equal to [5,0,0,0,9]. 
This array satisfy the statement, because every stone is moved to piles 1 and 5.
There are 4 operations in total.

In the second test case, it's impossible to put all stones into piles with numbers 1 and 3:

At the beginning there's only one possible operation with (i,j,k)=(1,2,3). The array becomes equal to [2,1,2].
Now there is no possible operation and the array doesn't satisfy the statement, so the answer is −1.

In the third test case, it's optimal to do the following:

Select (i,j,k)=(1,2,3). The array becomes equal to [2,0,2]. 
This array satisfies the statement, because every stone is moved to piles 1 and 3.
The is 1 operation in total.

In the fourth test case, it's impossible to do any operation, and the array doesn't satisfy the statement, so the answer is −1.
*/

/*
Solution:

Consider 2 cases when the answer is −1 for sure:

1. For all 1<i<n: ai=1. In this case, it's not possible to make any operation and not all stones are in piles 1 or n.

2. n=3 and a2 is odd. Then after any operation this number will remain odd, so it can never become equal to 0.

To show it consider the following algorithm:

	If all stones are in piles 1 and n then the algorithm is done.

	If there is at least one non-zero even element (piles 1 and n don't count), then subtract 2 from it, 
	add 1 to the odd number to the left or to the pile 1 if there's no such number. 

		Similarly add 1 to the odd number to the right or to the pile n if there's no such number. 

		Then continue the algorithm.

		Note that the number of odd elements after it (piles 1 and n don't count) decreases at least by 1 (if there was any odd number). 
		Also either a new even number has appeared, or the algorithm will be done.

	If all remaining non-zero numbers are odd, then there is at least one odd number greater than 1.
		
		So let's subtract 2 from this element and add ones similar to the 2-nd case. In this case the number of odd elements 
        decreases at least by 1.

From the notes written in the second and third cases, it follows that the algorithm always puts all stones to the piles 1 and n.
Also note that if in the initial array the element in position i (1<i<n) was even, then the algorithm did not add any 1 to it, 
so the number of operations with the center in i equals to ai2. And if ai was odd, the algorithm will add 1 to this element exactly once, 
so the number of operations with the center in i equals to ai+12.

This algorithm is optimal because for each odd number it's necessary to add at least 1 to it and the algorithm adds exactly 1. 
And from even elements the algorithm can only subtract. It means that the answer to the problem equals to Summation(i=2ton-1)ceil(ai/2).

Time complexity is O(n).
*/

#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
 
    if (*max_element(a.begin() + 1, a.end() - 1) == 1 || (n == 3 && a[1] % 2 == 1)) {
        cout << "-1\n";
        return;
    }
 
    long long answer = 0;
    for (int i = 1; i < n - 1; i++)
        answer += (a[i] + 1) / 2;
 
    cout << answer << '\n';
}
 
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tests;
    cin >> tests;
    while (tests--)
        solve();
}
