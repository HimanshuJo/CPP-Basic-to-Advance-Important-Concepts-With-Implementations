#include<bits/stdc++.h>
using namespace std;

int main(){
    int X;
    cin>>X;
    string ans{"No"};
    if(X>=100)
        cout<<(X%100==0?"Yes":ans)<<"\n";
    else cout<<ans;
}