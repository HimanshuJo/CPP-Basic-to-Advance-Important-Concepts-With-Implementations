/*
Vectors:

	are same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted,
	with their storage being handled automatically by the container.

-------

vector::emplace_back()

	This function is used to insert a new element into the vector container,
		the new element is added to the end of the vector.

	Syntax :

		vectorname.emplace_back(value)

	Parameters :

		The element to be inserted into the vector is passed as the parameter.

	Result :

		The parameter is added to the vector at the end position.

	-------

	Examples:

		Input: 	myvector{1, 2, 3, 4, 5};
	         	myvector.emplace_back(6);

		Output: myvector = 1, 2, 3, 4, 5, 6

		Input: 	myvector{};
	         	myvector.emplace_back(4);

		Output: myvector = 4

-------

Errors and Exceptions:

    It has a strong exception guarantee, therefore, no changes are made if an exception is thrown.

    The parameter should be of the same type as that of the container, otherwise, an error is thrown.
*/

/*
emplace_back() vs push_back()

    push_back():

    	copies a string into a vector.

    	First, a new string object will be implicitly created initialized with provided char*.

    	Then push_back will be called which will copy this string into the vector using the move constructor
    		because the original string is a temporary object.

    		Then the temporary object will be destroyed.


    emplace_back():

    	constructs a string in-place, so no temporary string will be created but rather emplace_back()
    		will be called directly with char* argument.

		It will then create a string to be stored in the vector initialized with this char*.

		So, in this case, we avoid constructing and destroying an unnecessary temporary string object.
*/

#include <iostream>
#include <vector>
using namespace std;

class Version1 {
public:
	void emplaceBackTest() {
		vector<int> myvector;
		myvector.emplace_back(1);
		myvector.emplace_back(2);
		myvector.emplace_back(3);
		myvector.emplace_back(4);
		myvector.emplace_back(5);
		myvector.emplace_back(6);
		for (auto it = myvector.begin(); it != myvector.end(); ++it)
			cout << ' ' << *it;
	}
};

/*
Output:

1 2 3 4 5 6
*/

class Version2 {
public:
	void emplaceBackTest() {
		vector<string> myvector;
		myvector.emplace_back("This");
		myvector.emplace_back("is");
		myvector.emplace_back("a");
		myvector.emplace_back("computer science");
		myvector.emplace_back("portal");
		// vector becomes This, is, a computer science, portal
		for (auto it = myvector.begin(); it != myvector.end(); ++it)
			cout << ' ' << *it;
	}
};

/*
Output:

This is a computer science portal
*/

/*
Application:

Given an empty vector, add integers to it using emplace_back function and then calculate its size.

Input  : 1, 2, 3, 4, 5, 6
Output : 6

Algorithm

    Add elements to the vector using emplace_back function
    Check if the size of the vector is 0, if not, increment the counter variable initialized as 0,
    	and pop the back element.
    Repeat this step until the size of the vector becomes 0.
    Print the final value of the variable.
*/

class Version3 {
public:
	void emplaceBackTest() {
		int count = 0;
		vector<int> myvector;
		myvector.emplace_back(1);
		myvector.emplace_back(2);
		myvector.emplace_back(3);
		myvector.emplace_back(4);
		myvector.emplace_back(5);
		myvector.emplace_back(6);
		while (!myvector.empty()) {
			count++;
			myvector.pop_back();
		}
		cout << count;
	}
};

class Version4 {
public:
	void emplaceBackTest() {
		vector<pair<char, int>> vect;

		// using emplace() to insert pair in-place
		vect.emplace_back('a', 24);

		// Below line would not compile
		// vect.push_back('b', 25);

		// using push_back() to insert
		vect.push_back(make_pair('b', 25));

		for (int i = 0; i < vect.size(); i++)
			cout << vect[i].first << " " << vect[i].second
			     << endl;
	}
};

/*
Output:

	a 24
	b 25
*/

/*
Other Differences:

	Emplace_back will call any type of constructor out there, whereas the more cautious push_back
	will call only constructors that are implicit.

	Implicit constructors are supposed to be safe.

		If you can implicitly construct a U from a T, you are saying that U
		can hold all of the information in T with no loss.

		It is safe in pretty much any situation to pass a T and no one
		will mind if you make it a U instead.

		A good example of an implicit constructor is the conversion from std::uint32_t to std::uint64_t.

		A bad example of an implicit conversion is double to std::uint8_t.
*/

int main() {
	Version1 obj1;
	Version2 obj2;
	Version3 obj3;
	Version4 obj4;
	obj1.emplaceBackTest();
	cout << "\n-------\n";
	obj2.emplaceBackTest();
	cout << "\n-------\n";
	obj3.emplaceBackTest();
	cout << "\n-------\n";
	obj4.emplaceBackTest();
	cout << "\n-------\n";
}