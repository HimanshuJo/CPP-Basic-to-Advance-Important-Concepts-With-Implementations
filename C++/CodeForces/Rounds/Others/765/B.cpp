// B. Elementary Particles
/*
Martians are actively engaged in interplanetary trade. Olymp City, the Martian city known for its spaceport, has become a place 
where goods from all the corners of our Galaxy come. To deliver even more freight from faraway planets, Martians need fast spaceships.

A group of scientists conducts experiments to build a fast engine for the new spaceship. In the current experiment, there are n elementary particles, the i-th of them has type ai.

Denote a subsegment of the particle sequence (a1,a2,…,an) as a sequence (al,al+1,…,ar) for some left bound l and right bound r (1<=l<=r<=n).
For instance, the sequence (1 4 2 8 5 7) for l=2 and r=4 has the sequence (4 2 8) as a subsegment. Two subsegments are considered different if at least one bound of those subsegments differs.

Note that the subsegments can be equal as sequences but still considered different. For example, consider the sequence (1 1 1 1 1) and two of its subsegments: 
one with l=1 and r=3 and another with l=2 and r=4. Both subsegments are equal to (1 1 1), but still considered different, as their left and right bounds differ.

The scientists want to conduct a reaction to get two different subsegments of the same length. Denote this length k. The resulting pair of subsegments must be harmonious, 
i. e. for some i (1<=i<=k) it must be true that the types of particles on the i-th position are the same for these two subsegments. 
For example, the pair (1 7 3) and (4 7 8) is harmonious, as both subsegments have 7 on the second position. The pair (1 2 3) and (3 1 2) is not harmonious.

The longer are harmonious subsegments, the more chances for the scientists to design a fast engine. So, they asked you to calculate 
the maximal possible length of harmonious pair made of different subsegments.

Example
input
4
7
3 1 5 2 1 3 4
6
1 1 1 1 1 1
6
1 4 2 8 5 7
2
15 15

output
4
5
-1
1
*/
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<pair<int, int>>in;	
		for(int i=0; i<n; ++i){
			int tmp;
			cin>>tmp;
			in.push_back({tmp, i});
		}
		sort(in.begin(), in.end());
		int ans=-1;
		for(int i=0; i<n-1; ++i){
			if(in[i].first==in[i+1].first){
				ans=max(ans, in[i].second+n-in[i+1].second);
			}
		}
		cout<<ans<<"\n";
	}
}


