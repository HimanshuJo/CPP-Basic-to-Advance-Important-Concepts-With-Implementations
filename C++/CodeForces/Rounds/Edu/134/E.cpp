// E. Prefix Function Queries
/*
You are given a string s, consisting of lowercase Latin letters.

You are asked q queries about it: given another string t, consisting of lowercase Latin letters, 
perform the following steps:

concatenate s and t;
calculate the prefix function of the resulting string s+t;
print the values of the prefix function on positions |s|+1,|s|+2,…,|s|+|t| (|s| and |t| 
denote the lengths of strings s and t, respectively);
revert the string back to s.

The prefix function of a string a is a sequence p1,p2,…,p|a|, where pi is the maximum value of k 
such that k<i and a[1..k]=a[i−k+1..i] (a[l..r] denotes a contiguous substring of a string a from a 
position l to a position r, inclusive). 

In other words, it's the longest proper prefix of the string a[1..i] that is equal to its suffix of the same length.
*/

/*
What's the issue with calculating the prefix function on the string s and then 
appending the string t with an extra |t| recalculations? 

Calculating prefix function is linear anyway. Well, it's linear, but it's also amortized. 
So while it will make O(n) operations for a string in total, it can take up to O(n) on every particular letter. 
These particular letters can appear in string t, making the algorithm work in O(q⋅(|s|+|t|)).

Let's analyze the classic way to calculate the prefix function. To append a character to the 
string and calculate the new value of the prefix function, you have to do the following:

	1. take the longest proper prefix of a string before appending the letter, which is also a suffix;
	
	2. if the letter right after it is the same as the new one, then the new value is length of it plus one;
	
	3. if it's empty, then the new value is 0;
	
	4. otherwise, take its longest proper prefix and return to step 2.
	
Basically, from having the value of the prefix function of the string and the new letter, 
you can determine the new value of the prefix function.

If |t| was always equal to 1, then you would only want to try all options for the next letter after a string.

That should remind you of a structure known as prefix function automaton. Its states are 
the values of the prefix function, and the transitions are appending a letter to a string with a 
certain value of the prefix function.

So you can append a letter in O(1) if you have an automaton built on the string s. 
However, you can't just append more letters after one — you don't have the automaton built this far.

You can follow two paths.

The first one is to jump with a regular way of calculating the prefix function until you 
reach the state of the automaton which exists.

The second one is to continue building the automaton onto the string t, calculating the prefix 
function along the way. Appending a layer to the automaton takes O(AL) non-amortized. 

After you calculated everything you needed, pop the states back to the original.

Overall complexity: O(|s|⋅AL+q⋅|t|) or O(|s|⋅AL+q⋅|t|⋅AL).
*/

#include<iostream>
#include<vector>
#define forn(i, n) for(int i=0; i<(int)n; ++i)
using namespace std;

const int AL=26;

vector<int> prefix_function(const string &s){
	int n=s.size();
    /*
        stores the sequence e.g. p1, p2, ... pn
        where pi is the maximum value of k such that k<i
        and str[1 ... k]=str[i-k+1 ... i]

        In other words, longest proper prefix of the string str[1 .. i]
        that is equal to its suffix of the same length
    */
	vector<int>p(n);
	for(int i=1; i<n; ++i){
		int k=p[i-1];
		while(k>0&&s[i]!=s[k]){
			k=p[k-1];
		}
		k+=(s[i]==s[k]);
		p[i]=k;
	}
	return p;
}

int main(){
    cin.tie(0);
    iostream::sync_with_stdio(0);
    string s;
    cin>>s;
    int n=s.size();
    auto p=prefix_function(s);
    vector<vector<int>>A(n, vector<int>(AL));
    forn(i, n) forn(j, AL){
        if(i>0&&j!=s[i]-'a'){
            A[i][j]=A[p[i-1]][j];
        } else{
            A[i][j]=i+(j==s[i]-'a');
        }
    }
    int q;
    cin>>q;
    vector<vector<int>>ans(q);
    forn(z, q){
        string t;
        cin>>t;
        int m=t.size();
        s+=t;
        for(int i=n; i<n+m; ++i){
            A.push_back(vector<int>(AL));
            forn(j, AL){
                if(j!=s[i]-'a'){
                    A[i][j]=A[p[i-1]][j];
                } else{
                    A[i][j]=i+(j==s[i]-'a');
                }
            }
            p.push_back(A[p[i-1]][s[i]-'a']);
            ans[z].push_back(p[i]);
        }
        forn(_, m){
            p.pop_back();
            s.pop_back();
            A.pop_back();
        }
    }
    for(auto &it: ans){
        for(int x: it){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
}