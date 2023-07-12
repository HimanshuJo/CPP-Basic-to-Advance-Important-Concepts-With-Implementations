/*
insert() is used to insert characters in string at specified position. 

It supports various syntaxes to facilitate same, here we will describe them.
*/

#include <iostream>
#include <string>
using namespace std;

/*
Syntax 1: Inserts the characters of str starting from index idx.

	string& string::insert (size_type idx, const string& str)

		idx : is the index number

		str : is the string from which characters is to be picked to insert 

		Returns *this.

		Errors:

			Throws out_of_range if idx > size().

			Throws length_error if the resulting size exceeds the maximum number of characters.
*/
void insertDemo1(string str1, string str2)
{
	// Inserts str2 in str1 starting from 6th index of str1
	str1.insert(6, str2);
	cout << "Using insert : ";
	cout << str1;
}

/*
Syntax 2: Inserts at most, str_num characters of str, starting with index str_idx.

	string& string::insert (size_type idx, const string &str, size_type str_idx, size_type str_num)
		
		idx : is the index number where insertion is to be made.

		str : is the string from which characters are to be picked to insert.

		str_idx : is the index number in str.

		str_num : is the number of characters to be inserted from str.

		Returns *this.

		Errors: 

			Throws out_of_range if idx > size().

			Throws out_of_range if str_idx > str.size().

			Throws length_error if the resulting size exceeds the maximum number of characters.
*/
void insertDemo2(string str1, string str2)
{
	// begin insertion at index 6, starting from index 8 take 6 characters from string str2
	str1.insert(6, str2, 8, 6);
	cout << "Using insert : ";
	cout << str1;
}

/*
Syntax 3: Inserts the characters of the C-string cstr so that the new characters start with index idx.

	string& string::insert (size_ type idx, const char* cstr)
		
		idx : is the index number where insertion is to be made.

		*cstr : is the pointer to the C-string which is to be inserted.

		Returns *this.

		Errors: 

			Throws out_of_range if idx > size().

			Throws length_error if the resulting size exceeds the maximum number of characters.

		Note: cstr may not be a null pointer (NULL).
*/
void insertDemo3(string str)
{
	// Inserts " are " at 5th index of str
	str.insert(5, " are ");
	cout << "Using insert : ";
	cout << str;
}

/*
Syntax 4: Inserts chars_len characters of the character array chars so that the new characters start with index idx.

	string& string::insert (size_type idx, const char* chars, size_type chars_len)
		
		idx : index number where insertion is to be made.

		*chars : is the pointer to the array.

		chars_len : is the number of characters to be inserted from character array.

		Returns : *this

		Errors: 

			Throws out_of_range if idx > size().

			Throws length_error if the resulting size exceeds the maximum number of characters.

	Note : chars must have at least chars_len characters.
*/
void insertDemo4(string str)
{

	// Inserts 10 characters from " are here " at 5th index of str
	str.insert(5, " are here and forJustGeeks", 10);
	cout << "Using insert : ";
	cout << str;
}

/*
Syntax 5: Inserts num occurrences of character c at the position specified by idx.

	string& string ::insert (size_type idx, size_type num, char c)
		
		idx : is the index number where insertion is to be made.

		c : is the character to be inserted.

		num : is the number of repetition of character c

		Returns : *this

		Errors: 

			Throw out_of_range if idx > size().

			Throw length_error if the resulting size exceeds the maximum number of characters.
*/
void insertDemo5(string str)
{

	// Inserts at 5th index, 5 occurrences of '$'
	str.insert(5, 5, '$');
	cout << "Using insert : ";
	cout << str;
}

/*
Syntax 6: Inserts num occurrences of character c at the position specified by iterator pos.

	void string ::insert (iterator pos, size_type num, char c)
		
		pos : is the position of iterator.

		c : is the character which is to be inserted.

		Returns : *this

		Errors: 

			Throws out_of_range if pos > size().

			Throws length_error if the resulting size exceeds the maximum number of characters.
*/
void insertDemo6(string str)
{

	// Inserts 5 occurrences of '$' at position str.begin() + 5
	str.insert(str.begin() + 5, 5, '$');
	cout << "Using insert : ";
	cout << str;
}

/*
Syntax 7: Inserts a copy of character c before the character to which iterator pos refers.

	iterator string ::insert (iterator pos, char c)
		
		pos : is the position of iterator.

		c : is the character which is to be inserted.

		Returns :  iterator pointing to the first character inserted.

		Error: 

			Throws length_error if the resulting size exceeds the maximum number of characters.
*/
void insertDemo7(string str)
{
	std::string::iterator pos;

	// Inserts '$' at position str.begin() + 5
	pos = str.insert(str.begin()+5,'$');
	cout << "Using insert : ";
	cout << str << endl;
	cout << "Value at Iterator returned : " << *pos;
}

/*
Syntax 8: Inserts all characters of the range [ beg, end ) before the character to which iterator 
pos refers.

	void string ::insert (iterator pos, InputIterator beg, InputIterator end)
		
		pos : is the iterator position.

		beg, end : Input iterators to the initial and final positions in a sequence.

		Error: 

			Throws length_error if the resulting size exceeds the maximum number of characters.
*/
void insertDemo8(string str1, string str2)
{
	// Inserts str2.begin() + 5 , str2.end() - 6 at position str1.begin() + 6
	str1.insert(str1.begin() + 6, str2.begin() + 5 , str2.end() - 6);
	cout << "Using insert : ";
	cout << str1;
}

int main()
{
	string str1("Hello World! ");
	string str2("GeeksforGeeks ");

	cout << "Original String : " << str1 << endl;
	insertDemo1(str1, str2);

    cout<<endl;
    cout<<endl;

    string str3("Hello World! ");
	string str4("GeeksforGeeks ");

	cout << "Original String : " << str3 << endl;
	insertDemo2(str3, str4);

    cout<<endl;
    cout<<endl;

    string str5("GeeksforGeeks ");

	cout << "Original String : " << str5 << endl;
	insertDemo3(str5);

    cout<<endl;
    cout<<endl;

    string str6("GeeksforGeeks ");

	cout << "Original String : " << str6 << endl;
	insertDemo4(str6);

    cout<<endl;
    cout<<endl;

    string str7("**********");

	cout << "Original String : " << str7 << endl;
	insertDemo5(str7);

    cout<<endl;
    cout<<endl;

    string str8("**********");

	cout << "Original String : " << str8 << endl;
	insertDemo6(str8);

    cout<<endl;
    cout<<endl;

    string str9("**********");

	cout << "Original String : " << str9 << endl;
	insertDemo7(str9);

    cout<<endl;
    cout<<endl;
    
    string str10("Hello World! ");
	string str11("GeeksforGeeks ");

	cout << "Original String : " << str10 << endl;
	insertDemo8(str10, str11);

	return 0;
}

/*
Output:

Original String : Hello World! 
Using insert : Hello GeeksforGeeks World!
*/
