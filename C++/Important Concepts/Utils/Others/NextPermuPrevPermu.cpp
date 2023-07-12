/*
std::next_permutation and prev_permutation in C++

    std::next_permutation

        It is used to rearrange the elements in the range [first, last) 
        into the next lexicographically greater permutation. 
        
        A permutation is each one of the N! possible arrangements the 
        elements can take (where N is the number of elements in the range). 
        
        Different permutations can be ordered according to how they 
        compare lexicographically to each other.
        
        The complexity of the code is O(n*n!) which also includes printing all the 
        permutations.

        -------

        Syntax: 

        template 
        bool next_permutation (BidirectionalIterator first, BidirectionalIterator last);

        Parameters: 

            first, last : Bidirectional iterators to the initial
            and final positions of the sequence. The range 
            used is [first, last), which contains all the elements 
            between first and last, including the element pointed 
            by first but not the element pointed by last.

        return value:

            true : if the function could rearrange 
            the object as a lexicographically greater permutation.
            Otherwise, the function returns false to indicate that 
            the arrangementis not greater than the previous, 
            but the lowest possible (sorted in ascending order).

        -------

        Application : next_permutation is to find next lexicographically greater 
        value for given array of values.

        Examples: 

        Input : next permutation of 1 2 3 is 
        Output : 1 3 2

        Input : next permutation of 4 6 8 is 
        Output : 4 8 6
*/

/*
    std::prev_permutation

        It is used to rearranges the elements in the range [first, last) 
        into the previous lexicographically-ordered permutation.
        
        A permutation is each one of the N! possible arrangements the elements 
        can take (where N is the number of elements in the range). 
        
        Different permutations can be ordered according to how they compare 
        lexicographically to each other.

        -------

        Syntax : 

        template 
        bool prev_permutation (BidirectionalIterator first, BidirectionalIterator last );

        parameters:

            first, last : Bidirectional iterators to the initial
            and final positions of the sequence. The range 
            used is [first, last), which contains all the
            elements between first and last, including 
            the element pointed by first but not the element
            pointed by last.

        return value:
            
            true : if the function could rearrange 
            the object as a lexicographically smaller permutation.
            Otherwise, the function returns false to indicate that 
            the arrangement is not less than the previous, 
            but the largest possible (sorted in descending order).

        -------

        Application : prev_permutation is to find previous lexicographically smaller 
        value for given array of values.

        Examples: 

        Input : prev permutation of 3 2 1 is 
        Output : 3 1 2 

        Input : prev permutation of 8 6 4 is 
        Output : 8 4 6
*/

#include <algorithm>
#include <iostream>
using namespace std;

void nextPermuationTest1(int arr[]){
    sort(arr, arr + 3);

    cout << "The 3! possible permutations with 3 elements:\n";
    do {
        cout << arr[0] << " " << arr[1] << " " << arr[2] << "\n";
    } while (next_permutation(arr, arr + 3));

    cout << "After loop: " << arr[0] << ' '
        << arr[1] << ' ' << arr[2] << '\n';
}

void nextPermutationTest2(int arr[]){
    sort(arr, arr + 4);

    cout << "The 4! possible permutations with 3 elements:\n";
    cout << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << "\n";
    while (next_permutation(arr, arr + 4))
    {
        cout << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << "\n";
    }
    cout << "After loop: " << arr[0] << ' '
            << arr[1] << ' ' << arr[2] << " " << arr[3] << '\n';
}

void prevPermuationTest1(int arr[]){
    sort(arr, arr + 3);
    reverse(arr, arr + 3);

    cout << "The 3! possible permutations with 3 elements:\n";
    do {
        cout << arr[0] << " " << arr[1] << " " << arr[2] << "\n";
    } while (prev_permutation(arr, arr + 3));

    cout << "After loop: " << arr[0] << ' ' << arr[1]
        << ' ' << arr[2] << '\n';
}

int main()
{
    int arr[] = { 1, 2, 3 };
    nextPermuationTest1(arr);
    int arr2[] = {1, 2, 3, 4};
    nextPermutationTest2(arr2);
    int arr3[] = {1, 2, 3};
    prevPermuationTest1(arr3);
}

/*
    Output: 

    The 3! possible permutations with 3 elements:
    1 2 3
    1 3 2
    2 1 3
    2 3 1
    3 1 2
    3 2 1
    After loop: 1 2 3

    -------

    1 2 3 4
    1 2 4 3
    1 3 2 4
    1 3 4 2
    1 4 2 3
    1 4 3 2
    2 1 3 4
    2 1 4 3
    2 3 1 4
    2 3 4 1
    2 4 1 3
    2 4 3 1
    3 1 2 4
    3 1 4 2
    3 2 1 4
    3 2 4 1
    3 4 1 2
    3 4 2 1
    4 1 2 3
    4 1 3 2
    4 2 1 3
    4 2 3 1
    4 3 1 2
    4 3 2 1
    After loop: 1 2 3 4

    -------

    The 3! possible permutations with 3 elements:
    3 2 1
    3 1 2
    2 3 1
    2 1 3
    1 3 2
    1 2 3
    After loop: 3 2 1

*/
