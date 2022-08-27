#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		vector<vector<char>>in(2, vector<char>(2));
		for(int i=0; i<2; ++i){
			for(int j=0; j<2; ++j){
				cin>>in[i][j];
			}
		}
		int ans=INT_MAX;
		vector<vector<char>>temp=in;
		char currcolr=temp[0][0];
		int curcount=0;
		for(int i=0; i<2; ++i){
			for(int j=0; j<2; ++j){
				if(temp[i][j]!=currcolr){
					curcount++;
					char nxtcolor=temp[i][j];
					temp[i][j]=currcolr;
					for(int ii=0; ii<2; ++ii){
						for(int jj=0; jj<2; ++jj){
							if(temp[ii][jj]==nxtcolor){
								temp[ii][jj]=currcolr;
							}
						}
					}
				}
			}
		}
		ans=min(ans, curcount);
		temp=in;
		currcolr=temp[0][1];
		curcount=0;
		for(int i=0; i<2; ++i){
			for(int j=0; j<2; ++j){
				if(temp[i][j]!=currcolr){
					curcount++;
					char nxtcolor=temp[i][j];
					temp[i][j]=currcolr;
					for(int ii=0; ii<2; ++ii){
						for(int jj=0; jj<2; ++jj){
							if(temp[ii][jj]==nxtcolor){
								temp[ii][jj]=currcolr;
							}
						}
					}
				}
			}
		}
		ans=min(ans, curcount);
		temp=in;
		currcolr=temp[1][0];
		curcount=0;
		for(int i=0; i<2; ++i){
			for(int j=0; j<2; ++j){
				if(temp[i][j]!=currcolr){
					curcount++;
					char nxtcolor=temp[i][j];
					temp[i][j]=currcolr;
					for(int ii=0; ii<2; ++ii){
						for(int jj=0; jj<2; ++jj){
							if(temp[ii][jj]==nxtcolor){
								temp[ii][jj]=currcolr;
							}
						}
					}
				}
			}
		}
		ans=min(ans, curcount);
		temp=in;
		currcolr=temp[1][1];
		curcount=0;
		for(int i=0; i<2; ++i){
			for(int j=0; j<2; ++j){
				if(temp[i][j]!=currcolr){
					curcount++;
					char nxtcolor=temp[i][j];
					temp[i][j]=currcolr;
					for(int ii=0; ii<2; ++ii){
						for(int jj=0; jj<2; ++jj){
							if(temp[ii][jj]==nxtcolor){
								temp[ii][jj]=currcolr;
							}
						}
					}
				}
			}
		}
		ans=min(ans, curcount);
		cout<<ans<<endl;
	}
}