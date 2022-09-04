#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int>A(n);
		vector<int>B(n);
		for(int i=0; i<n; ++i){
			cin>>A[i];
		}
		for(int i=0; i<n; ++i){
			cin>>B[i];
		}
		if(A==B){
			cout<<"YES\n";
		} else{
            if(B[0]>A[0]) swap(A, B);
			bool flag=false;
            if(A[0]==A[1]||(B[0]==B[1])){
                for(int i=0; i<n; ++i){
                    if(i+1<=n-1){
                        if(A[i]==B[i]||(B[i]<=B[i+1]+1)){}
                        else{
                            flag=true;
                            break;
                        }
                    }
                }
            } else flag=true;
            if(!flag){
                cout<<"YES\n";
            } else{
                cout<<"NO\n";
            }
		}
	}
}