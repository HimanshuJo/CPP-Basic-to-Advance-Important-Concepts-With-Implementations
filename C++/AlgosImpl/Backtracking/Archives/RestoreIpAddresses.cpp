// 93. Restore IP Addresses
/*
A valid IP address consists of exactly four integers separated by single dots.
Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but
"0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
Given a string s containing only digits, return all possible valid IP addresses that
can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s.
You may return the valid IP addresses in any order.

Example 1:

Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]

Example 5:

Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
*/

class Solution {
public:
	void decomposeIpAddresses(string s, vector<string>&snippets, vector<string>&ipAddresses, int idx) {
		if (idx == s.size() && snippets.size() == 4) {
			ipAddresses.push_back(snippets[0] + '.' + snippets[1] + '.' + snippets[2] + '.' + snippets[3]);
			return;
		}
		else if (idx == s.size() || snippets.size() == 4) {
			return;
		}
		for (int len = 1; len <= 3 && idx + len <= s.size(); len++) {
			string snippet = s.substr(idx, len);
			if ((stoi(snippet) > 255) || (snippet.size() > 1 && snippet[0] == '0')) break;

			// Choose, explore, Unchoose
			snippets.push_back(snippet);
			decomposeIpAddresses(s, snippets, ipAddresses, idx + len);
			snippets.pop_back();
		}
	}

	vector<string> restoreIpAddresses(string s) {
		vector<string>ipAddresses;
		vector<string>snippets;
		decomposeIpAddresses(s, snippets, ipAddresses, 0);
		return ipAddresses;
	}
};