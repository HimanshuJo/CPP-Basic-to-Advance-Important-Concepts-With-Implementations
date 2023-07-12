/*
Allows Duplicates:

	We have discussed unordered_map in our previous post, but there is a limitation, we can not store duplicates
	in unordered_map, that is if we have a key-value pair already in our unordered_multimap and another
	pair is inserted, then both will be there whereas in case of unordered_map the previous value
	corresponding to the key is updated by the new value that is only would be there.

	Even can exist in unordered_multimap twice.

Internal Representation:

	The internal implementation of unordered_multimap is the same as that of unordered_map but for duplicate keys,
	another count value is maintained with each key-value pair.

	As pairs are stored in the hash table, there is no particular order among them but
	pairs with the same keys come together in the data structure whereas pairs with the same
	values are not guaranteed to come together.

Time Complexity:

	All operation on unordered_multimap takes a constant amount of time on average but time can go to
	linear in the worst case depending on internally used hash function but in long run unordered_multimap
	outperforms multimap (tree-based multimap).
*/

// C++ program to demonstrate various function of
// unordered_multimap
#include <bits/stdc++.h>
using namespace std;

// making typedef for short declaration
typedef unordered_multimap<string, int>::iterator unit;

// Utility function to print unordered_multimap
void printUmm(unordered_multimap<string, int> umm)
{
	// begin() returns iterator to first element of map
	unit it = umm.begin();

	for (; it != umm.end(); it++) {
		cout << "<" << it->first << ", " << it->second
		     << "> ";
		cout << endl;
	}
}

int main()
{
	unordered_multimap<string, int> umm1;

	// Initialization by initializer list
	unordered_multimap<string, int> umm2(
	{	{ "apple", 1 },
		{ "ball", 2 },
		{ "apple", 10 },
		{ "cat", 7 },
		{ "dog", 9 },
		{ "cat", 6 },
		{ "apple", 1 }
	});

	// Initialization by assignment operation
	umm1 = umm2;
	printUmm(umm1);

	// empty returns true, if container is empty else it
	// returns false
	if (umm2.empty())
		cout << "unordered multimap 2 is empty\n";
	else
		cout << "unordered multimap 2 is not empty\n";

	// size returns total number of elements in container
	cout << "Size of unordered multimap 1 is "
	     << umm1.size() << endl;

	string key = "apple";

	// find and return any pair, associated with key
	unit it = umm1.find(key);
	if (it != umm1.end()) {
		cout << "\nkey " << key << " is there in unordered "
		     << " multimap 1\n";
		cout << "\none of the value associated with " << key
		     << " is " << it->second << endl;
	}
	else
		cout << "\nkey " << key
		     << " is not there in unordered"
		     << " multimap 1\n";

	// count returns count of total number of pair
	// associated with key
	int cnt = umm1.count(key);
	cout << "\ntotal values associated with " << key
	     << " are " << cnt << "\n\n";

	printUmm(umm2);

	// one insertion by making pair explicitly
	umm2.insert(make_pair("dog", 11));

	// insertion by initializer list
	umm2.insert({ { "alpha", 12 }, { "beta", 33 } });
	cout << "\nAfter insertion of <alpha, 12> and <beta, "
	     "33>\n";
	printUmm(umm2);

	// erase deletes all pairs corresponding to key
	umm2.erase("apple");
	cout << "\nAfter deletion of apple\n";
	printUmm(umm2);

	// clear deletes all pairs from container
	umm1.clear();
	umm2.clear();

	if (umm2.empty())
		cout << "\nunordered multimap 2 is empty\n";
	else
		cout << "\nunordered multimap 2 is not empty\n";
}

/*
<dog, 9>  
<cat, 6>  
<cat, 7>  
<ball, 2>  
<apple, 1>  
<apple, 10>  
<apple, 1>  
unordered multimap 2 is not empty
Size of unordered multimap 1 is 7

key apple is there in unordered  multimap 1

one of the value associated with apple is 1

total values associated with apple are 3

<dog, 9>  
<cat, 6>  
<cat, 7>  
<ball, 2>  
<apple, 1>  
<apple, 10>  
<apple, 1>  

After insertion of <alpha, 12> and <beta, 33>
<alpha, 12>  
<dog, 11>  
<dog, 9>  
<beta, 33>  
<cat, 6>  
<cat, 7>  
<ball, 2>  
<apple, 1>  
<apple, 10>  
<apple, 1>  

After deletion of apple
<alpha, 12>  
<dog, 11>  
<dog, 9>  
<beta, 33>  
<cat, 6>  
<cat, 7>  
<ball, 2>  

unordered multimap 2 is empty
*/