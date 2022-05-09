// 2225. Find Players With Zero or One Losses
/*
You are given an integer array matches where matches[i] = [winneri, loseri] indicates 
that the player winneri defeated player loseri in a match.

Return a list answer of size 2 where:

answer[0] is a list of all players that have not lost any matches.
answer[1] is a list of all players that have lost exactly one match.
The values in the two lists should be returned in increasing order.

Note:

You should only consider the players that have played at least one match.
The testcases will be generated such that no two matches will have the same outcome.

Example 1:

Input: matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
Output: [[1,2,10],[4,5,7,8]]
Explanation:
Players 1, 2, and 10 have not lost any matches.
Players 4, 5, 7, and 8 each have lost one match.
Players 3, 6, and 9 each have lost two matches.
Thus, answer[0] = [1,2,10] and answer[1] = [4,5,7,8].
Example 2:

Input: matches = [[2,3],[1,3],[5,4],[6,4]]
Output: [[1,2,5,6],[]]
Explanation:
Players 1, 2, 5, and 6 have not lost any matches.
Players 3 and 4 each have lost two matches.
Thus, answer[0] = [1,2,5,6] and answer[1] = [].
 

Constraints:

1 <= matches.length <= 10^5
matches[i].length == 2
1 <= winneri, loseri <= 10^5
winneri != loseri
All matches[i] are unique.
*/

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int sz=matches.size();
        vector<int>res(1e5+1, 0);
        vector<int>pres(1e5+1, 0);
        int maxEle=INT_MIN;
        for(auto &vals: matches){
            res[vals[1]]++;
            if(vals[0]>maxEle) maxEle=vals[0];
            if(vals[1]>maxEle) maxEle=vals[1];
            pres[vals[0]]=1, pres[vals[1]]=1;
        }
        vector<int>noLoss, oneLoss;
        for(int i=1; i<=maxEle; ++i){
            if(res[i]==0&&pres[i]==1){
                noLoss.push_back(i);
            }
            if(res[i]==1&&pres[i]==1){
                oneLoss.push_back(i);
            }
        }
        vector<vector<int>>ans;
        ans.push_back(noLoss);
        ans.push_back(oneLoss);
        return ans;
    }
};