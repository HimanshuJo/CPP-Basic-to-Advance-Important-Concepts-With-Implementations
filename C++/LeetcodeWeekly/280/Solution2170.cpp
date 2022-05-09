// 2170. Minimum Operations to Make the Array Alternating
/*
You are given a 0-indexed array nums consisting of n positive integers.

The array nums is called alternating if:

nums[i - 2] == nums[i], where 2 <= i <= n - 1.
nums[i - 1] != nums[i], where 1 <= i <= n - 1.
In one operation, you can choose an index i and change nums[i] into any positive integer.

Return the minimum number of operations required to make the array alternating.

 

Example 1:

Input: nums = [3,1,3,2,4,3]
Output: 3
Explanation:
One way to make the array alternating is by converting it to [3,1,3,1,3,1].
The number of operations required in this case is 3.
It can be proven that it is not possible to make the array alternating in less than 3 operations. 
Example 2:

Input: nums = [1,2,2,2,2]
Output: 2
Explanation:
One way to make the array alternating is by converting it to [1,2,1,2,1].
The number of operations required in this case is 2.
Note that the array cannot be converted to [2,2,2,2,2] because in this case nums[0] == nums[1] which violates the conditions of an alternating array.
 

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^5
*/

/*
Accepted:

class Solution {
public:
    
    bool allSame(vector<int>&nums){
        int bgn=nums[0];
        int count=0;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i]==bgn) count++;
        }
        if(count==nums.size()) return true;
        return false;
    }
    
    int minimumOperations(vector<int>& nums) {
        if(allSame(nums)) return nums.size()/2;
        if(nums.size()==2&&nums[0]==nums[1]) return 1;
        if(nums.size()<=2) return 0;
        int ans=0;
        int n=nums.size();
        int tempans1=0;
        int tempans3=0;
        int bgn1=nums[0];
        int bgn3=nums[1];
        map<int, int>mp1;
        map<int, int>mp2;
        for(int i=0; i<n; i+=2)
            mp1[nums[i]]++;
        for(int i=1; i<n; i+=2)
            mp2[nums[i]]++;
        int temp1_=0, res1=INT_MIN;
        for(auto &vals: mp1){
            if(vals.second>res1){
                temp1_=vals.first;
                res1=vals.second;
            }
        }
        bgn1=temp1_;
        int nwtemp1=0;
        int temp2_=0, res2=INT_MIN;
        for(auto &vals: mp2){
            if(vals.second>res2){
                temp2_=vals.first;
                res2=vals.second;
            }
        }
        bgn3=temp2_;
        int nwtemp2=0;
        if(bgn1==bgn3){
            if(res1<res2){
                res1=INT_MIN;
                for(auto &vals: mp1){
                    if(vals.second>res1&&vals.first!=bgn1){
                        nwtemp1=vals.first;
                        res1=vals.second;
                    }
                }
                bgn1=nwtemp1;   
            } else{
                if(mp2.size()==1){
                    res1=INT_MIN;
                    for(auto &vals: mp1){
                        if(vals.second>res1&&vals.first!=bgn1){
                            nwtemp1=vals.first;
                            res1=vals.second;
                        }
                    }
                    bgn1=nwtemp1;  
                } else{
                    int tempres1=res1;
                    res1=INT_MIN;
                    for(auto &vals: mp1){
                        if(vals.second>res1&&vals.first!=bgn1){
                            nwtemp1=vals.first;
                            res1=vals.second;
                        }
                    }
                    if(tempres1==res1){
                        bgn1=nwtemp1; 
                    } else{
                        res1=INT_MIN;
                        for(auto &vals: mp1){
                            if(vals.second>res1&&vals.first!=bgn1){
                                nwtemp1=vals.first;
                                res1=vals.second;
                            }
                        }
                        res2=INT_MIN;
                        for(auto &vals: mp2){
                            if(vals.second>res2&&vals.first!=bgn3){
                                nwtemp2=vals.first;
                                res2=vals.second;
                            }
                        }
                        if(res1>res2){
                            bgn1=nwtemp1;
                        } else{
                            bgn3=nwtemp2;    
                        }   
                    }  
                }
            }
        }
        if(nums[0]!=bgn1){
            nums[0]=bgn1;
            tempans1++;
        }
        for(int i=0; i<n; i+=2){
            if(i+2<n){
                if(nums[i+2]!=bgn1){
                    nums[i+2]=bgn1;
                    tempans1++;
                }
            }
        }
        ans+=tempans1;
        if(nums[1]!=bgn3){
            nums[1]=bgn3;
            tempans3++;
        }
        for(int i=1; i<n; i+=2){
            if(i+2<n){
                if(nums[i+2]!=bgn3){
                    nums[i+2]=bgn3;
                    tempans3++;
                }
            }
        }
        ans+=tempans3;
        return ans;
    }
};
*/

class Solution {
public:

    array<int, 3> top2Freq(vector<int>& nums, int start) {
        int first = 0, second = 0, cnt[100001] = {};
        for (int i = start; i < nums.size(); i += 2)
            if (++cnt[nums[i]] >= cnt[first]) {
                if (nums[i] != first)
                    second = first;    
                first = nums[i];
            }
            else if (cnt[nums[i]] > cnt[second])
                second = nums[i];
        return {first, cnt[first], cnt[second]};
    }
    
    int minimumOperations(vector<int>& nums) {
        auto ev = top2Freq(nums, 0), od = top2Freq(nums, 1);
        return nums.size() - (ev[0] != od[0] ? ev[1] + od[1] : max(ev[1] + od[2], ev[2] + od[1]));
    }
};