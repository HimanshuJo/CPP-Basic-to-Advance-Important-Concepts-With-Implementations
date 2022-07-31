#include<vector>
#include<iostream>
using namespace std;

int main(){
	vector<int>in{1, 2, 3, 4, 5, 6};
	auto itr=lower_bound(in.begin(), in.end(), 7);
	int idx=itr-in.begin();
	cout<<idx<<endl;
}