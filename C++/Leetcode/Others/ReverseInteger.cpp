/*
Given a signed 32-bit integer x, return x with its digits reversed. 
If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
 

Constraints:

-2^31 <= x <= 2^31 - 1
*/

/*
using inbuilt utilities

class Solution {
public:
    int reverse(int x) {
        int fnres=0;
        if(x<0){
            string res="";
            res=to_string(x);
            std::reverse(res.begin(), res.end());
            fnres=(stol(res)*-1)<INT_MIN?0:(stoi(res)*-1);
            return fnres;
        } else{
            string res="";
            res=to_string(x);
            std::reverse(res.begin(), res.end());
            fnres=stol(res)>INT_MAX?0:stoi(res);
            return fnres;
        }
        return fnres;
    }
};
*/

/*

Intuition

    We can build up the reverse integer one digit at a time. 
    While doing so, we can check beforehand whether or not appending another digit would cause overflow.

Algorithm

    Reversing an integer can be done similarly to reversing a string.

    We want to repeatedly "pop" the last digit off of x and "push" it to the back of the rev. 
    In the end, rev will be the reverse of the x.

    To "pop" and "push" digits without the help of some auxiliary stack/array, we can use math.

    //pop operation:
    pop = x % 10;
    x /= 10;

    //push operation:
    temp = rev * 10 + pop;
    rev = temp;

    -------

    However, this approach is dangerous, because the statement temp=rev⋅10+pop can cause overflow.

    Luckily, it is easy to check beforehand whether or this statement would cause an overflow.

    INT_MAX=2147483647, INT_MIN=-2147483648

    To explain, lets assume that rev is positive.

        If temp=rev⋅10+pop causes overflow, then it must be that rev≥INT_MAX/10
 
        If rev>INT_MAX/10, then temp=rev⋅10+pop is guaranteed to overflow.

        If rev==INT_MAX/10, then temp=rev⋅10+pop will overflow if and only if pop>7

            as 2147483640 + 7 = INT_MAX
               2147483640 + 8 = INT_MAX+1
    
    Similar logic can be applied when rev is negative.

        If temp=rev*10-pop causes underflow, then it must be that rev<=INT_MIN/10

        If rev<INT_MIN/10, then temp=rev*10-pop is guranteed to underflow.

        If rev==INT_MIN/10, then temp=rev*10-pop will underflow if and only if pop<-8
            
            as -2147483640 - 8 = INT_MIN,
               -2147483640 - 9 = INT_MIN-1 
*/

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};