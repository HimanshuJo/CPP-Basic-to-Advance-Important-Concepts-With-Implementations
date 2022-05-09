// 2213. Longest Substring of One Repeating Character
/*
You are given a 0-indexed string s. You are also given a 0-indexed string queryCharacters of length 
k and a 0-indexed array of integer indices queryIndices of length k, both of which are used to describe k queries.

The ith query updates the character in s at index queryIndices[i] to the character queryCharacters[i].

Return an array lengths of length k where lengths[i] is the length of the longest substring of s 
consisting of only one repeating character after the ith query is performed.

Example 1:

Input: s = "babacc", queryCharacters = "bcb", queryIndices = [1,3,3]
Output: [3,3,4]
Explanation: 
- 1st query updates s = "bbbacc". The longest substring consisting of one repeating character is "bbb" with length 3.
- 2nd query updates s = "bbbccc". 
  The longest substring consisting of one repeating character can be "bbb" or "ccc" with length 3.
- 3rd query updates s = "bbbbcc". The longest substring consisting of one repeating character is "bbbb" with length 4.
Thus, we return [3,3,4].
Example 2:

Input: s = "abyzz", queryCharacters = "aa", queryIndices = [2,1]
Output: [2,3]
Explanation:
- 1st query updates s = "abazz". The longest substring consisting of one repeating character is "zz" with length 2.
- 2nd query updates s = "aaazz". The longest substring consisting of one repeating character is "aaa" with length 3.
Thus, we return [2,3].
 

Constraints:

1 <= s.length <= 10^5
s consists of lowercase English letters.
k == queryCharacters.length == queryIndices.length
1 <= k <= 10^5
queryCharacters consists of lowercase English letters.
0 <= queryIndices[i] < s.length
*/

/*
TLE:

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        string res=s;
        int sz=s.length();
        int qsz=queryIndices.size();
        vector<int>ans(qsz, 0);
        for(int x=0; x<qsz; ++x){
            res[queryIndices[x]]=queryCharacters[x];
            string tempstr="";
            int tempans=0;
            for(int i=0; i<sz; ++i){
                string temp_="";
                temp_+=res[i];
                while(i+1<=sz-1&&res[i]==res[i+1]){
                    temp_+=res[i+1];
                    ++i;
                }
                if(temp_.length()>tempstr.length()){
                    tempstr=temp_;
                    tempans=temp_.length();
                }
            }
            ans[x]=tempans;
        }
        return ans;
    }
};
*/

#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Solution {
	public:

		int floorKey(map<int, int>&spansmp, int ky){
			auto it=spansmp.upper_bound(ky);
			if(it==spansmp.end()){
				if(spansmp.rbegin()!=spansmp.rend()){
					return spansmp.rbegin()->first;
				} else return ky;
			} else{
				--it;
				return it->first;
			}
		}

		int ceilingKey(map<int, int>&spansmp, int ky){
			auto it=spansmp.lower_bound(ky);
			if(it==spansmp.end()){
				return ky;
			} else{
				return it->first;
			}
		}

		int lastKey(map<int, int>&lengthsmp){
			if(!lengthsmp.empty()){
				return (--lengthsmp.end())->first;
			} else return -1;
		}

		vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
			int m=s.length(), n=queryIndices.size();
			/*
				spansmp-> key: repeating characters start index
						  value: repeating characters end index

				lengthsmp-> key: length of repeating characters
				            value: count of length
			*/
			map<int, int>spansmp, lengthsmp;
			/*
				i-> start index
				j-1-> end index
			*/
			for(int i=0, j=1; j<=m; ++j){
				if(j==m||s[i]!=s[j]){
					spansmp[i]=j-1;
					int count=lengthsmp.find(j-i)!=lengthsmp.end()?lengthsmp[j-i]:0;
					lengthsmp[j-i]=count+1;
					i=j;
				}
			}
			vector<int>res(n, 0);
			for(int i=0; i<n; ++i){
				int j=queryIndices[i];
				char ch=queryCharacters[i];
				if(ch!=s[j]){
					// retrieve key less or equal to j
					int left=floorKey(spansmp, j);
					/*
						j will always be including in spansmp
						in [left, right]

						if j is not in spansmp, e.g. j>right, then j will be in another spansmp
						therefore we've to remove the old one
					*/
					int right=spansmp[left];
					spansmp.erase(left);
					int length=right-left+1;
					if(lengthsmp.find(length)!=lengthsmp.end()&&lengthsmp[length]==1){
						lengthsmp.erase(length);
					} else{
						lengthsmp[length]=lengthsmp[length]-1;
					}
					// if j>left we need to add another entry in spansmp
					if(j>left){
						spansmp[left]=j-1;
						int count=lengthsmp.find(j-left)!=lengthsmp.end()?lengthsmp[j-left]:0;
						lengthsmp[j-left]=count+1;
					}
					// if j<right we need to add another entry in spansmp
					if(j<right){
						spansmp[j+1]=right;
						int count=lengthsmp.find(right-j)!=lengthsmp.end()?lengthsmp[right-j]:0;
						lengthsmp[right-j]=count+1;
					}
					left=j, right=j, s[j]=ch;
					/*
						if s[j]==s[j-1] we need to remove the previous spansmp entry and then add the
						combined spansmp entry
					*/
					if(j>0&&s[j]==s[j-1]){
						left=floorKey(spansmp, j);
						length=spansmp[left]-left+1;
						spansmp.erase(left);
						if(lengthsmp.find(length)!=lengthsmp.end()&&lengthsmp[length]==1){
							lengthsmp.erase(length);
						} else{
							lengthsmp[length]=lengthsmp[length]-1;
						}
					}
					/*
						if s[j]==s[j+1] we need to remove the previous spansmp entry and then add the
						combined spansmp entry
					*/
					if(j<m-1&&s[j]==s[j+1]){
						int key=ceilingKey(spansmp, j);
						right=spansmp[key];
						spansmp.erase(key);
						length=right-key+1;
						if(lengthsmp.find(length)!=lengthsmp.end()&&lengthsmp[length]==1){
							lengthsmp.erase(length);
						} else{
							lengthsmp[length]=lengthsmp[length]-1;
						}
					}
					spansmp[left]=right;
					int tempval=lengthsmp[right-left+1];
					lengthsmp[right-left+1]=tempval+1;
				}
				res[i]=lastKey(lengthsmp);
			}
			return res;
		}
};

