#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    string res="";
    if(s.length()>2){
        res+=s[s.length()-3];
        res+=s[s.length()-2];
        res+=s[s.length()-1];
        if(res.compare("ist")==0){
            cout<<"ist"<<"\n";
        } else{
            cout<<"er\n";
        }
    } else{
        cout<<"er\n";
    }
}