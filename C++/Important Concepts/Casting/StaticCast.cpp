/*
A Cast operator is an unary operator which forces one data type to be 
converted into another data type.

C++ supports four types of casting:

	1. Static Cast
	2. Dynamic Cast
	3. Const Cast
	4. Reinterpret Cast

-------

Static Cast: 

	This is the simplest type of cast which can be used. 

	It is a compile time cast.

	It does things like implicit conversions between 
	types (such as int to float, or pointer to void*), and it can also call 
	explicit conversion functions (or implicit ones).
*/

#include <iostream>
using namespace std;

class Int {
	int x;

public:
	Int(int x_in = 0): x{ x_in }
	{
		cout << "Conversion Ctor called" << endl;
	}
	operator string()
	{
		cout << "Conversion Operator" << endl;
		return to_string(x);
	}
};

void staticCastTest2(){
	Int obj(3);
	string str = obj;
	obj = 20;
	string str2 = static_cast<string>(obj);
	obj = static_cast<Int>(30);
}

void staticCastTest1(){
	float f = 3.5;
	int a = f; // this is how you do in C
	int b = static_cast<int>(f);
	cout << b; // 3
	char c = 'a';

	// pass at compile time, may fail at run time
	int* q = (int*)&c;
	/*
	If you compile the code below, you will get an error:

	[Error] invalid static_cast from type 'char*' to type 'int*'

	This means that even if you think you can some how typecast a 
	particular object int another but its illegal, static_cast will 
	not allow you to do this.
	*/
	// int* p = static_cast<int*>(&c);
}

int main()
{
	staticCastTest1();
	cout<<"\n------- ******* -------\n";
	staticCastTest2();
	/*
	Output:
		Conversion Ctor called
		Conversion Operator
		Conversion Ctor called
		Conversion Operator
		Conversion Ctor called
	*/
	/*
		
	Lets the try to understand the above output:

	When obj is created then constructor is called which in our case is also a 
	Conversion Constructor(For C++14 rules are bit changed).
	
	When you create str out of obj, compiler will not thrown an error as we have 
	defined the Conversion operator.
	
	When you make obj=20, you are actually calling the conversion constructor.
	
	When you make str2 out of static_cast, it is quite similar to string str=obj;, 
	but with a tight type checking.
	
	When you write obj=static_cast<Int>(30), you are converting 30 into Int using static_cast.
	*/
}