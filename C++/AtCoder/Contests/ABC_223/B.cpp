#include<bits/stdc++.h>
using namespace std;

string rotateLeft(string &s, int d)
{
    reverse(s.begin(), s.begin()+d);
    reverse(s.begin()+d, s.end());
    reverse(s.begin(), s.end());
    return s;
}

string rotateRight(string &s, int d)
{
   rotateLeft(s, s.length()-d);
   return s;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    if(s.length()==1){
        cout<<s<<"\n";
        cout<<s<<"\n";
        return 0;
    }
    string cpy=s;
    string cpylft=s;
    string cpyrght=s;
    vector<string>lftShifts;
    vector<string>rghtShifts;
    for(int i=0; i<s.length(); ++i){
        lftShifts.push_back(rotateLeft(s, i));
        s=cpylft;
    }
    for(int i=0; i<cpy.length(); ++i){
        rghtShifts.push_back(rotateRight(cpy, i));
        cpy=cpyrght;
    }
    vector<string>res;
    vector<string>res2;
    sort(lftShifts.begin(), lftShifts.end());
    sort(rghtShifts.begin(), rghtShifts.end());
    res.push_back(lftShifts[0]);
    res.push_back(rghtShifts[0]);
    res2.push_back(lftShifts[lftShifts.size()-1]);
    res2.push_back(rghtShifts[rghtShifts.size()-1]);
    sort(res.begin(), res.end());
    sort(res2.begin(), res2.end());
    cout<<res[0]<<"\n";
    cout<<res2[1]<<"\n";
}