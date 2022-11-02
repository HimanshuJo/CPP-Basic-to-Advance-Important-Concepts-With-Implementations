#include<iostream>
#include<vector>
#include<map>
using namespace std;

bool smallCave(string str) {
	int n = str.length();
	for (int i = 0; i < n; ++i) {
		if ((int)str[i] < 97 || (int)str[i] > 122) {
			return false;
		}
	}
	return true;
}

int dfs(map<string, vector<string>>&gr, vector<string>&curr, string currNode) {
	int count = 0;
	if (currNode == "end") {
		return 1;
	}
	if (smallCave(currNode)) {
		curr.push_back(currNode);
	}
	vector<string>vecCurrCave = gr[currNode];
	for (auto &vals : vecCurrCave) {
		bool flag = false;
		for (auto &caves : curr) {
			if (caves == vals) {
				flag = true;
				break;
			}
		}
		if (!flag) {
			vector<string>temp = curr;
			count += dfs(gr, temp, vals);
		}
	}
	return count;
}

int dfs2(map<string, vector<string>>&gr, vector<string>&smCave1, vector<string>&smCave2, string currNode) {
	int count = 0;
	if (currNode == "end") {
		return 1;
	}
	if (smallCave(currNode)) {
		bool flag = false;
		for (auto &vals : smCave1) {
			if (vals == currNode) {
				flag = true;
				break;
			}
		}
		if (!flag) {
			smCave1.push_back(currNode);
		} else {
			smCave2.push_back(currNode);
		}
	}
	vector<string>vecCurrCave = gr[currNode];
	for (auto &vals : vecCurrCave) {
		bool flag = false;
		for (auto &caves : smCave1) {
			if (vals == caves) {
				flag = true;
				break;
			}
		}
		if (!flag) {
			vector<string>smCave1_ = smCave1;
			vector<string>smCave2_ = smCave2;
			count += dfs2(gr, smCave1_, smCave2_, vals);
		} else {
			if (smCave2.size() == 0 && flag == true) {
				vector<string>smCave1_ = smCave1;
				vector<string>smCave2_ = smCave2;
				count += dfs2(gr, smCave1_, smCave2_, vals);
			}
		}
	}
	return count;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	map<string, vector<string>>gr;
	int n = 23;
	for (int i = 0; i < n; ++i) {
		string s1;
		cin >> s1;
		string s2;
		cin >> s2;
		gr[s1].push_back(s2);
		if (s1 == "start") continue;
		gr[s2].push_back(s1);
	}
	vector<string>curr;
	vector<string>smCave1;
	vector<string>smCave2;
	for (auto &entries : gr) {
		cout << entries.first << " : ";
		for (auto &vals : entries.second) {
			cout << vals << " ";
		}
		cout << endl;
	}
	int ans1 = dfs(gr, curr, "start");
	int ans2 = dfs2(gr, smCave1, smCave2, "start");
	cout << ans1 << endl;
	cout << ans2 << endl;
	cout << "-------\n";
}
