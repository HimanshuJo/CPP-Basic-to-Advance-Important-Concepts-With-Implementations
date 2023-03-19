/*
How to access/delete a specific value for a key? 

If we want to check whether a specific value is there or not, we need to loop over all pairs of 
key-value until we get our specific value, if we get our specific value in the unordered_multimap then use 
erase(position) method to delete that specific value from unordered_multimap. 
*/

#include <bits/stdc++.h>
using namespace std;

// Utility function to print unordered_multimap
void printUmm(unordered_multimap<string, int>& umm)
{

	// Iterator pointing to first element of unordered_map
	auto it1 = umm.begin();

	for (; it1 != umm.end(); it1++) {
		cout << "<" << it1->first << ", " << it1->second
			<< "> ";
		cout << endl;
	}
}

int main()
{

	// Initialization by intializer list
	unordered_multimap<string, int> umm{
		{ "apple", 1 }, { "ball", 2 }, { "apple", 10 },
		{ "cat", 7 }, { "dog", 9 }, { "cat", 6 },
		{ "apple", 1 }
	};

	// Iterator pointing to first element of unordered_map
	auto it = umm.begin();

	// Search for an element with value 1
	while (it != umm.end()) {
		if (it->second == 1)
			break;
		it++;
	}

	// Erase the element pointed by iterator it
	if (it != umm.end())
		umm.erase(it);
	
	cout << "After deletion of value 1 from umm" << endl;
	printUmm(umm);

	return 0;
}

/*
Output
After deletion of value 1 from umm
<dog, 9>  
<cat, 6>  
<cat, 7>  
<ball, 2>  
<apple, 10>  
<apple, 1> 
*/