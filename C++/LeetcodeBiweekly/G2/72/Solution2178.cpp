// 2178. Maximum Split of Positive Even Integers
/*
You are given an integer finalSum. Split it into a sum of a maximum number of unique positive even integers.

For example, given finalSum = 12, the following splits are valid 
(unique positive even integers summing up to finalSum): (12), (2 + 10), (2 + 4 + 6), and (4 + 8). 

Among them, (2 + 4 + 6) contains the maximum number of integers. Note that finalSum cannot be split into 
(2 + 2 + 4 + 4) as all the numbers should be unique.
Return a list of integers that represent a valid split containing a maximum number of integers. 
If no valid split exists for finalSum, return an empty list. You may return the integers in any order.

Example 1:

Input: finalSum = 12
Output: [2,4,6]
Explanation: The following are valid splits: (12), (2 + 10), (2 + 4 + 6), and (4 + 8).
(2 + 4 + 6) has the maximum number of integers, which is 3. Thus, we return [2,4,6].
Note that [2,6,4], [6,2,4], etc. are also accepted.
Example 2:

Input: finalSum = 7
Output: []
Explanation: There are no valid splits for the given finalSum.
Thus, we return an empty array.
Example 3:

Input: finalSum = 28
Output: [6,8,2,12]
Explanation: The following are valid splits: (2 + 26), (6 + 8 + 2 + 12), and (4 + 24). 
(6 + 8 + 2 + 12) has the maximum number of integers, which is 4. Thus, we return [6,8,2,12].
Note that [10,2,4,12], [6,2,4,16], etc. are also accepted.
 

Constraints:

1 <= finalSum <= 10^10
*/

using ll=long long;

class Solution {
public:
    
    bool flag=false;
    vector<ll>ans;
    
    void dfs(const ll finalSum, ll currSum, ll bgn, vector<ll>&currarr){
        if(flag) return;
        if(currSum>finalSum) return;
        if(currSum==finalSum){
            flag=true;
            ans=currarr;
            return;
        }
        if(bgn>finalSum) return;
        if(currSum+bgn<=finalSum){
            currarr.push_back(bgn);
            currSum+=bgn;
            dfs(finalSum, currSum, bgn+2, currarr);    
            if(currarr.size()>=1){
                currSum-=bgn;
                currarr.pop_back();
                dfs(finalSum, currSum, bgn+2, currarr);
            }
        }
    }
    
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum%2!=0) return {};
        ll currSum=0;
        vector<ll>currarr;
        dfs(finalSum, currSum, 2, currarr);
        return ans;
    }
};