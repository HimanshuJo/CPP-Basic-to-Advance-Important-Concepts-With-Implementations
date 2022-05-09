#include<iostream>
#include<bits/stdc++.h>
#define ll long long

using namespace std;

bool isPalindrome(string s) {
    for (int i = 0; i < (int) s.size() / 2; ++i) {
        if (s[i] != s[(int) s.size() - 1 - i]) return false;
    }

    return true;
}

void solution() {
    string s;
    cin >> s;
    int n = s.size();
    bool ifContainsAllA = true;

    for (int i = 0; i < n; ++i) {
        if (s[i] != 'a') ifContainsAllA = false;
    }

    if (ifContainsAllA) {
        cout << "NO" << "\n";
        return;
    }

    if (!isPalindrome('a' + s)) {
        cout << "YES" << "\n";
        cout << ('a' + s) << "\n";
    } else {
        cout << "YES" << "\n";
        cout << (s + 'a') << "\n";
    }
}

int main() {
    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        solution();
    }
}