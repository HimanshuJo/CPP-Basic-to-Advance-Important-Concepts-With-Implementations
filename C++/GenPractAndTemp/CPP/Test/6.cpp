#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
#define endl "\n"
using namespace std;

string toBinary(int num){
	string temp="";
	while(num>1){
		int quo=num/2;
		int rem=num%2;
		temp+=to_string(rem);
		num=quo;
	}
	temp+="1";
	while(temp.size()!=32){
		temp+="0";
	}
	reverse(temp.begin(), temp.end());
	return temp;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int>in(n);
		int maxx=INT_MIN;
		int maxxidx;
		set<int>seenidx;
		for(int i=0; i<n; ++i){
			cin>>in[i];
			if(maxx<in[i]){
				maxxidx=i;
			}
			maxx=max(maxx, in[i]);
		}
		seenidx.insert(maxxidx);
		map<int, priority_queue<pair<int, int>, vector<pair<int, int>>>, greater<>>mp;
		map<int, priority_queue<pair<int, int>, vector<pair<int, int>>>, greater<>>mp2;
		for(int i=0; i<n; ++i){
			if(seenidx.find(i)==seenidx.end()){
				string curr=toBinary(in[i]);
				int sz=curr.size();
				for(int x=0; x<sz; ++x){
					if(curr[x]=='1'){
						mp[x].push({in[i], i});
					} else{
						mp2[x].push({in[i], i});
					}
				}
			}
		}
		vector<int>ans;
		ans.push_back(maxx);
		string bgnbn=toBinary(maxx);
		int frstst;
		int cursz=bgnbn.size();
		for(int i=0; i<cursz; ++i){
			if(bgnbn[i]=='1'){
				frstst=i;
				break;
			}
		}
		for(int x=frstst; x<32; ++x){
			if(bgnbn[x]=='0'){
				auto it=mp.find(x);
				if(it!=mp.end()){
					auto curpq=it->second;
					while(!curpq.empty()){
						int tp=curpq.top().second;
						auto stit=seenidx.find(tp);
						if(stit==seenidx.end()){
							ans.push_back(in[tp]);
							seenidx.insert(tp);
						}
						curpq.pop();
					}
				}
			} else{
				auto it=mp2.find(x);
				if(it!=mp2.end()){
					auto curpq=it->second;
					while(!curpq.empty()){
						int tp=curpq.top().second;
						auto stit=seenidx.find(tp);
						if(stit==seenidx.end()){
							ans.push_back(in[tp]);
							seenidx.insert(tp);
						}
						curpq.pop();
					}
				}
			}
		}
		if(ans.size()!=n){
			for(auto &entries: mp){
				if(entries.second.size()!=0){
					auto curpq=entries.second;
					while(!curpq.empty()){
						int tp=curpq.top().second;
						auto stit=seenidx.find(tp);
						if(stit==seenidx.end()){
							ans.push_back(in[tp]);
							seenidx.insert(tp);
						}
						curpq.pop();
					}
				}
			}
		}
		for(auto &vals: ans){
			cout<<vals<<" ";
		}
		cout<<endl;
	}
}