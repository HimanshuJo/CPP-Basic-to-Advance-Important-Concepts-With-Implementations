/*

Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:

    All inputs will be in lowercase.
    The order of your output does not matter.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> res;
        int index = 0;
        for (string str : strs) {
            string cpStr = str;
            sort(str.begin(), str.end());
            if (map.find(str) == map.end()) {
                vector<string> temp;
                temp.push_back(cpStr);
                map[str] = temp;
            } else {
                map[str].push_back(cpStr);
            }
            index++;
        }
        for (auto &entry : map) {
            vector<string> temp;
            //cout << entry.first << " ";
            for (auto &vals : entry.second) {
                cout << vals << " ";
                temp.push_back(vals);
            }
            res.push_back(temp);
            cout << "\n";
        }
        return res;
    }
};

int main() {
    Solution obj;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    obj.groupAnagrams(strs);
}