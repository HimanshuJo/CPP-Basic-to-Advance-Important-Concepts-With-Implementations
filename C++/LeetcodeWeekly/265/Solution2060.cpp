#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool possiblyEquals(string s1, string s2) {
        int cnt1=0;
		int cnt2=0;
		for(int i=0; i<s1.length(); ++i){
			if(isalpha(s1[i]))
				cnt1++;
			if(isdigit(s1[i]))
				cnt1+=s1[i]-'0';
		}
		for(int i=0; i<s2.length(); ++i){
			if(isalpha(s2[i]))
				cnt2++;
			if(isdigit(s2[i]))
				cnt2+=s2[i]-'0';
		}
		if(cnt1!=cnt2) return false;
		if(isalpha(s1[0])&&isalpha(s2[0]))
			if(s1[0]!=s2[0])
				return false;
		return true;
    }
};
