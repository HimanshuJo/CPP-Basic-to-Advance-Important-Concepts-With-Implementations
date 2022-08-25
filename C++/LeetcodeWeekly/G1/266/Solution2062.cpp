// 2062. Count Vowel Substrings of a String
/*
A substring is a contiguous (non-empty) sequence of characters within a string.

A vowel substring is a substring that only consists of vowels 
('a', 'e', 'i', 'o', and 'u') and has all five vowels present in it.

Given a string word, return the number of vowel substrings in word.

Example 1:

Input: word = "aeiouu"
Output: 2
Explanation: The vowel substrings of word are as follows (underlined):
- "aeiouu"
- "aeiouu"
Example 2:

Input: word = "unicornarihan"
Output: 0
Explanation: Not all 5 vowels are present, so there are no vowel substrings.
Example 3:

Input: word = "cuaieuouac"
Output: 7
Explanation: The vowel substrings of word are as follows (underlined):
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"

Constraints:

1 <= word.length <= 100
word consists of lowercase English letters only.
*/

class Solution {
	public:

		vector<string> genAllSubstrs(const string str){
			vector<string>res;
			int n=str.length();
			for (int i = 0; i < n; i++) { 
				for (int j = i; j < n; j++) {
					string curr="";
					for (int k = i; k <= j; k++) {
						curr+=str[k];
					}
					res.push_back(curr);
				}
			}
			return res;
		}

		int countVowelSubstrings(string word) {
			unordered_map<char, char>mp;
			for(char ch='a'; ch<='z'; ++ch){
				mp[ch]=ch;
			}
			mp.erase('a');
			mp.erase('e');
			mp.erase('i');
			mp.erase('o');
			mp.erase('u');
			vector<string>allSubsStrs=genAllSubstrs(word);
			int ans=0;
			for(auto &vals: allSubsStrs){
				string curr=vals;
				auto it1=curr.find('a');
				auto it2=curr.find('e');
				auto it3=curr.find('i');
				auto it4=curr.find('o');
				auto it5=curr.find('u');
				if(it1!=string::npos&&it2!=string::npos&&it3!=string::npos&&it4!=string::npos&&it5!=string::npos){
					bool flag=false;
					for(char ch: curr){
						auto it=mp.find(ch);
						if(it!=mp.end()){
							flag=true;
							break;
						}
					}
					if(!flag)
						ans++;
				}
			}
			return ans;
		}
};
