#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

typedef std::vector<std::string>::iterator iterator;

struct startsWithA : public std::unary_function<std::string, bool>
{
    bool operator()(std::string s)
    {
        if (s[0] == 'A')
        {
            return true;
        }
        else
            return false;
    }
};

void print(iterator b, iterator e)
{
    iterator i;
    for (i = b; i != e; i++)
    {
        std::cout << *i << "    ";
    }
    std::cout << std::endl;
}

int main()
{
    startsWithA s;
    std::vector<std::string> v;
    v.push_back("China");
    v.push_back("India");
    v.push_back("Korea");
    v.push_back("America");
    v.push_back("Australia");
    v.push_back("Pakistan");
    std::cout << "Vector : ";
    print(v.begin(), v.end());
    iterator i = remove_if(v.begin(), v.end(), s);
    std::cout << "Vector : ";
    print(v.begin(), i);
    return 0;
}

/*
Output:
Vector : China    India    Korea    America    Australia    Pakistan
Vector : China    India    Korea    Pakistan
*/