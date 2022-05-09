#include<bits/stdc++.h>
using namespace std;

void funcRotate(vector<vector<int>>&vec){
	int N=vec.size();
	int n=N;
	int strt=0;
	int l1=strt, l2=strt, t1=strt, t2=strt, r1=strt, r2=strt, b1=strt, b2=strt;
	for(int i=0; i<N/2; ++i){
		t1=strt, t2=strt;
		r1=strt, r2=n-1;
		b1=n-1, b2=n-1;
		l1=n-1, l2=strt;
		for(int ii=strt; ii<n-1; ++ii){
			int temp=vec[t1][t2];
			vec[t1][t2]=vec[l1][l2];
			vec[l1][l2]=vec[b1][b2];
			vec[b1][b2]=vec[r1][r2];
			vec[r1][r2]=temp;
			t2++, l1--, b2--, r1++;
		}
		strt++;
		n--;
	}
	int N_=N-1;
	// swap entries in columns
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j){
			swap(vec[j][i], vec[N_-j][i]);
			if(j==(N/2)-1) break;
		}
	}
	// swap entries in a particular rows
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j){
			swap(vec[i][j], vec[i][N_-j]);
			if(j==(N/2)-1) break;
		}
	}
}

int main(){
	vector<vector<int>>vec={ { 134, 42, 333, 414 },
		{ 54, 66, 237, 458 },
		{ 69, 10, 131, 312 },
		{ 13, 14, 125, 416 } };
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
