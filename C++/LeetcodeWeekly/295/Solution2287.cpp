// 2287. Rearrange Characters to Make Target String
/*
You are given two 0-indexed strings s and target. You can take some letters from s and rearrange 
them to form new strings.

Return the maximum number of copies of target that can be formed by taking letters from s and rearranging them.

Example 1:

Input: s = "ilovecodingonleetcode", target = "code"
Output: 2
Explanation:
For the first copy of "code", take the letters at indices 4, 5, 6, and 7.
For the second copy of "code", take the letters at indices 17, 18, 19, and 20.
The strings that are formed are "ecod" and "code" which can both be rearranged into "code".
We can make at most two copies of "code", so we return 2.
Example 2:

Input: s = "abcba", target = "abc"
Output: 1
Explanation:
We can make one copy of "abc" by taking the letters at indices 0, 1, and 2.
We can make at most one copy of "abc", so we return 1.
Note that while there is an extra 'a' and 'b' at indices 3 and 4, we cannot reuse the letter 'c' at index 2, 
so we cannot make a second copy of "abc".
Example 3:

Input: s = "abbaccaddaeea", target = "aaaaa"
Output: 1
Explanation:
We can make one copy of "aaaaa" by taking the letters at indices 0, 3, 6, 9, and 12.
We can make at most one copy of "aaaaa", so we return 1.
 

Constraints:

1 <= s.length <= 100
1 <= target.length <= 10
s and target consist of lowercase English letters.
*/

// TC: O(m*log(k))  m: target length, n: s length, k: map size
// SC: O(n+m)
class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int>mp1, mp2;
        for(char ch: s){
            mp1[ch]++;
        }
        for(char ch: target){
            mp2[ch]++;
        }
        int ans=INT_MAX;
        for(auto &entries: mp2){
            if(mp1.find(entries.first)==mp1.end()){
                return 0;
            }
            ans=min(ans, mp1[entries.first]/entries.second);
        }
        return ans;
    }
};

// TC: <=O(n*n)  m: target length, n: s length
// SC: O(n+m)
class Solution2 {
public:
    int rearrangeCharacters(string s, string target) {
        int len=s.length();
        int len2=target.length();
        string temp="";
        int j=0;
        int i;
        int ans=0;
        vector<int>seen(len, 0);
        for(i=0; i<len; ++i){
            if(s[i]==target[j]&&seen[i]!=1){
                temp+=s[i];
                seen[i]=1;
                i=-1;
                j++;
            }
            if(temp==target){
                ans++;
                temp="";
                j=0;
            }
        }
        return ans;
    }
};

// TC: <=max(O(n*n*n), O(n^2*m))  n: s length, m: target length
// SC: O(m)
class Solution3 {
public:
    int rearrangeCharacters(string s, string target) {
        int len=s.length();
        int len2=target.length();
        string temp="";
        int j=0;
        int i;
        int ans=0;
        for(i=0; i<len; ++i){
            if(s[i]==target[j]){
                temp+=s[i];
                s.erase(s.begin()+i);
                len=s.length();
                i=-1;
                j++;
            }
            if(j==len2) j=0;
            if(temp==target){
                ans++;
                temp="";
            }
        }
        return ans;
    }
};