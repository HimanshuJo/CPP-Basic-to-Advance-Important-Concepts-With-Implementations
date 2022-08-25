#include<iostream>
#include<vector>
#include<map>
#include<algorithm> 
using namespace std;

bool isPalindrome(vector<int>&vec){
	int n=vec.size();
	for(int i=0; i<n/2; ++i){
		if(vec[i]!=vec[n-i-1]){
			return false;
		}
	}
	return true;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int>in(n);
		for(int i=0; i<n; ++i){
			cin>>in[i];
		}
		if(isPalindrome(in)){
			cout<<"YES\n";
			continue;
		} else{
			vector<int>temp=in;
			int todel1=0;
			int todel2=0;
			for(int i=0; i<temp.size()/2; ++i){
				if(temp[i]!=temp[n-i-1]){
					todel1=temp[i];
					todel2=temp[n-i-1];
					break;
				}
			}
			temp.erase(remove(temp.begin(), temp.end(), todel1), temp.end());
			if(isPalindrome(temp)){
				cout<<"YES\n";
				continue;
			} else{
				in.erase(remove(in.begin(), in.end(), todel2), in.end());
				if(isPalindrome(in)){
					cout<<"YES\n";
					continue;
				}
			}
			cout<<"NO\n";
		}
	}
}
