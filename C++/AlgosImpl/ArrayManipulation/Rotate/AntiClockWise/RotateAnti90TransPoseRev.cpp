/*
    Rotate an array 90 degree anti clockwise.

    In essence, all the rows in the array should become column and all the columns should automatically be converted
    to rows in reverse order but in the left direction.

    E.g. Original array:

            1 2 3 4
            5 6 7 8
            9 10 11 12
            13 14 15 16

        Rotated array:

            4 8 12 16
            3 7 11 15
            2 6 10 14
            1 5 9  13
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void transpose(vector<vector<int>>&vec){
    int rws=vec.size(), cols=vec[0].size();
    for(int i=0; i<rws; ++i){
        for(int j=i; j<cols; ++j){
            swap(vec[i][j], vec[j][i]);
        }
    }
}

void reverseIndividualColumns(vector<vector<int>>&vec){
    int cols=vec[0].size();
    int rws=vec.size();
    for(int i=0; i<cols; ++i){
        int left=0, right=rws-1;
        while(left<right){
            swap(vec[left][i], vec[right][i]);
            left++, right--;
        }
    }
}

void rotate90AntiClockWise(vector<vector<int>>&vec){
    transpose(vec);
    cout<<"After matrix transpose "<<endl;
    int rws=vec.size(), cols=vec[0].size();
    for(int i=0; i<rws; ++i){
        for(int j=0; j<cols; ++j){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"-------*******-------"<<endl;
    reverseIndividualColumns(vec);
}

int main(){
    int count=1;
    vector<vector<int>>vec(4, vector<int>(4, 0));
    for(int i=0; i<4; ++i){
        for(int j=0; j<4; ++j){
            vec[i][j]=count;
            count++;
        }
    }
    for(int i=0; i<4; ++i){
        for(int j=0; j<4; ++j){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    rotate90AntiClockWise(vec);
    cout<<"Final Matrix"<<endl;
    for(int i=0; i<4; ++i){
        for(int j=0; j<4; ++j){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
}