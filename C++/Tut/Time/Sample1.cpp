#include <bits/stdc++.h>
using namespace std;

long long getBuffer()
{
    time_t timer;
    char buffer[26];
    struct tm *tm_info;
    timer = time(NULL);
    tm_info = localtime(&timer);
    // strftime(buffer, 26, "%H:%M:%S", tm_info);
    // strftime(buffer, 26, "%M:%S", tm_info);
    strftime(buffer, 26, "%S", tm_info);
    string s;
    int tt = 1;
    // for min and secs
    /*     for (int i = 0; i < 5; ++i) {
        s += buffer[i];
        if (s.size() == 2) {
            tt = stoi(s);
            tt *= 60;
            s.clear();
            s = to_string(tt);
        }
    } */
    int curr = 0;
    for (int i = 0; i < 2; ++i)
    {
        curr += buffer[i] * 60;
    }
    s = to_string(curr);
    tt = stoi(s);
    s.clear();
    s = to_string(tt);
    s.erase(std::remove(s.begin(), s.end(), ':'), s.end());
    long long time = stol(s, nullptr, 10);
    return time;
}

void fun()
{
    long long res = 1;
    for (int x = 0; x < 1e9 + 7; ++x)
    {
        res += x;
    }
    for (int x = 0; x < 1e9 + 7; ++x)
    {
        res += x;
    }
    for (int x = 0; x < 1e9 + 7; ++x)
    {
        res += x;
    }
}

int main()
{
    long long st = getBuffer();
    long long res = 1;
    cout << st << "\n";
    for (int x = 0; x < 1e9 + 7; ++x)
    {
        res += x;
    }
    for (int x = 0; x < 1e9 + 7; ++x)
    {
        res += x;
    }
    for (int x = 0; x < 1e9 + 7; ++x)
    {
        res += x;
    }
    long long end = getBuffer();
    cout << end << "\n";
    cout << "diff " << abs(st - end) << endl;
    return 0;
}