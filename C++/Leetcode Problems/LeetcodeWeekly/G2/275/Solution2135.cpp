// 2135. Count Words Obtained After Adding a Letter
/*
You are given two 0-indexed arrays of strings startWords and targetWords.
Each string consists of lowercase English letters only.

For each string in targetWords, check if it is possible to choose a string from
startWords and perform a conversion operation on it to be equal to that from targetWords.

The conversion operation is described in the following two steps:

Append any lowercase letter that is not present in the string to its end.
For example, if the string is "abc", the letters 'd', 'e', or 'y' can be added to it,
but not 'a'. If 'd' is added, the resulting string will be "abcd".

Rearrange the letters of the new string in any arbitrary order.
For example, "abcd" can be rearranged to "acbd", "bacd", "cbda", and so on.

Note that it can also be rearranged to "abcd" itself.
Return the number of strings in targetWords that can be obtained by performing the
operations on any string of startWords.

Note that you will only be verifying if the string in targetWords can be obtained
from a string in startWords by performing the operations.

The strings in startWords do not actually change during this process.

Example 1:

Input: startWords = ["ant","act","tack"], targetWords = ["tack","act","acti"]
Output: 2
Explanation:
- In order to form targetWords[0] = "tack", we use startWords[1] = "act", append 'k' to it, and rearrange "actk" to "tack".
- There is no string in startWords that can be used to obtain targetWords[1] = "act".
  Note that "act" does exist in startWords, but we must append one letter to the string before rearranging it.
- In order to form targetWords[2] = "acti", we use startWords[1] = "act", append 'i' to it, and rearrange "acti" to "acti" itself.
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*
Brute Force:

class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        int res=0;
        for(auto &vals: targetWords){
            bool flag=false;
            int n=vals.length();
            for(auto &words: startWords){
                if(words.size()==n-1){
                    int count=0;
                    map<char, int>mp1;
                    map<char, int>mp2;
                    for(char ch: vals){
                        mp1[ch]++;
                    }
                    for(char ch: words){
                        mp2[ch]++;
                    }
                    for(auto &entry: mp1){
                        if(mp2.find(entry.first)!=mp2.end()){
                            count+=mp2[entry.first];
                        }
                    }
                    if(count==n-1){
                        flag=true;
                        res++;
                        break;
                    }
                }
            }
        }
        return res;
    }
};

*/

class Trie
{
    bool last;
    Trie *child[26];

public:
    Trie()
    {
        for (int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
        last = false;
    }

    void insert(string &s)
    {
        auto tmp = this;
        for (auto c : s)
        {
            if (!tmp->child[c - 'a'])
            {
                tmp->child[c - 'a'] = new Trie();
            }
            tmp = tmp->child[c - 'a'];
        }
        tmp->last = true;
    }

    bool check(string &s)
    {
        auto tmp = this;
        for (auto c : s)
        {
            if (!tmp->child[c - 'a'])
            {
                return false;
            }
            tmp = tmp->child[c - 'a'];
        }
        return tmp->last;
    }
};

class Solution
{
public:
    int wordCount(vector<string> &startWords, vector<string> &targetWords)
    {
        Trie t;

        for (auto s : startWords)
        {
            sort(s.begin(), s.end());
            t.insert(s);
        }

        int count = 0;
        for (auto s : targetWords)
        {
            sort(s.begin(), s.end());
            // remove one character and check if the remaining string is in Trie
            for (int i = 0; i < s.size(); i++)
            {
                string s1 = s.substr(0, i) + s.substr(i + 1);
                if (t.check(s1))
                {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};