// Find the missing element in an array of integers represented in binary format
/*
Given N strings which represents all integers from 0 to N in binary format except any one. 

The task is to find the missing number. 

Input consists of an array of strings where array elements are represented in binary format.

Examples: 
 
Input: arr[] = {“0000”, “0001”, “0010”, “0100”} 
Output: 3
Input: arr[] = {“0000”, “0001”, “0010”, “0011”, “0100”, “0110”, “0111”, “1000”} 
Output: 5 
*/

/*
Approach:

    An imbalance of 1’s and 0’s in the least significant bits of the numbers can be observed in the N 
    integers given. 
    Since one number is missing either a 0 or 1 from the LSB is missing. 
    If the number which is missing has LSB = 0 then count(1) will be greater than equal to count(0). 
    If LSB of missing number is 1 then count(1) is less than count(0).

    From the step 1 one can easily determine the LSB of missing number.
    
    Once determined, discard all the numbers having LSB different from that of the missing number, 
    i.e., if the missing number has LSB = 0, then discard all the numbers with LSB = 1 and vice versa.

    Continue the process from step 1 all over again and recur for the next LSB.

    Continue with the above process till all the bits are traversed.
*/

// Time Complexity: O(N)

#include<string>
#include<vector>
#include<iostream>
#include<cmath>
using namespace std;

string res="";

int toDec(string &str){
	int sz=str.size(), temp_=sz-1;
	int ans=0;
	for(int i=0; i<sz; ++i){
		ans+=(str[i]-'0')*pow(2, temp_--);
	}
	return ans;
}

int dfs(vector<string>&in, int sz, int col){
	if(col<0) return 0;
	vector<string>evenIdxs, oddIdxs;
	for(auto &vals: in){
		if(vals[col]=='0'){
			evenIdxs.push_back(vals);
		} else{
			oddIdxs.push_back(vals);
		}
	}
	if(oddIdxs.size()>=evenIdxs.size()){
		res[col]='0';
		return dfs(evenIdxs, sz, col-1);
	} else{
		res[col]='1';
		return dfs(oddIdxs, sz, col-1);
	}
}

int main(){
	vector<string>in{"0000", "0001", "0010", "0011", "0100", "0101", "0110", "1000"};
	int sz=in.size();
	int col=in[0].size();
	res.resize(col);
	dfs(in, sz, col-1);
	cout<<toDec(res)<<" ";
}