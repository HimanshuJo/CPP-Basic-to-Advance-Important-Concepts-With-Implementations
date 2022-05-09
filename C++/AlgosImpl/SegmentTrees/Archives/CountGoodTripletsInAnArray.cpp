// 2179. Count Good Triplets in an Array
/*
You are given two 0-indexed arrays nums1 and nums2 of length n, 
both of which are permutations of [0, 1, ..., n - 1].

A good triplet is a set of 3 distinct values which are present in increasing order by 
position both in nums1 and nums2. 

In other words, if we consider pos1v as the index of the value v in nums1 and pos2v as 
the index of the value v in nums2, then a good triplet will be a set (x, y, z) where 
0 <= x, y, z <= n - 1, such that pos1x < pos1y < pos1z and pos2x < pos2y < pos2z.

Return the total number of good triplets.

Example 1:

Input: nums1 = [2,0,1,3], nums2 = [0,1,2,3]
Output: 1
Explanation: 
There are 4 triplets (x,y,z) such that pos1x < pos1y < pos1z. They are (2,0,1), (2,0,3), (2,1,3), and (0,1,3). 
Out of those triplets, only the triplet (0,1,3) satisfies pos2x < pos2y < pos2z. Hence, there is only 1 good triplet.
Example 2:

Input: nums1 = [4,0,1,3,2], nums2 = [4,1,0,2,3]
Output: 4
Explanation: The 4 good triplets are (4,0,3), (4,0,2), (4,1,3), and (4,1,2).
 

Constraints:

n == nums1.length == nums2.length
3 <= n <= 105
0 <= nums1[i], nums2[i] <= n - 1
nums1 and nums2 are permutations of [0, 1, ..., n - 1]
*/

/*
TLE:

class Solution {
public:
    
    void dfs(vector<int>&nums1, int sz, int idx, vector<vector<int>>&triplets, vector<int>currtriplet){
        if(idx>=sz){
            if(currtriplet.size()==3){
                triplets.push_back(currtriplet);
            }
            return;
        }
        currtriplet.push_back(nums1[idx]);
        dfs(nums1, sz, idx+1, triplets, currtriplet);
        currtriplet.pop_back();
        dfs(nums1, sz, idx+1, triplets, currtriplet);
    }
    
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>triplets;
        vector<vector<int>>triplets2;
        vector<int>currtriplet;
        vector<int>currtriplet2;
        int sz=nums1.size();
        int sz2=nums2.size();
        dfs(nums1, sz, 0, triplets, currtriplet);
        dfs(nums2, sz2, 0, triplets2, currtriplet2);
        long long ans=0;
        for(auto &vals: triplets){
            auto it=find(triplets2.begin(), triplets2.end(), vals);{
                if(it!=triplets2.end()) ans++;
            }
        }
        return ans;
    }
};
*/

using ll=long long;

class Solution {
public:
    
    class SegmentTree{
        public:
        int size;
        vector<int>values;
        
        SegmentTree(int sz): size(sz){
            values=vector<int>(sz*2);
        }
        
        void increase(int pos){
            pos+=size;
            while(pos>0){
                values[pos]++;
                pos/=2;
            }
        }
        
        int sum(int l, int r){
            l+=size, r+=size;
            int res=0;
            while(l<=r){
                if(l%2==1){
                    res+=values[l];
                    l++;
                }
                if(r%2==0){
                    res+=values[r];
                    r--;
                }
                r/=2, l/=2;
            }
            return res;
        }
    };
    
    
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int>indexMap(n, 0);
        for(int i=0; i<n; ++i){
            indexMap[nums2[i]]=i;
        }
        for(int i=0; i<n; ++i){
            nums2[indexMap[nums1[i]]]=i;
            nums1[i]=i;
        }
        SegmentTree st(n);
        ll res=0;
        st.increase(nums2[0]);
        for(int i=1; i<n-1; ++i){
            int num=nums2[i];
            int l=st.sum(0, num-1);
            int r=n-num-i+l-1;
            res+=(ll)r*l;
            st.increase(num);
        }
        return res;
    }
};