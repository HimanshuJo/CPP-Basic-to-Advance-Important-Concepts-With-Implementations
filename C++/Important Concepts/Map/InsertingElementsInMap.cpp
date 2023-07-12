/*
Map is a container, as name suggests used to store a key-value pair. 

	Map has an advantage over other containers by the fact that searching 
    in map, defined by the “key” takes only O(1) time complexity, 
    hence making it useful in various coding fields. 

-------

Using insert():

	Insert function is used to insert the key-value pair in the map. 

	After insertion, the reordering of elements takes place and the 
    map is sorted w.r.t the key.

	-------

	This function is implemented in 3 ways:

    	insert(pair): 

    		This function inserts the pair in map. 

    		The insertion only takes place when the key passed is not 
            already in set.

    		It returns a pointer pair.

    			First element pointing to the pair already present or 
                newly inserted. 

    			Second element returning the boolean status “true” or “false”.

    	Time complexity: log(n) where n is size of map

		-------

    	insert(hint, pair):

    		In this implementation, the hint pointer is sent with the pair 
            to be inserted. 

    		The use of hint pointer is to help insert() know where the 
            actual insertion has to take place.

    		Hence, trying to reduce time to allocate the pair.

    		Hint pointer does not force the insertion at specific position. 
            This function returns the pointer to the position where 
            pair is inserted.

    		Time complexity: log(n) where n is size of map, if hint is 
            optimal then O(1)

		-------

    	insert(beg_ptr, end_ptr): 

    		This type of insertion is required to insert the pairs of 
            other container into map. 

    		The repeated pairs are not inserted if they are present in 
            the destination container.

    		Time complexity: k*log(n) where n is size of map, k is no. 
            of elements inserted
*/

// C++ code to demonstrate the working of insert()

#include<iostream>
#include<map> // for map operations
using namespace std;

void mapInsertTest1(){
    // declaring map
    // of char and int
    map<char, int> mp;
    
    // declaring iterators
    map<char, int>::iterator it ;
    map<char, int>::iterator it1;
    map<char, int>::iterator it2;
    
    // declaring pair for return value of map containing
    // map iterator and bool
    pair<map<char, int>::iterator, bool> ptr;
    
    // using insert() to insert single pair
    // inserting 'a' with 20
    ptr = mp.insert(pair<char, int>('a', 20));
    
    // checking if the key was already present or newly inserted
    if(ptr.second)
        cout << "The key was newly inserted" ;
    else
        cout << "The key was already present" ;
    
    cout << endl ;
    
    // printing map pairs after insertion
    cout << "The map pairs after 1st insertion are : \n";
    
    for (it1 = mp.begin(); it1!=mp.end(); ++it1)
        cout << it1->first << "->" << it1->second << endl;
    
    it = mp.begin();
    
    // inserting map pair using hint
    mp.insert(it, pair<char, int>('b', 24) );
    
    cout << endl ;
    
    // printing map pairs after insertion
    cout << "The map pairs after 2nd insertion are : \n";
    
    for (it1 = mp.begin(); it1!=mp.end(); ++it1)
        cout << it1->first << "->" << it1->second << endl;
    
    // initializing another map
    map<char, int> mp2;
    
    // using insert(beg_iter, end_iter) to copy all elements
    mp2.insert(mp.begin(), mp.end());
    
    cout << endl ;
    
    // printing new map pairs after insertion
    cout << "The new map pairs after insertion are : \n";
    
    for (it1 = mp2.begin(); it1!=mp2.end(); ++it1)
        cout << it1->first << "->" << it1->second << endl;
}

void mapInsertTest2(){
    // declaring map
    map<char, int> mp;
    
    // declaring iterators
    map<char, int>::iterator it;
    map<char, int>::iterator it1;
    map<char, int>::iterator it2;
    
    // declaring pair for return value of map containing
    // map iterator and bool
    pair<map<char, int>::iterator, bool> ptr;
    
    // using emplace() to insert pair element
    // inserting 'a' to 24
    // no "pair" needed, in-place construction
    ptr = mp.emplace('a', 24);
    
    // checking if the pair was already present or newly inserted
    // returns true. newly inserted
    if (ptr.second)
        cout << "The key was newly inserted" ;
    else
        cout << "The key was already present" ;
    
    cout << endl;
    
    // printing map pairs after insertion
    cout << "The map pairs after 1st insertion are : \n";
    
    for (it1 = mp.begin(); it1!=mp.end(); ++it1)
        cout << it1->first << "->" << it1->second << endl;
    
    cout << endl ;
    
    // using emplace() to insert single pair
    // inserting a to 24 // not inserted this time
    ptr = mp.emplace('a', 24);
    
    // checking if the key was already present or newly inserted
    // returns false. already inserted
    if(ptr.second)
        cout << "The key was newly inserted" ;
    else
        cout << "The key was already present" ;
    
    cout << endl ;
    
    // printing map pairs after insertion
    cout << "The map pairs after 2nd insertion are : \n";
    
    for (it1 = mp.begin(); it1!=mp.end(); ++it1)
        cout << it1->first << "->" << it1->second << endl;
    
    it = mp.begin();
    
    // inserting map pair using hint
    mp.emplace_hint(it, 'b', 20);
    
    cout << endl ;
    
    // printing map pairs after insertion
    cout << "The map pairs after 3rd insertion are : \n";
    
    for (it1 = mp.begin(); it1!=mp.end(); ++it1)
        cout << it1->first << "->" << it1->second << endl;
}

/*
Using operator[] : 

“[]” can also be used to insert elements in map. 

Similar to above functions and returns the pointer to the newly 
constructed element. 

Difference is that this operator always constructs a new element i.e 
even if a value is not mapped to key, default constructor is called 
and assigns a “null” or “empty” value to the key. 

Size of map is always increased by 1.

Time complexity : log(n) where n is size of map
*/
void mapInsertTest3(){
    // declaring map
    map<char, int> mp;
    
    // using [] to assign key to value
    mp['a'] = 5;
    mp['b'] = 6;
    mp['c'] = 2;
    
    // printing values
    cout << "The element keys to a is : ";
    cout << mp['a'] << endl;
    
    cout << "The element keys to b is : ";
    cout << mp['b'] << endl;
    
    cout << "The element keys to c is : ";
    cout << mp['c'] << endl;
    
    // default constructor is called
    // prints 0
    cout << "The element keys to d is : ";
    cout << mp['d'] << endl;
}

int main()
{
    mapInsertTest1();
    cout<<"\n-------\n";
    mapInsertTest2();
    cout<<"\n-------\n";
    mapInsertTest3();
    cout<<"\n-------\n";
}