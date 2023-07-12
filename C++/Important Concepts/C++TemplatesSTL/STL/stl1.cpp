#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef int* iter;

iter find(iter begin, iter end, const int& val) {
    while (begin != end && *begin != val) {
        ++begin;
    }
    return begin;
}

void init(vector<int>&arr, int count) {
    for (int i = 0; i <= count; ++i) {
        arr[i] = i * i;
    }
}

void init(int arr[], int count) {
    for (int i = 0; i <= count; ++i) {
        arr[i] = i * i;
    }
}

int main() {
    const int sz = 11;
    vector<int>arrV(sz);
    int arr[sz];
    iter begin = arr;
    iter end = arr + sz;
    init(arr, sz);
    init(arrV, sz);
    for (int x : arrV) {
        cout << x << " ";
    }
    cout << "\n";
    int num = -1;
    int num2 = -1;
    while (num != 0) {
        cout << "Num to find: ";
        if (!(cin >> num)) {
            break;
        }
        if (num != 0) {
            iter pos = find(begin, end, num);
            if (pos != end) {
                cout << num << " pos: " << (pos - begin) << "\n";
            }
        } else {
            cout << "At 0 \n";
            cout << "Terminating \n";
        }
    }
    while (num2 != 0) {
        cout << "Num to find in vec: ";
        if (!(cin >> num2)) {
            break;
        }
        if (num2 != 0) {
            auto pos = find(arrV.begin(), arrV.end(), num2);
            if (pos != arrV.end()) {
                cout << num2 << " pos: " << (pos - arrV.begin()) << "\n";
            }
        } else {
            cout << "At 0 \n";
            cout << "Terminating \n";
        }
    }
    return 0;
}