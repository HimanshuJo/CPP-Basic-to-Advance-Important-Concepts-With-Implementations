#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cstring>
using namespace std;
using ll=long long;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	char temp[100][100];
	for(int i=0; i<100; ++i){
		gets(temp[i]);
	}
	ll ans=0;
	vector<int>all;
	for(int i=0; i<100; ++i){
		if(i==0){
			for(int x=0; x<100; ++x){
				int curr=temp[i][x]-'0';
				if(x-1>=0&&x+1<=99){
					int prev=temp[i][x-1]-'0';
					int next=temp[i][x+1]-'0';
					int dwn=temp[i+1][x]-'0';
					if(curr<prev&&curr<next&&curr<dwn){
						all.push_back(curr);
					}
				} else if(x-1>=0&&x+1>=100){
					int prev=temp[i][x-1]-'0';
					int dwn=temp[i+1][x]-'0';
					if(curr<prev&&curr<dwn){
						all.push_back(curr);
					}
				} else if(x-1<0&&x+1<=99){
					int next=temp[i][x+1]-'0';
					int dwn=temp[i+1][x]-'0';
					if(curr<next&&curr<dwn){
						all.push_back(curr);
					}
				}
			}
		} else if(i==99){
			for(int x=0; x<100; ++x){
				int curr=temp[i][x]-'0';
				if(x-1>=0&&x+1<=99){
					int prev=temp[i][x-1]-'0';
					int next=temp[i][x+1]-'0';
					int up=temp[i-1][x]-'0';
					if(curr<prev&&curr<next&&curr<up){
						all.push_back(curr);
					}
				} else if(x-1>=0&&x+1>=100){
					int prev=temp[i][x-1]-'0';
					int up=temp[i-1][x]-'0';
					if(curr<prev&&curr<up){
						all.push_back(curr);
					}
				}  else if(x-1<0&&x+1<=99){
					int next=temp[i][x+1]-'0';
					int up=temp[i-1][x]-'0';
					if(curr<next&&curr<up){
						all.push_back(curr);
					}
				}
			}
		} else {
			for(int x=0; x<100; ++x){
				int curr=temp[i][x]-'0';
				if(x-1>=0&&x+1<=99){
					int prev=temp[i][x-1]-'0';
					int next=temp[i][x+1]-'0';
					int up=temp[i-1][x]-'0';
					int dwn=temp[i+1][x]-'0';
					if(curr<prev&&curr<next&&curr<up&&curr<dwn){
						all.push_back(curr);
					}
				}  else if(x-1>=0&&x+1>=100){
					int prev=temp[i][x-1]-'0';
					int up=temp[i-1][x]-'0';
					int dwn=temp[i+1][x]-'0';
					if(curr<prev&&curr<up&&curr<dwn){
						all.push_back(curr);
					}
				}  else if(x-1<0&&x+1<=99){
					int next=temp[i][x+1]-'0';
					int up=temp[i-1][x]-'0';
					int dwn=temp[i+1][x]-'0';
					if(curr<next&&curr<up&&curr<dwn){
						all.push_back(curr);
					}
				}
			}
		}
	}
	ll sum=0;
	/*for(auto &vals: all){
		cout<<vals<<" ";
		int val=vals+1;
		sum+=val;
	}
	cout<<endl; */
	cout<<sum<<"\n";
}
