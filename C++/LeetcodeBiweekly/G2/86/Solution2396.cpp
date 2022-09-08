// 2396. Strictly Palindromic Number
/*
An integer n is strictly palindromic if, for every base b between 2 and n - 2 (inclusive), 
the string representation of the integer n in base b is palindromic.

Given an integer n, return true if n is strictly palindromic and false otherwise.

A string is palindromic if it reads the same forward and backward.

 

Example 1:

Input: n = 9
Output: false
Explanation: In base 2: 9 = 1001 (base 2), which is palindromic.
In base 3: 9 = 100 (base 3), which is not palindromic.
Therefore, 9 is not strictly palindromic so we return false.
Note that in bases 4, 5, 6, and 7, n = 9 is also not palindromic.
Example 2:

Input: n = 4
Output: false
Explanation: We only consider base 2: 4 = 100 (base 2), which is not palindromic.
Therefore, we return false.

Constraints:

4 <= n <= 10^5
*/

class Solution {
public:
    
    string convtobase(int n, int j){
        string res="";
        while(n>=j){
            int nwn=n/j;
            int rem=n%j;
            res+=to_string(rem);
            n=nwn;
        }
        res+=to_string(n);
        reverse(res.begin(), res.end());
        return res;
    }
    
    bool isPalindrome(string str){
        int left=0, right=str.length()-1;
        while(left<right){
            if(str[left]!=str[right]) return false;
            left++, right--;
        }
        return true;
    }
    
    bool isStrictlyPalindromic(int n) {
        if(!isPalindrome(to_string(n))) return false;
        for(int j=2; j<=n-2; ++j){
            string toothbase=convtobase(n, j);
            if(!isPalindrome(toothbase)) return false;
        }
        return true;
    }
};