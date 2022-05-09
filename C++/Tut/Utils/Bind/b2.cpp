/*
The position of placeholder determines the value position in function call statement
*/
// C++ code to demonstrate placeholder
// property 1
#include <iostream>
#include <functional> // for bind()
using namespace std;

// for placeholders
using namespace std::placeholders;

// Driver function to demonstrate bind()
void func(int a, int b, int c)
{
    cout<<"a "<<a<<endl;
    cout<<"b "<<b<<endl;
    cout<<"c "<<c<<endl;
    cout <<"val "<<(a - b - c) << endl;
    cout<<"-------\n";
}

int main()
{
    // for placeholders
    using namespace std::placeholders;

    // Second parameter to fn1() is assigned
    // to 'a' in fun().
    // 2 is assigned to 'b' in fun
    // First parameter to fn1() is assigned
    // to 'c' in fun().
    auto fn1 = bind(func, _2, 2, _1);

    // calling of function
    cout << "The value of function is : \n";
    fn1(1, 13);

    // First parameter to fn2() is assigned
    // to 'a' in fun().
    // 2 is assigned to 'b' in fun
    // Second parameter to fn2() is assigned
    // to 'c' in fun().
    auto fn2 = bind(func, _1, 2, _2);

    // calling of same function
    cout << "The value of function after changing"
            " placeholder position is : \n";
    fn2(1, 13);

    return 0;
}

/*Output
The value of function is :
a 13
b 2
c 1
val 10
-------
The value of function after changing placeholder position is :
a 1
b 2
c 13
val -14
-------
*/