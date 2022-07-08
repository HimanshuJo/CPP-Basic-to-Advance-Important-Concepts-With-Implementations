#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dfs(vector<int>&in, const int sz, int idx, vector<int>&memo){
	if(memo[idx]!=-1) return memo[idx];
	if(idx==sz) return 0;
	int res=1;
	if(idx+1<=sz-1&&in[idx]<in[idx+1]){
		res=max(res, max(1+dfs(in, sz, idx+1, memo), dfs(in, sz, idx+1, memo)));
	} else{
		res=max(res, dfs(in, sz, idx+1, memo));
	}
	return memo[idx]=res;
}

/*
	Time Complexity: O(n^2)
	Space Complexity: O(n^2)
*/

int lisRec(vector<int>&in, const int sz, int idx){
	vector<int>memo(sz+1, -1);
	return dfs(in, sz, idx, memo);
}

/*
    Time Complexity: O(n^2). 
    Auxiliary Space: O(n). 
*/

int lisDp(vector<int>&in, const int sz){
	vector<int>dp(sz+1, 0);
	dp[0]=1;
	for(int i=1; i<sz; ++i){
		dp[i]=1;
		for(int j=0; j<i; ++j){
			if(in[i]>in[j]&&dp[i]<dp[j]+1){
				dp[i]=dp[j]+1;
			}
		}
	}
	sort(dp.begin(), dp.end());
	return dp[sz];
}

/*
	Time Complexity: O(n^2)
	Space Complexity: O(n^2)
*/

int lisLCS(vector<int>&in, vector<int>&temp, const int sz){
	vector<vector<int>>dp(sz+1, vector<int>(sz+1, 0));
	for(int i=1; i<=sz; ++i){
		for(int j=1; j<=sz; ++j){
			if(in[i-1]==temp[j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
			} else{
				dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[sz][sz];
}

vector<int> returnLIS(vector<int>&in, vector<int>&temp, const int sz){
	vector<vector<int>>dp(sz+1, vector<int>(sz+1, 0));
	for(int i=1; i<=sz; ++i){
		for(int j=1; j<=sz; ++j){
			if(in[i-1]==temp[j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
			} else{
				dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	int i=sz, j=sz, index=dp[sz][sz];
	vector<int>res(index, 0);
	while(i>0&&j>0){
		if(in[i-1]==temp[j-1]){
			res[index-1]=in[i-1];
			--i, --j, --index;
		} else if(dp[i-1][j]>dp[i][j-1]){
			--i;
		} else --j;
	}
	return res;
}

int binarySearch(vector<int>&arr, vector<int>&M, int L, int idx){
	int low=1, high=L+1;
	while(low<high){
		int mid=low+(high-low)/2;
		if(arr[M[mid]]<arr[idx]){
			low=mid+1;
		} else{
			high=mid;
		}
	}
	return low;
}

/*
	Time Complexity: O(nlogn)
	Space Complexity: O(n)
*/

int lisBinarySearch(vector<int>&in, const int sz){
	/*
		P stores the index of the predecessor of X[k] 
		in the longest increasing subsequence ending at X[k]
		on the range k≤i

		So if Ki,j denotes the set of all indices k 
		such that k≤i and there exists an increasing subsequence of length j ending at X[k] 
		(that is, there exist j indices l1 < l2 < ⋯ < lj = k ending at k 
		such that X[l1] ≤ X [l2] ≤ ⋯ ≤ X[k] then M[j] is the index for which the following holds: 
			M[j] ∈ Ki,j and X[M[j]]=min(k∈Ki,j) X[k]
	*/
	vector<int>P(sz, 0);
	/*
		M stores the index k of the smallest value X[k] 
		such that there is an increasing subsequence of length j
		ending at X[k] on the range k ≤ i
	*/
	vector<int>M(sz+1, 0);
	int L=0;
	for(int i=0; i<sz; ++i){
		int lo=binarySearch(in, M, L, i);
		int nwL=lo;
		P[i]=M[nwL-1];
		M[nwL]=i;
		if(nwL>L){
			L=nwL;
		}
	}
	vector<int>S(L, 0);
	int k=M[L];
	for(int x=L-1; x>=0; --x){
		S[x]=in[k];
		k=P[k];
	}	
	for(auto &vals: S)
		cout<<vals<<" ";
	cout<<endl;
	return S.size();
}

int main(){
	vector<int>in{50, 3, 10, 7, 40, 80};
	int sz=in.size();
	int res=lisRec(in, sz, 0);
	cout<<res<<endl;
	cout<<"-------\n";
	vector<int>temp=in;
	sort(temp.begin(), temp.end());
	int res2=lisLCS(in, temp, sz);
	cout<<res2<<endl;
	cout<<"-------\n";
	int res3=lisDp(in, sz);
	cout<<res3<<endl;
	cout<<"-------\n";
	vector<int>res4=returnLIS(in, temp, sz);
	for(auto &vals: res4){
		cout<<vals<<" ";
	}
	cout<<"\n-------\n";
	int res5=lisBinarySearch(in, sz);
	cout<<res5<<endl;
}