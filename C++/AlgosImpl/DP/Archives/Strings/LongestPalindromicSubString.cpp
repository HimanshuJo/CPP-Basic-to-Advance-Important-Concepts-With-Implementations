/*Given a string, find the longest substring which is palindrome. 

For example, 

Input: Given string :"forgeeksskeegfor", 
Output: "geeksskeeg"

Input: Given string :"Geeks", 
Output: "ee"
*/

#include<bits/stdc++.h>
using namespace std;

const int maxx=1000;

void printSubStr(string str, int low, int high){
    for (int i=low; i<=high; ++i){
        cout<<str[i];
    }
}

int longestPalSubstr(string str){
    int n=str.size();
    bool dp[maxx][maxx];
    memset(dp, 0, sizeof(dp));
    int maxLength=1;
    for (int i=0; i<n; ++i){
        dp[i][i]=true;
    }
    // checking for sub-string of length 2
    int start=0;
    for (int i=0; i<n-1; ++i){
        if (str[i]==str[i+1]){
            dp[i][i+1]=true;
            start=i;
            maxLength=2;
        }
    }
    // checking for length greater than 2
    for (int k=3; k<=n; ++k){
        for (int i=0; i<n-k+1; ++i){
            int j=i+k-1;
            // checking for sub-string from i'th index to j'th index 
            // if str[i+1] to str[j-1] is a palindrome
            if (dp[i+1][j-1]&&(str[i]==str[j])){
                dp[i][j]=true;
                if (k>maxLength){
                    start=i;
                    maxLength=k;
                }
            }
        }
    }
    cout<<"LPS is: ";
    printSubStr(str, start, start+maxLength-1);
    return maxLength;
}

int main(){
    string toCheck="hemnsnm";
    longestPalSubstr(toCheck);
}