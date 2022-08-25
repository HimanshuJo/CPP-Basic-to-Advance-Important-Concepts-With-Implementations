/*
Polycarp came up with a new programming language. 
There are only two types of statements in it:

    "x := s": assign the variable named x the value s (where s is a string). 
    
        For example, the statement var := hello assigns the variable named var the value hello. 
        
        Note that s is the value of a string, not the name of a variable. 
        
        Between the variable name, the := operator and the string contains exactly one space each.

    "x = a + b": assign the variable named x the concatenation of values of two variables a and b. 
        For example, if the program consists of three statements a := hello, b := world, c = a + b, 
        then the variable c will contain the string helloworld. 
        
    It is guaranteed that the program is correct and the variables a and b were previously defined. 
    
        There is exactly one space between the variable names and the = and + operators. 

All variable names and strings only consist of lowercase letters of the English alphabet and 
    do not exceed 5 characters.

The result of the program is the number of occurrences of string haha in the string that was 
    written to the variable in the last statement.

Polycarp was very tired while inventing that language. 
    He asks you to implement it. Your task is — for given program statements calculate the number 
    of occurrences of string haha in the last assigned variable.

Input

    The first line contains an integer t(1≤t≤103). Then t test cases follow.

    The first line of each test case contains a single integer n (1≤n≤50) — 
        the number of statements in the program.
        
        All variable names and strings are guaranteed to consist only of lowercase letters of the 
        English alphabet and do not exceed 5 characters.

    This is followed by n lines describing the statements in the format described above.
        It is guaranteed that the program is correct.

Output
    
    For each set of input data, output the number of occurrences of the haha substring in the 
    string that was written to the variable in the last statement.
*/

/*
    We can't model this process directly, since the maximum string length reaches 2^50

    To optimize this process, we can store each row as a set of the following values:

        Number of occurrences of "haha" in the string -> cnt
        String length -> length
        The first three characters of the string are -> pref
        The last three characters of the string are -> suff

    Then to process the second type of the request and combine the two strings a and b into the strings c, we need

        c.length = a.length + b.length

        c.cnt = a.cnt + b.cnt + count(a.suff + b.suff, haha)
            (New occurrences maybe added at the junctions of two words)

        c.pref = a.pref (however, if the string length is less than 6 = 3 + 3) then we need to handle
            this case carefully

        c.suff = b.suff (similarly we need to process small strings separately)
*/

#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<string> split(const string &s, char p)
{
    vector<string> res(1);
    for (char c : s)
    {
        if (c == p)
        {
            res.emplace_back();
        }
        else
        {
            res.back() += c;
        }
    }
    return res;
}

struct Word
{
    ll len;
    ll cnt;
    string s;
};

string getFirst(string s)
{
    if (s.size() < 3)
    {
        return s;
    }
    return s.substr(0, 3);
}

string getLast(string s)
{
    if (s.size() < 3)
    {
        return s;
    }
    return s.substr(s.size() - 3, 3);
}

int count(const string &s, const string &p)
{
    int cnt = 0;
    for (int i = 0; i + p.size() <= s.size(); ++i)
    {
        if (s.substr(i, p.size()) == p)
        {
            cnt++;
        }
    }
    return cnt;
}

Word merge(const Word &a, const Word &b)
{
    Word c;
    c.len = a.len + b.len;
    c.s = a.s + b.s;
    c.cnt = a.cnt + b.cnt + count(getLast(a.s) + getFirst(b.s), "haha");
    if (c.s.size() >= 7)
    {
        c.s = getFirst(c.s) + "@" + getLast(c.s);
    }
    return c;
}

void solve()
{
    int n;
    cin >> n;
    map<string, Word> vars;
    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
        string var;
        cin >> var;
        string opr;
        cin >> opr;
        if (opr == "=")
        {
            string a, plus, b;
            cin >> a >> plus >> b;
            vars[var] = merge(vars[a], vars[b]);
        }
        else
        {
            string str;
            cin >> str;
            Word word;
            word.len = str.length();
            word.cnt = count(str, "haha");
            word.s = str;
            vars[var] = word;
        }
        ans = vars[var].cnt;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}