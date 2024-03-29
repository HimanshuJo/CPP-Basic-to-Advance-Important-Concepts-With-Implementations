// tuple_cat() :- This function concatenates two tuples and returns a new tuple.

#include<iostream>
#include<tuple>
using namespace std;

int main()
{
    tuple <int, char, float> tup1(20, 'g', 17.5);

    tuple <int, char, float> tup2(30, 'f', 10.5);

    // Concatenating 2 tuples to return a new tuple
    auto tup3 = tuple_cat(tup1, tup2);

    cout << "The new tuple elements in order are : ";
    cout << get<0>(tup3) << " " << get<1>(tup3) << " ";
    cout << get<2>(tup3) << " " << get<3>(tup3) << " ";
    cout << get<4>(tup3) << " " << get<5>(tup3) << endl;
    return 0;
}

/*
Output:

The new tuple elements in order are : 20 g 17.5 30 f 10.5
*/