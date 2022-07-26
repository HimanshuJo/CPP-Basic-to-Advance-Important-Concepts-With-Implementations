/*
Sorting a vector in C++ can be done by using std::sort().

    It is defined in <algorithm> header.

    To get a stable sort std::stable_sort is used.

    It is exactly like sort() but maintain the relative order of equal elements.

    Quicksort(), mergesort() can also be used, as per requirement.

-------

Sorting a vector in descending order can be done by using std::greater <>()
*/

#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Version1 {
public:
    void sortTest() {
        vector<int> v{ 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };

        sort(v.begin(), v.end());

        cout << "Sorted \n";
        for (auto x : v)
            cout << x << " ";
    }
};

/*
Output :

Sorted
0 1 2 3 4 5 6 7 8 9
*/

/*
How to sort in descending order?

sort() takes a third parameter that is used to specify the order in which elements
are to be sorted. We can pass “greater()” function to sort in descending order.

This function does comparison in a way that puts greater element before.
*/

class Version2 {
public:
    void sortTest() {
        vector<int> v{ 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
        sort(v.begin(), v.end(), greater<int>());
        cout << "Sorted \n";
        for (auto x : v)
            cout << x << " ";
    }
};

/*
Output :

Sorted
9 8 7 6 5 4 3 2 1 0
*/

/*
How to sort in particular order?
We can also write our own comparator function and pass it as a third parameter.
*/

class Version3 {
public:

    struct Interval {
        int start, end;
    };

    struct custComp {
        bool operator()(Interval i1, Interval i2) {
            return (i1.start < i2.start);
        }
    };

    void sortTest() {
        vector<Interval> v { { 6, 8 }, { 1, 9 }, { 2, 4 }, { 4, 7 } };

        // sort the intervals in increasing order of start time
        sort(v.begin(), v.end(), custComp());

        cout << "Intervals sorted by start time : \n";
        for (auto x : v)
            cout << "[" << x.start << ", " << x.end << "] ";
    }
};

/*
Output :

Intervals sorted by start time :
[1, 9] [2, 4] [4, 7] [6, 8]
*/

class Version4 {
public:

    struct custComp {
        bool operator()(const vector<int>&A, const vector<int>&B) const {
            return A[1] == B[1] ? A[0] < B[0] : A[1] < B[1];
        }
    };

    void sortTest() {
        vector<vector<int>>vec{{1, 1}, {2, 4},  {5, 2}, {8, 3}, {7, 1}};
        sort(vec.begin(), vec.end(), custComp());
        for (auto &vals : vec) {
            for (auto &nums : vals) {
                cout << nums << " ";
            }
            cout << endl;
        }
    }
};

/*
Output:

1 1
7 1
5 2
8 3
2 4
*/

class Version5 {
public:
    struct custComp {
        const bool operator()(const pair<int, int>A, const pair<int, int>B) {
            return A.second == B.second ? A.first > B.first : A.second > B.second;
        }
    };

    void sortTest() {
        vector<pair<int, int>>vec{{1, 1}, {2, 4},  {5, 2}, {8, 3}, {7, 1}};
        sort(vec.begin(), vec.end(), custComp());
        for (auto &vals : vec) {
            cout << vals.first << " " << vals.second;
            cout << endl;
        }
    }
};

/*
Output:

2 4
8 3
5 2
7 1
1 1
*/

int main() {
    Version1 obj1;
    Version2 obj2;
    Version3 obj3;
    Version4 obj4;
    Version5 obj5;
    obj1.sortTest();
    cout << "\n-------\n";
    obj2.sortTest();
    cout << "\n-------\n";
    obj3.sortTest();
    cout << "\n-------\n";
    obj4.sortTest();
    cout << "\n-------\n";
    obj5.sortTest();
    cout << "\n-------\n";
}
