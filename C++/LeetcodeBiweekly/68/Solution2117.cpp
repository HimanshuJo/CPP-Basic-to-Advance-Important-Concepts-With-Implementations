// 2117. Abbreviating the Product of a Range
/*
You are given two positive integers left and right with left <= right. 
Calculate the product of all integers in the inclusive range [left, right].

Since the product may be very large, you will abbreviate it following these steps:

Count all trailing zeros in the product and remove them. Let us denote this count as C.
For example, there are 3 trailing zeros in 1000, and there are 0 trailing zeros in 546.
Denote the remaining number of digits in the product as d. If d > 10, 
then express the product as <pre>...<suf> where <pre> denotes the first 5 digits of the product, 
and <suf> denotes the last 5 digits of the product after removing all trailing zeros. If d <= 10, we keep it unchanged.

For example, we express 1234567654321 as 12345...54321, but 1234567 is represented as 1234567.
Finally, represent the product as a string "<pre>...<suf>eC".

For example, 12345678987600000 will be represented as "12345...89876e5".
Return a string denoting the abbreviated product of all integers in the inclusive range [left, right].


Example 1:

Input: left = 1, right = 4
Output: "24e0"
Explanation: The product is 1 × 2 × 3 × 4 = 24.
There are no trailing zeros, so 24 remains the same. The abbreviation will end with "e0".
Since the number of digits is 2, which is less than 10, we do not have to abbreviate it further.
Thus, the final representation is "24e0".

Example 2:

Input: left = 2, right = 11
Output: "399168e2"
Explanation: The product is 39916800.
There are 2 trailing zeros, which we remove to get 399168. The abbreviation will end with "e2".
The number of digits after removing the trailing zeros is 6, so we do not abbreviate it further.
Hence, the abbreviated product is "399168e2".
Example 3:

Input: left = 371, right = 375
Output: "7219856259e3"
Explanation: The product is 7219856259000.
 

Constraints:

1 <= left <= right <= 10^4
*/
/*
Solution 2: TLE

import java.math.BigInteger;

class Solution {
    
    ArrayList<Long>res=new ArrayList<>();
    
    public String abbreviateProduct(int left, int right) {
        long ans=1;
        for(int i=left; i<=right; ++i){
            ans*=i;
            if(ans>=Integer.MAX_VALUE){
                res.add(ans);
                ans=1;
            }
        }
        long fnres=1;
        BigInteger mult=new BigInteger("1");
        if(res.size()>=1){
            for(long vals: res){
                StringBuilder sb_ = new StringBuilder();
                sb_.append(vals);
                BigInteger nw= new BigInteger(sb_.toString());
                mult = mult.multiply(nw);
            }
            StringBuilder temp = new StringBuilder();
            temp.append(ans);
            BigInteger nw_= new BigInteger(temp.toString());
            mult = mult.multiply(nw_);
        } else{
            StringBuilder sb_ = new StringBuilder();
            sb_.append(ans);
            BigInteger nw= new BigInteger(sb_.toString());
            mult = mult.multiply(nw);
        }
        int len=mult.toString().length();
        StringBuilder finalans_=new StringBuilder();
        StringBuilder tempans_=new StringBuilder(mult.toString());
        int cnt_=0;
        int idx_=len-1;
        while(true){
            if(tempans_.charAt(idx_)=='0'){
                cnt_++;
                idx_--;
            } else break;
        }
        int nwlen=len-cnt_;
        if(nwlen>10){
            StringBuilder ans_=new StringBuilder(mult.toString());
            int cnt=0;
            int idx=len-1;
            while(true){
                if(ans_.charAt(idx)=='0'){
                    cnt++;
                    idx--;
                } else break;
            }
            for(int i=0; i<5; ++i){
                finalans_.append(ans_.charAt(i));
            }
            len-=cnt;
            finalans_.append("...");
            int counter=0;
            int nwIdx=(idx-5)+1;
            while(true){
                finalans_.append(ans_.charAt(nwIdx));
                counter++;
                if(counter==5) break;
                nwIdx++;
            }
            finalans_.append("e");
            finalans_.append(cnt);
        } else{
            StringBuilder ans_=new StringBuilder(mult.toString());
            int cnt=0;
            int idx=len-1;
            while(true){
                if(ans_.charAt(idx)=='0'){
                    cnt++;
                    idx--;
                } else break;
            }
            len-=cnt;
            for(int i=0; i<len; ++i){
                finalans_.append(ans_.charAt(i));
            }
            finalans_.append("e");
            finalans_.append(cnt);
        }
        return finalans_.toString();
    }
}
*/

using ll=long long;

class Solution {
public:
    string abbreviateProduct(int left, int right) {
        ll suffix=1, count=0, total=0, maxSuffix=1000'000'000'00;
        double pref=1.0;
        for(int i=left; i<=right; ++i){
            pref*=i, suffix*=i;
            while(pref>=100'000){
                pref/=10;
                total=total==0?6:total+1;
            }
            while(suffix%10==0){
                suffix/=10, ++count;
            }
            suffix%=maxSuffix;
        }
        string s=to_string(suffix);
        return (to_string((int)pref)+(total-count<=10?"":"...")+
                (total-count<5?"":s.substr(s.size()-min(5ll, total-count-5))))+
                "e"+to_string(count);
    }
};