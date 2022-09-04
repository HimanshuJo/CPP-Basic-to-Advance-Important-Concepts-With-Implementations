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
			if(A[0]>B[0]) swap(A, B);
			bool flag=false;
			if(A[n-1]>B[n-1]){
				cout<<"NO\n";
			} else{
				for(int i=n-1; i>=0; --i){
					if(i==n-1&&A[i]!=B[i]){
						if(A[0]<B[i]){
							if(i!=1&&B[1]>=A[n-1]){
							} else{
								flag=true;
								break;
							}
						} else{
							A[i]=max(B[0], B[n-1]);
						}
					} else{
						if(A[i]!=B[i]){
							if(B[i]<=A[i+1]){
							} else{
								flag=true;
								break;
							}
						}
					}
					if(flag) break;
					else{
						A[i]=B[i];
					}
					for(auto &vals: A){
						cout<<vals<<" ";
					}
					cout<<"\n-------\n";
				}
				if(!flag){
					cout<<"YES\n";
				} else{
					cout<<"NO\n";
				}
			}
		}
	}
}