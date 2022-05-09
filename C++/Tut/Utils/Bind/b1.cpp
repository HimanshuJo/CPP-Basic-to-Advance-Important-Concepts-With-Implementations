// Bind function and placeholders in C++
/*
Sometimes we need to manipulate the operation of a function according to the need, i.e changing some arguments to default etc. 
Predefining a function to have default arguments restricts the versatility of a function and forces us to use the default arguments 
and that too with similar value each time. From C++11 onwards, the introduction of bind function has made this task easier.

How does bind() work?
Bind function with the help of placeholders, helps to manipulate the position and number of values to be used by the function 
and modifies the function according to the desired output.

What are placeholders?
Placeholders are namespace which direct the position of a value in a function. They are represented by _1, _2, _3…
*/

// C++ code to demonstrate bind() and
// placeholders
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;

// for placeholders
using namespace std::placeholders;

// Driver function to demonstrate bind()
void func(int a, int b, int c)
{
    cout<<"a "<<a<<endl;
    cout<<"b "<<b<<endl;
    cout<<"c "<<c<<endl;
    cout << "val: "<<(a - b - c) << endl;
    cout<<"-------\n";
}

int main()
{
    // for placeholders
    using namespace std::placeholders;

    // Use of bind() to bind the function
    // _1 is for first parameter and assigned
    // to 'a' in above declaration.
    // 2 is assigned to b
    // 3 is assigned to c
    auto fn1 = bind(func, _1, 2, 3);

    // 2 is assigned to a.
    // _1 is for first parameter and assigned
    // to 'b' in above declaration.
    // 3 is assigned to c.
    auto fn2 = bind(func, 2, _1, 3);

    // calling of modified functions
    fn1(5);
    fn2(10);

    return 0;
}
/*
Output:

a 5
b 2
c 3
val: 0
-------
a 2
b 10
c 3
val: -11
-------
*/