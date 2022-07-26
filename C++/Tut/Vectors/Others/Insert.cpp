/*
Insert element in vector at specific position | vector::insert() examples:

	Vector provides different overloaded version of member function insert(),
		to insert one or more elements in between existing elements.

	-------

	Inserting a single element at specific position in vector

		We are going to use first overloaded version of Vector’s insert() function i.e.

			iterator insert (const_iterator pos, const value_type& val);

		It Inserts a copy of give element “val”, before the iterator position “pos”
			and also returns the iterator pointing to new inserted element.

	-------

	Suppose we have a vector of int i.e.

		std::vector<int> vecOfNums { 1, 4, 5, 22, 33, 2, 11, 89, 49 };

	Now we want to insert an element at index position 4th (In vector position index start from 0),

		// Create Iterator pointing to 4th Position
		auto itPos = vecOfNums.begin() + 4;

		// Insert element with value 9 at 4th Position in vector
		auto newIt = vecOfNums.insert(itPos, 9);

		Vector’s contents will be now,

			1, 4, 5, 22, 9, 33, 2, 11, 89, 49

		Inserting an element in vector will increase the vector size by 1.

			As in vector all elements are stored at continuous memory locations,

			So inserting an element in between will cause all the elements in
				right to shift or complete reallocation of all elements.

-------

Inserting multiple elements or a range at specific position in vector:

	For this, vector provides an overloaded version of insert() function to insert multiple elements i.e.

		iterator insert (const_iterator pos, InputIterator first, InputIterator last);

	It inserts the elements in range from [first, end) before iterator position pos and
		returns the iterator pointing to position first newly added element.

	-------

	Let’s understand by an example,

		Suppose we have 2 vectors of strings i.e.

		std::vector<std::string> vec1 { "at" , "hello", "hi", "there", "where", "now", "is", "that" };

		std::vector<std::string> vec2 { "one" , "two", "two" };

	Now insert all the elements in vec2 at position 3 in vec1 i.e.

		// Insert all the elements in vec2 at 3rd position in vec1

			auto iter = vec1.insert(vec1.begin() + 3, vec2.begin(), vec2.end());

	Contents of vec1 will be now,

		at, hello, hi, one, two, two, there, where, now, is, that,

-------

Inserting multiple elements using Initializer list:

	Another overloaded version of vector’s insert() function is as follows,

		iterator insert (const_iterator position, initializer_list<value_type> list);

	It copies all the elements in given initializer list before given iterator position pos
		and also returns the iterator of first of the newly added elements.

		Suppose we have vector of int i.e.

			std::vector<int> vecOfInts { 1, 4, 5, 22, 33, 2, 11, 89, 49 };

		Let’s add all elements in initialisation list to the existing vector i.e.

			// Insert all elements from initialization_list to vector at 3rd position

				auto iter2 = vecOfInts.insert(vecOfInts.begin() + 3, {34,55,66,77});

		Contents of vecOfInts will be now,

			1, 4, 5, 34, 55, 66, 77, 22, 33, 2, 11, 89, 49

-------

vector.insert() and Iterator invalidation:

	Inserting elements in vector will cause existing elements to shift places or
	sometimes complete reallocation, which will invalidates all the existing iterators.
*/

#include <iterator>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
template <typename T>

void print(T & vecOfElements, std::string delimeter = ", ")
{
	int sz = vecOfElements.size();
	for (int i = 0; i < sz; ++i)
		std::cout << vecOfElements[i] << (i != sz - 1 ? delimeter : "");
	std::cout << std::endl;
}

int main()
{
	std::vector<int> vecOfNums { 1, 4, 5, 22, 33, 2, 11, 89, 49 };

	/*
	 * Inserting an element at specific position in vector
	*/

	// Create Iterator pointing to 4th Position
	auto itPos = vecOfNums.begin() + 4;

	// Insert element with value 9 at 4th Position in vector
	auto newIt = vecOfNums.insert(itPos, 9);

	std::cout << "Element added in vector is : " << *newIt << std::endl;
	std::cout << "Modified vecOfNums = ";
	print(vecOfNums);

	/*
	 * Inserting multiple elements / range at specific position in vector
	*/

	std::vector<std::string> vec1 { "at" , "hello", "hi", "there", "where", "now", "is", "that" };
	std::vector<std::string> vec2 { "one" , "two", "two" };

	// Insert all the elements in vec2 at 3rd position in vec1
	auto iter = vec1.insert(vec1.begin() + 3, vec2.begin(), vec2.end());

	std::cout << "First of the newly added elements : " << *iter << std::endl;
	std::cout << "Modified vec1 = ";
	print(vec1);

	/*
	 * Inserting all elements in initialization_list in another vector
	 * at specific position.
	*/

	std::vector<int> vecOfInts { 1, 4, 5, 22, 33, 2, 11, 89, 49 };

	// Insert all elements from initialization_list to vector at 3rd position
	auto iter2 = vecOfInts.insert(vecOfInts.begin() + 3, {34, 55, 66, 77});

	std::cout << "First of the newly added elements : " << *iter2 << std::endl;
	std::cout << "Modified vecOfInts = ";
	print(vecOfInts);
	return 0;
}

/*
Output:

Element added in vector is : 9
Modified vecOfNums = 1, 4, 5, 22, 9, 33, 2, 11, 89, 49
First of the newly added elements : one
Modified vec1 = at, hello, hi, one, two, two, there, where, now, is, that
First of the newly added elements : 34
Modified vecOfInts = 1, 4, 5, 34, 55, 66, 77, 22, 33, 2, 11, 89, 49
*/