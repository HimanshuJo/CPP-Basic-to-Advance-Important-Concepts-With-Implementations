/*
The function is defined in header <algorithm>.

    It rotates the order of the elements in the range [first,last], in such a way that
        the element pointed by middle becomes the new first element.

-------

Function Template :

    void rotate(ForwardIterator first, ForwardIterator middle, ForwardIterator last)

        first, last:

            Forward Iterators to the initial and final positions of the sequence to be rotated

        middle:

            Forward Iterator pointing to the element within the range [first, last]
            that is moved to the first position in the range.

-------

Types of Rotations:

    Left Rotation:

        To rotate left, we need to add the vector index.

        For example, you have to rotate vector left 3 times.

            The 3th index of vector becomes first element.

                vec.begin() + 3 will rotate vector 3 times left.

    Right Rotation:

        To rotate right, we need to subtract the vector index.

        For example, you have to rotate vector right 3 times.

            The 3th last index of vector becomes first element.

                vec.begin()+vec.size()-3 will rotate vector 3 times right.

*/
/*
Examples:

    Input : 1 2 3 4 5 6 7 8 9
    Output :
    Old vector : 1 2 3 4 5 6 7 8 9
    New vector : 4 5 6 7 8 9 1 2 3 // Rotated at 3th position, starting index as 0.


    Input : 8 2 4 6 11 0 15 8
    Output :
    Old vector : 8 2 4 6 11 0 15 8
    New vector : 0 15 8 8 2 4 6 11 // Rotated at 5th position, starting index as 0.

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::vector<int> vec1{1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Print old vector
    std::cout << "Old vector :";
    for (int i = 0; i < vec1.size(); i++)
        std::cout << " " << vec1[i];
    std::cout << "\n";
    // Rotate vector left 3 times.
    int rotL = 3;

    // std::rotate function
    std::rotate(vec1.begin(), vec1.begin() + rotL, vec1.end());

    std::cout << "New vector after left rotation :";
    for (int i = 0; i < vec1.size(); i++)
        std::cout << " " << vec1[i];
    std::cout << "\n\n";

    std::vector<int> vec2{1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << "Old vector :";
    for (int i = 0; i < vec2.size(); i++)
        std::cout << " " << vec2[i];
    std::cout << "\n";

    // Rotate vector right 4 times.
    int rotR = 4;

    // std::rotate function
    std::rotate(vec2.begin(), vec2.begin() + vec2.size() - rotR, vec2.end());

    std::cout << "New vector after right rotation :";
    for (int i = 0; i < vec2.size(); i++)
        std::cout << " " << vec2[i];
    std::cout << "\n";

    return 0;
}

/*
Output:

    Old vector : 1 2 3 4 5 6 7 8 9
    New vector after left rotation : 4 5 6 7 8 9 1 2 3

    Old vector : 1 2 3 4 5 6 7 8 9
    New vector after right rotation: 6 7 8 9 1 2 3 4 5
*/