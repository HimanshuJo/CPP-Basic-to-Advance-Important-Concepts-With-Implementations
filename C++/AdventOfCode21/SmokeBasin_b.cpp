#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>
using namespace std;
using ll=long long;

bool isNotValid(int temp[][100], int i, int j){
  return (j<0||j>=100||i<0||i>=100||temp[j][i]==9||temp[j][i]==-1);
}

void dfs(int temp[][100], vector<ll>&groups, int i, int j){
  if(isNotValid(temp, i, j)) return;
  temp[j][i]=-1;
  groups[groups.size()-1]+=1;
  dfs(temp, groups, i+1, j);
  dfs(temp, groups, i-1, j);
  dfs(temp, groups, i, j+1);
  dfs(temp, groups, i, j-1);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int temp[100][100];
  for(int i=0; i<100; ++i){
    string in;
    cin>>in;
    for(int x=0; x<in.length(); ++x){
        temp[i][x]=in[x]-'0';
    }
  }
  vector<ll>groups;
  for(int i=0; i<100; ++i){
    for(int j=0; j<100; ++j){
      groups.push_back(0);
      dfs(temp, groups, j, i);
    }
  }
  sort(groups.begin(), groups.end(), greater<ll>());
  cout<<groups[0]*groups[1]*groups[2]<<"\n";
}
