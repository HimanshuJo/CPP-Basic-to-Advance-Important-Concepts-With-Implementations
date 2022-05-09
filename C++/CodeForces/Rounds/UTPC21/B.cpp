#include<bits/stdc++.h>
using namespace std;

bool check(vector<vector<bool>>&seen, int rw){
		vector<bool>currGrd=seen[rw];
		for(bool vals: currGrd){
				if(vals==false){
						return false;
				}
		}
		return true;
}

bool checkCol(vector<vector<bool>>&seen, int col){
		for(int i=0; i<seen.size(); ++i){
				if(seen[i][col]==false){
						return false;
				}
		}
		return true;
}


int main(){
		ios_base::sync_with_stdio(0);
		cin.tie(NULL);
		int N;
		cin>>N;	
		map<int, pair<int, int>>mp;
		vector<vector<int>>grd(N, vector<int>(N));
		for(int i=0; i<N; ++i){
				for(int j=0; j<N; ++j){
					cin>>grd[i][j];
					mp[grd[i][j]]={i, j};
				}
		}
		vector<int>callNum(N*N);
		vector<vector<bool>>seen(N, vector<bool>(N));
		for(int i=0; i<seen.size(); ++i){
				for(int j=0; j<seen[i].size(); ++j){
						seen[i][j]=false;
				}
		}
		for(int i=0; i<N*N; ++i){
				cin>>callNum[i];
		}
		int ans=-1;
		for(auto &vals: callNum){
				pair<int, int>curr=mp[vals];
				seen[curr.first][curr.second]=true;
				int rw=curr.first;
				int col=curr.second;
				bool tmp=check(seen, rw);
				if(tmp){
						ans=vals;
						break;
				}
				bool tmp_=checkCol(seen, col);
				if(tmp_){
						ans=vals;
						break;
				}
		}
		cout<<ans;
}


