// Retrieve the least key greater than or equals to the key specified
#include<iostream>
#include<map>
using namespace std;

int main(){
    map<int, int>mp;
    for(int i=1; i<=10; i+=2)
    	mp[i]=i;
    auto it=mp.lower_bound(12);
    if(it==mp.end()){
        cout<<"Doesn't exist "<<endl;
    } else{
        cout<<it->first<<endl;
    }
}