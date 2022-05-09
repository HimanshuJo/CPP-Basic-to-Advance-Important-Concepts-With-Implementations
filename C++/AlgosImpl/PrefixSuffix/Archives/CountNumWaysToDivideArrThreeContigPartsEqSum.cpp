/*
Given an array of n numbers. Our task is to find out the number of ways to divide the array 
into three contiguous parts such that the sum of three parts is equal. In other words, 
we need to find the number of index pairs i and j such that sum of elements from 0 to i-1 is 
equal to the sum of elements from i to j is equal to the sum of elements from j+1 to n-1.

Examples: 

Input  : arr[] = {1, 2, 3, 0, 3}
Output : 2
Following are two possible ways to partition
1) Three parts are (1, 2), (3) and (0, 3)
2) Three parts are (1, 2), (3,0) and (3)

Input : arr[] = {0, 1, -1, 0}
Output : 1
It is only one way to partition.
1) Three parts are (0), (1,-1) and (0)
*/
/*
Brute Force:

#include<iostream>
#include<vector>
#include<cstring>
#include<map>
using namespace std;

int numWaysThreeContiguousPartsEqSum(vector<int>&arr, int sz){
	map<int, vector<vector<int>>>mp;
	vector<vector<vector<int>>>vec;
	vector<int>temp1, prev1;
	vector<int>temp2, prev2;
	for(int i=0; i<=sz-3; ++i){
		temp1=prev1;
		temp1.push_back(arr[i]);
		prev1=temp1;
		for(int j=i+1; j<=sz-2; ++j){
			mp[i].push_back(temp1);
			temp2=prev2;
			temp2.push_back(arr[j]);
			prev2=temp2;
			mp[i].push_back(temp2);
			vector<int>temp3;
			for(int k=j+1; k<sz; ++k){
				temp3.push_back(arr[k]);
			}
			mp[i].push_back(temp3);
		}
		temp2.clear();
		prev2.clear();
	}
	for(auto &entries: mp){
		vector<vector<int>>adr1;
		for(auto &vecEntries: entries.second){
			vector<int>temp;
			for(auto &vals: vecEntries){
				temp.push_back(vals);
			}
			adr1.push_back(temp);
		}
		vec.push_back(adr1);
	}
	int ans=0;
	for(auto &vecEntries: vec){
		int counter=0, sm=0;
		bool flag=false;
		for(auto &entries: vecEntries){
			if(counter!=0){
				int tempsm=0;
				for(auto &vals: entries){
					tempsm+=vals;
				}
				if(tempsm!=sm){
					flag=true;
				}
			} else{
				for(auto &vals: entries){
					sm+=vals;
				}
			}
			counter++;
			if(counter==3){
				if(!flag) ans++;
				sm=0, counter=0;
				flag=false;
			}
		}
	}
	return ans;
}

int main(){
	vector<int>arr{3, 3, 3, 3, 3, 3};
	int sz=arr.size();
	int ans=numWaysThreeContiguousPartsEqSum(arr, sz);
	cout<<ans<<endl;
}
*/

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int numWaysThreeContiguousPartsEqSum(vector<int>&arr, int sz){
	int sum=0;
	for(auto &vals: arr){
		sum+=vals;
	}
	if(sum%3!=0) return 0;
	int prtsSm=sum/3;
	vector<int>cntprtsSmArr(sz, 0);
	int tmpSm=0;
	for(int i=sz-1; i>=0; --i){
		tmpSm+=arr[i];
		if(tmpSm==prtsSm){
			cntprtsSmArr[i]=1;
		}
	}
	for(int i=sz-2; i>=0; --i){
		cntprtsSmArr[i]+=cntprtsSmArr[i+1];
	}
	int tmpSm_=0, ans=0;
	for(int i=0; i+2<sz; ++i){
		tmpSm_+=arr[i];
		if(tmpSm_==prtsSm){
			ans+=cntprtsSmArr[i+2];
		}
	}
	return ans;
}

int main(){
	vector<int>arr{0, 1, -1, 0};
	int sz=arr.size();
	int ans=numWaysThreeContiguousPartsEqSum(arr, sz);
	cout<<ans<<endl;
}