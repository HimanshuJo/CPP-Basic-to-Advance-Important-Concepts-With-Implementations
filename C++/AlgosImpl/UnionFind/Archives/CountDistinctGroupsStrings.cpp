/*Count of distinct groups of strings formed after performing 
equivalent operation*/
/*
	Given an array arr[] of N strings consisting of lowercase alphabets, 
	the task is to find the number of distinct groups of strings 
	formed after performing the equivalent operation.

    Two strings are said to be equivalent if there exists the 
	same character in both the strings and if there exists 
	another string that is equivalent to one of the strings 
	in the group of equivalent string then that string is also 
	equivalent to that group.

Examples:

    Input: arr[] = {“a”, “b”, “ab”, “d”}
    Output: 2
    Explanation:
    As strings “b” and “ab” have ‘b’ as the same character, 
    they are equivalent also “ab” and  the string”a” have ‘a’ as the same character, 
    so the strings “a”, “b”, “ab” are equivalent and “d” is another string.

    Therefore, the count of distinct group of strings formed is 2.

    Input: arr[] = {“ab”, “bc”, “abc”}
    Output: 1
*/

#include<string>
#include<vector>
#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<set>
using namespace std;

unordered_map<string, string>parent;
unordered_map<string, int>sz;

void initialize(vector<string>&arr){
	for(auto &vals: arr){
		parent[vals]=vals;
		sz[vals]=1;
	}
}

string root(string node){
	if(parent[node]==node) return node;
	return (parent[node]=root(parent[node]));
}

void connect(string nodeA, string nodeB){
	nodeA=root(nodeA), nodeB=root(nodeB);
	if(nodeA!=nodeB){
		if(sz[nodeA]<sz[nodeB]){
			swap(nodeA, nodeB);
		}
		sz[nodeA]+=sz[nodeB];
		parent[nodeB]=nodeA;
	}
}

int distinctGroups(vector<string>&arr){
	set<string>st;
	for(auto &vals: arr){
		st.insert(parent[vals]);
	}
	return st.size();
}

int main(){
	vector<string>arr{"hemnshh", "s", "a", "h", "o"};
	initialize(arr);
	int size=arr.size();
	for(int i=0; i<size-1; ++i){
		string curr=arr[i];
		int cursz=curr.length();
		for(int j=i+1; j<size; ++j){
			string next=arr[j];
			int nxtsz=next.size();
			if(cursz<=nxtsz){
				for(int x=0; x<cursz; ++x){
					string s;
					s.push_back(curr[x]);
					if(next.find(s)!=string::npos){
						connect(curr, next);
						connect(next, curr);
						break;
					}
				}
			} else{
				for(int x=0; x<nxtsz; ++x){
					string s;
					s.push_back(next[x]);
					if(curr.find(s)!=string::npos){
						connect(curr, next);
						connect(next, curr);
						break;
					}
				}
			}
		}
	}
	for(auto &vals: arr)
		cout<<vals<<" : "<<parent[vals]<<endl;
	int ans=distinctGroups(arr);
	cout<<ans<<endl;
}
