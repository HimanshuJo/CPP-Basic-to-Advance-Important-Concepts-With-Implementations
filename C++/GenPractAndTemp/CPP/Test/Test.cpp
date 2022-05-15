#include<iostream>
#include<vector>
#include<climits>
#define INF INT_MAX
using namespace std;

int main(){
	vector<int>in{84,40,84,40};
	int temp=84;
	vector<int>res;
	for(auto &vals: in){
		int curr=temp&vals;
		if(curr!=0){
			res.push_back(vals);
			temp=temp&vals;
		}
	}
	for(auto &vals: res)
	cout<<vals<<endl;
}