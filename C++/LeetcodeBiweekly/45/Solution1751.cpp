// 1751. Maximum Number of Events That Can Be Attended II
/*
You are given an array of events where events[i] = [startDayi, endDayi, valuei]. 
The ith event starts at startDayi and ends at endDayi, and if you attend this event, 
you will receive a value of valuei. You are also given an integer k which represents 
the maximum number of events you can attend.

You can only attend one event at a time. If you choose to attend an event, 
you must attend the entire event. Note that the end day is inclusive: that is, you 
cannot attend two events where one of them starts and the other ends on the same day.

Return the maximum sum of values that you can receive by attending events.

Examples:

Input: events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
Output: 7
Explanation: Choose the green events, 0 and 1 (0-indexed) for a total value of 4 + 3 = 7.

Input: events = [[1,2,4],[3,4,3],[2,3,10]], k = 2
Output: 10
Explanation: Choose event 2 for a total value of 10.
Notice that you cannot attend any other event as they overlap, and that you do not have to attend k events.

Input: events = [[1,1,1],[2,2,2],[3,3,3],[4,4,4]], k = 3
Output: 9
Explanation: Although the events do not overlap, you can only attend 3 events. Pick the highest valued three.

Constraints:

1 <= k <= events.length
1 <= k * events.length <= 10^6
1 <= startDayi <= endDayi <= 10^9
1 <= valuei <= 106
*/

/*
TLE: Sol 1

class Solution {
public:
    
    int dfs(vector<vector<int>>&events, int k, int idx, int sz, vector<vector<int>>&memo){
        if(idx>=sz||k==0) return 0;
        if(memo[idx][k]!=-1) return memo[idx][k];
        int maxsm=0;
        for(int i=idx+1; i<sz; ++i){
            if(events[i][0]>events[idx][1]){
                if(k>0){
                    int curprof=dfs(events, k-1, i, sz, memo);
                    maxsm=max(maxsm, curprof);
                }
            }
        }
        maxsm+=events[idx][2];
        return memo[idx][k]=maxsm;
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int sz=events.size();
        int ans=INT_MIN;
        for(int i=0; i<sz; ++i){
            vector<vector<int>>memo(sz+1, vector<int>(k+1, -1));
            int cursum=dfs(events, k, i, sz, memo);
            ans=max(ans, cursum);
        }
        return ans;
    }
};
*/

/*
TLE: Sol 2

class Solution {
public:
    
    int dfs(vector<vector<int>>&events, int idx, int tempk, int k, int sz, int &ans, vector<vector<int>>&memo){
        if(idx>=sz||tempk==k) return memo[idx][tempk]=0;
        if(memo[idx][k]!=-1) return memo[idx][tempk];
        int i;
        for(i=idx+1; i<sz; ++i){
            if(events[i][0]>events[idx][1]) break;
        }
        int tempans=max(dfs(events, idx+1, tempk, k, sz, ans, memo), 
                        dfs(events, i, tempk+1, k, sz, ans, memo)+events[idx][2]);
        ans=max(ans, tempans);
        return memo[idx][tempk]=tempans;
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int sz=events.size();
        int ans=INT_MIN;
        vector<vector<int>>memo(sz+1, vector<int>(k+1, -1));
        dfs(events, 0, 0, k, sz, ans, memo);
        return ans;
    }
};
*/

class Solution3 {
public:
    
    int dfs(vector<vector<int>>&events, int idx, int k, int sz, int &ans, vector<vector<int>>&memo){
        if(idx>=sz||k==0) return memo[idx][k]=0;
        if(memo[idx][k]!=-1) return memo[idx][k];
        int i;
        for(i=idx+1; i<sz; ++i){
            if(events[i][0]>events[idx][1]) break;
        }
        int tempans=max(dfs(events, idx+1, k, sz, ans, memo), 
                        dfs(events, i, k-1, sz, ans, memo)+events[idx][2]);
        ans=max(ans, tempans);
        return memo[idx][k]=tempans;
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int sz=events.size();
        int ans=INT_MIN;
        vector<vector<int>>memo(sz+1, vector<int>(k+1, -1));
        dfs(events, 0, k, sz, ans, memo);
        return ans;
    }
};

class Solution2 {
public:
    
    int dfs(vector<vector<int>>&events, int idx, int k, int sz, int &ans, vector<vector<int>>&memo){
        if(idx==-1) return 0;
        if(idx>=sz||k==0) return 0;
        if(memo[idx][k]!=-1) return memo[idx][k];
        vector<int>temp={events[idx][1], INT_MAX, INT_MAX};
        int i=upper_bound(events.begin()+idx+1, events.end(), temp)-events.begin();
        int tempans=max(dfs(events, idx+1, k, sz, ans, memo), 
                        dfs(events, i, k-1, sz, ans, memo)+events[idx][2]);
        ans=max(ans, tempans);
        return memo[idx][k]=tempans;
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int sz=events.size();
        int ans=INT_MIN;
        vector<vector<int>>memo(sz+1, vector<int>(k+1, -1));
        dfs(events, 0, k, sz, ans, memo);
        return ans;
    }
};

class Solution {
public:
    
    int find(vector<vector<int>>&events,int start,int toFind)
    {
        int low=start;
        int high=events.size()-1;
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(events[mid][0]>toFind)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
    
    int dfs(vector<vector<int>>&events, int idx, int k, int sz, int &ans, vector<vector<int>>&memo){
        if(idx==-1) return 0;
        if(idx>=sz||k==0) return 0;
        if(memo[idx][k]!=-1) return memo[idx][k];
        int i=find(events,idx+1,events[idx][1]);
        int tempans=max(dfs(events, idx+1, k, sz, ans, memo), 
                        dfs(events, i, k-1, sz, ans, memo)+events[idx][2]);
        ans=max(ans, tempans);
        return memo[idx][k]=tempans;
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int sz=events.size();
        int ans=INT_MIN;
        vector<vector<int>>memo(sz+1, vector<int>(k+1, -1));
        dfs(events, 0, k, sz, ans, memo);
        return ans;
    }
};