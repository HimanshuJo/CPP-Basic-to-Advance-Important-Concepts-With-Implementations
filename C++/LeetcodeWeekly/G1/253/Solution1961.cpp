// 1961. Check If String Is a Prefix of Array
/*
Given a string s and an array of strings words, determine whether s is a prefix string of words.

A string s is a prefix string of words if s can be made by concatenating the first k strings in 
words for some positive k no larger than words.length.

Return true if s is a prefix string of words, or false otherwise.

Example 1:

Input: s = "iloveleetcode", words = ["i","love","leetcode","apples"]
Output: true
Explanation:
s can be made by concatenating "i", "love", and "leetcode" together.
Example 2:

Input: s = "iloveleetcode", words = ["apples","i","love","leetcode"]
Output: false
Explanation:
It is impossible to make s using a prefix of arr.
*/

class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        bool flag=false;
        int j=0;
        string toCheck="";
        for (string str: words){
            toCheck+=str;
        }
        if (toCheck.length()<s.length()){
            return false;
        }
        for (int i=0; i<words.size(); ++i){
            string toCheck=words[i];
            int len=toCheck.length();
            if (len>s.length()-j){
                return false;
            }
            for (int i=0; i<len; ++i){
                if (s.at(j)!=toCheck.at(i)){
                    return false;
                }
                if (j==s.length()-1){
                    flag=true;
                    break;
                }
                ++j;
            }
            if (flag){
                break;
            }
        }
        return true;
    }
};

// -------*******-------

class Solution2{
    public:
    bool isPrefixString(string s, vector<string>& words) {
        int i = 0;
        for (int j = 0; j < words.size() && i < s.size(); ++j)
            for (auto ch : words[j])
                if (i == s.size() || s[i++] != ch){
                    cout<<"false";
                    return false;
                }
        return i == s.size();
    }
};