#include<iostream>
#include<vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int N;
		cin>>N;
		vector<int>in(N);
		vector<int>count(2);
		for(int i=0; i<N; ++i){
			cin>>in[i];
			if(in[i]%2==0){
				count[0]++;
			} else{
				count[1]++;
			}
		}
		int countZ=count[0]%4, countOn=count[1]%4;
		if(countOn==0){
			cout<<"Alice"<<endl;
		} else if(countOn==2){
			cout<<"Bob"<<endl;
		} else if(countOn==3){
			cout<<"Alice"<<endl;
		} else{
			if(countZ%2==0){
				cout<<"Bob"<<endl;
			} else{
				cout<<"Alice"<<endl;
			}
		}
	}
}