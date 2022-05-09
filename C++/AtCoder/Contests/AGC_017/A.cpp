#include<iostream>
#include<vector>
using namespace std;


void genAllSubsUtil(vector<int>&vec, vector<vector<int>>&res, vector<int>&subarr, int idx){
	res.push_back(subarr);
	for(int i=idx; i<vec.size(); ++i){
		subarr.push_back(vec[i]);
		genAllSubsUtil(vec, res, subarr, i+1);
		subarr.pop_back();
	}
}

vector<vector<int>> genAllSubs(vector<int>&vec){
	vector<vector<int>>res;
	vector<int>subarr;
	genAllSubsUtil(vec, res, subarr, 0);
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, P;
	cin>>N>>P;
	vector<int>vec(N);
	for(int i=0; i<N; ++i){
		cin>>vec[i];
	}
	vector<vector<int>>allSubs=genAllSubs(vec);
	long long ans=0;
	for(auto &vals: allSubs){
		int currSm=0;
		for(auto &nums: vals){
			currSm+=nums;
		}
		if((currSm-P)%2==0) ans++;
	}
	cout<<ans<<"\n";
}

