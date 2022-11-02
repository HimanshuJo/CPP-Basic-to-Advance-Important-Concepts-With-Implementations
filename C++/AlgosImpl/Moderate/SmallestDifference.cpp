/*
	Given two arrays of integers, compute the pair of values(one value in each array) with the smallest
	(non-negative) difference. Return the difference

	Example:

		Input: {1, 3, 15, 11, 2}, {23, 127, 235, 19, 8}
*/
/*
	One more optimal approach is to sort the arrays. Once the arrays are sorted, we can find
	the minimum difference by iterating through the array

	E.g.: Consider the following two sorted arrays

		  A: {1, 2, 11, 15}
		  B: {4, 12, 19, 23, 127, 235}

  		-------

  		Starting the pointers at the beginning of each array(a->1 and b->4) Those have a difference of 3

  		Our goal is to find the smallest difference.

  			B is already bigger than a, so moving B will only make our pair's difference larger

  			Instead we should move the smaller one as this might shrink our pair's difference

		-------

		A->1, B->4 Difference: 3
		A->2, B->4 Difference: 2
*/