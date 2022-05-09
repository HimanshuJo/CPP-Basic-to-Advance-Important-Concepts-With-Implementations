#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int lst=s[s.length()-1]-'0';
    if (lst>=0&&lst<=2){
        if (s.length()==4){
            int x=stoi(s.substr(0, 2));
            cout<<x<<"-"<<"\n";
        } else {
            cout<<s[0]<<"-"<<"\n";
        }
    } else if (lst>=3&&lst<=6){
        if (s.length()==4){
            int x=stoi(s.substr(0, 2));
            cout<<x<<"\n";
        } else {
            cout<<s[0]<<"\n";
        }
    } else if (lst>=7&&lst<=9){
        if (s.length()==4){
            int x=stoi(s.substr(0, 2));
            cout<<x<<"+"<<"\n";
        } else {
            cout<<s[0]<<"+"<<"\n";
        }
    }
}