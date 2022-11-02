/*
    Generate all the permutations of an array where in the array duplicates numbers are allowed
    E.g. arr = {1, 2, 5, 5}
         
         Permutations:
            1 2 5 5 
            1 5 2 5 
            1 5 5 2 
            2 1 5 5 
            2 5 1 5 
            2 5 5 1 
            5 1 2 5 
            5 1 5 2 
            5 2 1 5 
            5 2 5 1 
            5 5 1 2 
            5 5 2 1 

*/

#include<iostream>
#include<vector>
#include<set>
using namespace std;

void dfs(vector<int>&in, vector<vector<int>>&res, vector<int>&curr, int sz, set<int>&seen){
    if(curr.size()==in.size()){
        res.push_back(curr);
    } else{
        for(int i=0; i<sz; ++i){
            auto it=seen.find(i);
            if(it!=seen.end()){
                continue;
            } else if(i>0&&in[i]==in[i-1]&&seen.find(i-1)==seen.end()){
                continue;
            } else{
                seen.insert(i);
                curr.push_back(in[i]);
                dfs(in, res, curr, sz, seen);
                curr.pop_back();
                auto itr=seen.find(i);
                seen.erase(itr);
            }
        }
    }
}

vector<vector<int>> genAllPermutationsDuplicatesAllowed(vector<int>&in){
    vector<vector<int>>res;
    vector<int>curr;
    int sz=in.size();
    set<int>seen;
    dfs(in, res, curr, sz, seen);
    return res;
}

int main(){
    vector<int>in{1, 2, 5, 5};
    vector<vector<int>>allPermutationsDuplicatesAllowed=genAllPermutationsDuplicatesAllowed(in);
    for(auto &entries: allPermutationsDuplicatesAllowed){
        for(auto &vals: entries){
            cout<<vals<<" ";
        }
        cout<<endl;
    }
}