/*
Given an integer a, b, m. Find (a * b) mod m, where a, b may be large and their direct multiplication may cause overflow. 
However they are smaller than half of the maximum allowed long long int value.

Input: a = 426, b = 964, m = 235
Output: 119
Explanation: (426 * 964) % 235  
            = 410664 % 235
            = 119

Input: a = 10123465234878998, 
       b = 65746311545646431
       m = 10005412336548794 
Output: 4652135769797794
*/

#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll modMul(ll a, ll b, ll mod)
{
	ll res = 0;
	a %= mod;
	while (b)
	{
		if (b & 1)
			res = (res + a) % mod;
		a = (2 * a) % mod;
		b >>= 1;
	}
	return res;
}

int main()
{
	long long a = 426;
	long long b = 964;
	long long m = 235;
	cout << modMul(a, b, m);
	return 0;
}