#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

bool isValid(vector<int>&in, int val, int curr){
	int currTotal=curr;
	for(int i=0; i<val-1; ++i){
		currTotal+=in[i];
		if(currTotal<0){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n, s;
		cin>>n>>s;
		vector<int>in(n);
		unordered_map<int, int>mp;
		for(int i=0; i<n; ++i){
			cin>>in[i];
			mp[in[i]]=i+1;
		}
		sort(in.begin(), in.end(), greater<int>());
		int left=0, right=n;
		while(left<right){
			int mid=left+(right-left)/2;
			if(isValid(in, mid, s)){
				right=mid;
			} else{
				left=mid+1;
			}
		}
		int frst=left-1;
		if(frst==-1){
			cout<<-1<<"\n";
			continue;
		}
		vector<int>resInd;
		for(int i=0; i<frst; ++i){
			resInd.push_back(in[i]);
		}
		sort(resInd.begin(), resInd.end());
		int ans1=mp[resInd[0]];
		int ans2=mp[resInd[1]];
		cout<<ans1<<" "<<ans2<<"\n";
	}
}
