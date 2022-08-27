// 1960. Maximum Product of the Length of Two Palindromic Substrings
/*
You are given a 0-indexed string s and are tasked with finding two non-intersecting palindromic substrings of odd 
length such that the product of their lengths is maximized.

More formally, you want to choose four integers i, j, k, l such that 0 <= i <= j < k <= l < s.length and 
both the substrings s[i...j] and s[k...l] are palindromes and have odd lengths. s[i...j] denotes 
a substring from index i to index j inclusive.

Return the maximum possible product of the lengths of the two non-intersecting palindromic substrings.

A palindrome is a string that is the same forward and backward. 
A substring is a contiguous sequence of characters in a string.

Example 1:

Input: s = "ababbb"
Output: 9
Explanation: Substrings "aba" and "bbb" are palindromes with odd length. product = 3 * 3 = 9.
Example 2:

Input: s = "zaaaxbbby"
Output: 9
Explanation: Substrings "aaa" and "bbb" are palindromes with odd length. product = 3 * 3 = 9.
*/
/*
Finding the longest palindrome in [i, j] is trivial using quadratic DP.

Then, we can just find the biggest product of [0, i] * [i + 1, n), moving the split point i left-to-right. 
However, quadratic would be too slow for n = 100,000.

Manacher's algorithm can identify all palindromes in O(n). 
It has two flavors for finding odd and even palindromes. 
Fortunately, we only care about odd palindromes here, which is the simpler case.

For each position as the center of the palindrome, the algorithm finds how far the palindrome extends
*/


class Solution {
public:
    
    void manacharAlgo(vector<int>&palRadi, string s){
        int sz=s.size();
        s="$"+s+"^";
        int leftB=1, rightB=1;
        for(int i=1; i<=sz; ++i){
            palRadi[i]=max(0, min(rightB-i, palRadi[leftB+(rightB-i)]));
            while(s[i-palRadi[i]]==s[i+palRadi[i]]){
                palRadi[i]++;
            }
            if(i+palRadi[i]>rightB){
                rightB=i+palRadi[i];
                leftB=i-palRadi[i];
            }
        }
        for(int i=1; i<=sz; ++i){
            palRadi[i]--;
        }
        auto it=palRadi.begin();
        palRadi.erase(it);
        int sz_=palRadi.size();
        auto it_=palRadi.begin()+sz_-1;
        palRadi.erase(it_);
    }
    
    long long maxProduct(string s) {
        int sz=s.length();
        vector<int>palRadi(sz+2, 0), lpIdx(sz, 0);
        manacharAlgo(palRadi, s);
        lpIdx[0]=1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        for(int i=1; i<=sz-1; ++i){
            if(palRadi[i]>0){
                pq.push({i, palRadi[i]});
                lpIdx[i]=1;
            }
            if(!pq.empty()){
                while(!pq.empty()&&pq.top().first+pq.top().second<i){
                    pq.pop();
                }
                if(!pq.empty()){
                    lpIdx[i]=2*(i-pq.top().first)+1;
                } else{
                    lpIdx[i]=1;
                }
            }
            lpIdx[i]=max(lpIdx[i], lpIdx[i-1]);
        }
        priority_queue<pair<int, int>>pql;
        int m=1, l=1;
        long long ans=0;
        ans=max(ans, 1LL*lpIdx[sz-2]*m);
        for(int i=sz-2; i>=0; --i){
            if(palRadi[i]>0){
                pql.push({i, palRadi[i]});
                l=1;
            }
            if(!pql.empty()){
                while(!pql.empty()&&pql.top().first-pql.top().second>i){
                    pql.pop();
                }
                if(!pql.empty()){
                    l=2*(pql.top().first-i)+1;
                } else l=1;
            }
            m=max(m, l);
            if(i>0){
                ans=max(ans, 1LL*lpIdx[i-1]*m);
            }
        }
        return ans;
    }
};