// 2279. Maximum Bags With Full Capacity of Rocks
/*
You have n bags numbered from 0 to n - 1. You are given two 0-indexed integer arrays 
capacity and rocks. 

The ith bag can hold a maximum of capacity[i] rocks and currently contains 
rocks[i] rocks. 

You are also given an integer additionalRocks, the number of additional rocks you can place in any of the bags.

Return the maximum number of bags that could have full capacity after placing the additional rocks in some bags.

Example 1:

Input: capacity = [2,3,4,5], rocks = [1,2,4,4], additionalRocks = 2
Output: 3
Explanation:
Place 1 rock in bag 0 and 1 rock in bag 1.
The number of rocks in each bag are now [2,3,4,4].
Bags 0, 1, and 2 have full capacity.
There are 3 bags at full capacity, so we return 3.
It can be shown that it is not possible to have more than 3 bags at full capacity.
Note that there may be other ways of placing the rocks that result in an answer of 3.
Example 2:

Input: capacity = [10,2,2], rocks = [2,2,0], additionalRocks = 100
Output: 3
Explanation:
Place 8 rocks in bag 0 and 2 rocks in bag 2.
The number of rocks in each bag are now [10,2,2].
Bags 0, 1, and 2 have full capacity.
There are 3 bags at full capacity, so we return 3.
It can be shown that it is not possible to have more than 3 bags at full capacity.
Note that we did not use all of the additional rocks.
 

Constraints:

n == capacity.length == rocks.length
1 <= n <= 5 * 10^4
1 <= capacity[i] <= 10^9
0 <= rocks[i] <= capacity[i]
1 <= additionalRocks <= 10^9
*/

class Solution1 {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int sz=capacity.size();
        vector<int>diff(sz, 0);
        for(int i=0; i<sz; ++i){
            diff[i]=capacity[i]-rocks[i];
        }
        sort(diff.begin(), diff.end());
        int ans=0;
        for(int i=0; i<sz; ++i){
            if(diff[i]==0){
                ans++;
                continue;
            }
            if(diff[i]!=0){
                if(diff[i]<=additionalRocks){
                    additionalRocks-=diff[i];
                    ans++;
                }
            }
        }
        return ans;
    }
};

class Solution2 {
public:
    
    bool isValid(vector<int>&diff, int mid, int additionalRocks){
        for(int i=mid; i>=0; --i){
            if(diff[i]!=0){
                if(diff[i]<=additionalRocks){
                    additionalRocks-=diff[i];
                } else return false;
            }
        }
        return true;
    }
    
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int sz=capacity.size();
        if(sz==1){
            if(rocks[0]==capacity[0]) return 1;
            else{
                int diff=capacity[0]-rocks[0];
                if(diff<=additionalRocks) return 1;
                return 0;
            }
        }
        vector<int>diff(sz, 0);
        for(int i=0; i<sz; ++i){
            diff[i]=capacity[i]-rocks[i];
        }
        sort(diff.begin(), diff.end());
        int left=0, right=sz-1;
        int ans=0;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(isValid(diff, mid, additionalRocks)){
                ans=mid;
                left=mid+1;
            } else{
                right=mid-1;
            }
        }
        return ans+1;
    }
};