// B. Minor Reduction
/*
You are given a decimal representation of an integer x without leading zeros.

You have to perform the following reduction on it exactly once: 
take two neighboring digits in x and replace them with their sum without leading zeros 
(if the sum is 0, it's represented as a single 0).

For example, if x=10057, the possible reductions are:

choose the first and the second digits 1 and 0, replace them with 1+0=1; the result is 1057;
choose the second and the third digits 0 and 0, replace them with 0+0=0; the result is also 1057;
choose the third and the fourth digits 0 and 5, replace them with 0+5=5; the result is still 1057;
choose the fourth and the fifth digits 5 and 7, replace them with 5+7=12; the result is 10012.
What's the largest number that can be obtained?

Example
input
2
10057
90

output
10012
9
Note
The first testcase of the example is already explained in the statement.

In the second testcase, there is only one possible reduction: the first and the second digits.
*/

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		string in;
		cin>>in;
		int len=in.length();
		if(in.length()==1){
			cout<<in<<"\n";
			continue;
		}
		bool flag=false;
		for(int i=len-1; i>0; --i){
			string temp;
			int sm=in[i-1]-'0'+in[i]-'0';
			temp=to_string(sm);
			if(temp.size()>=2){
				string s1="";
				for(int j=0; j<i-1; ++j){
					s1+=in[j];
				}
				cout<<"s1 "<<s1<<endl;
				s1+=temp;
				for(int j=i+1; j<len; ++j){
					s1+=in[j];
				}
				cout<<s1<<"\n";
				flag=true;
				break;
			}
		}
		if(flag) continue;
		int sm=in[0]-'0'+in[1]-'0';
		string temp=to_string(sm);
		for(int i=2; i<len; ++i){
			temp+=in[i];
		}
		cout<<temp<<"\n";
		continue;
	}
}


