#include<iostream>
#include<vector>
#include<set>
// F. Armor and Weapons
/*
Monocarp plays a computer game. There are n different sets of armor and m different weapons in this game. 
If a character equips the i-th set of armor and wields the j-th weapon, their power is usually equal to i+j; 
but some combinations of armor and weapons synergize well. Formally, there is a list of q ordered pairs, and 
if the pair (i,j) belongs to this list, the power of the character equipped with the i-th set of armor and 
wielding the j-th weapon is not i+j, but i+j+1.

Initially, Monocarp's character has got only the 1-st armor set and the 1-st weapon. Monocarp can obtain a 
new weapon or a new set of armor in one hour. If he wants to obtain the k-th armor set or the k-th weapon, 
he must possess a combination of an armor set and a weapon that gets his power to k or greater. Of course, 
after Monocarp obtains a weapon or an armor set, he can use it to obtain new armor sets or weapons, 
but he can go with any of the older armor sets and/or weapons as well.

Monocarp wants to obtain the n-th armor set and the m-th weapon. What is the minimum number of hours he has to spend on it?

Input
The first line contains two integers n and m (2≤n,m≤2⋅105) — the number of armor sets and the number of weapons, respectively.

The second line contains one integer q (0≤q≤min(2⋅105,nm)) — the number of combinations that synergize well.

Then q lines follow, the i-th line contains two integers ai and bi (1≤ai≤n; 1≤bi≤m) meaning that the ai-th 
armor set synergizes well with the bi-th weapon. All pairs (ai,bi) are distinct.

Output
Print one integer — the minimum number of hours Monocarp has to spend to obtain both the n-th armor set and the m-th weapon.

Examples
input
3 4
0

output
3

input
3 4
2
1 1
1 3

output
2

Note
In the first example, Monocarp can obtain the strongest armor set and the strongest weapon as follows:

Obtain the 2-nd weapon using the 1-st armor set and the 1-st weapon;
Obtain the 3-rd armor set using the 1-st armor set and the 2-nd weapon;
Obtain the 4-th weapon using the 3-rd armor set and the 2-nd weapon.
In the second example, Monocarp can obtain the strongest armor set and the strongest weapon as follows:

Obtain the 3-rd armor set using the 1-st armor set and the 1-st weapon (they synergize well, so Monocarp's power is not 2 but 3);
Obtain the 4-th weapon using the 3-rd armor set and the 1-st weapon.
*/

#include<algorithm>
using namespace std;
using ll=long long;

int n, m;
int ans=INT_MAX;
set<int>st[200001];

void dfs(int currArm, int currWep, bool arm, bool wep, int currT){
	int currS=currArm+currWep+(st[currArm].find(currWep)!=st[currArm].end());
	if(currS>=n&&!wep){
		dfs(n, currWep, 0, 1, ++currT);
		return;
	}
	if(currS>=m){
		ans=min(ans, currT);
		return;
	}
	if(currArm+currS>=n&&!wep){
		dfs(currArm, currS, 0, 0, ++currT);
	}
	if(currArm==n){
		dfs(n, currS, 0, 1, currT+1);
		return;
	}
	if(arm) dfs(currS, currWep, !arm, wep, ++currT);
	else dfs(currArm, currS, !arm, wep, ++currT);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	int q;
	cin>>q;
	for(int i=0; i<q; ++i){
		int a, b;
		cin>>a>>b;
		if(n>m) swap(a, b);
		st[a].insert(b);
	}
	if(n>m) swap(n, m);
	dfs(1, 1, 0, 0, 0);
	dfs(1, 1, 1, 0, 0);
	cout<<ans+1<<"\n";
}
