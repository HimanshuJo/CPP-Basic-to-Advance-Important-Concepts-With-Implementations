#include<bits/stdc++.h>
using namespace std;

string getModifiedString(string s, int N){
    string sb="";
    for(int i = 0; i < N; i++){
        sb+="#";
        sb+=s[i];
    }
    sb+="#";
    return sb;
}

int manachersAlgorithm(string s, int N) {
    string str = getModifiedString(s, N);
    int len = (2 * N) + 1;
    int P[len];
    memset(P, 0, sizeof(P));
    int c = 0; //stores the center of the longest palindromic substring until now
    int r = 0; //stores the right boundary of the longest palindromic substring until now
    int maxLen = 0;
    for(int i = 0; i < len; i++) {
        //get mirror index of i  
        int mirror = (2 * c) - i;
        
        //see if the mirror of i is expanding beyond the left boundary of 
        //current longest palindrome at center c
        //if it is, then take r - i as P[i]
        //else take P[mirror] as P[i]
        if(i < r) {
            P[i] = min(r - i, P[mirror]);
        }
        
        //expand at i
        int a = i + (1 + P[i]);
        int b = i - (1 + P[i]);
        while(a < len && b >= 0 && str[a] == str[b]) {
            P[i]++;
            a++;
            b--;
        }
        
        //check if the expanded palindrome at i is expanding beyond 
        //the right boundary of current longest palindrome at center c
        //if it is, the new center is i
        if(i + P[i] > r) {
            c = i;
            r = i + P[i];
            
            if(P[i] > maxLen) { //update maxlen
                maxLen = P[i];
            }
        }
    }
    return maxLen;
}


int main(){
	string s="abcdMADAMabcd";
	int maxLen=manachersAlgorithm(s, s.length());
    cout<<maxLen<<endl;
}
