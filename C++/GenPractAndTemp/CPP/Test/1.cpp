#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int N;
		cin>>N;
		cout<<((N-3)/3)-1<<endl;
	}
}