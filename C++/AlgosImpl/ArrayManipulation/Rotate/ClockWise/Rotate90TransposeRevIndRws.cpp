/*
	Rotating a matrix by 90 degree:

		first using swap and reverse the individual rows

		second using swapping and then using binary search for revering individual rows


*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rotate90ClockWiseTransposeAndReverse(vector<vector<int>>&vec){
    int N=vec.size();
    for(int i=0; i<N; ++i){
        for(int j=i+1; j<N; ++j){
            swap(vec[i][j], vec[j][i]);
        }
    }
    for(int i=0; i<N; ++i){
        reverse(vec[i].begin(), vec[i].end());
    }
}

void rotate90ClockWiseTransportAndReverse2(vector<vector<int>>&vec){
    int N=vec.size();
    for(int i=0; i<N; ++i){
        for(int j=i+1; j<N; ++j){
            swap(vec[i][j], vec[j][i]);
        }
    }
    for(int i=0; i<N; ++i){
        int low=0, high=N-1;
        while(low<high){
            swap(vec[i][low], vec[i][high]);
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
    vector<vector<int>>veccpy=vec;
    cout<<"-------*******-------"<<endl;
    rotate90ClockWiseTransposeAndReverse(vec);
    for(int i=0; i<4; ++i){
        for(int j=0; j<4; ++j){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"-------*******-------"<<endl;
    rotate90ClockWiseTransportAndReverse2(veccpy);
    for(int i=0; i<4; ++i){
        for(int j=0; j<4; ++j){
            cout<<veccpy[i][j]<<" ";
        }
        cout<<endl;
    }
}