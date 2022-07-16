/*
Solution2:

class Solution {
public:
    
    int getMin(int A, int B, int C){
        return (min(A, min(B, C)));
    }
    
    int minDistance(string word1, string word2) {
        word1.insert(0, "");
        word2.insert(0, "");
        if(word1.length()==0) return word2.length();
        if(word2.length()==0) return word1.length();
        int lenword1=word1.length(), lenword2=word2.length();
        vector<vector<int>>dp(lenword1+1, vector<int>(lenword2+1, 0));
        for(int i=0; i<=lenword1; ++i){
            for(int j=0; j<=lenword2; ++j){
                if(i==0){
                    dp[i][j]=j;
                    continue;
                }
                if(j==0){
                    dp[i][j]=i;
                    continue;
                }
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                } else{
                    dp[i][j]=1+getMin(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
                }
            }
        }
        return dp[lenword1][lenword2];
    }
};
*/

#include<vector>
#include<string>
#include<iostream>
#include<map>
using namespace std;

int getmin(int A, int B, int C){
	return (min(A, min(B, C)));
}

int dfs(string str1, string str2, int lenstr1, int lenstr2, map<tuple<string, string, int, int>, int>&memo){
	if(lenstr1==0) return lenstr2;
	if(lenstr2==0) return lenstr1;
	tuple<string, string, int, int>temp(str1, str2, lenstr1, lenstr2);
	if(memo.find(temp)!=memo.end()) return memo[temp];
	if(str1[lenstr1-1]==str2[lenstr2-1]) return dfs(str1, str2, lenstr1-1, lenstr2-1, memo);
	return (memo[temp]=1+getmin(dfs(str1, str2, lenstr1, lenstr2-1, memo), 
				dfs(str1, str2, lenstr1-1, lenstr2, memo),
				dfs(str1, str2, lenstr1-1, lenstr2-1, memo)));
}

int editDistance(string str1, string str2, int lenstr1, int lenstr2){
	map<tuple<string, string, int, int>, int>memo;
	int res=dfs(str1, str2, lenstr1, lenstr2, memo);
	return res;
}

int main(){
	string str1="voldemort";
	string str2="dumbledore";
	int lenstr1=str1.length(), lenstr2=str2.length();
	int ans=editDistance(str1, str2, lenstr1, lenstr2);
	cout<<ans<<endl;
}