#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool same(vector<char>&A, int strt, int end, string &s){
        if(end-strt!=s.size()){
            return false;
        }
        int j=0;
        while(strt+j<end&&(A[strt+j]==' '||A[strt+j]==s[j])){
            ++j;
        }
        if(j==s.size()){
            return true;
        }
        j=0;
        while(end-1-j>=strt&&(A[end-1-j]==' '||A[end-1-j]==s[j])){
            ++j;
        }
        return j==s.size();
    }

    bool match(vector<vector<char>>&A, string &s){
        int n=A.size(), m=A[0].size();
        for(int i=0; i<n; ++i){
            int j=0;
            while(j<m){
                while(j<m&&A[i][j]=='#'){
                    ++j;
                }
                int strt=j;
                while(j<m&&A[i][j]!='#'){
                    ++j;
                }
                if(same(A[i], strt, j, s)){
                    return true;
                }
            }
        }
        return false;
    }

    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<char>>tpA(m, vector<char>(n));
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                tpA[j][i]=board[i][j];
            }
        }
        return match(board, word)||match(tpA, word);     
    }
};