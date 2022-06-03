#include<vector>
#include<iostream>
using namespace std;

long dfs(long *values, int sz, int idx, bool flag, vector<vector<long>>&memo){
	if(idx>=sz) return 0;
	if(memo[idx][flag]!=-1) return memo[idx][flag];
    long prof=0;
	if(!flag){
		long curprof=max(dfs(values, sz, idx+1, false, memo), values[idx]+dfs(values, sz, idx+1, true, memo));
		prof=max(prof, curprof);
	} else{
		long curprof=max(dfs(values, sz, idx+1, true, memo), -values[idx]+dfs(values, sz, idx+1, false, memo));
		prof=max(prof, curprof);
	}
    return memo[idx][flag]=prof;
}

long getMaximumProfit(long *values, int n)
{
    int sz=n;
	vector<vector<long>>memo(sz+1, vector<long>(2, -1));
    return dfs(values, sz, 0, true, memo);    
}

int main(){
	long *values=new long[7];
	values[0]=1, values[1]=2, values[2]=3, values[3]=4, values[4]=5;
	values[5]=6; values[6]=7;
	int n=7;
	long long ans=getMaximumProfit(values, n);
	cout<<"\n-------\n";
	cout<<ans<<endl;
	delete []values;
}