/*
In vector elements are indexed from 0 to size() – 1.

To access any element in vector by index vector provides two member functions i.e.

    at()

    operator[]

-------

Access an element in vector using operator []

	std::vector provides [] operator i.e.

	element_reference operator[] (size_type n);

		It returns the reference of element in vector at index n.

	-------

	Suppose we have a vector of int i.e.

		std::vector<int> vecOfNums{ 1, 4, 5, 22, 33, 2, 11, 89, 49 };

	Let’s access element at index 3 using operator [] i.e.

		// Access element at index 3
		int & element = vecOfNums[3];

	Access and update element in vector using []

		As, operator [] returns a reference to the element in vector,
			so we can change the content of vector too using operator [] i.e.

		// Access and change the value of element at index 3
		vecOfNums[3] = 10;

		It will update the value of element at index 3. New contents of vector will be,

			1, 4, 5, 10, 33, 2, 11, 89, 49

	We can also keep the returned reference in a reference variable and use later to modify the vector i.e.

		// Get the reference of element at index 3
		int & elemRef = vecOfNums[3];

		// Modifying the vector using reference to element at index 3
		elemRef = 22;

		New contents of vector will be,

			1, 4, 5, 22, 33, 2, 11, 89, 49

	-------

	Accessing out of index element through operator []

		While accessing any element through operator [] we need to make sure that given index is in range
			i.e. less than the size of vector,
			otherwise it will result in undefined behavior and can also crash application.

		Therefore we should always check the size before accessing element using operator [] i.e.
		// Accessing out of range element using [] results in undefined behavior
		int index = 100;
		if (index < vecOfNums.size())
		{
		    element = vecOfNums[index];
		}
		else
		    std::cout << "index out of bound" << std::endl;

-------

Access an element in vector using vector::at()

	std::vector provides an another member function at() i.e.

		reference at(size_type n);

	It returns the reference of element at index n in vector.

		If index n is out of range i.e. greater then size of vector then it will throw out_of_range exception.

	Let’s access element at index 3 using at() i.e.

		// Access element at index 3 using at()
		int & numRef = vecOfNums.at(3);

	As at() returns a reference, so we can modify the value of element too i.e.

		// Modifying the element in vector using reference
		numRef = 96;

	Accessing out of range element using at()

		vector::at() will throw out_of_range exception in case we try to access the out of range element i.e.
		// Accessing out of range element using at() will throw out_of_range exception
		try
		{
		    int index = 100;
		    element = vecOfNums.at(index);
		}
		catch (const std::out_of_range & ex)
		{
		    std::cout << "out_of_range Exception Caught :: " << ex.what() << std::endl;
		}

	Output:

		out_of_range Exception Caught :: vector::_M_range_check: __n (which is 100) >= this->size() (which is 9)

-------

vector::operator[] vs vector::at()

	Both operator[] & at() provides random access to elements in vector in O(1) Complexity.

	But in case of out of range access operator[] causes undefined behavior,
		whereas at() returns proper out_of_range exception.

	So, at() is more safe to use as compared to operator[].
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
template <typename T>

void print(T & vecOfElements, std::string delimeter = " , ")
{
	for (auto elem : vecOfElements)
		std::cout << elem << delimeter;
	std::cout << std::endl;
}

int main()
{
	std::vector<int> vecOfNums{ 1, 4, 5, 22, 33, 2, 11, 89, 49 };

	/*
	Accessing element by index in vector using operator[]
	*/

	int & element = vecOfNums[3];
	std::cout << "Original vecOfNums = ";
	print(vecOfNums);
	std::cout << "Element at index 3 is : " << element << std::endl;
	vecOfNums[3] = 10;
	std::cout << "Modified vecOfNums = ";
	print(vecOfNums);
	int & elemRef = vecOfNums[3];
	elemRef = 22;
	std::cout << "Modified vecOfNums = ";
	print(vecOfNums);

	// Accessing out of range element using [] results in undefined behavior
	int index = 100;
	if (index < vecOfNums.size())
	{
		element = vecOfNums[index];
	}
	else
		std::cout << "index out of bound" << std::endl;

	/*
	Accessing element by index in vector using at()
	*/
	int & numRef = vecOfNums.at(3);

	std::cout << "Element at index 3 is : " << numRef << std::endl;

	// Modifying the element in vector using reference
	numRef = 96;
	std::cout << "Modified vecOfNums = ";
	print(vecOfNums);

	// Accessing out of range element using at() will throw out_of_range exception
	try
	{
		int index = 100;
		element = vecOfNums.at(index);
	}
	catch (const std::out_of_range & ex)
	{
		std::cout << "out_of_range Exception Caught :: " << ex.what() << std::endl;
	}
	return 0;
}

/*
Output:

Original vecOfNums = 1, 4, 5, 22, 33, 2, 11, 89, 49,
Element at index 3 is: 22
Modified vecOfNums = 1, 4, 5, 10, 33, 2, 11, 89, 49,
Modified vecOfNums = 1, 4, 5, 22, 33, 2, 11, 89, 49,
index out of bound
Element at index 3 is: 22
Modified vecOfNums = 1, 4, 5, 96, 33, 2, 11, 89, 49,

out_of_range Exception Caught :: vector::_M_range_check: __n (which is 100) >= this->size() (which is 9)
*/