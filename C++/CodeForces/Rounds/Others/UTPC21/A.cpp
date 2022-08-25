#include<bits/stdc++.h>
using namespace std;

int main(){
		int n; 
		cin>>n;
		string toChk=to_string(n);
		bool flag=false;
		for(int i=0; i<toChk.length(); ++i){
				if((toChk[i]-'0')%2==0){
						flag=true;
						break;
				}
		}
		if(!flag){
				cout<<"HAPPY";
		} else{
				cout<<"SAD";
		}
}

				
