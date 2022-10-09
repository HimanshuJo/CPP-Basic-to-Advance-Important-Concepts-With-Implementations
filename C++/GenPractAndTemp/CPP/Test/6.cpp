#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> calAllSplits(int curnum, int curmin){
	vector<int>res;
	int fnsize=INT_MAX;
	for(int i=1; i<=curnum; ++i){
		if(i<curmin){
			vector<vector<int>>currallsplits;
			vector<int>split;
			int frstnum=i;
			split.push_back(frstnum);
			int rem=curnum-frstnum;
			int anthminn=min(frstnum, rem);
			int anthmaxx=max(frstnum, rem);
			if(2*anthminn>curmin&&2*anthminn>anthmaxx){
				split.push_back(rem);
				currallsplits.push_back(split);
			}
			while(anthmaxx>=1){
				for(int ii=1; ii<=anthmaxx; ++ii){
					int secrem=curnum-(ii+anthmaxx+frstnum);
					if(secrem<=0||secrem<curmin) break;
					int tochkmin=min(secrem, anthminn);
					int tochkmaxx=max(ii, secrem);
					if(2*tochkmin>curmin&&2*tochkmin>tochkmaxx){
						split.push_back(secrem);
						split.push_back(ii+anthmaxx);
						currallsplits.push_back(split);
					}
				}
				anthmaxx--;
			}
			for(auto &vals: currallsplits){
				if(vals.size()<fnsize){
					res=vals;
					fnsize=vals.size();
				}
			}
		}
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int N;
		cin>>N;
		vector<int>in(N);
		int minn=INT_MAX;
		for(int i=0; i<N; ++i){
			cin>>in[i];
			minn=min(minn, in[i]);
		}
		unordered_map<int, vector<int>>mp;
		for(int i=0; i<N; ++i){
			vector<int>curr=calAllSplits(in[i], minn);
			mp[i]=curr;
		}
		/*
		for(auto &entries: mp){
			cout<<entries.first<<" : ";
			for(auto &vals: entries.second){
				cout<<vals<<" ";
			}
			cout<<endl;
		}
		cout<<"\n-------\n";
		*/
		int ans=0;
		for(auto &entries: mp){
			if(entries.second.size()!=0){
				vector<int>temp=entries.second;
				int idx=0;
				int cursplit=0;
				int sz=temp.size();
				while(true){
					if(idx+1>=sz){
						cursplit++;
						break;
					}
					cursplit++;
					idx+=2;
					if(idx>=sz){
						break;
					} 
				}
				ans+=cursplit;
			} else{
				if(2*1>minn){
					ans+=(in[entries.first]-1);
				}
			}
		}
		cout<<ans<<endl;
	}
}