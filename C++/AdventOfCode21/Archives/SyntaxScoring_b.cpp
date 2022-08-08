#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
using ll=long long;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n=98;
	ll smBrcC=0, capBrcC=0, curlBrcC=0, angBrcC=0;
	ll ans=0;
	vector<ll>res;
	for(int i=0; i<n; ++i){
		string s;
		cin>>s;
		stack<char>stk;
		bool flag=false;
		for(int i=0; i<s.length(); ++i){
			if(s[i]=='{'||s[i]=='('||s[i]=='['||s[i]=='<'){
				stk.push(s[i]);
			}
			else if((s[i]==')'&&stk.top()=='{')||(s[i]==')'&&stk.top()=='[')||(s[i]==')'&&stk.top()=='<')){
				flag=true;
				smBrcC++;
				break;
			} else if((s[i]=='}'&&stk.top()=='(')||(s[i]=='}'&&stk.top()=='[')||(s[i]=='}'&&stk.top()=='<')){
				flag=true;
				curlBrcC++;
				break;
			} else if((s[i]==']'&&stk.top()=='(')||(s[i]==']'&&stk.top()=='{')||(s[i]==']'&&stk.top()=='<')){
				flag=true;
				capBrcC++;
				break;
			} else if((s[i]=='>'&&stk.top()=='(')||(s[i]=='>'&&stk.top()=='{')||(s[i]=='>'&&stk.top()=='[')){
				flag=true;
				angBrcC++;
				break;
			}
			else{
				if(!stk.empty()){
					stk.pop();
				}
			}
		}
		if(!flag){
			vector<char>temp_;
			while(!stk.empty()){
				temp_.push_back(stk.top());
				stk.pop();
			}
			ll currScore=0;
			for(auto &vals: temp_){
				currScore*=5;
				currScore+=(vals=='['?2:vals=='('?1:vals=='{'?3:vals=='<'?4:0);
				//cout<<vals<<" ";
			}
			res.push_back(currScore);
		}
		//cout<<endl;
	}
	sort(res.begin(), res.end());
	int n_=res.size();
	ans=res[n_/2];
	for(auto &vals: res)
		cout<<vals<<" ";
	cout<<endl;
	cout<<"-------\n";
	cout<<ans;
}
