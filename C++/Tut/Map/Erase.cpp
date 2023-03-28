/*
map::erase() 

	is a built-in function in C++ STL which is used to erase element 
    from the container. 

	It can be used to erase keys, elements at any specified position or 
    a given range. 

Syntax for erasing a key:

	map_name.erase(key)

Parameters: The function accepts one mandatory parameter key which 
specifies the key to be erased in the map container. 

Return Value: The function returns 1 if the key element is found in the 
map else returns 0. 
*/

#include <bits/stdc++.h>
using namespace std;

void mapTest1(){
	// initialize container
	map<int, int> mp;

	// insert elements in random order
	mp.insert({ 2, 30 });
	mp.insert({ 1, 40 });
	mp.insert({ 3, 60 });
	mp.insert({ 5, 50 });

	// prints the elements
	cout << "The map before using erase() is : \n";
	cout << "KEY\tELEMENT\n";
	for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
		cout << itr->first << '\t' << itr->second << '\n';
	}

	// function to erase given keys
	mp.erase(1);
	mp.erase(2);

	// prints the elements
	cout << "\nThe map after applying erase() is : \n";
	cout << "KEY\tELEMENT\n";
	for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
		cout << itr->first << '\t' << itr->second << '\n';
	}
}

void mapTest2(){
	// initialize container
	map<int, int> mp;
	// insert elements in random order
	mp.insert({ 2, 30 });
	mp.insert({ 1, 40 });
	mp.insert({ 3, 60 });
	mp.insert({ 5, 50 });

	// prints the elements
	cout << "The map before using erase() is : \n";
	cout << "KEY\tELEMENT\n";
	for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
		cout << itr->first << '\t' << itr->second << '\n';
	}

	// function to erase given position
	auto it = mp.find(2);
	mp.erase(it);

	auto it1 = mp.find(5);
	mp.erase(it1);

	// prints the elements
	cout << "\nThe map after applying erase() is : \n";
	cout << "KEY\tELEMENT\n";
	for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
		cout << itr->first << '\t' << itr->second << '\n';
	}
}

void mapTest3(){
    // initialize container
    map<int, int> mp;
    // insert elements in random order
    mp.insert({ 2, 30 });
    mp.insert({ 1, 40 });
    mp.insert({ 3, 60 });
    mp.insert({ 2, 20 });
    mp.insert({ 5, 50 });

    // prints the elements
    cout << "The map before using erase() is : \n";
    cout << "KEY\tELEMENT\n";
    for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
        cout << itr->first << '\t' << itr->second << '\n';
    }

    // function to erase in a given range
    // find() returns the iterator reference to
    // the position where the element is
    auto it1 = mp.find(2);
    auto it2 = mp.find(5);
    mp.erase(it1, it2);

    // prints the elements
    cout << "\nThe map after applying erase() is : \n";
    cout << "KEY\tELEMENT\n";
    for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
        cout << itr->first << '\t' << itr->second << '\n';
    }
}

int main()
{
    mapTest1();
    cout<<"\n-------\n";
    mapTest2();
    cout<<"\n-------\n";
    mapTest3();
	return 0;
}