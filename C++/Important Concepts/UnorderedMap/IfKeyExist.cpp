/*
Using unordered_map::find function

	The standard solution is to use the public member function find() of the ordered or 
    the unordered map container, which returns an iterator to the key-value pair if the 
    specified key is found, or iterator to the end of the container if the specified key 
    is not found
*/

/*
Using unordered_map::count function

	If we only want to know the presence of a key in the map container, but doesn't want 
    an iterator to it we can use the count() member function of the map container, 
    which returns the value 1 if the specified key is found or 0 is the specified key is not found

	Since all the keys in a map are distinct, count() internally uses find() function
*/

/*
Using STL algorithms

	There are many algorithms offered by the standard library like

		std::find_if

		std::count_if

		std::for_each

		std::any_of

	these can be used to linearly searches the map container for a key
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>

void unorderedMapTest1(std::unordered_map<char, int>&m){
    std::string s("abcba");
    std::for_each(s.begin(), s.end(), [&m](char &c) { m[c]++; });
    
    char ch = 's';
    
    if (m.find(ch) != m.end())
    {
        std::cout << "Key found" << "\n";
    }
    else
    {
        std::cout << "Key not found" << "\n";
    }
}

void unorderedMapTest2(std::unordered_map<char, int>&m){
    std::string s("abcba");
    std::for_each(s.begin(), s.end(), [&m](char &c) { m[c]++; });
    
    char ch = 'a';
    
    if (m.count(ch))
    {
        std::cout << "Key found" << "\n";
    }
    else
    {
        std::cout << "Key not found" << "\n";
    }
}

void unorderedMapTestWithFindIf(std::unordered_map<char, int>&m){
    std::string s("abcba");
    std::for_each(s.begin(), s.end(), [&m](char &c)
                    { m[c]++; });

    char ch = 'a';

    auto it = std::find_if(m.begin(), m.end(),
                            [&ch](std::pair<const char, int> &entry)
                            {
                                return (entry.first == ch);
                            });

    if (it != m.end())
    {
        std::cout << "Key found"
                    << "\n";
    }
    else
    {
        std::cout << "Key not found"
                        "\n";
    }
}

void unorderedMapTestWithCountIf(std::unordered_map<char, int>&m){
    std::string s("abcba");
    std::for_each(s.begin(), s.end(), [&m](char &c)
                    { m[c]++; });

    char ch = 's';

    int count = std::count_if(m.begin(), m.end(),
                                [&ch](std::pair<const char, int> &entry)
                                {
                                    return (entry.first == ch);
                                });

    if (count)
    {
        std::cout << "Key found"
                    << "\n";
    }
    else
    {
        std::cout << "Key not found"
                    << "\n";
    }
}

void unorderedMapTestWithForEachFunction(std::unordered_map<char, int>&m){
    std::string s("abcba");
    std::for_each(s.begin(), s.end(), [&m](char &c)
                    { m[c]++; });

    char ch = 'a';

    bool found = false;
    std::for_each(m.begin(), m.end(),
                    [&ch, &found](std::pair<const char, int> &entry)
                    {
                        if (entry.first == ch)
                        {
                            found = true;
                        }
                    });

    if (found)
    {
        std::cout << "Key found"
                    << "\n";
    }
    else
    {
        std::cout << "Key not found"
                        "\n";
    }
}

void unorderedMapTestWithAnyOfFunction(std::unordered_map<char, int>&m){
    std::string s("abcba");
    std::for_each(s.begin(), s.end(), [&m](char &c)
                    { m[c]++; });

    char ch = 'a';

    bool found = std::any_of(m.begin(), m.end(),
                                [&ch](std::pair<const char, int> &entry)
                                {
                                    return (entry.first == ch);
                                });

    if (found)
    {
        std::cout << "Key found"
                    << "\n";
    }
    else
    {
        std::cout << "Key not found"
                    << "\n";
    }
}
    
int main()
{
    std::unordered_map<char, int> m;
    unorderedMapTest1(m);
    std::unordered_map<char, int> m2;
    unorderedMapTest2(m2);
    std::unordered_map<char, int> m3;
    unorderedMapTestWithFindIf(m3);
    std::unordered_map<char, int> m4;
    unorderedMapTestWithCountIf(m4);
    std::unordered_map<char, int> m5;
    unorderedMapTestWithForEachFunction(m5);
    std::unordered_map<char, int> m6;
    unorderedMapTestWithForEachFunction(m6);
    std::unordered_map<char, int> m7;
    unorderedMapTestWithAnyOfFunction(m7);
    return 0;
}

/*
	Output:

		Key not found

		Key found

        Key found

        Key not found

        Key found

        Key found
        
        Key found
*/
