// A. Spell Check
/*
Timur likes his name. As a spelling of his name, he allows any permutation of the letters of the name. 
For example, the following strings are valid spellings of his name: Timur, miurT, Trumi, mriTu. 

Note that the correct spelling must have uppercased T and lowercased other letters.

Today he wrote string s of length n consisting only of uppercase or lowercase Latin letters. 
He asks you to check if s is the correct spelling of his name.

Input
The first line of the input contains an integer t (1≤t≤10^3) — the number of test cases.

The first line of each test case contains an integer n (1≤n≤10) — the length of string s.

The second line of each test case contains a string s consisting of only uppercase or lowercase Latin characters.

Output
For each test case, output "YES" (without quotes) if s satisfies the condition, and "NO" (without quotes) otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes", "Yes" and "YES" will be 
recognized as a positive answer).

Example
input
10
5
Timur
5
miurT
5
Trumi
5
mriTu
5
timur
4
Timr
6
Timuur
10
codeforces
10
TimurTimur
5
TIMUR

output
YES
YES
YES
YES
NO
NO
NO
NO
NO
NO
*/

#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
#define ll long long
#define endl "\n"
#define lnbreak "\n-------*******-------\n"
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
        unordered_map<char, char>mp;
        mp['T']='T';
        mp['i']='i';
        mp['m']='m';
        mp['u']='u';
        mp['r']='r';
        int n;
        cin>>n;
        string s;
        cin>>s;
        if(n!=5){
            cout<<"NO\n";
        } else{
            bool flag=false;
            for(auto &entries: mp){
                size_t it=s.find(entries.first);
                if(it==string::npos){
                    cout<<"NO\n";
                    flag=true;
                    break;
                }
            }
            if(!flag){
                cout<<"YES\n";
            }
        }
	}
}