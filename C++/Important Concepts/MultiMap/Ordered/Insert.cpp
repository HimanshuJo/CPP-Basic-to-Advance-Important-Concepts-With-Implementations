/*
std::multimap::insert

    single element (1)
        iterator insert (const value_type& val);

    with hint (2)
        iterator insert (iterator position, const value_type& val);

    range (3)
        template <class InputIterator>
            void insert (InputIterator first, InputIterator last);

-------

Insert element

    Extends the container by inserting new elements, effectively increasing the container size by
        the number of elements inserted.

    Internally, multimap containers keep all their elements sorted by key following the criterion
        specified by its comparison object.

        The elements are always inserted in its respective position following this ordering.

-------

Return value

    In the versions returning a value, this is an iterator pointing to the newly inserted element in the multiset.

    Member type iterator is a bidirectional iterator type that points to elements.
*/

#include <iostream>
#include <map>

int main ()
{
    std::multimap<char, int> mymultimap;
    std::multimap<char, int>::iterator it;

    // first insert function version (single parameter):
    mymultimap.insert ( std::pair<char, int>('a', 100) );
    mymultimap.insert ( std::pair<char, int>('z', 150) );
    it = mymultimap.insert ( std::pair<char, int>('b', 75) );

    // second insert function version (with hint position):
    mymultimap.insert (it, std::pair<char, int>('c', 300)); // max efficiency inserting
    mymultimap.insert (it, std::pair<char, int>('z', 400)); // no max efficiency inserting

    // third insert function version (range insertion):
    std::multimap<char, int> anothermultimap;
    anothermultimap.insert(mymultimap.begin(), mymultimap.find('c'));

    std::cout << "mymultimap contains:\n";
    for (it = mymultimap.begin(); it != mymultimap.end(); ++it)
        std::cout << (*it).first << " => " << (*it).second << '\n';

    std::cout << "anothermultimap contains:\n";
    for (it = anothermultimap.begin(); it != anothermultimap.end(); ++it)
        std::cout << (*it).first << " => " << (*it).second << '\n';

    return 0;
}

/*
Output:
    mymultimap contains:
    a => 100
    b => 75
    c => 300
    z => 400
    z => 150
    anothermultimap contains:
    a => 100
    b => 75

-------

Complexity

    If a single element is inserted, logarithmic in size in general, but amortized constant if a hint is given
        and the position given is the optimal.
*/