#include<bits/stdc++.h>
using namespace std;

int calMatDist(int X1, int Y1, int X2, int Y2){
	return(abs(X1-X2)+abs(Y1-Y2));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	map<int, vector<pair<vector<int>, int>>>in;
	vector<vector<int>>inRoutes(1001, vector<int>(4));
	int route=1;
	for(int i=0; i<1000; ++i){
		int A, B, C, D;
		cin>>A>>B>>C>>D;
		vector<int>curr(4);
		curr[0]=A, curr[1]=B, curr[2]=C, curr[3]=D;
		inRoutes[route][0]=A;
		inRoutes[route][1]=B;
		inRoutes[route][2]=C;
		inRoutes[route][3]=D;
		int currDist=calMatDist(curr[0], curr[1], curr[2], curr[3]);
		in[currDist].push_back(make_pair(curr, route));
		route++;
	}
	int M=0;
	int N=0;
	set<int>seenRoutes;
	vector<int>fnRoutes;
	vector<vector<int>>fnCoords;
	auto it=in.begin();
	pair<int, int>prevCord1;
	pair<int, int>prevCord2;
	while(M!=50){
		vector<pair<vector<int>, int>>curr=it->second;
		for(auto &vals: curr){
			pair<vector<int>, int>toChk=vals;
			prevCord2.first=toChk.first[0];
			prevCord2.second=toChk.first[1];
			if(M>=1){
				int chkX1=prevCord1.first;
				int chkY1=prevCord1.second;
				int chkX2=prevCord2.first;
				int chkY2=prevCord2.second;
				for(int i=1; i<=1000; ++i){
					auto it_=seenRoutes.find(i);
					if(it_==seenRoutes.end()){
						if(inRoutes[i][0]>=chkX1&&inRoutes[i][1]>=chkY1&&inRoutes[i][2]>=chkX1&&inRoutes[i][3]>=chkY1&&inRoutes[i][0]<=chkX2&&inRoutes[i][1]<=chkY2&&inRoutes[i][2]<=chkX2&&inRoutes[i][3]<=chkY2){
							int currDist=calMatDist(inRoutes[i][0], inRoutes[i][1], inRoutes[i][2], inRoutes[i][3]);
							if(currDist>=it->first) continue;
							fnRoutes.push_back(i);
							fnCoords.push_back({inRoutes[i][0], inRoutes[i][1], inRoutes[i][2], inRoutes[i][3]});
							seenRoutes.insert(i);
							M++;
							if(M==50) break;
						}
					}
				}
				if(M==50) break;
			}
			auto it__=seenRoutes.find(toChk.second);
			if(it__==seenRoutes.end()){
				fnRoutes.push_back(toChk.second);
				fnCoords.push_back(toChk.first);
				seenRoutes.insert(toChk.second);
				prevCord1.first=toChk.first[2];
				prevCord1.second=toChk.first[3];
				M++;
				if(M==50) break;
			}
		}
		it++;
		if(it==in.end()) break;
	}
	int fnSize=(fnCoords.size()*4)+4;
	N=fnSize/2;
	cout<<M<<" ";
	for(auto &vals: fnRoutes){
		cout<<vals<<" ";
	}
	cout<<"\n";
	cout<<N<<" ";
	cout<<400<<" "<<400<<" ";
	for(auto &vals: fnCoords){
		for(auto &nums: vals){
			cout<<nums<<" ";
		}
	}
	cout<<400<<" "<<400;
	return 0;
}

