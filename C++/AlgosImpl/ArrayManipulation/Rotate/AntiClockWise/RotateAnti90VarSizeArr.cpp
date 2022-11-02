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

void rotate90ClockWise(vector<vector<int>>&vec){
    int numRows=vec.size();
    int tempNumRows=numRows;
    int start=0;
    int top1=0, top2=0, 
        right1=0, right2=tempNumRows-1, 
        bottom1=tempNumRows-1, bottom2=tempNumRows-1,
        left1=tempNumRows-1, left2=0;
    for(int i=0; i<numRows/2; ++i){
        top1=start, top2=start,
        right1=start, right2=tempNumRows-1,
        bottom1=tempNumRows-1, bottom2=tempNumRows-1,
        left1=tempNumRows-1, left2=start;
        for(int j=start; j<tempNumRows-1; ++j){
            int temp=vec[top1][top2];
            vec[top1][top2]=vec[left1][left2];
            vec[left1][left2]=vec[bottom1][bottom2];
            vec[bottom1][bottom2]=vec[right1][right2];
            vec[right1][right2]=temp;
            top2++, right1++, bottom2--, left1--;
        }
        start++;
        tempNumRows--;
    }
}

void reverseIndividualRows(vector<vector<int>>&vec){
    int sz=vec.size();
    for(int i=0; i<sz; ++i){
        reverse(vec[i].begin(), vec[i].end());
    }
}

void reverseIndividualColumns(vector<vector<int>>&vec){
    int numCols=vec[0].size();
    int numRows=vec.size();
    for(int i=0; i<numCols; ++i){
        int left=0, right=numRows-1;
        while(left<right){
            swap(vec[left][i], vec[right][i]);
            left++, right--;
        }
    }
}

void rotate90AntiClockWise(vector<vector<int>>&vec){
    /*
        Reversing individual columns
    */
   reverseIndividualColumns(vec);
   /*
        Reversing individual rows
   */
  reverseIndividualRows(vec);
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
    cout<<"-------*******-------"<<endl;
    rotate90ClockWise(vec);
    cout<<"After rotating clock wise 90"<<endl;
    for(int i=0; i<4; ++i){
        for(int j=0; j<4; ++j){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"-------*******-------"<<endl;
    rotate90AntiClockWise(vec);
    cout<<"After rotating anti clock wise 90"<<endl;
    for(int i=0; i<4; ++i){
        for(int j=0; j<4; ++j){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
}