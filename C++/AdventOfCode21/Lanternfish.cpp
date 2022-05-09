#include<iostream>
#include<vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n=300;
	vector<int>in;
	for(int i=0; i<n; ++i){
		int fsh;
		cin>>fsh;
		in.push_back(fsh);
	}
	int cnt=0;
	while(cnt!=80){
		for(int i=0; i<in.size(); ++i){
			if(in[i]==0){
				in[i]=6;
				in.push_back(9);
			} else{
				in[i]-=1;
			}
		}
		/*cout<<"\n-------\n";
		for(auto &vals: in){
			cout<<vals<<" ";
		}
		cout<<"\n-------\n";*/
		cnt++;
	}
	cout<<in.size()<<endl;
}
