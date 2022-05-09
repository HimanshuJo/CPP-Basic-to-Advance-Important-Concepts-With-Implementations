// C. Monsters And Spells
/*
Monocarp is playing a computer game once again. He is a wizard apprentice, who only knows a single spell. 
Luckily, this spell can damage the monsters.

The level he's currently on contains n monsters. The i-th of them appears ki seconds after the start of the level and has hi 
health points. As an additional constraint, hi<=ki for all 1<=i<=n. All ki are different.

Monocarp can cast the spell at moments which are positive integer amounts of second after the start of the level: 1,2,3,… 
The damage of the spell is calculated as follows. If he didn't cast the spell at the previous second, the damage is 1. 
Otherwise, let the damage at the previous second be x. Then he can choose the damage to be either x+1 or 1. 

A spell uses mana: casting a spell with damage x uses x mana. Mana doesn't regenerate.

To kill the i-th monster, Monocarp has to cast a spell with damage at least hi at the exact moment the monster appears, which is ki.

Note that Monocarp can cast the spell even when there is no monster at the current second.

The mana amount required to cast the spells is the sum of mana usages for all cast spells. 
Calculate the least amount of mana required for Monocarp to kill all monsters.

It can be shown that it's always possible to kill all monsters under the constraints of the problem.

Example
input
3
1
6
4
2
4 5
2 2
3
5 7 9
2 1 2

output
10
6
7
Note
In the first testcase of the example, 
Monocarp can cast spells 3,4,5 and 6 seconds from the start with damages 1,2,3 and 4, respectively. 
The damage dealt at 6 seconds is 4, which is indeed greater than or equal to the health of the monster that appears.

In the second testcase of the example, Monocarp can cast spells 3,4 and 5 seconds from the start with damages 1,2 and 3, respectively.

In the third testcase of the example, Monocarp can cast spells 4,5,7,8 and 9 seconds from the start with damages 1,2,1,1 and 2, respectively.
*/

/*
Solution:

Consider the problem with n=1. There is a single monster with some health h that appears at some second k. 
In order to kill it, we have to wind up our spell until it has damage h.

So we have to use it from second k−h+1 to second k. Look at it as a segment [k−h+1;k] on a timeline.

Actually, to avoid handling zero length segments, let's instead say that a segment covers the time 
from k−h non-inclusive to k inclusive, producing a half-interval (k−h;k]. 

This way, the total mana cost will be len(len+1)/2, where len is the length of the half-interval.

Now n=2. There are two time segments.

If they don't intersect (segments (1;2] and (2;3] don't intersect, since they are half-intervals), 
then it's always better to wind up the spell for the monsters separately instead of saving the damage.

However, if they intersect, then we don't have the choice other than to save the damage from the earlier 
one to the later one. Otherwise, there won't be enough time to wind up the spell.

What that means in a mathematic sense? The answer is the union of two half-intervals. 
If they don't intersect, they are left as is. Otherwise, they become one half-interval that covers them both.

Now add the third monster into the construction. The same argument applies. 
While there exists a pair of intersecting half-intervals, keep uniting them.

The union of all half-intervals can be found in O(nlogn), but the constraints allowed slower approaches as well.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
using ll=long long;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<ll>in1(n);
		vector<ll>in2(n);
		vector<pair<ll, ll>>combs;
		for(int i=0; i<n; ++i){
			cin>>in1[i];
		}
		for(int i=0; i<n; ++i){
			cin>>in2[i];
		}
		for(int i=0; i<n; ++i){
			combs.push_back({in1[i]-in2[i], in1[i]});
		}
		sort(combs.begin(), combs.end());
		ll ans=0;
		ll l=-1, r=-1;
		for(auto &vals: combs){
			if(vals.first>=r){
				ans+=(r-l)*(r-l+1)/2;
				l=vals.first, r=vals.second;
			} else{
				r=max(r, vals.second);
			}
		}
		ans+=(r-l)*(r-l+1)/2;
		cout<<ans<<"\n";
	}
}

