// 1734. Decode XORed Permutation
/*
There is an integer array perm that is a permutation of the first n positive integers, where n is always odd.

It was encoded into another integer array encoded of length n - 1, 
such that encoded[i] = perm[i] XOR perm[i + 1]. For example, if perm = [1,3,2], then encoded = [2,1].

Given the encoded array, return the original array perm. It is guaranteed that the answer exists and is unique.


Example 1:

Input: encoded = [3,1]
Output: [1,2,3]
Explanation: If perm = [1,2,3], then encoded = [1 XOR 2,2 XOR 3] = [3,1]
Example 2:

Input: encoded = [6,5,4,6]
Output: [2,4,1,5,3]
 

Constraints:

3 <= n < 10^5
n is odd.
encoded.length == n - 1
*/

/*
TLE: 33 / 63

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int maxx=INT_MIN;
        int fstNum, scndNum;
        for(auto &vals: encoded){
            if(vals>maxx){
                maxx=vals;
            }
        }
        set<pair<int, int>>seen;
        while(true){
            bool flag=false;
            for(int i=1; i<maxx; ++i){
                for(int j=1; j<maxx; ++j){
                    if((i^j)==encoded[0]&&(seen.find({i, j})==seen.end())){
                        fstNum=i, scndNum=j;
                        seen.insert({i, j});
                        flag=true;
                        break;
                    }
                }
                if(flag) break;
            }
            int sz=encoded.size();
            vector<int>ans(sz+1, 0);
            ans[0]=fstNum, ans[1]=scndNum;
            bool flag2=false;
            for(int i=2; i<=sz; ++i){
                ans[i]=encoded[i-1]^ans[i-1];
            }
            vector<int>temp=ans;
            sort(temp.begin(), temp.end());
            for(int i=0; i<=sz; ++i){
                if(i+1!=temp[i]){
                    flag2=true;
                    break;
                }
            }
            if(flag2){
                vector<int>ans_(sz+1, 0);
                swap(fstNum, scndNum);
                ans_[0]=fstNum, ans_[1]=scndNum;
                for(int i=2; i<=sz; ++i){
                    ans_[i]=encoded[i-1]^ans_[i-1];
                }
                bool flag2_=false;
                vector<int>temp=ans_;
                sort(temp.begin(), temp.end());
                for(int i=0; i<=sz; ++i){
                    if(i+1!=temp[i]){
                        flag2_=true;
                        break;
                    }
                }
                if(!flag2_) return ans_;   
            }
            if(!flag2) return ans;
        }
    }
};

*/

/*
Explanation:

We make good use of the condition "n is odd" as follow
a1,(a2,a3),(a4,a5).....,
making the decoded into pairs.
a2^a3 = A[1]
a4^a5 = A[3]
a6^a7 = A[5]
...
so we can have the result of a2^a3^a4...^an.
And a1,a2,a3... is a permuatation of 1,2,3,4..n

so we can have
a1 = 1^2^3...^n^a2^a2^a3...^an

Then we can deduct the whole decoded array.

Complexity
Time O(n)
Space O(n)
*/
/*
XOR properties and tips

Let's note xor as xor instead of ^
1) For a xor b = c , you can write
b = c xor a
or a = c xor b

You can use 2) and 3) to demonstrate 1) .
2) XOR is commutative, a xor b = b xor a
3) XOR to the same number is always zero a xor a = 0

Intuition

If the first element is determined, the whole array can be decoded.

    encoded[i] = perm[i] XOR perm[i + 1] implies

perm[i+1] = perm[i] XOR encoded[i] thanks to 1)
So you can loop to find the next perm element
See 1720. Decode XORed Array

But you still need perm[0] , the first element in output array.

-------

Find the first element

Integer array perm that is a permutation of the first n positive integers, where n is always odd.

Yes, perm is an array with values ranging from [1,2,3 .. n]. The order in the array is permuted.

Let's XOR all elements in array perm. And perms is an array with first n positive integers
perm[0] XOR perm[1] XOR ... perm[n] = 1 XOR 2 XOR 3 .. XOR n Order doesn't matter, XOR is commutative.

Let's call totalXor

totalXor = 1 XOR 2 XOR 3 .. XOR n .

XOR all except the first perm[0]

perm[0] = totalXor XOR perm[1] XOR perm[2] XOR perm[3] XOR perm[4] XOR ... perm[n]

Let's subsitute (replace) by encoded

    encoded[i] = perm[i] XOR perm[i + 1]

encoded[1] = perm[1] XOR perm[2]
encoded[3] = perm[3] XOR perm[4]

...

encoded[n-2] = perm[n-2] XOR perm[n-1], remember n is the size of perm and is always odd

perm[0] = totalXor XOR encoded[1] XOR encoded[3] ... encoded[n-2]
Only the odd indexes of encoded are taken.

Solutions big O

Time complexity: O(n)
Space complexity: O(n)
*/

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int fstNum=0;
        int n=encoded.size()+1;
        for(int i=0; i<=n; ++i) {
            fstNum^=i;
            if(i<n&&i%2==1) {
                fstNum^=encoded[i];
            }
        }
        int sz=encoded.size();
        vector<int>ans(sz+1, 0);
        ans[0]=fstNum;
        for(int i=0; i<sz; ++i){
            ans[i+1]=encoded[i]^ans[i];
        }
        return ans;
    }
};