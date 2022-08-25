// C. Kill the Monster
/*
Monocarp is playing a computer game. In this game, his character fights different monsters.

A fight between a character and a monster goes as follows. 
Suppose the character initially has health hC and attack dC; the monster initially has health hM and attack dM. The fight consists of several steps:

the character attacks the monster, decreasing the monster's health by dC;
the monster attacks the character, decreasing the character's health by dM;
the character attacks the monster, decreasing the monster's health by dC;
the monster attacks the character, decreasing the character's health by dM;
and so on, until the end of the fight.
The fight ends when someone's health becomes non-positive (i.e. 0 or less). If the monster's health becomes non-positive, the character wins, otherwise the monster wins.

Monocarp's character currently has health equal to hC and attack equal to dC. 

He wants to slay a monster with health equal to hM and attack equal to dM. 

Before the fight, Monocarp can spend up to k coins to upgrade his character's weapon and/or armor; 
each upgrade costs exactly one coin, each weapon upgrade increases the character's attack by w, and each armor upgrade increases the character's health by a.

Can Monocarp's character slay the monster if Monocarp spends coins on upgrades optimally?

Input
The first line contains one integer t (1<=t<=5<=10^4) — the number of test cases. Each test case consists of three lines:

The first line contains two integers hC and dC (1<=hC<=10^15; 1<=dC<=10^9) — the character's health and attack;

The second line contains two integers hM and dM (1<=hM<=10^15; 1<=dM<=10^9) — the monster's health and attack;

The third line contains three integers k, w and a (0<=k<=2*10^5; 0<=w<=10^4; 0<=a<=10^10) — the maximum number of coins that Monocarp can spend, 
the amount added to the character's attack with each weapon upgrade, and the amount added to the character's health with each armor upgrade, respectively.

The sum of k over all test cases does not exceed 2*10^5.

Output
For each test case, print YES if it is possible to slay the monster by optimally choosing the upgrades. Otherwise, print NO.

Example
input
4
25 4
9 20
1 1 10
25 4
12 20
1 1 10
100 1
45 2
0 4 10
9 2
69 2
4 2 7

output
YES
NO
YES
YES

Note
In the first example, Monocarp can spend one coin to upgrade weapon (damage will be equal to 5), then health during battle will 
change as follows: (hC,hM)=(25,9)→(25,4)→(5,4)→(5,−1). The battle ended with Monocarp's victory.

In the second example, Monocarp has no way to defeat the monster.

In the third example, Monocarp has no coins, so he can't buy upgrades. However, the initial characteristics are enough for Monocarp to win.

In the fourth example, Monocarp has 4 coins. To defeat the monster, he has to spend 2 coins to upgrade weapon and 2 coins to upgrade armor.
*/

/*
Solution:

First of all, let's understand how to solve the problem without upgrades. 
To do this, it is enough to compare two numbers: 

⌈hM/dC⌉ and ⌈hC/dM⌉ — the number of attacks that the character needs to kill the monster and 
the number of attacks that the monster needs to kill the character, respectively. 
So, if the first number is not greater than the second number, then the character wins. (Character needs less atacks to kill the monster)

Note that the number of coins is not very large, which means we can iterate over the number of coins that we will 
spend on weapon upgrades, and the remaining coins will be spent on armor upgrades. 

After that, we can use the formula described above to check whether the character will win.

The complexity of the solution is O(k).
*/

#include<iostream>
#include<cmath>
#include<cstdlib>
using ll=long long;
using namespace std;

ll div_ceil(ll x, ll y) {
    return x / y + (x % y > 0);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		ll healthC, attackC, healthM, attackM;
		cin>>healthC>>attackC>>healthM>>attackM;
		ll k, attackUpg, healthUpg;
		cin>>k>>attackUpg>>healthUpg;
		bool flag=false;
		for(int k1=0; k1<=k; ++k1){
			int k2=k-k1;
			ll updHealthC=healthC+k1*healthUpg;
			ll updAttackC=attackC+k2*attackUpg;
			ll charNeed=div_ceil(healthM, updAttackC);
			ll monsterNeed=div_ceil(updHealthC, attackM);
			if(charNeed<=monsterNeed){
				cout<<"YES\n";
				flag=true;
				break;
			}
		}
		if(!flag) cout<<"NO\n";
	}
}
