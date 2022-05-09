#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool check(int x, vector<pair<int, int>>&in){
	int c=0;
	for(int i=0; i<in.size(); ++i){
		if(x-1-in[i].first<=c&&c<=in[i].second){
			c++;
		}
	}
	return c>=x;
}

bool custComp(pair<int, int>A, pair<int, int>B){
	if(A.first==B.first){
		return A.second<B.second;
	}
	return A.first<B.first;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<pair<int, int>>in;
		for(int i=0; i<n; ++i){
			int a, b;
			cin>>a>>b;
			in.push_back({a, b});
		}
		//sort(in.begin(), in.end(), custComp);
		int left=0, right=n;
		int ans=0;
		while(left<=right){
			int mid=left+(right-left)/2;
			if(check(mid, in)){
				left=mid+1;
				ans=mid;
			} else{
				right=mid-1;
			}
		}
		cout<<ans<<"\n";
	}
}
