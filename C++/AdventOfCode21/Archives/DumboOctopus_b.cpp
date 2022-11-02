#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;

int startFlashes(int i, int j, vector<vector<int>>&board, int nbr_flash, int lb) {
	nbr_flash += 1;
	int rw = i, col = j;
	board[i][j] = 0;
	if (rw + 1 < lb) {
		int level = board[rw + 1][j];
		if (level + 1 > 9) {
			nbr_flash = startFlashes(rw + 1, col, board, nbr_flash, lb);
		} else {
			if (level != 0) {
				level += 1;
				board[rw + 1][col] = level;
			}
		}
	}
	if (rw - 1 >= 0) {
		int level = board[rw - 1][col];
		if (level + 1 > 9) {
			nbr_flash = startFlashes(rw - 1, col, board, nbr_flash, lb);
		} else {
			if (level != 0) {
				level += 1;
				board[rw - 1][col] = level;
			}
		}
	}
	if (rw - 1 >= 0 && col - 1 >= 0) {
		int level = board[rw - 1][col - 1];
		if (level + 1 > 9) {
			nbr_flash = startFlashes(rw - 1, col - 1, board, nbr_flash, lb);
		} else {
			if (level != 0) {
				level += 1;
				board[rw - 1][col - 1] = level;
			}
		}
	}
	if (rw - 1 >= 0 && col + 1 < lb) {
		int level = board[rw - 1][col + 1];
		if (level + 1 > 9) {
			nbr_flash = startFlashes(rw - 1, col + 1, board, nbr_flash, lb);
		} else {
			if (level != 0) {
				level += 1;
				board[rw - 1][col + 1] = level;
			}
		}
	}
	if (col + 1 < lb) {
		int level = board[rw][col + 1];
		if (level + 1 > 9) {
			nbr_flash = startFlashes(rw, col + 1, board, nbr_flash, lb);
		} else {
			if (level != 0) {
				level += 1;
				board[rw][col + 1] = level;
			}
		}
	}
	if (col - 1 >= 0) {
		int level = board[rw][col - 1];
		if (level + 1 > 9) {
			nbr_flash = startFlashes(rw, col - 1, board, nbr_flash, lb);
		} else {
			if (level != 0) {
				level += 1;
				board[rw][col - 1] = level;
			}
		}
	}
	if (rw + 1 < lb && col - 1 >= 0) {
		int level = board[rw + 1][col - 1];
		if (level + 1 > 9) {
			nbr_flash = startFlashes(rw + 1, col - 1, board, nbr_flash, lb);
		} else {
			if (level != 0) {
				level += 1;
				board[rw + 1][col - 1] = level;
			}
		}
	}
	if (rw + 1 < lb && col + 1 < lb) {
		int level = board[rw + 1][col + 1];
		if (level + 1 > 9) {
			nbr_flash = startFlashes(rw + 1, col + 1, board, nbr_flash, lb);
		} else {
			if (level != 0) {
				level += 1;
				board[rw + 1][col + 1] = level;
			}
		}
	}
	return nbr_flash;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ifstream infile("./Test/11_inp.txt");
	string line;
	vector<vector<int>>board(10, vector<int>(10, 0));
	int i = 0;
	while (getline(infile, line)) {
		istringstream iss(line);
		string s;
		if (!(iss >> s)) { break; }
		int len = s.length();
		for (int x = 0; x < len; ++x) {
			board[i][x] = s[x] - '0';
		}
		++i;
	}
	int step = 0, temp = 0, flashes_count = 0, nbr_flash = 0;
	int lb = board.size();
	int lib = board[0].size();
	int count = 0;
	while (true) {
		for (int i = 0; i < lb; ++i) {
			for (int j = 0; j < lib; ++j) {
				int level = board[i][j];
				level += 1;
				board[i][j] = level;
			}
		}
		for (int i = 0; i < lb; ++i) {
			for (int j = 0; j < lib; ++j) {
				if (board[i][j] > 9) {
					startFlashes(i, j, board, nbr_flash, lb);
				}
			}
		}
		bool flag = false;
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				if (board[i][j] != 0) {
					flag = true;
					break;
				}
			}
			if (flag) break;
		}
		if (!flag) break;
		count++;
	}
	cout << "-------\n";
	cout << count + 1 << endl;
}
