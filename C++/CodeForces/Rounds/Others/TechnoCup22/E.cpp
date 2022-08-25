#include<bits/stdc++.h>
using namespace std;

void dfs(int curr, int par, 
         vector<bool>&seen, 
         vector<vector<int>>&gr, 
         vector<vector<int>>&tree){
    seen[curr]=true;
    for(int next: gr[curr]){
        if(!seen[next]){
            tree[curr].push_back(next);
            tree[next].push_back(curr);
            dfs(next, curr, seen, gr, tree);
        }
    }    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    vector<int>in;
    in.push_back(n);
    in.push_back(m);
    vector<vector<int>>gr(n+1);
    vector<vector<int>>tree(n+1);
    for(int i=0; i<m; ++i){
        int x, y;
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
        in.push_back(x);
        in.push_back(y);
    }
    vector<int>parity(n+1);
    int q;
    cin>>q;
    in.push_back(q);
    vector<int>queries(2*q);
    for(int i=1; i<2*q; i+=2){
        int a, b;
        cin>>a>>b;
        queries[i-1]=a;
        queries[i]=b;
        parity[a]^=1;
        parity[b]^=1;
        in.push_back(a);
        in.push_back(b);
    }
    int cntExtr=0;
    for(int x: parity){
        cntExtr+=x;
    }
    if(cntExtr>0){
        cout<<"No\n";
        cout<<cntExtr/2<<"\n";
        return 0;
    }
    vector<bool>seen(n+1);
    for(int i=0; i<n; ++i){
        seen[i+1]=false;
    }
    dfs(1, 0, seen, gr, tree);
    cout<<"Yes\n";
    string res="";
    for(int i=1; i<2*q; i+=2){
        int a=queries[i-1];
        int b=queries[i];
        vector<int>parents(n+1);
        queue<int>q;
        q.push(a);
        parents[a]=-1;
        bool flag=false;
        while(q.size()>0){
            int curr=q.front();
            q.pop();
            for(int next: tree[curr]){
                if(parents[next]==0){
                    parents[next]=curr;
                    if(next==b){
                        flag=true;
                        break;
                    }
                    if(!flag)
                        q.push(next);
                }
            }
            if(flag) break;
        }
        vector<int>path;
        int curr=b;
        while(curr!=a){
            path.push_back(curr);
            curr=parents[curr];
        }
        path.push_back(a);
        reverse(path.begin(), path.end());
        res+=to_string(path.size())+"\n";
        for(int x: path){
            res+=to_string(x)+" ";
        }
        res+="\n";
    }
    cout<<res;
}