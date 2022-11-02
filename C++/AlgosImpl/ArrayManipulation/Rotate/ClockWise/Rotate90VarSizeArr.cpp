/*
    Rotate an array 90 degree.

    In essence, all the rows in the array should become column and all the columns should automatically be converted
    to rows in reverse order.

    E.g. Original array:

            1 2 3 4
            5 6 7 8
            9 10 11 12
            13 14 15 16

        Rotated array:

            13 9 5 1
            14 10 6 2
            15 11 7 3
            16 12 8 4
*/

#include<iostream>
#include<vector>
using namespace std;

void rotate90ClockWise(vector<vector<int>>&vec){
    int totalRows=vec.size();
    int tempTotalRows=totalRows;
    int start=0;
    /*
        Initially:
            top1, top2 -> row(0), col(0)
            right1, right2 -> row(0), col(n-1)
            bottom1, bottom2 -> row(n-1), col(n-1)
            left1, left2 -> row(n-1), col(0)
    */
   int top1=0, top2=0,
       right1=0, right2=tempTotalRows-1,
       bottom1=tempTotalRows-1, bottom2=tempTotalRows-1,
       left1=tempTotalRows-1, left2=0;
    for(int i=0; i<totalRows/2; ++i){
        top1=start, top2=start,
        right1=start, right2=tempTotalRows-1,
        bottom1=tempTotalRows-1, bottom2=tempTotalRows-1,
        left1=tempTotalRows-1, left2=start;
        for(int ii=start; ii<tempTotalRows-1; ++ii){
            int temp=vec[top1][top2];
            vec[top1][top2]=vec[left1][left2];
            vec[left1][left2]=vec[bottom1][bottom2];
            vec[bottom1][bottom2]=vec[right1][right2];
            vec[right1][right2]=temp;
            top2++, right1++, bottom2--, left1--;
        }
        start++;
        tempTotalRows--;
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
    cout<<"-------*******-------"<<endl;
    rotate90ClockWise(vec);
    for(int i=0; i<4; ++i){
        for(int j=0; j<4; ++j){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
}