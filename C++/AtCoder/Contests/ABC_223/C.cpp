#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    vector<vector<double>>vec;
    for(int i=0; i<N; ++i){
        double a, b;
        cin>>a>>b;
        vec.push_back({a, b});
    }
    vector<double>timeStamps;
    double totT=0.0;
    for(auto &vals: vec){
        double time=double(vals[0]/vals[1]);
        timeStamps.push_back(time);
    }
    for(auto &vals: timeStamps){
        totT+=vals;
    }
    totT/=2;
    double res=0;
    for(auto &vals: vec){
        res+=min(vals[0], totT*vals[1]);
        totT-=min(double (vals[0]/vals[1]), totT);
    }
    cout<<fixed<<setprecision(15);
    cout<<res<<"\n";
}