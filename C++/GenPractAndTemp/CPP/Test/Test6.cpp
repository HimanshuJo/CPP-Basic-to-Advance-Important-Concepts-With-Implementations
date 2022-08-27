#include<iostream>
#include<vector>
#include<queue>
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
        vector<int>in1(n);
        for(int i=0; i<n; ++i){
            cin>>in1[i];
        }

        vector<int>in2(n);
        for(int i=0; i<n; ++i){
            cin>>in2[i];
        }
        vector<int>ans1(n, 0);
        vector<int>ans2(n, 0);
        if(in1[0]>in2[0]) swap(in1, in2);
        if(in1!=in2){
            for(int i=0; i<n; ++i){
                auto it=lower_bound(in2.begin(), in2.end(), in1[i]);
                int idx=it-in2.begin();
                if(idx<=n-1){
                    ans1[i]=in2[idx]-in1[i];
                }
            }
            for(int i=0; i<n; ++i){
                if(in1[n-1]<in2[0]){
                    ans2[i]=in2[n-1]-in1[i];
                } else{
                    auto it=upper_bound(in2.begin(), in2.end(), in1[i]);
                    int idx=it-in2.begin();
                    if(idx<=n-1){
                        if(in2[idx]-in1[i]==ans1[i]){
                            if(idx+1<=n-1){
                                ans2[i]=in2[idx+1]-in1[i];
                            } else{
                                ans2[i]=in2[idx]-in1[i];
                            }
                        } else{
                            ans2[i]=in2[idx]-in1[i];
                        }
                    }
                }
            }
        }
        for(auto &vals: ans1){
            cout<<vals<<" ";
        }
        cout<<"\n";
        for(auto &vals: ans2){
            cout<<vals<<" ";
        }
        cout<<"\n";
	}
}