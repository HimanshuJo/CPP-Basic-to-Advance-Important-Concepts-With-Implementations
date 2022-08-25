// 2306. Naming a Company
/*
You are given an array of strings ideas that represents a list of names to 
be used in the process of naming a company. 

The process of naming a company is as follows:

Choose 2 distinct names from ideas, call them ideaA and ideaB.
Swap the first letters of ideaA and ideaB with each other.
If both of the new names are not found in the original ideas, 
then the name ideaA ideaB (the concatenation of ideaA and ideaB, separated by a space) 
is a valid company name.

Otherwise, it is not a valid name.
Return the number of distinct valid names for the company.

Example 1:

Input: ideas = ["coffee","donuts","time","toffee"]
Output: 6
Explanation: The following selections are valid:
- ("coffee", "donuts"): The company name created is "doffee conuts".
- ("donuts", "coffee"): The company name created is "conuts doffee".
- ("donuts", "time"): The company name created is "tonuts dime".
- ("donuts", "toffee"): The company name created is "tonuts doffee".
- ("time", "donuts"): The company name created is "dime tonuts".
- ("toffee", "donuts"): The company name created is "doffee tonuts".
Therefore, there are a total of 6 distinct company names.

The following are some examples of invalid selections:
- ("coffee", "time"): The name "toffee" formed after swapping already exists in the original array.
- ("time", "toffee"): Both names are still the same after swapping and exist in the original array.
- ("coffee", "toffee"): Both names formed after swapping already exist in the original array.
Example 2:

Input: ideas = ["lack","back"]
Output: 0
Explanation: There are no valid selections. Therefore, 0 is returned.
 

Constraints:

2 <= ideas.length <= 5 * 10^4
1 <= ideas[i].length <= 10
ideas[i] consists of lowercase English letters.
All the strings in ideas are unique.
*/

/*
TLE: 74 / 89

class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        int sz=ideas.size();
        unordered_map<string, string>mp;
        for(auto &vals: ideas){
            mp[vals]=vals;
        }
        long long ans=0;
        for(int i=0; i<sz; ++i){
            if(i+1<=sz-1){
                string curr=ideas[i];
                for(int j=i+1; j<sz; ++j){
                    string nxt=ideas[j];
                    string temp1="", temp2="";
                    temp1+=curr[0];
                    temp2+=nxt[0];
                    if(nxt.length()>=1){
                        for(int x=1; x<nxt.length(); ++x){
                            temp1+=nxt[x];
                        }   
                    }
                    if(curr.length()>=1){
                        for(int x=1; x<curr.length(); ++x){
                            temp2+=curr[x];
                        }   
                    }
                    if(mp.find(temp1)==mp.end()&&mp.find(temp2)==mp.end()){
                        ans++;
                    }
                }
            }
        }
        return ans*2;
    }
};
*/

// TC: (25*25*n)  n: ideas length
class Solution1 {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<unordered_set<string>>suffix(26);
        long long res=0;
        for(auto &idea: ideas){
            suffix[idea[0]-'a'].insert(idea.substr(1));
        }
        for(int i=0; i<25; ++i){
            for(int j=i+1; j<26; ++j){
                auto &setA=suffix[i];
                auto &setB=suffix[j];
                int intersect=0;
                for(auto &item: setA){
                    intersect+=setB.count(item);
                }
                res+=2*(setA.size()-intersect)*(setB.size()-intersect);
            }
        }
        return res;
    }
};

// -------*******-------

class Solution2 {
public:
    long long distinctNames(vector<string>& ideas) {
        long long res=0;
        long long cnt[26][26]={};
        unordered_set<string>st[26];
        for(auto &idea: ideas){
            st[idea[0]-'a'].insert(idea.substr(1));
        }
        for(int i=0; i<26; ++i){
            for(auto &stuff: st[i]){
                for(int j=0; j<26; ++j){
                    cnt[i][j]+=st[j].count(stuff)==0;
                }
            }
        }
        for(int i=0; i<26; ++i){
            for(int j=0; j<26; ++j){
                res+=cnt[i][j]*cnt[j][i];
            }
        }
        return res;
    }
};