/*
Insertion Sort:

    Insertion sort is a simple sorting algorithm that builds the final sorted array
        (or list) one item at a time.

        that means, for the current item, sorting technique will first check the suitable
            place for that item in the list and then put it right there

        it then progress to the next item in the list

    It is much less efficient on large lists than more advanced algorithms such as
        quicksort, heapsort, or merge sort.

    However, insertion sort provides several advantages:

        1. Efficient for (quite) small data sets, much like other quadratic sorting algorithms

        2. More efficient in practice than most other simple quadratic (i.e., O(n^2))
            algorithms such as selection sort or bubble sort

        3. Adaptive, i.e., efficient for data sets that are already substantially sorted:
            the time complexity is O(kn) when each element in the input is no more
            than k places away from its sorted position

        4. Stable; i.e., does not change the relative order of elements with equal keys

        5. In-place; i.e., only requires a constant amount O(1) of additional memory space

        6. Online; i.e., can sort a list as it receives it

-------

Complexity:

    Best: Omega(n)

    Average: O(n^2)

    Worst: O(n^2)

-------

How does it work:

    Insertion sort iterates, consuming one input element each repetition,
        and grows a sorted output list.

    At each iteration, insertion sort removes one element from the input data,
        finds the location it belongs within the sorted list, and inserts it there.

    It repeats until no input elements remain.

    Sorting is typically done in-place, by iterating up the array,
        growing the sorted list 'behind it'.

    At each array-position, it checks the value there against the largest value
        in the sorted list (which happens to be next to it, in the previous array-position checked)

    If larger, it leaves the element in place and moves to the next.

        If smaller, it finds the correct position within the sorted list,
            shifts all the larger values up to make a space, and inserts into that correct position.

    The resulting array after k iterations has the property where the first k + 1
        entries are sorted ("+1" because the first entry is skipped)

-------

Pseudocode of the complete algorithm follows, where the arrays are zero-based:

    i <- 1
    while i < length(A)
        j <- i
        while j > 0 and A[j - 1] > A[j]
            swap A[j] and A[j - 1]
            j <- j - 1
        end while
        i <- i + 1
    end while

    -------

    The outer loop runs over all the elements except the first one,
        because the single-element prefix A[0:1] is trivially sorted, so the
        invariant that the first i entries are sorted is true from the start

    The inner loop moves element A[i] to its correct place so that after the loop, the first
        i + 1 elements are sorted

        Note that the 'and' operator in the test must use 'short-circuit evaluation', otherwise
            the test might result in an array bounds error

            when j = 0 and tries to evaluate A[j - 1] > A[j] (i.e accessing A[-1] fails)

    After expanding the swap operation in-place as
        x <- A[j]
        A[j] <- A[j - 1]
        A[j - 1] <- x

        where x is a temporary variable

        -------

        A slightly faster version can be produced that moves A[i] to its position in one go,
            and only performs one assignment in the inner loop body

-------

Slightly improved Pseudocode

    i <- 1
    while i < length[A]
        x <- A[i]
        j <- i - 1
        while j >= 0 and A[j] > x
            A[j + 1] <- A[j]
            j <- j - 1
        end while
        A[j + 1] <- x
        i <- i + 1
    end while

*/

class InsertionSort {

    public int[] insertionSort(int[] arr) {

        int i = 1;
        while (i < arr.length) {
            int j = i;
            while (j > 0 && arr[j - 1] > arr[j]) {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                j--;
            }
            i++;
        }
        return arr;
    }
}

/*

Faster version:

    public int[] insertionSortFaster(int[] arr) {

        int i = 1;
        while (i < arr.length) {
            int temp = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > temp) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = temp;
            i++;
        }
        return arr;
    }

*/
/*
Best Case complexity:

    The best case input is an array that is already sorted.

    In this case insertion sort has a linear running time (i.e., O(n)).

    During each iteration, the first remaining element of the input is only compared
        with the right-most element of the sorted subsection of the array.

-------

Worst Case:

    The simplest worst case input is an array sorted in reverse order.

    The set of all worst case inputs consists of all arrays where each element is the
        smallest or second-smallest of the elements before it.

        In these cases every iteration of the inner loop will scan and shift the entire
            sorted subsection of the array before inserting the next element.

        This gives insertion sort a quadratic running time (i.e., O(n^2)).

-------

Average Case:

    The average case is also quadratic, which makes insertion sort impractical for
        sorting large arrays.

-------

However, insertion sort is one of the fastest algorithms for sorting very small
    arrays, even faster than quicksort;

    indeed, good quicksort implementations use insertion sort for arrays
        smaller than a certain threshold, also when arising as subproblems;
        the exact threshold must be determined experimentally and depends on the machine,
        but is commonly around ten.

-------

Relation to another sorting algorithms:

    Insertion sort is very similar to selection sort.

            As in selection sort, after k passes through the array, the first k elements
                are in sorted order.

            However, the fundamental difference between the two algorithms is that
                insertion sort scans backwards from the current key,
                while selection sort scans forwards.

            This results in selection sort making the first k elements the k smallest
                elements of the unsorted input, while

                in insertion sort they are simply the first k elements of the input.

    -------

    The primary advantage of the insertion sort over selection sort is that selection sort
        must scan all remaining elements to find the absolute smallest element in the
        unsorted portion of the list,

        while insertion sort requires only a single comparison when the (k + 1)-st element
            is greater than the k-th element

            when this is frequently true (such as if the input array is already sorted
                or partially sorted), insertion sort is distinctly more efficient

            On average (assuming the rank of the k + 1)-st element rank is random,
                insertion sort will require comparing and shifting half of the previous
                k elements, meaning that insertion sort will perform about half as many
                comparisons as selection sort on average

    -------

    In the worst case for the insertion sort (when the input array is reverse-sorted),
        insertion sort performs just as many comparisons as selection sort

        However, a disadvantage of insertion sort over the selection sort is that it requires
            more writes due to the fact that, on each iteration, inserting the (k + 1)-st
            element into the sorted portion of the array requires many element swaps to shift
            all of the following elements,

            while only a single swap is required for each iteration of the selection sort

        In general, insertion sort will write to the array O(n^2) times, whereas
            selection sort will write only O(n) times

        For this reason selection sort may be preferable in cases where writing to memory
            is significantly more expensive than reading

-------

While some divide-and-conquer algorithms such as quicksort and mergesort outperform
    insertion sort for larger arrays,

    non-recursive sorting algorithms such as insertion sort or selection sort are
        generally faster for very small arrays

        (the exact size varies by environment and implementation, but is typically
            between 7 and 50 elements).
*/