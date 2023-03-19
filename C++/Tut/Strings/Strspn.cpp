/*
std::strspn

Defined in header <cstring>

    size_t strspn( const char* dest, const char* src );

Returns the length of the maximum initial segment (span) of the byte string pointed to by dest, 
that consists of only the characters found in byte string pointed to by src.

Parameters
    dest       -    pointer to the null-terminated byte string to be analyzed
    src        -    pointer to the null-terminated byte string that contains the characters to search for

Return value
    The length of the maximum initial segment that contains only characters from byte string pointed to by src
*/

#include <cstring>
#include <string>
#include <iostream>

using namespace std;

const char *low_alpha = "qwertyuiopasdfghjklzxcvbnm";

int main()
{
    std::string s = "abcde312$#@";
 
    std::size_t spnsz = std::strspn(s.c_str(), low_alpha);
    cout<<"Number of chars found: "<<spnsz<<endl;
    std::cout << "After skipping initial lowercase letters from '" << s
              << "'\nThe remainder is '" << s.substr(spnsz) << "'\n";
}

/*
Output:

Number of chars found: 5
After skipping initial lowercase letters from 'abcde312$#@'
The remainder is '312$#@'
*/