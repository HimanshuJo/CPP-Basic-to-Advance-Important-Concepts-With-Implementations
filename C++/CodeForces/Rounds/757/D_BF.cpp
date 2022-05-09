#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>>res;

int gcd(int A, int B){
    if(B==0) return A;
    return gcd(B, A%B);
}

void dfs(vector<int>&tmp, vector<int>&currsub, vector<bool>&visited){
    if(currsub.size()>tmp.size()) return;
    if(currsub.size()==tmp.size()) return;
    for(int i=0; i<tmp.size(); ++i){
        if(!visited[i]){
            if(currsub.size()==0){
                visited[i]=true;
                vector<int>nxtSub;
                nxtSub.push_back(tmp[i]);
                dfs(tmp, nxtSub, visited);
                visited[i]=false;
            }
            else if(currsub.size()==tmp.size()-1){
                currsub.push_back(tmp[i]);
                res.push_back(currsub);
            }
            else{
                visited[i]=true;
                vector<int>nxtSub_;
                for(auto &vals: currsub)
                    nxtSub_.push_back(vals);
                nxtSub_.push_back(tmp[i]);
                dfs(tmp, nxtSub_, visited);
                visited[i]=false;
            }
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int x;
	cin>>x;
	vector<int>in(x);
	for(int i=0; i<x; ++i){
		cin>>in[i];
	}
	int n=in.size();
    vector<bool>visited(n, false);
    vector<int>subset;
    dfs(in, subset, visited);
    int maxx=INT_MIN;
    for(auto &vals: res){
        int sm=0;
        for(int i=0; i<vals.size(); ++i){
            int currgcd=vals[i];
            for(int j=0; j<=i; ++j){
                currgcd=gcd(currgcd, vals[j]);
            }
            sm+=currgcd;
        }
        maxx=max(sm, maxx);
    }
    cout<<(maxx==INT_MIN?in[0]:maxx)<<endl;
}
