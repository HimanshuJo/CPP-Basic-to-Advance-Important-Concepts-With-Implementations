/*
	Perform string compression.

	Example: string str="aabcccccaa" would become "a2b1c5a3"

Time: O(p+k^2) where p is the size of the string, and k is the number of the character sequences(in the above example, there are 5 character sequences)
*/

#include<string>
#include<iostream>
using namespace std;

string compressString1(string str){
	str+="";
	string compressedString="";
	int countConsecutive=0;
	for(int i=0; i<str.length(); ++i){
		countConsecutive++;
		if(str[i]!=str[i+1]){
			compressedString+=str[i]+to_string(countConsecutive);
			countConsecutive=0;
		}
	}
	return compressedString.length()<str.length()?compressedString: str;
}

/*
Solution 2
*/

int countCompression(string str){
	int compressedLength=0, countConsecutive=0;
	for(int i=0; i<str.length(); ++i){
		countConsecutive++;
		if(str[i]!=str[i+1]){
			compressedLength+=1+(to_string(countConsecutive)).length();
			countConsecutive=0;
		}	
	}
	return compressedLength;
}

string compressString2(string str){
	str+="";
	int fnlength=countCompression(str);
	if(fnlength>=str.length()) return str;
	string compressedString="";
	compressedString.reserve(fnlength);
	int countConsecutive=0;
	for(int i=0; i<str.length(); ++i){
		countConsecutive++;
		if(str[i]!=str[i+1]){
			compressedString+=str[i]+to_string(countConsecutive);
			countConsecutive=0;
		}
	}
	return compressedString;
}

int main(){
	string in="aabcccccaaa";
	string ans1=compressString1(in);
	cout<<ans1;
	cout<<"\n-------\n";
	string ans2=compressString2(in);
	cout<<ans2;
}