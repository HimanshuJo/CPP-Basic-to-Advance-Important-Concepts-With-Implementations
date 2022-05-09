/*
Ques: Count number of Binary Tree possible given Preorder sequence of length n

Suppose we have a binary tree as below:

	          10
	        /    \
           11    12
          /     /  \
         9     13  14

    So the pre-order sequence for this binary tree is: 10 11 9 12 13 14

-------

Suppose n = 1

	when we just have a sequence of length 1 let's say 10

		how many binary trees that can be formed that have the same pre-order-> only 1

		hence our dp array looks likes this:

			Indices: 0  1  2  3  4  5
			Values:  1  1  _  _  _  _

Suppose n = 2

	when we have two keys 10, 11, how many binary trees that can be formed that have the same pre-order

		1 ->	10
			    /
		   	   11

	    2 ->	10
	    		  \
	    		  11

	    hence our dp array looks like this

			Indices: 0  1  2  3  4  5
			Values:  1  1  2  _  _  _

Suppose n = 3

	when we have three keys 10, 11, 12, how many binary trees can be formed that have the same pre-order

		1 ->	10
		        /
	          11
	          /
	        12

        2 ->	10
        		/
    		  11
    		  	\
    		  	12

	  	3 ->	10
	  	       /  \
  	          11  12

        4 ->	10
        		  \
        		  11
        		  /
    		  	 12

	  	5 ->	10
	  			  \
  			  	  11
  			  	    \
  			  	    12

  	    hence our dp array looks like this

  	    	Indices: 0  1  2  3  4  5
			Values:  1  1  2  5  _  _

Suppose n = 4

	when we have four keys 10, 11, 12, 13

		10 will be the root, and suppose 11, 12 and 13 all go on the left side of 10
			we already know how many keys 11, 12 and 13 can form (if we just consider the tree of keys 11, 12, 13)
			that is 5

		Case 1: When 11, 12 and 13 go on the left side of 10

			1 ->	10
				    /
				  11
				  /
			    12
			    /
			  13

		  	2 ->	10
		  			/
		  		  11
		  		 /  \
	  		    12  13

  		    3 ->	10
  		    		/
  		    	   11
  		    	    \
  		    	    12
  		    	      \
  		    	      13

	        4 ->	10
	        		/
	        	   11
	        	    \
	        	    12
	        	    /
	        	   13

    	    5 ->	10
    	    		/
    	    	   11
    	    	   /
    	    	  12
    	    	   \
    	    	   13

	   	Case 2: 	

	   				10
   			       /  \
   			    {11}  {12, 13}

	   			When 11 stays on the left side of 10 and 11, 12 goes on the right side of 20

	   			We already know that when one key is present on one side the value is 1

	   			Also, we already know that when two keys present on one side the value is 2

	   			so here in this particular case, the total number of trees that we can get is
	   				1 * 2 = 2 (all the combinations of 12, 13 and all the combinations of 11 alone)

		Case 3: 
	   				   10
   			       	  /  \
   			    {11,12}  {13}

				When 11, 12 stays on the left side and 13 stays on the right side

				Same case as above:
					2 keys on one side
					1 key on one side

					2 * 1 = 2

		Case 4: 
					10
					  \
					  {11, 12, 13}

				  When all of the keys goes on the right side, we also know from our dp table, the value for this case is
				  	5

  	-------

  	Hence the total trees that we can get = 5 + 2 + 2 + 5 = 14

  	our dp table looks like this:

  		Indices: 0  1  2  3  4   5
		Values:  1  1  2  5  14  _

Suppose n = 5

	When we have the following keys 10, 11, 12, 13, 14

	Case 1:
					10
				   /
		   {11, 12, 13, 14}

		   	When 11, 12, 13 and 14 all go on the left side, we have our total combinations in this case = 14

   	Case 2:
					 10
				   /    \
		   {11, 12, 13} {14}

		    for the above case we have our combinations from our dp table as:
		   		for 3 -> 5
		   		for 1 -> 1
		   		total 5 * 1 = 5

	Case 3:
				 10
			   /    \
	      {11, 12} {13, 14}

       	for the above case we have our combinations from our dp table as:
	   		for 2 -> 2
	   		total 2 * 2 = 4

	Case 4:

	 			 10
			   /    \
	      	 {11} {12,13,14}

      	    for the above case we have our combinations from our dp table as:

      	    	for 1 -> 1
      	    	for 3 -> 5
      	    	total 1 * 5 = 5

	Case 5:

			 10
			   \
		     {11,12,13,14}

	     	for the above case we have our total combination from our dp table as:
	     		14

	Hence the total trees we can get is 14 + 5 + 4 + 5 + 14 = 42

	  	our dp table looks like this:

  		Indices: 0  1  2  3  4   5
		Values:  1  1  2  5  14  42

-------

Pseudo-code:

	T[0] = 1;
	T[1] = 1;
	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j < i; ++j) {
			T[i] += T[j] * T[i - j - 1];
		}
	}

*/

/**
 * Given a preorder sequence how many unique trees can be created
 * Solution is CATALAN NUMBER Number of tree is exactly same
 * as number of unique BST create with array of size n
 * 
 * The way it works for preorder sequence is as follows
 * 
 * Suppose our preorder sequence is 1 2 3 4
 * So we need to compute following things
 * count(3)* 2 (combination of 2,3 and 4 on both side of 1)
 * count(1)*count(2) (combination of 2 on one side and 3, 4 on other side)
 * count(2)*count(1) (combination of 2,3 on one side and 4 on other side)
 * count(3)*2 can be broken into count(3)*count(0) + count(0)*count(3)
 * 
 * So our final result is
 * count(0)*count(3) + count(1)*count(2) + count(2)*count(1) + count(3)*count(0)
 * which is a catalan number
 */

 public class CountNumberOfTreePreorder {
 	// Iterative
 	public int count(int num) {
 		if (num == 0) {
 			return 0;
 		}
 		int[] T = new int[num + 1];
 		T[0] = 1;
 		T[1] = 1;
 		for (int i = 2; i <= num; ++i) {
 			int sum = 0;
 			for (int k = 0; k < i; ++k) {
 				sum += T[k] * T[i - k - 1];
 			}
 			T[i] = sum;
 		}
 		return T[num];
 	}

 	// Recursive
 	public int countRec(int num) {
 		if (num == 0 || num == 1) {
 			return 1;
 		}
 		int sum = 0;
 		for (int i = 1; i <= num; ++i) {
 			sum += countRec(i - 1) * countRec(num - i);
 		}
 		return sum;
 	}

 	public static void main(String[] args) {
 		CountNumberOfTreePreorder cn = new CountNumberOfTreePreorder();
 		System.out.println(cn.count(3));
 		System.out.println(cn.count(4));
 		System.out.println(cn.count(5));
 		System.out.println(cn.countRec(3));
 		System.out.println(cn.countRec(4));
 		System.out.println(cn.countRec(5));
 	}
 }