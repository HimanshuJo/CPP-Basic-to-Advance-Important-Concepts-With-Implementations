#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int sz=nums.size();
        for(int i=0; i<sz-1; ++i){
            if(nums[i]>threshold) return 1;
            priority_queue<int, vector<int>, greater<>>pq;
            pq.push(nums[i]);
            for(int j=i+1; j<sz; ++j){
                pq.push(nums[j]);
                int sz_=pq.size();
                int tp=pq.top();
                if(tp>threshold/sz_) return pq.size();
            }
        }
        return -1;
    }
};
