// 2101. Detonate the Maximum Bombs
/*
You are given a list of bombs. The range of a bomb is defined as the area where its effect can be felt. 
This area is in the shape of a circle with the center as the location of the bomb.

The bombs are represented by a 0-indexed 2D integer array bombs where bombs[i] = [xi, yi, ri]. xi and yi denote the X-coordinate and Y-coordinate of the location of the ith bomb, 
whereas ri denotes the radius of its range.

You may choose to detonate a single bomb. When a bomb is detonated, it will detonate all bombs that lie in its range. 
These bombs will further detonate the bombs that lie in their ranges.

Given the list of bombs, return the maximum number of bombs that can be detonated if you are allowed to detonate only one bomb.

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

using d=double;

class Solution {
public:

	vector<vector<int>>gr;
	vector<bool>seen;

    bool isValid(int x1, int y1, int x2, int y2, int r1, int r2){
		return ((d)(x2-x1)*((d)(x2-x1))+((d)(y2-y1))*((d)(y2-y1))<=(d)((d)r1*(d)r1));
	}

	int dfs(int idx){
		if(seen[idx]==true){
			return 0;
		}
		seen[idx]=true;
		int sum=1;
		for(auto &node: gr[idx]){
			sum+=dfs(node);
		}
		return sum;
	}

	int maximumDetonation(vector<vector<int>>& bombs) {
    	int sz=bombs.size();
		gr=vector<vector<int>>(sz);
		seen=vector<bool>(sz, false);
		for(int i=0; i<sz; ++i){
			int x1=bombs[i][0];
			int y1=bombs[i][1];
			int r1=bombs[i][2];
			for(int j=0; j<sz; ++j){
				if(i!=j){
					int x2=bombs[j][0];
					int y2=bombs[j][1];
					int r2=bombs[j][2];
					if(isValid(x1, y1, x2, y2, r1, r2)){
						gr[i].push_back(j);
					}
				}
			}
		}
		int maxx=0;
		for(int i=0; i<sz; ++i){
			for(int j=0; j<sz; ++j){
				seen[j]=false;
			}
            int sum=dfs(i);
            if(sum>maxx) maxx=sum;
		}
		return maxx;
  	}
};
