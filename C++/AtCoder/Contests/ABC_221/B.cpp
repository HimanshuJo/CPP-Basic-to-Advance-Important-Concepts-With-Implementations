#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string S, T;
    cin>>S>>T;
    bool possb=true;
    for(int i=0; i<S.length(); ++i){
        if(S[i]!=T[i]){
            if(S[i]==T[i+1]&&S[i+1]==T[i]&&i+1<S.length()){
                swap(S[i], S[i+1]);
                if(S.compare(T)==0){
                    possb=true;
                    break;
                }
            } else possb=false;
        }
    }
    if(!possb) cout<<"No";
    else cout<<"Yes";
}