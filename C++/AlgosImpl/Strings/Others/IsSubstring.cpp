/*
Check if a smaller string is a substring of a longer string, if it is then return the first occurrence of the substring in the longer string

Time: O(n*m)
Space: O(1)
*/

#include<iostream>
#include<string>
using namespace std;

int is_substring(string longerStr, string smallerStr){
	int counter=0;
	int i;
	int lngsz=longerStr.length();
	int smsz=smallerStr.length();
	for(i=0; i<lngsz; ++i){
		if(counter==smsz) break;
		if(smallerStr[counter]==longerStr[i]) counter++;
		else{
			if(counter>0) i-=counter;
			counter=0;
		}
	}
	return counter<smsz?-1:i-counter;
}

int main(){
	string s1="hemnshh";
	string s2="mnsh";
	int indx=is_substring(s1, s2);
	int sz=s2.size();
	cout<<indx<<endl;
	if(indx!=-1){
		cout<<s1.substr(indx, sz);
	}
}