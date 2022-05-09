#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isValid(vector<int>&coordCurCr, vector<vector<int>>&progress, 
	         vector<vector<int>>&wordD, vector<vector<int>>&tWrkSt, int M, int S, int x){
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int M, S, T, L;
	cin>>M>>S>>T>>L;
	vector<vector<int>>tWrkSt(M+1, vector<int>(S+1, 0));
	for(int i=0; i<M; ++i){
		for(int j=0; j<S; ++j){
			int in;
			cin>>in;
			tWrkSt[i][j]=in;
		}
	}
	vector<int>coordsS(S+1);
	for(int i=0; i<S; ++i){
		cin>>coordsS[i];
	}
	vector<int>dmnds(M+1);
	int sm=0;
	for(int i=0; i<M; ++i){
		cin>>dmnds[i];
		sm+=dmnds[i];
	}
	int t=0, flagB=0;
	vector<vector<int>>progress(M+1, vector<int>(S+1, 0));
	vector<int>coordCurCr(M+1, 0);
	vector<vector<int>>workD(M+1, vector<int>(S+1, -1));
	int counter2=0;
	while(t!=L||counter2<sm){
		bool tmpFlg=false;
		for(int k=0; k<M; ++k){
			coordCurCr[k]=-(k-1)*T;
			for(int x=0; x<S; ++x){
				if(coordsS[x]==coordCurCr[k]&&workD[k][x]!=tWrkSt[k][x]){
					flagB=1;
					tmpFlg=true;
					break;
				}
			}
		}
		if(!tmpFlg) flagB=0;
		for(int x=0; x<S; ++x){
			bool flag_=false;
			for(int y=0; y<M; ++y){
				if(isValid(coordCurCr, progress, workD, tWrkSt, M, S, x)){
					workD[y][x]+=1;
					flag_=true;
					break;
				}
			}
			if(flag_) break;
		}
		if(flagB==0){
			for(int k=0; k<M; ++k){
				coordCurCr[k]+=1;
			}
		}
		t++;
		counter2=0;
		for(int i=0; i<M; ++i)
			for(int j=0; j<S; ++j){
				if(workD[i][j]==tWrkSt[i][j]){
					counter2++;
				}
			}
	}
	int counter=0;
	for(int i=0; i<M; ++i){
		for(int j=0; j<S; ++j){
			if(workD[i][j]==tWrkSt[i][j]){
				counter++;
			}
		}
	}
	cout<<counter<<"\n";
}