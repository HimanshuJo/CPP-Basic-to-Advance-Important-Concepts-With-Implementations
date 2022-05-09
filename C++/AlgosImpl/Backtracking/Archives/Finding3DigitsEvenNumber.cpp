// 2094. Finding 3-Digit Even Numbers
/*
You are given an integer array digits, where each element is a digit. The array may contain duplicates.

You need to find all the unique integers that follow the given requirements:

The integer consists of the concatenation of three elements from digits in any arbitrary order.
The integer does not have leading zeros.
The integer is even.
For example, if the given digits were [1, 2, 3], integers 132 and 312 follow the requirements.

Return a sorted array of the unique integers.

Example 1:

Input: digits = [2,1,3,0]
Output: [102,120,130,132,210,230,302,310,312,320]
Explanation: 
All the possible integers that follow the requirements are in the output array. 
Notice that there are no odd integers or integers with leading zeros.
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

	unordered_set<int>uset;
	unordered_set<string>memo;

	void dfs(vector<int>&digits, string num, vector<bool>visited){
		if(num.size()>=3) return;
		if(num.size()==2&&memo.count(num)>0) return;
		for(int i=0; i<digits.size(); ++i){
			if(!visited[i]){
				if(num.size()==0){
					if(digits[i]!=0){
						visited[i]=true;
						string str=num;
						str+=to_string(digits[i]);
						dfs(digits, str, visited);
						visited[i]=false;
					}
				} else if(num.size()==2&&digits[i]%2==0){
					uset.insert(stol(num+to_string(digits[i])));
				} else{
					visited[i]=true;
					string str=num+to_string(digits[i]);
					dfs(digits, str, visited);
					visited[i]=false;
				}
			}
		}
		if(num.size()==2){
			memo.insert(num);
		}
	}

    vector<int> findEvenNumbers(vector<int>& digits) {
    	int n=digits.size();
    	vector<bool>visited(n, false);
    	dfs(digits, "", visited);
    	vector<int>ans;
    	for(auto &vals: uset)
    		ans.push_back(vals);
    	sort(ans.begin(), ans.end());
    	return ans;    
    }
};

class Solution2 {
public:

	set<int>ans;
	
    void dfs(int data, int val, int length, vector<int>&digits, vector<bool>&seen){
		val=val*10+data;
        if(memo.count(val)>0) return;
		if(length==3){
			if(data%2==0){
				ans.insert(val);
			}
			return;
		}
		for(int i=0; i<digits.size(); ++i){
			if(length==0&&digits[i]==0) continue;
			if(seen[i]) continue;
			seen[i]=true;
			dfs(digits[i], val, length+1, digits, seen);
			seen[i]=false;
		}
	}

    vector<int> findEvenNumbers(vector<int>& digits) {
        int n=digits.size();
        vector<bool>seen(n, false);
        dfs(0, 0, 0, digits, seen);
        return {ans.begin(), ans.end()};
    }
};