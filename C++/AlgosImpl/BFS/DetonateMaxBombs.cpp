// 2101. Detonate the Maximum Bombs
/*
You are given a list of bombs. The range of a bomb is defined as the area where its effect can be felt. 
This area is in the shape of a circle with the center as the location of the bomb.

The bombs are represented by a 0-indexed 2D integer array bombs where 
bombs[i] = [xi, yi, ri]. xi and yi denote the X-coordinate and Y-coordinate of the location of the ith bomb, 
whereas ri denotes the radius of its range.

You may choose to detonate a single bomb. When a bomb is detonated, it will 
detonate all bombs that lie in its range. 
These bombs will further detonate the bombs that lie in their ranges.

Given the list of bombs, return the maximum number of bombs that can be detonated if you are 
allowed to detonate only one bomb.

Input: bombs = [[2,1,3],[6,1,4]]
Output: 2
Explanation:
The above figure shows the positions and ranges of the 2 bombs.
If we detonate the left bomb, the right bomb will not be affected.
But if we detonate the right bomb, both bombs will be detonated.
So the maximum bombs that can be detonated is max(1, 2) = 2.

Input: bombs = [[1,2,3],[2,3,1],[3,4,2],[4,5,3],[5,6,4]]
Output: 5
Explanation:
The best bomb to detonate is bomb 0 because:
- Bomb 0 detonates bombs 1 and 2. The red circle denotes the range of bomb 0.
- Bomb 2 detonates bomb 3. The blue circle denotes the range of bomb 2.
- Bomb 3 detonates bomb 4. The green circle denotes the range of bomb 3.
Thus all 5 bombs are detonated.
*/

using ll= long long;

class Solution {
public:

	bool isValid(ll x1, ll y1, ll x2, ll y2, ll r){
		return (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2))<=r);
	}

    int maximumDetonation(vector<vector<int>>& bombs) {
    	const int sz=bombs.size();
		vector<vector<int>>gr(sz);
		for(int i=0; i<sz; ++i){
			ll r=(ll)bombs[i][2]*bombs[i][2];
			ll x1=bombs[i][0], y1=bombs[i][1];
			for(int j=0; j<sz; ++j){
				if(i!=j){
					ll x2=bombs[j][0], y2=bombs[j][1];
					if(isValid(x1, y1, x2, y2, r)){
						gr[i].push_back(j);
					}
				}
			}
		}
		int ans=1;
		for(int i=0; i<sz; ++i){
			vector<bool>seen(sz, false);
			int maxx=0;
			queue<int>q;
			q.push(i);
			while(!q.empty()){
				int len=q.size();
				while(len--){
					int curr=q.front();
					q.pop();
					seen[curr]=true;
					maxx++;
					for(auto &nei: gr[curr]){
						if(!seen[nei]){
							q.push(nei);
							seen[nei]=true;
						}
					}
				}
			}
			ans=max(maxx, ans);
		}
		return ans;
    }
};

