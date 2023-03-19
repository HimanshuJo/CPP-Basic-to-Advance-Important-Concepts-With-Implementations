// Retrieve the key strictly higher than the specified key
#include<iostream>
#include<map>
using namespace std;

int main(){
    map<int, int>mp;
    for(int i=1; i<=10; i+=2)
    	mp[i]=i;
    int ky=10;
    auto it=mp.lower_bound(ky);
    if(it==mp.end()){
        cout<<"Doesn't exist "<<endl;
    } else{
        if(it->first==ky){
            ++it;
            if(it==mp.end()){
                cout<<"Doesn't exist "<<endl;
            } else {
                cout<<it->first<<endl;
            }
        } else cout<<it->first<<endl;
    }
}