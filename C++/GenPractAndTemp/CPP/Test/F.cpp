#include<iostream>
#include<vector>
using namespace std;

bool dfs(int n, vector<int>&vec, int curnum){
	if(curnum>n){
		if(vec.size()==n){
            int evnxor=0, oddxor=0;
            for(int i=0; i<n; ++i){
                if(i%2==0){
                    evnxor^=vec[i];
                } else{
                    oddxor^=vec[i];
                }
            }
            return evnxor==oddxor;
        }
        return false;
	}
    vec.push_back(curnum);
    if(dfs(n, vec, curnum+1)) return true;
    vec.pop_back();
    if(dfs(n, vec, curnum+1)) return true;
    return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int>vec;
		int evnxors=0, oddxors=0;
		dfs(n, vec, 0);
		int evnbgn=0, oddbgn=0;
		for(auto &vals: vec){
            cout<<vals<<" ";
		}
		cout<<"\n";
	}
}