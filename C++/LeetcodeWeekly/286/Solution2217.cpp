// 2217. Find Palindrome With Fixed Length
/*
Given an integer array queries and a positive integer intLength, 
return an array answer where answer[i] is either the queries[i]th smallest 
positive palindrome of length intLength or -1 if no such palindrome exists.

A palindrome is a number that reads the same backwards and forwards. 
Palindromes cannot have leading zeros.

Example 1:

Input: queries = [1,2,3,4,5,90], intLength = 3
Output: [101,111,121,131,141,999]
Explanation:
The first few palindromes of length 3 are:
101, 111, 121, 131, 141, 151, 161, 171, 181, 191, 202, ...
The 90th palindrome of length 3 is 999.
Example 2:

Input: queries = [2,4,6], intLength = 4
Output: [1111,1331,1551]
Explanation:
The first six palindromes of length 4 are:
1001, 1111, 1221, 1331, 1441, and 1551.
 

Constraints:

1 <= queries.length <= 5 * 10^4
1 <= queries[i] <= 10^9
1 <= intLength <= 15
*/

/*
Only the first (intLength/2) characters matter

The remaining characters are just a reflection
e.g. suppose intLength==7, so we only consider 4 characters

The min number is 1000 and max 9999

Therefore we can have 9999-1000+1=9000 palindromes

For example: for query 8765, the base number is 1000+8756-1=9764
             
             concatenating it with 679 we get 9764679
*/

/*
TLE:

class Solution {
public:
    
    long long createPalindrome(long long input, long long b, bool isOdd)
    {
        long long n = input;
        long long palin = input;
        if (isOdd)
            n /= b;
        while (n > 0)
        {
            palin = palin * b + (n % b);
            n /= b;
        }
        return palin;
    }

    vector<long long> generatePalindromes(long long i, long long n)
    {
        long long number;
        vector<long long>palins;
        for (int j = 0; j < 2; j++)
        {
            while ((number = createPalindrome(i, 10, j % 2)) < n)
            {
                palins.push_back(number);
                i++;
            }
        }
        return palins;
    }
    
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        string bgn="1";
        if(intLength>1){
            int cnt=intLength/2;
            while(bgn.length()!=cnt){
                bgn+='0';
            }
            if(intLength%2!=0) bgn+='0';
        }
        long long start=stol(bgn);
        long long end=(long long)(pow(10, intLength));
        vector<long long>temp=generatePalindromes(start, end);
        int sz=queries.size();
        vector<long long>res(sz, -1);
        int idx=0;
        for(auto &vals: queries){
            vals--;
            if(vals>=temp.size()){}
            else res[idx]=temp[vals];
            idx++;
        }
        return res;
    }
};
*/
class Solution {
public:
    
    int reverse(long long n, bool skip){
        long long res=0;
        for(n=skip?n/10:n; n>0; n/=10){
            res=res*10+n%10;
        }
        return res;
    }
    
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        int sz=intLength;
        vector<long long>res;
        long long start=pow(10, (sz+1)/2-1), end=pow(10, (sz+1)/2), mul=pow(10, sz/2);
        for(auto &q: queries){
            res.push_back(start+q>end?-1:(start+q-1)*mul+reverse(start+q-1, sz%2));
        }
        return res;
    }
};