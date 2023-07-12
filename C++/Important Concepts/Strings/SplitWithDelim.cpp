#include <iostream>
#include <string>
#include <algorithm>
#include<vector>
#include<cstring>
#include<sstream>
using namespace std;

vector<string> splitString(string str, char delimiter) { 
	vector<string> res; 
	stringstream ss(str); 
	string tok; 
	while(getline(ss, tok, delimiter)) { 
		res.push_back(tok); 
	} 
	return res;  
}

int main()
{
    string str="hemnshh joshi";
    vector<string>splittedStr=splitString(str, ' ');
    for(auto &vals: splittedStr)
        cout<<vals<<endl;
    return 0;
}

/*
output:

hemnshh
joshi
*/