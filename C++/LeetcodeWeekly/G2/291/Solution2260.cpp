// 2260. Minimum Consecutive Cards to Pick Up
/*
You are given an integer array cards where cards[i] represents the value of the ith card. 
A pair of cards are matching if the cards have the same value.

Return the minimum number of consecutive cards you have to pick up to have a pair of 
matching cards among the picked cards. If it is impossible to have matching cards, return -1.

 

Example 1:

Input: cards = [3,4,2,3,4,7]
Output: 4
Explanation: We can pick up the cards [3,4,2,3] which contain a matching pair of 
cards with value 3. Note that picking up the cards [4,2,3,4] is also optimal.
Example 2:

Input: cards = [1,0,5,3]
Output: -1
Explanation: There is no way to pick up a set of consecutive cards that contain a pair of matching cards.
 

Constraints:

1 <= cards.length <= 10^5
0 <= cards[i] <= 10^6
*/

class Solution {
public:
    
    int minimumCardPickup(vector<int>& cards) {
        int res=INT_MAX;
        int sz=cards.size();
        bool flag=false;
        map<int, vector<int>>mp;
        vector<int>indexes;
        for(int i=0; i<sz; ++i){
            mp[cards[i]].push_back(i);
        }
        for(auto &entries: mp){
            if(entries.second.size()>=2){
                flag=true;
                sort(entries.second.begin(), entries.second.end());
                int curmin=INT_MAX;
                int sz_=entries.second.size();
                for(int i=0; i<sz_-1; ++i){
                    curmin=min(curmin, abs(entries.second[i]-entries.second[i+1]));
                    res=min(res, curmin);
                }
            }
        }
        return flag?res+1:-1;
    }
};