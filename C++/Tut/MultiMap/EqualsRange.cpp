/*
Multimap store elements in key value pair. It can also have duplicate keys.

There can be many scenarios when we want to find all the values associated with a key in multimap.

For example, we have a multimap of char & int as key value pair and initialzed with following values i.e.

{'a', 1},
{'b', 2},
{'c', 3},
{'a', 4},
{'c', 5},
{'c', 6},
{'d', 7},

There are 3 pairs with duplicate key ‘c’. 

Values associated with key ‘c’ are 3,5 & 6. 

Now let’s see how to access all the values associated with a key in multimap.

-------

std::multimap::equal_range

	We can find all values of a key in Multimap using is member function equal_range().
		
		pair<iterator, iterator>equal_range(const key_type& k);

	It accepts the key as an argument and returns a pair of multimap iterator. 

	This returned pair has a range that represents the entries with given key.
*/

#include <iostream>
#include <map>
#include <iterator>
#include <algorithm>

int main()
{
    std::multimap<char, int> mmapOfPos ={
        {'a', 1},
        {'b', 2},
        {'c', 3},
        {'a', 4},
        {'c', 5},
        {'c', 6},
        {'d', 7},
    };
    typedef std::multimap<char, int>::iterator MMAPIterator;
    // It returns a pair representing the range of elements with key equal to 'c'
    std::pair<MMAPIterator, MMAPIterator> result = mmapOfPos.equal_range('c');
    std::cout << "All values for key 'c' are," << std::endl;
    // Iterate over the range
    for (MMAPIterator it = result.first; it != result.second; it++)
        std::cout << it->second << std::endl;
    // Total Elements in the range
    int count = std::distance(result.first, result.second);
    std::cout << "Total values for key 'c' are : " << count << std::endl;
    return 0;
}

/*
All values for key 'c' are,
3
5
6
Total values for key 'c' are : 3
*/