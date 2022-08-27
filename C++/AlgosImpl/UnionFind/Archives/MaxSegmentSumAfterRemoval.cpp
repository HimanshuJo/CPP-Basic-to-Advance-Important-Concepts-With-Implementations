// 2382. Maximum Segment Sum After Removals
/*
You are given two 0-indexed integer arrays nums and removeQueries, both of length n. 
For the ith query, the element in nums at the index removeQueries[i] is removed, splitting 
nums into different segments.

A segment is a contiguous sequence of positive integers in nums. 
A segment sum is the sum of every element in a segment.

Return an integer array answer, of length n, where answer[i] is the maximum 
segment sum after applying the ith removal.

Note: The same index will not be removed more than once.

Example 1:

Input: nums = [1,2,5,6,1], removeQueries = [0,3,2,4,1]
Output: [14,7,2,2,0]
Explanation: Using 0 to indicate a removed element, the answer is as follows:
Query 1: Remove the 0th element, nums becomes [0,2,5,6,1] and the maximum segment sum is 14 for segment [2,5,6,1].
Query 2: Remove the 3rd element, nums becomes [0,2,5,0,1] and the maximum segment sum is 7 for segment [2,5].
Query 3: Remove the 2nd element, nums becomes [0,2,0,0,1] and the maximum segment sum is 2 for segment [2]. 
Query 4: Remove the 4th element, nums becomes [0,2,0,0,0] and the maximum segment sum is 2 for segment [2]. 
Query 5: Remove the 1st element, nums becomes [0,0,0,0,0] and the maximum segment sum is 0, since there are no segments.
Finally, we return [14,7,2,2,0].
Example 2:

Input: nums = [3,2,11,1], removeQueries = [3,2,1,0]
Output: [16,5,3,0]
Explanation: Using 0 to indicate a removed element, the answer is as follows:
Query 1: Remove the 3rd element, nums becomes [3,2,11,0] and the maximum segment sum is 16 for segment [3,2,11].
Query 2: Remove the 2nd element, nums becomes [3,2,0,0] and the maximum segment sum is 5 for segment [3,2].
Query 3: Remove the 1st element, nums becomes [3,0,0,0] and the maximum segment sum is 3 for segment [3].
Query 4: Remove the 0th element, nums becomes [0,0,0,0] and the maximum segment sum is 0, since there are no segments.
Finally, we return [16,5,3,0].
 

Constraints:

n == nums.length == removeQueries.length
1 <= n <= 10^5
1 <= nums[i] <= 10^9
0 <= removeQueries[i] < n
All the values of removeQueries are unique.
*/

/*
TLE: 27 / 42

class Solution {
public:
    
    long long findMaxSegSum(vector<int>&nums){
        int sz=nums.size();
        long long maxxsm=LONG_MIN;
        for(int i=0; i<sz; ++i){
            long long cursm=0;
            for(int j=i; j<sz; ++j){
                if(cursm!=0&&nums[j]==0) break;
                cursm+=nums[j];
                maxxsm=max(maxxsm, cursm);
            }
        }
        return maxxsm;
    }
    
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int sz=nums.size();
        vector<long long>ans(sz, 0);
        int i=0;
        for(auto &vals: removeQueries){
            nums[vals]=0;
            ans[i++]=findMaxSegSum(nums);
        }
        return ans;
    }
};
*/

/*
	For the current index (curr) we will first find the left to be removed index (L) and right to be removed index (R)

	We will delete the current segment sum -> pre[right-1]-pre[left]

	We will insert the left segment sum -> pre[curr-1]-pre[left]

	We will insert the right segment sum -> pre[right-1]-pre[curr]

	We will find the max among all the sums
*/

#define ll long long

class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int sz=nums.size();
        vector<ll>pre(sz, 0);
        pre[0]=nums[0];
        for(int i=1; i<sz; ++i){
            pre[i]+=pre[i-1]+nums[i];
        }
        set<int>idxes;
        idxes.insert(-1);
        idxes.insert(sz);
        vector<ll>ans(sz, 0);
        multiset<ll>smSegs;
        smSegs.insert(pre[sz-1]);
        for(int i=0; i<sz; ++i){
            int currRmInd=removeQueries[i];
            auto it=idxes.lower_bound(currRmInd);
            int rRmInd=*it;
            int lRmInd=*(prev(it));
            ll curr_sum=pre[rRmInd-1]-(lRmInd==-1?0:pre[lRmInd]);
            smSegs.erase(smSegs.find(curr_sum));
            ll leftSm=(currRmInd==0?0:pre[currRmInd-1])-(lRmInd==-1?0:pre[lRmInd]);
            ll rightSm=(rRmInd==0?0:pre[rRmInd-1]-pre[currRmInd]);
            smSegs.insert(leftSm), smSegs.insert(rightSm);
            idxes.insert(currRmInd);
            ans[i]=*(smSegs.rbegin());
        }
        return ans;
    }
};

// -------*******-------

/*
In the end, we remove all elements from the array (nums.length == removeQueries.length).

So, we can start from no segments, add elements in the reverse (of the removal) order, and create/merge segments.

As we add an element, it can either:

create a new segment (e.g. __, [7], __)
join an existing segment on the left (e.g. 5, 6, [7], __)
join an existing segment on the right (e.g. __, [7], 8, 9)
merge existing segments on the left and right into one (e.g. 5, 6, [7], 8, 9)
*/

#define ll long long

class Solution2 {
public:
    
    int findParent(int i, vector<ll>&parent){
        if(parent[i]!=i){
            parent[i]=findParent(parent[i], parent);
        }
        return parent[i];
    }
    
    void doUnion(int x, int y, vector<ll>&rank, vector<ll>&parent){
        if(rank[x]>=rank[y]){
            parent[y]=x;
            rank[x]+=rank[y];
        } else{
            parent[x]=y;
            rank[y]+=rank[x];
        }
    }
    
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        ll n=nums.size();
        vector<ll>parent(n), rank(n, 0);
        for(int i=0; i<n; ++i){
            parent[i]=i;
        }
        vector<ll>res(n);
        for(int i=n-1; i>0; --i){
            int idx=removeQueries[i];
            int value=nums[idx];
            rank[idx]=value;
            if(idx>0&&rank[idx-1]!=0){
                int x=findParent(idx, parent);
                int y=findParent(idx-1, parent);
                doUnion(x, y, rank, parent);
            }
            if(idx+1<n&&rank[idx+1]!=0){
                int x=findParent(idx, parent);
                int y=findParent(idx+1, parent);
                doUnion(x, y, rank, parent);
            }
            int x=findParent(idx, parent);
            res[i-1]=max(res[i], rank[x]);
        }
        return res;
    }
};