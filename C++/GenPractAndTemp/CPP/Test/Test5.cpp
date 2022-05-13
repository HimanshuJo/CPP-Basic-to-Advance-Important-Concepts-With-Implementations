#include <iostream>
#include <string>
using namespace std;

int main() { 
   std::string str = "cdbcbbaaabab";
   std::string pattern = "ba";

   std::string::size_type i = str.find(pattern);
   int count=0;
   while (i != std::string::npos) {
       count++;
     str.erase(i, pattern.length());
     i = str.find(pattern, i);
   }
   cout<<count<<endl;
   std::cout << str;
}