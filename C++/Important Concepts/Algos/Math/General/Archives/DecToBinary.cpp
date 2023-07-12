/*
Given a decimal number as input, we need to write a program to convert
the given decimal number into equivalent binary number.

Examples:

Input : 7
Output : 111

Input : 10
Output : 1010

Input: 33
Output: 100001

*/

#include <iostream>
using namespace std;

int decToBinary1(int n)
{
	for (int i = 31; i >= 0; i--) {
		int k = n >> i;
		if (k & 1)
			cout << "1";
		else
			cout << "0";
	}
}

int decToBinary2(int n)
{
	for (int i = 31; i >= 0; i--) {
		int k = n / pow(2, i);
		if (k % 2 != 0)
			cout << "1";
		else
			cout << "0";
	}
}

vector<int> decToBinary3(int n) {
	vector<int> binArr(32);
	int index = 0;
	for (int i = 31; i >= 0; --i) {
		int k = n >> i;
		if (k & 1) {
			binArr[index++] = 1;
		} else {
			binArr[index++] = 0;
		}
	}
	return binArr;
}

long int decToBinary4(int n)
{
	long int binary = 0;
	int remainder, i, flag = 1;
	for (i = 1; n != 0; i = i * 10)
	{
		remainder = n % 2;
		n /= 2;
		binary += remainder * i;
	}
	return binary;
}

void decToBinary5(int n)
{
	int binaryNum[32];
	int i = 0;
	while (n > 0) {
		binaryNum[i] = n % 2;
		n = n / 2;
		i++;
	}
	for (int j = i - 1; j >= 0; j--)
		cout << binaryNum[j];
}

int main()
{
	int n = 32;
	decToBinary(n);
}

/*
Output :

00000000000000000000000000100000

*/