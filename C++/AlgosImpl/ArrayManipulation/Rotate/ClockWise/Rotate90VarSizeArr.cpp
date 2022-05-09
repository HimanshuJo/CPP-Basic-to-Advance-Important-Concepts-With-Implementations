#include<bits/stdc++.h>
using namespace std;

void funcRotate(vector<vector<int>>&vec){
	int N=vec.size();
	int n=N;
	int strt=0;
	int left1=strt, left2=strt, top1=strt, top2=strt, right1=strt, right2=strt, bottom1=strt, bottom2=strt;
	for(int i=0; i<N/2; ++i){
		top1=strt, top2=strt;
		right1=strt, right2=n-1;
		bottom1=n-1, bottom2=n-1;
		left1=n-1, left2=strt;
		for(int ii=strt; ii<n-1; ++ii){
			int temp=vec[top1][top2];
			vec[top1][top2]=vec[left1][left2];
			vec[left1][left2]=vec[bottom1][bottom2];
			vec[bottom1][bottom2]=vec[right1][right2];
			vec[right1][right2]=temp;
			left1--, top2++, right1++, bottom2--; 
		}
		strt++;
		n--;
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
