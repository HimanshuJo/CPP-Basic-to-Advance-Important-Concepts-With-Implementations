// 1209. Remove All Adjacent Duplicates in String II
/*
You are given a string s and an integer k, a k duplicate removal consists of choosing 
k adjacent and equal letters from s and removing them, causing the left and 
the right side of the deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. 

It is guaranteed that the answer is unique.

Example 1:

Input: s = "abcd", k = 2
Output: "abcd"
Explanation: There's nothing to delete.
Example 2:

Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation: 
First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"
Example 3:

Input: s = "pbbcggttciiippooaais", k = 2
Output: "ps"
 

Constraints:

1 <= s.length <= 10^5
2 <= k <= 10^4
s only contains lower case English letters.
*/

/*
TLE:

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<char>st;
        int sz=s.size();
        int i=0;
        while(i<=sz-1){
            st.push(s[i]);
            if(st.size()>=k){
                int cnt=0;
                vector<char>temp;
                char frst=st.top();
                temp.push_back(frst);
                cnt++;
                st.pop();
                bool flag=false;
                while(!st.empty()||cnt!=k){
                    char nxt=st.top();
                    temp.push_back(nxt);
                    if(nxt==frst){
                        cnt++;
                        st.pop();
                    } else{
                        flag=true;
                        break;
                    }
                }
                if(flag&&cnt!=k){
                    temp.pop_back();
                    reverse(temp.begin(), temp.end());
                    for(auto &vals: temp){
                        st.push(vals);
                    }
                }
            }
            ++i;
        }
        string res="";
        while(!st.empty()){
            char curr=st.top();
            res+=curr;
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
*/

/*
TLE:

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<char>st;
        int sz=s.size();
        int i=0;
        while(i<=sz-1){
            st.push(s[i]);
            if(st.size()>=k){
                stack<char>tempSt=st;
                int cnt=0;
                char frst=st.top();
                cnt++;
                st.pop();
                bool flag=false;
                while(!st.empty()||cnt!=k){
                    char nxt=st.top();
                    if(nxt==frst){
                        cnt++;
                        st.pop();
                    } else{
                        flag=true;
                        break;
                    }
                }
                if(flag&&cnt!=k){
                    st=tempSt;
                }
            }
            ++i;
        }
        string res="";
        while(!st.empty()){
            char curr=st.top();
            res+=curr;
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
*/
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<int, int>>st;
        int n=s.size(), i=0;
        while(i<n){
            if(!st.empty()){
                if(s[st.top().first]==s[i]){
                    if(st.top().second+1==k){
                        int temp=k-1;
                        while(temp--){
                            st.pop();
                        }
                    } else{
                        st.push({i, st.top().second+1});
                    }
                } else{
                    st.push({i, 1});
                }
            } else{
                st.push({i, 1});
            }
            ++i;
        }
        string res="";
        while(!st.empty()){
            char curr=s[st.top().first];
            res+=curr;
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};