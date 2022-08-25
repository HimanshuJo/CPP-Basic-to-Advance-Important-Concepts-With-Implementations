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
		long long n, k, b, s;
		cin>>n>>k>>b>>s;
		vector<long long>ans(n, 0);
		long long tochk=k*b;
		long long lfttochk=s-tochk;
		long long lftsz=n-1, szdv=-1;
		if(lftsz>=1)
			szdv=ceil((double)lfttochk/lftsz);
		if(szdv>k||szdv<0||(s==0&&b>=1)){
			cout<<-1<<endl;
		} else if(s==1&&b==1&&k!=1){
			cout<<-1<<endl;
		} else{
			long long smtochk=0;
			ans[0]=tochk;
			smtochk=ans[0];
			for(int i=1; i<n; ++i){
				ans[i]=szdv;
				smtochk+=ans[i];
				if(smtochk+szdv>=s) break;
			}
			if(smtochk!=s){
				if(smtochk<s){
					if((ans[0]+1)/k>b){
						break;
					}
					ans[0]++;
					smtochk++;
					if(smtochk!=s){
						for(int i=1; i<n; ++i){
							ans[i]++;
							if(ans[i]>k){
								break;
							}
							smtochk++;
							if(smtochk==s) break;
						}
						if(smtochk!=s){
							cout<<-1<<endl;
							continue;
						}
					}
				} else{
					for(int i=1; i<n; ++i){
						if(ans[i]>=1){
							ans[i]--;
							smtochk--;
							if(smtochk==s) break;
						}
					}
					if(smtochk!=s){
						cout<<-1<<endl;
						continue;
					}
				}
			}
			for(auto &vals: ans){
				cout<<vals<<" ";
			}
			cout<<endl;
		}
	}
}