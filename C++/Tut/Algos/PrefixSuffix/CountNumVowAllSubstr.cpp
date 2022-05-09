/*
Count the number of vowels occurring in all the substrings of given string

Given a string of length N of lowercase characters containing 0 or more vowels, 
the task is to find the count of vowels that occurred in all the substrings of the given string.

Examples: 

    Input: str = “abc” 
    Output: 3
    The given string “abc” contains only one vowel = ‘a’ 
    Substrings of “abc” are = {“a”, “b”, “c”, “ab”, “bc, “abc”} 
    Hence, the sum of occurrences of the vowel in these strings = 3.(‘a’ occurred 3 times)
    Input: str = “daceh” 
    Output: 16

Efficient Approach: 

	The idea is to use a prefix sum array-based technique where we store the 
	occurrences of each character in all the substrings concatenated. 

    For the first character,
    	no. of occurrences = no. of substrings starting with the first character = N.

    For each of the following characters, we store the

    	no. of substrings starting with that character + 
    	the number of substrings formed by the previous characters containing this character – 
    	the number of substrings formed by the previous characters only
*/
/*
// Naive

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

map<char, int> mp;

void subString(string s, int n)
{
	// Pick starting point in outer loop
	// and lengths of different strings for
	// a given starting point
	for (int i = 0; i < n; i++)
		for (int len = 1; len <= n - i; len++)
		{
			string temp = s.substr(i, len);
			char cstr[temp.size() + 1];
			std::copy(temp.begin(), temp.end(), cstr);
			cstr[temp.size()] = '\0';
			for (char ch : cstr)
			{
				if (mp.find(ch) == mp.end())
				{
					mp[ch] = 1;
				}
				else
				{
					mp[ch] += 1;
				}
			}
			cout << s.substr(i, len) << endl;
		}
	cout << "-------"
		 << "\n";
}

int main()
{
	string s = "abcd";
	subString(s, s.length());
	if (mp.find(0) != mp.end())
	{
		mp.erase(0);
	}
	int ans = 0;
	for (auto &pair : mp)
	{
		if (pair.first == 'a' || pair.first == 'e' || pair.first == 'i' || pair.first == 'o' || pair.first == 'u')
		{
			ans += pair.second;
		}
		cout << pair.first << " " << pair.second;
		cout << endl;
	}
	cout << endl;
	cout << ans;
	return 0;
}

Output:

4
*/

#include <bits/stdc++.h>
using namespace std;

int vowel_calc(string s)
{
	int n = s.length();
	vector<int> arr;

	for (int i = 0; i < n; i++) {

		if (i == 0)
			// No. of occurrences of 0th character
			// in all the substrings
			arr.push_back(n);

		else
			// No. of occurrences of the ith character
			// in all the substrings
			arr.push_back((n - i) + arr[i - 1] - i);
	}

	int sum = 0;
	for (int i = 0; i < n; i++)

		// Check if ith character is a vowel
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
			sum += arr[i];
	return sum;
}

int main()
{
	string s = "daceh";
	cout << vowel_calc(s) << endl;

	return 0;
}

/*
Output:

4
*/