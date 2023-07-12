/*
public member function

<vector>

std::vector::size

	Return size

		Returns the number of elements in the vector.

		This is the number of actual objects held in the vector, which is not necessarily equal to
			its storage capacity.
*/

#include <iostream>
#include <vector>

int main ()
{
	std::vector<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i = 0; i < 10; i++) myints.push_back(i);
	std::cout << "1. size: " << myints.size() << '\n';

	myints.insert (myints.end(), 10, 100);
	std::cout << "2. size: " << myints.size() << '\n';

	myints.pop_back();
	std::cout << "3. size: " << myints.size() << '\n';

	return 0;
}