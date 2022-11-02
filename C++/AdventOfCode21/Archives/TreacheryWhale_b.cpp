#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <climits>
using namespace std;
using ll = long long;

long long total_fuel_spent(const std::vector<long long> &positions, const long long final_position)
{
	long long sum = 0;
	for (const auto &ele : positions)
	{
		sum += (std::abs(ele - final_position) * (std::abs(ele - final_position) + 1)) / 2;
	}
	return sum;
}

int main()
{
	std::string input = "1101,1,29";

	std::vector<long long> crab_positions;

	std::size_t start = 0;
	std::size_t end = input.find(',', start);
	long long average_pos = 0;
	while (end != std::string::npos)
	{
		const long long position = std::stoll(input.substr(start, end - start));
		crab_positions.emplace_back(position);
		average_pos += position;
		start = end + 1;
		end = input.find(',', start);
	}
	const long long position = std::stoll(input.substr(start, input.size() - start));
	crab_positions.emplace_back(position);
	sort(crab_positions.begin(), crab_positions.end());
	int end_ = crab_positions[crab_positions.size() - 1];
	ll ans = LONG_MAX;
	int n = crab_positions.size();
	for (int i = 0; i <= end_; ++i)
	{
		int curr = i;
		ll currans = 0;
		for (int x = 0; x < n; ++x)
		{
			int temp = abs(crab_positions[x] - curr);
			ll rnSm = (temp * (temp + 1)) / 2;
			currans += rnSm;
		}
		if (currans < ans)
		{
			ans = currans;
		}
	}
	cout << ans << "\n";
	return 0;
}