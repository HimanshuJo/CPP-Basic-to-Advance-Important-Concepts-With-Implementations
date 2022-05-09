#include<bits/stdc++.h>
using namespace std;

void funcRotate(vector<vector<int>>&mat){
	int n=mat.size();
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			swap(mat[i][j], mat[j][i]);
	for (int i = 0; i < n; i++) {
		int low = 0, high = n - 1;
		while (low < high) {
			swap(mat[i][low], mat[i][high]);
			low++;
			high--;
		}
	}
}

int main(){
	vector<vector<int>>vec(4, vector<int>(4));
	int cnt=1;
	for(int i=0; i<4; ++i){
		for(int j=0; j<4; ++j){
			vec[i][j]=cnt++;
		}
	}
	for(int i=0; i<4; ++i){
		for(int j=0; j<4; ++j){
			cout<<vec[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"****----****\n";
	funcRotate(vec);
	for(int i=0; i<4; ++i){
		for(int j=0; j<4; ++j){
			cout<<vec[i][j]<<" ";
		}
		cout<<endl;
	}
}
