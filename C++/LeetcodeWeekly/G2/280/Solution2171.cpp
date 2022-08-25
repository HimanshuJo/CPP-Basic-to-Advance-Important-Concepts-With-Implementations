// 2171. Removing Minimum Number of Magic Beans
/*
You are given an array of positive integers beans, where each integer represents 
the number of magic beans found in a particular magic bag.

Remove any number of beans (possibly none) from each bag such that the number 
of beans in each remaining non-empty bag (still containing at least one bean) is equal. 
Once a bean has been removed from a bag, you are not allowed to return it to any of the bags.

Return the minimum number of magic beans that you have to remove.

Example 1:

Input: beans = [4,1,6,5]
Output: 4
Explanation: 
- We remove 1 bean from the bag with only 1 bean.
  This results in the remaining bags: [4,0,6,5]
- Then we remove 2 beans from the bag with 6 beans.
  This results in the remaining bags: [4,0,4,5]
- Then we remove 1 bean from the bag with 5 beans.
  This results in the remaining bags: [4,0,4,4]
We removed a total of 1 + 2 + 1 = 4 beans to make the remaining non-empty bags have an equal number of beans.
There are no other solutions that remove 4 beans or fewer.
Example 2:

Input: beans = [2,10,3,2]
Output: 7
Explanation:
- We remove 2 beans from one of the bags with 2 beans.
  This results in the remaining bags: [0,10,3,2]
- Then we remove 2 beans from the other bag with 2 beans.
  This results in the remaining bags: [0,10,3,0]
- Then we remove 3 beans from the bag with 3 beans. 
  This results in the remaining bags: [0,10,0,0]
We removed a total of 2 + 2 + 3 = 7 beans to make the remaining non-empty bags have an equal number of beans.
There are no other solutions that removes 7 beans or fewer.
 

Constraints:

1 <= beans.length <= 10^5
1 <= beans[i] <= 10^5
*/
/*
Solution:

sort the original array A.

If we select A[i] as the number of beans in a non-empty bag, the 
number of removals needed is sum(A) - (N - i) * A[i].

Meaning of equation

For all A[j] (j < i), they are completely removed, contributing A[0] + .. + A[i-1] removals.

For all A[j] (j >= i), they become all A[i]s, contributing A[i] + .. + A[N-1] - (N-i) * A[i] removals.

Summing these two up, we get sum(A) - (N - i) * A[i].

Another way to think this is to remove every thing and recover (N - i) * A[i] beans that shouldn't be removed.

Why we should pick the number from A?

Assume A = [1,5,10]. If we pick a number that is not in A, say 3, A becomes [0,3,3]. 
This is definitely not better than picking A[i] = 5 resulting in [0,5,5]. 

So, a solution picking a non-existent number is always dominated by another solution picking an existing number.

Example:

A = [1,4,5,6], sum(A) = 16

If we pick A[0] = 1, the result array is [1,1,1,1], # of removals is 16 - (4 - 0) * 1 = 12.
If we pick A[1] = 4, the result array is [0,4,4,4], # of removals is 16 - (4 - 1) * 4 = 4.
If we pick A[2] = 5, the result array is [0,0,5,5], # of removals is 16 - (4 - 2) * 5 = 6.
If we pick A[3] = 6, the result array is [0,0,0,6], # of removals is 16 - (4 - 3) * 6 = 10.
*/

/*
TLE:

using ll=long long;

class Solution {
public:
    
    bool isValid(vector<int>&vec){
        sort(vec.begin(), vec.end());
        int sz=vec.size();
        int ltval=vec[sz-1];
        if(ltval==0) return true;
        for(int i=0; i<sz; ++i){
            if(vec[i]!=0&&vec[i]!=ltval) return false;
        }
        return true;
    }
    
    ll dfs(vector<int>&beans, vector<int>&temp, int idx, int sz){
        if(idx==sz){
            if(isValid(temp)) return 0;
            return INT_MAX;
        }
        if(isValid(temp)) return 0;
        ll curmin=LONG_MAX;
        int curbean=beans[idx];
        for(int i=0; i<=curbean; ++i){
            vector<int>temp_=temp;
            temp_[idx]-=i;
            curmin=min(curmin, min(dfs(beans, temp, idx+1, sz), i+dfs(beans, temp_, idx+1, sz)));
        }
        return curmin;
    }
    
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        int sz=beans.size();
        int idx=0;
        vector<int>temp=beans;
        ll ans=dfs(beans, temp, idx, sz);
        return ans;
    }
};
*/

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int sz=beans.size();
        sort(beans.begin(), beans.end());
        long long sm=0;
        for(auto &vals: beans)
            sm+=vals;
        long long ans=LONG_MAX;
        int counter=0;
        for(auto &vals: beans){
            ans=min(ans, sm-(sz-counter)*(long long)vals);
            counter++;
        }
        return ans;
    }
};