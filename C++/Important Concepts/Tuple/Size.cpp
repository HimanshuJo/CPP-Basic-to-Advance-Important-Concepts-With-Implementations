// tuple_size :- It returns the number of elements present in the tuple.

#include<iostream>
#include<tuple>
using namespace std;

int main()
{
    tuple <char, int, float> geek(20, 'g', 17.5);
    cout << "The size of tuple is : ";
    cout << tuple_size<decltype(geek)>::value << endl;
    return 0;

}

/*
Output:

The size of tuple is : 3
*/