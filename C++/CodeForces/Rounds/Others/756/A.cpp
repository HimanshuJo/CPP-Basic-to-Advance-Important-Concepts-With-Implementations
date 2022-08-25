#include<iostream>
#include<vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n%2==0){
			cout<<"0\n";
		} else if(n%2!=0&&n<10){
			cout<<-1<<"\n";
		} else{
			bool flag=false;
			string tmp=to_string(n);
			if((tmp[0]-'0')%2==0){
				cout<<"1\n";
				continue;
			}
			int len=tmp.length();
			for(int i=0; i<len; ++i){
				if((tmp[i]-'0')%2==0){
					flag=true;
					break;
				}
			}
			if(flag) cout<<"2\n";
			else cout<<"-1\n";
		}
	}
}
