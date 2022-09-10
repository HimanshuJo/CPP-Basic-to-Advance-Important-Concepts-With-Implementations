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

Input: fruits = [[0,9],[4,1],[5,7],[6,2],[7,4],[10,9]], startPos = 5, k = 4
Output: 14
Explanation: 
You can move at most k = 4 steps, so you cannot reach position 0 nor 10.
The optimal way is to:
- Harvest the 7 fruits at the starting position 5
- Move left to position 4 and harvest 1 fruit
- Move right to position 6 and harvest 2 fruits
- Move right to position 7 and harvest 4 fruits
You moved 1 + 3 = 4 steps and harvested 7 + 1 + 2 + 4 = 14 fruits in total.

Input: fruits = [[0,3],[6,4],[8,5]], startPos = 3, k = 2
Output: 0
Explanation:
You can move at most k = 2 steps and cannot reach any position with fruits.

Constraints:

1 <= fruits.length <= 10^5
fruits[i].length == 2
0 <= startPos, positioni <= 2 * 10^5
positioni-1 < positioni for any i > 0 (0-indexed)
1 <= amounti <= 10^4
0 <= k <= 2 * 10^5
*/

/*
TLE: 34 / 202

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
*/

/*
From the start position, we can have 2 possible scenarios :

Move to the left for few positions and then travel back to the right passing through 
the start position (cost = 2*l + r <= k)

Move to the right for few positions and then travel back to the left passing through 
the start position (cost = 2*r + l <= k)

where, l = number of left positions travelled & r = number of right positions travelled

We count the number of fruits by prefix sum, (start position : sp)
left[i] indicates total fruits in the range [i, sp] inclusive
right[i] indicates total fruits in the range [sp, i] inclusive

Keeping the cost in mind, we update the answer(ans) with the above counts,
also check the bounds where, we cannot move beyond 0 to the left & n-1 to the right, where: n - 2*10^5 + 1

    ans = max(ans, left[left_pos] + right[right_pos] - fruits_at_sp)

subtract fruits_at_sp because it is included twice in the first two terms
*/

class Solution {
public:
    
    int sz=2e5+1;
    
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        vector<int>fruitsmp(sz, 0);
        for(auto &entries: fruits){
            fruitsmp[entries[0]]=entries[1];
        }
        vector<int>left(sz, 0), right(sz, 0);
        left[startPos]=fruitsmp[startPos], right[startPos]=fruitsmp[startPos];
        for(int i=startPos-1; i>=0; --i){
            left[i]=left[i+1]+fruitsmp[i];
        }
        for(int i=startPos+1; i<sz; ++i){
            right[i]=right[i-1]+fruitsmp[i];
        }
        int ans=INT_MIN;
        for(int l=0; l<=min(k, startPos); ++l){
            int r=min(k-2*l, sz-1-startPos);
            ans=r>=0&&startPos+r<sz?max(ans, left[startPos-l]+right[startPos+r]-fruitsmp[startPos]):ans;
        }
        for(int r=0; r<=min(k, sz-1-startPos); ++r){
            int l=min(k-2*r, startPos);
            ans=l>=0&&startPos-l>=0?max(ans, left[startPos-l]+right[startPos+r]-fruitsmp[startPos]):ans;
        }
        return ans;
    }
};