// 2429. Minimize XOR
/*
Given two positive integers num1 and num2, find the integer x such that:

x has the same number of set bits as num2, and
The value x XOR num1 is minimal.
Note that XOR is the bitwise XOR operation.

Return the integer x. The test cases are generated such that x is uniquely determined.

The number of set bits of an integer is the number of 1's in its binary representation.

Example 1:

Input: num1 = 3, num2 = 5
Output: 3
Explanation:
The binary representations of num1 and num2 are 0011 and 0101, respectively.
The integer 3 has the same number of set bits as num2, and the value 3 XOR 3 = 0 is minimal.

Example 2:

Input: num1 = 1, num2 = 12
Output: 3
Explanation:
The binary representations of num1 and num2 are 0001 and 1100, respectively.
The integer 3 has the same number of set bits as num2, and the value 3 XOR 1 = 2 is minimal.

Constraints:

1 <= num1, num2 <= 10^9
*/

class Solution {
public:
    
    long long toDec(string num){
        int sz=num.size();
        int lstpwr=sz-1;
        long long val=0;
        for(int i=0; i<sz; ++i){
            val+=pow(2, lstpwr)*(num[i]-'0');
            lstpwr--;
        }
        return val;
    }
    
    string toBinary(int num){
        string bn="";
        while(num>1){
            int quo=num%2;
            bn+=to_string(quo);
            num/=2;
        }
        bn+=to_string(1);
        while(bn.size()!=32){
            bn+='0';
        }
        reverse(bn.begin(), bn.end());
        return bn;
    }
    
    int minimizeXor(int num1, int num2) {
        string ans="";
        int count=0;
        string num2tostr=toBinary(num2);
        string num1tostr=toBinary(num1);
        for(int i=0; i<num2tostr.size(); ++i){
            if(num2tostr[i]=='1'){
                count++;
            }
        }
        ans.resize(num1tostr.size(), '0');
        for(int i=0; i<num1tostr.size(); ++i){
            if(num1tostr[i]=='1'){
                if(count>0){
                    ans[i]='1';
                    count--;
                }
            }
        }
        int sz__=ans.size();
        sz__--;
        while(count>0){
            if(ans[sz__]=='0'){
                ans[sz__]='1';
                count--;
                sz__--;
            } else{
                sz__--;
            }
        }
        return toDec(ans);
    }
};