// 2197. Replace Non-Coprime Numbers in Array
/*
You are given an array of integers nums. Perform the following steps:

Find any two adjacent numbers in nums that are non-coprime.
If no such numbers are found, stop the process.
Otherwise, delete the two numbers and replace them with their LCM (Least Common Multiple).
Repeat this process as long as you keep finding two adjacent non-coprime numbers.

Return the final modified array. It can be shown that replacing adjacent non-coprime 
numbers in any arbitrary order will lead to the same result.

The test cases are generated such that the values in the final array are less than or equal to 10^8.

Two values x and y are non-coprime if GCD(x, y) > 1 where GCD(x, y) is the Greatest Common Divisor of x and y.

Example 1:

Input: nums = [6,4,3,2,7,6,2]
Output: [12,7,6]
Explanation: 
- (6, 4) are non-coprime with LCM(6, 4) = 12. Now, nums = [12,3,2,7,6,2].
- (12, 3) are non-coprime with LCM(12, 3) = 12. Now, nums = [12,2,7,6,2].
- (12, 2) are non-coprime with LCM(12, 2) = 12. Now, nums = [12,7,6,2].
- (6, 2) are non-coprime with LCM(6, 2) = 6. Now, nums = [12,7,6].
There are no more adjacent non-coprime numbers in nums.
Thus, the final modified array is [12,7,6].
Note that there are other ways to obtain the same resultant array.
Example 2:

Input: nums = [2,2,1,1,3,3,3]
Output: [2,1,1,3]
Explanation: 
- (3, 3) are non-coprime with LCM(3, 3) = 3. Now, nums = [2,2,1,1,3,3].
- (3, 3) are non-coprime with LCM(3, 3) = 3. Now, nums = [2,2,1,1,3].
- (2, 2) are non-coprime with LCM(2, 2) = 2. Now, nums = [2,1,1,3].
There are no more adjacent non-coprime numbers in nums.
Thus, the final modified array is [2,1,1,3].
Note that there are other ways to obtain the same resultant array.
 

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^5
The test cases are generated such that the values in the final array are less than or equal to 10^8.
*/
/*
TLE:

class Solution {
public:
    
    int gcd(int A, int B){
        if(B==0) return A;
        return (gcd(B, A%B));
    }
    
    int getLCM(int A, int B){
        return (A/gcd(A, B))*B;    
    }
    
    bool areNonCoprime(int A, int B){
        int gcdNms=gcd(A, B);
        return gcdNms>1;
    }
    
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        while(true){
            bool flag=false;
            int sz=nums.size();
            for(int i=0; i<sz-1; ++i){
                if(areNonCoprime(nums[i], nums[i+1])){
                    flag=true;
                    int lcm=getLCM(nums[i], nums[i+1]);
                    auto it3=nums.begin()+(i+2);
                    nums[i]=-1, nums[i+1]=-1;
                    nums.insert(it3, lcm);
                    nums.erase(remove(nums.begin(), nums.end(), -1), nums.end());
                    break;
                }
            }
            if(!flag) break;
        }
        return nums;
    }
};
*/
/*
Solution2:

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int>res;
        for(auto &vals: nums){
            res.push_back(vals);
            while(res.size()>1&&__gcd(res.back(), res[res.size()-2])>1){
                long long a=res.back(), b=res[res.size()-2], g=__gcd(a, b);
                res.pop_back();
                res.pop_back();
                res.push_back(a*b/g);
            }
        }
        return res;
    }
};
*/

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int>st;
        int numssz=nums.size();
        for(int i=0; i<numssz; ++i){
            int gcd, lcm, tp;
            int curr=nums[i];
            while(!st.empty()){
                int gcd=__gcd(curr, st.top());
                if(gcd>1){
                    tp=st.top();
                    st.pop();
                    lcm=(curr/gcd)*tp;
                    curr=lcm;
                } else break;
            }
            st.push(curr);
        }
        vector<int>res;
        while(!st.empty()){
            int tp=st.top();
            res.push_back(tp);
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};