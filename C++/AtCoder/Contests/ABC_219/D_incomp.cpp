#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

bool gbX=false;
bool gbY=false;

struct custComp{
    bool operator()(const pii &lhs, const pii &rhs){
        if(gbY==true){
            if(lhs.second!=rhs.second)
                return lhs.second<rhs.second;
            else{
                return lhs.first<rhs.first;
            }
        } else if(gbX==true){
            if(lhs.first!=rhs.first)
                return lhs.first<rhs.first;
            else{
                return lhs.second<rhs.second;
            }
        }
        if(lhs.first!=rhs.first)
            return lhs.first<rhs.first;
        else{
            return lhs.second<rhs.second;
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    int X, Y;
    cin>>X>>Y;
    if(X>Y){
        gbX=true;
    } else if(Y>X){
        gbY=true;
    }
    priority_queue<pii, vector<pii>, custComp>pq;
    for(int i=0; i<N; ++i){
        int ai, bi;
        cin>>ai>>bi;
        pq.push(make_pair(ai, bi));
    }
    int ans=0;
    bool flag=false;
    int tako=0, taika=0;
    while(!pq.empty()){
        int frst=pq.top().first;
        int sec=pq.top().second;
        tako+=frst, taika+=sec;
        ans++;
        if(tako>=X&&taika>=Y){
            flag=true;
            break;
        }
        pq.pop();
    }
    if(flag){
        gbX=false;
        gbY=false;
        cout<<ans;
    } else{
        gbX=false;
        gbY=false;
        cout<<-1;
    }
}