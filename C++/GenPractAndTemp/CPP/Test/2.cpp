#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<queue>
#include<algorithm>
#define endl "\n"
using ll=long long;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n, x, y;
        cin>>n>>x>>y;
        int curmax=max(x, y);
        int curmin=min(x, y);
        if((x==0&&y==0)||((n-1)%curmax!=0)||curmin!=0){
            cout<<-1<<endl;
        } else{
            vector<int>ans;
            int bgn=1;
            int count=max(x, y);
            while(true){
                for(int i=0; i<count; ++i){
                    ans.push_back(bgn);
                    if(ans.size()==n-1) break;
                }
                if(ans.size()==n-1) break;
                bgn=ans.size()+2;
            }
            for(auto &vals: ans){
                cout<<vals<<" ";
            }
            cout<<endl;
        }
    }
}