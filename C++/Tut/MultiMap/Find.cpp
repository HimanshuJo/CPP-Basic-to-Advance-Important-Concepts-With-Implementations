/*
std::multimap::find

	iterator find (const key_type& k);
	const_iterator find (const key_type& k) const;

Get iterator to element:

	Searches the container for an element with a key equivalent to k and returns an
	iterator to it if found, otherwise it returns an iterator to multimap::end.

	Notice that this function returns an iterator to a single element
	(of the possibly multiple elements with equivalent keys).

	To obtain the entire range of equivalent elements, see multimap::equal_range.

	Two keys are considered equivalent if the container's comparison object returns false
	reflexively (i.e., no matter the order in which the elements are passed as arguments).

Parameters:

	k

		Key to be searched for.

		Member type key_type is the type of the keys for the elements in the container,
		defined in multimap as an alias of its first template parameter (Key).

Return value:

	An iterator to the element, if an element with specified key is found, or multimap::end otherwise.

	If the multimap object is const-qualified, the function returns a const_iterator.

		Otherwise, it returns an iterator.

	Member types iterator and const_iterator are bidirectional iterator types pointing to
	elements (of type value_type).

	Notice that value_type in multimap containers is an alias of pair<const key_type, mapped_type>.
*/

// multimap::find
#include <iostream>
#include <map>

int main ()
{
	std::multimap<char, int> mymm;

	mymm.insert (std::make_pair('x', 10));
	mymm.insert (std::make_pair('y', 20));
	mymm.insert (std::make_pair('z', 30));
	mymm.insert (std::make_pair('z', 40));

	std::multimap<char, int>::iterator it = mymm.find('x');
	mymm.erase (it);
	mymm.erase (mymm.find('z'));

	// print content:
	std::cout << "elements in mymm:" << '\n';
	std::cout << "y => " << mymm.find('y')->second << '\n';
	std::cout << "z => " << mymm.find('z')->second << '\n';

	return 0;
}

/*
Output:
elements in mymm:
y => 20
z => 40
*/