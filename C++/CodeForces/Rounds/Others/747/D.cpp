#include<bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> pll;
vector<vector<pll>>adj;
int c[2];
int colour[700005];
bool flag;
int n;

void dfs(int idx){
    c[colour[idx]]+= (idx <= n);
    for(auto x:adj[idx]){
        if(colour[x.first] == -1){
            colour[x.first] = colour[idx] ^ x.second;
            dfs(x.first);
        }
        else if(colour[x.first] != (colour[idx] ^ x.second)){
            ///impossible
            flag = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int m;
        cin>>n>>m;
        adj.assign(n+m+5, vector<pll>());
        for(int i=0; i<n+m+5; ++i){
            colour[i]=-1;
        }
        int tmp=n+1;
        for(int i=0; i<m; ++i){
            int a, b;
            string c;
            cin>>a>>b>>c;
            if(c=="crewmate"){
                adj[a].push_back(pll(tmp, 1));
                adj[tmp].push_back(pll(a, 1));
                adj[tmp].push_back(pll(b, 1));
                adj[b].push_back(pll(tmp, 1));
                tmp++;
            } else{
                adj[a].push_back(pll(b, 1));
                adj[b].push_back(pll(a, 1));
            }
        }
        int ans=0;
        flag=true;
        for(int i=1; i<n+1; ++i){
            if(colour[i]==-1){
                colour[i]=0;
                c[0]=c[1]=0;
                dfs(i);
                ans+=max(c[0], c[1]);
            }
        }
        if(!flag){
            ans=-1;
        }
        cout<<ans<<"\n";
    }
}

