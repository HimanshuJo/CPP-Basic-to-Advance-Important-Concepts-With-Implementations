#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<cmath>
using namespace std;
using ll=long long;

ll toDec(string str){
	int n=str.length();
	ll ans=0;
	int cnt=1;
	for(int i=0; i<n; ++i){
		ll temp=(pow(2, n-cnt))*(str[i]-'0');
		ans+=temp;
		cnt++;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n=1000;
	int toChk;
	int oxGenRt=0;
	int co2GenRt=0;
	vector<string>in(n);
	for(int i=0; i<n; ++i){
		cin>>in[i];
	}
	map<string, int>mp;
	for(auto &vals: in){
		string curr=vals;
		toChk=curr.length();
		for(int i=0; i<curr.length(); ++i){
			int tmp=i+1;
			string ky=to_string(tmp);
			if(curr[i]=='1'){
				ky+="1";
				mp[ky]++;
			} else{
				int tmp=i+1;
				ky+="0";
				mp[ky]++;
			}
		}
	}
	vector<string>temp;
	int bgn__=0;
	for(int i=bgn__; i<toChk; ++i){
		if(temp.size()!=0){
			for(auto &vals: temp){
				string curr=vals;
				toChk=curr.length();
				for(int i=0; i<curr.length(); ++i){
					int tmp=i+1;
					string ky=to_string(tmp);
					if(curr[i]=='1'){
						ky+="1";
						mp[ky]++;
					} else{
						int tmp=i+1;
						ky+="0";
						mp[ky]++;
					}
				}
			}
		}
		string ky1=to_string(i+1);
		ky1+="1";
		string ky2=to_string(i+1);
		ky2+="0";
		int val1=mp[ky1];
		int val2=mp[ky2];
		if(val1>val2){
			if(temp.size()==0){
				for(auto &vals: in){
					if(vals[i]=='1'){
						temp.push_back(vals);
					}
				}
			} else{
				vector<string>nwTemp;
				for(auto &vals: temp){
					if(vals[i]=='1'){
						nwTemp.push_back(vals);
					}
				}
				temp.clear();
				temp=nwTemp;
			}
			/*std::cout<<"***---***\n";
			for(auto &vals: temp)
				std::cout<<vals<<" ";
			std::cout<<endl;*/
		} else if(val2>val1){
			if(temp.size()==0){
				for(auto &vals: in){
					if(vals[i]=='0'){
						temp.push_back(vals);
					}
				}	
			} else{
				vector<string>nwTemp;
				for(auto &vals: temp){
					if(vals[i]=='0'){
						nwTemp.push_back(vals);
					}
				}
				temp.clear();
				temp=nwTemp;
			}
		} else if(val1==val2){
			if(temp.size()==0){
				for(auto &vals: in){
					if(vals[i]=='1'){
						temp.push_back(vals);
					}
				}
			} else{
				vector<string>nwTemp;
				for(auto &vals: temp){
					if(vals[i]=='1'){
						nwTemp.push_back(vals);
					}
				}
				temp.clear();
				temp=nwTemp;
			}
		}
		if(temp.size()==1) break;
		mp.clear();
		bgn__++;
	}
	/*std::cout<<"-------\n";*/
	ll ans1=toDec(temp[0]);
	std::cout<<ans1<<endl;
	bgn__=0;
	temp.clear();
	mp.clear();
	for(auto &vals: in){
		string curr=vals;
		toChk=curr.length();
		for(int i=0; i<curr.length(); ++i){
			int tmp=i+1;
			string ky=to_string(tmp);
			if(curr[i]=='1'){
				ky+="1";
				mp[ky]++;
			} else{
				int tmp=i+1;
				ky+="0";
				mp[ky]++;
			}
		}
	}
	for(int i=bgn__; i<toChk; ++i){
		if(temp.size()!=0){
			for(auto &vals: temp){
				string curr=vals;
				toChk=curr.length();
				for(int i=0; i<curr.length(); ++i){
					int tmp=i+1;
					string ky=to_string(tmp);
					if(curr[i]=='1'){
						ky+="1";
						mp[ky]++;
					} else{
						int tmp=i+1;
						ky+="0";
						mp[ky]++;
					}
				}
			}
		}
		string ky1=to_string(i+1);
		ky1+="1";
		string ky2=to_string(i+1);
		ky2+="0";
		int val1=mp[ky1];
		int val2=mp[ky2];
		if(val1>val2){
			if(temp.size()==0){
				for(auto &vals: in){
					if(vals[i]=='0'){
						temp.push_back(vals);
					}
				}
			} else{
				vector<string>nwTemp;
				for(auto &vals: temp){
					if(vals[i]=='0'){
						nwTemp.push_back(vals);
					}
				}
				temp.clear();
				temp=nwTemp;
			}
		} else if(val2>val1){
			if(temp.size()==0){
				for(auto &vals: in){
					if(vals[i]=='1'){
						temp.push_back(vals);
					}
				}	
			} else{
				vector<string>nwTemp;
				for(auto &vals: temp){
					if(vals[i]=='1'){
						nwTemp.push_back(vals);
					}
				}
				temp.clear();
				temp=nwTemp;
			}
		} else if(val1==val2){
			if(temp.size()==0){
				for(auto &vals: in){
					if(vals[i]=='0'){
						temp.push_back(vals);
					}
				}
			} else{
				vector<string>nwTemp;
				for(auto &vals: temp){
					if(vals[i]=='0'){
						nwTemp.push_back(vals);
					}
				}
				temp.clear();
				temp=nwTemp;
			}
		}
		if(temp.size()==1) break;
		mp.clear();
		bgn__++;
	}
	ll ans2=toDec(temp[0]);
	std::cout<<ans2<<endl;
	std::cout<<"\n-------\n";
	std::cout<<ans1*ans2<<endl;
}
