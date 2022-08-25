// https://codeforces.com/contest/1720
// https://codeforces.com/blog/entry/106136
// A. Burenka Plays with Fractions
/*
Burenka came to kindergarden. This kindergarten is quite strange, so each kid there receives 
two fractions (ab and cd) with integer numerators and denominators. Then children are 
commanded to play with their fractions.

Burenka is a clever kid, so she noticed that when she claps once, she can multiply numerator or 
denominator of one of her two fractions by any integer of her choice (but she can't multiply denominators by 0). 
Now she wants know the minimal number of claps to make her fractions equal (by value). Please help her 
and find the required number of claps!

Input
The first line contains one integer t (1≤t≤10^4) — the number of test cases. 
Then follow the descriptions of each test case.

The only line of each test case contains four integers a, b, c and d (0≤a,c≤10^9, 1≤b,d≤10^9) — 
numerators and denominators of the fractions given to Burenka initially.

Output
For each test case print a single integer — the minimal number of claps Burenka needs to make her fractions equal.

Example
input
8
2 1 1 1
6 3 2 1
1 2 2 3
0 1 0 100
0 1 228 179
100 3 25 6
999999999 300000000 666666666 100000000
33 15 0 84

output
1
0
2
0
1
1
1
1
Note
In the first case, Burenka can multiply c by 2, then the fractions will be equal.

In the second case, fractions are already equal.

In the third case, Burenka can multiply a by 4, then b by 3. Then the fractions will be equal (1⋅42⋅3=23).
*/

#include<iostream>
#include<vector>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		long long a, b, c, d;
		cin>>a>>b>>c>>d;
		if(((double)a/b==(double)c/d)||(a==0&&c==0)){
			cout<<0<<endl;
		} else if(a==0||c==0){
			cout<<1<<endl;
		} else{
			long long fracNum1=a*d;
			long long fracNum2=c*b;
			if((fracNum1%fracNum2==0)||(fracNum2%fracNum1==0)){
				cout<<1<<endl;
			} else{
				cout<<2<<endl;
			}
		}
	}
}