#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int Q;
    cin>>Q;
    queue<int>q;
    priority_queue<int, vector<int>, greater<>>pq;
    for(int i=0; i<Q; ++i){
        int in;
        cin>>in;
        if(in==1){
            int x;
            cin>>x;
            q.push(x);
        } else if(in==2){
            if(pq.empty()){
                cout<<q.front()<<"\n";
                q.pop();
            } else{
                cout<<pq.top()<<"\n";
                pq.pop();
            }
        } else if(in==3){
            while(!q.empty()){
                pq.push(q.front());
                q.pop();
            }
        }
    }
}