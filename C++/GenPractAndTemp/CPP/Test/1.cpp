class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int sz=nums.size();
        long long ans=0;
        for(int i=0; i<sz; ++i){
            vector<int>curr;
            for(int j=i; j<sz; ++j){
                if(nums[j]>maxK||nums[j]<minK) break;
                curr.push_back(nums[j]);
                auto it=find(curr.begin(), curr.end(), minK);
                auto it2=find(curr.begin(), curr.end(), maxK);
                if(it!=curr.end()&&it2!=curr.end()) ans++;
            }
        }
        return ans;
    }
};