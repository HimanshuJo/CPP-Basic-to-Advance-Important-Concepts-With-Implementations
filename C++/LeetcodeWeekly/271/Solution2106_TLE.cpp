// 2106. Maximum Fruits Harvested After at Most K Steps
/*
Fruits are available at some positions on an infinite x-axis. You are given a 2D integer array fruits where 
fruits[i] = [positioni, amounti] depicts amounti fruits at the position positioni. 
fruits is already sorted by positioni in ascending order, and each positioni is unique.

You are also given an integer startPos and an integer k. Initially, you are at the position startPos. 
From any position, you can either walk to the left or right. It takes one step to move one unit on the x-axis, 
and you can walk at most k steps in total. For every position you reach, you harvest all the fruits at that position, 
and the fruits will disappear from that position.

Return the maximum total number of fruits you can harvest.

Input: fruits = [[2,8],[6,3],[8,6]], startPos = 5, k = 4
Output: 9
Explanation: 
The optimal way is to:
- Move right to position 6 and harvest 3 fruits
- Move right to position 8 and harvest 6 fruits
You moved 3 steps and harvested 3 + 6 = 9 fruits in total.
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

	void dfs(map<int, int>&mp, int currPos, int remainingK, int &maxProf, int currTotal, vector<bool>&seen){
		maxProf=max(maxProf, currTotal);
		for(auto &entries: mp){
			int dist=abs(currPos-entries.first);
			int fruitCount=entries.second;
			if(remainingK>=dist&&!seen[entries.first]){
				currTotal+=fruitCount;
				seen[entries.first]=true;
				dfs(mp, entries.first, remainingK-dist, maxProf, currTotal, seen);
				seen[entries.first]=false;
				currTotal-=fruitCount;
			}
		}
	}

    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
		map<int, int>mp;
		for(auto &vals: fruits){
			mp[vals[0]]=vals[1];
		}
        if(fruits.size()==1){
            if(fruits[0][0]==startPos)
                return fruits[0][1];
            else{
                if(startPos+k==fruits[0][0]||startPos-k==fruits[0][0]) return fruits[0][1];
                return 0;
            }
        }
		auto it=mp.end();
		it--;
		int maxInd=(*it).first;
        int maxProf=0;
        vector<bool>seen(maxInd, false);
		dfs(mp, startPos, k, maxProf, 0, seen);
		return maxProf;
    }
};
