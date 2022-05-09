#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<set>
using namespace std;
using ll=long long;

bool isValid(vector<vector<bool>>&vec){
	for(int i=0; i<5; ++i){
		bool flag=false;
		vector<bool>rw=vec[i];
		for(int x=0; x<5; ++x){
			if(!rw[x]){
				flag=true;
				break;
			}
		}
		if(!flag){
			return true;
		} else{
			flag=false;
			for(int x=0; x<5; ++x){
				if(!vec[x][i]){
					flag=true;
					break;
				}
			}
		}
		if(!flag) return true;
	}
	return false;
}

vector<string> splitString(string str, char delimiter) { 
	vector<string> internal; 
	stringstream ss(str); 
	string tok; 
	while(getline(ss, tok, delimiter)) { 
		internal.push_back(tok); 
	} 
	return internal;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string order;
	cin>>order;
	int sz=599;
	vector<vector<vector<int>>>bingos(sz, vector<vector<int>>(5, vector<int>(5)));
	vector<vector<vector<bool>>>binB(sz, vector<vector<bool>>(5, vector<bool>(5, false)));
	vector<string>nwOrders=splitString(order, ',');
	for(int i=0; i<sz; ++i){
		for(int x=0; x<5; ++x){
			for(int y=0; y<5; ++y){
				cin>>bingos[i][x][y];
			}
		}
	}
	set<int>st;
	int fnIdx=0;
	int fnNum=1;
	int n=bingos.size();
	for(string str: nwOrders){
		int vals=stoi(str);
		bool flag=false;
		for(int i=0; i<n; ++i){
			vector<vector<int>>curr=bingos[i];
			for(int x=0; x<5; ++x){
				for(int y=0; y<5; ++y){
					if(curr[x][y]==vals){
						binB[i][x][y]=true;
						if(isValid(binB[i])){
							st.insert(i);
						}
						if(st.size()==n){
							fnIdx=i;
							fnNum=vals;
							flag=true;
							break;
						}
					}
				}
				if(flag) break;
			}
			if(flag) break;
		}
		if(flag) break;
	}
	vector<vector<int>>fn=bingos[fnIdx];
	vector<vector<bool>>fnB=binB[fnIdx];
	ll sum=0;
	for(int i=0; i<5; ++i){
		for(int j=0; j<5; ++j){
			if(!fnB[i][j]){
				sum+=fn[i][j];
			}
		}
	}
	cout<<(sum*fnNum)<<"\n";
}
