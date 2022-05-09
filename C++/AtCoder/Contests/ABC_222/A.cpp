#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    string res="";
    char ch='0';
    res+=to_string(N);
    if(res.size()!=4){
        while(res.size()!=4){
            res.insert(res.begin(), ch);
        }
    }
    cout<<res;
}