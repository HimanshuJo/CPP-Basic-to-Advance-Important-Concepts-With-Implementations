/*
Best way to generate a target sum from an array of numbers. 
Numbers of an array can be used any number of times
*/

#include<vector>
#include<map>
#include<iostream>
using namespace std;

vector<vector<int>> allSum(vector<int>&numbers, int targetSum, int n){
	if(targetSum==0) return {{}};
	if(targetSum<0) return {{INT_MAX}};
	vector<vector<int>>allcombs;
	for(auto &vals: numbers){
		int remain=targetSum-vals;
		vector<vector<int>>remainCombo=allSum(numbers, remain, n);
        if(remainCombo.size()==1&&remainCombo[0][0]==INT_MAX) continue;
        for(auto &entries: remainCombo){
            entries.push_back(vals);
        }
        for(auto &entries: remainCombo){
            allcombs.push_back(entries);
        }
	}
	return allcombs;
}

int main(){
	vector<int>numbers{1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	map<int, vector<int>>memo;
	int targetSum=12;
    int n=6;
	vector<vector<int>>ans1=allSum(numbers, targetSum, n);
	for(auto &vals: ans1){
		for(auto &nums: vals){
            cout<<nums<<" ";
        }
        cout<<endl;
	}
}
