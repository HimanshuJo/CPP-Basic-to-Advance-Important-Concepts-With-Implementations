/*
function<string>std::to_string

string to_string (int val);
string to_string (long val);
string to_string (long long val);
string to_string (unsigned val);
string to_string (unsigned long val);
string to_string (unsigned long long val);
string to_string (float val);
string to_string (double val);
string to_string (long double val);
*/

#include <iostream>   // std::cout
#include <string>     // std::string, std::to_string

int main ()
{
  std::string pi = "pi is " + std::to_string(3.1415926);

  std::string perfect = std::to_string(1+2+4+7+14) + " is a perfect number";

  std::cout << pi << '\n';

  std::cout << perfect << '\n';
  
  return 0;
}

/*
Output:
pi is 3.141593
28 is a perfect number
*/