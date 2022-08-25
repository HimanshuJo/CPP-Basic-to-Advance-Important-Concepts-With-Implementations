// 2384. Largest Palindromic Number
/*
You are given a string num consisting of digits only.

Return the largest palindromic integer (in the form of a string) that can be formed using digits 
taken from num. It should not contain leading zeroes.

Notes:

You do not need to use all the digits of num, but you must use at least one digit.
The digits can be reordered.
 

Example 1:

Input: num = "444947137"
Output: "7449447"
Explanation: 
Use the digits "4449477" from "444947137" to form the palindromic integer "7449447".
It can be shown that "7449447" is the largest palindromic integer that can be formed.
Example 2:

Input: num = "00009"
Output: "9"
Explanation: 
It can be shown that "9" is the largest palindromic integer that can be formed.
Note that the integer returned should not contain leading zeroes.

Constraints:

1 <= num.length <= 10^5
num consists of digits.
*/

class Solution1 {
public:
    string largestPalindromic(string num) {
        unordered_map<int, int>mp;
        for(auto &ch: num){
            mp[ch-'0']++;
        }
        string resl="", resr="";
        for(auto &ch: num){
            for(int i=9; i>=0; --i){
                if(mp[i]>1){
                    if(i==0&&resl=="") continue;
                    resl+=i+'0';
                    resr+=i+'0';
                    mp[i]-=2;
                    break;
                }
            }
        }
        for(int i=9; i>=0; --i){
            if(mp[i]==1){
                resl+=i+'0';
                break;
            }
        }
        reverse(resr.begin(), resr.end());
        return (resl+resr)==""?"0":resl+resr;
    }
};

// -------*******-------

class Solution {
public:
    string largestPalindromic(string num) {
        if(num.size()==1) return num;
        int sz=num.size();
        map<int, int, greater<>>mp;
        for(auto &ch: num){
            mp[ch-'0']++;
        }
        vector<int>ans(sz, -1);
        int curbegin=0, curend=sz-1;
        int mid=-1;
        bool flag=false;
        vector<int>extr;
        for(auto &entries: mp){
            int count=entries.second;
            if(count%2!=0&&!flag&&entries.first!=0){
                mid=entries.first;
                count--;
                flag=true;
                while(count){
                    extr.push_back(mid);
                    count--;
                    if(count==0) break;
                }
                continue;
            }
            if(count%2==0){
                while(count){
                    ans[curbegin++]=entries.first;
                    count--;
                    if(count==0) break;
                    ans[curend--]=entries.first;
                    count--;
                }
            } else{
                vector<int>tmp=ans;
                tmp.erase(remove(tmp.begin(), tmp.end(), -1), tmp.end());
                if((mp.size()>2&&curbegin!=tmp.size()/2)||mid!=-1){
                    while(count>0&&count%2!=0){
                        count--;
                    }   
                }
                while(count){
                    ans[curbegin++]=entries.first;
                    count--;
                    if(count==0) break;
                    ans[curend--]=entries.first;
                    count--;
                }
            }
            if(mid==-1&&entries.second==1){
                mid=entries.first;
            }
        }
        for(int i=0; i<sz/2; ++i){
            if(ans[i]==0){
                ans[i]=-1;
            } else break;
        }
        for(int i=sz-1; i>sz/2; --i){
            if(ans[i]==0){
                ans[i]=-1;
            } else break;
        }
        ans.erase(remove(ans.begin(), ans.end(), -1), ans.end());
        string res="";
        auto it=ans.begin()+ans.size()/2;
        ans.insert(it, mid);
        if(extr.size()!=0){
            int sz__=extr.size();
            auto it=ans.begin();
            auto it2=ans.begin()+ans.size();
            int valtochk1=*it;
            if(valtochk1<=mid){
                while(sz__){
                    it=ans.begin();
                    ans.insert(it, mid);
                    sz__--;
                    if(sz__==0) break;
                    it2=ans.begin()+ans.size();
                    ans.insert(it2, mid);
                    sz__--;
                }   
            } else{
                while(valtochk1>mid){
                    it++;
                    valtochk1=*it;
                }
                while(sz__){
                    ans.insert(it, mid);
                    sz__--;
                    if(sz__==0) break;
                    it2=ans.begin()+ans.size()-1;
                    int valtochk2=*it2;
                    while(valtochk2>mid){
                        it2--;
                        valtochk2=*it2;
                    }
                    it2++;
                    ans.insert(it2, mid);
                    sz__--;
                }   
            }
        }
        for(auto &vals: ans){
            if(vals!=-1)
                res+=to_string(vals);
        }
        return res==""?"0":res;
    }
};