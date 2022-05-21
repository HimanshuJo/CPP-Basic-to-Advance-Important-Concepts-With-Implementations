// 2063. Vowels of All Substrings
/*
Given a string word, return the sum of the number of vowels 
('a', 'e', 'i', 'o', and 'u') in every substring of word.

A substring is a contiguous (non-empty) sequence of characters within a string.

Note: Due to the large constraints, the answer may not fit in a signed 32-bit integer. 
Please be careful during the calculations.

Example 1:

Input: word = "aba"
Output: 6
Explanation: 
All possible substrings are: "a", "ab", "aba", "b", "ba", and "a".
- "b" has 0 vowels in it
- "a", "ab", "ba", and "a" have 1 vowel each
- "aba" has 2 vowels in it
Hence, the total sum of vowels = 0 + 1 + 1 + 1 + 1 + 2 = 6. 
Example 2:

Input: word = "abc"
Output: 3
Explanation: 
All possible substrings are: "a", "ab", "abc", "b", "bc", and "c".
- "a", "ab", and "abc" have 1 vowel each
- "b", "bc", and "c" have 0 vowels each
Hence, the total sum of vowels = 1 + 1 + 1 + 0 + 0 + 0 = 3.
Example 3:

Input: word = "ltcd"
Output: 0
Explanation: There are no vowels in any substring of "ltcd".
 

Constraints:

1 <= word.length <= 10^5
word consists of lowercase English letters.

*/

/*
Solution:

For each vowels s[i],
it could be in the substring starting at s[x] and ending at s[y],

where 0 <= x <= i and i <= y < n,
that is (i + 1) choices for x and (n - i) choices for y.

So there are (i + 1) * (n - i) substrings containing s[i].

-------

Complexity
	Time O(n)
	Space O(1)

-------

long long countVowels(string s) {
    long res = 0, n = s.size();
    for (int i = 0; i < n; ++i)
        if (string("aeiou").find(s[i]) != string::npos)
            res += (i + 1) * (n - i);
    return res;
}
*/

class Solution {
	public:
		long long countVowels(string word) {
			long long cnt=0;
			long long n=word.length();
			unordered_map<char, char>mp;
			mp['a']='a';
			mp['e']='e';
			mp['i']='i';
			mp['o']='o';
			mp['u']='u';
			for(int i=0; i<word.length(); ++i){
				auto it=mp.find(word[i]);
				if(it!=mp.end()){
					cnt+=(n-i)*(i+1);
				}
			}
			return cnt;
		}
};
