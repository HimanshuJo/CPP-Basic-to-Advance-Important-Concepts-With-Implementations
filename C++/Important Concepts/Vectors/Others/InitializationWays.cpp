// 1. Initializing by pushing values one by one:

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

class Version1 {
public:
	void initializationTest() {
		vector<int> vect;
		vect.push_back(10);
		vect.push_back(20);
		vect.push_back(30);
		for (int x : vect)
			cout << x << " ";
	}
};

/*
Output:

10 20 30
*/

// 2. Specifying size and initializing all values:

class Version2 {
public:
	void initializationTest() {
		int n = 3;
		vector<int> vect(n, 10);
		for (int x : vect)
			cout << x << " ";
	}
};

/*
Output:

10 10 10
*/

// 3. Initializing like arrays:

class Version3 {
public:
	void initializationTest() {
		vector<int> vect{ 10, 20, 30 };
		for (int x : vect)
			cout << x << " ";
	}
};

/*
Output:

10 20 30
*/

// 4. Initializing from an array:  *IMP

class Version4 {
public:
	void initializationTest() {
		int arr[] = { 10, 20, 30 };
		int n = sizeof(arr) / sizeof(arr[0]);

		vector<int> vect(arr, arr + n);

		for (int x : vect)
			cout << x << " ";
	}
};

/*
Output:

10 20 30
*/

// 5. Initializing from another vector:

class Version5 {
public:
	void initializationTest() {
		vector<int> vect1{ 10, 20, 30 };

		vector<int> vect2(vect1.begin(), vect1.end()); // vector<int>vect2=vect1;

		for (int x : vect2)
			cout << x << " ";
	}
};

/*
Output:

10 20 30
*/

// 6. Initializing all elements with a particular value:

class Version6 {
public:
	void initializationTest() {
		vector<int> vect1(10);
		int value = 5;
		fill(vect1.begin(), vect1.end(), value);
		for (int x : vect1)
			cout << x << " ";
	}
};

/*
Output:

5 5 5 5 5 5 5 5 5 5
*/

// 7. Initialize vector of custom type with all zeros with memset

class Version7 {
public:

	struct someStruct {
		unsigned int ProductID;
		string ProductName;
		string Category;
		unsigned int Number;
		float CostPrice;
		float SellingPrice;
	};

	void initializationTest() {
		std::vector<someStruct> vtr(2);
		vtr[1].ProductID = 1; vtr[1].ProductName = "TV Set"; vtr[1].Category = "Entertainment";
		cout << vtr[1].ProductID << ", "; cout << vtr[1].ProductName << ", "; cout << vtr[1].Category << ", "; cout << vtr[1].Number << endl;
	}
};

/*
Output:

1, TV Set, Entertainment, 0
*/

// Initialization 2d, 3d, 4d vectors:

class Version8 {
public:
	void initializationTest() {
		int x = 3, y = 3, z = 3, z_ = 3;
		std::vector<std::vector<int>> twoDimVector(x, std::vector<int>(y, 0));
		//vector<vector<vector<double>>> threeDimVector(x, vector<vector<double>>(y, vector<double>(z, 5)));
		//vector<vector<vector<vector<int>>>>fourDimVector(x, vector<vector<vector<int>>>(y, vector<vector<int>>(z, vector<int>(z_, -1))));
		vector<vector<vector<double>>> threeDimVector =
		{
			{
				{5, 5, 5},
				{5, 5, 5},
				{5, 5, 5}
			},

			{
				{5, 5, 5},
				{5, 5, 5},
				{5, 5, 5}
			},

			{
				{5, 5, 5},
				{5, 5, 5},
				{5, 5, 5}
			}
		};
		vector<vector<vector<vector<int>>>>fourDimVector =
		{
			{
				{
					{ -1, -1, -1  },
					{ -1, -1, -1  },
					{ -1, -1, -1  }
				},
				{
					{ -1, -1, -1  },
					{ -1, -1, -1  },
					{ -1, -1, -1  }
				},
				{
					{ -1, -1, -1  },
					{ -1, -1, -1  },
					{ -1, -1, -1  }
				}
			},
			{
				{
					{ -1, -1, -1  },
					{ -1, -1, -1  },
					{ -1, -1, -1  }
				},
				{
					{ -1, -1, -1  },
					{ -1, -1, -1  },
					{ -1, -1, -1  }
				},
				{
					{ -1, -1, -1  },
					{ -1, -1, -1  },
					{ -1, -1, -1  }
				}
			},
			{
				{
					{ -1, -1, -1  },
					{ -1, -1, -1  },
					{ -1, -1, -1  }
				},
				{
					{ -1, -1, -1  },
					{ -1, -1, -1  },
					{ -1, -1, -1  }
				},
				{
					{ -1, -1, -1  },
					{ -1, -1, -1  },
					{ -1, -1, -1  }
				}
			}
		};

		for (int i = 0; i < x; ++i) {
			for (int j = 0; j < y; ++j) {
				cout << twoDimVector[i][j] << " ";
			}
			cout << endl;
		}
		cout << "\n-------*******-------\n";
		for (int i = 0; i < x; ++i) {
			for (int j = 0; j < y; ++j) {
				for (int k = 0; k < z; ++k) {
					cout << threeDimVector[i][j][k] << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
		cout << "\n-------*******-------\n";
		for (int i = 0; i < x; ++i) {
			for (int j = 0; j < y; ++j) {
				for (int k = 0; k < z; ++k) {
					for (int l = 0; l < z_; ++l) {
						cout << fourDimVector[i][j][k][l] << " ";
					}
					cout << endl;
				}
				cout << endl;
			}
			cout << endl;
		}
	}
};

/*
Output:

{
 {0, 0, 0},
 {0, 0, 0},
 {0, 0, 0}
};

-------*******-------

{
 {
  {5, 5, 5},
  {5, 5, 5},
  {5, 5, 5}
 },

 {
  {5, 5, 5},
  {5, 5, 5},
  {5, 5, 5}
 },

 {
  {5, 5, 5},
  {5, 5, 5},
  {5, 5, 5}
 }
};

-------*******-------
{
	{
		{
			{ -1 -1 -1  },
			{ -1 -1 -1  },
			{ -1 -1 -1  }
		},
		{
			{ -1 -1 -1  },
			{ -1 -1 -1  },
			{ -1 -1 -1  }
		},
		{
			{ -1 -1 -1  },
			{ -1 -1 -1  },
			{ -1 -1 -1  }
		}
	},
	{
		{
			{ -1 -1 -1  },
			{ -1 -1 -1  },
			{ -1 -1 -1  }
		},
		{
			{ -1 -1 -1  },
			{ -1 -1 -1  },
			{ -1 -1 -1  }
		},
		{
			{ -1 -1 -1  },
			{ -1 -1 -1  },
			{ -1 -1 -1  }
		}
	},
	{
		{
			{ -1 -1 -1  },
			{ -1 -1 -1  },
			{ -1 -1 -1  }
		},
		{
			{ -1 -1 -1  },
			{ -1 -1 -1  },
			{ -1 -1 -1  }
		},
		{
			{ -1 -1 -1  },
			{ -1 -1 -1  },
			{ -1 -1 -1  }
		}
	}
};
*/

int main() {
	Version8 obj;
	obj.initializationTest();
	cout << "\n-------\n";
	Version7 obj2;
	obj2.initializationTest();
}