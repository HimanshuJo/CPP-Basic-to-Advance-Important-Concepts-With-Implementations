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


int MX=2e5+2;

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        vector<int>prefSum(MX);
        int l, r, ans=0;
        startPos++;
        for(auto &vals: fruits){
            prefSum[vals[0]+1]=vals[1];
        }
        for(int i=1; i<MX; ++i){
            prefSum[i]+=prefSum[i-1];
        }
        for(r=startPos; r<MX&&r<=startPos+k; ++r){
            l=min(startPos, startPos-(k-2*(r-startPos)));
            l=max(1, l);
            ans=max(ans, prefSum[r]-prefSum[l-1]);
        }
        for(l=startPos; l>0&&l>=startPos-k; --l){
            r=max(startPos, startPos+(k-2*(startPos-l)));
            r=min(MX-1, r);
            ans=max(ans, prefSum[r]-prefSum[l-1]);
        }
        return ans;
    }
};