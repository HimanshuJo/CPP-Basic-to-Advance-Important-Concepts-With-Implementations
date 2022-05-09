#include<bits/stdc++.h>
using namespace std;

int gcd(int A, int B){
	if(B==0) return A;
	return gcd(B, A%B);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin>>N;
	vector<pair<int, int>>coords;
	for(int i=0; i<N; ++i){
		int x, y;
		cin>>x>>y;
		coords.push_back(make_pair(x, y));
	}
	set<pair<int, int>>aldCal;
	for(int i=0; i<N-1; ++i){
		pair<int, int>currX=coords[i];
		for(int j=i+1; j<N; ++j){
			pair<int, int>nxt=coords[j];
			int nwX=currX.first-nxt.first;
			int nwY=currX.second-nxt.second;
			int g=gcd(nwX, nwY);
			nwX/=g;
			nwY/=g;
			aldCal.insert(make_pair(nwX, nwY));
			aldCal.insert(make_pair(-nwX, -nwY));
		}
	}
	cout<<aldCal.size()<<"\n";
}

