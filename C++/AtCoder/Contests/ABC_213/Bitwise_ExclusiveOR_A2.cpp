#include <bits/stdc++.h>
using lt = long int;
using namespace std;

long int decimal_to_binary(int n)
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

int binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;
    int base = 1;
    int temp = num;
    while (temp)
    {
        int last_digit = temp % 10;
        temp = temp / 10;
        dec_value += last_digit * base;
        base = base * 2;
    }
    return dec_value;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--)
    {
        int A, B;
        cin >> A >> B;
        string nwA = to_string(decimal_to_binary(A));
        string nwB = to_string(decimal_to_binary(B));
        if (nwA.length() != 8) {
            while (nwA.length() != 8) {
                nwA.insert(0, "0");
            }
        }
        if (nwB.length() != 8) {
            while (nwB.length() != 8) {
                nwB.insert(0, "0");
            }
        }
        int n = nwA.length();
        string ans = "";
        for (int i = 0; i < n; ++i)
        {
            if (nwA[i] == nwB[i])
            {
                ans += "0";
            }
            else
            {
                ans += "1";
            }
        }
        unsigned long res = bitset<8>(ans).to_ulong();
        cout << res;
    }
}