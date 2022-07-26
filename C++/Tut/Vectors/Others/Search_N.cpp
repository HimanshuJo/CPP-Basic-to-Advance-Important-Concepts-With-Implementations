/*
std::search_n:

    is an STL algorithm defined inside the header file, which is used to search
    whether a given element satisfies a predicate (equality if no such predicate is defined )
    a given no. of times consecutively with the container elements.

    It searches the range [first, last) for a sequence of count elements, each comparing
    equal to a given value (version 1) or satisfying a predicate (version 2).

    The function returns an iterator to the first of such elements, or an iterator to the
    last element of the container, if no such sequence is found.

    -------

    The two versions of std::search_n are defined as below –

    For comparing elements using ==:

        Syntax:

            ForwardIterator search_n (ForwardIterator first, ForwardIterator last,
                                      Size count, const T& val);

        first:

            Forward iterator to beginning of the container to be searched into.

        last:

            Forward iterator to end of the container to be searched into.

        count:

            Minimum number of successive elements to match.

            Size shall be (convertible to) an integral type.

        val:

            Individual value to be compared.

        -------

        Returns:

            It returns an iterator to the first element of the sequence.

            If no such sequence is found, the function returns last.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int i, j;

    // Declaring the sequence to be searched into
    vector<int> v1 = { 1, 2, 3, 4, 5, 3, 3, 6, 7 };

    // Declaring the value to be searched for
    int v2 = 3;

    // Declaring an iterator for storing the returning pointer
    vector<int>::iterator i1;

    // Using std::search_n and storing the result in
    // iterator i1
    i1 = std::search_n(v1.begin(), v1.end(), 2, v2);

    // checking if iterator i1 contains end pointer of v1 or not
    if (i1 != v1.end()) {
        cout << "v2 is present consecutively 2 times at index "
             << (i1 - v1.begin());
    } else {
        cout << "v2 is not present consecutively 2 times in "
             << "vector v1";
    }

    return 0;
}

/*
Output:

v2 is present consecutively 2 times at index 5
*/

/*
For comparing element using a predicate:

    Syntax:

        ForwardIterator search_n (ForwardIterator first, ForwardIterator last,
                                  Size count, const T& val, BinaryPredicate pred );

    All the arguments are same as previous template, just one more argument is added

        pred:

            Binary function that accepts two arguments
            (one element from the sequence as first, and val as second),
            and returns a value convertible to bool.

            The value returned indicates whether the element is considered a match
            in the context of this function.

            The function shall not modify any of its arguments.

            This can either be a function pointer or a function object.

        Returns:

            It also returns value as per the previous version, i.e., an iterator to the
            first element of the sequence, satisfying a condition with respect to a given value.

            If no such sequence is found, the function returns last.
*/