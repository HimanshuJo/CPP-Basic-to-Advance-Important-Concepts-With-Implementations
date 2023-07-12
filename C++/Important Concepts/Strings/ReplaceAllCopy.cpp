#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
#include<sstream>
#include<ostream>
#include<chrono>
#include<iomanip>
using namespace std;

string& rtrim(string &s){
	auto it=find_if(s.rbegin(), s.rend(),
	[](char c){
		return !isspace<char>(c, locale::classic());
	});
	s.erase(it.base(), s.end());
	return s;
}

string replace_all_copy(const string &s, const string &f, const string &r){
	if (s.empty()||f.empty()||f==r||f.size()>s.size()){
		return s;
	}
	ostringstream buffer;
	auto start=s.cbegin();
	while(true){
		const auto end=search(start, s.cend(), f.cbegin(), f.cend());
		copy(start, end, ostreambuf_iterator<char>(buffer));
		if (end==s.cend()){
			break;
		}
		copy(r.cbegin(), r.cend(), ostreambuf_iterator<char>(buffer));
		start=end+f.size();
	}
	return buffer.str();
}

string urlify(string str, int sz) {
	string temp = rtrim(str);
	auto start = chrono::high_resolution_clock::now();
	string res = replace_all_copy(temp, " ", "%20");
	auto end = chrono::high_resolution_clock::now();
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	cout << "Time taken by program is : " << fixed
	     << time_taken << setprecision(9);
	cout << " sec" << endl;
	return res;
}

int main() {
	string str = "Mr. John Smith Mr. John Smith Mr. John Smith   ";
	string res = urlify(str, sz);
	cout << res;
}
