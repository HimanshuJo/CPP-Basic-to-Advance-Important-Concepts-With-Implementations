#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

bool isValid(vector<int>&vec, int curval){
    int sz=vec.size();
    vector<int>temp;
    temp.push_back(0);
    int bgn=0;
    for(int i=0; i<sz; ++i){
        if(vec[i]>bgn){
            temp.push_back(vec[i]+bgn);
            bgn=vec[i]+bgn;
        } else{
            temp.push_back(0);
            bgn=0;
        }
    }
    return temp.back()>=curval;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>ans(n, 0), ans2(n, 0);
        ans[n-1]=n;
        ans2[n-1]=n;
        for(int i=n-1; i>=1; --i){
            ans[n-2]=i;
            int nwnum=1;
            while(nwnum==i){
                nwnum++;
            }
            for(int x=0; x<n-2; ++x){
                if(nwnum!=i){
                    ans[x]=nwnum;
                } else{
                    nwnum++;
                    ans[x]=nwnum;
                }
                nwnum++;
            }
            int curval=ans[n-1]+ans[n-2];
            if(isValid(ans, curval)){
                break;
            }
        }
        int curfnval=ans[n-1]+ans[n-2];
        for(int i=n-1; i>=1; --i){
            ans2[n-2]=i;
            int nwnum=1;
            while(nwnum==i){
                nwnum++;
            }
            for(int x=n-3; x>=0; --x){
                if(nwnum!=i){
                    ans2[x]=nwnum;
                } else{
                    nwnum++;
                    ans2[x]=nwnum;
                }
                nwnum++;
            }
            int curval=ans2[n-1]+ans2[n-2];
            if(isValid(ans2, curval)){
                break;
            }
        }
        int secfnval=ans2[n-1]+ans2[n-2];
        if(secfnval>curfnval){
            swap(ans, ans2);
        }
        for(auto &vals: ans){
            cout<<vals<<" ";
        }
        cout<<"\n";
    }
}