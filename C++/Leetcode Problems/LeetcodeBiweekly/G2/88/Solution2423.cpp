// 2423. Remove Letter To Equalize Frequency
/*
You are given a 0-indexed string word, consisting of lowercase English letters. 
You need to select one index and remove the letter at that index from word so that the frequency of 
every letter present in word is equal.

Return true if it is possible to remove one letter so that the frequency of all letters in 
word are equal, and false otherwise.

Note:

The frequency of a letter x is the number of times it occurs in the string.
You must remove exactly one letter and cannot chose to do nothing.
 

Example 1:

Input: word = "abcc"
Output: true
Explanation: Select index 3 and delete it: word becomes "abc" and each character has a frequency of 1.
Example 2:

Input: word = "aazz"
Output: false
Explanation: We must delete a character, so either the frequency of "a" is 1 and the frequency of "z" is 2, 
or vice versa. It is impossible to make all present letters have equal frequency.
 

Constraints:

2 <= word.length <= 100
word consists of lowercase English letters only.
*/

class Solution {
public:
    bool equalFrequency(string word) {
        set<char>gvn;
        for(char &ch: word){
            gvn.insert(ch);
        }
        if(gvn.size()==1) return true;
        unordered_map<char, int>mp_;
        for(auto &chrs: word){
            mp_[chrs]++;
        }
        int bgn_=-1;
        bool flag_=false;
        for(auto &entries: mp_){
            if(bgn_==-1){
                bgn_=entries.second;
            } else{
                if(entries.second!=bgn_){
                    flag_=true;
                    break;
                }
            }
        }
        if(!flag_){
            if(bgn_!=1) return false;
        }
        int sz=gvn.size();
        for(int i=0; i<sz; ++i){
            string temp=word;
            auto it=gvn.begin();
            char tochk=*it;
            gvn.erase(it);
            int sz__=temp.size();
            int idxtoremove;
            for(int ii=0; ii<sz__; ++ii){
                if(temp[ii]==tochk){
                    idxtoremove=ii;
                    break;
                }
            }
            auto itr=temp.begin()+idxtoremove;
            temp.erase(itr);
            unordered_map<char, int>mp;
            for(auto &chrs: temp){
                mp[chrs]++;
            }
            int bgn=-1;
            bool flag=false;
            for(auto &entries: mp){
                if(bgn==-1){
                    bgn=entries.second;
                } else{
                    if(entries.second!=bgn){
                        flag=true;
                        break;
                    }
                }
            }
            if(!flag) return true;
        }
        return false;
    }
};