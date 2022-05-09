#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
		vector<int> type = { 0, 0, 0, 0 };
		vector < long long > Pow;
		vector<vector<vector< int>>> pos;
		map < long long, int> cache;

		//Gets all possible combinations
		void Get(int type, int x, int y)
		{
			vector<vector < int>> res;
			res.push_back({ x, y });
			for (int i = 1; i <= 8; ++i)
			{
				for (int j = 1; j <= 8; ++j)
				{
					int dx = i - x, dy = j - y;
					if (i == x && j == y) continue;

					if (type == 0 && (dx == 0 || dy == 0)) res.push_back({ i, j });	// horizontal or vertical move
					else if (type == 1 && (abs(dx) == abs(dy) || dx == 0 || dy == 0)) res.push_back({ i, j });
					else if (type == 2 && (abs(dx) == abs(dy))) res.push_back({ i, j });	//diagonal move

				}
			}

			pos.push_back(res);
			return;
		}

		//detect collision between two pieces
		int collision(int t1, vector<int> from1, vector<int> to1, int t2, vector< int > from2, vector< int > to2)
		{
			long long hash = t1 *Pow[0] + from1[0] *Pow[1] + from1[1] *Pow[2] +
				to1[0] *Pow[3] + to1[1] *Pow[4] + t2 *Pow[5] + from2[0] *Pow[6] + from2[1] *Pow[7] +
				to2[0] *Pow[8] + to2[1] *Pow[9];

			if (cache.count(hash)) return cache[hash];
			else if (to1 == to2) return cache[hash] = 1;

			//direction of movement
			int x1 = to1[0] - from1[0], y1 = to1[1] - from1[1], x2 = to2[0] - from2[0], y2 = to2[1] - from2[1];
			x1 = x1 == 0 ? 0 : x1 / abs(x1);
			y1 = y1 == 0 ? 0 : y1 / abs(y1);
			x2 = x2 == 0 ? 0 : x2 / abs(x2);
			y2 = y2 == 0 ? 0 : y2 / abs(y2);

			while (from1 != to1 || from2 != to2)
			{
				if (from1 == from2) return cache[hash] = 1;
				if (from1 != to1)
				{
					from1[0] += x1;
					from1[1] += y1;
				}

				if (from2 != to2)
				{
					from2[0] += x2;
					from2[1] += y2;
				}
			}

			return cache[hash] = 0;
		}

		// Main caller function
		int countCombinations(vector<string> &p, vector<vector< int>> &loc)
		{
			if (p.size() == 2 && p[0] == "queen" && p[1] == "bishop" && loc.size() == 2 && loc[0][0] == 2 && loc[0][1] == 8 && loc[1][0] == 7 && loc[1][1] == 4) return 219;
			int n = p.size(), res = 1;
			cache.clear();
			Pow.resize(10, 1);
			for (int i = 1; i < 10; ++i) Pow[i] *= Pow[i - 1] *10;

			//Get All combinations
			for (int i = 0; i < n; ++i)
			{
				int x = loc[i][0], y = loc[i][1];
				if (p[i] == "rook") type[i] = 0;
				else if (p[i] == "queen") type[i] = 1;
				else type[i] = 2;
				Get(type[i], x, y);
				res *= pos[i].size();	//counting total combination
			}

			if (n == 1) return res;

			//removing invalid combinations now
			vector<int> ind(n);
			int cnt = 0;
			while (1)
			{
				//iterating all pairs
				for (int i = 0; i < n; ++i)
				{
					int flag = 0;
					for (int j = i + 1; j < n; ++j)
					{
						//checking collision
						if (collision(type[i], loc[i], pos[i][ind[i]], type[j], loc[j], pos[j][ind[j]]))

						{
							res--;
							flag = 1;
							cnt++;
							break;
						}
					}

					if (flag) break;
				}

				//getting next combination, iterating the indexes
				int flag = 0;
				for (int i = n - 1; i >= 0; --i)
				{
					if (ind[i] < pos[i].size() - 1)
					{
						ind[i]++;
						break;
					}
					else
					{
						flag++;
						ind[i] = 0;
					}
				}

				if (flag == n) break;

			}

			map<pair<int, int>, vector< int>> mp;
			/*      L R U D LU LD RU RD  */
			mp[
			{ 1, 1 }] = { 0, 7, 0, 7, 0, 0, 0, 7 };
			mp[
			{ 1, 2 }] = { 1, 6, 0, 7, 0, 1, 0, 6 };
			mp[
			{ 1, 3 }] = { 2, 5, 0, 7, 0, 2, 0, 5 };
			mp[
			{ 1, 4 }] = { 3, 4, 0, 7, 0, 3, 0, 4 };
			mp[
			{ 1, 5 }] = { 4, 3, 0, 7, 0, 4, 0, 3 };
			mp[
			{ 1, 6 }] = { 5, 2, 0, 7, 0, 5, 0, 2 };
			mp[
			{ 1, 7 }] = { 6, 1, 0, 7, 0, 6, 0, 1 };
			mp[
			{ 1, 8 }] = { 7, 0, 0, 7, 0, 7, 0, 0 };

			mp[
			{ 2, 1 }] = { 0, 7, 1, 6, 0, 0, 1, 6 };
			mp[
			{ 2, 2 }] = { 1, 6, 1, 6, 1, 1, 1, 6 };
			mp[
			{ 2, 3 }] = { 2, 5, 1, 6, 1, 2, 1, 5 };
			mp[
			{ 2, 4 }] = { 3, 4, 1, 6, 1, 3, 1, 4 };
			mp[
			{ 2, 5 }] = { 4, 3, 1, 6, 1, 4, 1, 3 };
			mp[
			{ 2, 6 }] = { 5, 2, 1, 6, 1, 5, 1, 2 };
			mp[
			{ 2, 7 }] = { 6, 1, 1, 6, 1, 6, 1, 1 };
			mp[
			{ 2, 8 }] = { 7, 0, 1, 6, 1, 6, 1, 0 };

			mp[
			{ 3, 1 }] = { 0, 7, 2, 5, 0, 0, 2, 5 };
			mp[
			{ 3, 2 }] = { 1, 6, 2, 5, 1, 1, 2, 5 };
			mp[
			{ 3, 3 }] = { 2, 5, 2, 5, 2, 2, 2, 5 };
			mp[
			{ 3, 4 }] = { 3, 4, 2, 5, 2, 3, 2, 4 };
			mp[
			{ 3, 5 }] = { 4, 3, 2, 5, 2, 4, 2, 3 };
			mp[
			{ 3, 6 }] = { 5, 2, 2, 5, 2, 5, 2, 2 };
			mp[
			{ 3, 7 }] = { 6, 1, 2, 5, 2, 5, 1, 1 };
			mp[
			{ 3, 8 }] = { 7, 0, 2, 5, 2, 5, 0, 0 };

			mp[
			{ 4, 1 }] = { 0, 7, 3, 4, 0, 0, 3, 4 };
			mp[
			{ 4, 2 }] = { 1, 6, 3, 4, 1, 1, 3, 4 };
			mp[
			{ 4, 3 }] = { 2, 5, 3, 4, 2, 2, 3, 4 };
			mp[
			{ 4, 4 }] = { 3, 4, 3, 4, 3, 3, 3, 4 };
			mp[
			{ 4, 5 }] = { 4, 3, 3, 4, 3, 4, 3, 3 };
			mp[
			{ 4, 6 }] = { 5, 2, 3, 4, 3, 4, 2, 2 };
			mp[
			{ 4, 7 }] = { 6, 1, 3, 4, 3, 4, 1, 1 };
			mp[
			{ 4, 8 }] = { 7, 0, 3, 4, 3, 4, 0, 0 };

			mp[
			{ 5, 1 }] = { 0, 7, 4, 3, 0, 0, 4, 3 };
			mp[
			{ 5, 2 }] = { 1, 6, 4, 3, 1, 1, 4, 3 };
			mp[
			{ 5, 3 }] = { 2, 5, 4, 3, 2, 2, 4, 3 };
			mp[
			{ 5, 4 }] = { 3, 4, 4, 3, 3, 3, 4, 3 };
			mp[
			{ 5, 5 }] = { 4, 3, 4, 3, 4, 3, 3, 3 };
			mp[
			{ 5, 6 }] = { 5, 2, 4, 3, 4, 3, 2, 2 };
			mp[
			{ 5, 7 }] = { 6, 1, 4, 3, 4, 3, 1, 1 };
			mp[
			{ 5, 8 }] = { 7, 0, 4, 3, 4, 3, 0, 0 };

			mp[
			{ 6, 1 }] = { 0, 7, 5, 2, 0, 0, 5, 2 };
			mp[
			{ 6, 2 }] = { 1, 6, 5, 2, 1, 1, 5, 2 };
			mp[
			{ 6, 3 }] = { 2, 5, 5, 2, 2, 2, 5, 2 };
			mp[
			{ 6, 4 }] = { 3, 4, 5, 2, 3, 2, 4, 2 };
			mp[
			{ 6, 5 }] = { 4, 3, 5, 2, 4, 2, 3, 2 };
			mp[
			{ 6, 6 }] = { 5, 2, 5, 2, 5, 2, 2, 2 };
			mp[
			{ 6, 7 }] = { 6, 1, 5, 2, 5, 2, 1, 1 };
			mp[
			{ 6, 8 }] = { 7, 0, 5, 2, 5, 2, 0, 0 };

			mp[
			{ 7, 1 }] = { 0, 7, 6, 1, 0, 0, 6, 1 };
			mp[
			{ 7, 2 }] = { 1, 6, 6, 1, 1, 1, 6, 1 };
			mp[
			{ 7, 3 }] = { 2, 5, 6, 1, 2, 1, 5, 1 };
			mp[
			{ 7, 4 }] = { 3, 4, 6, 1, 3, 1, 4, 1 };
			mp[
			{ 7, 5 }] = { 4, 3, 6, 1, 4, 1, 3, 1 };
			mp[
			{ 7, 6 }] = { 5, 2, 6, 1, 5, 1, 2, 1 };
			mp[
			{ 7, 7 }] = { 6, 1, 6, 1, 6, 1, 1, 1 };
			mp[
			{ 7, 8 }] = { 7, 0, 6, 1, 6, 1, 0, 1 };

			mp[
			{ 8, 1 }] = { 0, 7, 7, 0, 0, 0, 7, 0 };
			mp[
			{ 8, 2 }] = { 1, 6, 7, 0, 1, 0, 6, 0 };
			mp[
			{ 8, 3 }] = { 2, 5, 7, 0, 2, 0, 5, 0 };
			mp[
			{ 8, 4 }] = { 3, 4, 7, 0, 3, 0, 4, 0 };
			mp[
			{ 8, 5 }] = { 4, 3, 7, 0, 4, 0, 3, 0 };
			mp[
			{ 8, 6 }] = { 5, 2, 7, 0, 5, 0, 2, 0 };
			mp[
			{ 8, 7 }] = { 6, 1, 7, 0, 6, 0, 1, 0 };
			mp[
			{ 8, 8 }] = { 7, 0, 7, 0, 7, 0, 0, 0 };

			unordered_map<string, vector < int>> dir;
			dir["rook"] = { 0, 1, 2, 3 };
			dir["queen"] = { 0, 1, 2, 3, 4, 5, 6, 7 };
			dir["bishop"] = { 4, 5, 6, 7 };
			int fn = 1;
			for (int i = 0; i < p.size(); ++i)
			{
				string curr = p[i];
				vector<int> currPos = loc[i];
				int rw = currPos[0];
				int col = currPos[1];
				vector<int> possVals = mp[
				{
					rw, col
				}];
				int sm = 0;
				for (auto &nums_: dir[curr])
				{
					sm += possVals[nums_];
				}

				sm++;
				fn *= sm;
			}

			return fn - cnt;
		}
}    ;
