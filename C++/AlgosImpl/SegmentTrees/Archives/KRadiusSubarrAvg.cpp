// 2090. K Radius Subarray Averages
/*
You are given a 0-indexed array nums of n integers, and an integer k.

The k-radius average for a subarray of nums centered at some index i with the radius k 
is the average of all elements in nums between the indices i - k and i + k (inclusive). 
If there are less than k elements before or after the index i, then the k-radius average is -1.

Build and return an array avgs of length n where avgs[i] is the k-radius average 
for the subarray centered at index i.

The average of x elements is the sum of the x elements divided by x, using integer division. 
The integer division truncates toward zero, which means losing its fractional part.

For example, the average of four elements 2, 3, 1, and 5 is (2 + 3 + 1 + 5) / 4 = 11 / 4 = 2.75, which truncates to 2.

Input: nums = [7,4,3,9,1,8,5,2,6], k = 3
Output: [-1,-1,-1,5,4,4,-1,-1,-1]
Explanation:
- avg[0], avg[1], and avg[2] are -1 because there are less than k elements before each index.
- The sum of the subarray centered at index 3 with radius 3 is: 7 + 4 + 3 + 9 + 1 + 8 + 5 = 37.
  Using integer division, avg[3] = 37 / 7 = 5.
- For the subarray centered at index 4, avg[4] = (4 + 3 + 9 + 1 + 8 + 5 + 2) / 7 = 4.
- For the subarray centered at index 5, avg[5] = (3 + 9 + 1 + 8 + 5 + 2 + 6) / 7 = 4.
- avg[6], avg[7], and avg[8] are -1 because there are less than k elements after each index.

Input: nums = [100000], k = 0
Output: [100000]
Explanation:
- The sum of the subarray centered at index 0 with radius 0 is: 100000.
  avg[0] = 100000 / 1 = 100000.

Input: nums = [8], k = 100000
Output: [-1]
Explanation: 
- avg[0] is -1 because there are less than k elements before and after index 0.
 

Constraints:

n == nums.length
1 <= n <= 10^5
0 <= nums[i], k <= 10^5
*/

/*
TLE:

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        map<int, pair<int, int>>mp;
        for(int i=0; i<nums.size(); ++i){
            if(i+k<=nums.size()-1&&i-k>=0){
                mp[i]={i-k, i+k};
            }
        }
        map<int, int>mp2;
        for(auto &entry: mp){
            int left=entry.second.first;
            int right=entry.second.second;
            int sm=0;
            int cnt=0;
            for(int i=left; i<=right; ++i){
                sm+=nums[i];
                cnt++;
            }
            int avg=sm/cnt;
            mp2[entry.first]=avg;
        }
        vector<int>res;
        for(int i=0; i<nums.size(); ++i){
            if(mp.find(i)!=mp.end()){
                res.push_back(mp2[i]);
            } else{
                res.push_back(-1);
            }
        }
        return res;
    }
};
*/

/*
Solution2:

#include<vector>
#include<map>
using namespace std;

class Solution {
public:

    int n;
    long long tree[2 * 100000];

    void build(vector<int> arr)
    {
        for (int i=0; i<n; i++)   
            tree[n+i] = arr[i];
        for (int i = n - 1; i > 0; --i)    
            tree[i] = tree[i<<1] + tree[i<<1 | 1];   
    }

    void updateTreeNode(int p, int value)
    {
        tree[p+n] = value;
        p = p+n;
        for (int i=p; i > 1; i >>= 1)
            tree[i>>1] = tree[i] + tree[i^1];
    }

    long long query(int l, int r)
    {
        long long res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l&1)
                res += tree[l++];

            if (r&1)
                res += tree[--r];
        }

        return res;
    }

    vector<int> getAverages(vector<int>& nums, int k) {
        n=nums.size();
        build(nums);
        if(k>nums.size()) return {-1};
        vector<int>res2(nums.size(), -1);
        map<int, pair<int, int>>mp;
        for(int i=0+k; i<nums.size()-k; ++i){
            if(i+k<=nums.size()-1&&i-k>=0){
                long long sm=0;
                long long avg=(i+k)-(i-k)+1;
                sm=query(i-k, (i+k)+1);
                res2[i]=sm/avg;
            }
        }
        return res2;
    }
};
*/

using ll=long long;

class Solution {
public:
    
    int getMid(int s, int e){
        return (s+(e-s)/2);
    }

    ll getSumUtil(vector<ll>&st, int ss, int se, int qs, int qe, int sidx){
        if(se<qs||ss>qe) return 0;
        if(ss>=qs&&se<=qe) return st[sidx];
        int mid=getMid(ss, se);
        return (getSumUtil(st, ss, mid, qs, qe, sidx*2+1)+
                getSumUtil(st, mid+1, se, qs, qe, sidx*2+2));
    }

    ll getSum(vector<ll>&st, int n, int qs, int qe){
        if(qs<0||qe>n-1||qs>qe){
            cout<<"Invalid "<<endl;
            return -1;
        }
        int ss=0, se=n-1, sidx=0;
        return (getSumUtil(st, ss, se, qs, qe, sidx));
    }

    void updateValueUtil(vector<ll>&st, int ss, int se, int diff, int vidx, int sidx){
        if(ss>vidx||se<vidx) return;
        st[sidx]=st[sidx]+diff;
        if(ss!=se){
            int mid=getMid(ss, se);
            updateValueUtil(st, ss, mid, diff, vidx, sidx*2+1);
            updateValueUtil(st, mid+1, se, diff, vidx, sidx*2+2);
        }
    }

    void updateValue(vector<int>&arr, vector<ll>&st, int n, int vidx, int nwVal){
        if(vidx<0||vidx>n-1){
            cout<<"Invalid "<<endl;
            return;
        }
        int diff=nwVal-arr[vidx];
        arr[vidx]=nwVal;
        int ss=0, se=n-1, sidx=0;
        updateValueUtil(st, ss, se, diff, vidx, sidx);
    }

    ll constructStUtil(vector<int>&arr, vector<ll>&st, int ss, int se, int sidx){
        if(ss==se){
            st[sidx]=arr[ss];
            return arr[ss];
        }
        int mid=getMid(ss, se);
        st[sidx]=constructStUtil(arr, st, ss, mid, sidx*2+1)+
                 constructStUtil(arr, st, mid+1, se, sidx*2+2);
        return st[sidx];
    }

    vector<ll> constructSt(vector<int>&arr, int n){
        int x=(int)(ceil(log2(n)));
        int maxSz=2*(int)pow(2, x)-1;
        vector<ll>st(maxSz, 0);
        int ss=0, se=n-1, sidx=0;
        constructStUtil(arr, st, ss, se, sidx);
        return st;
    }
 
    vector<int> getAverages(vector<int>& nums, int k) {
        int sz=nums.size();
        vector<ll>segTree=constructSt(nums, sz);
        vector<int>res(sz, -1);
        for(int i=0; i<sz; ++i){
            if(i+k<=nums.size()-1&&i-k>=0){
                long long sm=0;
                long long denom=k*2+1;
                sm=getSum(segTree, sz, i-k, (i+k));
                res[i]=sm/denom;
            }
        }
        return res;
    }
};
