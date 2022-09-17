// B. Decode String
/*
Polycarp has a string s consisting of lowercase Latin letters.

He encodes it using the following algorithm.

He goes through the letters of the string s from left to right and for each letter Polycarp considers 
its number in the alphabet:

if the letter number is single-digit number (less than 10), then just writes it out;
if the letter number is a two-digit number (greater than or equal to 10), then it writes it out and adds the number 0 after.
For example, if the string s is code, then Polycarp will encode this string as follows:

'c' — is the 3-rd letter of the alphabet. Consequently, Polycarp adds 3 to the code (the code becomes equal to 3);
'o' — is the 15-th letter of the alphabet. Consequently, Polycarp adds 15 to the code and also 0 (the code becomes 3150);
'd' — is the 4-th letter of the alphabet. Consequently, Polycarp adds 4 to the code (the code becomes 31504);
'e' — is the 5-th letter of the alphabet. Therefore, Polycarp adds 5 to the code (the code becomes 315045).
Thus, code of string code is 315045.

You are given a string t resulting from encoding the string s. Your task is to decode it (get the original string s by t).

Input
The first line of the input contains an integer q (1≤q≤10^4) — the number of test cases in the input.

The descriptions of the test cases follow.

The first line of description of each test case contains one integer n (1≤n≤50) — the length of the given code.

The second line of the description of each test case contains a string t of length n — the given code. 
It is guaranteed that there exists such a string of lowercase Latin letters, as a result of encoding which the 
string t is obtained.

Output
For each test case output the required string s — the string that gives string t as the result of encoding. 
It is guaranteed that such a string always exists. It can be shown that such a string is always unique.

Example
input
9
6
315045
4
1100
7
1213121
6
120120
18
315045615018035190
7
1111110
7
1111100
5
11111
4
2606

output
code
aj
abacaba
ll
codeforces
aaaak
aaaaj
aaaaa
zf
Note
The first test case is explained above.

In the second test case, the answer is aj. Indeed, the number of the letter a is equal to 1, 
so 1 will be appended to the code. The number of the letter j is 10, so 100 will be appended to the code. 
The resulting code is 1100.

There are no zeros in the third test case, which means that the numbers of all letters are less than 
10 and are encoded as one digit. The original string is abacaba.

In the fourth test case, the string s is equal to ll. The letter l has the number 12 and is encoded as 120. 
So ll is indeed 120120.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#define endl "\n"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        unordered_map<int, char>mp;
        char bgn='a';
        for(int i=1; i<=26; ++i){
            mp[i]=bgn++;
        }
        string res="";
        int sz=s.size();
        int idx=sz-1;
        while(idx>=0){
            if(s[idx]!='0'){
                string temp="";
                temp+=s[idx];
                res+=mp[stoi(temp)];
            } else{
                string temp="";
                idx--;
                temp+=s[idx];
                idx--;
                temp+=s[idx];
                reverse(temp.begin(), temp.end());
                res+=mp[stoi(temp)];
            }
            idx--;
        }
        reverse(res.begin(), res.end());
        cout<<res<<endl;
    }
}