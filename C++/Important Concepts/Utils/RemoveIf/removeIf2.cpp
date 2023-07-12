#include <bits/stdc++.h>
#include <random>
using namespace std;

bool greater6(int value)
{
    return value > 6;
}

int main()
{
    vector<int> v1;
    vector<int>::iterator Iter1, Iter2, new_end;
    int i;
    for (i = 0; i <= 9; i++)
        v1.push_back(i);
    int ii;
    for (ii = 0; ii <= 3; ii++)
        v1.push_back(7);
    auto rng = std::default_random_engine {};
    shuffle(v1.begin(), v1.end(), rng);
    cout << "Vector v1 is (";
    for (Iter1 = v1.begin(); Iter1 != v1.end(); Iter1++)
        cout << *Iter1 << " ";
    cout << ")." << endl;
    cout<<"-------\n";
    // Remove elements satisfying predicate greater6
    new_end = remove_if(v1.begin(), v1.end(), greater6);
    cout << "Vector v1 with elements satisfying greater6 removed is\n(";
    for (Iter1 = v1.begin(); Iter1 != new_end; Iter1++)
        cout << *Iter1 << " ";
    cout << ")." << endl;
    cout<<"currently vec size: "<<v1.size()<<endl;
    cout<<"-------\n";
    // To change the sequence size, use erase
    v1.erase(new_end, v1.end());
    cout << "Vector v1 resized elements satisfying greater6 removed and erased is\n(";
    for (Iter1 = v1.begin(); Iter1 != v1.end(); Iter1++)
        cout << *Iter1 << " ";
    cout << ")." << endl;
    cout<<"Now vec size: "<<v1.size()<<endl;
    return 0;
}

/*
Output:
Vector v1 is (7 7 7 6 7 0 4 9 7 3 1 8 2 5 ).
-------
Vector v1 with elements satisfying greater6 removed is
(6 0 4 3 1 2 5 ).
currently vec size: 14
-------
Vector v1 resized elements satisfying greater6 removed and erased is
(6 0 4 3 1 2 5 ).
Now vec size: 7
*/