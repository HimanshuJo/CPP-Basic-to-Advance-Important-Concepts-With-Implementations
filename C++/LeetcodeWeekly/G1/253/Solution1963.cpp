// Minimum Number of Swaps to Make the String Balanced
/*
You are given a 0-indexed string s of even length n. The string consists of exactly n / 2 
opening brackets '[' and n / 2 closing brackets ']'.

A string is called balanced if and only if:

It is the empty string, or
It can be written as AB, where both A and B are balanced strings, or
It can be written as [C], where C is a balanced string.
You may swap the brackets at any two indices any number of times.

Return the minimum number of swaps to make s balanced.

Example 1:

Input: s = "][]["
Output: 1
Explanation: You can make the string balanced by swapping index 0 with index 3.
The resulting string is "[[]]".
Example 2:

Input: s = "]]][[["
Output: 2
Explanation: You can do the following to make the string balanced:
- Swap index 0 with index 4. s = "[]][][".
- Swap index 1 with index 5. s = "[[][]]".
The resulting string is "[[][]]".
Example 3:

Input: s = "[]"
Output: 0
Explanation: The string is already balanced.

Constraints:

n == s.length
2 <= n <= 106
n is even.
s[i] is either '[' or ']'.
The number of opening brackets '[' equals n / 2, and the number of closing brackets ']' equals n / 2.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        stack<int>stk;
        for (int i=0; i<s.length(); ++i){
            if (s.at(i)=='['){
                stk.push(i);
            } else if (s.at(i)==']'){
                if (!stk.empty()){
                    s[i]=' ';
                    int index=stk.top();
                    s[index]=' ';
                    stk.pop();
                }
            }
        }
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        //cout<<s<<endl;
        int unMd=s.size()/2;
        return ((unMd+1)/2);
    }
};

/*
First of all it is guarenteed that total number of '[' brackets is equal to total number of ']' brackets.
So, for every bracket element we are sure that its counterpart exist.
Also, to keep string balanced, at every i
count of '[' >= count of ']'
If at any moment count of ']' exceeds count of '[', this is the time when we need to do swaping.
As of now that we have noted few important observations, lets move to algorithm part.

To track if brackets are balanced at any index i, lets take a variable balance

balance = 0 , initially
When we see a opening bracket, we increament balance by one.

As we expect a closing bracket later who will balance it . '[' -> 1
Else When we see closing bracket, we decrement balance by one so that number

this will balance the opening bracket that occured previously. ']' -> -1

  string:    [   [    ]   ] 
  balance:   1   2    1   0   
  		(at last balance is zero which means all elements are matched)
Now, the main catch where we need to swap. When number of closing brackets exceed the already occured opening brackets. This is where we need to do swapping.

when balance < 0, or balance == -1 , swap this element with first occuring '[' from last.

Doing this we change our current balance to 1 and now we can move further in search of closing brackets.

  string:     [      ]       ]          [
  balance :	 (1)    (0)    (-1)  ....  (1)  
  // Swap (-1) with the last (1) to balance it
As soon as we swap the brackets, we need to again set balance to 1 as current bracket is opening -> '[' = 1

Lets Do a dry run on string : "[ ] ] ] [ [ ] ["

index:   0  1  2  3  4  5  6  7
string : [  ]  ]  ]  [  [  ]  [
balance: 1  0 -1  .  .  .  .  .
-> swap ']' at index 2 with first '[' from last i.e index 7
=> swap = 1 , set balance to 1 

After swapping we continue till end until balance does not become -1. 
If balance = -1, repeat above steps

index:   0  1  2  3  4  5  6  7
string : [  ]  [  ]  [  [  ]  ]
balance: 1  0  1  0  1  2  1  0  
-> This is final value of balance and state string that is balanced
*/

class Solution2{
    public:
        int minSwaps(string s) {
        int n = s.size();
        int balance = 0, swaps = 0, j=n-1;
        for(int i=0; i<n; i++)
        {
            if(s[i] == '[') balance++;
            else balance--;

            if(balance < 0)
            {
                while(i<j && s[j] != '[') j--;
                swap(s[i], s[j]);
                swaps++;
                balance = 1;
            }
        }
        return swaps;
    }
};

int main(){
    Solution obj;
    obj.minSwaps("]]][[[");
}