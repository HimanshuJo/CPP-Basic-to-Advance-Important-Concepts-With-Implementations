class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        unordered_map<char, int>mp1;
        unordered_map<char, int>mp2;
        for(char ch: word1){
            mp1[ch]++;
        }
        for(char ch: word2){
            mp2[ch]++;
        }
        for(auto &entry: mp1){
            char ch=entry.first;
            int val=entry.second;
            int toChk=mp2[ch];
            if(abs(val-toChk)>3){
                return false;
            }
        }
        for(auto &entry: mp2){
            char ch=entry.first;
            int val=entry.second;
            int toChk=mp1[ch];
            if(abs(val-toChk)>3){
                return false;
            }
        }
        return true;
    }
};