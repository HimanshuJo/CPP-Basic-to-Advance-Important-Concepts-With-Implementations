/*
vector::erase()

	erase() function is used to remove elements from a container from the specified position or range.

Syntax :

	1. vectorname.erase(position)
	2. vectorname.erase(startingposition, endingposition)

Parameters :
	Position of the element to be removed in the form of iterator.
	or the range specified using start and end iterator.

Result :
	Elements are removed from the specified
	position of the container.
*/

/*
Examples:

Input  : myvector= {1, 2, 3, 4, 5}, iterator= myvector.begin()+2
         myvector.erase(iterator);
Output : 1, 2, 4, 5

Input  : myvector= {1, 2, 3, 4, 5, 6, 7, 8}, iterator1= myvector.begin()+3, iterator2= myvector.begin()+6
         myvector.erase(iterator1, iterator2);
Output : 1, 2, 3, 7, 8
*/

/*
Errors and Exceptions
	1. It has a no exception throw guarantee if the position is valid.
	2. Shows undefined behavior otherwise.

-------

The erase method on std::vector is overloaded, so it's probably clearer to call

	vec.erase(vec.begin() + index);

-------

The erase method will be used in two ways:

	Erasing single element:

		vector.erase( vector.begin() + 3 ); // Deleting the fourth element

	Erasing range of elements:
		// Deleting from fourth element to sixth element
		vector.erase( vector.begin() + 3, vector.begin() + 5 );
*/

#include <iostream>
#include <vector>
using namespace std;

class Version1 {
public:
	void eraseTest() {
		vector<int> myvector{ 1, 2, 3, 4, 5 };
		vector<int>::iterator it;
		cout << "original vector " << endl;
		for (auto &vals : myvector) {
			cout << vals << " ";
		}
		cout << endl;
		cout << "Removing at begin" << endl;
		it = myvector.begin();
		myvector.erase(it);
		for (auto it = myvector.begin(); it != myvector.end(); ++it)
			cout << *it << " ";
	}
};

/*
Output:

original vector
1 2 3 4 5
Removing at begin
2 3 4 5
*/

class Version2 {
public:
	void eraseTest() {
		vector<int> myvector{ 1, 2, 3, 4, 5 };
		vector<int>::iterator it1, it2;
		it1 = myvector.begin();
		it2 = myvector.end();
		it2--;
		it2--;
		int idx1 = it1 - myvector.begin();
		int idx2 = it2 - myvector.begin();
		cout << "Removing in a range " << idx1 << " " << idx2 << endl;
		myvector.erase(it1, it2);
		for (auto it = myvector.begin(); it != myvector.end(); ++it)
			cout << *it << " ";
	}
};

/*
Output:

Removing in a range 0 3
4 5
*/

/*
Application:

Given a list of integers, remove all the even elements from the vector and print the vector.

Input : 1, 2, 3, 4, 5, 6, 7, 8, 9
Output : 1 3 5 7 9
Explanation : 2, 4, 6 and 8 which are even are erased from the vector

Algorithm
	1. Run a loop till the size of the vector.
	2. Check if the element at each position is divisible by 2, if yes, remove the element
		and decrement iterator.
	3. Print the final vector.
*/

class Version3 {
public:
	void eraseTest() {
		vector<int> myvector{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		for (auto i = myvector.begin(); i != myvector.end(); ++i) {
			if (*i % 2 == 0) {
				myvector.erase(i);
				i--;
			}
		}
		for (auto it = myvector.begin(); it != myvector.end(); ++it)
			cout << *it << " ";
	}
};

/*
Output:

1 3 5 7 9
*/

/*
How to set up lambda function to use it again:

	auto removeByIndex = []<class T>(std::vector<T> &vec, unsigned int index)
	{
	  	vec.erase(vec.begin() + index);
	};

	// Then you can throw whatever vector at it you desire
	std::vector<std::string> stringvec = {"Hello", "World"};

	// Will remove index 1: "World"
	removeByIndex(stringvec, 1);

	// Vector of integers, we will use push_back
	std::vector<unsigned int> intvec;
	intvec.push_back(33);
	intvec.push_back(66);
	intvec.push_back(99);

	// Will remove index 2: 99
	removeByIndex(intvec, 2);
*/

// Erase while iterating:

class Version4 {
public:
	void eraseTest() {
		std::vector<int> v = {1, 2, 3, 4, 5, 6};
		auto it = v.begin();
		while (it != v.end())
		{
			// specify condition for removing element; in this case remove odd numbers
			if (*it & 1)
			{
				// erase() invalidates the iterator, use returned iterator
				it = v.erase(it);
			}
			// Notice that iterator is incremented only on the else part (why?)
			else
			{
				++it;
			}
		}
		for (int const &i : v)
		{
			std::cout << i << ' ';
		}
	}
};

int main() {
	Version1 obj1;
	Version2 obj2;
	Version3 obj3;
	Version4 obj4;
	obj1.eraseTest();
	cout << "\n-------\n";
	obj2.eraseTest();
	cout << "\n-------\n";
	obj3.eraseTest();
	cout << "\n-------\n";
	obj4.eraseTest();
}