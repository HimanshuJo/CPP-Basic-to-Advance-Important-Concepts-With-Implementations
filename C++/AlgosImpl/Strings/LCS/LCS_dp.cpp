#include<bits/stdc++.h>
using namespace std;

int dp[11][11];

int max(int a, int b) {
	return (a > b) ? a : b;
}

int lcs(char* X, char* Y, int m, int n) {
	int i, j;
	for (i = 0; i <= m; ++i) {
		for (j = 0; j <= n; ++j) {
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
			} else if (X[i - 1] == Y[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[m][n];
}

string subseq(char* X, char* Y, int m, int n) {
	int index = dp[m][n];
	char lcs[index + 1];
	lcs[index] = '\0';
	int i = m, j = n;
	while (i > 0 && j > 0)
	{
		if (X[i - 1] == Y[j - 1])
		{
			lcs[index - 1] = X[i - 1];
			i--; j--; index--;
		}
		else if (dp[i - 1][j] > dp[i][j - 1])
			i--;
		else
			j--;
	}
	return lcs;
}

int main() {
	char X[] = "AGGTAB";
	char Y[] = "GXTXA";
	cout << lcs(X, Y, 6, 5) << endl;
	cout << subseq(X, Y, 6, 5);
}