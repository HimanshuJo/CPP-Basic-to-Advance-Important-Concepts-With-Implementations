#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<cstring>
using namespace std;
#define Dbg(e) cerr<<e<<endl
#define E(e) #e<<" = "<<(e)
#define Cm <<", "

inline int binary(const string &s) {
	int res = 0;
	for (auto c : s) {
		res <<= 1;
		res |= (c & 1);
	}
	return res;
}

struct bit_is {
	int bit, desired;
	bit_is(int bit, int desired): bit(bit), desired(desired) {}
	bool operator()(const string &s) const {
		return (s[bit] & 1) == desired;
	}
};

struct bit_is_set: public bit_is {
	bit_is_set(int bit): bit_is(bit, 1) {}
};

int most_popular(int bit, const vector<string>&values) {
	int ones = count_if(begin(values), end(values), bit_is_set(bit));
	Dbg(E(bit) Cm E(ones) Cm E(values.size()));
	return !!(ones >= ((int(values.size()) + 1) / 2));
}

template<typename Container, typename Predicate>
auto remove_if_not(Container &c, const Predicate &p) {
	return remove_if(begin(c), end(c), [&] (const auto & value) {
		return !p(value);
	});
}

void filter_numbers(vector<string>&numbers, bool useLeastPopular = false) {
	Dbg(E(useLeastPopular));
	for (int bit = 0; numbers.size() > 1; ++bit) {
		int mostPopular = most_popular(bit, numbers);
		Dbg(E(bit) Cm E(numbers.size()) Cm E(mostPopular));
		auto ri = remove_if_not(numbers, bit_is(bit, int(useLeastPopular ^ mostPopular)));
		numbers.erase(ri, end(numbers));
	}
}

int main(int, const char *[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string>rep;
	int smples = 0;
	while (smples != 12) {
		string num;
		cin >> num;
		rep.emplace_back(move(num));
		smples++;
	}
	Dbg(E(rep.size()) Cm E(rep.front().length()));
	vector<string>vec1(rep);
	filter_numbers(vec1);
	int ans1 = binary(vec1.front());
	vector<string>vec2(rep);
	filter_numbers(vec2, true);
	int ans2 = binary(vec2.front());
	int fnans = ans1 * ans2;
	Dbg(E(ans1) Cm E(ans2) Cm E(fnans));
	cout << fnans << endl;
	return EXIT_SUCCESS;
}
