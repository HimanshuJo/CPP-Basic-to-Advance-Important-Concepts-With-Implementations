// 2007. Find Original Array From Doubled Array
/*
An integer array original is transformed into a doubled array changed by appending twice 
the value of every element in original, and then randomly shuffling the resulting array.

Given an array changed, return original if changed is a doubled array. If changed is 
not a doubled array, return an empty array. The elements in original may be returned in any order.

Example 1:

Input: changed = [1,3,4,2,6,8]
Output: [1,3,4]
Explanation: One possible original array could be [1,3,4]:
- Twice the value of 1 is 1 * 2 = 2.
- Twice the value of 3 is 3 * 2 = 6.
- Twice the value of 4 is 4 * 2 = 8.
Other original arrays could be [4,3,1] or [3,1,4].
Example 2:

Input: changed = [6,3,0,1]
Output: []
Explanation: changed is not a doubled array.
Example 3:

Input: changed = [1]
Output: []
Explanation: changed is not a doubled array.
 

Constraints:

1 <= changed.length <= 10^5
0 <= changed[i] <= 10^5
*/

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int sz=changed.size();
        if(sz%2!=0) return {};
        vector<int>res;
        sort(changed.begin(), changed.end());
        if(changed[0]==changed[sz-1]&&changed[0]==0){
            for(int i=0; i<sz/2; ++i){
                res.push_back(0);
            }
            return res;
        }
        unordered_map<int, vector<int>>mp;
        for(int i=0; i<sz; ++i){
            mp[changed[i]].push_back(i);
        }
        if(mp.find(0)!=mp.end()){
            if(mp[0].size()%2==0){
                for(int i=0; i<mp[0].size()/2; ++i){
                    res.push_back(0);
                }
            }
        }
        vector<int>seen(sz, -1);
        for(int i=0; i<sz; ++i){
            if(changed[i]!=0&&changed[i]%2==0){
                int nmtochk=changed[i]/2;
                auto it=mp.find(nmtochk);
                if(it!=mp.end()){
                    vector<int>temp=mp[nmtochk];
                    for(auto &x: temp){
                        if(seen[x]==-1&&seen[i]==-1&&x<i){
                            seen[x]=1;
                            seen[i]=1;
                            res.push_back(changed[i]/2);
                            if(res.size()==sz/2) return res;
                            break;
                        }
                    }
                }
            }
        }
        return {};
    }
};