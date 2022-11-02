/*
Given a matrix where every element is either ‘O’ or ‘X’, find the largest sub-square surrounded by ‘X’.
In the below article, it is assumed that the given matrix is also a square matrix.
The code given below can be easily extended for rectangular matrices.

Input: mat[N][N] = { {'X', 'O', 'X', 'X', 'X'},
                     {'X', 'X', 'X', 'X', 'X'},
                     {'X', 'X', 'O', 'X', 'O'},
                     {'X', 'X', 'X', 'X', 'X'},
                     {'X', 'X', 'X', 'O', 'O'},
                    };
Output: 3
The square sub-matrix starting at (1, 1) is the largest
sub-matrix surrounded by 'X'

Input: mat[M][N] = { {'X', 'O', 'X', 'X', 'X', 'X'},
                     {'X', 'O', 'X', 'X', 'O', 'X'},
                     {'X', 'X', 'X', 'O', 'O', 'X'},
                     {'X', 'X', 'X', 'X', 'X', 'X'},
                     {'X', 'X', 'X', 'O', 'X', 'O'},
                    };
Output: 4
The square sub-matrix starting at (0, 2) is the largest
sub-matrix surrounded by 'X'

A Simple Solution is to consider every square sub-matrix and check whether is has all corner edges filled with ‘X’.
The time complexity of this solution is O(N^4).

We can solve this problem in O(N^3) time using extra space.
The idea is to create two auxiliary arrays hor[N][N] and ver[N][N].

The value stored in hor[i][j] is the number of horizontal continuous ‘X’ characters till mat[i][j] in mat[][].

Similarly, the value stored in ver[i][j] is the number of vertical continuous ‘X’ characters till mat[i][j] in mat[][].

Example:

mat[6][6] =  X  O  X  X  X  X
             X  O  X  X  O  X
             X  X  X  O  O  X
             O  X  X  X  X  X
             X  X  X  O  X  O
             O  O  X  O  O  O

hor[6][6] = 1  0  1  2  3  4
            1  0  1  2  0  1
            1  2  3  0  0  1
            0  1  2  3  4  5
            1  2  3  0  1  0
            0  0  1  0  0  0

ver[6][6] = 1  0  1  1  1  1
            2  0  2  2  0  2
            3  1  3  0  0  3
            0  2  4  1  1  4
            1  3  5  0  2  0
            0  0  6  0  0  0

Once we have filled values in hor[][] and ver[][], we start from the bottom-most-rightmost corner of matrix and move toward the
leftmost-topmost in row by row manner.

For every visited entry mat[i][j], we compare the values of hor[i][j] and ver[i][j], and pick the smaller of two as we need a square.

Let the smaller of two be ‘small’.

After picking smaller of two, we check if both ver[][] and hor[][] for left and up edges respectively.

If they have entries for the same, then we found a sub-square.

Otherwise we try for small-1.
*/

#include<iostream>
#include<vector>
using namespace std;

int findSubSquare(vector<vector<char>>&mat){
    int rws=mat.size(), cols=mat[0].size();
    vector<vector<int>>hormat(rws, vector<int>(cols, 0));
    vector<vector<int>>vermat(rws, vector<int>(cols, 0));
    int fnmax=0;
    for(int i=0; i<rws; ++i){
        for(int j=0; j<cols; ++j){
            if(mat[i][j]=='X'){
                if(i==0){
                    vermat[i][j]=1;
                } else{
                    vermat[i][j]=vermat[i-1][j]+1;
                }
                if(j==0){
                    hormat[i][j]=1;
                } else{
                    hormat[i][j]=hormat[i][j-1]+1;
                }
            }
        }
    }
    cout<<"Matrix"<<endl;
    for(int i=0; i<rws; ++i){
        for(int j=0; j<cols; ++j){
            cout<<mat[i][j]<<" "; 
        }
        cout<<endl;
    }
    cout<<"-------*******-------"<<endl;
    for(int i=0; i<rws; ++i){
        for(int j=0; j<cols; ++j){
            cout<<hormat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"-------*******-------"<<endl;
    for(int i=0; i<rws; ++i){
        for(int j=0; j<cols; ++j){
            cout<<vermat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=rws-1; i>=0; --i){
        for(int j=cols-1; j>=0; --j){
            /*
                A square can only be made using the smaller of the two values from the current
                hormat[i][j] and vermat[i][j]
            */
            /*
                At this point we are sure that there is a 
                right vertical line and a bottom horozontal line of atleast 'curmin'
                However, in between this particular square there can be some values as 'O'
                Therefore, we have to find the appropriate square where all the values are 'X'
                The minimum size of that square can be 1
            */
           /*
                We will find a bigger valid square than the current biggest valid square 
                only on these conditions:
                    1. If side of the current square is greater than the current max

                    2. There is a left vertical line of length >= 'curmin'

                    3. There is a top horizontal line of length >= 'curmin'
           */
            int curmin=min(hormat[i][j], vermat[i][j]);
            while(curmin>fnmax){
                if(hormat[i-curmin+1][j]>=curmin&&vermat[i][j-curmin+1]>=curmin){
                    fnmax=max(fnmax, curmin);
                }
                curmin--;
            }
        }
    }
    return fnmax;
}

int main(){
    vector<vector<char>>mat{
        { 'X', 'O', 'X', 'X', 'X', 'X' },
		{ 'X', 'O', 'X', 'X', 'O', 'X' },
		{ 'X', 'X', 'X', 'O', 'O', 'X' },
		{ 'O', 'X', 'X', 'X', 'X', 'X' },
		{ 'X', 'X', 'X', 'O', 'X', 'O' },
		{ 'O', 'O', 'X', 'O', 'O', 'O' }};
    cout<<findSubSquare(mat);
}