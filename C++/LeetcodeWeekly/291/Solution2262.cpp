// 2262. Total Appeal of A String
/*
The appeal of a string is the number of distinct characters found in the string.

For example, the appeal of "abbca" is 3 because it has 3 distinct characters: 'a', 'b', and 'c'.

Given a string s, return the total appeal of all of its substrings.

A substring is a contiguous sequence of characters within a string.

Example 1:

Input: s = "abbca"
Output: 28
Explanation: The following are the substrings of "abbca":
- Substrings of length 1: "a", "b", "b", "c", "a" have an appeal of 1, 1, 1, 1, and 1 respectively. The sum is 5.
- Substrings of length 2: "ab", "bb", "bc", "ca" have an appeal of 2, 1, 2, and 2 respectively. The sum is 7.
- Substrings of length 3: "abb", "bbc", "bca" have an appeal of 2, 2, and 3 respectively. The sum is 7.
- Substrings of length 4: "abbc", "bbca" have an appeal of 3 and 3 respectively. The sum is 6.
- Substrings of length 5: "abbca" has an appeal of 3. The sum is 3.
The total sum is 5 + 7 + 7 + 6 + 3 = 28.

Example 2:

Input: s = "code"
Output: 20
Explanation: The following are the substrings of "code":
- Substrings of length 1: "c", "o", "d", "e" have an appeal of 1, 1, 1, and 1 respectively. The sum is 4.
- Substrings of length 2: "co", "od", "de" have an appeal of 2, 2, and 2 respectively. The sum is 6.
- Substrings of length 3: "cod", "ode" have an appeal of 3 and 3 respectively. The sum is 6.
- Substrings of length 4: "code" has an appeal of 4. The sum is 4.
The total sum is 4 + 6 + 6 + 4 = 20.
 

Constraints:

1 <= s.length <= 10^5
s consists of lowercase English letters.
*/

/*
TLE:

class Solution {
public:
    
    long long returnDistinctChars(string &temp){
        unordered_map<char, int>mp;
        for(char ch: temp){
            mp[ch]++;
        }
        return mp.size();
    }
    
    long long appealSum(string s) {
        long long ans=s.length();
        int len=s.length();
        for(int i=0; i<len; ++i){
            string temp="";
            temp+=s[i];
            if(i+1<=len-1){
                for(int j=i+1; j<len; ++j){
                    temp+=s[j];
                    long long count=returnDistinctChars(temp);
                    ans+=count;
                }
            }
        }
        return ans;
    }
};
*/

/*
Explanation:
	
	assume we have string xxxaxxxxb..., with s[i] = a and s[j] = b.
	
	s[i] is th last character a before that b.

	We want to count, how many substring ending at s[j] contains character a.
	
	They are xxxaxxxxb, xxaxxxxb, xaxxxxb, axxxxb ....,
	i + 1 substring ending with character a at s[i],
	
	so we do res += i + 1.

-------

	We repeatly do this for every s[i] and every one of 26 characters.

-------

Complexity
	
	Time O(n)
	
	Space O(26)
*/

class Solution {
public:
    long long appealSum(string s) {
        vector<int>last(26);
        long long res=0;
        int sz=s.size();
        for(int i=0; i<sz; ++i){
            last[s[i]-'a']=i+1;
            for(auto &vals: last){
                res+=vals;
            }
        }
        return res;
    }
};