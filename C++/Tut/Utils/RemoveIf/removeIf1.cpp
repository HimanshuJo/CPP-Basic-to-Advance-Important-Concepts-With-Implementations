/*
C++ Algorithm remove_if()
C++ Algorithm remove_if() function is used to eliminate all the elements that satisfy a predicate from a 
given range [first, last) without disturbing the order of the remaining elements.

This function cannot alter the size of the container.
It returns an iterator to the new end of the range.
Remove is stable, means that the relative order of the elements that are not removed is remain unchanged.

-------

Syntax
template <class ForwardIterator, class UnaryPredicate>  
ForwardIterator remove_if (ForwardIterator first, ForwardIterator last, UnaryPredicate pred);  

-------

Parameter
first: A forward iterator pointing the position of the first element in the range from which elements are being removed.

last: A forward iterator pointing the position one past the final element in the range from which elements are being removed.

pred: The unary predicate function which accepts an element as an argument that must be satisfied is the value of an element is to be replaced.

Return value
A forward iterator pointing the new end position (last) of the modified range or first element if first and last is equal.

Complexity
Complexity is linear in the range [first, last): Applies pred to each element, and possibly performs assignments on some of them.

Data races
The object in the range [first, last) are accessed and potentially modified.

Exception safety
This function throws an exception if any of pred, the element assignments or the operation on an iterator throws an exception.
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool IsOdd(int i)
{
    return ((i % 2) == 1);
}

int main()
{
    vector<int> vec2{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    //store the position of last element
    vector<int>::iterator pend;

    // Print original vector
    cout << "\nOriginal vector : ";
    for (int i = 0; i < vec2.size(); i++)
        cout << " " << vec2[i];
    cout << "\n";

    // remove_if function call
    pend = remove_if(vec2.begin(), vec2.end(), IsOdd);

    // Print the vector
    cout << "After remove_if : ";
    for (vector<int>::iterator q = vec2.begin(); q != pend; ++q)
        cout << ' ' << *q;
    cout << '\n';

    return 0;
}

/*
Output:
Original vector :  1 2 3 4 5 6 7 8 9 10
After remove_if :  2 4 6 8 10
*/