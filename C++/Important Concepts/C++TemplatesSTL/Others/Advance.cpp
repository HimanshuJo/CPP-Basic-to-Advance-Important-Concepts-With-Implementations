/*
std::advance advances the iterator ‘it’ by n element positions. Syntax :

template
    void advance (InputIterator& it, Distance n);

it : Iterator to be advanced
n : Number of element positions to advance.
This shall only be negative for random-access and bidirectional iterators.

Return type :
None.
Motivation problem : A vector container is given. Task is to print alternate elements. Examples :

Input : 10 40 20 50 80 70
Output : 10 20 80
*/

#include <bits/stdc++.h>

int main()
{
	std::vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(i * 10);
	for (int i = 0; i < 10; i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	std::vector<int>::iterator it = vec.begin();
	while (it < vec.end()) {
		std::cout << *it << " ";
		std::advance(it, 2);
	}
}

/*
Output:

0 10 20 30 40 50 60 70 80 90
0 20 40 60 80
*/