// 2053. Kth Distinct String in an Array
/*
A distinct string is a string that is present only once in an array.

Given an array of strings arr, and an integer k, return the kth distinct string present in arr. 

If there are fewer than k distinct strings, return an empty string "".

Note that the strings are considered in the order in which they appear in the array.

Example 1:

Input: arr = ["d","b","c","b","c","a"], k = 2
Output: "a"
Explanation:
The only distinct strings in arr are "d" and "a".
"d" appears 1st, so it is the 1st distinct string.
"a" appears 2nd, so it is the 2nd distinct string.
Since k == 2, "a" is returned. 
Example 2:

Input: arr = ["aaa","aa","a"], k = 1
Output: "aaa"
Explanation:
All strings in arr are distinct, so the 1st string "aaa" is returned.
Example 3:

Input: arr = ["a","b","a"], k = 3
Output: ""
Explanation:
The only distinct string is "b". Since there are fewer than 3 distinct strings, we return an empty string "".
 

Constraints:

1 <= k <= arr.length <= 1000
1 <= arr[i].length <= 5
arr[i] consists of lowercase English letters.
*/

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int>mp;
        for(string str: arr){
            mp[str]++;
        }
        vector<string>res;
        for(string str: arr){
            int currCnt=mp[str];
            if(currCnt==1){
                res.push_back(str);
            }
        }
        if(res.size()<k) return "";
        else return res[k-1];
    }
};

// -------*******-------

class Solution2 {
public:
    string kthDistinct(vector<string>& arr, int k) {
        vector<string>res;
        int sz=arr.size();
        for(int i=0; i<sz; ++i){
            string curr=arr[i];
            arr[i]="";
            auto it=find(arr.begin(), arr.end(), curr);
            if(it==arr.end()){
                res.push_back(curr);
            }
            arr[i]=curr;
        }
        if(res.size()<k) return "";
        return res[k-1];
    }
};