/*
In C programming, we used to initialize objects using assignment operator = and 
passing arguments at the right side of the assignment operator = to invoke the 
constructor.

In C++ programming, this feature has been kept.

However, it is not recommended to use assignment operator = to initialize objects, 
especially for the objects whose constructor only takes one single argument, 
because it is often confusing to the readers who first read the code. 

For example, we initialize A typed variable a using A a = 1. 

At first glance, the reader would wonder why an integer could be “assigned” 
to an A typed variable. But actually it is calling the constructor.

Instead of using the confusing assignment operator =, we use 
parentheses () and the more recommended curly braces {} to.
 
Especially for curly braces {}, it unambiguously means that it will invoke 
the constructor.

-------

In C++ programming, initialization using assignment operator = 
is called implicit initialization,

and initialization using parentheses () and curly braces {} is 
called explicit initialization.

-------

Examples:

We use explicit specifier for constructor to specify that the constructor 
would only be invoked explicitly using parentheses () and curly braces {}. 

The compiler will raise errors if the user tries to invoke an explicit constructor 
using an assignment operator =
*/

/*
Parenthesis VS Braces

    In some scenarios, using parenthesis () will have different effects from using 
    braces {}.

    // An vector of integers containing one element of 2.
    std::vector<int> v1(1, 2);
    // An vector of integers containing two elements, 1 and 2.
    std::vector<int> v2{1, 2};

    While the expressions look ambiguous to the readers, they are not ambiguous 
    to the compiler.

    Using {} automatically invokes std::initializer_list where the corresponding 
    constructor accepts an std::initializer_list parameter.

    Looking at the constructors for std::vector. We do find that std::vector 
    has a corresponding constructor that accepts an std::initializer_list parameter.

    vector(std::initializer_list<T> init, const Allocator& alloc = Allocator());

    So this means {1, 2} is an entirety of std::initializer_list<int> rather 
    than two individual int. 

    Therefore, std::vector<int> v2{1, 2} constructs an vector of integers 
    containing two elements, 1 and 2. Parenthesis () does not have this 
    special effect.

    In addition, using {} will invoke implicit type conversion checking 
    during compilation, whereas () has no such effect.

The previous example was modified so that there will be implicit type 
conversion before invoking the constructor.
*/

#include <iostream>
using namespace std;

class Implicit
{
public:
    Implicit(int v) : mV{v}
    {
        std::cout << "Implicit constructor called." << std::endl;
    }
private:
    int mV;
};

class Explicit
{
public:
    // Use explicit specifier for explicit constructor
    explicit Explicit(int v) : mV{v}
    {
        std::cout << "Explicit constructor called." << std::endl;
    }
private:
    int mV;
};

void implicitExplicitTest1(){
    // Explicit initialization
    Implicit implicit1{1};
    Implicit implicit2(1);
    // Non-explicit initializations might be confusing to readers
    Implicit implicit3 = {1};
    Implicit implicit4 = 1;
    // Default copy constructor called
    Implicit implicit5 = implicit1;

    // Explicit initialization
    Explicit explicit1{1};
    Explicit explicit2(1);
    // explicit specifier prevents non-explicit initialization
    // Explicit explicit3 = {1}; // Invalid
    // Explicit explicit4 = 1; // Invalid
    // Default copy constructor called
    Explicit explicit5 = explicit1;
}

void implicitExplicitTest2(){
    int i = 1;
    // Explicit initialization

    // This will at least throw warning
    Implicit implicit1{i};

    // This will not throw warning
    Implicit implicit2(i);

    // Non-explicit initializations might be confusing to readers

    // This will at least throw warning
    Implicit implicit3 = {i};

    // This will not throw warning
    Implicit implicit4 = i;

    // Explicit initialization
    // This will at least throw warning
    Explicit explicit1{i};
    
    // This will not throw warning
    Explicit explicit2(i);
}

int main()
{
    implicitExplicitTest1();
    cout<<"\n-------\n";
    implicitExplicitTest2();
}

/*
Output:

Implicit constructor called.
Implicit constructor called.
Implicit constructor called.
Implicit constructor called.
Explicit constructor called.
Explicit constructor called.

-------
Implicit constructor called.
Implicit constructor called.
Implicit constructor called.
Implicit constructor called.
Explicit constructor called.
Explicit constructor called.
*/