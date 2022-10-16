// A. Ela Sorting Books
/*
n books must be split into k compartments on the bookshelf (n is divisible by k). 
Each book is represented by a lowercase Latin letter from 'a' to 'y' inclusively, which is the 
beginning letter in the title of the book.

Ela must stack exactly nk books in each compartment. After the books are stacked, 
for each compartment indexed from 1 to k, she takes the minimum excluded (MEX) letter of the 
multiset of letters formed by letters representing all books in that compartment, 
then combines the resulting letters into a string. The first letter of the resulting string is 
the MEX letter of the multiset of letters formed by the first compartment, the second letter of 
the resulting string is the MEX letter of the multiset of letters formed by the second compartment, ... 
and so on. Please note, under the constraint of this problem, MEX letter can always be determined for any 
multiset found in this problem because 'z' is not used.

What is the lexicographically greatest resulting string possible that Ela can create?

A string a is lexicographically greater than a string b if and only if one of the following holds:

b is a prefix of a, but b≠a;
in the first position where a and b differ, the string a has a letter that appears later in the alphabet than 
the corresponding letter in b.

The minimum excluded (MEX) letter of a multiset of letters is the letter that appears earliest in the alphabet 
and is not contained in the multiset. For example, if a multiset of letters contains 7 letters 
'b', 'a', 'b', 'c', 'e', 'c', 'f' respectively, then the MEX letter of this compartment is 'd', because 'd' 
is not included in the multiset, and all letters comes before 'd' in the alphabet, namely 'a', 'b' and 'c', 
are included in the multiset.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤100). 
Description of the test cases follows.

The first line of each test case contains two integers n and k (1≤n≤200; 1≤k≤n). It is guaranteed that n is divisible by k.

The second line of each test case contains a string of n lowercase Latin letters from 'a' to 'y' 
inclusively. Each letter represents the starting letter of the title of a book in the initial heap.

It is guaranteed that the sum of n over all test cases does not exceed 1000.

Output
For each test case, output a string of k letters which is the most optimal string that Ela can find.

Example
input
5
12 3
cabccadabaac
12 6
cabccadabaac
12 12
cabccadabaac
25 1
abcdefghijklmnopqrstuvwxy
10 5
bcdxedbcfg

output
edb
ccbbba
bbbbbaaaaaaa
z
aaaaa
Note
In the first test case, the books can be divided into 3 compartments as below:

the first compartment contains the books with indices 1,2,3,7: multiset1={'c', 'a', 'b', 'd'} → MEX(multiset1)= 'e'
the second compartment contains the books with indices 4,5,6,9 : multiset2={'c', 'c', 'a', 'b'} → MEX(multiset2)= 'd'
the third compartment contains the remaining books 8,10,11,12 : multiset3={ 'a', 'a', 'a', 'c'} → MEX(multiset3)= 'b'
Therefore, the answer is 'edb'. It can be proven that there is no way that Ela can arrange the books so that it results 
in a lexicographically greater string.
*/

#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<queue>
#include<algorithm>
#define endl "\n"
using ll=long long;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
		int N, K;
		string str;
		cin>>N>>K;
		cin>>str;
		vector<int>count_char(26, 0);
		for(char &ch: str){
			count_char[ch-'a']++;
		}
		string ans="";
		for(int i=0; i<min(25, N/K); ++i){
			while(K-ans.size()>count_char[i]){
				ans.push_back(i+'a');
			}
		}
		char ch='a'+min(N/K, 25);
		while(K>ans.size()){
			ans+=ch;
		}
		reverse(ans.begin(), ans.end());
		cout<<ans<<endl;
    }
}