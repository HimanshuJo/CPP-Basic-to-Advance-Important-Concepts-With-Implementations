/*
Replace all the spaces in a string with "%20"

Example:

	Input

		string str="Mr. John Smith     "

	Output

		Mr.%20John%20Smith

*/

/*

import java.util.*;

class Solution{
    public void replaceSpaces(char[] str, int trueLength){
        int numSpaces=countOfChar(str, 0, trueLength, ' ');
        int newIndex=trueLength-1+numSpaces*2;
        if(newIndex+1<str.length){
            str[newIndex+1]='\0';
        } 
        for(int oldIndex=trueLength-1; oldIndex>=0; --oldIndex){
            if(str[oldIndex]==' '){
                str[newIndex]='0';
                str[newIndex-1]='2';
                str[newIndex-2]='%';
                newIndex-=3;
            } else{
                str[newIndex]=str[oldIndex];
                newIndex-=1;
            }
        }
        System.out.println("-------");
        System.out.println(str);
    }

    int countOfChar(char[] str, int start, int end, int target){
        int count=0;
        for(int i=start; i<end; ++i){
            if(str[i]==target){
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args){
        String str_="Mr John Smith    ";
        char[] str=new char[str_.length()];
        for (int i = 0; i < str_.length(); i++) {
            str[i] = str_.charAt(i);
        }
        int trueLength=13;
        Solution obj=new Solution();
        obj.replaceSpaces(str, trueLength);
    }
}

-------

#include<string>
#include<iostream>
#include<cstring>
using namespace std;

int countOfChar(char *chstr, int start, int end, int target){
	int count=0;
	for(int i=start; i<end; ++i){
		if(chstr[i]==target){
			count++;
		}
	}
	return count;
}

void replaceSpacesAndUrlify(char *chstr, int trueLength){
	int numSpaces=countOfChar(chstr, 0, trueLength, ' ');
	int nwIdx=trueLength-1+numSpaces*2;
	if(nwIdx+1<trueLength){
		chstr[nwIdx+1]='\0';
	}
	for(int oldIdx=trueLength-1; oldIdx>=0; --oldIdx){
		if(chstr[oldIdx]==' '){
			chstr[nwIdx]='0';
			chstr[nwIdx-1]='2';
			chstr[nwIdx-2]='%';
			nwIdx-=3;
		} else{
			chstr[nwIdx]=chstr[oldIdx];
			nwIdx-=1;
		}
	}
}

int main(){
	string str = "Mr John Smith    ";
	int trueLength=13;
	char *chstr=new char[str.length()+1];
	strcpy(chstr, str.c_str());
	replaceSpacesAndUrlify(chstr, 13);
	cout<<chstr;
}
*/

#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
#include<sstream>
#include<ostream>
#include<chrono>
#include<iomanip>
using namespace std;

string& rtrim(string &s){
	auto it=find_if(s.rbegin(), s.rend(),
	[](char c){
		return !isspace<char>(c, locale::classic());
	});
	s.erase(it.base(), s.end());
	return s;
}

string replace_all_copy(const string &s, const string &f, const string &r){
	if (s.empty()||f.empty()||f==r||f.size()>s.size()){
		return s;
	}
	ostringstream buffer;
	auto start=s.cbegin();
	while(true){
		const auto end=search(start, s.cend(), f.cbegin(), f.cend());
		copy(start, end, ostreambuf_iterator<char>(buffer));
		if (end==s.cend()){
			break;
		}
		copy(r.cbegin(), r.cend(), ostreambuf_iterator<char>(buffer));
		start=end+f.size();
	}
	return buffer.str();
}

string urlify(string str, int sz) {
	string temp = rtrim(str);
	auto start = chrono::high_resolution_clock::now();
	string res = replace_all_copy(temp, " ", "%20");
	auto end = chrono::high_resolution_clock::now();
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	cout << "Time taken by program is : " << fixed
	     << time_taken << setprecision(9);
	cout << " sec" << endl;
	return res;
}

int main() {
	string str = "Mr.   John Smith    ";
	int sz=str.size();
	string res = urlify(str, sz);
	cout << res;
}