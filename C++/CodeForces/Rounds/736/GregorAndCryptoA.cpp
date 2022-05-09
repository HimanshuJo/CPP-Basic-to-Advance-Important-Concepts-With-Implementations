// Gregor and Cryptography
/*
Gregor is learning about RSA cryptography, and although he doesn't understand 
how RSA works, he is now fascinated with prime numbers and factoring them.

Gregor's favorite prime number is P. Gregor wants to find two bases of P. 
Formally, Gregor is looking for two integers a and b which satisfy both of 
the following properties.

Pmoda=Pmodb, where xmody denotes the remainder when x is divided by y, and
2≤a<b≤P.

Output
Your output should consist of t lines. Each line should consist of two integers a and b (2≤a<b≤P).
 If there are multiple possible solutions, print any.

Example
input
2
17
5
output
3 5
2 4
*/
/*
Since P≥5 and is also a prime number, we know that P−1 is an even composite number. 
A even composite number is guaranteed to have at least 2 unique divisors 
greater than 1. Let two of these divisors be a and b. It is guaranteed that 
Pmoda=Pmodb=1, and thus this selection is valid.

For example, we can simply pick a=2 and b=P−1, and we will get a correct solution.

The time complexity is O(Q).

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int p;
		cin >> p;
		cout << "2 " << p-1 << "\n";
	}
	return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int P;
        cin >> P;
        int qo = P / 2;
        cout << 2 << " " << qo * 2 << "\n";
    }
}