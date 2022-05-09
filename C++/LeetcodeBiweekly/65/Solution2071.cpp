#include<bits/stdc++.h>
using namespace std;

class Robot {
private:
	int w, h, x, y;
	int dir;
public:
	Robot(int width, int height) {
		w = width;
		h = height;
		x = 0, y = 0;
		dir = 1;
	}

	void move(int num) {
		num %= w * 2 + h * 2 - 4;
		if (num == 0) num = w * 2 + h * 2 - 4;
		for (int i = 0; i < num; ++i) {
			switch (dir) {
			case 1:
				if (x == w - 1) {
					dir = 3;
					y++;
				} else x++;
				break;
			case 3:
				if (y == h - 1) {
					dir = 2;
					x--;
				} else y++;
				break;
			case 2:
				if (x == 0) {
					dir = 4;
					y--;
				} else x--;
				break;
			case 4:
				if (y == 0) {
					dir = 1;
					x++;
				} else y--;
			}
		}
	}

	vector<int> getPos() {
		return {x, y};
	}

	string getDir() {
		return dir==1?"East":dir==2?"West":dir==3?"North":"South";
	}
};