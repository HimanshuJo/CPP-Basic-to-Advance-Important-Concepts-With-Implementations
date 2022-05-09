#include<bits/stdc++.h>
using namespace std;

int checkWinner(char A, char B){
    if(A==B) return -1;
    if(A=='G'&&B=='C') return 0;
    if(A=='C'&&B=='P') return 0;
    if(A=='P'&&B=='G') return 0;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin>>N>>M;
    pair<int, int>rank[2*N];
    string S[2*N];
    for(int i=0; i<=2*N-1; ++i){
        cin>>S[i];
        rank[i]={0, i};
    }
    for(int j=0; j<=M-1; ++j){
        for(int i=0; i<=N-1; ++i){
            int a=rank[2*i].second;
            int b=rank[2*i+1].second;
            int k=checkWinner(S[a][j], S[b][j]);
            if(k!=-1){
                rank[2*i+k].first--;
            }
        }
        sort(rank, rank+2*N);
    }
    for(int i=0; i<=2*N-1; ++i){
        cout<<rank[i].second+1<<endl;
    }
}