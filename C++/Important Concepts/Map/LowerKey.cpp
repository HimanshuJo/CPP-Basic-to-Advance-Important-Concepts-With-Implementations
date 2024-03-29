// Retrieve strictly lower key than the specified key
#include<iostream>
#include<map>
using namespace std;

int main(){
    map<int, int>mp;
    for(int i=1; i<=10; i+=2)
        mp[i]=i;
    int ky=4;
    auto it=mp.upper_bound(ky);
    if(it==mp.end()){
        if(mp.rbegin()!=mp.rend()&&mp.rbegin()->first!=ky)
            cout<<mp.rbegin()->first<<endl;
        else cout<<"Doesn't exist "<<endl;
    } else{
        --it;
        if(it->first!=ky)
            cout<<it->first<<endl;
        else cout<<"Doesn't exist "<<endl;
    }
}