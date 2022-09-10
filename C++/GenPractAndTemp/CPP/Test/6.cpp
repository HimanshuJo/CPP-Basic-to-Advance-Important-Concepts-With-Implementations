#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include <fstream>
using namespace std;

fstream tmpfil;

void returnNwVec(vector<int>&vec, vector<int>&in){
    tmpfil<<"orig in ";
    for(auto &vals: in){
        tmpfil<<vals<<" ";
    }
    tmpfil<<endl;
    int sz=in.size();
    vector<int>temp(sz, 0);
    for(int i=0; i<sz; ++i){
        temp[i]=in[vec[i]];
    }
    tmpfil<<"new temp ";
    for(auto &vals: temp){
        tmpfil<<vals<<" ";
    }
    tmpfil<<endl;
    for(int i=1; i<sz; ++i){
        if(temp[i]<=temp[i-1]){
            while(temp[i]<=temp[i-1]){
                temp[i]++;
            }
            while(temp[i]%in[vec[i]]!=0){
                temp[i]++;
            }
        }
    }
    tmpfil<<"changed permu ";
    for(auto &vals: temp){
        tmpfil<<vals<<" ";
    }
    tmpfil<<endl;
    swap(vec, temp);
}

void dfs(vector<int>&vec, vector<vector<int>>&res, vector<int>curpermu, int n){
	if(curpermu.size()==n){
		res.push_back(curpermu);
	} else{
		for(int i=0; i<n; ++i){
			auto it=find(curpermu.begin(), curpermu.end(), vec[i]);
			if(it!=curpermu.end()) continue;
			curpermu.push_back(vec[i]);
			dfs(vec, res, curpermu, n);
			curpermu.pop_back();
		}
	}
}
vector<vector<int>> genallpermus(vector<int>&vec, int n){
    vector<vector<int>>res;
    vector<int>curpermu;
    dfs(vec, res, curpermu, n);
    return res;
}

int main(){
    tmpfil.open("sample.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    while(t--){
        int n;
        cin>>n;
        vector<int>in(n, 0);
        for(int i=0; i<n; ++i){
            cin>>in[i];
        }
        vector<int>intemp;
        for(int i=0; i<n; ++i){
            intemp.push_back(i);
        }
        vector<vector<int>>allpermus=genallpermus(intemp, n);
        long long res=LONG_MAX;
        for(auto &entries: allpermus){
            tmpfil<<"curr permu ";
            for(auto &vals: entries){
                tmpfil<<vals<<" ";
            }
            tmpfil<<endl;
            returnNwVec(entries, in);
            long long cursm=0;
            for(auto &vals: entries){
                cursm+=vals;
            }
            tmpfil<<"cursm "<<cursm<<endl;
            tmpfil<<"-------\n";
            res=min(res, cursm);
        }
        cout<<res<<"\n";
    }
    tmpfil.close();
}