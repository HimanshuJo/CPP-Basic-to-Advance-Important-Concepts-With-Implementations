/*
std::unique:

	is used to remove duplicates of any element present 'consecutively' in a range[first, last).

	It performs this task for all the sub-groups present in the range having the same element present consecutively.

	It does not delete all the duplicate elements, but it removes duplicacy by just
	replacing those elements by the next element present in the sequence which is
	not duplicate to the current element being replaced.

	All the elements which are replaced are left in an unspecified state.

	Another interesting feature of this function is that it does not changes the size
	of the container after deleting the elements, it just returns a pointer pointing to
	the new end of the container, and based upon that we have to resize the container,
	or remove the garbage elements.

	-------

	It can be used in two ways as shown below:

		Comparing elements using ==:

			Syntax:

				template

					ForwardIterator unique (ForwardIterator first, ForwardIterator last);

						first: Forward iterator to the first element in the container.

						last: forward iterator to the last element in the container.

					Return Value:

						It returns an iterator to the element that follows
						the last element not removed.

						The range between first and this iterator includes all the elements
						in the sequence that were not duplicates and hence not removed.
*/

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Version1 {
public:
	void uniqueTest() {
		vector<int>v = {1, 1, 3, 3, 3, 10, 1, 3, 3, 7, 7, 8}, i;
		vector<int>::iterator ip;
		ip = std::unique(v.begin(), v.begin() + 12);
		// Now v becomes {1 3 10 1 3 7 8 * * * * *}
		// * means undefined

		// Resizing the vector so as to remove the undefined terms
		v.resize(std::distance(v.begin(), ip));
		for (ip = v.begin(); ip != v.end(); ++ip) {
			cout << *ip << " ";
		}
	}
};

/*
Output:

1 3 10 1 3 7 8
*/

/*
Here, in this vector, all the sub-groups having consecutive duplicate elements has
been reduced to only one element.

Note that it does not matter whether the same element is present later on as well,
only duplicate elements present consecutively are handled by this function.
*/

/*
By comparing using a pre-defined function:

	Syntax:

		template

 			ForwardIterator unique(ForwardIterator first, ForwardIterator last,
                                   BinaryPredicate Pred);

			Here, first and last are the same as previous case.

			Pred:

				Binary function that accepts two elements in the range as argument,
				and returns a value convertible to bool.

				The value returned indicates whether both arguments are considered equivalent
				(if true, they are equivalent and one of them is removed).

				The function shall not modify any of its arguments.

				This can either be a function pointer or a function object.

			Return Value:

				It returns an iterator to the element that follows the
				last element not removed.

				The range between first and this iterator includes all the elements in
				the sequence that were not duplicates and hence not removed.
*/

class Version2 {
public:

	struct custComp{
		bool operator()(char a, char b) {
			// Checking if both the arguments are same and equal
			// to 'G' then only they are considered same
			// and duplicates are removed
			if (a == b && a == 'G') {
				return 1;
			} else {
				return 0;
			}
		}
	};


	void uniqueTest() {
		// Declaring a string
		string s = "You arre vvvisiting GGGGFGGGG";

		// Using std::unique to remove the consecutive
		// G in the word
		auto ip = std::unique(s.begin(), s.end(), custComp());

		// Displaying the corrected string
		cout << string(s.begin(), ip);
	}
};

/*
Output:

You arre vvvisiting GFG
*/

/*
Here, we have manipulated the binary function in such a way that only if
two G are passed as arguments, then only they will be considered as same, and
if any other character is present consecutively, then it will remain unaffected,
and will not be removed (like r in arre, v in visiting).
*/

/*
Where str::unique can be used ?

	Remove all the duplicate elements from a container:

		Many of you must have searched for std::unique with a view that it will
		remove all the duplicate elements from the container, and now you might feel a
		bit disappointed to know that it removes only the consecutive duplicate elements.

		But, although, std::unique cannot do so as per its definition, but applying a bit of logic,
		we can make that happen.

		What we need to do is just sort the array before applying std::unique,
		such that all equal elements become consecutive, and now we have std::unique to
		remove all the duplicate consecutive elements.

		So, std::unique can also be used to remove all the duplicate elements from a container.
*/

class Version3 {
public:
	void uniqueTest() {
		vector<int> v = { 1, 2, 3, 3, 3, 10, 1, 2, 3, 7, 7, 8 };
		vector<int>::iterator ip;
		std::sort(v.begin(), v.end());
		// Now v becomes 1 1 2 2 3 3 3 3 7 7 8 10

		// Using std::unique
		ip = std::unique(v.begin(), v.begin() + 12);
		// Now v becomes {1 2 3 7 8 10 * * * * * *}
		// * means undefined

		// Resizing the vector so as to remove the undefined terms
		v.resize(std::distance(v.begin(), ip));

		for (ip = v.begin(); ip != v.end(); ++ip) {
			cout << *ip << " ";
		}
	}
};

/*
Output:

1 2 3 7 8 10
*/

/*
Count unique elements : It can also be used if we want to count the total no. of unique elements in a container.
*/

class Version4 {
public:
	void uniqueTest() {
		vector<int> v = { 1, 1, 3, 3, 3, 10, 1, 3, 3, 7, 7, 8 };
		vector<int>::iterator ip;

		int count;
		sort(v.begin(), v.end());

		// Using std::unique and std::distance to count
		// unique elements in a container
		count = std::distance(v.begin(), std::unique(v.begin(), v.begin() + 12));

		cout << "Total no. of unique elements = " << count;
	}
};


/*
Output:

Total no. of unique elements = 5
*/

/*
Explanation:

	As we know that std::unique returns an iterator to what should be the new
	end of the container after removing duplicate elements, so just counting the total no.
	of elements from beginning till this new end with the help of std::distance,
	should give us the total no. of unique elements in the container.
*/

int main(){
	Version1 obj1;
	Version2 obj2;
	Version3 obj3;
	Version4 obj4;
	obj1.uniqueTest();
	cout<<"\n-------\n";
	obj2.uniqueTest();
	cout<<"-------\n";
	obj3.uniqueTest();
	cout<<"-------\n";
	obj4.uniqueTest();
}