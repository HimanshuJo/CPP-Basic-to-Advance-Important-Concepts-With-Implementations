/*
The number of placeholders determine the number of arguments required to pass in function
We can use any no. of placeholders in function call statement (obviously less than the maximum number of arguments). 
The rest values are replaced by the user defined default values.
*/

// C++ code to demonstrate placeholder
// property 2
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

    // 1 placeholder
    auto fn1 = bind(func, _1, 2, 4);

    // calling of function with 1 argument
    cout << "The value of function with 1 "
            "placeholder is : \n";
    fn1(10);

    // 2 placeholders
    auto fn2 = bind(func, _1, 2, _2);

    // calling of function with 2 arguments
    cout << "The value of function with 2"
            " placeholders is : \n";
    fn2(13, 1);

    // 3 placeholders
    auto fn3 = bind(func, _1, _3, _2);

    // calling of function with 3 arguments
    cout << "The value of function with 3 "
            "placeholders is : \n";
    fn3(13, 1, 4);

    return 0;
}

/*
Output:
The value of function with 1 placeholder is :
a 10
b 2
c 4
val 4
-------
The value of function with 2 placeholders is :
a 13
b 2
c 1
val 10
-------
The value of function with 3 placeholders is :
a 13
b 4
c 1
val 8
-------
*/