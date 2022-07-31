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

int longestIncreasingSubsequenceBS(vector<int>&arr, int n)
{
    vector<int>ans;
    int len=1;
    ans.push_back(arr[0]);
    for(int i=1; i<n; ++i){
        if(arr[i]>ans.back()){
            ans.push_back(arr[i]);
            len++;
        } else{
            auto it=lower_bound(ans.begin(), ans.end(), arr[i]);
            int idx=it-ans.begin();
            ans[idx]=arr[i];
        }
    }
    return len;
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
	int res5=longestIncreasingSubsequenceBS(in, sz);
	cout<<res5<<endl;
}